<?php
/**
 * @file
 * action_pod.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function action_pod_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_fieldable_panels_pane__action_pod';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'basic_pod_reverse' => array(
        'custom_settings' => FALSE,
      ),
      'flexslider_carousel_thumb' => array(
        'custom_settings' => FALSE,
      ),
      'flexslider_grid_16' => array(
        'custom_settings' => FALSE,
      ),
      'flexslider_main_slide' => array(
        'custom_settings' => FALSE,
      ),
      'intro_headline_huge' => array(
        'custom_settings' => FALSE,
      ),
      'tabs_grid_18' => array(
        'custom_settings' => FALSE,
      ),
      'tabs_grid_24' => array(
        'custom_settings' => FALSE,
      ),
      'grid_4' => array(
        'custom_settings' => FALSE,
      ),
      'grid_6' => array(
        'custom_settings' => FALSE,
      ),
      'grid_8' => array(
        'custom_settings' => FALSE,
      ),
      'grid_9' => array(
        'custom_settings' => FALSE,
      ),
      'grid_12' => array(
        'custom_settings' => FALSE,
      ),
      'grid_13' => array(
        'custom_settings' => FALSE,
      ),
      'grid_14' => array(
        'custom_settings' => FALSE,
      ),
      'grid_16' => array(
        'custom_settings' => FALSE,
      ),
      'grid_18' => array(
        'custom_settings' => FALSE,
      ),
      'grid_20' => array(
        'custom_settings' => FALSE,
      ),
      'grid_22' => array(
        'custom_settings' => FALSE,
      ),
      'grid_24' => array(
        'custom_settings' => FALSE,
      ),
      'basic_pod' => array(
        'custom_settings' => FALSE,
      ),
      'intro' => array(
        'custom_settings' => FALSE,
      ),
      'list_view' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'image_first' => array(
        'custom_settings' => FALSE,
      ),
      'grid_2' => array(
        'custom_settings' => FALSE,
      ),
      'grid_15' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
      ),
      'display' => array(
        'title' => array(
          'default' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_fieldable_panels_pane__action_pod'] = $strongarm;

  return $export;
}
