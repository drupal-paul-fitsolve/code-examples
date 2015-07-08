<?php
/**
 * @file
 * sr16splash_site_panes.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function sr16splash_site_panes_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_fieldable_panels_pane__text';
  $strongarm->value = array(
    'view_modes' => array(
      'basic_pod' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'picture_main1pod_withoutside' => array(
        'custom_settings' => FALSE,
      ),
      'picture_main1pod_withside' => array(
        'custom_settings' => FALSE,
      ),
      'picture_main2pod_withoutside' => array(
        'custom_settings' => FALSE,
      ),
      'picture_main2pod_withside' => array(
        'custom_settings' => FALSE,
      ),
      'picture_main3pod_withoutside' => array(
        'custom_settings' => FALSE,
      ),
      'picture_main3pod_withside' => array(
        'custom_settings' => FALSE,
      ),
      'picture_promo_withoutside_' => array(
        'custom_settings' => FALSE,
      ),
      'picture_promo_withside' => array(
        'custom_settings' => FALSE,
      ),
      'picture_subpod_withoutside' => array(
        'custom_settings' => FALSE,
      ),
      'list_view' => array(
        'custom_settings' => FALSE,
      ),
      'intro' => array(
        'custom_settings' => TRUE,
      ),
      'pod' => array(
        'custom_settings' => FALSE,
      ),
      'intro_headline_huge' => array(
        'custom_settings' => TRUE,
      ),
      'grid_4' => array(
        'custom_settings' => FALSE,
      ),
      'grid_6' => array(
        'custom_settings' => FALSE,
      ),
      'grid_8' => array(
        'custom_settings' => FALSE,
      ),
      'grid_9' => array(
        'custom_settings' => FALSE,
      ),
      'grid_12' => array(
        'custom_settings' => FALSE,
      ),
      'grid_14' => array(
        'custom_settings' => FALSE,
      ),
      'grid_16' => array(
        'custom_settings' => FALSE,
      ),
      'grid_18' => array(
        'custom_settings' => FALSE,
      ),
      'grid_20' => array(
        'custom_settings' => FALSE,
      ),
      'grid_22' => array(
        'custom_settings' => FALSE,
      ),
      'grid_24' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'title' => array(
          'default' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
          'basic_pod' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
          'intro' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
          'intro_headline_huge' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_fieldable_panels_pane__text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_fieldable_panels_pane__video';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'full_content' => array(
        'custom_settings' => FALSE,
      ),
      'panel' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
      ),
      'display' => array(
        'title' => array(
          'default' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_fieldable_panels_pane__video'] = $strongarm;

  return $export;
}
