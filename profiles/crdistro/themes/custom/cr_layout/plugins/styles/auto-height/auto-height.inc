<?php

/**
 * @file
 * Definition of the 'Equal Heights Element' panel style.
*/

// Plugin definition
$plugin = array(
  'title' => t('Auto Height '),
  'description' => t('Sets the equal height element class'),
  'render region' => 'cr_layout_auto_height_region_render_region',
  'settings form' => 'cr_layout_auto_height_region_settings',
);

/**
 * Settings form
 */
function cr_layout_auto_height_region_settings($style) {
  $classes = array(
    'auto-height__6040' => t('60% - 40%'),
    'auto-height__4060' => t('40% - 60%'),
    'auto-height__100' => t('100% Single Panel'),
  );

  $form = array();
  //Generate checkboxes from classes array
  foreach ($classes as $class => $title) {
    $form['autoheight'][$class] = array(
      '#title' => $title,
      '#type' => 'checkbox',
      '#default_value' => (int)($style['autoheight'][$class] == 1),
    );
  }
  $form['help'] = array(
    '#markup' => t('<p>For auto height to work correctly please ensure the panels in this region have a semantic wrapper assigned to them. It needs to be an DIV Wrapper and you can add the default classes or any extra ones.</p>'),
  );
  return $form;
}



/**
 * Render callback for a region
 * @ingroup themeable
 */

function theme_cr_layout_auto_height_region_render_region($vars) {

  $autoheightclasses = '';
  $loadautoheight = false;
  if(isset($vars['settings'])) {
    foreach($vars['settings']['autoheight'] as $class => $enabled) {
      if($enabled) {
        $autoheightclasses .= $class.' ';
        $loadautoheight = true;
      }
    }
  }
  if($loadautoheight) {
    $autoheightclasses .= 'autoheight-run';
    // This JS should be present sitewide as mediabar can be used sidewide without this
    // plugin. EG nodepages cant use region plugins so theres no way to include JS below.
    //drupal_add_js($vars['style']['path'] . '/auto-height.js');
    //drupal_add_js(array('cr_auto_height' => array('autoheightselector' => '.autoheight-run')), 'setting');
  }
  $output = '';
  $output .= '<div class="region region-' . $vars['region_id'] . ' '.$autoheightclasses.'">';
  $output .= implode('', $vars['panes']);
  $output .= '</div>';
  return $output;
}