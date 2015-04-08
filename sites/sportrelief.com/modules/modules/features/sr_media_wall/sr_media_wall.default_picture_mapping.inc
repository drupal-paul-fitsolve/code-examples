<?php
/**
 * @file
 * sr_media_wall.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function sr_media_wall_default_picture_mapping() {
  $export = array();

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'media_wall_default';
  $picture_mapping->breakpoint_group = 'media_wall_default';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout.fluid' => array(
      '1x' => 'media_wall_breakpoints_theme_cr_layout_fluid_1x',
    ),
    'breakpoints.theme.cr_layout.narrow' => array(
      '1x' => 'media-wall-defaultbreakpoints_theme_cr_layout_narrow_1x',
    ),
    'breakpoints.theme.cr_layout.normal' => array(
      '1x' => 'media-wall-defaultbreakpoints_theme_cr_layout_normal_1x',
    ),
    'breakpoints.theme.cr_layout.wide' => array(
      '1x' => 'media-wall-defaultbreakpoints_theme_cr_layout_wide_1x',
    ),
  );
  $export['media_wall_default'] = $picture_mapping;

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'media_wall_promo_1';
  $picture_mapping->breakpoint_group = 'media_wall_promo_1';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout.fluid' => array(
      '1x' => 'media_wall_breakpoints_theme_cr_layout_fluid_1x',
    ),
    'breakpoints.theme.cr_layout.narrow' => array(
      '1x' => 'media-wall-promo-breakpoints_theme_cr_layout_narrow_1x',
    ),
    'breakpoints.theme.cr_layout.normal' => array(
      '1x' => 'media-wall-promo-1breakpoints_theme_cr_layout_normal_1x',
    ),
    'breakpoints.theme.cr_layout.wide' => array(
      '1x' => 'media-wall-promo-1breakpoints_theme_cr_layout_wide_1x',
    ),
  );
  $export['media_wall_promo_1'] = $picture_mapping;

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'media_wall_promo_2';
  $picture_mapping->breakpoint_group = 'media_wall_promo_2';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout.fluid' => array(
      '1x' => 'media_wall_breakpoints_theme_cr_layout_fluid_1x',
    ),
    'breakpoints.theme.cr_layout.narrow' => array(
      '1x' => 'media-wall-promo-breakpoints_theme_cr_layout_narrow_1x',
    ),
    'breakpoints.theme.cr_layout.normal' => array(
      '1x' => 'media-wall-promo-2breakpoints_theme_cr_layout_normal_1x',
    ),
    'breakpoints.theme.cr_layout.wide' => array(
      '1x' => 'media-wall-promo-2breakpoints_theme_cr_layout_wide_1x',
    ),
  );
  $export['media_wall_promo_2'] = $picture_mapping;

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'media_wall_touch';
  $picture_mapping->breakpoint_group = 'media_wall_touch';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout.fluid' => array(
      '1x' => 'media_wall_breakpoints_theme_cr_layout_fluid_1x',
    ),
    'breakpoints.theme.cr_layout.narrow' => array(
      '1x' => 'media_wall_touch_breakpoints_theme_cr_layout_narrow_1x',
    ),
    'breakpoints.theme.cr_layout.normal' => array(
      '1x' => 'media_wall_touch_breakpoints_theme_cr_layout_normal_1x',
    ),
  );
  $export['media_wall_touch'] = $picture_mapping;

  return $export;
}
