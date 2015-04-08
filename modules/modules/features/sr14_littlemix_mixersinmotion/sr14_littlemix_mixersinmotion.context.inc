<?php
/**
 * @file
 * sr14_littlemix_mixersinmotion.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sr14_littlemix_mixersinmotion_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sr14_littlemix_mixersinmotion';
  $context->description = 'Body classes and CSS documents required on #mixersinmotion page.';
  $context->tag = 'CSS';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'latest/littlemix' => 'latest/littlemix',
      ),
    ),
  );
  $context->reactions = array(
    'css' => array(
      'Sport Relief 2014' => array(
        'sites/sportrelief.com/themes/sport_relief_2014/css/components/littlemixmixersinmotion.less' => 'sites/sportrelief.com/themes/sport_relief_2014/css/components/littlemixmixersinmotion.less',
      ),
    ),
    'theme_html' => array(
      'class' => 'littlemix-mixersinmotion-landing',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Body classes and CSS documents required on #mixersinmotion page.');
  t('CSS');
  $export['sr14_littlemix_mixersinmotion'] = $context;

  return $export;
}
