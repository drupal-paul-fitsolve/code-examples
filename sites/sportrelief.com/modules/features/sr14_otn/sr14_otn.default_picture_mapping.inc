<?php
/**
 * @file
 * sr14_otn.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function sr14_otn_default_picture_mapping() {
  $export = array();

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'otn';
  $picture_mapping->breakpoint_group = 'otn';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout.fluid' => array(
      '1x' => 'grid-all-columns-fluid',
    ),
    'breakpoints.theme.cr_layout.narrow' => array(
      '1x' => 'otnbreakpoints_theme_cr_layout_narrow_1x',
      '2x' => 'otnbreakpoints_theme_cr_layout_narrow_2x',
    ),
    'breakpoints.theme.cr_layout.normal' => array(
      '1x' => 'otnbreakpoints_theme_cr_layout_normal_1x',
    ),
    'breakpoints.theme.cr_layout.wide' => array(
      '1x' => 'otnbreakpoints_theme_cr_layout_wide_1x',
    ),
  );
  $export['otn'] = $picture_mapping;

  return $export;
}
