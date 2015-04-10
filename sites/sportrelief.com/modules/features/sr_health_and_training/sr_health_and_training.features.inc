<?php
/**
 * @file
 * sr_health_and_training.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sr_health_and_training_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
