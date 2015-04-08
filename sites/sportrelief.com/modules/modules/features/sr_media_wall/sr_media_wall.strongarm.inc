<?php
/**
 * @file
 * sr_media_wall.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function sr_media_wall_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_bean__media_wall';
  $strongarm->value = array(
    'view_modes' => array(
      'media_wall' => array(
        'custom_settings' => TRUE,
      ),
      'default' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'redirect' => array(
          'weight' => '6',
        ),
      ),
      'display' => array(
        'title' => array(
          'default' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'media_wall' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_bean__media_wall'] = $strongarm;

  return $export;
}
