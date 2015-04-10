<?php
/**
 * @file
 * partners.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function partners_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Official Partners',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => 0,
    'uuid' => '5c8ec6f2-2c2b-436b-ad98-47c8304c61d1',
    'vocabulary_machine_name' => 'partner_categories',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Sport Relief initiatives',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => 0,
    'uuid' => '5e24cf51-6e29-413d-b75c-7846d257dcc8',
    'vocabulary_machine_name' => 'partner_categories',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Headline Sponsor',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => 0,
    'uuid' => '6d046c38-95fc-4ac2-9e31-fb6e9bf4c7b3',
    'vocabulary_machine_name' => 'partner_categories',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Supporting Partners',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => 0,
    'uuid' => 'dc3905f5-c7fd-49af-9e15-f2800fb5df75',
    'vocabulary_machine_name' => 'partner_categories',
    'metatags' => array(),
  );
  return $terms;
}
