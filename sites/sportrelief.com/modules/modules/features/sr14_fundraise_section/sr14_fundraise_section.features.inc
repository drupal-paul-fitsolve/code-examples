<?php
/**
 * @file
 * sr14_fundraise_section.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sr14_fundraise_section_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
