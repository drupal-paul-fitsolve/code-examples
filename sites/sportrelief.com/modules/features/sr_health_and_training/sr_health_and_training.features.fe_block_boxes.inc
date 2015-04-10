<?php
/**
 * @file
 * health_and_training.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function sr_health_and_training_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Health and Training Quiz';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'health_quiz';
  $fe_block_boxes->body = 'Content';

  $export['health_quiz'] = $fe_block_boxes;

  return $export;
}
