<?php

/**
 * @file
 * Defines a simple 12 row layout.
 * Documentation: http://wiki.comicrelief.com/wiki/CR_Layout_V2
 * Author: Jeremy P.
 */

// Plugin definition.
$plugin = array(
  'title' => t('CR Content'),
  'icon' => 'preview.png',
  'category' => t('CR Content Layouts'),
  'theme' => 'cr_content_panel',
  'regions' => array(
    'first' => t('First'),
    'second' => t('Second'),
    'third' => t('Third'),
    'fourth' => t('Fourth'),
    'fifth' => t('Fifth'),
    'sixth' => t('Sixth'),
    'seven' => t('Seventh'),
    'eight' => t('Eighth'),
    'ninth' => t('Ninth'),
    'tenth' => t('Tenth'),
    'eleventh' => t('Eleventh'),
    'twelfth' => t('Twelfth'), 
  ),
);

/**
 * Implements hook_preprocess_cr_content().
 */
function template_preprocess_cr_content_panel(&$variables) {
  $variables['attributes_array']['class'][] = 'cr-content';
  $variables['attributes_array']['class'][] = 'cr-content--rows';

  foreach($variables['content'] as $name => $item) {
    $variables['region_attributes_array'][$name]['class'][] = 'cr-content-region';
    $variables['region_attributes_array'][$name]['class'][] = 'cr-content-region--' . drupal_clean_css_identifier($name);
  }
}
