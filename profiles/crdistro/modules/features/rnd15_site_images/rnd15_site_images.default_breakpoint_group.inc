<?php
/**
 * @file
 * rnd15_site_images.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function rnd15_site_images_default_breakpoint_group() {
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
  $breakpoint_group->machine_name = 'col_1';
  $breakpoint_group->name = '1 Column';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['col_1'] = $breakpoint_group;

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
  $breakpoint_group->machine_name = 'col_2';
  $breakpoint_group->name = '2 Columns';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['col_2'] = $breakpoint_group;

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
  $breakpoint_group->machine_name = 'col_3';
  $breakpoint_group->name = '3 Columns';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['col_3'] = $breakpoint_group;

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
  $breakpoint_group->machine_name = 'col_4';
  $breakpoint_group->name = '4 Columns';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['col_4'] = $breakpoint_group;

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
  $breakpoint_group->machine_name = 'col_5';
  $breakpoint_group->name = '5 Columns';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['col_5'] = $breakpoint_group;

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
  $breakpoint_group->machine_name = 'col_6';
  $breakpoint_group->name = '6 Columns';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['col_6'] = $breakpoint_group;

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
  $breakpoint_group->machine_name = 'col_7';
  $breakpoint_group->name = '7 Columns';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['col_7'] = $breakpoint_group;

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
  $breakpoint_group->machine_name = 'col_8';
  $breakpoint_group->name = '8 Columns';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['col_8'] = $breakpoint_group;

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
  $breakpoint_group->machine_name = 'col_9';
  $breakpoint_group->name = '9 Columns';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['col_9'] = $breakpoint_group;


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
  $breakpoint_group->machine_name = 'col_10';
  $breakpoint_group->name = '10 Columns';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['col_10'] = $breakpoint_group;

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
  $breakpoint_group->machine_name = 'col_11';
  $breakpoint_group->name = '11 Columns';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['col_11'] = $breakpoint_group;

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
  $breakpoint_group->machine_name = 'col_12';
  $breakpoint_group->name = '12 Columns';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['col_12'] = $breakpoint_group;

  return $export;
}
