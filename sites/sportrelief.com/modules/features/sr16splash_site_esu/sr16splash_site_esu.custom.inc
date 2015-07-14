<?php
/**
 * @file
 * All custom code of the sr16splash Site ESU Feature
 */

/**
 * Implements hook_preprocess_HOOK(&$variables)
 */
function sr16splash_site_esu_preprocess_cr_marketing_prefs_promo_form(&$vars) {
  // Add class to submit button
  $vars['form']['submit']['#attributes']['class'] = array('btn btn-grey');
}
