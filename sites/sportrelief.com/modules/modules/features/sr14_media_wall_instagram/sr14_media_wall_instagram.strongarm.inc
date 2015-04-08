<?php
/**
 * @file
 * sr14_media_wall_instagram.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function sr14_media_wall_instagram_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'drupagram_client_id';
  $strongarm->value = '6b228eb427094494bb44244b4c19c4bd';
  $export['drupagram_client_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'drupagram_client_secret';
  $strongarm->value = 'a80b749b85a749b396135edc9a0bd34f';
  $export['drupagram_client_secret'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'drupagram_expire';
  $strongarm->value = '0';
  $export['drupagram_expire'] = $strongarm;

  return $export;
}
