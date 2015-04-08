<?php
/**
 * @file
 * sr_play_games_landing_body_class.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sr_play_games_landing_body_class_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
