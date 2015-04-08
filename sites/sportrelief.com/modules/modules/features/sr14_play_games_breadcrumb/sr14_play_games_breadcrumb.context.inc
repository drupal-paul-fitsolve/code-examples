<?php
/**
 * @file
 * sr14_play_games_breadcrumb.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sr14_play_games_breadcrumb_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'play_games_override_breadcrumb';
  $context->description = 'Override the breadcrumb for /play-games';
  $context->tag = 'Fun and Games';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/384' => 'node/384',
        'play-games' => 'play-games',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'playgames',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Fun and Games');
  t('Override the breadcrumb for /play-games');
  $export['play_games_override_breadcrumb'] = $context;

  return $export;
}
