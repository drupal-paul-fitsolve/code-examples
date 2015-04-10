<?php
/**
 * @file
 * sr_fun_and_games.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sr_fun_and_games_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'fun_and_games_background';
  $context->description = '';
  $context->tag = 'Fun and Games';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'fun-and-games' => 'fun-and-games',
        'fun-and-games/*' => 'fun-and-games/*',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'kids-bg',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Fun and Games');
  $export['fun_and_games_background'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'fun_and_games_background_pledge';
  $context->description = 'The background for the pledge page';
  $context->tag = 'Fun and Games';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'fun-and-games/ideas-generator' => 'fun-and-games/ideas-generator',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'kids-pledge-bg',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Fun and Games');
  t('The background for the pledge page');
  $export['fun_and_games_background_pledge'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'fun_games_content';
  $context->description = 'Is this content going to be displayed on the fun and games section';
  $context->tag = 'Fun and Games';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        60 => 60,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Fun and Games');
  t('Is this content going to be displayed on the fun and games section');
  $export['fun_games_content'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sport_relief_no_social';
  $context->description = '';
  $context->tag = 'Header and footer';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        60 => 60,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'fun-and-games' => 'fun-and-games',
        'fun-and-games/*' => 'fun-and-games/*',
      ),
    ),
  );
  $context->reactions = array(
    'block_disable' => array(
      'blocks' => array(
        'block' => array(
          'block-4' => 'block-4',
        ),
        'boxes' => array(
          'boxes-user_menu' => 'boxes-user_menu',
        ),
        'cr_general' => array(
          'cr_general-share' => 'cr_general-share',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Header and footer');
  $export['sport_relief_no_social'] = $context;

  return $export;
}
