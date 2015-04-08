<?php
/**
 * @file
 * sr_fundraising_leaderboards.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function sr_fundraising_leaderboards_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['panels_mini-leaderboard1'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'leaderboard1',
    'module' => 'panels_mini',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
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

  $export['panels_mini-leaderboard_cycle'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'leaderboard_cycle',
    'module' => 'panels_mini',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
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

  $export['panels_mini-leaderboard_freestyle'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'leaderboard_freestyle',
    'module' => 'panels_mini',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
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

  $export['panels_mini-leaderboard_swim'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'leaderboard_swim',
    'module' => 'panels_mini',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
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
