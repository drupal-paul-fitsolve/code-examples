<?php
/**
 * @file
 * sr_media_bar.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function sr_media_bar_user_default_roles() {
  $roles = array();

  // Exported role: content editor.
  $roles['content editor'] = array(
    'name' => 'content editor',
    'weight' => 6,
  );

  // Exported role: digital pm.
  $roles['digital pm'] = array(
    'name' => 'digital pm',
    'weight' => 5,
  );

  // Exported role: marketing (general).
  $roles['marketing (general)'] = array(
    'name' => 'marketing (general)',
    'weight' => 7,
  );

  return $roles;
}
