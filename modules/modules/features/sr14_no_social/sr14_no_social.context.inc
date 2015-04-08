<?php
/**
 * @file
 * sr14_no_social.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sr14_no_social_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'no-social';
  $context->description = 'Pages that should not have social share links anywhere';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'play-games' => 'play-games',
        'play-games/*' => 'play-games/*',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'no-social',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Pages that should not have social share links anywhere');
  $export['no-social'] = $context;

  return $export;
}
