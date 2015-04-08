<?php
/**
 * @file
 * sr_news_gallery.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function sr_news_gallery_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tile_caption|node|media_images|tile_grid_6';
  $field_group->group_name = 'group_tile_caption';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'media_images';
  $field_group->mode = 'tile_grid_6';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Caption',
    'weight' => '1',
    'children' => array(
      0 => 'title_field',
      1 => 'field_publish_date',
      2 => 'node_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Caption',
      'instance_settings' => array(
        'classes' => 'tile-caption',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_tile_caption|node|media_images|tile_grid_6'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tile_caption|node|news_article|tile_grid_6';
  $field_group->group_name = 'group_tile_caption';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news_article';
  $field_group->mode = 'tile_grid_6';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Caption',
    'weight' => '2',
    'children' => array(
      0 => 'title_field',
      1 => 'field_publish_date',
      2 => 'node_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Caption',
      'instance_settings' => array(
        'classes' => 'tile-caption',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_tile_caption|node|news_article|tile_grid_6'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tile_caption|node|video|tile_grid_6';
  $field_group->group_name = 'group_tile_caption';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video';
  $field_group->mode = 'tile_grid_6';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Caption',
    'weight' => '2',
    'children' => array(
      0 => 'title_field',
      1 => 'field_publish_date',
      2 => 'node_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Caption',
      'instance_settings' => array(
        'classes' => 'tile-caption',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_tile_caption|node|video|tile_grid_6'] = $field_group;

  return $export;
}
