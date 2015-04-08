<?php
/**
 * @file
 * sr_news_gallery.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function sr_news_gallery_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|media_images|tile_grid_6';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'media_images';
  $ds_fieldsetting->view_mode = 'tile_grid_6';
  $ds_fieldsetting->settings = array(
    'colorbox_node_link' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'node_link' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'View photo',
        'wrapper' => '',
        'class' => 'cta',
        'ft' => array(),
      ),
    ),
  );
  $export['node|media_images|tile_grid_6'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|news_article|tile_grid_6';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'news_article';
  $ds_fieldsetting->view_mode = 'tile_grid_6';
  $ds_fieldsetting->settings = array(
    'node_link_field' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'node_link' => array(
      'weight' => '16',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'Read more',
        'wrapper' => '',
        'class' => 'cta',
        'ft' => array(),
      ),
    ),
  );
  $export['node|news_article|tile_grid_6'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|video|tile_grid_6';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'video';
  $ds_fieldsetting->view_mode = 'tile_grid_6';
  $ds_fieldsetting->settings = array(
    'colorbox_node_link' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'node_link' => array(
      'weight' => '17',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'Watch now',
        'wrapper' => '',
        'class' => 'cta',
        'ft' => array(),
      ),
    ),
    'field_video_url' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_publish_date' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|video|tile_grid_6'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function sr_news_gallery_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|media_images|tile_grid_6';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'media_images';
  $ds_layout->view_mode = 'tile_grid_6';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'colorbox_node_link',
        1 => 'field_image',
        2 => 'group_tile_caption',
        3 => 'field_publish_date',
        4 => 'title_field',
        5 => 'node_link',
      ),
    ),
    'fields' => array(
      'colorbox_node_link' => 'ds_content',
      'field_image' => 'ds_content',
      'group_tile_caption' => 'ds_content',
      'field_publish_date' => 'ds_content',
      'title_field' => 'ds_content',
      'node_link' => 'ds_content',
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
  $export['node|media_images|tile_grid_6'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|news_article|tile_grid_6';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'news_article';
  $ds_layout->view_mode = 'tile_grid_6';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'node_link_field',
        2 => 'group_tile_caption',
        3 => 'field_publish_date',
        4 => 'title_field',
        5 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'node_link_field' => 'ds_content',
      'group_tile_caption' => 'ds_content',
      'field_publish_date' => 'ds_content',
      'title_field' => 'ds_content',
      'node_link' => 'ds_content',
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
  $export['node|news_article|tile_grid_6'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|video|tile_grid_6';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'tile_grid_6';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_video_url',
        1 => 'colorbox_node_link',
        2 => 'group_tile_caption',
        3 => 'field_publish_date',
        4 => 'title_field',
        5 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_video_url' => 'ds_content',
      'colorbox_node_link' => 'ds_content',
      'group_tile_caption' => 'ds_content',
      'field_publish_date' => 'ds_content',
      'title_field' => 'ds_content',
      'node_link' => 'ds_content',
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
  $export['node|video|tile_grid_6'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function sr_news_gallery_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'tile_grid_6';
  $ds_view_mode->label = 'Tile: grid 6';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['tile_grid_6'] = $ds_view_mode;

  return $export;
}
