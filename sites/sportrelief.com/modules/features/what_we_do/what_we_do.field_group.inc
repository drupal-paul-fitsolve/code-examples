<?php
/**
 * @file
 * what_we_do.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function what_we_do_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fact_wrapper|fieldable_panels_pane|helped_people|full';
  $field_group->group_name = 'group_fact_wrapper';
  $field_group->entity_type = 'fieldable_panels_pane';
  $field_group->bundle = 'helped_people';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '2',
    'children' => array(
      0 => 'field_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'classes' => 'people-helped__fact grid-12 omega image-rounded__all',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_fact_wrapper|fieldable_panels_pane|helped_people|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_image_slider|fieldable_panels_pane|helped_people|full';
  $field_group->group_name = 'group_image_slider';
  $field_group->entity_type = 'fieldable_panels_pane';
  $field_group->bundle = 'helped_people';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image slider',
    'weight' => '0',
    'children' => array(
      0 => 'field_image_with_quote',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image slider',
      'instance_settings' => array(
        'classes' => 'grid-12 alpha flexslider--cycle flexslider--people-helped image-rounded__all',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_image_slider|fieldable_panels_pane|helped_people|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meet_person|fieldable_panels_pane|helped_people|full';
  $field_group->group_name = 'group_meet_person';
  $field_group->entity_type = 'fieldable_panels_pane';
  $field_group->bundle = 'helped_people';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meet person',
    'weight' => '1',
    'children' => array(
      0 => 'field_body',
      1 => 'title_field',
      2 => 'field_grant_sections',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Meet person',
      'instance_settings' => array(
        'classes' => 'pod pod--padding people-helped__story grid-12 omega',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_meet_person|fieldable_panels_pane|helped_people|full'] = $field_group;

  return $export;
}
