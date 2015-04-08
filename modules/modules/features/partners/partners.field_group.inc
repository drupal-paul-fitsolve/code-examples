<?php
/**
 * @file
 * partners.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function partners_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_column_1|fieldable_panels_pane|partner|full';
  $field_group->group_name = 'group_column_1';
  $field_group->entity_type = 'fieldable_panels_pane';
  $field_group->bundle = 'partner';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Column 1',
    'weight' => '0',
    'children' => array(
      0 => 'field_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Column 1',
      'instance_settings' => array(
        'classes' => 'alpha grid-12 image-rounded__left',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_column_1|fieldable_panels_pane|partner|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_column_2|fieldable_panels_pane|partner|full';
  $field_group->group_name = 'group_column_2';
  $field_group->entity_type = 'fieldable_panels_pane';
  $field_group->bundle = 'partner';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Column 2',
    'weight' => '1',
    'children' => array(
      0 => 'field_body',
      1 => 'field_external_link',
      2 => 'field_partner_name',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Column 2',
      'instance_settings' => array(
        'classes' => 'grid-12 omega',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_column_2|fieldable_panels_pane|partner|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_partner_basic_wrapper|fieldable_panels_pane|partner|partner_basic';
  $field_group->group_name = 'group_partner_basic_wrapper';
  $field_group->entity_type = 'fieldable_panels_pane';
  $field_group->bundle = 'partner';
  $field_group->mode = 'partner_basic';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Partner Basic Wrapper',
    'weight' => '0',
    'children' => array(
      0 => 'field_external_link',
      1 => 'field_partner_logo',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Partner Basic Wrapper',
      'instance_settings' => array(
        'classes' => 'partner-basic--wrapper',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_partner_basic_wrapper|fieldable_panels_pane|partner|partner_basic'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_partner_wrapper|fieldable_panels_pane|partner|list_view';
  $field_group->group_name = 'group_partner_wrapper';
  $field_group->entity_type = 'fieldable_panels_pane';
  $field_group->bundle = 'partner';
  $field_group->mode = 'list_view';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Partner Wrapper',
    'weight' => '0',
    'children' => array(
      0 => 'field_partner_logo',
      1 => 'link_to_full_view_mode',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Partner Wrapper',
      'instance_settings' => array(
        'classes' => 'partner',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_partner_wrapper|fieldable_panels_pane|partner|list_view'] = $field_group;

  return $export;
}
