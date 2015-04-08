<?php
/**
 * @file
 * sr_media_bar.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function sr_media_bar_user_default_permissions() {
  $permissions = array();

  // Exported permission: create any media_bar bean.
  $permissions['create any media_bar bean'] = array(
    'name' => 'create any media_bar bean',
    'roles' => array(
      'site builder' => 'site builder',
    ),
    'module' => 'bean',
  );

  // Exported permission: create any twitter_bar bean.
  $permissions['create any twitter_bar bean'] = array(
    'name' => 'create any twitter_bar bean',
    'roles' => array(
      'site builder' => 'site builder',
    ),
    'module' => 'bean',
  );

  // Exported permission: delete any media_bar bean.
  $permissions['delete any media_bar bean'] = array(
    'name' => 'delete any media_bar bean',
    'roles' => array(
      'site builder' => 'site builder',
    ),
    'module' => 'bean',
  );

  // Exported permission: delete any twitter_bar bean.
  $permissions['delete any twitter_bar bean'] = array(
    'name' => 'delete any twitter_bar bean',
    'roles' => array(
      'site builder' => 'site builder',
    ),
    'module' => 'bean',
  );

  // Exported permission: edit any media_bar bean.
  $permissions['edit any media_bar bean'] = array(
    'name' => 'edit any media_bar bean',
    'roles' => array(
      'site builder' => 'site builder',
    ),
    'module' => 'bean',
  );

  // Exported permission: edit any twitter_bar bean.
  $permissions['edit any twitter_bar bean'] = array(
    'name' => 'edit any twitter_bar bean',
    'roles' => array(
      'site builder' => 'site builder',
    ),
    'module' => 'bean',
  );

  // Exported permission: view any media_bar bean.
  $permissions['view any media_bar bean'] = array(
    'name' => 'view any media_bar bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site builder' => 'site builder',
    ),
    'module' => 'bean',
  );

  // Exported permission: view any twitter_bar bean.
  $permissions['view any twitter_bar bean'] = array(
    'name' => 'view any twitter_bar bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site builder' => 'site builder',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
