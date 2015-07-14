<?php
/**
 * @file
 * rnd15_site_images_backgrounds.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function rnd15_site_images_backgrounds_default_picture_mapping() {
  $export = array();

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'full_width_focus_left';
  $picture_mapping->breakpoint_group = 'full_width_focus_left';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout_v2.xs' => array(
      '1x' => 'full_width_focus_left_xs',
      '2x' => 'full_width_focus_left_xs_2x',
    ),
    'breakpoints.theme.cr_layout_v2.sm' => array(
      '1x' => 'full_width_focus_left_sm',
      '2x' => 'full_width_focus_left_sm_2x',
    ),
    'breakpoints.theme.cr_layout_v2.md' => array(
      '1x' => 'full_width_focus_left_md',
      '2x' => 'full_width_focus_left_md_2x',
    ),
    'breakpoints.theme.cr_layout_v2.lg' => array(
      '1x' => 'full_width_focus_left_lg',
      '2x' => 'full_width_focus_left_lg_2x',
    ),
  );
  $export['full_width_focus_left'] = $picture_mapping;

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'full_width_focus_right';
  $picture_mapping->breakpoint_group = 'full_width_focus_right';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout_v2.xs' => array(
      '1x' => 'full_width_focus_right_xs',
      '2x' => 'full_width_focus_right_xs_2x',
    ),
    'breakpoints.theme.cr_layout_v2.sm' => array(
      '1x' => 'full_width_focus_right_sm',
      '2x' => 'full_width_focus_right_sm_2x',
    ),
    'breakpoints.theme.cr_layout_v2.md' => array(
      '1x' => 'full_width_focus_right_md',
      '2x' => 'full_width_focus_right_md_2x',
    ),
    'breakpoints.theme.cr_layout_v2.lg' => array(
      '1x' => 'full_width_focus_right_lg',
      '2x' => 'full_width_focus_right_lg_2x',
    ),
  );
  $export['full_width_focus_right'] = $picture_mapping;

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'full_width_focus_centre';
  $picture_mapping->breakpoint_group = 'full_width_focus_centre';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout_v2.xs' => array(
      '1x' => 'full_width_focus_centre_xs',
      '2x' => 'full_width_focus_centre_xs_2x',
    ),
    'breakpoints.theme.cr_layout_v2.sm' => array(
      '1x' => 'full_width_focus_centre_sm',
      '2x' => 'full_width_focus_centre_sm_2x',
    ),
    'breakpoints.theme.cr_layout_v2.md' => array(
      '1x' => 'full_width_focus_centre_md',
      '2x' => 'full_width_focus_centre_md_2x',
    ),
    'breakpoints.theme.cr_layout_v2.lg' => array(
      '1x' => 'full_width_focus_centre_lg',
      '2x' => 'full_width_focus_centre_lg_2x',
    ),
  );
  $export['full_width_focus_centre'] = $picture_mapping;

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'full_width_crop_width_centre';
  $picture_mapping->breakpoint_group = 'full_width_crop_width_centre';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout_v2.xs' => array(
      '1x' => 'full_width_crop_width_centre_xs',
      '2x' => 'full_width_crop_width_centre_xs_2x',
    ),
    'breakpoints.theme.cr_layout_v2.sm' => array(
      '1x' => 'full_width_crop_width_centre_sm',
      '2x' => 'full_width_crop_width_centre_sm_2x',
    ),
    'breakpoints.theme.cr_layout_v2.md' => array(
      '1x' => 'full_width_crop_width_centre_md',
      '2x' => 'full_width_crop_width_centre_md_2x',
    ),
    'breakpoints.theme.cr_layout_v2.lg' => array(
      '1x' => 'full_width_crop_width_centre_lg',
      '2x' => 'full_width_crop_width_centre_lg_2x',
    ),
  );
  $export['full_width_crop_width_centre'] = $picture_mapping;

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'full_width_crop';
  $picture_mapping->breakpoint_group = 'full_width_crop';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout_v2.xs' => array(
      '1x' => 'full_width_crop_xs',
      '2x' => 'full_width_crop_xs_2x',
    ),
    'breakpoints.theme.cr_layout_v2.sm' => array(
      '1x' => 'full_width_crop_sm',
      '2x' => 'full_width_crop_sm_2x',
    ),
    'breakpoints.theme.cr_layout_v2.md' => array(
      '1x' => 'full_width_crop_md',
      '2x' => 'full_width_crop_md_2x',
    ),
    'breakpoints.theme.cr_layout_v2.lg' => array(
      '1x' => 'full_width_crop_lg',
      '2x' => 'full_width_crop_lg_2x',
    ),
  );
  $export['full_width_crop'] = $picture_mapping;

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'full_width_focus_tall_tablet';
  $picture_mapping->breakpoint_group = 'full_width_focus_tall_tablet';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout_v2.xs' => array(
      '1x' => 'full_width_focus_tall_tablet_xs',
      '2x' => 'full_width_focus_tall_tablet_xs_2x',
    ),
    'breakpoints.theme.cr_layout_v2.sm' => array(
      '1x' => 'full_width_focus_tall_tablet_sm',
      '2x' => 'full_width_focus_tall_tablet_sm_2x',
    ),
    'breakpoints.theme.cr_layout_v2.md' => array(
      '1x' => 'full_width_focus_tall_tablet_md',
      '2x' => 'full_width_focus_tall_tablet_md_2x',
    ),
    'breakpoints.theme.cr_layout_v2.lg' => array(
      '1x' => 'full_width_focus_tall_tablet_lg',
      '2x' => 'full_width_focus_tall_tablet_lg_2x',
    ),
  );
  $export['full_width_focus_tall_tablet'] = $picture_mapping;

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'full_width_crop_small';
  $picture_mapping->breakpoint_group = 'full_width_crop_small';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout_v2.xs' => array(
      '1x' => 'full_width_crop_small_xs',
      '2x' => 'full_width_crop_small_xs_2x',
    ),
    'breakpoints.theme.cr_layout_v2.sm' => array(
      '1x' => 'full_width_crop_small_sm',
      '2x' => 'full_width_crop_small_sm_2x',
    ),
    'breakpoints.theme.cr_layout_v2.md' => array(
      '1x' => 'full_width_crop_small_md',
      '2x' => 'full_width_crop_small_md_2x',
    ),
    'breakpoints.theme.cr_layout_v2.lg' => array(
      '1x' => 'full_width_crop_small_lg',
      '2x' => 'full_width_crop_small_lg_2x',
    ),
  );
  $export['full_width_crop_small'] = $picture_mapping;

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'full_width_crop_width_centre_large';
  $picture_mapping->breakpoint_group = 'full_width_crop_width_centre_large';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout_v2.xs' => array(
      '1x' => 'full_width_crop_width_centre_large_xs',
      '2x' => 'full_width_crop_width_centre_large_xs_2x',
    ),
    'breakpoints.theme.cr_layout_v2.sm' => array(
      '1x' => 'full_width_crop_width_centre_large_sm',
      '2x' => 'full_width_crop_width_centre_large_sm_2x',
    ),
    'breakpoints.theme.cr_layout_v2.md' => array(
      '1x' => 'full_width_crop_width_centre_large_md',
      '2x' => 'full_width_crop_width_centre_large_md_2x',
    ),
    'breakpoints.theme.cr_layout_v2.lg' => array(
      '1x' => 'full_width_crop_width_centre_large_lg',
      '2x' => 'full_width_crop_width_centre_large_lg_2x',
    ),
  );
  $export['full_width_crop_width_centre_large'] = $picture_mapping;

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'full_width_focus_left_stack';
  $picture_mapping->breakpoint_group = 'full_width_focus_left_stack';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout_v2.xs' => array(
      '1x' => 'full_width_focus_left_stack_xs',
      '2x' => 'full_width_focus_left_stack_xs_2x',
    ),
    'breakpoints.theme.cr_layout_v2.sm' => array(
      '1x' => 'full_width_focus_left_stack_sm',
      '2x' => 'full_width_focus_left_stack_sm_2x',
    ),
    'breakpoints.theme.cr_layout_v2.md' => array(
      '1x' => 'full_width_focus_left_stack_md',
      '2x' => 'full_width_focus_left_stack_md_2x',
    ),
    'breakpoints.theme.cr_layout_v2.lg' => array(
      '1x' => 'full_width_focus_left_stack_lg',
      '2x' => 'full_width_focus_left_stack_lg_2x',
    ),
  );
  $export['full_width_focus_left_stack'] = $picture_mapping;

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'full_width_focus_right_stack';
  $picture_mapping->breakpoint_group = 'full_width_focus_right_stack';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout_v2.xs' => array(
      '1x' => 'full_width_focus_right_stack_xs',
      '2x' => 'full_width_focus_right_stack_xs_2x',
    ),
    'breakpoints.theme.cr_layout_v2.sm' => array(
      '1x' => 'full_width_focus_right_stack_sm',
      '2x' => 'full_width_focus_right_stack_sm_2x',
    ),
    'breakpoints.theme.cr_layout_v2.md' => array(
      '1x' => 'full_width_focus_right_stack_md',
      '2x' => 'full_width_focus_right_stack_md_2x',
    ),
    'breakpoints.theme.cr_layout_v2.lg' => array(
      '1x' => 'full_width_focus_right_stack_lg',
      '2x' => 'full_width_focus_right_stack_lg_2x',
    ),
  );
  $export['full_width_focus_right_stack'] = $picture_mapping;

  return $export;
}
