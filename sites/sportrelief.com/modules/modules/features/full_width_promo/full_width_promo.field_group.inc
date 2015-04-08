<?php
/**
 * @file
 * full_width_promo.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function full_width_promo_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pod_text|fieldable_panels_pane|text_media|full_width_promo';
  $field_group->group_name = 'group_pod_text';
  $field_group->entity_type = 'fieldable_panels_pane';
  $field_group->bundle = 'text_media';
  $field_group->mode = 'full_width_promo';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Text wrapper',
    'weight' => '2',
    'children' => array(
      0 => 'field_custom_body',
      1 => 'title_field',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Text wrapper',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_pod_text|fieldable_panels_pane|text_media|full_width_promo'] = $field_group;

  return $export;
}
