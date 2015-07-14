<?php

/**
 * @file
 * Definition of the 'Centering' panel style.
*/

// Plugin definition
$plugin = array(
  'title' => t('Centering'),
  'description' => t('Centering panel panes content'),
  'render region' => '',
  'render pane' => 'cr_layout_centering_render_pane',
);

/**
 * Render callback for a single pane.
 */
function theme_cr_layout_centering_render_pane($vars) {
  $content = $vars['content'];
  if (empty($content->content)) {
    return;
  }

  $output = '<div class="text-align-center">';
  $output .= theme('panels_pane', $vars);
  $output .= '</div>';
  return $output;

}
