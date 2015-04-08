<?php
/**
 * @file
 * sr_layout_base.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function sr_layout_base_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'semantic_panels_attributes';
  $strongarm->value = array(
    'title' => 'title',
    'target' => 'target',
    'role' => 'role',
    'tabindex' => 'tabindex',
    'id' => 'id',
    'lang' => 'lang',
    'accesskey' => 'accesskey',
    'data-start' => 'data-start',
    'data-end' => 'data-end',
    'data-bottom-center' => 'data-bottom-center',
    'data--100-bottom-bottom' => 'data--100-bottom-bottom',
    'data-center-center' => 'data-center-center',
  );
  $export['semantic_panels_attributes'] = $strongarm;

  return $export;
}
