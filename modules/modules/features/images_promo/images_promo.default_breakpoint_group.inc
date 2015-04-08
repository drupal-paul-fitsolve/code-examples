<?php
/**
 * @file
 * images_promo.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function images_promo_default_breakpoint_group() {
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
  $breakpoint_group->machine_name = 'grid_12_promo';
  $breakpoint_group->name = 'Grid 12 Promo';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['grid_12_promo'] = $breakpoint_group;

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
  $breakpoint_group->machine_name = 'grid_13_promo';
  $breakpoint_group->name = 'Grid 13 Promo';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['grid_13_promo'] = $breakpoint_group;

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
  $breakpoint_group->machine_name = 'grid_14_promo';
  $breakpoint_group->name = 'Grid 14 Promo';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['grid_14_promo'] = $breakpoint_group;

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
  $breakpoint_group->machine_name = 'grid_9_promo';
  $breakpoint_group->name = 'Grid 9 Promo';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['grid_9_promo'] = $breakpoint_group;

  return $export;
}
