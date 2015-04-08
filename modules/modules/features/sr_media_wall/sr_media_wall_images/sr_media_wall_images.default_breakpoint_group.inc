<?php
/**
 * @file
 * sr_media_wall_images.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function sr_media_wall_images_default_breakpoint_group() {
  $export = array();

  // Breakpoints.
  $breakpoints = array();
  $breakpoints[] = 'breakpoints.theme.cr_layout.fluid';
  $breakpoints[] = 'breakpoints.theme.cr_layout.narrow';
  $breakpoints[] = 'breakpoints.theme.cr_layout.normal';
  $breakpoints[] = 'breakpoints.theme.cr_layout.wide';

  // Breakpoint group.
  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'media_wall_instagram';
  $breakpoint_group->name = 'Media Wall: Instagram';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['media_wall_instagram'] = $breakpoint_group;

  return $export;
}
