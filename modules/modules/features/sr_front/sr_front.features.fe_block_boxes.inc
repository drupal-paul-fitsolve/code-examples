<?php
/**
 * @file
 * sr_front.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function sr_front_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Google event microformat';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'event_microformat';
  $fe_block_boxes->body = '<div class="vevent">
  <span class="dtstart">
    <span class="value-title" title="2014-03-21"></span>
  </span>
  <span class="dtend">
    <span class="value-title" title="2014-03-23"></span>
  </span>
  <span class="location">
    <span class="region value-title" title="United Kingdom"></span>
  </span>
  <span class="eventType">
    <span class="value-title" title="Charity Event"></span>
  </span>
</div>';

  $export['event_microformat'] = $fe_block_boxes;

  return $export;
}
