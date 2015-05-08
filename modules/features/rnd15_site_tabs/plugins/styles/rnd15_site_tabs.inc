<?php
/**
 * @file rnd14_site_tabs.inc
 *
 * Definition of the 'Tab' panel style.
 *
 * Author: Andy E. Phipps
 */

// Plugin definition
$plugin = array(
  'title' => t('Tab'),
  'description' => t('Show panel panes in a region as a tab.'),
  'render region' => 'rnd15_site_tabs_style_render_region',
  'settings form' => 'rnd15_site_tabs_style_render_region_settings_form',
);

/**
 * Render callback.
 * Based on render region function in rnd15_site_slideshows
 */
function theme_rnd15_site_tabs_style_render_region($vars) {

  $panes = $vars['panes'];
  if(!$panes) { return; }

  // render through all panes, prepare content for drupal_render
  foreach ($panes as $pane_id => $item) {

    $element[$pane_id] = array(
      '#markup' => $item,
    );
  }
  return drupal_render($element);
}

/**
 * Region settings form callback.
 */
function rnd15_site_tabs_style_render_region_settings_form($style_settings, $panel_display) {
  
  // View Modes of Fieldable Panel Pane - add a select field
  $entity_info = entity_get_info('fieldable_panels_pane');
  foreach ($entity_info['view modes'] as $id => $config) {
    // push label value back to array key, so it displays label on dropdown options 
    $entity_info['view modes'][$id] = $entity_info['view modes'][$id]['label'];
  }

  $view_mode_default_value = isset($style_settings['view_mode']) ? $style_settings['view_mode'] : '';
  
  $form['view_mode'] = array(
    '#type' => 'select',
    '#title' => t('View Modes of Panes'),
    '#multiple' => FALSE,
    '#options' => $entity_info['view modes'],
    '#default_value' => $view_mode_default_value,
    '#description' => t('Set view modes of all fieldable panes'),
  );

  $tabs_heading_default_value = isset($style_settings['tabsHeading']) ? $style_settings['tabsHeading'] : '';

  $form['tabsHeading'] = array(
    '#title' => t('Tabs Heading'),
    '#description' => t('H3 rendered above the tabs'),
    '#type' => 'textfield',
    '#default_value' =>  $tabs_heading_default_value,
  );

  /** 
    * Array of non-empty regions in the minipanel, allowing dev to choose
    * which region/tab the page defaults to upon page open
    */
  $regionList = array_keys($panel_display->panels);

  // Set array to use 1-index rather than 0-index, to match region naming/numbering convention (as used in js)
  foreach ( $regionList as $key => $val ) {
    $regionList[ $key+1 ] = $val;
  }
  
  unset($regionList[0]);

  // Defaults to using tab/region #1 as default tab when user lands on page
  $default_tab_default_value = isset($style_settings['defaultTab']) ? $style_settings['defaultTab'] : '1';

  $form['defaultTab'] = array(
    '#title' => t('Default Tab'),
    '#description' => t('Sets the default tab for the page (if no tabname is stipulated in the URL)'),
    '#type' => 'select',
    '#multiple' => FALSE,
    '#options' => $regionList,
    '#default_value' => $default_tab_default_value,
  );

  // Extra classes - this output same level of tab wrapper
  $extra_classes_default_value = isset($style_settings['extraClasses']) ? $style_settings['extraClasses'] : '';
  $form['extraClasses'] = array(
    '#title' => t('Extra Classes'),
    '#description' => t('Drop any classes you want in here, this class applies to the same level of tab wrapper'),
    '#type' => 'textfield',
    '#default_value' => $extra_classes_default_value,
  );
  
  return $form;
}