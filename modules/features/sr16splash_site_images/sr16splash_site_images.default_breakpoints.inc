<?php
/**
 * @file
 * sr16splash_site_images.default_breakpoints.inc
 */

/**
 * Implements hook_default_breakpoints().
 */
function sr16splash_site_images_default_breakpoints() {
  $export = array();

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'breakpoints.theme.cr_layout_v2.lg';
  $breakpoint->name = 'lg';
  $breakpoint->breakpoint = '(min-width: 1400px)';
  $breakpoint->source = 'cr_layout_v2';
  $breakpoint->source_type = 'theme';
  $breakpoint->status = 1;
  $breakpoint->weight = 3;
  $breakpoint->multipliers = array(
    '1x' => '1x',
    '2x' => '2x',
  );
  $export['breakpoints.theme.cr_layout_v2.lg'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'breakpoints.theme.cr_layout_v2.md';
  $breakpoint->name = 'md';
  $breakpoint->breakpoint = '(min-width: 992px) and (max-width: 1399px)';
  $breakpoint->source = 'cr_layout_v2';
  $breakpoint->source_type = 'theme';
  $breakpoint->status = 1;
  $breakpoint->weight = 2;
  $breakpoint->multipliers = array(
    '1x' => '1x',
    '2x' => '2x',
  );
  $export['breakpoints.theme.cr_layout_v2.md'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'breakpoints.theme.cr_layout_v2.sm';
  $breakpoint->name = 'sm';
  $breakpoint->breakpoint = '(min-width: 768px) and (max-width: 991px)';
  $breakpoint->source = 'cr_layout_v2';
  $breakpoint->source_type = 'theme';
  $breakpoint->status = 1;
  $breakpoint->weight = 1;
  $breakpoint->multipliers = array(
    '1x' => '1x',
    '2x' => '2x',
  );
  $export['breakpoints.theme.cr_layout_v2.sm'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'breakpoints.theme.cr_layout_v2.xs';
  $breakpoint->name = 'xs';
  $breakpoint->breakpoint = '(min-width: 0px) and (max-width: 767px)';
  $breakpoint->source = 'cr_layout_v2';
  $breakpoint->source_type = 'theme';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
    '2x' => '2x',
  );
  $export['breakpoints.theme.cr_layout_v2.xs'] = $breakpoint;

  return $export;
}
