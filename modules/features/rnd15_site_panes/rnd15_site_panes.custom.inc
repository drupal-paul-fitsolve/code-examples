<?php
/**
 * @file
 * All custom code of the rnd15 Site Panes Feature
 */

/**
 * implementation of HOOK_entity_info_alter
 */
function rnd15_site_panes_entity_info_alter(&$entity_info) {
  $module_path = drupal_get_path('module', 'rnd15_site_panes');

  $entity_info['fieldable_panels_pane']['bundles']['image'] = array(
    'label' => t('Image Pane'),
    'pane top level' => TRUE, // set to true to make this show as a top level icon
    'pane icon' => $module_path.'/icon-pane-image.png',
    'admin' => array(
      'path' => 'admin/structure/fieldable-panels-panes/manage/%fieldable_panels_panes_type',
      'bundle argument' => 4,
      'real path' => 'admin/structure/fieldable-panels-panes/manage/image',
      'access arguments' => array('administer fieldable panels panes'),
    ),
  );

  $entity_info['fieldable_panels_pane']['bundles']['image_overlay'] = array(
    'label' => t('Image Overlay Pane'),
    'pane top level' => TRUE, // set to true to make this show as a top level icon
    'pane icon' => $module_path.'/icon-pane-image.png',
    'admin' => array(
      'path' => 'admin/structure/fieldable-panels-panes/manage/%fieldable_panels_panes_type',
      'bundle argument' => 4,
      'real path' => 'admin/structure/fieldable-panels-panes/manage/image-overlay',
      'access arguments' => array('administer fieldable panels panes'),
    ),
  );

  $entity_info['fieldable_panels_pane']['bundles']['video'] = array(
    'label' => t('Video Pane'),
    'pane top level' => TRUE, // set to true to make this show as a top level icon
    'pane icon' => $module_path.'/icon-pane-video.png',
    'admin' => array(
      'path' => 'admin/structure/fieldable-panels-panes/manage/%fieldable_panels_panes_type',
      'bundle argument' => 4,
      'real path' => 'admin/structure/fieldable-panels-panes/manage/video',
      'access arguments' => array('administer fieldable panels panes'),
    ),
  );

  $entity_info['fieldable_panels_pane']['bundles']['text'] = array(
    'label' => t('Text Pane'),
    'pane top level' => TRUE, // set to true to make this show as a top level icon
    'pane icon' => $module_path.'/icon-pane-text.png',
    'admin' => array(
      'path' => 'admin/structure/fieldable-panels-panes/manage/%fieldable_panels_panes_type',
      'bundle argument' => 4,
      'real path' => 'admin/structure/fieldable-panels-panes/manage/text',
      'access arguments' => array('administer fieldable panels panes'),
    ),
  );

  $entity_info['fieldable_panels_pane']['bundles']['svg'] = array(
    'label' => t('SVG Pane'),
    'pane top level' => TRUE, // set to true to make this show as a top level icon
    'pane icon' => $module_path.'/icon-pane-svg.png',
    'admin' => array(
      'path' => 'admin/structure/fieldable-panels-panes/manage/%fieldable_panels_panes_type',
      'bundle argument' => 4,
      'real path' => 'admin/structure/fieldable-panels-panes/manage/svg',
    ),
  );
}

/**
 * implementation of HOOK_preprocess_panels_pane()
 *
 * Preprocess our panel panes
 * - Extend settings 
 */
