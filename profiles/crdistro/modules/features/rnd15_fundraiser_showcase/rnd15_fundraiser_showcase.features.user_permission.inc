<?php
/**
 * @file
 * rnd15_fundraiser_showcase.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function rnd15_fundraiser_showcase_user_default_permissions() {
  $permissions = array();

  // Exported permission: create fundraiser_showcase content.
  $permissions['create fundraiser_showcase content'] = array(
    'name' => 'create fundraiser_showcase content',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any fundraiser_showcase content.
  $permissions['delete any fundraiser_showcase content'] = array(
    'name' => 'delete any fundraiser_showcase content',
    'roles' => array(
      'developer' => 'developer',
      'fundraiser showcase moderator' => 'fundraiser showcase moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own fundraiser_showcase content.
  $permissions['delete own fundraiser_showcase content'] = array(
    'name' => 'delete own fundraiser_showcase content',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any fundraiser_showcase content.
  $permissions['edit any fundraiser_showcase content'] = array(
    'name' => 'edit any fundraiser_showcase content',
    'roles' => array(
      'developer' => 'developer',
      'fundraiser showcase moderator' => 'fundraiser showcase moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own fundraiser_showcase content.
  $permissions['edit own fundraiser_showcase content'] = array(
    'name' => 'edit own fundraiser_showcase content',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  return $permissions;
}
