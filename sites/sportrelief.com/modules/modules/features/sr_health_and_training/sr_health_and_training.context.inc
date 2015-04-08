<?php
/**
 * @file
 * sr_health_and_training.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sr_health_and_training_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'health-training';
  $context->description = 'theme settings required for health and training section.';
  $context->tag = 'CSS';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'event-info/prepare-for-your-event' => 'event-info/prepare-for-your-event',
      ),
    ),
  );
  $context->reactions = array(
    'css' => array(
      'Sport Relief 2014' => array(
        'sites/sportrelief.com/themes/sport_relief_2014/css/components/health-training-quiz.less' => 'sites/sportrelief.com/themes/sport_relief_2014/css/components/health-training-quiz.less',
      ),
    ),
    'theme_html' => array(
      'class' => 'health-training',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('CSS');
  t('theme settings required for health and training section.');
  $export['health-training'] = $context;

  return $export;
}
