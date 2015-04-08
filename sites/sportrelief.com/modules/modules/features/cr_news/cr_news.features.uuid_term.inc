<?php
/**
 * @file
 * cr_news.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function cr_news_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'home',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => 0,
    'uuid' => '41fa4c70-b1e1-4216-84e1-ed673f834a72',
    'vocabulary_machine_name' => 'media_bar_section',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Nurseries',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => 0,
    'uuid' => '4f337686-80c8-412e-bc62-2d1f8c2b0bf8',
    'vocabulary_machine_name' => 'media_bar_section',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Primary',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => 0,
    'uuid' => '85a7b465-4824-4a77-9b6f-682b875ae3ab',
    'vocabulary_machine_name' => 'media_bar_section',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Fun and games',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => 0,
    'uuid' => '86f02507-06ed-410e-aa3f-52e9e9e7c127',
    'vocabulary_machine_name' => 'media_bar_section',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Secondary',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => 0,
    'uuid' => 'ef1b4259-9dd3-4296-bd4f-a3f143e07801',
    'vocabulary_machine_name' => 'media_bar_section',
    'metatags' => array(),
  );
  return $terms;
}
