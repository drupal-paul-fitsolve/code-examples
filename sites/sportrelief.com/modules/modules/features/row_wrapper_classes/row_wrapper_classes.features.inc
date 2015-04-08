<?php
/**
 * @file
 * row_wrapper_classes.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function row_wrapper_classes_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
