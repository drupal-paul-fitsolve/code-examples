<?php
/**
 * @file
 * sr14_no_social.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sr14_no_social_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
