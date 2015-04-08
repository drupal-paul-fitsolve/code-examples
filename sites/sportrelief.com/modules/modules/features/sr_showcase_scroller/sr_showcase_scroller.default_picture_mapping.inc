<?php
/**
 * @file
 * sr_showcase_scroller.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function sr_showcase_scroller_default_picture_mapping() {
  $export = array();

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'showcase_scroller';
  $picture_mapping->breakpoint_group = 'showcase_scroller';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout.fluid' => array(
      '1x' => 'showcase-scroller--fluid',
    ),
    'breakpoints.theme.cr_layout.narrow' => array(
      '1x' => 'showcase-scroller--narrow',
    ),
    'breakpoints.theme.cr_layout.normal' => array(
      '1x' => 'showcase-scroller--normal',
    ),
    'breakpoints.theme.cr_layout.wide' => array(
      '1x' => 'showcase-scroller--wide',
    ),
  );
  $export['showcase_scroller'] = $picture_mapping;

  return $export;
}
