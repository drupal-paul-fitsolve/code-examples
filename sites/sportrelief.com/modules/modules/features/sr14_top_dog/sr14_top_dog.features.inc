<?php
/**
 * @file
 * sr14_top_dog.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sr14_top_dog_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
