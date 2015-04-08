<?php
/**
 * @file
 * sr_battle_of_the_backsides.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sr_battle_of_the_backsides_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sr14_battle_of_the_backsides';
  $context->description = 'Body classes and CSS documents required on /latest/battle';
  $context->tag = 'CSS';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'latest/battle' => 'latest/battle',
      ),
    ),
  );
  $context->reactions = array(
    'css' => array(
      'Sport Relief 2014' => array(
        'sites/sportrelief.com/themes/sport_relief_2014/css/components/battleofthebacksides.less' => 'sites/sportrelief.com/themes/sport_relief_2014/css/components/battleofthebacksides.less',
      ),
    ),
    'theme_html' => array(
      'class' => 'BattleOfTheBacksides',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sport Relief');
  t('Body classes and CSS documents required on /latest/battle');
  $export['sr_battle_of_the_backsides'] = $context;

  return $export;
}
