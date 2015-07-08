<?php
/**
 * @file
 *
 * Ctools content type for fundraise showcase form
 *
 * Author: Graham Utton
 */

$plugin = array(
  'title' => t('Fundraise showcase form'),
  'description' => t('Displays a form for end users to submit fundraiser showcase information'),
  'single' => TRUE,
  'render callback' => 'sr16splash_fundraiser_showcase_submission_form_render',
  'category' => array(t('Fundraise'), -9),
);

/**
 * Render callback function for Fundraise showcase form
 *
 * @param $subtype
 *  The subtype if applicable
 * @param $conf
 *  Any configuration set for this content type
 * @param $args
 *  Any additional arguments
 * @param $context
 *  Any context data
 *
 * @return stdClass
 *  A block object
 */
function sr16splash_fundraiser_showcase_submission_form_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $form = drupal_get_form('sr16splash_fundraiser_showcase_submission_form');
  $block->content = $form;

  return $block;
}


/**
 * Form function for submitting fundraiser showcases
 *
 * @param array $form
 *  The form array
 * @param array $form_state
 *  The form state array
 * @return array
 *  The form
 */
function sr16splash_fundraiser_showcase_submission_form($form, &$form_state) {
  // It is necessary to add the content type plugin path into the form state
  // here, so that this form function can be found again on form rebuild
  $form_state['build_info']['files']['menu'] =
    drupal_get_path('module', 'sr16splash_fundraiser_showcase') . '/plugins/content_types/fundraise_showcase_form.inc';

  $form['#attached']['js']['parsley'] = drupal_get_path('module', 'sr16splash_fundraiser_showcase') . '/js/parsley1.2.3.min.js';

  $form['#attributes'] = array(
    'parsley-validate' => 'parsley-validate',
  );

  $node = new stdClass();
  $node->type = 'fundraiser_showcase';
  $node->language = LANGUAGE_NONE;

  // store the empty node in the form_state so we can retrieve and add to it in the submit handler
  $form['new_node'] = array(
    '#type' => 'value,',
    '#value'  => $node,
  );

  // add all additional fields
  $attach_form_field_common_args = array(
    'node',
    'fundraiser_showcase',
    $node,
    &$form,
    &$form_state,
    $node->language
  );

  $field_names = array(
    'field_fundraiser_showcase_images',
    'body',
    'field_site_first_name',
    'field_site_last_name',
    'field_site_establishment',
    'field_site_town',
    'field_site_email',
    'field_site_fundraising_context',
    'field_site_consent'
  );

  foreach($field_names as $field_name) {
    $attach_form_field_args = $attach_form_field_common_args;
    array_unshift($attach_form_field_args, $field_name);
    call_user_func_array('sr16splash_fundraiser_showcase_attach_form_field', $attach_form_field_args);
  }

  // add upload validator where we can remove spaces from filename
  $image_indexes = element_children($form['field_fundraiser_showcase_images'][$node->language]);
  $images = &$form['field_fundraiser_showcase_images'][$node->language];
  foreach ($image_indexes as $image_index) {
    $images[$image_index]['#upload_validators']['sr16splash_fundraiser_showcase_validate_filename'] = array();
  }

  // Add in the parsley inline validation attributes

  // Photo caption parsley attributes
  $current_attributes = &$form['body'][$node->language][0]['value']['#attributes'];

  $parsley_attributes = array(
    'parsley-trigger' => 'blur',
    'parsley-error-message' => 'Please add a photo caption',
    'parsley-required' => "true",
    'parsley-validation-minlength'  => 0,
  );

  $current_attributes += $parsley_attributes;

  // First name parsley attributes
  $current_attributes = &$form['field_site_first_name'][$node->language][0]['value']['#attributes'];

  $parsley_attributes = array(
    'parsley-trigger' => 'blur',
    'parsley-error-message' => 'Please fill in your first name',
    'parsley-required' => "true",
    'parsley-validation-minlength'  => 0,
  );

  $current_attributes += $parsley_attributes;

  // Town parsley attributes
  $current_attributes = &$form['field_site_town'][$node->language][0]['value']['#attributes'];

  $parsley_attributes = array(
    'parsley-trigger' => 'blur',
    'parsley-error-message' => 'Please fill in your town',
    'parsley-required' => "true",
    'parsley-validation-minlength'  => 0,
  );

  $current_attributes += $parsley_attributes;

  // Email parsley attributes
  $current_attributes = &$form['field_site_email'][$node->language][0]['value']['#attributes'];

  $parsley_attributes = array(
    'parsley-trigger' => 'blur',
    'parsley-required' => 'true',
    'parsley-type' => 'email',
    'parsley-required-message' => 'Please fill in your email',
    'parsley-type-message' => 'Please enter a valid email address',
    'parsley-validation-minlength'  => 0,
  );

  $current_attributes += $parsley_attributes;

  // How you fundraised parsley attributes
  $parsley_attributes = array(
    'parsley-regexp' => "(family|own|school|university|work|youth_group)",
    'parsley-regexp-message' => 'Please tell us how you fundraised',
    'parsley-trigger' => 'blur change',
  );

  $fundraising_context = &$form['field_site_fundraising_context'][$node->language];
  $fundraising_context['#attributes'] = $parsley_attributes;

  // Consent parsley attributes
  $parsley_attributes = array(
    'parsley-required' => 'true',
    'parsley-trigger' => 'blur change',
    'parsley-error-message' => 'Please tick the box if you agree with the Terms of Use',
  );

  $consent = &$form['field_site_consent'][$node->language];
  $consent['#attributes'] = $parsley_attributes;

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Done'),
    '#weight' => 10,
  );

  return $form;
}

