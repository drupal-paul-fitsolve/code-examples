<?php
/**
 * @file
 * sr14_ideas_and_tools.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sr14_ideas_and_tools_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
