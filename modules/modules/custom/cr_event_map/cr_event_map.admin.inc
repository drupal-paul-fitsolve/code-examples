<?php
/**
 * Comic relief
 * Event Maps Module
 */

 /**
 * This is the main configuration form for the admin page.
 */
function cr_event_map_settings_form($form, &$form_state) {
  global $base_url;

  module_load_include('inc', 'cr_event_map', 'fusion_tables_auth');
  module_load_include('inc', 'cr_event_map', 'kml_parsers');

  $auth = new FusionTablesAuth();
  $form = array();
  if(!$auth->hasToken()) {
    drupal_set_message(t('<strong>You are not authenticated with the Google API.</strong> This means you cannot sync your files with Fusion Tables. <a href="/admin/config/services/cr_event_map/gapi/auth">Please login</a> to create a valid Token.'), 'error');
    
    // We're not authenticated
    $form['auth_google'] = array(
      '#markup' => l('Authenticate with Google API', 'admin/config/services/cr_event_map/gapi/auth')
    );
  } else {
    // We're authenticated
    $form['auth_google'] = array(
      '#markup' => l('Logout from Google API', 'admin/config/services/cr_event_map/gapi/logout')
    );

    // General Status Message
    $last_run = variable_get('cr_event_map_last_run');
    $last_run = $last_run ? date("F j, Y, g:i a", $last_run) : "Not run";
    drupal_set_message(t('Google API OAuth Status: <strong>Authenticated</strong>. Last Sync: <strong>%lastrun</strong>. ', array('%lastrun' => $last_run)), 'status');
  }  

  $form['fetch_time'] = array(
    '#description' => t("<b>Minutes</b> it should fetch the KML files in. E.g. 24 hours*60 = 1440. 0 to disable."),
    '#required' => TRUE,
    '#type' => 'textfield',
    '#size' => 10,
    '#title' => t("Minutes to fetch"),
    '#default_value' => variable_get('cr_event_map_fetch_time', '0'),
  );

  // Fetch Settings
  $form['force_fetch'] = array(
    '#type' => 'submit',
    '#value' => t('Force Update All'),
    '#submit' => array('cr_event_map_settings_form_force_fetch'),
    '#ajax' => array(
      'callback' => 'cr_event_map_settings_form_ajax_callback',
      'wrapper' => 'ajax-event-data-wrapper',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );
  // We're not authenticated
  $form['force_fetch_info'] = array(
    '#markup' => t("<p>Force fetches the KML sources, parses the files and imports them into their respective Fusion Tables. This may take a while, so please be patient. You will receive a status message once the requested has been completed.</p>")
  );



  // Restore existing gapi settings
  $form_state['gapi_settings'] = variable_get('cr_event_map_gapi_settings');

  $form_state['gapi_settings'] = !empty($form_state['gapi_settings']) ? unserialize($form_state['gapi_settings']) : FALSE;

  $form['gapi_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Google API'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['gapi_settings']['clientid'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#title' => t("Client ID"),
    '#description' => t('Client ID and secret can be found under &ldquo;Authorized API Access&rdquo; in your <a href="https://code.google.com/apis/console" target="_blank">API Console</a>.'),
    '#default_value' => isset($form_state['gapi_settings']['clientid']) ? $form_state['gapi_settings']['clientid'] : '',
  );
  $form['gapi_settings']['clientsecret'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#title' => t("Client Secret"),
    '#default_value' => isset($form_state['gapi_settings']['clientsecret']) ? $form_state['gapi_settings']['clientsecret'] : '',
  );
  $form['gapi_settings']['redirecturi'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#title' => t("Client Redirect URL"),
    '#description' => t('Your API settings need to match the values here.'),
    '#disabled' => true,
    '#default_value' => $base_url .'/admin/config/services/cr_event_map/gapi/auth',
  );
  $form['gapi_settings']['jsorigin'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#title' => t("JavaScript origins"),
    '#description' => t('Your API settings need to match the values here.'),
    '#disabled' => true,
    '#default_value' => $base_url,
  );
  $form['gapi_settings']['apikey'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#title' => t("API Key"),
    '#description' => t('Found under &ldquo;Simple API Access&rdquo; in your <a href="https://code.google.com/apis/console" target="_blank">API Console</a>.'),
    '#default_value' => isset($form_state['gapi_settings']['apikey']) ? $form_state['gapi_settings']['apikey'] : '',
  );
  $form['gapi_settings']['referers'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#title' => t("Simple API Access Referers"),
    '#description' => t('Your API settings need to match the values here. Please use the root domain e.g. *.comicrelief.com/*.'),
    '#disabled' => true,
    '#default_value' => '*.'.basedomain($base_url).'/*',
  );

  // KML Files
  $form['event_data'] = array(
    '#type' => 'fieldset',
    '#title' => t('Event Data'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#prefix' => '<div id="ajax-event-data-wrapper">',
    '#suffix' => '</div>',
  );
  $form['#tree'] = TRUE;

  // Restore Saved KML References
  $form_state['event_kml'] = variable_get('cr_event_map_kmls');
  $form_state['event_kml'] = !empty($form_state['event_kml']) ? unserialize($form_state['event_kml']) : FALSE;

  if(isset($form_state['triggering_element'])){
    switch($form_state['triggering_element']['#name']){
      // Add new KML
      case 'add_kml':
        $form_state['num_kmls']++;
      break;
      // Remove last KML
      case 'remove_kml':
        if ($form_state['num_kmls'] > 1) {
          $form_state['num_kmls']--;
        }
      break;
    }
  }

  // Create event KML for defaults if none existent
  if(!$form_state['event_kml']) {
    $form_state['event_kml'][] = array(
      'enabled' => 0,
      'name' => '',
      'url' => '',
      'parser' => 'cr_event_map_kml_parser_default',
      'tableid' => ''
    );
  }

  // If empty, count based on event KML array
  if (empty($form_state['num_kmls'])) {
    $form_state['num_kmls'] = count($form_state['event_kml']);
  }

  // Parsers
  $parsers = cr_event_kml_parser_info();
  $parser_options = array();
  foreach($parsers as $parser_function => $parser) {
    $parser_options[$parser_function] = $parser['name'];
  }

  // Build the number of name fieldsets indicated by $form_state['num_names']
  for ($i = 0; $i < $form_state['num_kmls']; $i++) {
    $form['event_data']['files'][$i] = array(
      '#type' => 'fieldset',
      '#title' => t('kml #@num', array('@num' => $i+1)),
      '#collapsible' => FALSE,
    );

    $form['event_data']['files'][$i]['enabled'] = array(
      '#type' => 'checkbox',
      '#default_value' => $form_state['event_kml'][$i]['enabled'],
      '#title' => t('Enabled'),
    );
    $form['event_data']['files'][$i]['name'] = array(
      '#description' => t("<b>Name</b> of the KML file."),
      '#required' => TRUE,
      '#type' => 'textfield',
      '#size' => 20,
      '#title' => t("Name"),
      '#default_value' => $form_state['event_kml'][$i]['name'],
    );
    $form['event_data']['files'][$i]['tableid'] = array(
      '#description' => t("<b>ID</b> of the google Fusion Table. Please ensure all columns are there."),
      '#required' => TRUE,
      '#type' => 'textfield',
      '#size' => 80,
      '#title' => t("Table ID"),
      '#default_value' => $form_state['event_kml'][$i]['tableid'],
    );
    $form['event_data']['files'][$i]['parser'] = array(
      '#type' => 'select',
      '#description' => t("The parser to use. Please see kml_parsers.inc for more details."),
      '#required' => TRUE,
      '#title' => t("Parser"),
      '#options' => $parser_options,
      '#default_value' => $form_state['event_kml'][$i]['parser'],
    );
    $form['event_data']['files'][$i]['url'] = array(
      '#description' => t("<b>URL</b> to a KML file."),
      '#required' => TRUE,
      '#type' => 'textfield',
      '#size' => 80,
      '#title' => t("KML URL"),
      '#default_value' => $form_state['event_kml'][$i]['url'],
    );
    $form['event_data']['files'][$i]['remove_this_kml'] = array(
      '#type' => 'submit',
      '#value' => t('Remove'),
      '#name' => 'remove_this_kml',
      '#ajax' => array(
        'callback' => 'cr_event_map_settings_form_ajax_callback',
        'wrapper' => 'ajax-event-data-wrapper',
        'method' => 'replace',
        'effect' => 'fade',
      ),
      // Since we are removing a name, don't validate until later.
      '#limit_validation_errors' => array(),
    );
  }
  // Adds "Add another name" button
  $form['event_data']['add_kml'] = array(
    '#type' => 'submit',
    '#value' => t('Add another KML'),
    '#executes_submit_callback' => FALSE,
    '#name' => 'add_kml',
    '#ajax' => array(
      'callback' => 'cr_event_map_settings_form_ajax_callback',
      'wrapper' => 'ajax-event-data-wrapper',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );
  if ($form_state['num_kmls'] > 1) {
    $form['event_data']['remove_kml'] = array(
      '#type' => 'submit',
      '#value' => t('Remove latest KML'),
      '#executes_submit_callback' => FALSE,
      '#name' => 'remove_kml',
      '#ajax' => array(
        'callback' => 'cr_event_map_settings_form_ajax_callback',
        'wrapper' => 'ajax-event-data-wrapper',
        'method' => 'replace',
        'effect' => 'fade',
      ),
      // Since we are removing a name, don't validate until later.
      '#limit_validation_errors' => array(),
    );
  }

  // Restore Saved Test KML
  $form_state['test_kml'] = variable_get('cr_event_map_test_kml');
  $form_state['test_kml'] = !empty($form_state['test_kml']) ? unserialize($form_state['test_kml']) : FALSE;

  // Create event test KML for defaults if none existent
  if(!$form_state['test_kml']) {
    $form_state['test_kml'] = array(
      'url' => '',
      'enabled' => true,
      'name' => 'Test KML',
      'parser' => 'cr_event_map_kml_parser_sr14',
      'tableid' => ''
    );
  }

  // Map Sync Testing
  $form['testing'] = array(
    '#type' => 'fieldset',
    '#title' => t('Testing'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#prefix' => '<div id="ajax-test-wrapper">',
    '#suffix' => '</div>',
  );
  $form['testing']['test_kml']['name'] = array(
    '#description' => t("<b>Name</b> of the KML file."),
    '#type' => 'textfield',
    '#size' => 20,
    '#disabled' => true,
    '#title' => t("Name"),
    '#default_value' => 'Test KML',
  );
  $form['testing']['test_kml']['enabled'] = array(
    '#type' => 'checkbox',
    '#disabled' => true,
    '#default_value' => true,
    '#title' => t('Enabled'),
  );
  $form['testing']['test_kml']['tableid'] = array(
    '#description' => t("<b>ID</b> of the google Fusion Table. Please ensure all columns are there."),
    '#type' => 'textfield',
    '#size' => 80,
    '#title' => t("Table ID"),
    '#default_value' => $form_state['test_kml']['tableid'],
  );
  $form['testing']['test_kml']['parser'] = array(
    '#type' => 'select',
    '#description' => t("The parser to use. Please see kml_parsers.inc for more details."),
    '#title' => t("Parser"),
    '#options' => $parser_options,
    '#default_value' => $form_state['test_kml']['parser'],
  );
  $form['testing']['test_kml']['url'] = array(
    '#description' => t("<b>URL</b> to a KML file."),
    '#type' => 'textfield',
    '#size' => 80,
    '#title' => t("KML URL"),
    '#default_value' => $form_state['test_kml']['url'],
  );

  // Fetch Settings
  $form['testing']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Test Fusion Table Import'),
    '#submit' => array('cr_event_map_settings_form_test_fetch'),
    '#ajax' => array(
      'callback' => 'cr_event_map_settings_form_test_ajax_callback',
      'wrapper' => 'ajax-test-wrapper',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save settings',
  );

  return $form;
}

function cr_event_map_settings_form_ajax_callback($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
  return $form['event_data'];
}
function cr_event_map_settings_form_test_ajax_callback($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
  return $form['testing'];
}
function cr_event_map_settings_form_force_fetch($form, &$form_state) {
  cr_event_map_sync(true); // Verbose so we can see messages
}
function cr_event_map_settings_form_test_fetch($form, &$form_state) {
  cr_event_map_sync(true, true); // Verbose so we can see messages
}


/**
 * This is the submit function for cr_event_map_settings_form
 */
function cr_event_map_settings_form_submit($form, &$form_state) {
  // Save Event Data
  $form_state['event_kml'] = serialize($form_state['values']['event_data']['files']);
  $form_state['test_kml'] = serialize($form_state['values']['testing']['test_kml']);
  $form_state['gapi_settings'] = serialize($form_state['values']['gapi_settings']);

  // Save Event KML
  variable_set('cr_event_map_kmls', $form_state['event_kml']);

  // Save Test KML
  variable_set('cr_event_map_test_kml', $form_state['test_kml']);

  // Save gapi settings
  variable_set('cr_event_map_gapi_settings', $form_state['gapi_settings']);

  // Save fetch time
  variable_set('cr_event_map_fetch_time', $form_state['values']['fetch_time']);

  drupal_set_message(t('The configuration options have been saved.'));
}


function cr_event_map_machine_name($human_readable) {
  $machine_readable = strtolower($human_readable);
  $machine_readable = preg_replace('@[^a-z0-9_]+@','_',$machine_readable);
  return $machine_readable;
}

// From http://stackoverflow.com/questions/3211411/how-can-i-get-the-base-domain-name-from-a-url-using-php-eg-google-com-from-ima
function basedomain( $str = '' ) {
    $url = @parse_url( $str );
    if ( empty( $url['host'] ) ) return;
    $parts = explode( '.', $url['host'] );
    $slice = ( strlen( reset( array_slice( $parts, -2, 1 ) ) ) == 2 ) && ( count( $parts ) > 2 ) ? 3 : 2;
    return implode( '.', array_slice( $parts, ( 0 - $slice ), $slice ) );
}