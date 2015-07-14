<?php
/*
 * @file panel_transitions_flip.inc
 * 
 * Define a Panels style plugin for Transitions: Flip mini-panels.
 * 
 * Author: P.Brady
 * Last updated: 30th October 2014
 *
 */

// Plugin definition
$plugin = array(
  'title' => t('Transition: Flip'),
  'description' => t('Add a transition component.'),
  'render region' => 'rnd15_panel_transitions_flip_render_region',
  'settings form' => 'rnd15_panel_transitions_settings_form',
);

/**
 * Render callback for the Transition: Flip style plugin
 *
 * This render function runs for each region.
 */
function theme_rnd15_panel_transitions_flip_render_region($vars) {

  $panes = $vars['panes'];
  if(!$panes) { return; }

  foreach ($panes as $pane_id => $item) {
    $element[$pane_id] = array(
      '#markup' => $item,
    );
  }

  return drupal_render($element);
}

/**
 * Render preprocess.
 *
 * Ask all modules for hook implementations to allow them to alter $vars.
 *
 * We don't use theme preprocess functions here as preprocessing the Panels
 * theme callbacks is basically a nightmare. No other way to describe it.
 *
 * We just ask other Transition plugins if they want to manipulate or add their stuff to $vars.
 */
function rnd15_panel_transitions_flip_preprocess_panel_transitions__flip(&$vars) {

  // Cache $vars in $localVars to pass to plugins implementing panel_transitions_prepare_vars().
  // Need to do this to avoid merge_recursive errors when passing $vars around too much.
  $localVars = $vars;

  // Ask for implementations of hook_rnd15_panel_transitions_prepare_vars().
  // Append implementations to $vars but pass $localVars around instead of $vars.
  $vars += module_invoke_all('rnd15_panel_transitions_prepare_vars', $localVars);
  
}

/**
 * Implementation of hook_rnd15_panel_transitions_prepare_vars().
 * 
 * Manipulate $vars here. Add the variables this plugin needs for it's layout.tpl.php.
 * 
 * This is kind of a faux preprocess function.
 */
function rnd15_panel_transitions_flip_rnd15_panel_transitions_prepare_vars($vars){

  // Add our manipulations to $localVars so we don't get merge recursion errors
  // when passing $vars around.
  // 
  // Basic rules of thumb here:
  // - if you want to check something or grab a value, look in $vars.
  // - if you want to add something to use later, add it to $localVars.
  $localVars = array();

  // We don't want things flipping all over the place in the panels UI so
  // only preprocess when we're not in the Panels/Page Manager UI.
  if(!$vars['renderer']->admin){
 
    // Cache the part of the panel array we need. Just for readability.
    $settings = $vars['display']->panel_settings['style_settings']['default'];

    // Prepare the flip classes we need for panel-transitions-flip.tpl.php
    // Grab the flip classes we need from $settings.
    if($settings['flip']['use_flip'] == 1) { // Always either 0 or 1
      $localVars['transition_attributes']['class'][] = 'flip';
      if(!empty($settings['flip']['options']['radios'])) {
        $localVars['transition_attributes']['class'][] = drupal_clean_css_identifier($settings['flip']['options']['radios'], array('_' => '-'));
      }
      if(!empty($settings['flip']['options']['front_style'])) {
        $localVars['transition_attributes']['class'][] = drupal_clean_css_identifier($settings['flip']['options']['front_style'], array('_' => '-'));
      }
      // Add the mini panel machine name as a HTML id for QA/GA
      // Id's should be unique but pass through drupal_html_id just in case.
      $localVars['transition_attributes']['id'] = drupal_html_id(str_replace('mini-panel-', '', $vars['css_id']));
    }
  }

  return $localVars;
}


/**
 * Implementation of hook_rnd15_panel_transitions_style_settings().
 *
 * Allow this plugin to add it's form elements to the Transition style settings form.
 *
 * See module_invoke_all in:
 * - rnd15_panel_transitions.custom.inc
 *   - function rnd15_panel_transitions_settings_form($style_settings)
 */
function rnd15_panel_transitions_flip_rnd15_panel_transitions_style_settings($style_settings){

  $form = array();

  $form['flip'] = array(
    '#type' => 'container',
    // Set the weight so this plugin's form elements can be arranged.
    '#weight' => 10,
  );

  // Provides a states-driven checkbox for using flip transitions.
  // Use flip is the default option for new mini panels.
  $form['flip']['use_flip'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use a flip transition?'),
    '#description' => t('Flip between the \'Front\' and \'Back\' regions on hover or initial touch.'),
    '#default_value' => (isset($style_settings['flip']['use_flip'])) ? $style_settings['flip']['use_flip'] : TRUE,
  );

  // Provides the states container for the flip option elements.
  $form['flip']['options'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="settings[flip][use_flip]"]' => array('checked' => TRUE),
      ),
    ),
  );

  // Provides the flip option elements.
  // Flip left is the default option for new mini panels.
  $form['flip']['options']['radios'] = array(
    '#type' => 'radios',
    '#title' => t('Flip effect'),
    '#options' => array(
      'flip_instant'=> t('Swap (no animation)'),
      'flip_left'=> t('Flip left'),
      ),
    '#default_value' => (isset($style_settings['flip']['options']['radios'])) ? $style_settings['flip']['options']['radios'] : 'flip_left'
  );

  return $form;
}