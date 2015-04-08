<?php
/**
 * @file
 * sr_media_wall.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function sr_media_wall_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'bean|media_wall|default';
  $ds_fieldsetting->entity_type = 'bean';
  $ds_fieldsetting->bundle = 'media_wall';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'media_wall_instagram_feed' => array(
      'weight' => '15',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'grid-4 narrow-grid-4 narrow-omega media-wall_instagram',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'meda_bar_queue' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
    'media_bar_homepage' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_custom_body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'grid-4 narrow-grid-14 narrow-alpha media-wall__fundraising-kit',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['bean|media_wall|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'bean|media_wall|media_wall';
  $ds_fieldsetting->entity_type = 'bean';
  $ds_fieldsetting->bundle = 'media_wall';
  $ds_fieldsetting->view_mode = 'media_wall';
  $ds_fieldsetting->settings = array(
    'media_bar_mixersinmotion_block' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'media_wall_dynamic_mbq' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:15:{s:23:"override_pager_settings";i:0;s:9:"use_pager";i:0;s:14:"nodes_per_page";s:1:"1";s:8:"pager_id";s:1:"0";s:6:"offset";s:1:"0";s:9:"more_link";i:0;s:10:"feed_icons";i:0;s:10:"panel_args";i:0;s:12:"link_to_view";i:0;s:4:"args";s:10:"little-mix";s:3:"url";s:0:"";s:7:"display";s:7:"block_2";s:7:"context";a:1:{i:0;s:0:"";}s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";}s:4:"type";s:5:"views";s:7:"subtype";s:10:"media_wall";}',
        'load_terms' => 0,
        'ft' => array(),
      ),
    ),
    'media_wall_mixersinmotion_ig' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'grid-4 narrow-grid-4 narrow-omega media-wall_instagram',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_custom_body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'grid-4 narrow-grid-14 narrow-alpha media-wall__fundraising-kit',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['bean|media_wall|media_wall'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function sr_media_wall_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'meda_bar_queue';
  $ds_field->label = 'Media Wall: MBQ';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'bean' => 'bean',
  );
  $ds_field->ui_limit = 'media_wall|*';
  $ds_field->properties = array(
    'block' => 'views|media_wall-block_2',
    'block_render' => '3',
  );
  $export['meda_bar_queue'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'media_bar_homepage';
  $ds_field->label = 'Media Bar Twitter: Homepage';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'bean' => 'bean',
  );
  $ds_field->ui_limit = 'media_wall|*';
  $ds_field->properties = array(
    'block' => 'bean|media-bar-home-twitter',
    'block_render' => '3',
  );
  $export['media_bar_homepage'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'media_wall_dynamic_mbq';
  $ds_field->label = 'Media Wall: Dynamic MBQ';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'bean' => 'bean',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['media_wall_dynamic_mbq'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'taxonomy_term_id_field';
  $ds_field->label = 'Taxonomy term id field';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'media_images|*
video|*
news_article|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<div class = "taxonomy-term media-wall__type term-[node:field_media_wall] term-id-[node:field-media-wall:tid]  ">[node:field-media-wall]</div>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['taxonomy_term_id_field'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function sr_media_wall_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|media_wall|default';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'media_wall';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'group_mw_top',
        1 => 'group_mw_bottom',
        2 => 'field_media_wall_promo',
        3 => 'field_media_wall_promo_2',
        5 => 'group_mw_bottom_downloadables',
        6 => 'field_media_wall_promo_3',
        7 => 'field_media_wall_promo_4',
        8 => 'meda_bar_queue',
        9 => 'media_wall_instagram_feed',
        10 => 'field_custom_body',
      ),
      'right' => array(
        4 => 'media_bar_homepage',
      ),
    ),
    'fields' => array(
      'group_mw_top' => 'left',
      'group_mw_bottom' => 'left',
      'field_media_wall_promo' => 'left',
      'field_media_wall_promo_2' => 'left',
      'media_bar_homepage' => 'right',
      'group_mw_bottom_downloadables' => 'left',
      'field_media_wall_promo_3' => 'left',
      'field_media_wall_promo_4' => 'left',
      'meda_bar_queue' => 'left',
      'media_wall_instagram_feed' => 'left',
      'field_custom_body' => 'left',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'left' => array(
        'alpha' => 'alpha',
        'grid-18' => 'grid-18',
      ),
      'right' => array(
        'alpha' => 'alpha',
        'omega' => 'omega',
        'grid-6' => 'grid-6',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['bean|media_wall|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|media_wall|media_wall';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'media_wall';
  $ds_layout->view_mode = 'media_wall';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'group_mw_top',
        1 => 'group_mw_bottom',
        3 => 'group_mw_bottom_downloadables',
        4 => 'field_media_wall_promo_3',
        5 => 'media_wall_mixersinmotion_ig',
        6 => 'field_custom_body',
        7 => 'field_media_wall_promo_4',
        8 => 'media_wall_dynamic_mbq',
        9 => 'field_media_wall_promo',
        10 => 'field_media_wall_promo_2',
      ),
      'right' => array(
        2 => 'media_bar_mixersinmotion_block',
      ),
    ),
    'fields' => array(
      'group_mw_top' => 'left',
      'group_mw_bottom' => 'left',
      'media_bar_mixersinmotion_block' => 'right',
      'group_mw_bottom_downloadables' => 'left',
      'field_media_wall_promo_3' => 'left',
      'media_wall_mixersinmotion_ig' => 'left',
      'field_custom_body' => 'left',
      'field_media_wall_promo_4' => 'left',
      'media_wall_dynamic_mbq' => 'left',
      'field_media_wall_promo' => 'left',
      'field_media_wall_promo_2' => 'left',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'left' => array(
        'alpha' => 'alpha',
        'grid-18' => 'grid-18',
      ),
      'right' => array(
        'alpha' => 'alpha',
        'grid-6' => 'grid-6',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['bean|media_wall|media_wall'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function sr_media_wall_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'media_wall';
  $ds_view_mode->label = 'Little Mix Media Wall';
  $ds_view_mode->entities = array(
    'node' => 'node',
    'bean' => 'bean',
  );
  $export['media_wall'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'media_wall_promo_2';
  $ds_view_mode->label = 'Media Wall: Promo 2';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['media_wall_promo_2'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'media_wall_promo_3';
  $ds_view_mode->label = 'Media Wall: Promo 3';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['media_wall_promo_3'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'media_wall_touch_device';
  $ds_view_mode->label = 'Media Wall: Touch Device';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['media_wall_touch_device'] = $ds_view_mode;

  return $export;
}
