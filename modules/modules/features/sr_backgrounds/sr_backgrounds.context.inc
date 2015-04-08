<?php
/**
 * @file
 * sr_backgrounds.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sr_backgrounds_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sr-promo-background';
  $context->description = '';
  $context->tag = 'SR backgrounds';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
        'uber-promo-content' => 'uber-promo-content',
        'content-sidebar-and-uber-promo' => 'content-sidebar-and-uber-promo',
        'schools' => 'schools',
        'schools/*' => 'schools/*',
        'node/46' => 'node/46',
        'node/27' => 'node/27',
        'node/23' => 'node/23',
        'node/58' => 'node/58',
        'node/51' => 'node/51',
        'node/35' => 'node/35',
        'fundraising-ideas-and-tools' => 'fundraising-ideas-and-tools',
        'sainsburys-sport-relief-mile' => 'sainsburys-sport-relief-mile',
        'sainsburys-sport-relief-cycle' => 'sainsburys-sport-relief-cycle',
        'sainsburys-sport-relief-swimathon' => 'sainsburys-sport-relief-swimathon',
        'event-info/health-and-training' => 'event-info/health-and-training',
        'latest' => 'latest',
        'node/386' => 'node/386',
        'node/529' => 'node/529',
        'node/2796' => 'node/2796',
        'front004' => 'front004',
        'node/2' => 'node/2',
        'node/4372' => 'node/4372',
        'node/4451' => 'node/4451',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'promo-bg',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('SR backgrounds');
  $export['sr-promo-background'] = $context;

  return $export;
}
