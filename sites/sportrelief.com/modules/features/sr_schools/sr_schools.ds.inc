<?php
/**
 * @file
 * sr_schools.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function sr_schools_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'fieldable_panels_pane|schools_need_media|default';
  $ds_fieldsetting->entity_type = 'fieldable_panels_pane';
  $ds_fieldsetting->bundle = 'schools_need_media';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_quote' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'blockquote',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_schools_media_body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'pod__body',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_slide_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h2',
          'fi-cl' => 'pod__title',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['fieldable_panels_pane|schools_need_media|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function sr_schools_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'fieldable_panels_pane|schools_need_media|default';
  $ds_layout->entity_type = 'fieldable_panels_pane';
  $ds_layout->bundle = 'schools_need_media';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_pod_text',
        1 => 'group_pod_media',
        2 => 'field_need_image',
        3 => 'field_quote',
        4 => 'field_slide_title',
        5 => 'field_schools_media_body',
      ),
    ),
    'fields' => array(
      'group_pod_text' => 'ds_content',
      'group_pod_media' => 'ds_content',
      'field_need_image' => 'ds_content',
      'field_quote' => 'ds_content',
      'field_slide_title' => 'ds_content',
      'field_schools_media_body' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
  );
  $export['fieldable_panels_pane|schools_need_media|default'] = $ds_layout;

  return $export;
}
