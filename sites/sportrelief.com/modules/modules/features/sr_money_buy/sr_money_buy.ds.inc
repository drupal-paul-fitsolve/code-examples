<?php
/**
 * @file
 * sr_money_buy.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function sr_money_buy_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'fieldable_panels_pane|money_buy_fundraiser|default';
  $ds_fieldsetting->entity_type = 'fieldable_panels_pane';
  $ds_fieldsetting->bundle = 'money_buy_fundraiser';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
        ),
      ),
    ),
    'field_body_left' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
        ),
      ),
    ),
    'field_body_right' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
        ),
      ),
    ),
    'field_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
        ),
      ),
    ),
  );
  $export['fieldable_panels_pane|money_buy_fundraiser|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'fieldable_panels_pane|money_buy|default';
  $ds_fieldsetting->entity_type = 'fieldable_panels_pane';
  $ds_fieldsetting->bundle = 'money_buy';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
        ),
      ),
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
        ),
      ),
    ),
    'field_fact' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
        ),
      ),
    ),
  );
  $export['fieldable_panels_pane|money_buy|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function sr_money_buy_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'fieldable_panels_pane|money_buy_fundraiser|default';
  $ds_layout->entity_type = 'fieldable_panels_pane';
  $ds_layout->bundle = 'money_buy_fundraiser';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_3col_equal_width';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_body_left',
      ),
      'middle' => array(
        1 => 'field_image',
        2 => 'field_link',
      ),
      'right' => array(
        3 => 'field_body_right',
      ),
    ),
    'fields' => array(
      'field_body_left' => 'left',
      'field_image' => 'middle',
      'field_link' => 'middle',
      'field_body_right' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'middle' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['fieldable_panels_pane|money_buy_fundraiser|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'fieldable_panels_pane|money_buy|default';
  $ds_layout->entity_type = 'fieldable_panels_pane';
  $ds_layout->bundle = 'money_buy';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_body',
        1 => 'field_image',
        2 => 'field_fact',
        3 => 'group_wrapper',
      ),
    ),
    'fields' => array(
      'field_body' => 'ds_content',
      'field_image' => 'ds_content',
      'field_fact' => 'ds_content',
      'group_wrapper' => 'ds_content',
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
    'layout_attributes_merge' => 1,
  );
  $export['fieldable_panels_pane|money_buy|default'] = $ds_layout;

  return $export;
}
