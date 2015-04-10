<?php
/**
 * @file
 * sr_media_wall_images.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function sr_media_wall_images_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Instagram',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => 0,
    'uuid' => '2ae8a065-d758-4d4a-80ee-d4dcc3ae5c94',
    'vocabulary_machine_name' => 'tags',
    'metatags' => array(),
  );
  return $terms;
}
