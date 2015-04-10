<?php
/**
 * @file
 * Listing bean plugin.
 */

class EventMapBean extends BeanPlugin {
  /**
   * Declares default block settings.
   */
  public function values() {
    $values = array(
      'settings' => array(
        'kml_source' => 0,
        'default_filter' => 'all',
        'filter_types' => array(
          'all' => 'All',
          'run' => 'Mile',
          'swim' => 'Swimathon',
          'cycle' => 'Cycle',
          
        ),
        'marker_limit' => 10,
        'markers' => array(
          'run' => 'http://maps.gstatic.com/intl/en_ALL/mapfiles/ms/micons/red-dot.png',
          'cycle' => 'http://maps.gstatic.com/intl/en_ALL/mapfiles/ms/micons/yellow-dot.png',
          'swim' => 'http://maps.gstatic.com/intl/en_ALL/mapfiles/ms/micons/blue-dot.png',
        ),
        'map' => array(
          'default_position' => '53.943155,-2.373047',
          'default_zoom' => 6,
          'default_searchzoom' => 11,
          'breakpoints' => array(
            'mobile' => array('height' => 200),
            'narrow' => array('height' => 300),
            'normal' => array('height' => 450),
            'wide' => array('height' => 600),
          ),
        ),
      ),
    );
    return array_merge(parent::values(), $values);
  }
  /**
   * Builds extra settings for the block edit form.
   */
  public function form($bean, $form, &$form_state) {
    $form = array();
    $form['settings'] = array(
      '#type' => 'fieldset',
      '#tree' => 1,
      '#title' => t('Output'),
    );

    $default_values = $this->values();

    $kmls = unserialize(variable_get('cr_event_map_kmls'));

    $gapi = unserialize(variable_get('cr_event_map_gapi_settings'));

    if(count($kmls) == 0) {
      drupal_set_message('Please define some KML files on the CR Event Map Settings page.', 'error');
      return $form;
    }

    if(!isset($gapi['apikey']) || empty($gapi['apikey'])) {
      drupal_set_message('Please set the Google API Key on the CR Event Map Settings page.', 'error');
      return $form;
    }

    $kml_types = array();
    foreach($kmls as $kml) {
      $kml_types[] = $kml['name'];
    }

    $form['settings']['kml_source'] = array(
      '#type' => 'select',
      '#title' => t('KML Source'),
      '#options' => $kml_types,
      '#default_value' => $bean->settings['kml_source'],
      '#required' => TRUE,
      '#multiple' => FALSE,
    );
    
    $form['settings']['default_filter'] = array(
      '#type' => 'select',
      '#title' => t('Default Filter'),
      '#options' => $default_values['settings']['filter_types'],
      '#default_value' => $bean->settings['default_filter'],
      '#required' => TRUE,
      '#multiple' => FALSE,
    );

    $form['settings']['marker_limit'] = array(
      '#type' => 'textfield',
      '#size' => 4,
      '#title' => t("Number of Markers to show"),
      '#default_value' => $bean->settings['marker_limit'],
    );

    $form['settings']['markers'] = array(
      '#type' => 'fieldset',
      '#title' => t('Type Markers'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['settings']['markers']['run'] = array(
      '#type' => 'textfield',
      '#size' => 60,
      '#title' => t("Run Marker"),
      '#default_value' => $bean->settings['markers']['run'],
      '#description' => t('Local path or URL. If using a local path, start at the docroot with no slash at the beginning .e.g &ldquo;sites/default...&rdquo;.'),
    );
    $form['settings']['markers']['cycle'] = array(
      '#type' => 'textfield',
      '#size' => 60,
      '#title' => t("Cycle Marker"),
      '#default_value' => $bean->settings['markers']['cycle'],
      '#description' => t('Local path or URL. If using a local path, start at the docroot with no slash at the beginning .e.g &ldquo;sites/default...&rdquo;.'),
    );
    $form['settings']['markers']['swim'] = array(
      '#type' => 'textfield',
      '#size' => 60,
      '#title' => t("Swim Marker"),
      '#default_value' => $bean->settings['markers']['swim'],
      '#description' => t('Local path or URL. If using a local path, start at the docroot with no slash at the beginning .e.g &ldquo;sites/default...&rdquo;.'),
    );

    $form['settings']['map'] = array(
      '#type' => 'fieldset',
      '#title' => t('Map Settings'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    
    $form['settings']['map']['default_zoom'] = array(
      '#type' => 'textfield',
      '#size' => 4,
      '#title' => t("Default Map Zoom on load with no results."),
      '#default_value' => $bean->settings['map']['default_zoom'],
    );
    $form['settings']['map']['default_searchzoom'] = array(
      '#type' => 'textfield',
      '#size' => 4,
      '#title' => t("Default Map Zoom with results."),
      '#default_value' => $bean->settings['map']['default_searchzoom'],
    );
    $form['settings']['map']['default_position'] = array(
      '#type' => 'textfield',
      '#size' => 20,
      '#title' => t("Default LNG/LTD Position"),
      '#default_value' => $bean->settings['map']['default_position'],
    );
    $form['settings']['map']['breakpoints']['mobile']['height'] = array(
      '#type' => 'textfield',
      '#size' => 6,
      '#title' => t("Mobile Height (px)"),
      '#default_value' => $bean->settings['map']['breakpoints']['mobile']['height'],
    );
    $form['settings']['map']['breakpoints']['narrow']['height'] = array(
      '#type' => 'textfield',
      '#size' => 6,
      '#title' => t("Narrow Height (px)"),
      '#default_value' => $bean->settings['map']['breakpoints']['narrow']['height'],
    );
    $form['settings']['map']['breakpoints']['normal']['height'] = array(
      '#type' => 'textfield',
      '#size' => 6,
      '#title' => t("Normal Height (px)"),
      '#default_value' => $bean->settings['map']['breakpoints']['normal']['height'],
    );
    $form['settings']['map']['breakpoints']['wide']['height'] = array(
      '#type' => 'textfield',
      '#size' => 6,
      '#title' => t("Wide Height (px)"),
      '#default_value' => $bean->settings['map']['breakpoints']['wide']['height'],
    );


    return $form;
  }

  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    $default_values = $this->values();
    $kmls = unserialize(variable_get('cr_event_map_kmls'));
    $gapi_settings = unserialize(variable_get('cr_event_map_gapi_settings'));
    
    $content['search'] = array(
      '#theme' => 'cr_event_map_search',
      'children' => drupal_get_form('cr_event_map_search_form', $default_values['settings']['filter_types'], $bean->settings['default_filter'], $bean->title)
    );

    $content['map'] = array(
      '#theme' => 'cr_event_map_gmap',
      '#map_container_id' => 'gmap-container',
      '#title' => $bean->title,
      '#tableid' => $kmls[$bean->settings['kml_source']]['tableid'],
      '#apikey' => $gapi_settings['apikey'],
      '#default_filter' => $bean->settings['default_filter'],
      '#filter_markers' => $bean->settings['markers'],
      '#marker_limit' => $bean->settings['marker_limit'],
      '#map_settings' => $bean->settings['map'],
    );

    return $content;
  }
}
