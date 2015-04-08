<?php
/**
 * @file
 * sr_schools.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function sr_schools_taxonomy_default_vocabularies() {
  return array(
    'schools_toolbox_category' => array(
      'name' => 'Schools Toolbox Category',
      'machine_name' => 'schools_toolbox_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
