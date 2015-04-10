<?php
/**
 * @file
 * sr_project.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function sr_project_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-project-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'project-block',
    'module' => 'views',
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
