<?php
/**
 * @file
 * rnd15_site_header.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function rnd15_site_header_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_name';
  $strongarm->value = 'Red Nose Day';
  $export['site_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_slogan';
  $strongarm->value = '13th March 2015';
  $export['site_slogan'] = $strongarm;

  return $export;
}
