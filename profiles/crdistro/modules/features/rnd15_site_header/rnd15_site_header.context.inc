<?php
/**
 * @file
 * rnd15_site_header.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function rnd15_site_header_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'rnd15_site_header';
  $context->description = '';
  $context->tag = 'header';
  $context->conditions = array(
    'error' => array(
      'values' => array(
        1 => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        '~donate' => '~donate',
        '~donate/thankyou' => '~donate/thankyou',
        '~donate/cancel' => '~donate/cancel',
        '~user' => '~user',
        '~access_denied' => '~access_denied',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'header',
          'weight' => '-10',
        ),
        'cr_marketing_prefs-esu_header' => array(
          'module' => 'cr_marketing_prefs',
          'delta' => 'esu_header',
          'region' => 'header',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('header');
  $export['rnd15_site_header'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'rnd15_site_header_simple';
  $context->description = 'For the simple nav bar on Donate pages';
  $context->tag = 'header';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'donate' => 'donate',
        'donate/thankyou' => 'donate/thankyou',
        'donate/cancel' => 'donate/cancel',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-simple_nav' => array(
          'module' => 'boxes',
          'delta' => 'simple_nav',
          'region' => 'header',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('For the simple nav bar on Donate pages');
  t('header');
  $export['rnd15_site_header_simple'] = $context;

  return $export;
}
