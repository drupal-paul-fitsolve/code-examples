<?php
/**
 * @file
 * disable_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function disable_search_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
