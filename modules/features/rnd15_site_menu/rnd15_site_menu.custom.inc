<?php
/**
 * @file
 * All custom code of the rnd15 Site Menu Feature
 */

/**
 * Implements hook_preprocess_menu_link().
 *
 * Intercepts the menu links to:
 * - Add a span
 * - Add faux top level menu where we have children to toggle the menu
 */
function rnd15_site_menu_preprocess_menu_link(&$vars) {
  // Preprocess the main menu links
  if(!empty($vars['element']) && $vars['element']['#theme'] == 'menu_link__main_menu') {
    _preprocess_menu_link__main_menu($vars);
  }
}

function _preprocess_menu_link__main_menu(&$vars) {

  // Nice little script that creates a 'fake' menu item of the primary top level link
  if(!empty($vars['element']['#below'])) {
    // Create a copy of the current menu
    $duplicate_primary_link = $vars['element'];

    // Reset the #below as we do not want to rerender the children again
    $duplicate_primary_link['#below'] = array();

    // Remove existing classes (e.g. expanding) and add custom and first class
    $duplicate_primary_link['#attributes']['class'] = array('leaf', 'first');
    $duplicate_primary_link['#localized_options']['attributes']['class'][] = 'nav__link--primary-duplicate';

    // Remove the 'first' class from the old menu item
    $menu_keys = array_keys($vars['element']['#below']);
    unset($vars['element']['#below'][$menu_keys[0]]['#attributes']['class'][0]);

    // Add the new item to the beginning
    array_unshift($vars['element']['#below'], $duplicate_primary_link);
  }

  // Add a unique id
  // Format: #menu-<clean url>
  $link_id_str = 'menu-'.$vars['element']['#title'];
  $vars['element']['#localized_options']['attributes']['id'] = drupal_html_id($link_id_str);

  // Adds span so we can style this correctly
  $vars['element']['#localized_options']['html'] = TRUE;
  $vars['element']['#title'] = '<span>' . $vars['element']['#title'] . '</span>';
}