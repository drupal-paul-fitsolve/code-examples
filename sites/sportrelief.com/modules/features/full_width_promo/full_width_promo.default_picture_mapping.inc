<?php
/**
 * @file
 * full_width_promo.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function full_width_promo_default_picture_mapping() {
  $export = array();

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'full_width_image';
  $picture_mapping->breakpoint_group = 'full_width_image';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout.fluid' => array(
      '1x' => 'full_width_image_fluid',
      '2x' => 'full_width_image_fluid-2_x',
    ),
    'breakpoints.theme.cr_layout.narrow' => array(
      '1x' => 'full_width_image_narrow',
      '2x' => 'full_width_image_narrow-2_x',
    ),
    'breakpoints.theme.cr_layout.normal' => array(
      '1x' => 'full_width_image_normal',
    ),
    'breakpoints.theme.cr_layout.wide' => array(
      '1x' => 'full_width_image_wide',
    ),
  );
  $export['full_width_image'] = $picture_mapping;

  return $export;
}
