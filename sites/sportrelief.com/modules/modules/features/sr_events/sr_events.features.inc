<?php
/**
 * @file
 * sr_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sr_events_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
}
