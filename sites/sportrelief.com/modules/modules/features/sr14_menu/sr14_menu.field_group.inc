<?php
/**
 * @file
 * sr14_menu.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function sr14_menu_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cta|node|news_article|form';
  $field_group->group_name = 'group_cta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'CTA',
    'weight' => '7',
    'children' => array(
      0 => 'field_cta',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_cta|node|news_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mw_caption_news_p3|node|news_article|media_wall_promo_3';
  $field_group->group_name = 'group_mw_caption_news_p3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news_article';
  $field_group->mode = 'media_wall_promo_3';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Caption',
    'weight' => '1',
    'children' => array(
      0 => 'title_field',
      1 => 'taxonomy_term_id_field',
      2 => 'node_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Caption',
      'instance_settings' => array(
        'classes' => 'media-wall__caption',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_mw_caption_news_p3|node|news_article|media_wall_promo_3'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mw_caption_touch|node|news_article|media_wall_touch_device';
  $field_group->group_name = 'group_mw_caption_touch';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news_article';
  $field_group->mode = 'media_wall_touch_device';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Caption',
    'weight' => '2',
    'children' => array(
      0 => 'title_field',
      1 => 'taxonomy_term_id_field',
      2 => 'node_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Caption',
      'instance_settings' => array(
        'classes' => 'media-wall__caption',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_mw_caption_touch|node|news_article|media_wall_touch_device'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row_wrapper_classes|node|panel|form';
  $field_group->group_name = 'group_row_wrapper_classes';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'panel';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Row Wrapper Classes',
    'weight' => '5',
    'children' => array(
      0 => 'field_row_wrapper_class',
      1 => 'field_row_2_wrapper_class',
      2 => 'field_row_3_wrapper_class',
      3 => 'field_row_4_wrapper_class',
      4 => 'field_row_5_wrapper_class',
      5 => 'field_row_6_wrapper_class',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Row Wrapper Classes',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_row_wrapper_classes|node|panel|form'] = $field_group;

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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_top_group|node|news_article|full';
  $field_group->group_name = 'group_top_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news_article';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Top',
    'weight' => '0',
    'children' => array(
      0 => 'title_field',
      1 => 'body',
      2 => 'field_cta',
      3 => 'field_publish_date',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'classes' => 'pod--article__top-wrapper pod__body ',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_top_group|node|news_article|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_top_group|node|news_article|full_content_no_social';
  $field_group->group_name = 'group_top_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news_article';
  $field_group->mode = 'full_content_no_social';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Top',
    'weight' => '0',
    'children' => array(
      0 => 'title_field',
      1 => 'body',
      2 => 'field_cta',
      3 => 'field_publish_date',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Top',
      'instance_settings' => array(
        'classes' => 'pod--article__top-wrapper pod__body ',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_top_group|node|news_article|full_content_no_social'] = $field_group;

  return $export;
}
