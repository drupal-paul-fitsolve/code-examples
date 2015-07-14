<?php

/**
 * Implements hook_panels_layouts().
 */
function cr_layout_cr_layout_content_partners_panels_layouts() {
  $items['cr_layout_content_partners'] = array(
    'title' => t('Content only - Partners'),
    'category' => t('CR Layouts'),
    'icon' => 'cr_layout_content_partners.png',
    'theme' => 'cr_layout_content_partners',
    'regions' => array(
      'intro' => t('Intro'),
      'row1_col1' => t('Row1: Column1'),
      'row1_col2' => t('Row1: Column2'),
      'row1_col3' => t('Row1: Column3'),
      'row1_col4' => t('Row1: Column4'),
      'row2_col1' => t('Row2: Column1'),
      'row2_col2' => t('Row2: Column2'),
      'row2_col3' => t('Row2: Column3'),
      'row2_col4' => t('Row2: Column4'),
      'row3_col1' => t('Row3: Column1'),
      'row3_col2' => t('Row3: Column2'),
      'row3_col3' => t('Row3: Column3'),
      'row3_col4' => t('Row3: Column4'),
      'row4_col1' => t('Row4: Column1'),
      'row4_col2' => t('Row4: Column2'),
      'row4_col3' => t('Row4: Column3'),
      'row4_col4' => t('Row4: Column4'),
      'row5_col1' => t('Row5: Column1'),
      'row5_col2' => t('Row5: Column2'),
      'row5_col3' => t('Row5: Column3'),
      'row5_col4' => t('Row5: Column4'),
      'row6_col1' => t('Row6: Column1'),
      'row6_col2' => t('Row6: Column2'),
      'row6_col3' => t('Row6: Column3'),
      'row6_col4' => t('Row6: Column4'),
      'row7_col1' => t('Row7: Column1'),
      'row7_col2' => t('Row7: Column2'),
      'row7_col3' => t('Row7: Column3'),
      'row7_col4' => t('Row7: Column4'),

      'row8_col1' => t('Row8: Column1'),
      'row8_col2' => t('Row8: Column2'),
      'row8_col3' => t('Row8: Column3'),
      'row8_col4' => t('Row8: Column4'),

      'row9_col1' => t('Row9: Column1'),
      'row9_col2' => t('Row9: Column2'),
      'row9_col3' => t('Row9: Column3'),
      'row9_col4' => t('Row9: Column4'),

      'row10_col1' => t('Row10: Column1'),
      'row10_col2' => t('Row10: Column2'),
      'row10_col3' => t('Row10: Column3'),
      'row10_col4' => t('Row10: Column4'),

      'row11_col1' => t('Row11: Column1'),
      'row11_col2' => t('Row11: Column2'),
      'row11_col3' => t('Row11: Column3'),
      'row11_col4' => t('Row11: Column4'),

      'row12_col1' => t('Row12: Column1'),
      'row12_col2' => t('Row12: Column2'),
      'row12_col3' => t('Row12: Column3'),
      'row12_col4' => t('Row12: Column4'),

      'row13_col1' => t('Row13: Column1'),
      'row13_col2' => t('Row13: Column2'),
      'row13_col3' => t('Row13: Column3'),
      'row13_col4' => t('Row13: Column4'),

      'row14_col1' => t('Row14: Column1'),
      'row14_col2' => t('Row14: Column2'),
      'row14_col3' => t('Row14: Column3'),
      'row14_col4' => t('Row14: Column4'),

      'row15_col1' => t('Row15: Column1'),
      'row15_col2' => t('Row15: Column2'),
      'row15_col3' => t('Row15: Column3'),
      'row15_col4' => t('Row15: Column4'),

      'row16_col1' => t('Row16: Column1'),
      'row16_col2' => t('Row16: Column2'),
      'row16_col3' => t('Row16: Column3'),
      'row16_col4' => t('Row16: Column4'),

      'row17_col1' => t('Row17: Column1'),
      'row17_col2' => t('Row17: Column2'),
      'row17_col3' => t('Row17: Column3'),
      'row17_col4' => t('Row17: Column4'),

      'row18_col1' => t('Row18: Column1'),
      'row18_col2' => t('Row18: Column2'),
      'row18_col3' => t('Row18: Column3'),
      'row18_col4' => t('Row18: Column4'),

      'row19_col1' => t('Row19: Column1'),
      'row19_col2' => t('Row19: Column2'),
      'row19_col3' => t('Row19: Column3'),
      'row19_col4' => t('Row19: Column4'),

      'row20_col1' => t('Row20: Column1'),
      'row20_col2' => t('Row20: Column2'),
      'row20_col3' => t('Row20: Column3'),
      'row20_col4' => t('Row20: Column4'),

      'subpod1' => t('Subpod 1'),
      'subpod2' => t('Subpod 2'),
      'subpod3' => t('Subpod 3'),
    ),
  );

  return $items;
}

/**
 * Preprocess variables for cr_layout_content_side_promo.tpl.php
 */
function template_preprocess_cr_layout_content_partners(&$vars) {
  require_once DRUPAL_ROOT . '/' . drupal_get_path('theme','cr_layout') . '/includes/helper.inc';
  $structure = array(
    'max-columns' => 4,
    'grid-column-total' => 24,
  );
  $vars['panel_adjustments'] = _cr_layout_calculate_panels_layout($vars, $structure);
}
