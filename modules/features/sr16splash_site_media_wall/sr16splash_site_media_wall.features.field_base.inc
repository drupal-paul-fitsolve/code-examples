<?php
/**
 * @file
 * sr16splash_site_media_wall.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function sr16splash_site_media_wall_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_site_media_wall_badge'
  $field_bases['field_site_media_wall_badge'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_site_media_wall_badge',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'none' => 'No Badge',
        'news' => 'News',
        'event' => 'Event',
        'video' => 'Video',
        'photo' => 'Photo',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
