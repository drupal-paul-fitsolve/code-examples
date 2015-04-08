<?php
/**
 * @file
 * sr_media_wall_video.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function sr_media_wall_video_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|video|media_wall';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'video';
  $ds_fieldsetting->view_mode = 'media_wall';
  $ds_fieldsetting->settings = array(
    'colorbox_node_link' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'taxonomy_term_id_field' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|video|media_wall'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|video|media_wall_promo_2';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'video';
  $ds_fieldsetting->view_mode = 'media_wall_promo_2';
  $ds_fieldsetting->settings = array(
    'colorbox_node_link' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'taxonomy_term_id_field' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|video|media_wall_promo_2'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|video|media_wall_promo_3';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'video';
  $ds_fieldsetting->view_mode = 'media_wall_promo_3';
  $ds_fieldsetting->settings = array(
    'colorbox_node_link' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'taxonomy_term_id_field' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|video|media_wall_promo_3'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|video|media_wall_touch_device';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'video';
  $ds_fieldsetting->view_mode = 'media_wall_touch_device';
  $ds_fieldsetting->settings = array(
    'colorbox_node_link' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'taxonomy_term_id_field' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_video_url' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|video|media_wall_touch_device'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function sr_media_wall_video_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|video|media_wall';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'media_wall';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_video_url',
        1 => 'colorbox_node_link',
        2 => 'group_mw_caption_video',
        3 => 'taxonomy_term_id_field',
        4 => 'title_field',
      ),
    ),
    'fields' => array(
      'field_video_url' => 'ds_content',
      'colorbox_node_link' => 'ds_content',
      'group_mw_caption_video' => 'ds_content',
      'taxonomy_term_id_field' => 'ds_content',
      'title_field' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|video|media_wall'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|video|media_wall_promo_2';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'media_wall_promo_2';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_video_url',
        1 => 'colorbox_node_link',
        2 => 'group_mw_caption_video_p2',
        3 => 'taxonomy_term_id_field',
        4 => 'title_field',
      ),
    ),
    'fields' => array(
      'field_video_url' => 'ds_content',
      'colorbox_node_link' => 'ds_content',
      'group_mw_caption_video_p2' => 'ds_content',
      'taxonomy_term_id_field' => 'ds_content',
      'title_field' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|video|media_wall_promo_2'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|video|media_wall_promo_3';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'media_wall_promo_3';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_video_url',
        1 => 'colorbox_node_link',
        2 => 'group_mw_caption_video_p3',
        3 => 'taxonomy_term_id_field',
        4 => 'title_field',
      ),
    ),
    'fields' => array(
      'field_video_url' => 'ds_content',
      'colorbox_node_link' => 'ds_content',
      'group_mw_caption_video_p3' => 'ds_content',
      'taxonomy_term_id_field' => 'ds_content',
      'title_field' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|video|media_wall_promo_3'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|video|media_wall_touch_device';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'media_wall_touch_device';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_video_url',
        1 => 'colorbox_node_link',
        2 => 'taxonomy_term_id_field',
        3 => 'group_mw_caption_touch',
        4 => 'title_field',
      ),
    ),
    'fields' => array(
      'field_video_url' => 'ds_content',
      'colorbox_node_link' => 'ds_content',
      'taxonomy_term_id_field' => 'ds_content',
      'group_mw_caption_touch' => 'ds_content',
      'title_field' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|video|media_wall_touch_device'] = $ds_layout;

  return $export;
}
