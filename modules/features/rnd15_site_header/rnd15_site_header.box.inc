<?php
/**
 * @file
 * rnd15_site_header.box.inc
 */

/**
 * Implements hook_default_box().
 */
function rnd15_site_header_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'simple_nav';
  $box->plugin_key = 'simple';
  $box->title = '<none>';
  $box->description = 'simple navigation for donate pages';
  $box->options = array(
    'body' => array(
      'value' => '<nav class="simple-nav__wrapper nav"><ul class="menu"><li><a href="/"><span>Back to Home</span></a></li></ul></nav>',
      'format' => 'full_html',
    ),
    'additional_classes' => 'nav__wrapper ',
  );
  $export['simple_nav'] = $box;

  return $export;
}
