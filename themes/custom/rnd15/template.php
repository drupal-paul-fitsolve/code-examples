<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * RND15 theme.
 */

/**
 * Implementation of hook_()_alter
 *
 * Add .type--white to each anchor in the breadcrumb.
 *  
 * We need to add a .type--white class to each breadcrumb link. Overrriding 
 * theme_breadcrumb doesn't allow us access to the anchors themselves. Only the wrapper.
 *
 * So instead, we use hook_()_alter to alter the breadcrumb anchors well before they're
 * ready for the theme.
 */
function rnd15_menu_breadcrumb_alter(&$active_trail, $item) {
 
  // Classes to add to breadcrumb anchors
  // Add additional classes to the $classes array, should you need to.
  $classes = array(
    'type--white',
  );

  // Loop through each breadcrumb link
  foreach ($active_trail as &$breadcrumb) {
    // Add .type--white to each anchor
    $breadcrumb['localized_options']['attributes']['class'] = implode($classes, ' ');

    // Add title attribute to breadcrumb anchor.
    // Not sure why Drupal doesn't do this already. Strange.
    $breadcrumb['localized_options']['attributes']['title'] = $breadcrumb['title'];
  }
}