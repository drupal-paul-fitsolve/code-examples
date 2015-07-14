<?php

/**
 * @file
 * Definition of the 'Grey' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Grey'),
  'description' => t('Show panel panes in a region as tabs.'),
  'render region' => 'panels_grey_style_render_region',
);

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_panels_grey_style_render_region($vars) {
  $panes = $vars['panes'];
  $output = '<div class="grey-background grey-background--light">';
    foreach ($panes as $pane_id => $pane) {
      $output .= $pane;
    }
   $output .=  '</div>';
  return $output;
}
