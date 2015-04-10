<?php
/**
 * @file
 * full_width_promo.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function full_width_promo_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'full_width_promo';
  $ds_view_mode->label = 'Full width promo';
  $ds_view_mode->entities = array(
    'node' => 'node',
    'fieldable_panels_pane' => 'fieldable_panels_pane',
  );
  $export['full_width_promo'] = $ds_view_mode;

  return $export;
}
