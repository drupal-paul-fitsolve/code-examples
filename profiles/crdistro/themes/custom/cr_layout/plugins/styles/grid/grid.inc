<?php

/**
 * @file
 * Definition of the 'Grid' panel style.
*/

// Plugin definition
$plugin = array(
  'title' => t('Grid'),
  'description' => t('Set the width of your panel panes'),
  'render pane' => 'cr_layout_grid_render_pane',
  'pane settings form' => 'cr_layout_grid_pane_settings',
);

/**
 * Render callback for a single pane.
 */

function theme_cr_layout_grid_render_pane($vars) {
  $content = $vars['content'];
  if (empty($content->content)) {
    return;
  }
  // TO DO: find better way to override? such as push class array?
  $content_classes = $vars['settings']['columns'];
  if (isset($vars['settings']['prefix'])) {
    $content_classes .= ' ' . $vars['settings']['prefix'];
  }
  if (isset($vars['settings']['suffix'])) {
    $content_classes .= ' ' . $vars['settings']['suffix'];
  }
  if (isset($vars['settings']['narrowColumns'])) {
    $content_classes .= ' ' . $vars['settings']['narrowColumns'];
  }
  if (isset($vars['settings']['mobileColumns'])) {
    $content_classes .= ' ' . $vars['settings']['mobileColumns'];
  }
  foreach ($vars['settings'] as $class => $enabled) {
    if ($enabled === 1) {
      $content_classes .= ' ' . $class;
    }
  }
  if(!empty($vars['settings']['extraClasses'])) {
    $content_classes .= ' ' . $vars['settings']['extraClasses'];
  }

  $output = '';
  $output .= (isset($vars['settings']['pane_prefix'])) ? $vars['settings']['pane_prefix'] : '';
  $output .= '<div class="' . $content_classes . '">';
  $output .= theme('panels_pane', $vars);
  $output .= '</div>';
  $output .= (isset($vars['settings']['pane_suffix'])) ? $vars['settings']['pane_suffix'] : '';
  return $output;
}

function cr_layout_grid_pane_settings($style_settings) {
  // Get all the grid columns set in theme setting "content" region
  // Temporary hack so you can use the plugin within the backend panels editor (mini panels)
  $maxColumns = theme_get_setting("alpha_zone_content_columns", 'cr_layout');
  $columns = array();
  for ($i=1; $i <= $maxColumns; $i++) {
    $columns['grid-' . $i] = 'Grid ' . $i;
  }
  $narrowColumns = array();
  $narrowColumns[''] = 'None';
  for ($i=1; $i <= $maxColumns; $i++) {
    $narrowColumns['narrow-grid-' . $i] = 'Grid ' . $i;
  }
  $mobileColumns = array();
  $mobileColumns[''] = 'None';
  for ($i=1; $i <= $maxColumns; $i++) {
    $mobileColumns['mobile-grid-' . $i] = 'Grid ' . $i;
  }
  $prefix = array();
  $prefix[''] = 'None';
  for ($i=1; $i <= $maxColumns; $i++) {
    $prefix['prefix-' . $i] = 'Grid ' . $i;
  }
  $suffix = array();
  $suffix[''] = 'None';
  for ($i=1; $i <= $maxColumns; $i++) {
    $suffix['suffix-' . $i] = 'Grid ' . $i;
  }

  $classes = array (
    'alpha' => t('First column (alpha)'),
    'omega' => t('Last column (omega)'),
    'narrow-alpha' => t('Narrow First column (alpha)'),
    'narrow-omega' => t('Narrow Last column (omega)'),
    'mobile-alpha' => t('Mobile First column (alpha)'),
    'mobile-omega' => t('Mobile Last column (omega)'),
    'mobile-row' => t('Mobile Row'),
    'force-end-desktop' => t('Force Pane to right side on desktop only'),
    'text-align-center-narrow-mobile' => t('Centralise text on narrow and mobile'),
    'text-align-center-mobile-only' => t('Centralise text on mobile only'),
    'text-align-center-all' => t('Centralise text across all screens sizes'),      
    'container-center' => t('Centre Container'),
  );

  $form = array();

  $columns_default_value = isset($style_settings['columns']) ? $style_settings['columns'] : 'grid-4';
  $form['columns'] = array(
    '#title' => 'Column Width',
    '#type' => 'select',
    '#options' => $columns,
    '#default_value' => $columns_default_value,
  );

  $prefix_default_value = isset($style_settings['prefix']) ? $style_settings['prefix'] : '';
  $form['prefix'] = array(
    '#title' => 'Prefix',
    '#type' => 'select',
    '#options' => $prefix,
    '#default_value' => $prefix_default_value,
  );

  $suffix_default_value = isset($style_settings['suffix']) ? $style_settings['suffix'] : '';
  $form['suffix'] = array(
    '#title' => 'Suffix',
    '#type' => 'select',
    '#options' => $suffix,
    '#default_value' => $suffix_default_value,
  );

  $narrow_columns_default_value = isset($style_settings['narrowColumns']) ? $style_settings['narrowColumns'] : '';
  $form['narrowColumns'] = array(
    '#title' => 'Narrow Column Width',
    '#description' => 'Specify a grid width only for narrow screen sizes.',
    '#type' => 'select',
    '#options' => $narrowColumns,
    '#default_value' => $narrow_columns_default_value,
  );

  $mobile_columns_default_value = isset($style_settings['mobileColumns']) ? $style_settings['mobileColumns'] : '';
  $form['mobileColumns'] = array(
    '#title' => 'Mobile Column Width',
    '#description' => 'Specify a grid width only for mobile screen sizes.',
    '#type' => 'select',
    '#options' => $mobileColumns,
    '#default_value' => $mobile_columns_default_value,
  );

  //Generate checkboxes from classes array
  foreach ($classes as $class => $title) {
    $form[$class] = array(
      '#title' => $title,
      '#type' => 'checkbox',
      '#default_value' => (int)($style_settings[$class] == 1),
    );
  }

  $extra_classes_default_value = isset($style_settings['extraClasses']) ? $style_settings['extraClasses'] : '';
  $form['extraClasses'] = array(
    '#title' => 'Extra Classes',
    '#description' => 'Drop any classes you want in here.',
    '#type' => 'textfield',
    '#default_value' => $extra_classes_default_value,
  );

  return $form;
}
