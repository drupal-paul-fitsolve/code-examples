<?php
/**
 * @file
 * action_pod.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function action_pod_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_download_item'
  $field_bases['field_download_item'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_download_item',
    'foreign keys' => array(
      'node' => array(
        'columns' => array(
          'target_id' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(),
      ),
      'target_type' => 'downloadable',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
