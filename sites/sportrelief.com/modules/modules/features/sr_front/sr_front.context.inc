<?php
/**
 * @file
 * sr_front.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sr_front_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front';
  $context->description = '';
  $context->tag = 'front';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
        'front001' => 'front001',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-8' => array(
          'module' => 'block',
          'delta' => '8',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('front');
  $export['front'] = $context;

  return $export;
}
