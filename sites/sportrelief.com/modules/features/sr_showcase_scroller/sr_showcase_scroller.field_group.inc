<?php
/**
 * @file
 * sr_showcase_scroller.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function sr_showcase_scroller_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about|node|fundraiser_showcase|form';
  $field_group->group_name = 'group_about';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'fundraiser_showcase';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_step3';
  $field_group->data = array(
    'label' => 'Tell us about yourself',
    'weight' => '13',
    'children' => array(
      0 => 'title_field',
      1 => 'field_town',
      2 => 'field_how_did_you_fundraise',
      3 => 'field_email',
      4 => 'field_last_name',
      5 => 'field_organisation',
      6 => 'group_school',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Tell us about yourself',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_about|node|fundraiser_showcase|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_options|node|fundraiser_showcase|form';
  $field_group->group_name = 'group_options';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'fundraiser_showcase';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_step1';
  $field_group->data = array(
    'label' => 'What are you uploading?',
    'weight' => '13',
    'children' => array(
      0 => 'field_fundrasier_showcase_option',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'What are you uploading?',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_options|node|fundraiser_showcase|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photo_upload|node|fundraiser_showcase|form';
  $field_group->group_name = 'group_photo_upload';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'fundraiser_showcase';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_step2';
  $field_group->data = array(
    'label' => 'Photo Upload',
    'weight' => '13',
    'children' => array(
      0 => 'field_fundrasier_showcase_images',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Photo Upload',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => 'For full terms and conditions, <a href="/legal#rules-for-using-the-giving-pages-and-fundraiser-showcase?terms-of-use" target="_blank">click here</a><br /><br />
<span class="fr-showcase-upload-desc">3 Photos max.</span> <span class="fr-showcase-upload-desc">JPEG/PNG/GIF</span> <span class="fr-showcase-upload-desc">5MB max.</span>',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_photo_upload|node|fundraiser_showcase|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_school|node|fundraiser_showcase|form';
  $field_group->group_name = 'group_school';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'fundraiser_showcase';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_about';
  $field_group->data = array(
    'label' => ' ',
    'weight' => '20',
    'children' => array(
      0 => 'field_fundrasier_showcase_school',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => ' ',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => 'I\'m fundraising with a school, nursery, or youth group.',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_school|node|fundraiser_showcase|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_step1|node|fundraiser_showcase|form';
  $field_group->group_name = 'group_step1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'fundraiser_showcase';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'What are you uploading?',
    'weight' => '0',
    'children' => array(
      0 => 'group_options',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'What are you uploading?',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'fr-step',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_step1|node|fundraiser_showcase|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_step2|node|fundraiser_showcase|form';
  $field_group->group_name = 'group_step2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'fundraiser_showcase';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Upload your photos & video',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'field_terms',
      2 => 'group_photo_upload',
      3 => 'group_video_upload',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Upload your photos & video',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'fr-step',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_step2|node|fundraiser_showcase|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_step3|node|fundraiser_showcase|form';
  $field_group->group_name = 'group_step3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'fundraiser_showcase';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tell us about yourself',
    'weight' => '2',
    'children' => array(
      0 => 'group_about',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Tell us about yourself',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'fr-step',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_step3|node|fundraiser_showcase|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_upload|node|fundraiser_showcase|form';
  $field_group->group_name = 'group_video_upload';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'fundraiser_showcase';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_step2';
  $field_group->data = array(
    'label' => 'Video Upload',
    'weight' => '14',
    'children' => array(
      0 => 'field_video_upload',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Video Upload',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => 'Any video uploaded, once approved will also be displayed on Youtube. For full terms and conditions, <a href="/legal#rules-for-using-the-giving-pages-and-fundraiser-showcase?terms-of-use" target="_blank">click here</a><br /><br />
<span class="fr-showcase-upload-desc">1 Video max.</span>  <span class="fr-showcase-upload-desc">200MB max.</span>',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_video_upload|node|fundraiser_showcase|form'] = $field_group;

  return $export;
}
