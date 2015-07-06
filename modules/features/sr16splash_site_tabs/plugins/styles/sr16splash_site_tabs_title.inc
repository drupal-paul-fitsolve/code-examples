<?php
/**
 * @file sr16splash_site_tabs_title.inc
 *
 * Definition of the 'Tab Title' region style.
 *
 * Author: Andy E. Phipps
 */

// Plugin definition
$plugin = array(
  'title' => t('Tabs Title'),
  'description' => t('Tabs title'),
  'render region' => 'sr16splash_site_tabs_title_style_render_region',
  'settings form' => 'sr16splash_site_tabs_title_style_render_region_settings_form',
);

/**
 * Render tabs title callback.
 * 
 * Removes the selected 'title pane' from the pane array so it's not rendered
 */
function theme_sr16splash_site_tabs_title_style_render_region($vars) {

  // If we have a title set, grab the FPID for the title, load the fpp object, and
  // remove the key of the FPP's pid from $vars['panes'].
  if (isset($vars['settings']['title_pane'])){
    $titlePaneFPID = $vars['settings']['title_pane'];
    $fpp = fieldable_panels_panes_load($titlePaneFPID);
    $paneId = $fpp->pane_id;
    unset($vars['panes'][$paneId]);
  }
  
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
function sr16splash_site_tabs_title_style_render_region_settings_form($style_settings, $panel_display, $region) {
  
  // Style plugin settings
  $title_pane_options = sr16splash_site_tabs_title_pane_options($panel_display, $region);

  $title_pane_default_value = isset($style_settings['title_pane']) ? $style_settings['title_pane'] : '';

  $form['title_pane'] = array(
    '#title' => t('Title Pane'),
    '#description' => t('Choose a pane in this region to act as tab title'),
    '#type' => 'select',
    '#multiple' => FALSE,
    '#options' => $title_pane_options,
    '#default_value' => $title_pane_default_value,
  );  
  return $form;
}

/**
 * Helper function to add each pane in a region to the select option,
 * allowing the user to select the 'title pane'
 *
 * @param array $panes Passed in array of pane objects
 * @return array $options Options array, 
 *
 */
function sr16splash_site_tabs_title_pane_options($panel_display, $region) {

  // Get the panes that belong to this region
  $region_pane_ids = isset($panel_display->panels[$region]) ? array_flip($panel_display->panels[$region]) : array();

  // Get the panes belonging to this region
  $region_panes = isset($panel_display->content) ? array_intersect_key($panel_display->content, $region_pane_ids) : array();

  // Create default option
  $options = array('_none' => 'Select a pane...');

  // Loop through and return panes as an option
  foreach ($region_panes as $pane_id => $pane_object) {
    if($pane_object->type === 'fieldable_panels_pane') {

      // Grab subtype field and filter out chars, leaving just pane's fpid
      $fpid = filter_var($pane_object->subtype, FILTER_SANITIZE_NUMBER_INT);

      // Use fpid to grab title, only adding to option array if not empty
      $title = fieldable_panels_panes_load($fpid)->title;

      if (!empty($title)) {
        $options[$fpid] = $title;
      } 
    }
  }
  return $options;
}