function rnd15_site_panes_preprocess_fieldable_panels_pane(&$vars) {
  // Custom Checks if we actually want to preprocess this pane
  $pane_filter = array('text', 'image', 'image_overlay', 'video', 'svg', 'media_wall');
  $pane_filter_images = array('image', 'image_overlay', 'video', 'svg', 'media_wall');

  // Skip if no pane type, no content or is not a valid pane
  if (empty($vars['elements']['#entity_type']) || empty($vars['content']) || !in_array($vars['elements']['#bundle'], $pane_filter)) return;

  /**
   * Do the Picture Group Magic :)
   */
  if(in_array($vars['elements']['#bundle'], $pane_filter_images)) {
    _process_pane_picture_groups($vars);
  }

  /**
   * Do our default preprocess fieldable panels pane logic
   */
  $elements = $vars['elements'];

  // At this point, remove the fieldable class and add our own
  $vars['classes_array'] = array(
    drupal_html_class('pane-' . $elements['#bundle'] . '__content'),
  );

  if (!empty($elements['#fieldable_panels_pane']->title)) {
    $vars['title'] = $elements['#fieldable_panels_pane']->title;
  }

  // Add theme hook suggestions based on entity type + bundle and entity type + bundle + view mode
  $vars['theme_hook_suggestions'][] = $elements['#entity_type'] . '__' . $elements['#bundle'];
  $vars['theme_hook_suggestions'][] = $elements['#entity_type'] . '__' . $elements['#bundle'] . '__' . $elements['#view_mode'];
}

/**
 * Process Pane Picture Groups
 * @param  [array] &$vars [preprocess vars array]
 * @param  [array] $pane  [description]
 */
function _process_pane_picture_groups(&$vars) {
  $pane = $vars['elements']['#fieldable_panels_pane'];
  $pane_settings = !empty($pane->pane_settings) ? $pane->pane_settings : FALSE;
  $pane_settings_columns = !empty($pane_settings['columns']) ? $pane_settings['columns'] : FALSE;

  // Get the PANEL/REGION picture groups if they are set
  $panel_picture_group = _get_panel_picture_groups($pane);

  if ($panel_picture_group) {
    // IF we have panel picture group, then set this picture group as precedence on all applicable fields
    _rnd15_site_panes_set_picture_group($vars, $panel_picture_group, $pane_settings_columns);
  } elseif ($pane_settings && $pane_settings_columns) {
    // OTHERWISE check if we have pane settings and columns, then let's stipulate the picture group from that
    
    // Use helper function to create our picture group from the pane setting columns
    $picture_group = _col_class_to_picture_group_breakpoints($pane_settings_columns);

    // Set the picture group of all fields
    _rnd15_site_panes_set_picture_group($vars, $picture_group, $pane_settings_columns);
  }

  // Override the fields and re-render the fields
  $vars['fields'] = '';
  foreach ($vars['content'] as $content) {
    $vars['fields'] .= render($content);
  }
}

/**
 * implementation of HOOK_preprocess_panels_pane()
 *
 * Preprocess our panel panes
 * - Extend settings 
 */
function rnd15_site_panes_preprocess_panels_pane(&$vars) {
  // SKIP if no type or it is not a fieldable panels pane
  if (empty($vars['pane']->type) || !($vars['pane']->type == 'fieldable_panels_pane')) return;

  // Fieldable Panel Panes and Panel Panes add classes we don't need so let's remove them
  $remove_classes = array(
    'panel-pane',
    'pane-fieldable-panels-pane',
  );

  // Alter pane classes
  foreach ($vars['classes_array'] as $key => &$value) {
    // Not great but should cover future pane types being added
    $value = str_replace('pane-bundle-', 'pane-', $value);
    // Also, remove the classes we defined in $remove_classes array.
    if (in_array($value, $remove_classes)){
      unset($vars['classes_array'][$key]);
    }
  }

  // Extend the content to contain the pane settings
  // Pass this in so that the _preprocess_fieldable_panels_pane hook can access the pane settings
  // Supply the layout and panel the pane is within
  // Supply pane id in which the FP is wrapped in
  // Also pass in the panel the pane sits in along with the layout
  // Only because of fieldable panels pane, is there a cleaner solution? Object merge type thing?
  $vars['content']['#element']->pane_settings = !empty($vars['pane']->style['settings']) ? $vars['pane']->style['settings'] : null;
  $vars['content']['#element']->region_settings = isset($vars['display']->panel_settings['style_settings'][$vars['pane']->panel]) ? $vars['display']->panel_settings['style_settings'][$vars['pane']->panel] : null;
  $vars['content']['#element']->panel = isset($vars['pane']->panel) ? $vars['pane']->panel : null;
  $vars['content']['#element']->layout = isset($vars['display']->layout) ? $vars['display']->layout : null;
  $vars['content']['#element']->pane_id = isset($vars['pane']->pid) ? $vars['pane']->pid : null;

  // Add additional hook suggestion so we can template panels panes based on the entity type and bundle
  $vars['theme_hook_suggestions'][] = 'panels_pane__' . $vars['content']['#entity_type'] . '__' .  $vars['content']['#bundle'];
}

