<?php
/**
 * @file
 * sr16splash_otn_banner.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sr16splash_otn_banner_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
