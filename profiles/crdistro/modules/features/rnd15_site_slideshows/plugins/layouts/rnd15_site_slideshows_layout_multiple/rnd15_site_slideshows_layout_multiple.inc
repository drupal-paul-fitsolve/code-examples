<?php
/**
 * @file
 * Code for Panels Layout Plugin - Multiple Layout
 */

/**
 * Implements hook_panels_layouts().
 */
function rnd15_site_slideshows_rnd15_site_slideshows_layout_multiple_panels_layouts() {
  $items['rnd15_site_slideshows_layout_multiple'] = array(
    'title' => t('Multiple Pane Slides'),
    'category' => t('Slideshow Layouts'),
    'icon' => 'rnd15_site_slideshows_layout_multiple.png',
    'theme' => 'rnd15_site_slideshows_layout_multiple',
    'regions' => array(
    'first' => t('First slide'),
    'second' => t('Second slide'),
    'third' => t('Third slide'),
    'fourth' => t('Fourth slide'),
    'fifth' => t('Fifth slide'),
    ),
  );  
  return $items;
}

/**
 * Preprocess function for rnd15_site_slideshows_layout_multiple.tpl.php
 */
function template_preprocess_rnd15_site_slideshows_layout_multiple(&$vars) {
  
  // Declare variables
  $is_admin = $vars['renderer']->admin;
  $contents = &$vars['content'];
  
  // Extra classes
  $extra_classes_str = isset($vars['display']->panel_settings['style_settings']['default']['extraClasses']) ? $vars['display']->panel_settings['style_settings']['default']['extraClasses'] : '';
  $extra_classes = explode(' ', $extra_classes_str);
 
  // Pager set 
  if((isset($vars['display']->panel_settings['style_settings']['default']['pager']) && $vars['display']->panel_settings['style_settings']['default']['pager'] == 1)) {
    $extra_classes[] = 'slideshow--pager-black';
  }

  // Pager Overlay
  if(isset($vars['display']->panel_settings['style_settings']['default']['pager_overlay'])) {
    switch ($vars['display']->panel_settings['style_settings']['default']['pager_overlay']) {
      case 0:

      break;
      case 1:
        $extra_classes[] = 'slideshow--pager-overlay-md';
      break;
    }
  } else {
    $extra_classes[] = 'slideshow--pager-overlay-md';
  }
 
  // Optionset
  $optionset = isset($vars['display']->panel_settings['style_settings']['default']['optionset']) ? $vars['display']->panel_settings['style_settings']['default']['optionset'] : null;
  $options = flexslider_optionset_load($optionset);
  $options_name = isset($options->name)? $options->name: null; 
  $options_options = isset($options->options)? $options->options: null; 

  // Create uniqle id for each flexslider
  $unique_id = 'flexslider-rnd15_site_slideshows-' . time() . '-' . rand(0, 100);

  // Create container, associtate with Flexsilder Id and extra class from setting form        
  $element['slideshow'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => $unique_id,
      'class' => array(
        'flexslider',
        'slideshow',
        'slideshow__wrapper'
        ),
      ),
    'slidehow_content' => array(
      'type' => 'markup',
      // Attach JS settings, include Instances and Optionset
      '#attached' => array(
        'js' => array(
          drupal_get_path('module', 'rnd15_site_slideshows') . '/js/rnd15_site_slideshows.min.js' => array('type' => 'file'), /* attach preload images js */
          array(
            'type' => 'setting',
            'data' => array('flexslider' => array(
              'optionsets' => array(
                $options_name => $options_options,
              ),
              'instances' => array(
                $unique_id => $options_name,
              ),
            )),
          ),
        ),
      ),
    ),
  );

  // Add the extra classes
  $element['slideshow']['#attributes']['class'] = array_merge($element['slideshow']['#attributes']['class'], $extra_classes);

  $output = '';
  // Loop through contents, assign content to array
  $delta = 0;
  foreach ($contents as $region_id => $item) {
    $output .= $item;
    ++$delta;
  }

  $element['slideshow']['slidehow_content']['#markup'] = theme_item_list(array(
    'items' => array_filter($contents, 'strlen'), 
    'title' => '', 
    'type' => 'ul', 
    'attributes' => array('
      class'=>' slides'
      )
    )
  );   

  $contents = array(
        '#markup' => $output,
  );

  // Only add slideshows to node display page 
  if(isset($is_admin) && $is_admin != '1') { 
    // Call flexlider_add function, so we don't have to attach extra flexsider JS 
     flexslider_add($unique_id, $optionset);
     // Push array for contents
     $contents = array(
        '#markup' => drupal_render($element),
      );   
  } 
}
