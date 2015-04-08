<?php
/**
 * @file
 * partners.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function partners_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_fieldable_panels_pane__partner';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'list_view' => array(
        'custom_settings' => TRUE,
      ),
      'basic_pod_reverse' => array(
        'custom_settings' => FALSE,
      ),
      'flexslider_carousel_thumb' => array(
        'custom_settings' => FALSE,
      ),
      'flexslider_grid_16' => array(
        'custom_settings' => FALSE,
      ),
      'flexslider_main_slide' => array(
        'custom_settings' => FALSE,
      ),
      'intro_headline_huge' => array(
        'custom_settings' => FALSE,
      ),
      'tabs_grid_18' => array(
        'custom_settings' => FALSE,
      ),
      'tabs_grid_24' => array(
        'custom_settings' => FALSE,
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
      'grid_13' => array(
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
      'basic_pod' => array(
        'custom_settings' => FALSE,
      ),
      'intro' => array(
        'custom_settings' => FALSE,
      ),
      'partner_basic' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'action_pod_grid_3_404_page' => array(
        'custom_settings' => FALSE,
      ),
      'basic_pod_image_first_grid8' => array(
        'custom_settings' => FALSE,
      ),
      'grid_12_promo' => array(
        'custom_settings' => FALSE,
      ),
      'grid_13_promo' => array(
        'custom_settings' => FALSE,
      ),
      'grid_14_promo' => array(
        'custom_settings' => FALSE,
      ),
      'grid_9_promo' => array(
        'custom_settings' => FALSE,
      ),
      'image_first' => array(
        'custom_settings' => FALSE,
      ),
      'partners_carousel_front_' => array(
        'custom_settings' => FALSE,
      ),
      'partners_carousel_support_page_' => array(
        'custom_settings' => FALSE,
      ),
      'promo_slider' => array(
        'custom_settings' => FALSE,
      ),
      'grid_2' => array(
        'custom_settings' => FALSE,
      ),
      'grid_3' => array(
        'custom_settings' => FALSE,
      ),
      'grid_10' => array(
        'custom_settings' => FALSE,
      ),
      'grid_15' => array(
        'custom_settings' => FALSE,
      ),
      'grid_mediabar_big' => array(
        'custom_settings' => FALSE,
      ),
      'full_width_promo' => array(
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
          'full' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
          'list_view' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
          'partner_basic' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_fieldable_panels_pane__partner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_partner';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_partner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_partner';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_partner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_partner';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_partner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_partner';
  $strongarm->value = 0;
  $export['node_submitted_partner'] = $strongarm;

  return $export;
}
