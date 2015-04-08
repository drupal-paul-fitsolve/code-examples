<?php
/**
 * @file
 * sr14_otn.delta.inc
 */

/**
 * Implements hook_delta_default_templates().
 */
function sr14_otn_delta_default_templates() {
  $export = array();

  $delta = new stdClass();
  $delta->disabled = FALSE; /* Edit this to true to make a default delta disabled initially */
  $delta->api_version = 3;
  $delta->machine_name = 'content_page_centered_social_lin';
  $delta->name = 'Content Page - Centered social links';
  $delta->description = 'Same as normal page but with centered social links';
  $delta->theme = 'sport_relief';
  $delta->mode = 'preserve';
  $delta->parent = '';
  $delta->settings = array(
    'theme_sport_relief_settings' => array(
      'alpha_zone_content_wrapper' => 1,
      'alpha_region_footer_social_css' => 'container-24',
      'alpha_zone_footer_primary' => 'footer_first',
    ),
  );
  $export['content_page_centered_social_lin'] = $delta;

  return $export;
}
