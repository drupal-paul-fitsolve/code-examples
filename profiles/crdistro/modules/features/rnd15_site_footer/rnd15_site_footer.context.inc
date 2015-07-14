<?php
/**
 * @file
 * rnd15_site_footer.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function rnd15_site_footer_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'footer';
  $context->description = 'Adds blocks, boxes & footer menu to footer';
  $context->tag = 'Header & Footer';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-social_follow_links_box' => array(
          'module' => 'boxes',
          'delta' => 'footer_social_links_box',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'menu-menu-footer-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-menu',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'boxes-copyright_box' => array(
          'module' => 'boxes',
          'delta' => 'footer_copyright_box',
          'region' => 'footer',
          'weight' => '-8',
        ),
        'boxes-footer_branding_box' => array(
          'module' => 'boxes',
          'delta' => 'footer_branding_box',
          'region' => 'footer',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds blocks, boxes & footer menu to footer');
  t('Header & Footer');
  $export['footer'] = $context;

  return $export;
}
