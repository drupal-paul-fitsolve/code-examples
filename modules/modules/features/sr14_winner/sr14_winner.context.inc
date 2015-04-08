<?php
/**
 * @file
 * sr14_winner.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sr14_winner_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sr14_winner';
  $context->description = 'less file for winner page';
  $context->tag = 'CSS';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'fundraise/winner' => 'fundraise/winner',
      ),
    ),
  );
  $context->reactions = array(
    'css' => array(
      'Sport Relief 2014' => array(
        'sites/sportrelief.com/themes/sport_relief_2014/css/components/winner.less' => 'sites/sportrelief.com/themes/sport_relief_2014/css/components/winner.less',
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('CSS');
  t('less file for winner page');
  $export['sr14_winner'] = $context;

  return $export;
}
