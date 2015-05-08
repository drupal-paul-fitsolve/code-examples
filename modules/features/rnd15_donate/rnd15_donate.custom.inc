<?php
/**
 * @file
 * All custom code of the rnd15 Site Donate Feature
 */

/**
 * Preprocess fieldable panel panes (Money Buys)
 * Implements hook_preprocess_HOOK(&$variables)
 */

function rnd15_donate_preprocess_fieldable_panels_pane(&$vars) {
  $preprocess_custom_panels = array('donate_money_buy');

  // Custom Checks if we actually want to preprocess this pane
  $has_type = isset($vars['elements']['#entity_type']);
  $has_content = isset($vars['content']);
  $is_valid_pane = in_array($vars['elements']['#bundle'], $preprocess_custom_panels);

  if ($has_type && $has_content && $is_valid_pane) {

    // Add theme hook suggestions based on entity type + bundle and entity type + bundle + view mode
    $vars['theme_hook_suggestions'][] = $vars['elements']['#entity_type'] . '__' . $vars['elements']['#bundle'];
  }
}

/**
 * Preprocess donate form
 * Implements hook_preprocess_HOOK(&$variables)
 */

function rnd15_donate_preprocess_cr_donate_form(&$vars) {

  /**
   * Money buy section
   */
  $vars['form']['amount']['#attributes']['class'][] = 'money-buy__donate-amount';
  $vars['form']['amount']['amount']['#title'] = '';
  $vars['form']['amount']['amount']['#attributes']['class'][] = 'type--centred col-xs-12 col-md-6 col-md-offset-6 col-md-pull-3';
  $vars['form']['amount']['currency']['#title'] = '';
  $vars['form']['amount']['currency']['#attributes']['class'][] = 'col-xs-12';

  $vars['form']['amount']['currency']['GBP']['#prefix'] = '<div class="type--centred col-xs-5 col-xs-offset-1 col-sm-2 col-sm-offset-2 col-md-1 col-md-offset-4">';
  $vars['form']['amount']['currency']['GBP']['#suffix'] = '</div>';

  $vars['form']['amount']['currency']['EUR']['#prefix'] = '<div class="type--centred col-xs-5 col-xs-offset-1 col-sm-2 col-sm-offset-0 col-md-1 col-md-offset-0">';
  $vars['form']['amount']['currency']['EUR']['#suffix'] = '</div>';

  $vars['form']['amount']['currency']['AUD']['#prefix'] = '<div class="type--centred col-xs-5 col-xs-offset-1 col-sm-2 col-sm-offset-0 col-md-1 col-md-offset-0">';
  $vars['form']['amount']['currency']['AUD']['#suffix'] = '</div>';

  $vars['form']['amount']['currency']['USD']['#prefix'] = '<div class="type--centred col-xs-5 col-xs-offset-1 col-sm-2 col-sm-offset-0 col-md-1 col-md-offset-0">';
  $vars['form']['amount']['currency']['USD']['#suffix'] = '</div>';

  /**
   * Payment method section
   */
  // removing uneccessary form wrappers
  $vars['form']['method']['#theme_wrappers'] = array();
  $vars['form']['method']['#description'] = '';

  $vars['form']['method']['paymentType']['#attributes']['class'][] = 'row';

  $vars['form']['method']['paymentType']['AMEX']['#prefix'] = '<div class="col-xs-4 col-sm-3">';
  $vars['form']['method']['paymentType']['AMEX']['#suffix'] = '</div>';
  $vars['form']['method']['paymentType']['AMEX']['#title'] = '<span class="payment__card-image payment__card-amex"></span>';

  $vars['form']['method']['paymentType']['JCB']['#prefix'] = '<div class="col-xs-4 col-sm-3">';
  $vars['form']['method']['paymentType']['JCB']['#suffix'] = '</div>';
  $vars['form']['method']['paymentType']['JCB']['#title'] = '<span class="payment__card-image payment__card-jcb"></span>';

  $vars['form']['method']['paymentType']['MSCD']['#prefix'] = '<div class="col-xs-4 col-sm-3">';
  $vars['form']['method']['paymentType']['MSCD']['#suffix'] = '</div>';
  $vars['form']['method']['paymentType']['MSCD']['#title'] = '<span class="payment__card-image payment__card-mscd"></span>';

  $vars['form']['method']['paymentType']['DMC']['#prefix'] = '<div class="col-xs-4 col-sm-3">';
  $vars['form']['method']['paymentType']['DMC']['#suffix'] = '</div>';
  $vars['form']['method']['paymentType']['DMC']['#title'] = '<span class="payment__card-image payment__card-dmc"></span>';

  $vars['form']['method']['paymentType']['MAES']['#prefix'] = '<div class="col-xs-4 col-sm-3">';
  $vars['form']['method']['paymentType']['MAES']['#suffix'] = '</div>';
  $vars['form']['method']['paymentType']['MAES']['#title'] = '<span class="payment__card-image payment__card-maes"></span>';

  $vars['form']['method']['paymentType']['VISA']['#prefix'] = '<div class="col-xs-4 col-sm-3">';
  $vars['form']['method']['paymentType']['VISA']['#suffix'] = '</div>';
  $vars['form']['method']['paymentType']['VISA']['#title'] = '<span class="payment__card-image payment__card-visa"></span>';

  $vars['form']['method']['paymentType']['VISD']['#prefix'] = '<div class="col-xs-3 col-xs-offset-3 col-sm-offset-0">';
  $vars['form']['method']['paymentType']['VISD']['#suffix'] = '</div>';
  $vars['form']['method']['paymentType']['VISD']['#title'] = '<span class="payment__card-image payment__card-visd"></span>';

  $vars['form']['method']['paymentType']['VIED']['#prefix'] = '<div class="col-xs-3">';
  $vars['form']['method']['paymentType']['VIED']['#suffix'] = '</div>';
  $vars['form']['method']['paymentType']['VIED']['#title'] = '<span class="payment__card-image payment__card-vied"></span>';

  // removing uneccessary form wrappers
  $vars['form']['card_or_paypal']['#theme_wrappers'] = array();

  /**
   * Billing section
   */
  $vars['form']['billing']['#theme_wrappers'] = array();
  $vars['form']['billing']['#description'] = t('');

  $vars['form']['billing']['title']['#prefix'] = '<div class="row"><div class="col-xs-12 col-md-5 col-md-offset-7 col-md-pull-6">';
  $vars['form']['billing']['title']['#suffix'] = '</div></div>';

  $vars['form']['billing']['MC_firstname']['#prefix'] = '<div class="row"><div class="col-xs-12 col-md-5 col-md-offset-1">';
  $vars['form']['billing']['MC_firstname']['#suffix'] = '</div>';

  $vars['form']['billing']['MC_lastname']['#prefix'] = '<div class="col-xs-12 col-md-5">';
  $vars['form']['billing']['MC_lastname']['#suffix'] = '</div></div>';

  $vars['form']['billing']['email']['#prefix'] = '<div class="row"><div class="col-xs-12 col-md-5 col-md-offset-1">';
  $vars['form']['billing']['email']['#suffix'] = '</div>';

  $vars['form']['billing']['email_confirm']['#prefix'] = '<div class="col-xs-12 col-md-5">';
  $vars['form']['billing']['email_confirm']['#suffix'] = '</div></div>';

  $vars['form']['billing']['tel']['#prefix'] = '<div class="row"><div class="col-xs-12 col-md-5 col-md-offset-1">';
  $vars['form']['billing']['tel']['#suffix'] = '</div>';

  $vars['form']['billing']['address']['#prefix'] = '<div class="col-xs-12 col-md-5">';
  $vars['form']['billing']['address']['#suffix'] = '</div></div>';

  /**
   * Subscribe section
   */
  $vars['form']['subscribe']['#description'] = t('<h2 class="type--centred">Keep me posted</h2><p class="type--centred type--lg subscribe__type-padding col-xs-12 col-md-8 col-md-offset-2">Don\'t worry, we definitely won\'t send you spam or junk mail, or give your details to anyone else. We don\'t like that sort of thing - <a class="link--inline-grey" href="/legal#/privacy-policy/privacy-policy" target="_blank">see our privacy policy</a>.</p>');

  $vars['form']['subscribe']['MC_permission_email']['#prefix'] = '<div class="col-xs-12 col-sm-8 col-sm-offset-2 col-md-6 col-md-offset-3">';
  $vars['form']['subscribe']['MC_permission_email']['#suffix'] = '</div>';

  $vars['form']['subscribe']['MC_permission_post']['#prefix'] = '<div class="col-xs-12 col-sm-8 col-sm-offset-2 col-md-6 col-md-offset-3">';
  $vars['form']['subscribe']['MC_permission_post']['#suffix'] = '</div>';
}


