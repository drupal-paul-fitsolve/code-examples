<?php

/**
 * PB: 2/9/2014
 * 
 * Contains the rnd15 function override for 'breadcrumb'.
 */

/**
 * Returns HTML for a breadcrumb trail.
 *
 * We need add a span with icon font as the delimitter.
 * Need to do it like this so we don't get a hover on the delimitter.
 */
function rnd15_breadcrumb($variables) {

  $breadcrumb = $variables['breadcrumb'];

  if (!empty($breadcrumb)) {
    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';

    // Add our delimitter span using the icon font classes
    $delimitter = '<span class="icon icon--inline icon-arrow-right type--white">&nbsp;</span>';
    $output .= '<ul class="breadcrumb"><li>' . implode('</li>' . $delimitter . '<li>', $breadcrumb) . '</li></ul>';
    return $output;
  }
}
