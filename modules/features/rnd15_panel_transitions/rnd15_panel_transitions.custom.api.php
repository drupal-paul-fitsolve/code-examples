<?php

/**
 * @file
 * Describe hooks provided by the rnd15 Panel Transitions Module.
 */

/**
 *
 * Describe hook_rnd15_panel_transitions_style_settings.
 *
 * Use this hook to add your transition's plugin settings to the transition settings form in Mini-Panels.
 *
 * Basically, just build a Drupal Form API form array and return it.
 * 
 * This hook should be implemented by your module in <your-module>/plugins/styles/<your-module>.inc and it will be
 * auto-loaded.
 * 
 * Eg. function mymodule_rnd15_panel_transitions_style_settings(style_settings){
 *   ...
 * }
 *
 * @return
 * A typical Drupal Form API form array.
 *
 * Example, assuming a plugin called panel_transitions_rotate: 
 * 
 * function rnd15_panel_transitions_rotate_rnd15_panel_transitions_style_settings($style_settings){
 *
 *   $form = array();
 *
 *     $form['rotate'] = array(
 *       '#type' => 'container',
 *       // Set the weight so this plugin's form elements can be arranged.
 *       '#weight' => 10,
 *     );
 *
 *     // Provides a states-driven checkbox for using rotate transitions.
 *     // Use rotate is the default option for new mini panels.
 *     $form['rotate']['use_rotate'] = array(
 *       '#type' => 'checkbox',
 *       '#title' => t('Use a rotate transition?'),
 *       '#description' => t('Rotate between the \'Front\' and \'Back\' regions on hover or initial touch.'),
 *       '#default_value' => (isset($style_settings['rotate']['use_rotate'])) ? $style_settings['rotate'][
 *       'use_rotate'] : TRUE,
 *     );
 *   
 *    return $form;
 *   }
 *
 *
 * Notes:
 * 
 * - Remember to add a weight to the container of your form elements for sensible positions in the settings form.
 * - Use $style_settings in your hook implementation.
 *
 * 
 *
 * Describe cTools plugin declaration settings.
 *
 * If you're building a Transition plugin, approach it like you would any other Panels plugin, except for two things:
 * 
 * 1:
 * 
 * See below. Notice the value for 'settings form' below. Just point it back to
 * 'rnd15_panel_transitions_settings_form' module so hook implementations can be gathered in one place.
 *
 *   // Plugin definition
 *   $plugin = array(
 *    'title' => t('Transition: Flip'),
 *    'description' => t('Add a transition component.'),
 *    'render region' => 'panel_transitions_flip_render_region',
 *    // Uses the setting form from rnd15_panel_transitions so other
 *    // modules can implement the rnd15_panel_transitions hooks.
 *    'settings form' => 'rnd15_panel_transitions_settings_form',
 *    // The plugin can have it's own validation function.
 *    'settings form validate' => 'rnd15_panel_transitions_flip_settings_form_validate',
 *  );
 *
 *  2: Implement hook_rnd15_panel_transitions_prepare_vars().
 *
 *  All plugins invoke this hook to ensure their default Transition variables are added to use in their
 *  layout.tpl.php file.
 *
 *  The following is an example from rnd15_panel_transitions_flip module.
 *  
 *  ----------------
 *  
 *  Ensure $transition_attributes and the $cta (if applicable) are available to all Transition plugins.
 * 
 *  function rnd15_panel_transitions_flip_rnd15_panel_transitions_prepare_vars($vars){
 *
 *    // Add our manipulations to $localVars so we don't get merge recursion errors
 *    // when passing $vars around.
 *    // 
 *    // Basic rules of thumb here:
 *    // - if you want to check something or grab a value, look in $vars.
 *    // - if you want to add something to use later, add it to $localVars.
 *    $localVars = array();
 *
 *    // We don't want things flipping all over the place in the panels UI so
 *    // only preprocess when we're not in the Panels/Page Manager UI.
 *    if(!$vars['renderer']->admin){
 *
 *     // Cache the part of the panel array we need. Just for readability.
 *     $settings = $vars['display']->panel_settings['style_settings']['default'];
 *
 *     // Prepare the flip classes we need for panel-transitions-flip.tpl.php
 *     // Grab the flip classes we need from $settings.
 *     if($settings['flip']['use_flip'] == 1) { // Always either 0 or 1
 *       $localVars['transition_attributes']['class'][] = 'flip';
 *       $localVars['transition_attributes']['class'][] =  drupal_clean_css_identifier($settings['flip']['options'][
 *       'radios'], array('_' => '-'));
 *     }
 *   }
 *
 *   return $localVars;
 *  }
 *  
 *  ----------------
