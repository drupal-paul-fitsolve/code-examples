<?php
/**
 * @file
 * cr_news.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cr_news_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_news_article';
  $strongarm->value = 'edit-menu';
  $export['additional_settings__active_tab_news_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_classes_fields';
  $strongarm->value = '';
  $export['ds_classes_fields'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_classes_regions';
  $strongarm->value = 'pod|Pod
pod--article|Pod article
colorbox-container
colorbox--top
colorbox--bottom
alpha
omega
container-24
grid-1|Grid 1
grid-2|Grid 2
grid-3|Grid 3
grid-4|Grid 4
grid-5|Grid 5
grid-6|Grid 6
grid-7|Grid 7
grid-8|Grid 8
grid-9|Grid 9
grid-10|Grid 10
grid-11|Grid 11
grid-12|Grid 12
grid-13|Grid 13
grid-14|Grid 14
grid-15|Grid 15
grid-16|Grid 16
grid-17|Grid 17
grid-18|Grid 18
grid-19|Grid 19
grid-20|Grid 20
grid-21|Grid 21
grid-22|Grid 22
grid-23|Grid 23
grid-24|Grid 24';
  $export['ds_classes_regions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__news_article';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'downloadable' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'node_embed' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'panel_grid_6' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'media_bar' => array(
        'custom_settings' => TRUE,
      ),
      'colorbox' => array(
        'custom_settings' => TRUE,
      ),
      'full_content_no_social' => array(
        'custom_settings' => TRUE,
      ),
      'colorbox_no_social' => array(
        'custom_settings' => FALSE,
      ),
      'grid_12_promo_node' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '9',
        ),
        'path' => array(
          'weight' => '8',
        ),
        'xmlsitemap' => array(
          'weight' => '7',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__news_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_news_article';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_news_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_news_article';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_news_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_news_article';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_news_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_news_article';
  $strongarm->value = '1';
  $export['node_preview_news_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_news_article';
  $strongarm->value = 0;
  $export['node_submitted_news_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_article_pattern';
  $strongarm->value = 'news/[node:title]';
  $export['pathauto_node_news_article_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_news_article';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_news_article'] = $strongarm;

  return $export;
}
