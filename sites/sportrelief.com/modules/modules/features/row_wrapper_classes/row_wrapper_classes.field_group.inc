<?php
/**
 * @file
 * row_wrapper_classes.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function row_wrapper_classes_field_group_info() {
  $export = array();

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

  return $export;
}
