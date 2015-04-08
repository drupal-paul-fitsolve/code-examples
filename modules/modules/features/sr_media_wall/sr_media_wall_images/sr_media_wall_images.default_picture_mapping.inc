<?php
/**
 * @file
 * sr_media_wall_images.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function sr_media_wall_images_default_picture_mapping() {
  $export = array();

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'media_wall_instagram';
  $picture_mapping->breakpoint_group = 'media_wall_instagram';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout.fluid' => array(
      '1x' => 'grid-all-columns-fluid',
    ),
    'breakpoints.theme.cr_layout.narrow' => array(
      '1x' => 'media-wall-instagram-breakpoints_theme_cr_layout_narrow_1x',
    ),
    'breakpoints.theme.cr_layout.normal' => array(
      '1x' => 'media-wall-instagram-breakpoints_theme_cr_layout_normal_1x',
    ),
    'breakpoints.theme.cr_layout.wide' => array(
      '1x' => 'media-wall-instagram-breakpoints_theme_cr_layout_wide_1x',
    ),
  );
  $export['media_wall_instagram'] = $picture_mapping;

  return $export;
}
