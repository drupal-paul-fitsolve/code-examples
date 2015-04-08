<?php
/**
 * @file
 * images_promo.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function images_promo_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "1");
  }
}
