<?php
/**
 * @file
 * All custom code of the RND15 Site Header ESU Feature
 */

/**
 * Preprocess the cr marketing prefs form (ESU Header)
 * Implements hook_preprocess_HOOK(&$variables)
 */
function rnd15_site_header_esu_preprocess_cr_marketing_prefs_header_form(&$vars) {

  // Hide honey pot fields
  if (isset($vars['form']['comment_explanation'])) {
    $vars['form']['comment_explanation']['#markup'] = '<div class="element-invisible">' . $vars['form']['comment_explanation']['#markup'] . '</div>';
  }
  if (isset($vars['form']['comment'])) {
    $vars['form']['comment']['#attributes']['class'][] = 'element-invisible';
    $vars['form']['comment']['#prefix'] = '<div class="element-invisible">';
    $vars['form']['comment']['#suffix'] = '</div>';
  }
  
  // Add class to submit btn so it's style nicely
  $vars['form']['submit']['#attributes']['class'] = array('btn btn-grey');

  // Override the default option
  // if(isset($vars['form']['phase']) && isset($vars['form']['phase']['#options'])) {
  //   $vars['form']['phase']['#options'][0] = t('Choose an age group');
  // }
}

/**
 * Preprocess the cr marketing prefs block (ESU Header)
 * Implements hook_preprocess_HOOK(&$variables)
 */
function rnd15_site_header_esu_preprocess_block(&$variables) {
  // Only affect the prefs esu header
  if($variables['block']->bid === 'cr_marketing_prefs-esu_header') {
    // Prepare close link options
    $close_link_options = array(
      'html' => TRUE,
      'fragment' => 'esu-header',
      'attributes' => array(
        'title' => t('Close the Email Signup.'),
        'id' => 'esu-header__close', 
        'class' => array(
          'esu-header__close',
          'icon',
          'icon-cross',
          'icon--large'
        )
      )
    );

    // Create the close link
    $close_link = l('<span class="esu-header__close-text">Close</span>','', $close_link_options);

    // String replace the link as we don't have other access to it
    $variables['content'] = str_replace('<a href="#" class="close-button">X</a>', '', $variables['content']);
    $variables['close_button'] = $close_link;

    // Content Attributes
    $variables['content_attributes_array']['class'] = array('esu-header__content');

    // Classes
    $variables['classes_array'] = array('esu-header');
  }
}