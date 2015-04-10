<?php
/**
 * @file
 * sr14_menu.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function sr14_menu_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'header sainsburys logo';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'header_sainsburys_logo';
  $fe_block_boxes->body = '<p><a href="/partners" alt="Sainsburys" class="sainsburys-logo"> &nbsp;<span>&nbsp;</span></a></p>';

  $export['header_sainsburys_logo'] = $fe_block_boxes;

  return $export;
}
