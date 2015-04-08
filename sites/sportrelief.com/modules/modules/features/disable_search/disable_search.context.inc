<?php
/**
 * @file
 * disable_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function disable_search_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'disable_search';
  $context->description = 'disables search';
  $context->tag = 'Header and footer';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block_disable' => array(
      'blocks' => array(
        'boxes' => array(
          'boxes-search_header' => 'boxes-search_header',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Header and footer');
  t('disables search');
  $export['disable_search'] = $context;

  return $export;
}
