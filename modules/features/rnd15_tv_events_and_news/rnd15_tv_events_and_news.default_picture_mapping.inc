<?php
/**
 * @file
 * rnd15_tv_events_and_news.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function rnd15_tv_events_and_news_default_picture_mapping() {
  $export = array();

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'media_image';
  $picture_mapping->breakpoint_group = 'media_image';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout_v2.xs' => array(
      '1x' => 'media_image_xs',
      '2x' => 'media_image_xs_2x',
    ),
    'breakpoints.theme.cr_layout_v2.sm' => array(
      '1x' => 'media_image_sm',
      '2x' => 'media_image_sm_2x',
    ),
    'breakpoints.theme.cr_layout_v2.md' => array(
      '1x' => 'media_image_md',
      '2x' => 'media_image_md_2x',
    ),
    'breakpoints.theme.cr_layout_v2.lg' => array(
      '1x' => 'media_image_lg',
      '2x' => 'media_image_lg_2x',
    ),
  );
  $export['media_image'] = $picture_mapping;

  return $export;
}
