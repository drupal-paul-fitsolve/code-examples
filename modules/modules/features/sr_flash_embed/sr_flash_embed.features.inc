<?php
/**
 * @file
 * sr_flash_embed.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sr_flash_embed_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
