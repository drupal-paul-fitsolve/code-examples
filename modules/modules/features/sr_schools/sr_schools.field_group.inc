<?php
/**
 * @file
 * sr_schools.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function sr_schools_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pod_media|fieldable_panels_pane|schools_need_media|default';
  $field_group->group_name = 'group_pod_media';
  $field_group->entity_type = 'fieldable_panels_pane';
  $field_group->bundle = 'schools_need_media';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '1',
    'children' => array(
      0 => 'field_quote',
      1 => 'field_need_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'classes' => 'grid-13 narrow-grid-24 omega',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_pod_media|fieldable_panels_pane|schools_need_media|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pod_text|fieldable_panels_pane|schools_need_media|default';
  $field_group->group_name = 'group_pod_text';
  $field_group->entity_type = 'fieldable_panels_pane';
  $field_group->bundle = 'schools_need_media';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '0',
    'children' => array(
      0 => 'field_schools_media_body',
      1 => 'field_slide_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'classes' => 'grid-5 narrow-grid-24 alpha text-align-center-narrow-mobile',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_pod_text|fieldable_panels_pane|schools_need_media|default'] = $field_group;

  return $export;
}
