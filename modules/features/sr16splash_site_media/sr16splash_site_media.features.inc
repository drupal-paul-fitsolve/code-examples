<?php
/**
 * @file
 * sr16splash_site_media.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sr16splash_site_media_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
