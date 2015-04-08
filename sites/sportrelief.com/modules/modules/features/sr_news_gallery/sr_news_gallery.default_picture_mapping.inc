<?php
/**
 * @file
 * sr_news_gallery.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function sr_news_gallery_default_picture_mapping() {
  $export = array();

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'tile_grid_6';
  $picture_mapping->breakpoint_group = 'tile_grid_6';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout.fluid' => array(
      '1x' => 'tile_grid_6breakpoints_theme_cr_layout_fluid_1x',
    ),
    'breakpoints.theme.cr_layout.narrow' => array(
      '1x' => 'tile_grid_6breakpoints_theme_cr_layout_narrow_1x',
    ),
    'breakpoints.theme.cr_layout.normal' => array(
      '1x' => 'tile_grid_6breakpoints_theme_cr_layout_normal_1x',
    ),
    'breakpoints.theme.cr_layout.wide' => array(
      '1x' => 'tile_grid_6breakpoints_theme_cr_layout_wide_1x',
    ),
  );
  $export['tile_grid_6'] = $picture_mapping;

  return $export;
}
