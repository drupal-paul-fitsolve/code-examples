<?php
/**
 * @file
 * sr_layout_base.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sr_layout_base_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'base_page_layout';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/appearance/styleguide' => 'admin/appearance/styleguide',
        'user' => 'user',
        'users/*' => 'users/*',
      ),
    ),
  );
  $context->reactions = array(
    'delta' => array(
      'delta_template' => 'basic_page',
    ),
  );
  $context->condition_mode = 0;
  $export['base_page_layout'] = $context;

  return $export;
}
