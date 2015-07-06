<?php
/**
 * @file
 * sr16splash_site_images_backgrounds.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function sr16splash_site_images_backgrounds_default_breakpoint_group() {
  $export = array();

  // Breakpoints.
  $breakpoints = array();
  $breakpoints[] = 'breakpoints.theme.cr_layout_v2.xs';
  $breakpoints[] = 'breakpoints.theme.cr_layout_v2.sm';
  $breakpoints[] = 'breakpoints.theme.cr_layout_v2.md';
  $breakpoints[] = 'breakpoints.theme.cr_layout_v2.lg';

  // Breakpoint group.
  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'full_width_focus_left';
  $breakpoint_group->name = 'Full Width Focus Left';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['full_width_focus_left'] = $breakpoint_group;

  // Breakpoint group.
  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'full_width_focus_right';
  $breakpoint_group->name = 'Full Width Focus Right';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['full_width_focus_right'] = $breakpoint_group;

  // Breakpoint group.
  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'full_width_focus_centre';
  $breakpoint_group->name = 'Full Width Focus Centre';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['full_width_focus_centre'] = $breakpoint_group;

  // Breakpoint group.
  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'full_width_crop_width_centre';
  $breakpoint_group->name = 'Full Width Focus Centre';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['full_width_crop_width_centre'] = $breakpoint_group;

  // Breakpoint group.
  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'full_width_crop';
  $breakpoint_group->name = 'Full Width Crop';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['full_width_crop'] = $breakpoint_group;

  // Breakpoint group.
  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'full_width_focus_tall_tablet';
  $breakpoint_group->name = 'Full Width Focus Tall Tablet';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['full_width_focus_tall_tablet'] = $breakpoint_group;

  // Breakpoint group.
  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'full_width_crop_small';
  $breakpoint_group->name = 'Full Width Crop Small';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['full_width_crop_small'] = $breakpoint_group;

  // Breakpoint group.
  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'full_width_crop_width_centre_large';
  $breakpoint_group->name = 'Full Width Crop Centre Large';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['full_width_crop_width_centre_large'] = $breakpoint_group;

  // Breakpoint group.
  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'full_width_focus_left_stack';
  $breakpoint_group->name = 'Full Width Focus Left Stack';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['full_width_focus_left_stack'] = $breakpoint_group;

  // Breakpoint group.
  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'full_width_focus_right_stack';
  $breakpoint_group->name = 'Full Width Focus Right Stack';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['full_width_focus_right_stack'] = $breakpoint_group;

  return $export;
}
