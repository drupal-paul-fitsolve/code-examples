<?php
/**
 * @file
 * site_building.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function site_building_user_default_roles() {
  $roles = array();

  // Exported role: site builder.
  $roles['site builder'] = array(
    'name' => 'site builder',
    'weight' => 3,
  );

  return $roles;
}
