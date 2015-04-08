<?php
/**
 * @file
 * sr_media_bar.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function sr_media_bar_taxonomy_default_vocabularies() {
  return array(
    'twitter_tags' => array(
      'name' => 'Twitter Tags',
      'machine_name' => 'twitter_tags',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
