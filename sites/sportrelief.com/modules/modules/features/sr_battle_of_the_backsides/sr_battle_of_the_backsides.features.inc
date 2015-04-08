<?php
/**
 * @file
 * sr_battle_of_the_backsides.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sr_battle_of_the_backsides_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