/**
 * Delivers just the content from a menu_callback, no page furniture
 *
 * This is a copy of drupal_deliver_html_page with the end changed to just
 * return the results of the menu_callback and nothing else
 *
 * @param $page_callback_result
 *   The result of a page callback. Can be one of:
 *   - NULL: to indicate no content.
 *   - An integer menu status constant: to indicate an error condition.
 *   - A string of HTML content.
 *   - A renderable array of content.
 *
 * @see drupal_deliver_page()
 */
function rnd15_donate_delivery_raw($page_callback_result) {
  // Emit the correct charset HTTP header, but not if the page callback
  // result is NULL, since that likely indicates that it printed something
  // in which case, no further headers may be sent, and not if code running
  // for this page request has already set the content type header.
  if (isset($page_callback_result) && is_null(drupal_get_http_header('Content-Type'))) {
    drupal_add_http_header('Content-Type', 'text/html; charset=utf-8');
  }

  // Send appropriate HTTP-Header for browsers and search engines.
  global $language;
  drupal_add_http_header('Content-Language', $language->language);

  // Menu status constants are integers; page content is a string or array.
  if (is_int($page_callback_result)) {
    // @todo: Break these up into separate functions?
    switch ($page_callback_result) {
      case MENU_NOT_FOUND:
        // Print a 404 page.
        drupal_add_http_header('Status', '404 Not Found');

        watchdog('page not found', check_plain($_GET['q']), NULL, WATCHDOG_WARNING);

        // Check for and return a fast 404 page if configured.
        drupal_fast_404();

        // Keep old path for reference, and to allow forms to redirect to it.
        if (!isset($_GET['destination'])) {
          $_GET['destination'] = $_GET['q'];
        }

        $path = drupal_get_normal_path(variable_get('site_404', ''));
        if ($path && $path != $_GET['q']) {
          // Custom 404 handler. Set the active item in case there are tabs to
          // display, or other dependencies on the path.
          menu_set_active_item($path);
          $return = menu_execute_active_handler($path, FALSE);
        }

        if (empty($return) || $return == MENU_NOT_FOUND || $return == MENU_ACCESS_DENIED) {
          // Standard 404 handler.
          drupal_set_title(t('Page not found'));
          $return = t('The requested page "@path" could not be found.', array('@path' => request_uri()));
        }

        drupal_set_page_content($return);
        $page = element_info('page');
        print drupal_render_page($page);
        break;

      case MENU_ACCESS_DENIED:
        // Print a 403 page.
        drupal_add_http_header('Status', '403 Forbidden');
        watchdog('access denied', check_plain($_GET['q']), NULL, WATCHDOG_WARNING);

        // Keep old path for reference, and to allow forms to redirect to it.
        if (!isset($_GET['destination'])) {
          $_GET['destination'] = $_GET['q'];
        }

        $path = drupal_get_normal_path(variable_get('site_403', ''));
        if ($path && $path != $_GET['q']) {
          // Custom 403 handler. Set the active item in case there are tabs to
          // display or other dependencies on the path.
          menu_set_active_item($path);
          $return = menu_execute_active_handler($path, FALSE);
        }

        if (empty($return) || $return == MENU_NOT_FOUND || $return == MENU_ACCESS_DENIED) {
          // Standard 403 handler.
          drupal_set_title(t('Access denied'));
          $return = t('You are not authorized to access this page.');
        }

        print drupal_render_page($return);
        break;

      case MENU_SITE_OFFLINE:
        // Print a 503 page.
        drupal_maintenance_theme();
        drupal_add_http_header('Status', '503 Service unavailable');
        drupal_set_title(t('Site under maintenance'));
        print theme('maintenance_page', array(
          'content' => filter_xss_admin(variable_get('maintenance_mode_message',
            t('@site is currently under maintenance. We should be back shortly. Thank you for your patience.',
              array('@site' => variable_get('site_name', 'Drupal')))))
        ));
        break;
    }
  }
  elseif (isset($page_callback_result)) {
    // Print anything besides a menu constant, assuming it's not NULL or
    // undefined.

    // until this point, this function is a direct copy and paste of
    // drupal_deliver_html_page but at this stage, instead of rendering a full
    // page with all its theme region content, we just want to render
    // $page_callback_result on its own.

    // As long as we hav a non_empty render_array or string then render the
    // $page_callback_result and return it as it
    if (is_string($page_callback_result) || is_array($page_callback_result)) {
      if (!empty($page_callback_result)) {
        $output = (is_array($page_callback_result) ? $page_callback_result :
          array(
            'main' => array(
              '#markup' => $page_callback_result,
            )
          )
        );
      }

      print drupal_render($output);
    }
  }

  // Perform end-of-request tasks.
  drupal_page_footer();
}

