<?php

/**
 * @file
 * Contains a pre-process hook for 'html'.
 */

/**
 * Implements hook_preprocess_TEMPLATE().
 */
function rnd15_preprocess_html(&$variables) {
  // IE8 Polyfill for indexof and event listener
  drupal_add_js(drupal_get_path('theme', 'rnd15') . '/js/vendor/ie8-polyfill.js', array(
    'browsers' => array(
      'IE' => 'lt IE 9', 
      '!IE' => FALSE
      )
    )
  );

  /*
   * Checks if the user is logged in and needs admin styles
   */
  if($variables['logged_in']) {
    drupal_add_css(drupal_get_path('theme', 'rnd15') . '/css/rnd15-admin.styles.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'weight'=>200, 'preprocess' => FALSE,'external' => TRUE));
  }
}