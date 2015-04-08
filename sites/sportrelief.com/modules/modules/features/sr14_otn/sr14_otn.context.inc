<?php
/**
 * @file
 * sr14_otn.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sr14_otn_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front005';
  $context->description = 'March 23rd OTN context';
  $context->tag = 'OTN';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/7193' => 'node/7193',
      ),
    ),
  );
  $context->reactions = array(
    'css' => array(
      'Sport Relief 2014' => array(
        'sites/sportrelief.com/themes/sport_relief_2014/css/components/otn.less' => 'sites/sportrelief.com/themes/sport_relief_2014/css/components/otn.less',
      ),
    ),
    'theme_html' => array(
      'class' => 'context-otn-homepage-march-23rd',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('March 23rd OTN context');
  t('OTN');
  $export['front005'] = $context;

  return $export;
}
