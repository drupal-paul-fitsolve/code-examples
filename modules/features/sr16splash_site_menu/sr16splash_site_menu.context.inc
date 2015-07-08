<?php
/**
 * @file
 * sr16splash_site_menu.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sr16splash_site_menu_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sr16splash_simple_nav';
  $context->description = '';
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
    'menu' => '0',
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('header');
  $export['sr16splash_simple_nav'] = $context;

  return $export;
}
