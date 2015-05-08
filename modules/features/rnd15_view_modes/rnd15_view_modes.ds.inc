<?php
/**
 * @file
 * rnd15_view_modes.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function rnd15_view_modes_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'full_content';
  $ds_view_mode->label = 'Full content';
  $ds_view_mode->entities = array(
    'fieldable_panels_pane' => 'fieldable_panels_pane',
    'node' => 'node',
  );
  $export['full_content'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'panel';
  $ds_view_mode->label = 'Panel';
  $ds_view_mode->entities = array(
    'fieldable_panels_pane' => 'fieldable_panels_pane',
    'node' => 'node',
  );
  $export['panel'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'token';
  $ds_view_mode->label = 'Token';
  $ds_view_mode->entities = array(
    'fieldable_panels_pane' => 'fieldable_panels_pane',
    'node' => 'node',
  );
  $export['token'] = $ds_view_mode;

  return $export;
}
