<?php
/**
 * @file
 * All custom code of the rnd15 Site Gift Aid Feature
 */

/**
 * Preprocess gift aid form
 * Implements hook_preprocess_HOOK(&$variables)
 */

function rnd15_giftaid_preprocess_cr_donate_giftaid_form(&$vars) {

  /**
   * Gift Aid top section
   */
  $vars['form']['main']['#title'] = '';
  $vars['form']['main']['#theme_wrappers'] = array();
  $vars['form']['main']['phone']['#title'] = '';
  $vars['form']['main']['donate-giftaid']['#title'] = '';
  $vars['form']['main']['donate-giftaid']['#theme_wrappers'] = array();

  /**
   * Gift Aid billing section
   */
  $vars['form']['billing']['#description'] = '';
  $vars['form']['billing']['#theme_wrappers'] = array();


}