/**
 * Implementation of hook_form_FORM_ID_alter.
 *
 * Add rnd15 specific elements to the donate_pay_in.inc form
 */
function rnd15_donate_form_cr_donate_pay_in_form_alter(&$form, &$form_state, $form_id) {

  // Load in pay-in form specific behaviour
  drupal_add_js(drupal_get_path('module', 'rnd15_donate') . '/js/rnd15.payin.min.js');
  $values = isset($form_state['values']) ? $form_state['values'] : array();
  $form['#submit'][] = "rnd15_donate_pay_in_form_submit_step_1";
  $form['#validate'][] = "rnd15_donate_pay_in_form_validate_step_1";

  // Step 2
  $form['amount']['currency']['#type'] = 'radios';
  $form['amount']['#description'] = '';
  $form['amount']['amount']['#title'] = '';
  $form['amount']['currency']['#title'] = '';
  $form['amount']['currency']['GBP']['#title'] = '&pound;GBP';
  $form['amount']['currency']['EUR']['#title'] = '&euro;EUR';
  $form['amount']['currency']['AUD']['#title'] = '$AUD';
  $form['amount']['currency']['USD']['#title'] = '$USD';
  $form['method']['#description'] = '';
  $form['subscribe']['#description'] = '';
  $form['billing']['#description'] = '';
  $form['previous'] = '';
  $form['billing']['tel'] = '';

  // Step 1
  $form['options']['type']['#title'] = '';

  // Remove promo image
  $form['container']['general']['image'] = '';
  $form['container']['schools']['image'] = '';
  $form['container']['corporate']['image'] = '';

  // Add campaign specific event types to the form.
  $form['container']['general']['general_fields_container']['general_event']['#title'] = ' ';
  $form['container']['general']['general_fields_container']['general_event']['#options'] = array(
    'select' => "Please select",  
    'dance' => "By doing a Danceathon",
    'bake' => "By doing a Bake-off",
    'other' => "Other",
  );
  $form['container']['general']['general_fields_container']['general_event']['#default_value'] = 
    isset($values['general_event']) ? $values['general_event'] : 'Please select';
  $form['container']['corporate']['corporate_fields_container']['corporate_event']['#title'] = ' ';
  $form['container']['corporate']['corporate_fields_container']['corporate_event']['#options'] = array(
    'select' => "Please select",  
    'dance' => "By doing a Danceathon",
    'bake' => "By doing a Bake-off",
    'other' => "Other",
  );
  $form['container']['corporate']['corporate_fields_container']['corporate_event']['#default_value'] =
    isset($values['corporate_event']) ? $values['corporate_event'] : 'Please select';

  // Override the Parsley attributes.
  $form['container']['general']['general_fields_container']['general_event']['#attributes']['parsley-regexp'] = '(dance|bake|other)';
  $form['container']['corporate']['corporate_fields_container']['corporate_event']['#attributes']['parsley-regexp'] = '(dance|bake|other)';

  // Override references to Sport Relief.
  $form['container']['general']['general_fields_container']['general_about']['#title'] =
    "If you've got a second we'd love you to tell us a bit more about what your Red Nose Day fundraising involved";

  $form['container']['corporate']['corporate_fields_container']['corporate_about']['#title'] =
    "If you've got a second we'd love you to tell us a bit more about what your Red Nose Day fundraising involved";

  // Override the label for corporate events
  $label_theme_params = array(
    'element' => array(
      '#title' => ' ',
      '#title_display' => 'before',
      '#id' => 'edit-organisation-dropdown',
    ),
  );
  $form['container']['corporate']['corporate_fields_container']['organisation']['dropdown_label'] = array(
    '#markup' => theme('form_element_label', $label_theme_params),
  );

  $form['container']['schools']['schools_fields_container']['establishment_type'] = array(
    '#type' => 'rnd15_establishment_type',
  );

  // Override the corporate partners
  $org_list_options_conf = <<<ORG_LIST_OPTIONS
Please Select
Armakuni
Babybel
Barclays
British Airways
BT
Carrenza
Cisco
Claire’s
COTY
EY
Hewlett Packard
Mars
NCC Group
Oxfam
PayPal
Pottermore
Robert Dyas
Ryman
Sainsbury’s
Specsavers
TJX Europe
Toyota
Unilever
University
Weetabix
WorldPay
Youth Group
Other
ORG_LIST_OPTIONS;

  $org_options = drupal_map_assoc(explode("\n", $org_list_options_conf));
  $form['container']['corporate']['corporate_fields_container']['organisation']['organisation_dropdown'] = array(
    '#type' => 'select',
    '#title' => ' ',
    '#options' => $org_options,
    '#default_value' => isset($values['organisation_dropdown']) ? $values['organisation_dropdown'] : 'Please Select',
    '#attributes' => array(
      'parsley-regexp' => '(Armakuni|Babybel|Barclays|British Airways|BT|Carrenza|Cisco|Claire’s|COTY|'.
        'EY|Hewlett Packard|Mars|NCC Group|Oxfam|PayPal|Pottermore|Robert Dyas|Ryman|Sainsbury’s|'.
        'Specsavers|TJX Europe|Toyota|Unilever|University|Weetabix|WorldPay|Youth Group|Other)',
      'parsley-trigger' => 'blur change',
      'parsley-error-message' => 'Please select your partner',
    ),
  );
}

