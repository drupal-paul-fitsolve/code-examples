<?php
/**
 * @file
 * partners.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function partners_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'fieldable_panels_pane|partner|full';
  $ds_fieldsetting->entity_type = 'fieldable_panels_pane';
  $ds_fieldsetting->bundle = 'partner';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'field_body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'partner__description',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_external_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
        ),
      ),
    ),
    'field_partner_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h2',
          'fi-cl' => 'partner__name',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['fieldable_panels_pane|partner|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'fieldable_panels_pane|partner|list_view';
  $ds_fieldsetting->entity_type = 'fieldable_panels_pane';
  $ds_fieldsetting->bundle = 'partner';
  $ds_fieldsetting->view_mode = 'list_view';
  $ds_fieldsetting->settings = array(
    'link_to_full_view_mode' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:4:{s:8:"sanitize";i:1;s:7:"context";s:42:"argument_entity_id:fieldable_panels_pane_1";s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";}s:4:"type";s:5:"token";s:7:"subtype";s:26:"fieldable_panels_pane:uuid";}',
        'load_terms' => 0,
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'js-partner-uuid',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_partner_logo' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
  );
  $export['fieldable_panels_pane|partner|list_view'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function partners_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'link_to_full_view_mode';
  $ds_field->label = 'UUID';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'fieldable_panels_pane' => 'fieldable_panels_pane',
  );
  $ds_field->ui_limit = '*|list_view';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['link_to_full_view_mode'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function partners_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'fieldable_panels_pane|partner|default';
  $ds_layout->entity_type = 'fieldable_panels_pane';
  $ds_layout->bundle = 'partner';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_external_link',
        1 => 'field_image',
        2 => 'field_body',
        3 => 'field_partner_logo',
        4 => 'field_partner_name',
      ),
    ),
    'fields' => array(
      'field_external_link' => 'ds_content',
      'field_image' => 'ds_content',
      'field_body' => 'ds_content',
      'field_partner_logo' => 'ds_content',
      'field_partner_name' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
  );
  $export['fieldable_panels_pane|partner|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'fieldable_panels_pane|partner|full';
  $ds_layout->entity_type = 'fieldable_panels_pane';
  $ds_layout->bundle = 'partner';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_column_1',
        1 => 'field_image',
        2 => 'group_column_2',
        3 => 'field_partner_name',
        4 => 'field_external_link',
        5 => 'field_body',
      ),
    ),
    'fields' => array(
      'group_column_1' => 'ds_content',
      'field_image' => 'ds_content',
      'group_column_2' => 'ds_content',
      'field_partner_name' => 'ds_content',
      'field_external_link' => 'ds_content',
      'field_body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['fieldable_panels_pane|partner|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'fieldable_panels_pane|partner|list_view';
  $ds_layout->entity_type = 'fieldable_panels_pane';
  $ds_layout->bundle = 'partner';
  $ds_layout->view_mode = 'list_view';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_partner_wrapper',
        1 => 'link_to_full_view_mode',
        2 => 'field_partner_logo',
      ),
    ),
    'fields' => array(
      'group_partner_wrapper' => 'ds_content',
      'link_to_full_view_mode' => 'ds_content',
      'field_partner_logo' => 'ds_content',
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
  $export['fieldable_panels_pane|partner|list_view'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function partners_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'list_view';
  $ds_view_mode->label = 'List View';
  $ds_view_mode->entities = array(
    'fieldable_panels_pane' => 'fieldable_panels_pane',
  );
  $export['list_view'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'partner_basic';
  $ds_view_mode->label = 'Partner Basic';
  $ds_view_mode->entities = array(
    'fieldable_panels_pane' => 'fieldable_panels_pane',
  );
  $export['partner_basic'] = $ds_view_mode;

  return $export;
}
