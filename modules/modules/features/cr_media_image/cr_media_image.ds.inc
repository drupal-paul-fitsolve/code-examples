<?php
/**
 * @file
 * cr_media_image.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function cr_media_image_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|media_images|colorbox';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'media_images';
  $ds_fieldsetting->view_mode = 'colorbox';
  $ds_fieldsetting->settings = array(
    'social_share_links' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'pod--article__sharelinks sharelinks--colorbox',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h4',
        'class' => '',
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_cta' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|media_images|colorbox_no_social'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|media_images|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'media_images';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'social_share_links' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'pod--article__sharelinks',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|media_images|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|media_images|full_content_no_social';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'media_images';
  $ds_fieldsetting->view_mode = 'full_content_no_social';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'span',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|media_images|full_content_no_social'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|media_images|media_bar';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'media_images';
  $ds_fieldsetting->view_mode = 'media_bar';
  $ds_fieldsetting->settings = array(
    'colorbox_node_link' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'media_bar_image_icon' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|media_images|media_bar'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function cr_media_image_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'media_bar_image_icon';
  $ds_field->label = 'Media Bar Image Icon';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '*|media_bar';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<span class="media-bar__image-icon"></span>',
      'format' => 'full_html',
    ),
    'use_token' => 0,
  );
  $export['media_bar_image_icon'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function cr_media_image_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|media_images|colorbox';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'media_images';
  $ds_layout->view_mode = 'colorbox';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'body',
        3 => 'field_cta',
        4 => 'social_share_links',
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'title' => 'right',
      'body' => 'right',
      'field_cta' => 'right',
      'social_share_links' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|media_images|colorbox'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|media_images|colorbox_no_social';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'media_images';
  $ds_layout->view_mode = 'colorbox_no_social';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_image',
      ),
      'right' => array(
        1 => 'title_field',
        2 => 'body',
        3 => 'field_cta',
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'title_field' => 'right',
      'body' => 'right',
      'field_cta' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        'container-24' => 'container-24',
        'colorbox-container' => 'colorbox-container',
      ),
      'left' => array(
        'colorbox--top' => 'colorbox--top',
        'alpha' => 'alpha',
        'omega' => 'omega',
        'grid-16' => 'grid-16',
      ),
      'right' => array(
        'colorbox--bottom' => 'colorbox--bottom',
        'alpha' => 'alpha',
        'omega' => 'omega',
        'grid-16' => 'grid-16',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|media_images|colorbox_no_social'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|media_images|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'media_images';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_image',
        1 => 'title_field',
        2 => 'body',
        3 => 'field_cta',
      ),
      'right' => array(
        4 => 'social_share_links',
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'title_field' => 'left',
      'body' => 'left',
      'field_cta' => 'left',
      'social_share_links' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|media_images|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|media_images|full_content_no_social';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'media_images';
  $ds_layout->view_mode = 'full_content_no_social';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_image',
        1 => 'title',
        2 => 'body',
        3 => 'field_cta',
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'title' => 'left',
      'body' => 'left',
      'field_cta' => 'left',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|media_images|full_content_no_social'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|media_images|media_bar';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'media_images';
  $ds_layout->view_mode = 'media_bar';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'colorbox_node_link',
        1 => 'media_bar_image_icon',
        2 => 'field_image',
      ),
    ),
    'fields' => array(
      'colorbox_node_link' => 'ds_content',
      'media_bar_image_icon' => 'ds_content',
      'field_image' => 'ds_content',
    ),
    'limit' => array(
      'field_image' => '1',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|media_images|media_bar'] = $ds_layout;

  return $export;
}
