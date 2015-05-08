<?php
/**
 * @file
 * rnd15_fundraiser_showcase.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function rnd15_fundraiser_showcase_user_default_roles() {
  $roles = array();

  // Exported role: fundraiser showcase moderator.
  $roles['fundraiser showcase moderator'] = array(
    'name' => 'fundraiser showcase moderator',
    'weight' => 8,
  );

  return $roles;
}
