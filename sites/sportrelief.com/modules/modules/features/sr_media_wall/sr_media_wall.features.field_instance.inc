<?php
/**
 * @file
 * sr_media_wall.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function sr_media_wall_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-media_wall-field_custom_body'
  $field_instances['bean-media_wall-field_custom_body'] = array(
    'bundle' => 'media_wall',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 16,
      ),
      'media_wall' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'ds_extras_field_template' => 'theme_field',
    'entity_type' => 'bean',
    'exclude_cv' => 0,
    'field_name' => 'field_custom_body',
    'label' => 'Inline HTML',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'bean-media_wall-field_media_wall_promo'
  $field_instances['bean-media_wall-field_media_wall_promo'] = array(
    'bundle' => 'media_wall',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 0,
          'view_mode' => 'media_wall',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 1,
      ),
      'media_wall' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 0,
          'view_mode' => 'media_wall',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 6,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'bean',
    'exclude_cv' => 0,
    'field_name' => 'field_media_wall_promo',
    'label' => 'Promo 1',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'bean-media_wall-field_media_wall_promo_2'
  $field_instances['bean-media_wall-field_media_wall_promo_2'] = array(
    'bundle' => 'media_wall',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 0,
          'view_mode' => 'media_wall_promo_2',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 2,
      ),
      'media_wall' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 0,
          'view_mode' => 'media_wall_promo_2',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 7,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'bean',
    'exclude_cv' => 0,
    'field_name' => 'field_media_wall_promo_2',
    'label' => 'Promo 2',
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

  // Exported field_instance: 'bean-media_wall-field_media_wall_promo_3'
  $field_instances['bean-media_wall-field_media_wall_promo_3'] = array(
    'bundle' => 'media_wall',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 0,
          'view_mode' => 'media_wall_promo_3',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 9,
      ),
      'media_wall' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 0,
          'view_mode' => 'media_wall_promo_3',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'bean',
    'exclude_cv' => 0,
    'field_name' => 'field_media_wall_promo_3',
    'label' => 'Promo 3',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'bean-media_wall-field_media_wall_promo_4'
  $field_instances['bean-media_wall-field_media_wall_promo_4'] = array(
    'bundle' => 'media_wall',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 0,
          'view_mode' => 'media_wall_promo_3',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 10,
      ),
      'media_wall' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 0,
          'view_mode' => 'media_wall_promo_3',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 5,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'bean',
    'exclude_cv' => 0,
    'field_name' => 'field_media_wall_promo_4',
    'label' => 'Promo 4',
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
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Inline HTML');
  t('Promo 1');
  t('Promo 2');
  t('Promo 3');
  t('Promo 4');

  return $field_instances;
}
