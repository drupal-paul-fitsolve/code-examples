<?php
/**
 * @file
 * sr16splash_site_wysiwyg.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function sr16splash_site_wysiwyg_filter_default_formats() {
  $formats = array();

  // Exported format: wysiwyg.
  $formats['wysiwyg'] = array(
    'format' => 'wysiwyg',
    'name' => 'wysiwyg',
    'cache' => 0,
    'status' => 1,
    'weight' => -10,
    'filters' => array(
      'filter_tokens' => array(
        'weight' => -50,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_html' => array(
        'weight' => -49,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<u> <a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd> <img> <div> <p> <h1> <h2> <h3> <h4> <h5> <h6> <video> <source><span><br>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'picture' => array(
        'weight' => -46,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_fbshare' => array(
        'weight' => -20,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
