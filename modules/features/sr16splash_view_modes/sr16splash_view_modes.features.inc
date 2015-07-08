<?php
/**
 * @file
 * sr16splash_view_modes.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sr16splash_view_modes_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}
