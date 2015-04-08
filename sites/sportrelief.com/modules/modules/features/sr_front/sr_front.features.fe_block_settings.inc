<?php
/**
 * @file
 * sr_front.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function sr_front_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-event_microformat'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'machine_name' => 'event_microformat',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'cr_layout' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'cr_layout',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'sport_relief' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sport_relief',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
