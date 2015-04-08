<?php
/**
 * @file
 * sr_schools.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sr_schools_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'schools_general';
  $context->description = '';
  $context->tag = 'Schools';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'schools*' => 'schools*',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Schools');
  $export['schools_general'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'schools_landing';
  $context->description = '';
  $context->tag = 'Schools';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'schools' => 'schools',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'schools-landing',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Schools');
  $export['schools_landing'] = $context;

  return $export;
}
