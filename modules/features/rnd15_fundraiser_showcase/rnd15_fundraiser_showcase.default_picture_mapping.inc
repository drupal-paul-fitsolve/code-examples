<?php
/**
 * @file
 * rnd15_fundraiser_showcase.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function rnd15_fundraiser_showcase_default_picture_mapping() {
  $export = array();

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'fundraiser_showcase_gallery';
  $picture_mapping->breakpoint_group = 'fundraiser_showcase_gallery';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout_v2.xs' => array(
      '1x' => 'fundraiser_showcase_gallery_xs',
      '2x' => 'fundraiser_showcase_gallery_xs_2x',
    ),
    'breakpoints.theme.cr_layout_v2.sm' => array(
      '1x' => 'fundraiser_showcase_gallery_sm',
      '2x' => 'fundraiser_showcase_gallery_sm_2x',
    ),
    'breakpoints.theme.cr_layout_v2.md' => array(
      '1x' => 'fundraiser_showcase_gallery_md',
      '2x' => 'fundraiser_showcase_gallery_md_2x',
    ),
    'breakpoints.theme.cr_layout_v2.lg' => array(
      '1x' => 'fundraiser_showcase_gallery_lg',
      '2x' => 'fundraiser_showcase_gallery_lg_2x',
    ),
  );
  $export['fundraiser_showcase_gallery'] = $picture_mapping;

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'fundraiser_showcase_page';
  $picture_mapping->breakpoint_group = 'fundraiser_showcase_page';
  $picture_mapping->mapping = array(
    'breakpoints.theme.cr_layout_v2.xs' => array(
      '1x' => 'fundraiser_showcase_page_xs',
      '2x' => 'fundraiser_showcase_page_xs_2x',
    ),
    'breakpoints.theme.cr_layout_v2.sm' => array(
      '1x' => 'fundraiser_showcase_page_sm',
      '2x' => 'fundraiser_showcase_page_sm_2x',
    ),
    'breakpoints.theme.cr_layout_v2.md' => array(
      '1x' => 'fundraiser_showcase_page_md',
      '2x' => 'fundraiser_showcase_page_md_2x',
    ),
    'breakpoints.theme.cr_layout_v2.lg' => array(
      '1x' => 'fundraiser_showcase_page_lg',
      '2x' => 'fundraiser_showcase_page_lg_2x',
    ),
  );
  $export['fundraiser_showcase_page'] = $picture_mapping;

  return $export;
}
