<?php
/**
 * @file
 * cr_news.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cr_news_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_article_bottom|node|news_article|full';
  $field_group->group_name = 'group_article_bottom';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news_article';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bottom',
    'weight' => '7',
    'children' => array(
      0 => 'social_share_links',
      1 => 'facebook_comments',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Bottom',
      'instance_settings' => array(
        'classes' => 'pod--article__bottom-wrapper',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_article_bottom|node|news_article|full'] = $field_group;

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
    'weight' => '5',
    'children' => array(
      0 => 'field_news_cta',
      1 => 'field_cta',
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
