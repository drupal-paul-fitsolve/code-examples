<?php
/**
 * @file
 * images_promo.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function images_promo_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'grid_12_promo';
  $ds_view_mode->label = 'Grid 12 Promo';
  $ds_view_mode->entities = array(
    'fieldable_panels_pane' => 'fieldable_panels_pane',
  );
  $export['grid_12_promo'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'grid_13_promo';
  $ds_view_mode->label = 'Grid 13 Promo';
  $ds_view_mode->entities = array(
    'fieldable_panels_pane' => 'fieldable_panels_pane',
  );
  $export['grid_13_promo'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'grid_14_promo';
  $ds_view_mode->label = 'Grid 14 Promo';
  $ds_view_mode->entities = array(
    'fieldable_panels_pane' => 'fieldable_panels_pane',
  );
  $export['grid_14_promo'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'grid_9_promo';
  $ds_view_mode->label = 'Grid 9 Promo';
  $ds_view_mode->entities = array(
    'fieldable_panels_pane' => 'fieldable_panels_pane',
  );
  $export['grid_9_promo'] = $ds_view_mode;

  return $export;
}