/**
 * Implements hook_element_info_alter
 */
function rnd15_donate_element_info_alter(&$type) {
  if (isset($type['cr_eddirect_area_job']['#process'][0])) {
    $type['cr_eddirect_area_job']['#process'][0] = 'rnd15_donate_area_job_element_process';
  }
}

/**
 * Overridden Process callback for the edDirect element. The base form element is modified to show a rnd15 specific set of options.
 */
function rnd15_donate_area_job_element_process($element, $form_state = array(), $complete_form = array()) {  
  $element['job_title'] = array(
    '#type' => 'select',
    '#title' => t('Job title') . ' ' . theme('form_required_marker'),
    '#default_value' => 'Please Select',
    '#options' => drupal_map_assoc(array(
      'Please Select',  
      'Head Teacher',
      'Administrative Staff',
      'Senior Management',
      'Teacher',
      'Charity Coordinator',
      'PSHE Coordinator',
      'Childminder',
      'Support Staff',
      'Nursery Manager',
      'Early Years Practitioner',
      'SEN Department',
      'Other',
    )),
    '#attributes' => array(
      'parsley-regexp' => '(Head Teacher|Administrative Staff|Senior Management|Teacher|Charity Coordinator|' .
        'PSHE Coordinator|Childminder|Support Staff|Nursery Manager|Early Years Practitioner|SEN Department|Other)',
        'parsley-trigger' => 'blur change',
        'parsley-error-message' => 'Please choose a job title',
      ),
  );
  return $element;
}

