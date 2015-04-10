<?php
/**
 * @file
 * what_we_do.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function what_we_do_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'spend-areas';
  $context->description = 'Page styling for the spend areas section in what-we-do';
  $context->tag = 'what-we-do';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'what-we-do' => 'what-we-do',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'spend-areas',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Page styling for the spend areas section in what-we-do');
  t('what-we-do');
  $export['spend-areas'] = $context;

  return $export;
}
