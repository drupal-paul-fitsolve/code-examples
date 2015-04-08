<?php
/**
 * @file
 * sr_project.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function sr_project_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-project-body'
  $field_instances['node-project-body'] = array(
    'bundle' => 'project',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'downloadable' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
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
      'exclude_cv' => FALSE,
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-project-field_cta'
  $field_instances['node-project-field_cta'] = array(
    'bundle' => 'project',
    'default_value' => NULL,
    'deleted' => 0,
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
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
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
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'exclude_cv' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
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
      'weight' => 43,
    ),
  );

  // Exported field_instance: 'node-project-field_project_image'
  $field_instances['node-project-field_project_image'] = array(
    'bundle' => 'project',
    'deleted' => 0,
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
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
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
      'exclude_cv' => FALSE,
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
        'insert' => 0,
        'insert_absolute' => FALSE,
        'insert_class' => '',
        'insert_default' => array(
          0 => 'auto',
        ),
        'insert_styles' => array(
          0 => 'auto',
        ),
        'insert_width' => '',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 44,
    ),
  );

  // Exported field_instance: 'node-project-field_project_region'
  $field_instances['node-project-field_project_region'] = array(
    'bundle' => 'project',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'downloadable' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_plain',
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
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-project-title_field'
  $field_instances['node-project-title_field'] = array(
    'bundle' => 'project',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'title',
        'settings' => array(
          'title_class' => 'project-title',
          'title_link' => '',
          'title_style' => 'h4',
        ),
        'type' => 'title_linked',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'title_field',
    'label' => 'Title',
    'required' => TRUE,
    'settings' => array(
      'exclude_cv' => FALSE,
      'hide_label' => array(
        'entity' => 'entity',
        'page' => 'page',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('CTA');
  t('Project Image');
  t('Region');
  t('Title');

  return $field_instances;
}
