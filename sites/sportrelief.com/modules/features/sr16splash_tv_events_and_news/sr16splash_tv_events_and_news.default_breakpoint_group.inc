<?php
/**
 * @file
 * sr16splash_tv_events_and_news.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function sr16splash_tv_events_and_news_default_breakpoint_group() {
  $export = array();

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'media_image';
  $breakpoint_group->name = 'Media image';
  $breakpoint_group->breakpoints = array(
    0 => 'breakpoints.theme.cr_layout_v2.xs',
    1 => 'breakpoints.theme.cr_layout_v2.sm',
    2 => 'breakpoints.theme.cr_layout_v2.md',
    3 => 'breakpoints.theme.cr_layout_v2.lg',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['media_image'] = $breakpoint_group;

  return $export;
}
