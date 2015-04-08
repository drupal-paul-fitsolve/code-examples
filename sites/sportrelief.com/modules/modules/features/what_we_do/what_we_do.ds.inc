<?php
/**
 * @file
 * what_we_do.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function what_we_do_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'fieldable_panels_pane|helped_people|full';
  $ds_fieldsetting->entity_type = 'fieldable_panels_pane';
  $ds_fieldsetting->bundle = 'helped_people';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'field_body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
    'field_image_with_quote' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'h3',
          'ow-cl' => 'people-helped-title',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_grant_sections' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'people-helped-section',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['fieldable_panels_pane|helped_people|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'fieldable_panels_pane|helped_people|list_view';
  $ds_fieldsetting->entity_type = 'fieldable_panels_pane';
  $ds_fieldsetting->bundle = 'helped_people';
  $ds_fieldsetting->view_mode = 'list_view';
  $ds_fieldsetting->settings = array(
    'link_to_full_view_mode' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:4:{s:8:"sanitize";i:1;s:7:"context";s:42:"argument_entity_id:fieldable_panels_pane_1";s:14:"override_title";i:1;s:19:"override_title_text";s:6:"<none>";}s:4:"type";s:5:"token";s:7:"subtype";s:26:"fieldable_panels_pane:uuid";}',
        'load_terms' => 0,
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'js-people-helped-uuid',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h3',
          'fi-cl' => 'people-helped__name',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['fieldable_panels_pane|helped_people|list_view'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function what_we_do_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'fieldable_panels_pane|helped_people|full';
  $ds_layout->entity_type = 'fieldable_panels_pane';
  $ds_layout->bundle = 'helped_people';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_image_slider',
        1 => 'title_field',
        2 => 'group_meet_person',
        3 => 'field_image_with_quote',
        4 => 'field_grant_sections',
        5 => 'group_fact_wrapper',
        6 => 'field_image',
        7 => 'field_body',
      ),
    ),
    'fields' => array(
      'group_image_slider' => 'ds_content',
      'title_field' => 'ds_content',
      'group_meet_person' => 'ds_content',
      'field_image_with_quote' => 'ds_content',
      'field_grant_sections' => 'ds_content',
      'group_fact_wrapper' => 'ds_content',
      'field_image' => 'ds_content',
      'field_body' => 'ds_content',
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
  $export['fieldable_panels_pane|helped_people|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'fieldable_panels_pane|helped_people|list_view';
  $ds_layout->entity_type = 'fieldable_panels_pane';
  $ds_layout->bundle = 'helped_people';
  $ds_layout->view_mode = 'list_view';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_main_image',
        1 => 'title_field',
        2 => 'link_to_full_view_mode',
      ),
    ),
    'fields' => array(
      'field_main_image' => 'ds_content',
      'title_field' => 'ds_content',
      'link_to_full_view_mode' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
  );
  $export['fieldable_panels_pane|helped_people|list_view'] = $ds_layout;

  return $export;
}
