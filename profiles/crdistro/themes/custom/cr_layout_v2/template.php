<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * CR Layout V2 theme.
 */

/**
 * Implements hook_omega_theme_libraries_info().
 *
 * Allows sub-themes (and this theme) to add the Modernizr JS
 * library.
 *
 * Usage:
 * 
 *  - Go to admin/appearance/settings/<theme>
 *  - Open the 'Asstes' tab
 *  - Select 'Enable Assets extension'
 *  - Scroll down. Select 'Modernizr'
 *  - Save
 *
 * In general, Modernizr should only be enabled in cr_layout_v2 sub-themes.
 *
 * Testing:
 *
 * There are various ways to test Modernizr is being included:
 *
 *  - Check the following script is being added to <head> scripts section
 *    - /sites/all/themes/custom/cr_layout_v2/libraries/modernizr/modernizr.min.js
 *
 *  - Inspect the body element. You should see a lot of classes added, based on the capabilities
 *    of your browser. Ie. csstransitions, svg, flexbox etc
 *
 *  - In a console window, the Modernizr object shoud be available
 * 
 */
function cr_layout_v2_omega_theme_libraries_info() {
  $libraries['modernizr'] = array(
    'name' => t('Modernizr'),
    'description' => t('Modernizr is a JavaScript library that detects HTML5 and CSS3 features in the user’s browser.'),
    'vendor' => 'Modernizr',
    'vendor url' => 'http://modernizr.com/',
    'package' => t('Polyfills'),
    'files' => array(
      'js' => array(
        'modernizr.min.js' => array(
          'browsers' => array(),
          'weight' => 0,
          'every_page' => TRUE,
        ),
      ),
    ),
  );

  return $libraries;
}