<?php
/**
 * @file
 * sr_schools.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function sr_schools_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Primary schools',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => 0,
    'uuid' => '538d1a48-c7b5-4d5c-a493-f4a7500aff43',
    'vocabulary_machine_name' => 'schools_toolbox_category',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Secondary schools',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => 0,
    'uuid' => 'c6fdfc46-1d37-4368-be52-b9dedd6883ec',
    'vocabulary_machine_name' => 'schools_toolbox_category',
    'metatags' => array(),
  );
  return $terms;
}
