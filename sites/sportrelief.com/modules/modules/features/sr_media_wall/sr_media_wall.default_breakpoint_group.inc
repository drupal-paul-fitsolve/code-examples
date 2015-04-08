<?php
/**
 * @file
 * sr_media_wall.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function sr_media_wall_default_breakpoint_group() {
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
  $breakpoint_group->machine_name = 'media_wall_default';
  $breakpoint_group->name = 'Media Wall: Default';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['media_wall_default'] = $breakpoint_group;

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
  $breakpoint_group->machine_name = 'media_wall_promo_1';
  $breakpoint_group->name = 'Media Wall: Promo 1';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['media_wall_promo_1'] = $breakpoint_group;

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
  $breakpoint_group->machine_name = 'media_wall_promo_2';
  $breakpoint_group->name = 'Media Wall: Promo 2';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['media_wall_promo_2'] = $breakpoint_group;

  // Breakpoints.
  $breakpoints = array();
  $breakpoints[] = 'breakpoints.theme.cr_layout.fluid';
  $breakpoints[] = 'breakpoints.theme.cr_layout.narrow';
  $breakpoints[] = 'breakpoints.theme.cr_layout.normal';

  // Breakpoint group.
  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'media_wall_touch';
  $breakpoint_group->name = 'Media Wall: Touch';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['media_wall_touch'] = $breakpoint_group;

  return $export;
}
