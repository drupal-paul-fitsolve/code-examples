<?php
/**
 * @file
 * CR Event Map module
 */

/**
 * Define theme templates.
 */
function theme_cr_event_map_search(&$variables) {
 	return render($variables['element']['children']);
}

function theme_cr_event_map_search_textfield(&$variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'text';
  element_set_attributes($element, array('id', 'name', 'value', 'size', 'maxlength'));
  _form_set_class($element, array('form-text'));

  $extra = '';
  if ($element['#autocomplete_path'] && drupal_valid_path($element['#autocomplete_path'])) {
    drupal_add_library('system', 'drupal.autocomplete');
    $element['#attributes']['class'][] = 'form-autocomplete';

    $attributes = array();
    $attributes['type'] = 'hidden';
    $attributes['id'] = $element['#attributes']['id'] . '-autocomplete';
    $attributes['value'] = url($element['#autocomplete_path'], array('absolute' => TRUE));
    $attributes['disabled'] = 'disabled';
    $attributes['class'][] = 'autocomplete';
    $extra = '<input' . drupal_attributes($attributes) . ' />';
  }

  $output = '<input' . drupal_attributes($element['#attributes']) . ' />';

  return $output . $extra;
}

/**
 * Preprocess the CR Event Map output render call
 * Provides the necessary JS files and settings to load the map
 */
function cr_event_map_preprocess_cr_event_map_gmap(&$variables) {
  $js_map_settings = array('cr_event_map' => 
    array(
    	'map_container_selector' => '#'.$variables['element']['#map_container_id'],
      'apikey' => $variables['element']['#apikey'],
      'tableid' => $variables['element']['#tableid'],
      'default_filter' => $variables['element']['#default_filter'],
      'filter_markers' => marker_as_base64($variables['element']['#filter_markers']),
      'marker_limit' => $variables['element']['#marker_limit'],
      'map_settings' => $variables['element']['#map_settings']
    )
  );

  drupal_add_css(drupal_get_path('module', 'cr_event_map') . '/cr_event_map.css',array('group' => CSS_DEFAULT, 'every_page' => FALSE));
  drupal_add_js('https://maps.googleapis.com/maps/api/js?key='.$js_map_settings['cr_event_map']['apikey'].'&sensor=true', array('type' => 'external', 'weight' => 200));
  drupal_add_js(drupal_get_path('module', 'cr_event_map') . '/infobubble_custom.js', array('type' => 'file', 'weight' => 201));
  drupal_add_js(drupal_get_path('module', 'cr_event_map') . '/cr_event_map.js', array('type' => 'file', 'weight' => 202));
  drupal_add_js($js_map_settings, 'setting');

  $variables['map_container_id'] = $variables['element']['#map_container_id'];
}

function marker_as_base64($filter_markers) {
  global $base_path;
	$markers_base64 = array();
	foreach($filter_markers as $name => $marker_file) {
    if(strpos($marker_file, 'http') === false) {
      $file_path = $_SERVER['DOCUMENT_ROOT'] . $base_path . $marker_file;
    } else {
      $file_path = $marker_file;
    }
    if(file_exists($file_path)) {
		  $markers_base64[$name] = base64_encode(file_get_contents($file_path));
    } else {
      watchdog('cr_event_map', 'Could not generate map markers: ', array('%file' => $file_path), WATCHDOG_ERROR);
    }
	}
	return $markers_base64;
}