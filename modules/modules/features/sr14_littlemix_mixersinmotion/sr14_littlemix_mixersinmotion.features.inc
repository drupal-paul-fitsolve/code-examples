<?php
/**
 * @file
 * sr14_littlemix_mixersinmotion.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sr14_littlemix_mixersinmotion_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
