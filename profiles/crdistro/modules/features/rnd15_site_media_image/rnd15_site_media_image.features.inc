<?php
/**
 * @file
 * rnd15_site_media_image.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function rnd15_site_media_image_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function rnd15_site_media_image_node_info() {
  $items = array(
    'media_image' => array(
      'name' => t('Media image'),
      'base' => 'node_content',
      'description' => t('Use \'Media image\' for a standard image. Supports titles, images, body copy, and media tags.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
