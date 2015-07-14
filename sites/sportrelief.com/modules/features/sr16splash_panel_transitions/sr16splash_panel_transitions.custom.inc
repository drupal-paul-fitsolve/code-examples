<?php
/*
 * @file sr16splash_panel_transitions.custom.inc
 * 
 * 1. Provide a style settings form for other plugins to hook into and add to.
 * 
 * 2. Add form fields and variables used across all Transition plugins.
 * 
 * Author: P.Brady
 * Last updated: 30th October 2014
 *
 */

function sr16splash_panel_transitions_settings_form($style_settings, $display, $pid, $type, $form_state) {

  // Create an empty $form array.
  $form = array();

  // Plugins provide the Form API elements they want to add.
  // 
  // Ask for implementations of hook_panel_transitions_style_settings and add them
  // to the $form array.
  // 
  // Also note that we pass $style_settings to the hook implementations so 
  // plugin form elements can default to their previously saved values.
  $form += module_invoke_all('sr16splash_panel_transitions_style_settings', $style_settings);

  // module_invoke_all gets hook impementations ordered by module name. This messes
  // with the weight of form elements set in the plugins.
  // To respect those weights, we need to arrange the $form array by weight here.
  uasort($form, 'drupal_sort_weight');
  
  // Add the default form fields that will apply to all Transition plugins.
  
  // Add CTA
  $form['cta'] = array(
    '#type' => 'container',
    // Set the weight so this plugin's form elements can be arranged.    
    '#weight' => 20,    
  );

  // Provides a states-driven checkbox for using a CTA in transitions.
  // Use flip is the default option for new mini panels.
  $form['cta']['use_cta'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use a CTA?'),
    '#description' => t('Wrap the panes in the \'Back\' region in a link.'),
    '#default_value' => (isset($style_settings['cta']['use_cta'])) ? $style_settings['cta']['use_cta'] : TRUE,
  );

  // Provides the states container for the cta option elements.
  $form['cta']['options'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="settings[cta][use_cta]"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['cta']['options']['link']['title'] = array(
    '#type' => 'textfield', 
    '#title' => t('Title'), 
    '#default_value' => (isset($style_settings['cta']['options']['link']['title'])) ? $style_settings['cta']['options']['link']['title'] : '',
    '#size' => 60, 
    '#maxlength' => 128, 
    '#description' => t('Supports tokens IE. [dl:machine_name:title]'),    
  );

  $form['cta']['options']['link']['url'] = array(
    '#type' => 'textfield', 
    '#title' => t('URL'), 
    '#default_value' => (isset($style_settings['cta']['options']['link']['url'])) ? $style_settings['cta']['options']['link']['url'] : '',
    '#size' => 60, 
    '#maxlength' => 256, 
    '#description' => t('Supports tokens IE. [dl:machine_name:url]'),        
  );

  $form['cta']['options']['link']['tokens'] = array(
    '#theme' => 'token_tree',
    '#token_types' => array('all'),
  );

  $form['cta']['options']['link']['blank'] = array(
    '#type' => 'checkbox',
    '#title' => t('Open in a new window?'),
    '#default_value' => (isset($style_settings['cta']['options']['link']['blank'])) ? $style_settings['cta']['options']['link']['blank'] : TRUE,
  );

  // Add a custom classes field
  $form['custom_classes'] = array(
    '#type' => 'container',
    // Set the weight so this plugin's form elements can be arranged.    
    '#weight' => 100,    
  );

  // Provides a states-driven checkbox for using custom classes for a tansition.
  $form['custom_classes']['use_custom_classes'] = array(
    '#type' => 'checkbox',
    '#title' => t('Apply custom classes?'),
    '#description' => t('Apply custom classes to this transition element.'),
    '#default_value' => (isset($style_settings['custom_classes']['use_custom_classes'])) ? $style_settings['custom_classes']['use_custom_classes'] : FALSE,
  );

  // Provides the states container for the cta option elements.
  $form['custom_classes']['options'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="settings[custom_classes][use_custom_classes]"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['custom_classes']['options']['classes'] = array(
    '#type' => 'textfield', 
    '#description' => t('Supply a space-separated list of classes without the dot prefix.'),
    '#default_value' => (isset($style_settings['custom_classes']['options']['classes'])) ? $style_settings['custom_classes']['options']['classes'] : '',
    '#size' => 60, 
    '#maxlength' => 128, 
  );
  
  return $form;
}

/**
 * Implementation of hook_sr16splash_panel_transitions_prepare_vars().
 *
 * All plugins invoke this hook to ensure our default Transition varables get added.
 * 
 * Add default transition variables here.
 * 
 * This is kind of a faux preprocess function.
 *
 * Ensure $transition_attributes and the $cta (if applicable) are available to all Transition plugins.
 */
function sr16splash_panel_transitions_sr16splash_panel_transitions_prepare_vars($vars){
  
  // Add our manipulations to $localVars so we don't get merge recursion errors
  // when passing $vars around.
  // 
  // Basic rules of thumb here:
  // - if you want to check something or grab a value, look in $vars.
  // - if you want to add something to use later, add it to $localVars.
  $localVars = array(
    'cta' => '', // Set default, for override later.
  );

  // Only preprocess when we're not in the Panels/Page Manager UI.
  if(!$vars['renderer']->admin){
 
    // Cache the part of the panel array we need. Just for readability.
    $settings = $vars['display']->panel_settings['style_settings']['default'];

    // Prepare the custom classes we need for panel-transitions-flip.tpl.php
    // Grab the custom classes we need from $settings.
    if($settings['custom_classes']['use_custom_classes'] == 1) { // Always either 0 or 1
      $localVars['transition_attributes']['class'][] =  drupal_clean_css_identifier($settings['custom_classes']['options']['classes'], array('_' => '-'));
    }

    // Prepare the CTA (if applicable) for panel-transitions-flip.tpl.php
    if($settings['cta']['use_cta'] == 1) { // Always either 0 or 1
     
      $cta_title = $cta_target = $cta_url = '';            

      // Prepare the title attribute
      (isset($settings['cta']['options']['link']['title'])) ? $cta_title = $settings['cta']['options']['link']['title'] : $cta_title = '';

      // Prepare the target = _blank attribute
      $settings['cta']['options']['link']['blank'] == 1 ? $cta_target = '_blank' : $cta_target = '';

      // Prepare the URL
      (isset($settings['cta']['options']['link']['url'])) ? $cta_url = $settings['cta']['options']['link']['url'] : '';

      // Prepare the ID
      $cta_id = ' id="' . str_replace('mini-panel-', '', drupal_html_id($vars['css_id'])) . '__cta" ';

      if($cta_title){
        // Resolve the token used in the Title field, if applicable.
        $cta_title = token_replace($cta_title);
      }

      if($cta_url){
        // Resolve the URL field to a URL, if applicable.
        $cta_url = token_replace($cta_url);
      }

      // We need to construct the anchor link manually here. Can't use l() as we can't have
      // a trailing </a>. The trailing </a> is added in a conditional in the transition's layout.tpl.php.
      
      // Contruct the title attribute
      $cta_title ? $cta_title = 'title="' . $cta_title . '"' : '';

      // Contruct the target attribute
      $cta_target ? $cta_target = ' target="' . $cta_target . '" ' : '';

      // Now contruct the anchor without a trailing </a>
      $localVars['cta'] = '<a ' . $cta_id . ' ' . $cta_title . $cta_target . 'href="' . $cta_url . '">';
      
    }

  }

  return $localVars;
}