<?php
/**
 * @file
 * images_promo.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function images_promo_default_picture_mapping() {
  $export = array();

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'grid_12_promo';
  $picture_mapping->breakpoint_group = 'grid_12_promo';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout.fluid' => array(
      '1x' => 'grid-all-columns-fluid',
    ),
    'breakpoints.theme.cr_layout.narrow' => array(
      '1x' => 'grid-24-narrow',
    ),
    'breakpoints.theme.cr_layout.normal' => array(
      '1x' => 'grid-12-normal',
    ),
    'breakpoints.theme.cr_layout.wide' => array(
      '1x' => 'grid-12-wide',
    ),
  );
  $export['grid_12_promo'] = $picture_mapping;

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'grid_13_promo';
  $picture_mapping->breakpoint_group = 'grid_13_promo';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout.fluid' => array(
      '1x' => 'grid-all-columns-fluid',
    ),
    'breakpoints.theme.cr_layout.narrow' => array(
      '1x' => 'grid-24-narrow',
    ),
    'breakpoints.theme.cr_layout.normal' => array(
      '1x' => 'grid-13-normal',
    ),
    'breakpoints.theme.cr_layout.wide' => array(
      '1x' => 'grid-13-wide',
    ),
  );
  $export['grid_13_promo'] = $picture_mapping;

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'grid_14_promo';
  $picture_mapping->breakpoint_group = 'grid_14_promo';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout.fluid' => array(
      '1x' => 'grid-all-columns-fluid',
    ),
    'breakpoints.theme.cr_layout.narrow' => array(
      '1x' => 'grid-24-narrow',
    ),
    'breakpoints.theme.cr_layout.normal' => array(
      '1x' => 'grid-14-normal',
    ),
    'breakpoints.theme.cr_layout.wide' => array(
      '1x' => 'grid-14-wide',
    ),
  );
  $export['grid_14_promo'] = $picture_mapping;

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'grid_9_promo';
  $picture_mapping->breakpoint_group = 'grid_9_promo';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout.fluid' => array(
      '1x' => 'grid-all-columns-fluid',
    ),
    'breakpoints.theme.cr_layout.narrow' => array(
      '1x' => 'grid-24-narrow',
    ),
    'breakpoints.theme.cr_layout.normal' => array(
      '1x' => 'grid-9-normal',
    ),
    'breakpoints.theme.cr_layout.wide' => array(
      '1x' => 'grid-9-wide',
    ),
  );
  $export['grid_9_promo'] = $picture_mapping;

  return $export;
}
