<?php
/**
 * @file
 * cr_news.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function cr_news_taxonomy_default_vocabularies() {
  return array(
    'media_bar_section' => array(
      'name' => 'Media Bar Section',
      'machine_name' => 'media_bar_section',
      'description' => 'Multiple sections where the media bar should be tagged with',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
