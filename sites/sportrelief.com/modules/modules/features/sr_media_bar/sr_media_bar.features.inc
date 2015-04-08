<?php
/**
 * @file
 * sr_media_bar.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sr_media_bar_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function sr_media_bar_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function sr_media_bar_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: media_bar_default_queue
  $nodequeues['media_bar_default_queue'] = array(
    'name' => 'media_bar_default_queue',
    'title' => 'Media Bar Default Queue',
    'subqueue_title' => '',
    'size' => 2,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 1,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'media_images',
      1 => 'news_article',
      2 => 'video',
    ),
    'roles' => array(
      0 => 'content editor',
      1 => 'digital pm',
      2 => 'marketing (general)',
    ),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_node_info().
 */
function sr_media_bar_node_info() {
  $items = array(
    'tweet' => array(
      'name' => t('Tweet'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
