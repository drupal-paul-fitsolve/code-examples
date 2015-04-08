<?php
/**
 * @file
 * otn_banners.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function otn_banners_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sr14_otn_banners_styling';
  $context->description = 'Styling needed for OTN banners on multiple pages';
  $context->tag = 'CSS';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'event-info/enter-now' => 'event-info/enter-now',
        'event-info' => 'event-info',
        'schools' => 'schools',
        'fundraise' => 'fundraise',
        'latest' => 'latest',
        'order-stuff' => 'order-stuff',
        'play-games' => 'play-games',
        'what-we-do' => 'what-we-do',
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
      'class' => 'otn-banners',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('CSS');
  t('Styling needed for OTN banners on multiple pages');
  $export['sr14_otn_banners_styling'] = $context;

  return $export;
}
