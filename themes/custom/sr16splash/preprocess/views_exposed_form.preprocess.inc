<?php

/**
 * @file
 * Contains a pre-process hook for 'preprocess_views_exposed_form'.
 */

/**
 * Implements hook_preprocess_views_exposed_form.
 */
function sr16splash_preprocess_views_exposed_form(&$vars, $hook) {

  // Adds a font icon to the submit button on the Fundraiser
  // Gallery exposed search form.
  if ($vars['form']['#id'] == 'views-exposed-form-fundraiser-showcase-panel-pane-1') {

    // Change the text on the submit button
    $vars['form']['submit']['#value'] = decode_entities('&#xe617;');

    // Rebuild the rendered version (submit button, rest remains unchanged)
    unset($vars['form']['submit']['#printed']);
    $vars['button'] = drupal_render($vars['form']['submit']);

  }
  
}