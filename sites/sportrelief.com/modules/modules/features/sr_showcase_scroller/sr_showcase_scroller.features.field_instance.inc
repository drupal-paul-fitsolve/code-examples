<?php
/**
 * @file
 * sr_showcase_scroller.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function sr_showcase_scroller_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-fundraiser_showcase-field_fundrasier_showcase_option'
  $field_instances['node-fundraiser_showcase-field_fundrasier_showcase_option'] = array(
    'bundle' => 'fundraiser_showcase',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_fundrasier_showcase_option',
    'label' => 'What are you uploading?',
    'required' => 1,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_buttons',
      'weight' => 18,
    ),
  );

  // Exported field_instance: 'node-fundraiser_showcase-field_fundrasier_showcase_school'
  $field_instances['node-fundraiser_showcase-field_fundrasier_showcase_school'] = array(
    'bundle' => 'fundraiser_showcase',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_fundrasier_showcase_school',
    'label' => 'tick if you are a teacher',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_onoff',
      'weight' => 20,
    ),
  );

  // Exported field_instance: 'node-fundraiser_showcase-field_last_name'
  $field_instances['node-fundraiser_showcase-field_last_name'] = array(
    'bundle' => 'fundraiser_showcase',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_last_name',
    'label' => 'Last name',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-fundraiser_showcase-field_organisation'
  $field_instances['node-fundraiser_showcase-field_organisation'] = array(
    'bundle' => 'fundraiser_showcase',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_organisation',
    'label' => 'Organisation / establishment',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'node-fundraiser_showcase-field_video_upload'
  $field_instances['node-fundraiser_showcase-field_video_upload'] = array(
    'bundle' => 'fundraiser_showcase',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'youtube_uploader',
        'settings' => array(
          'youtube_video_height' => NULL,
          'youtube_video_size' => '420x315',
          'youtube_video_width' => NULL,
        ),
        'type' => 'youtube_uploader_video',
        'weight' => 3,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'youtube_uploader',
        'settings' => array(
          'youtube_video_height' => NULL,
          'youtube_video_size' => '420x315',
          'youtube_video_width' => NULL,
        ),
        'type' => 'youtube_uploader_video',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'youtube_uploader',
        'settings' => array(
          'youtube_video_height' => NULL,
          'youtube_video_size' => '420x315',
          'youtube_video_width' => NULL,
        ),
        'type' => 'youtube_uploader_video',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_video_upload',
    'label' => 'Video upload',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'file_directory' => '',
      'user_register_form' => FALSE,
      'youtube_settings' => array(
        'youtube_uploader_category' => 'Sports',
        'youtube_uploader_delete' => 1,
        'youtube_uploader_description' => 'default description',
        'youtube_uploader_publishing_options' => 'Unlisted',
        'youtube_uploader_tags' => 'funny, fun, sport relief 2014',
      ),
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'youtube_uploader',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'youtube_uploader_widget',
      'weight' => 21,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Last name');
  t('Organisation / establishment');
  t('Video upload');
  t('What are you uploading?');
  t('tick if you are a teacher');

  return $field_instances;
}
