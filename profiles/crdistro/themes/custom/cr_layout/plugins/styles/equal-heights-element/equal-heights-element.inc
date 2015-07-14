<?php

/**
 * @file
 * Definition of the 'Equal Heights Element' panel style.
*/

// Plugin definition
$plugin = array(
  'title' => t('Equal Height Element'),
  'description' => t('Sets the equal height element class'),
  'render region' => '',
  'render pane' => 'cr_layout_equal_height_element_render_pane',
);

/**
 * Render callback for a single pane.
 */
function theme_cr_layout_equal_height_element_render_pane($vars) {
  $content = $vars['content'];
  if (empty($content->content)) {
    return;
  }

  $output = '<div class="equal-height-element">';
  $output .= theme('panels_pane', $vars);
  $output .= '</div>';
  return $output;

}
