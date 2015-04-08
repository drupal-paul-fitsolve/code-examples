<?php
/**
 * @file
 * sr_media_wall.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function sr_media_wall_taxonomy_default_vocabularies() {
  return array(
    'media_wall' => array(
      'name' => 'Media Wall Content Tag',
      'machine_name' => 'media_wall',
      'description' => 'Set the media wall type here',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
