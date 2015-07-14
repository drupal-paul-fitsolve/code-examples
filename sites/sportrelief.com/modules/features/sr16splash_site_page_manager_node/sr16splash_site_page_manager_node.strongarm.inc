<?php
/**
 * @file
 * sr16splash_site_page_manager_node.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function sr16splash_site_page_manager_node_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_month_day_year';
  $strongarm->value = 'F jS Y';
  $export['date_format_month_day_year'] = $strongarm;

  return $export;
}
