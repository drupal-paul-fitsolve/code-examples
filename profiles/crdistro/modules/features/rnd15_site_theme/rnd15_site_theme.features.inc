<?php
/**
 * @file
 * rnd15_site_theme.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function rnd15_site_theme_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}