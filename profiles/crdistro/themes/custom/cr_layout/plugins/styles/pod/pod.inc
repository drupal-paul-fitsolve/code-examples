<?php

// Plugin definition.
$plugin = array(
  'title' => t('Pod Styles'),
  'description' => t('Sets the style for a pod'),
  'render region' => 'panels_pod_render_region',
  'settings form' => 'panels_pod_region_settings',
  'hook theme' => array(
    'panels_pod' => array(
      'template' => 'panels-pod',
      'path' => drupal_get_path('theme', 'cr_layout') . '/plugins/styles/pod',
      'variables' => array('pane_content' => NULL, 'region_classes' => 'pod'),
    ),
  ),
);

/**
 * Renderer for the region
 */
function theme_panels_pod_render_region($vars) {
  $classes = array(
    'pod',
    'clearfix',
  );


  // @TODO This shouldn't assume every setting is a class
  foreach ($vars['settings'] as $class => $enabled) {
    if ($enabled === 1) {
      $classes[] = 'pod--' . $class;
      if($class == 'content-media-player') {
        if (($library = libraries_load('flexslider')) && !empty($library['loaded'])) {
          // Do something with the library here.
        }
        drupal_add_js(drupal_get_path('theme', 'cr_layout') .'/js/components/content-media-player.js', 'file');
        drupal_add_js(drupal_get_path('theme', 'sport_relief') .'/javascripts/vendor/audiojs/audio.min.js', 'file');
      }
      if($class == 'star-fundraiser') {
        $vars['panes']['span'] = '<span class="star-fundraiser-cover"></span>';
      }
    }
  }
  if(!empty($vars['settings']['extraClasses'])) {
    $content = ' ' . $vars['settings']['extraClasses'];
    $classes[] .= $content;
  }

  $pane_content = '';
  foreach ($vars['panes'] as $pane_id => $pane) {
    $pane_content .= $pane;
  }

  return theme('panels_pod', array('pane_content' => $pane_content, 'region_classes' => implode(' ', $classes)));
}

/**
 * Settings form
 * Example:
 *  New classes can be easily added by simply adding
 *  to the classes array
 *  The varation gets appended with:
 *    pod--
 */
function panels_pod_region_settings($style) {
  $classes = array (
    'padding' => t('Padding'),
    'dark' => t('Dark background, light text'),
    'light-grey' => t('Light grey background'),
    'content-media-player' => t('Content Media Player'),
    'action-pod' => t('Action Pod'),
    'star-fundraiser' => t ('Star Fundraiser'),
  );

  $form = array();

  //Generate checkboxes from classes array
  foreach ($classes as $class => $title) {
    $form[$class] = array(
      '#title' => $title,
      '#type' => 'checkbox',
      '#default_value' => (int)($style[$class] == 1),
    );
  }
  $extra_classes_default_value = isset($style['extraClasses']) ? $style['extraClasses'] : '';
  $form['extraClasses'] = array(
    '#title' => 'Extra Classes',
    '#description' => 'Drop any classes you want in here.',
    '#type' => 'textfield',
    '#default_value' => $extra_classes_default_value,
  );
  return $form;
}
