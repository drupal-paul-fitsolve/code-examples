<?php
/**
 * @file
 * cr_media_image.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function cr_media_image_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'media_images';
  $context->description = 'Media Images';
  $context->tag = 'media images';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'media_images' => 'media_images',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'delta_blocks-tabs' => array(
          'module' => 'delta_blocks',
          'delta' => 'tabs',
          'region' => 'preface_first',
          'weight' => '-10',
        ),
        'delta_blocks-messages' => array(
          'module' => 'delta_blocks',
          'delta' => 'messages',
          'region' => 'preface_first',
          'weight' => '-9',
        ),
        'delta_blocks-breadcrumb' => array(
          'module' => 'delta_blocks',
          'delta' => 'breadcrumb',
          'region' => 'breadcrumb',
          'weight' => '-10',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'content_page',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Media Images');
  t('media images');
  $export['media_images'] = $context;

  return $export;
}
