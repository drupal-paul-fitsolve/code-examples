<?php
/**
 * @file
 * sr14_top_dog.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sr14_top_dog_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sr14_top_dog';
  $context->description = 'add top-dog less file and context body tag';
  $context->tag = 'CSS';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'latest/top-dog' => 'latest/top-dog',
        'top-dog' => 'top-dog',
      ),
    ),
  );
  $context->reactions = array(
    'css' => array(
      'Sport Relief 2014' => array(
        'sites/sportrelief.com/themes/sport_relief_2014/css/components/topdog.less' => 'sites/sportrelief.com/themes/sport_relief_2014/css/components/topdog.less',
      ),
    ),
    'theme_html' => array(
      'class' => 'context-top-dog',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('CSS');
  t('add top-dog less file and context body tag');
  $export['top_dog'] = $context;

  return $export;
}
