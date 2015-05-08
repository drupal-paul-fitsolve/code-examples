<?php
/**
 * @file rnd15_site_media_wall.inc
 *
 * Code for Panels Layout Plugin - Media Wall
 *
 * Author: Andy E. Phipps
 */

// Plugin definition.
$plugin = array(
  'title' => t('Media Wall template 1'),
  'icon' => 'rnd15_site_media_wall_template_1.png',
  'category' => t('Media Wall layouts'),
  'theme' => 'rnd15_site_media_wall_template_1',
  'regions' => array(
    'region_1' => t('Region 1 (top - left landscape)'),
    'region_2' => t('Region 2 (top - right top square)'),
    'region_3' => t('Region 3 (top - right bottom square)'),
    'region_4' => t('Region 4 (centre - right large square)'),
    'region_5' => t('Region 5 (centre - left top landscape)'),
    'region_6' => t('Region 6 (centre - left bottom landscape)'),
    'region_7' => t('Region 7 (bottom - left square)'),
    'region_8' => t('Region 8 (bottom - centre square)'),
    'region_9' => t('Region 9 (bottom - right square)'),
  ),
  'region_picture_groups' => array(
    'region_1' => array(
      'breakpoints.theme.cr_layout_v2.xs' => array(
        '1x' => 'col_4_xs',
        '2x' => 'col_4_xs_2x',
      ),
      'breakpoints.theme.cr_layout_v2.sm' => array(
        '1x' => 'col_9_sm',
        '2x' => 'col_9_sm_2x',
      ),
      'breakpoints.theme.cr_layout_v2.md' => array(
        '1x' => 'col_9_md',
        '2x' => 'col_9_md_2x',
      ),
      'breakpoints.theme.cr_layout_v2.lg' => array(
        '1x' => 'col_9_lg',
        '2x' => 'col_9_lg_2x',
      ),
    ),
    'region_2' => array(
      'breakpoints.theme.cr_layout_v2.xs' => array(
        '1x' => 'col_4_xs',
        '2x' => 'col_4_xs_2x',
      ),
      'breakpoints.theme.cr_layout_v2.sm' => array(
        '1x' => 'col_3_sm',
        '2x' => 'col_3_sm_2x',
      ),
      'breakpoints.theme.cr_layout_v2.md' => array(
        '1x' => 'col_3_md',
        '2x' => 'col_3_md_2x',
      ),
      'breakpoints.theme.cr_layout_v2.lg' => array(
        '1x' => 'col_3_lg',
        '2x' => 'col_3_lg_2x',
      ),
    ),
    'region_3' => array(
      'breakpoints.theme.cr_layout_v2.xs' => array(
        '1x' => 'col_4_xs',
        '2x' => 'col_4_xs_2x',
      ),
      'breakpoints.theme.cr_layout_v2.sm' => array(
        '1x' => 'col_3_sm',
        '2x' => 'col_3_sm_2x',
      ),
      'breakpoints.theme.cr_layout_v2.md' => array(
        '1x' => 'col_3_md',
        '2x' => 'col_3_md_2x',
      ),
      'breakpoints.theme.cr_layout_v2.lg' => array(
        '1x' => 'col_3_lg',
        '2x' => 'col_3_lg_2x',
      ),
    ),
    'region_4' => array(
      'breakpoints.theme.cr_layout_v2.xs' => array(
        '1x' => 'col_4_xs',
        '2x' => 'col_4_xs_2x',
      ),
      'breakpoints.theme.cr_layout_v2.sm' => array(
        '1x' => 'col_6_sm',
        '2x' => 'col_6_sm_2x',
      ),
      'breakpoints.theme.cr_layout_v2.md' => array(
        '1x' => 'col_6_md',
        '2x' => 'col_6_md_2x',
      ),
      'breakpoints.theme.cr_layout_v2.lg' => array(
        '1x' => 'col_6_lg',
        '2x' => 'col_6_lg_2x',
      ),
    ),
    'region_5' => array(
      'breakpoints.theme.cr_layout_v2.xs' => array(
        '1x' => 'col_4_xs',
        '2x' => 'col_4_xs_2x',
      ),
      'breakpoints.theme.cr_layout_v2.sm' => array(
        '1x' => 'col_6_sm',
        '2x' => 'col_6_sm_2x',
      ),
      'breakpoints.theme.cr_layout_v2.md' => array(
        '1x' => 'col_6_md',
        '2x' => 'col_6_md_2x',
      ),
      'breakpoints.theme.cr_layout_v2.lg' => array(
        '1x' => 'col_6_lg',
        '2x' => 'col_6_lg_2x',
      ),
    ),
    'region_6' => array(
      'breakpoints.theme.cr_layout_v2.xs' => array(
        '1x' => 'col_4_xs',
        '2x' => 'col_4_xs_2x',
      ),
      'breakpoints.theme.cr_layout_v2.sm' => array(
        '1x' => 'col_6_sm',
        '2x' => 'col_6_sm_2x',
      ),
      'breakpoints.theme.cr_layout_v2.md' => array(
        '1x' => 'col_6_md',
        '2x' => 'col_6_md_2x',
      ),
      'breakpoints.theme.cr_layout_v2.lg' => array(
        '1x' => 'col_6_lg',
        '2x' => 'col_6_lg_2x',
      ),
    ),
    'region_7' => array(
      'breakpoints.theme.cr_layout_v2.xs' => array(
        '1x' => 'col_4_xs',
        '2x' => 'col_4_xs_2x',
      ),
      'breakpoints.theme.cr_layout_v2.sm' => array(
        '1x' => 'col_4_sm',
        '2x' => 'col_4_sm_2x',
      ),
      'breakpoints.theme.cr_layout_v2.md' => array(
        '1x' => 'col_4_md',
        '2x' => 'col_4_md_2x',
      ),
      'breakpoints.theme.cr_layout_v2.lg' => array(
        '1x' => 'col_4_lg',
        '2x' => 'col_4_lg_2x',
      ),
    ),
    'region_8' => array(
      'breakpoints.theme.cr_layout_v2.xs' => array(
        '1x' => 'col_4_xs',
        '2x' => 'col_4_xs_2x',
      ),
      'breakpoints.theme.cr_layout_v2.sm' => array(
        '1x' => 'col_4_sm',
        '2x' => 'col_4_sm_2x',
      ),
      'breakpoints.theme.cr_layout_v2.md' => array(
        '1x' => 'col_4_md',
        '2x' => 'col_4_md_2x',
      ),
      'breakpoints.theme.cr_layout_v2.lg' => array(
        '1x' => 'col_4_lg',
        '2x' => 'col_4_lg_2x',
      ),
    ),
    'region_9' => array(
      'breakpoints.theme.cr_layout_v2.xs' => array(
        '1x' => 'col_4_xs',
        '2x' => 'col_4_xs_2x',
      ),
      'breakpoints.theme.cr_layout_v2.sm' => array(
        '1x' => 'col_4_sm',
        '2x' => 'col_4_sm_2x',
      ),
      'breakpoints.theme.cr_layout_v2.md' => array(
        '1x' => 'col_4_md',
        '2x' => 'col_4_md_2x',
      ),
      'breakpoints.theme.cr_layout_v2.lg' => array(
        '1x' => 'col_4_lg',
        '2x' => 'col_4_lg_2x',
      ),
    ),
  ),
);

/**
 * Implements hook_preprocess_rnd15_site_media_wall_template_1().
 */
function template_preprocess_rnd15_site_media_wall_template_1(&$variables) {
  $variables['attributes_array']['class'][] = 'media-wall';
  $variables['attributes_array']['class'][] = 'media-wall--template-1';
}