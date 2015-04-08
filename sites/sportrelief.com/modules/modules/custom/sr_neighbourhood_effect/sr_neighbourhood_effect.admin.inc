<?php

/**
 * @file
 * Administrative page callbacks for the sr_neighbourhood_effect module.
 */

/**
 * Implements hook_admin_settings() for module settings configuration.
 */
function sr_neighbourhood_effect_admin_settings_form($form_state) {

  $form['sr_neighbourhood_effect_enable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable neighbourhood effect tracking'),
    '#default_value' => variable_get('sr_neighbourhood_effect_enable', 0),
  );

  $form['sr_neighbourhood_effect_url'] = array(
    '#title' => t('Script URL'),
    '#type' => 'textfield',
    '#default_value' => variable_get('sr_neighbourhood_effect_url', 'https://hotspot.datatalk.co.uk/frgyh/HSD.js'),
    '#size' => 15,
    '#maxlength' => 255,
    '#required' => TRUE,
    '#description' => t('The script url used for the tracking.  Defaults to: https://hotspot.datatalk.co.uk/frgyh/HSD.js'),
  );

  return system_settings_form($form);
}