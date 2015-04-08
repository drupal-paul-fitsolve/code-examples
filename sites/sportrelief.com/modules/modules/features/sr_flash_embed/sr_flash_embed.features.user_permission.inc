<?php
/**
 * @file
 * sr_flash_embed.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function sr_flash_embed_user_default_permissions() {
  $permissions = array();

  // Exported permission: create fieldable flash_embed.
  $permissions['create fieldable flash_embed'] = array(
    'name' => 'create fieldable flash_embed',
    'roles' => array(),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: delete fieldable flash_embed.
  $permissions['delete fieldable flash_embed'] = array(
    'name' => 'delete fieldable flash_embed',
    'roles' => array(),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: edit fieldable flash_embed.
  $permissions['edit fieldable flash_embed'] = array(
    'name' => 'edit fieldable flash_embed',
    'roles' => array(),
    'module' => 'fieldable_panels_panes',
  );

  return $permissions;
}
