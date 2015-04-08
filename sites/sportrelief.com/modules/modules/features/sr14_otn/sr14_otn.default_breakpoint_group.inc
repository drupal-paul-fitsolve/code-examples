<?php
/**
 * @file
 * sr14_otn.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function sr14_otn_default_breakpoint_group() {
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
  $breakpoint_group->machine_name = 'otn';
  $breakpoint_group->name = 'otn';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['otn'] = $breakpoint_group;

  return $export;
}
