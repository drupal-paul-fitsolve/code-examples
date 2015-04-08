<?php
/**
 * @file
 * sr_play_games_landing_body_class.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sr_play_games_landing_body_class_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'play_games_body_class';
  $context->description = '';
  $context->tag = 'Fun and Games';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'play-games' => 'play-games',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'play-games-landing-page',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Fun and Games');
  $export['play_games_body_class'] = $context;

  return $export;
}
