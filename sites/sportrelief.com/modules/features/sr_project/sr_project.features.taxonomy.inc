<?php
/**
 * @file
 * sr_project.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function sr_project_taxonomy_default_vocabularies() {
  return array(
    'project_region' => array(
      'name' => 'Project Region',
      'machine_name' => 'project_region',
      'description' => 'List of regions for Sport relief projects',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
