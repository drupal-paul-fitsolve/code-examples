<?php
/**
 * @file
 * Definition of the 'Slideshow' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Slideshow'),
  'description' => t('Show panel panes in a region as a slideshow.'),
  'render region' => 'sr16splash_site_slideshows_style_render_region',
  'settings form' => 'sr16splash_site_slideshows_style_render_region_settings_form',
);

/**
 * Render callback.
 *
 */
function theme_sr16splash_site_slideshows_style_render_region($vars) {
  $panes = $vars['panes'];
  if(!$panes) { return; }

  // return true if single display layout
  $singleLayout = ($vars['display']->layout == 'sr16splash_site_slideshows_layout_single') ? 1 : 0; 

  // render through all panes, prepare content for drupal_render
  $delta = 0;
  foreach ($panes as $pane_id => $item) {
    $element[$pane_id] = array(
      '#markup' => $item,
    );
    ++$delta;
  }

  // preprocess panes to list item on single layout 
  // muiltiple layout will be preprocess on template_preprocess function 
  if($singleLayout) {
    return theme_item_list(array(
      'items' => $panes, 
      'title' => '', 
      'type' => 'ul', 
      'attributes' => array('
        class'=>'slides'
        )
      )
    );
  } else {
    return drupal_render($element);
  }

}

/**
 * Region settings form callback.
 */
function sr16splash_site_slideshows_style_render_region_settings_form($style_settings) {
  // Style plugin settings

  // The Flexslider Option Set
  // Load the list of option sets
  $optionsets = flexslider_optionset_load_all();
  // Parse out into key/value pairs
  foreach ($optionsets as $key => $optionset) {
    $options[$key] = $optionset->title;
  }
  // Optionset - add a select field
  $optionset_default_value = isset($style_settings['optionset']) ? $style_settings['optionset'] : 'default';
  $form['optionset'] = array(
    '#type' => 'select',
    '#title' => t('FlexSlider Option Set'),
    '#multiple' => FALSE,
    '#options' => $options,
    '#default_value' => $optionset_default_value,
    '#description' => t('Select a configured option set to use with Flex Slider, or create one ') . l('here', 'admin/config/media/flexslider/add'),
  );

  // View Modes of Fieldable Panel Pane - add a select field
  $entity_info = entity_get_info('fieldable_panels_pane');
  foreach ($entity_info['view modes'] as $id => $config)
  {   // push label value back to array key, so it displays label on dropdown options 
      $entity_info['view modes'][$id] = $entity_info['view modes'][$id]['label'];
  }
  $view_mode_default_value = isset($style_settings['view_mode']) ? $style_settings['view_mode'] : '';
  $form['view_mode'] = array(
    '#type' => 'select',
    '#title' => t('View Modes of Panes'),
    '#multiple' => FALSE,
    '#options' => $entity_info['view modes'],
    '#default_value' => $view_mode_default_value,
    '#description' => t('Set view modes of all fieldable panes'),
  );

  // Pager set - add a select field
  $pager_default_value = isset($style_settings['pager']) ? $style_settings['pager'] : 0;
  $form['pager'] = array(
    '#type' => 'select',
    '#title' => t('Slideshow pager color set'),
    '#multiple' => FALSE,
    '#options' => array(
      0 => t('White'),
      1 => t('Black'),
    ),
    '#default_value' => $pager_default_value,
  ); 

  // Pager set - add a select field
  $pager_overlay_default = isset($style_settings['pager_overlay']) ? $style_settings['pager_overlay'] : 1;
  $form['pager_overlay'] = array(
    '#type' => 'select',
    '#title' => t('Pager Overlay'),
    '#description' => 'Defines on which breakpoints the pager is over the slideshow content.',
    '#multiple' => FALSE,
    '#options' => array(
      0 => t('No Overlay'),
      1 => t('Overlay on MD/LG'),
    ),
    '#default_value' => $pager_overlay_default,
  );

  // Extra classes - this output same level of flexslider wrapper
  $extra_classes_default_value = isset($style_settings['extraClasses']) ? $style_settings['extraClasses'] : '';
  $form['extraClasses'] = array(
    '#title' => 'Extra Classes',
    '#description' => 'Drop any classes you want in here, this class applies to the same level of flexslider wrapper',
    '#type' => 'textfield',
    '#default_value' => $extra_classes_default_value,
  );

  return $form;
}
