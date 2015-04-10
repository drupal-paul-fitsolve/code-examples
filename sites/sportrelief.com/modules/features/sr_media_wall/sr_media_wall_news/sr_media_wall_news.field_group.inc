<?php
/**
 * @file
 * sr_media_wall_news.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function sr_media_wall_news_field_group_info() {
  $export = array();

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

  return $export;
}
