<?php
/**
 * @file
 * sr16splash_site_header.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function sr16splash_site_header_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_name';
  $strongarm->value = 'Sport Relief';
  $export['site_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_slogan';
  $strongarm->value = '18-20th 2016';
  $export['site_slogan'] = $strongarm;

  return $export;
}
