<?php
// Plugin definition.
$plugin = array(
  'title' => t('Image Styles'),
  'description' => t('Sets the style for an image'),
  'render region' => '',
  'render pane' => 'cr_layout_image_render_pane',
  //'settings form' => 'cr_layout_image_theme_settings',
  'pane settings form' => 'cr_layout_image_pane_settings',
);

/**
 * Render callback for a single pane.
 */
function theme_cr_layout_image_render_pane($vars) {
  $content = $vars['content'];
  if (empty($content->content)) {
    return;
  }

  if(isset($vars['settings'])) {
    foreach($vars['settings']['rounded'] as $class => $enabled) {
      if($enabled)
        $vars['content']->css_class .= ' image-'.$class;
    }
  }

  $output = theme('panels_pane', $vars);
  return $output;
}

/**
 * Settings form
 * Example:
 *  New classes can be easily added by simply adding
 *  to the classes array
 *  The varation gets appended with:
 *    image-
 */
function cr_layout_image_pane_settings($style) {
  $radius_classes = array(
    'rounded__top' => t('Rounded Top'),
    'rounded__bottom' => t('Rounded Bottom'),
    'rounded__left' => t('Rounded Left'),
    'rounded__right' => t('Rounded Right'),
    'rounded__all' => t('Rounded All'),
  );

  $form = array();
  //Generate checkboxes from classes array
  foreach ($radius_classes as $class => $title) {
    $form['rounded'][$class] = array(
      '#title' => $title,
      '#type' => 'checkbox',
      '#default_value' => (int)($style['rounded'][$class] == 1),
    );
  }
  return $form;
}

function cr_layout_image_theme_settings($default_value = FALSE) {
  $options['theme'] = array(
    '#type' => 'checkbox',
    '#title' => t('Additionally, wrap the content with Panels theming layer.'),
    '#default_value' => $default_value,
  );

  return $options;
}