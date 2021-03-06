<?php
/**
 * @file
 * downloadable.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function downloadable_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'search_result';
  $ds_view_mode->label = 'Search Result';
  $ds_view_mode->entities = array(
    'downloadable' => 'downloadable',
  );
  $export['search_result'] = $ds_view_mode;

  return $export;
}