/**
 * Implements hook_element_info().
 */
function rnd15_donate_element_info() {
  $type['rnd15_establishment_type'] = array(
    '#input' => TRUE,
    '#skip_validation' => FALSE,
    '#process' => array('rnd15_donate_establishment_type_element_process'),
    // commenting out validate functiton as we want to call this manually from the containing forms validation
    // function as this element is not always visible, and thus should not always be validated
    //'#element_validate' => array('rnd15_donate_establishment_type_element_validate'),
    '#theme_wrappers' => array('form_element'),
  );

  return $type;
}

/**
 * Process callback for the rnd15_donate_establishment_type element.
 */
function rnd15_donate_establishment_type_element_process($element, $form_state = array(), $complete_form = array()) {
  $element['establishment_type'] = array(
    '#type' => 'select',
    '#title' => t('Establishment Type') . ' ' . theme('form_required_marker'),
    '#default_value' => 'Please select',
    '#options' => drupal_map_assoc(array(
      'Please select',
      'Nursery',
      'Primary School',
      'Secondary School',
      'Sixth Form/FE College',
    )),
	'#attributes' => array(
      'parsley-regexp' => '(Nursery|Primary School|Secondary School|Sixth Form/FE College)',
      'parsley-trigger' => 'blur change',
      'parsley-error-message' => 'Please choose an establishment type',
    ),
  );
  return $element;
}

/**
 * Validation callback for fundraising paying in form, step 1.
 * This callback is added to the validation handlers for the rnd15 version of the paying in form,
 * in order to stop the user from submitting the select value.
 */
function rnd15_donate_pay_in_form_validate_step_1($form, &$form_state) {
  switch ($form_state['values']['type']) {
    case 'schools':
      if ($form_state['values']['establishment_type'] === 'Please select') {
        form_set_error('establishment_type', 'Please choose an establishment type');
      }
      if ($form_state['values']['job_title'] === 'Please select') {
          form_set_error('job_title', 'Please choose a job title');
      }
    break;
  }
}

/**
 * Submit callback for fundraising paying in form, step 1.
 * This callback is added to the submit handlers for the rnd15 version of the paying in form,
 * in order to add the establishment type to the form, for a schools pay in.
 */
function rnd15_donate_pay_in_form_submit_step_1($form, &$form_state) {
  if (isset($form_state['values']['type']) && ($form_state['values']['type'] == 'schools')) {
    $data = array();
    $organisation = $form_state['values']['establishment_type'];
    $data += array(
      'schoolType' => $organisation,
    );
    $form_state['data'] += $data;
  }
}
