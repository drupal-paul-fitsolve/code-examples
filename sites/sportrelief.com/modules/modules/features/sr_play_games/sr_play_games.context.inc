<?php
/**
 * @file
 * sr_play_games.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sr_play_games_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sr14_play_games_section';
  $context->description = 'Body classes and CSS documents required on /play-games and /play-games/*';
  $context->tag = 'CSS';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'play-games' => 'play-games',
        'play-games/*' => 'play-games/*',
      ),
    ),
  );
  $context->reactions = array(
    'css' => array(
      'Sport Relief 2014' => array(
        'sites/sportrelief.com/themes/sport_relief_2014/css/components/tabs/tabs-fun-and-games.less' => 'sites/sportrelief.com/themes/sport_relief_2014/css/components/tabs/tabs-fun-and-games.less',
        'sites/sportrelief.com/themes/sport_relief_2014/css/components/leaderboards.less' => 'sites/sportrelief.com/themes/sport_relief_2014/css/components/leaderboards.less',
        'sites/sportrelief.com/themes/sport_relief_2014/css/components/play-games.less' => 'sites/sportrelief.com/themes/sport_relief_2014/css/components/play-games.less',
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('CSS');
  t('Body classes and CSS documents required on /play-games and /play-games/*');
  $export['sr14_play_games_section'] = $context;

  return $export;
}
