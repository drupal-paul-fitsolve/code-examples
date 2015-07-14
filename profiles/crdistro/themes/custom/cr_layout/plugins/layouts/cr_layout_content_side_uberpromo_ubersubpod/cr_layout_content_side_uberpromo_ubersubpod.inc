<?php

/**
 * Implements hook_panels_layouts().
 */
function cr_layout_cr_layout_content_side_uberpromo_ubersubpod_panels_layouts() {
  $items['cr_layout_content_side_uberpromo_ubersubpod'] = array(
    'title' => t('Content with sidebar and uber promo and uber subpods'),
    'category' => t('CR Layouts'),
    'icon' => 'cr_layout_content_side_uberpromo_ubersubpod.png',
    'theme' => 'cr_layout_content_side_uberpromo_ubersubpod',
    'regions' => array(
      'intro' => t('Intro'),
      'top' => t('Promo'),
      'promo_bottom' => t('Promo Bottom'),
      'sidebar' => t('Sidebar'),
      'row1_col1' => t('Row1: Column1'),
      'row1_col2' => t('Row1: Column2'),
      'row1_col3' => t('Row1: Column3'),
      'row2_col1' => t('Row2: Column1'),
      'row2_col2' => t('Row2: Column2'),
      'row2_col3' => t('Row2: Column3'),
      'row3_col1' => t('Row3: Column1'),
      'row3_col2' => t('Row3: Column2'),
      'row3_col3' => t('Row3: Column3'),
      'row4_col1' => t('Row4: Column1'),
      'row4_col2' => t('Row4: Column2'),
      'row4_col3' => t('Row4: Column3'),
      'row5_col1' => t('Row5: Column1'),
      'row5_col2' => t('Row5: Column2'),
      'row5_col3' => t('Row5: Column3'),
      'row6_col1' => t('Row6: Column1'),
      'row6_col2' => t('Row6: Column2'),
      'row6_col3' => t('Row6: Column3'),
      'subpod1' => t('Subpod 1'),
      'subpod2' => t('Subpod 2'),
      'subpod3' => t('Subpod 3'),
      'ubersubpod' => t('Ubersubpod'),
    ),
  );

  return $items;
}


/**
 * Preprocess variables for cr_layout_content_side_uberpromo-ubersubpod.tpl.php
 */
function template_preprocess_cr_layout_content_side_uberpromo_ubersubpod(&$vars) {
  require_once DRUPAL_ROOT . '/' . drupal_get_path('theme','cr_layout') . '/includes/helper.inc';
    $structure = array(
    'grid-column-total' => 18,
  );
  $vars['panel_adjustments'] = _cr_layout_calculate_panels_layout($vars, $structure);

  $narrowStructure = array(
    'grid-column-total' => 24,
  );
  $narrowSettings = array(
    'prefix' => 'narrow-',
    'equal-heights' => FALSE,
  );
  $vars['narrow_panel_adjustments'] = _cr_layout_calculate_panels_layout($vars, $narrowStructure, $narrowSettings);
}
