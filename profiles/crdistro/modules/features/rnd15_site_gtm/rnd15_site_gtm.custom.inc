<?php
/**
 * @file
 * All custom code of the RND15 Site GTM Feature
 */

/**
 * Implements hook_preprocess_html
 * 
 * Simply adds an inline JS to declare the data variable so it's immediately available to all scripts
 */
function rnd15_site_gtm_preprocess_html(&$variables) {
  drupal_add_js('var dataLayer = []; // GTM VAR',
    array('type' => 'inline', 'scope' => 'header', 'weight' => -100)
  );
}