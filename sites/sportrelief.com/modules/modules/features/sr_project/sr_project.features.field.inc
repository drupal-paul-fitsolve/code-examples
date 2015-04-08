<?php
/**
 * @file
 * sr_project.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function sr_project_field_default_fields() {
  $fields = array();

  // Exported field: 'node-project-body'.
  $fields['node-project-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'project',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 0,
        ),
        'downloadable' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => 600,
          ),
          'type' => 'text_summary_or_trimmed',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Body',
      'required' => FALSE,
      'settings' => array(
        'display_summary' => TRUE,
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 20,
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '41',
      ),
    ),
  );

  // Exported field: 'node-project-field_cta'.
  $fields['node-project-field_cta'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '3',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_cta',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'link',
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'rel' => '',
          'target' => 'default',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 1,
        'title' => 'optional',
        'title_maxlength' => 128,
        'title_value' => '',
        'url' => 0,
      ),
      'translatable' => '0',
      'type' => 'link_field',
    ),
    'field_instance' => array(
      'bundle' => 'project',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(),
          'type' => 'link_default',
          'weight' => 1,
        ),
        'downloadable' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_cta',
      'label' => 'CTA',
      'required' => 0,
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'configurable_title' => 0,
          'rel' => '',
          'target' => 'default',
          'title' => '',
        ),
        'display' => array(
          'url_cutoff' => '80',
        ),
        'enable_tokens' => 1,
        'title' => 'optional',
        'title_maxlength' => '128',
        'title_value' => '',
        'url' => 0,
        'user_register_form' => FALSE,
        'validate_url' => 1,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_field',
        'weight' => '43',
      ),
    ),
  );

  // Exported field: 'node-project-field_project_image'.
  $fields['node-project-field_project_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_project_image',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'project',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => 2,
        ),
        'downloadable' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_project_image',
      'label' => 'Project Image',
      'required' => 0,
      'settings' => array(
        'alt_field' => 1,
        'default_image' => 0,
        'epsacrop' => array(
          'styles' => array(
            'maincontent-no-sidebar-dualcolumn-leftright-v' => 0,
            'maincontent-no-sidebar-dualcolumn-leftright__default' => 0,
            'maincontent-no-sidebar-dualcolumn__default' => 0,
            'maincontent-no-sidebar-singlecolumn__default' => 0,
            'maincontent-no-sidebar-tricolumn__default' => 0,
            'maincontent-tabbed-wide-sidebar__default' => 0,
            'maincontent-thin-sidebar-dualcolumn__default' => 0,
            'maincontent-thin-sidebar-singlecolumn__default' => 0,
            'maincontent-top-sidebar-dualcolumn__default' => 0,
            'maincontent-top-sidebar-singlecolumn__default' => 0,
            'maincontent-wide-sidebar-dualcolumn__default' => 0,
            'maincontent-wide-sidebar-singlecolumn__default' => 0,
            'maincontent_alt_image_size' => 0,
            'maincontent_showcase' => 0,
            'news_thumb' => 0,
            'partner-rotation-logo' => 0,
            'partner-slideshow-photos' => 0,
            'promo-no-sidebar-singlecolumn-tabs-v' => 0,
            'promo-no-sidebar-singlecolumn-tabs__default' => 0,
            'promo-no-sidebar-singlecolumn-v' => 0,
            'promo-no-sidebar-singlecolumn__default' => 0,
            'promo-thin-sidebar-singlecolumn-tabs-v' => 0,
            'promo-thin-sidebar-singlecolumn-tabs__default' => 0,
            'promo-thin-sidebar-singlecolumn-v' => 0,
            'promo-thin-sidebar-singlecolumn__default' => 0,
            'promo-top-sidebar-singlecolumn-tabs-v' => 0,
            'promo-top-sidebar-singlecolumn-tabs__default' => 0,
            'promo-top-sidebar-singlecolumn-v' => 0,
            'promo-top-sidebar-singlecolumn__default' => 0,
            'promo-wide-sidebar-singlecolumn-tabs-v' => 0,
            'promo-wide-sidebar-singlecolumn-tabs__default' => 0,
            'promo-wide-sidebar-singlecolumn-v' => 0,
            'promo-wide-sidebar-singlecolumn__default' => 0,
            'promohome-thin-sidebar-singlecolumn__default' => 0,
            'schools_resources' => 0,
            'sidebar_generic_block' => 0,
            'subpod-no-sidebar-tricolumn-fullwidth__default' => 0,
            'subpod-no-sidebar-tricolumn-sticky__default' => 0,
            'subpod-no-sidebar-tricolumn__default' => 0,
            'subpod-thin-sidebar-tricolumn-fullwidth__default' => 0,
            'subpod-thin-sidebar-tricolumn-sticky__default' => 0,
            'subpod-thin-sidebar-tricolumn__default' => 0,
            'subpod-top-sidebar-tricolumn-fullwidth__default' => 0,
            'subpod-top-sidebar-tricolumn-sticky__default' => 0,
            'subpod-top-sidebar-tricolumn_default' => 0,
            'subpod-wide-sidebar-dualcolumn-fullwidth__default' => 0,
            'subpod-wide-sidebar-dualcolumn-sticky__default' => 0,
            'subpod-wide-sidebar-dualcolumn__default' => 0,
          ),
        ),
        'file_directory' => '',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '1 MB',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'image',
        'settings' => array(
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '44',
      ),
    ),
  );

  // Exported field: 'node-project-field_project_region'.
  $fields['node-project-field_project_region'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_project_region',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'project_region',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'project',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 3,
        ),
        'downloadable' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_project_region',
      'label' => 'Region',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '45',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('CTA');
  t('Project Image');
  t('Region');

  return $fields;
}
