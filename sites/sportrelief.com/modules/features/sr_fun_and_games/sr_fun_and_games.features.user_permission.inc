<?php
/**
 * @file
 * sr_fun_and_games.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function sr_fun_and_games_user_default_permissions() {
  $permissions = array();

  // Exported permission: add new pledges.
  $permissions['add new pledges'] = array(
    'name' => 'add new pledges',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'cr_ig',
  );

  // Exported permission: administer pledges.
  $permissions['administer pledges'] = array(
    'name' => 'administer pledges',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'cr_ig',
  );

  return $permissions;
}
