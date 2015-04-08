<?php
/**
 * @file
 * sr14_otn.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function sr14_otn_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'grid_15_otn';
  $ds_view_mode->label = 'Grid 15 OTN';
  $ds_view_mode->entities = array(
    'fieldable_panels_pane' => 'fieldable_panels_pane',
  );
  $export['grid_15_otn'] = $ds_view_mode;

  return $export;
}
