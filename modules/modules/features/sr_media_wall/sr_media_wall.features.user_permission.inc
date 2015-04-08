<?php
/**
 * @file
 * sr_media_wall.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function sr_media_wall_user_default_permissions() {
  $permissions = array();

  // Exported permission: create any media_wall bean.
  $permissions['create any media_wall bean'] = array(
    'name' => 'create any media_wall bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site builder' => 'site builder',
    ),
    'module' => 'bean',
  );

  // Exported permission: delete any media_wall bean.
  $permissions['delete any media_wall bean'] = array(
    'name' => 'delete any media_wall bean',
    'roles' => array(
      'site builder' => 'site builder',
    ),
    'module' => 'bean',
  );

  // Exported permission: edit any media_wall bean.
  $permissions['edit any media_wall bean'] = array(
    'name' => 'edit any media_wall bean',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
      'digital pm' => 'digital pm',
      'marketing (general)' => 'marketing (general)',
      'site builder' => 'site builder',
    ),
    'module' => 'bean',
  );

  // Exported permission: view any media_wall bean.
  $permissions['view any media_wall bean'] = array(
    'name' => 'view any media_wall bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site builder' => 'site builder',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