/**
 * Custom function that essentially recreates the breakpoints based on the panes grid
 * vars = reference to the pane vars variable
 * picture_group = the picture group we want to set the image to
 * column_check = if we want to check if the 
 */
function _rnd15_site_panes_set_picture_group(&$vars, $picture_group, $columns) {
  // Use Drupal alter so anyone can modify this
  $context = array(
    'columns' => $columns,
    'fieldable_panels_pane' => $vars['elements']['#fieldable_panels_pane'],
  );
  drupal_alter('rnd15_site_panes_set_picture_group', $picture_group, $context);

  // Define an array of field names we want to inherit the grid.
  $field_names = array('field_site_image', 'field_site_image_xs', 'field_site_image_overlay');

  // Add grid inheritance to each field.
  foreach ($field_names as $field_name) {

    // Skip if it's not a valid image pane
    if (empty($vars['content'][$field_name][0]) || $vars['content'][$field_name][0]['#theme'] != 'picture_formatter') continue;

    // Assign breakpoints variable by reference
    $vars['content'][$field_name][0]['#breakpoints'] = $picture_group;

    // Set the fallback image style to the normal resolution medium breakpoint
    $vars['content'][$field_name][0]['#image_style'] = ($picture_group['breakpoints.theme.cr_layout_v2.md']['1x']) ? $picture_group['breakpoints.theme.cr_layout_v2.md']['1x'] : $vars['content'][$field_name][0]['#image_style'];
  }
}

/* 
 * Helper function to modify breakpoints based on column size
 *
 * @param $columns Columns from Pane Settings
 *
 * @return $picture_group a picture group
 * 
 * This function loops through the columns of the pane 
 * and modifies the breakpoints to match the correct picture group
 * column size
 */
function _col_class_to_picture_group_breakpoints($columns) {
  $picture_group = array();

  // XS is never empty, others may inherit, but xs 1x will always have to be set
  $previous_column_class = '';

  // Loop thorugh the columns
  foreach ($columns as $current_breakpoint => $col_class) {

    // If we dont' have a col class let's skip this.
    if ($col_class === 0) continue;

    // If inherit, use old previous
    $col_class = ($col_class !== 'inherit' && $col_class !== 1) ? $col_class : $previous_column_class;

    // Deconstruct the col class so we have the breakpoint and columns
    list(, $class_break, $class_cols) = explode('_', $col_class);

    // Now assign the correct picture group
    $picture_group['breakpoints.theme.cr_layout_v2.' . $current_breakpoint] = array(
      '1x' => 'col_' . $class_cols . '_' . $current_breakpoint,
      '2x' => 'col_' . $class_cols . '_' . $current_breakpoint . '_2x'
    );

    // Store the previous valid breakpoint, used for 'inherit'
    $previous_column_class = $col_class;
  }

  return $picture_group;
}

/**
 * Create a static version of the panel layouts available so we don't keep calling the function
 */
function _get_static_layouts() {
  $layouts = &drupal_static(__FUNCTION__);

  if (empty($layouts)) {
    module_load_include('inc', 'panels', 'includes/plugins');
    $layouts = panels_get_layouts();
  }

  return $layouts;
}

/**
 * Helper funciton to get the panel picture groups
 */
function _get_panel_picture_groups($pane) {
  // Skip if we dont have a layout or panel
  if(empty($pane->layout) || empty($pane->panel)) return;

  $available_layouts = _get_static_layouts();
  $layout = $pane->layout;
  $panel = $pane->panel;

  if (!empty($available_layouts[$layout]['region_picture_groups'][$panel])) {
    return $available_layouts[$layout]['region_picture_groups'][$panel];
  }

  return FALSE;
}