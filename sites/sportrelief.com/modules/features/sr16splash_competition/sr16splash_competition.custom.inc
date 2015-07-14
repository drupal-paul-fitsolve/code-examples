<?php
/**
 * @file
 * All custom code of the sr16splash Site Header ESU Feature
 */

/**
 * Preprocess the cr marketing prefs form (ESU Header)
 * Implements hook_preprocess_HOOK(&$variables)
 */
function sr16splash_competition_preprocess_cr_competition_form(&$vars) {
  /**
   * Hide honey pot fields
   */
  $vars['form']['feedback']['#attributes']['class'][] = 'element-invisible';

  /**
   * Make cancel button grey
   */
  $vars['form']['cancel']['#attributes']['class'][] = 'btn';
  $vars['form']['cancel']['#attributes']['class'][] = 'btn-grey';
  

  /**
   * Wrap both two main buttons and make them inline
   */
  $vars['form']['cancel']['#prefix'] = '<div class="form-item form-item--inline"><p>';
  $vars['form']['submit']['#suffix'] = '</p></div>';

  /**
   * Submit button text
   */
  $vars['form']['submit']['#value'] = t('Submit your entry');

  /**
   * Add grey inline link class to T&Cs
   */
  $vars['form']['competition']['terms']['#title'] = t('I have read and accepted the <a href="/legal#/golden-nose-tcs/golden-nose-tcs" target="_blank" class="link--inline-grey" title="The Who Nose Terms and Conditions">terms and conditions</a>');

  /**
   * Email Permission Title
   */
  $vars['form']['competition_email']['permission_email']['#title'] =
    t('Would you like to be kept informed by email about what Comic Relief\'s up to?');
}