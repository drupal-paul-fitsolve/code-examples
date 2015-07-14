<?php
/**
 * @file
 * rnd15_otn_banner.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function rnd15_otn_banner_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'otn-banner-1';
  $context->description = 'on the night';
  $context->tag = 'OTN Banner';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'fundraise' => 'fundraise',
        'schools' => 'schools',
        'what-we-do' => 'what-we-do',
        'tv-events-and-news' => 'tv-events-and-news',
        'order-stuff' => 'order-stuff',
        'sponsor-and-donate' => 'sponsor-and-donate',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-otn' => array(
          'module' => 'boxes',
          'delta' => 'otn',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('OTN Banner');
  t('on the night');
  $export['otn-banner-1'] = $context;

  $context = new stdClass();
  $context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'otn-banner-2';
  $context->description = 'after';
  $context->tag = 'OTN Banner';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'fundraise' => 'fundraise',
        'schools' => 'schools',
        'what-we-do' => 'what-we-do',
        'tv-events-and-news' => 'tv-events-and-news',
        'order-stuff' => 'order-stuff',
        'sponsor-and-donate' => 'sponsor-and-donate',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-otn_after' => array(
          'module' => 'boxes',
          'delta' => 'otn_after',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('OTN Banner');
  t('after');
  $export['otn-banner-2'] = $context;

  $context = new stdClass();
  $context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'otn-banner-3';
  $context->description = 'monday';
  $context->tag = 'OTN Banner';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'fundraise' => 'fundraise',
        'schools' => 'schools',
        'what-we-do' => 'what-we-do',
        'tv-events-and-news' => 'tv-events-and-news',
        'order-stuff' => 'order-stuff',
        'sponsor-and-donate' => 'sponsor-and-donate',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-otn_monday' => array(
          'module' => 'boxes',
          'delta' => 'otn_monday',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('OTN Banner');
  t('monday');
  $export['otn-banner-3'] = $context;

  return $export;
}
