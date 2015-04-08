<?php
/**
 * @file
 * sr_media_wall.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function sr_media_wall_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'TV Pick',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => 4,
    'uuid' => '13f76040-6135-4192-aee1-490b01d602a5',
    'vocabulary_machine_name' => 'media_wall',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Events',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => 0,
    'uuid' => '24ff4be8-de8e-44e3-8a24-5b78e2efbd72',
    'vocabulary_machine_name' => 'media_wall',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Schools',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => 3,
    'uuid' => '3f0bb8aa-a076-4246-9743-001104fd25cb',
    'vocabulary_machine_name' => 'media_wall',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'News',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => 2,
    'uuid' => 'c2e8612a-31fb-46cb-915d-cb1a917f6e53',
    'vocabulary_machine_name' => 'media_wall',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Merchandise',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => 1,
    'uuid' => 'e4701cb8-cde1-4a53-b1fb-5b60ed5bb77a',
    'vocabulary_machine_name' => 'media_wall',
    'metatags' => array(),
  );
  return $terms;
}