/**
 * File upload validator to replace spaces in filenames
 *
 * This function does not actually validate filenames, instead it actually
 * amends the filename to replace spaces with underscores, before the file is written.
 *
 * Slight misuse of a file upload validator, but don't think there is a better spot to do this.
 *
 * @param \stdClass $file
 *  The file
 * @return array
 *  Any errors detected during validation
 */
function sr16splash_fundraiser_showcase_validate_filename(stdClass $file) {
  // not strictly necessary to create $errors array here but the impact is
  // minimal, its just an empty array. Its better to keep the normal form of the
  // function as this self describes the normal way it is used,
  $errors = array();
  $file->filename = str_replace(' ', '_', $file->filename);
  return $errors;
}

/**
 * Submit handler for fundraiser showcase form
 *
 * @param array $form
 *  The form
 * @param array $form_state
 *  The form state
 */
function sr16splash_fundraiser_showcase_submission_form_submit($form, &$form_state) {
  $vals = $form_state['values'];

  $node = $form['new_node']['#value'];

  $field_names = array(
    'field_fundraiser_showcase_images',
    'body',
    'field_site_first_name',
    'field_site_last_name',
    'field_site_establishment',
    'field_site_town',
    'field_site_email',
    'field_site_fundraising_context',
    'field_site_consent'
  );

  foreach ($field_names as $field_name) {
    $node->$field_name = $vals[$field_name];
  }

  // create title field from First name and Town values
  $name_field = field_get_items('node', $node, 'field_site_first_name');
  $name_value = render(field_view_value('node', $node, 'field_site_first_name', $name_field[0]));

  $town_field = field_get_items('node', $node, 'field_site_town');
  $town_value = render(field_view_value('node', $node, 'field_site_town', $town_field[0]));

  $node->title = $name_value  . ", " . $town_value;

  $node->status = 0;

  $node = node_submit($node); // Prepare node for saving
  node_save($node);

  $form_state['redirect'] = 'fundraise/fundraiser-gallery/thank-you';
}


/**
 * Helper function to pull fields from node types for rendering in custom form arrays.
 *
 * @todo This could be move to a generic module of helper functions as it
 * could prove useful in future
 *
 * @param $field_name
 *  The field name
 * @param $entity_type
 *  The entity type
 * @param $bundle
 *  The bundle
 * @param $entity
 *  The entity
 * @param $form
 *  The form
 * @param $form_state
 *  The form state
 * @param null $langcode
 *  The language
 */
function sr16splash_fundraiser_showcase_attach_form_field($field_name, $entity_type, $bundle, $entity, &$form, &$form_state, $langcode = NULL) {
  // Set #parents to 'top-level' if it doesn't exist.
  $form += array('#parents' => array());

  // If no language is provided use the default site language.
  $options = array(
    'language' => field_valid_language($langcode),
    'default' => TRUE,
  );

  // Append to the form
  ctools_include('fields');
  $field_instance = field_info_instance($entity_type, $field_name, $bundle);
  $form += (array) ctools_field_invoke_field($field_instance, 'form', $entity_type, $entity, $form, $form_state, $options);
}
