<?php
/**
 * @file
 * sr_media_wall.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function sr_media_wall_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'media_wall';
  $bean_type->label = 'Media Wall';
  $bean_type->options = '';
  $bean_type->description = 'Media wall, which is another take on the media bar';
  $export['media_wall'] = $bean_type;

  return $export;
}
