<?php
/**
 * @file
 * action_pod.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function action_pod_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'fieldable_panels_pane-action_pod-field_download_item'
  $field_instances['fieldable_panels_pane-action_pod-field_download_item'] = array(
    'bundle' => 'action_pod',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'downloadable',
        'settings' => array(
          'cta_field_name' => '',
        ),
        'type' => 'downloadable_ctaicons',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'fieldable_panels_pane',
    'field_name' => 'field_download_item',
    'label' => 'Download Item',
    'required' => 1,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Download Item');

  return $field_instances;
}
