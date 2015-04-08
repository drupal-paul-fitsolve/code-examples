<?php
/**
 * @file
 * sr_media_wall_images.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sr_media_wall_images_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "1");
  }
}
