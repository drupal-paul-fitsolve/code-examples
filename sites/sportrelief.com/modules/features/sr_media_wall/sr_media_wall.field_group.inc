<?php
/**
 * @file
 * sr_media_wall.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function sr_media_wall_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mw_bottom_downloadables|bean|media_wall|default';
  $field_group->group_name = 'group_mw_bottom_downloadables';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'media_wall';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_mw_bottom';
  $field_group->data = array(
    'label' => 'Downloadables',
    'weight' => '8',
    'children' => array(
      0 => 'field_custom_body',
      1 => 'media_wall_instagram_feed',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Downloadables',
      'instance_settings' => array(
        'classes' => 'media-wall__downloadables clearfix',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_mw_bottom_downloadables|bean|media_wall|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mw_bottom_downloadables|bean|media_wall|media_wall';
  $field_group->group_name = 'group_mw_bottom_downloadables';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'media_wall';
  $field_group->mode = 'media_wall';
  $field_group->parent_name = 'group_mw_bottom';
  $field_group->data = array(
    'label' => 'Downloadables',
    'weight' => '3',
    'children' => array(
      0 => 'field_custom_body',
      1 => 'media_wall_mixersinmotion_ig',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Downloadables',
      'instance_settings' => array(
        'classes' => 'media-wall__downloadables clearfix',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_mw_bottom_downloadables|bean|media_wall|media_wall'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mw_bottom|bean|media_wall|default';
  $field_group->group_name = 'group_mw_bottom';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'media_wall';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bottom',
    'weight' => '1',
    'children' => array(
      0 => 'field_media_wall_promo_3',
      1 => 'field_media_wall_promo_4',
      2 => 'meda_bar_queue',
      3 => 'group_mw_bottom_downloadables',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Bottom',
      'instance_settings' => array(
        'classes' => 'clearfix media-wall-group media-wall-group__bottom',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_mw_bottom|bean|media_wall|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mw_bottom|bean|media_wall|media_wall';
  $field_group->group_name = 'group_mw_bottom';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'media_wall';
  $field_group->mode = 'media_wall';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bottom',
    'weight' => '1',
    'children' => array(
      0 => 'field_media_wall_promo_3',
      1 => 'field_media_wall_promo_4',
      2 => 'media_wall_dynamic_mbq',
      3 => 'meda_bar_queue',
      4 => 'group_mw_bottom_downloadables',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Bottom',
      'instance_settings' => array(
        'classes' => 'clearfix media-wall-group media-wall-group__bottom',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_mw_bottom|bean|media_wall|media_wall'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mw_top|bean|media_wall|default';
  $field_group->group_name = 'group_mw_top';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'media_wall';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Top',
    'weight' => '0',
    'children' => array(
      0 => 'field_media_wall_promo',
      1 => 'field_media_wall_promo_2',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Top',
      'instance_settings' => array(
        'classes' => 'clearfix media-wall-group media-wall-group__top',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_mw_top|bean|media_wall|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mw_top|bean|media_wall|media_wall';
  $field_group->group_name = 'group_mw_top';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'media_wall';
  $field_group->mode = 'media_wall';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Top',
    'weight' => '0',
    'children' => array(
      0 => 'field_media_wall_promo',
      1 => 'field_media_wall_promo_2',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Top',
      'instance_settings' => array(
        'classes' => 'clearfix media-wall-group media-wall-group__top',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_mw_top|bean|media_wall|media_wall'] = $field_group;

  return $export;
}
