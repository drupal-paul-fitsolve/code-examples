<?php
/**
 * @file
 * sr_fundraising_pay_in_form.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sr_fundraising_pay_in_form_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
