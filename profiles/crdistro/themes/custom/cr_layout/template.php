<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 *
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */


/**
 * Implements hook_preprocess_zone().
 */
function cr_layout_preprocess_zone(&$vars){
  if(module_exists('devel') && isset($vars['attributes_array']['id'])) {
    $vars['attributes_array']['data-themers-helper'][] = $vars['attributes_array']['id'];
    $vars['content_attributes_array']['data-themers-helper'][] = $vars['content_attributes_array']['id'];
  }
  $vars['attributes_array']['class'] = array_values(array_diff($vars['attributes_array']['class'],array('zone-wrapper','clearfix')));
  $vars['attributes_array']['class'] = preg_grep('/^zone-/', $vars['attributes_array']['class'], PREG_GREP_INVERT);
  unset($vars['attributes_array']['id']);
  $vars['content_attributes_array']['class'] = array_values(array_diff($vars['attributes_array']['class'],array('zone','clearfix')));
  $vars['content_attributes_array']['class'] = preg_grep('/^zone-/', $vars['content_attributes_array']['class'], PREG_GREP_INVERT);
  unset($vars['content_attributes_array']['id']);
}

/*
**
 * Small bug fix for DS expert mode, do not print the wrapper if the field is empty. https://drupal.org/node/2043913
 */
function cr_layout_theme_ds_field_expert($variables) {
   $output = '';
   $config = $variables['ds-config'];
  // Render the label if it's not hidden.
  if (!$variables['label_hidden']) {
    $label_wrapper = isset($config['lb-el']) ? $config['lb-el'] : 'div';
    $class = array('label-' . $variables['element']['#label_display']);
    if (!empty($config['lb-cl'])) $class[] = $config['lb-cl'];
    $class = !empty($class) ? ' class="' . implode(' ', $class) . '"' : '';
    $attributes = array();
    if (!empty($config['lb-at'])) $attributes[] = $config['lb-at'];
    if (!empty($config['lb-def-at'])) $attributes[] = $variables['title_attributes'];
    $attributes = (!empty($attributes)) ? ' ' . implode(' ', $attributes) : '';
    $output .= '<' . $label_wrapper . $class . $attributes . '>' . $variables['label'];
    if (!isset($config['lb-col'])) $output .= ':&nbsp;';
    $output .= '</' . $label_wrapper . '>';
  }

  // Field items wrapper
  if (isset($config['fis'])) {
    $class = (!empty($config['fis-cl'])) ? ' class="' . $config['fis-cl'] . '"' : '';
    $attributes = array();
    if (!empty($config['fis-at'])) $attributes[] = $config['fis-at'];
    if (!empty($config['fis-def-at'])) $attributes[] = $variables['content_attributes'];
    $attributes = (!empty($attributes)) ? ' ' . implode(' ', $attributes) : '';
    $output .= '<' . $config['fis-el'] . $class . $attributes . '>';
  }

  // Render items.
  foreach ($variables['items'] as $delta => $item) {

   // Header attribute
   if (!empty($config['fi-cl']) && $config['fi-cl'] == 'pod__title') {
    if(isset($variables['items'][0]['#header_attributes'])) {
      $config['fi-el'] = $variables['items'][0]['#header_attributes'];
    }
   }

    if(!empty($item['#markup'])) {
      // Field item wrapper.
      if (isset($config['fi'])) {
        $class = array();
        if (!empty($config['fi-odd-even'])) {
          $class[] = $delta % 2 ? 'odd' : 'even';
        }
        if (!empty($config['fi-cl'])) {
          $class[] = $config['fi-cl'];
        }
        $class = !empty($class) ? ' class="'. implode(' ', $class)  .'"' : '';
        $attributes = array();
        if (!empty($config['fi-at'])) {
          $attributes[] = token_replace($config['fi-at'], array($variables['element']['#entity_type'] => $variables['element']['#object']), array('clear' => TRUE));
        }
        if (!empty($config['fi-def-at'])) {
          $attributes[] = $variables['item_attributes'][$delta];
        }
        $attributes = (!empty($attributes)) ? ' ' . implode(' ', $attributes) : '';
        $output .= '<' . $config['fi-el'] . $class . $attributes .'>';
      }

      // Render field content.
      $output .= drupal_render($item);

      // Closing field item wrapper.
      if (isset($config['fi'])) {
        $output .= '</' . $config['fi-el'] . '>';
      }
    }

    // Closing field items wrapper.
    if (isset($config['fis'])) {
      $output .= '</' . $config['fis-el'] . '>';
    }
  }

  // Outer wrapper.
  if (isset($config['ow'])) {
    $class = array();
    if (!empty($config['ow-cl'])) $class[] = $config['ow-cl'];
    if (!empty($config['ow-def-cl'])) $class[] = $variables['classes'];
    $class = (!empty($class)) ? ' class="' . implode(' ', $class) . '"' : '';
    $attributes = array();
    if (!empty($config['ow-at'])) $attributes[] = $config['ow-at'];
    if (!empty($config['ow-def-at'])) $attributes[] = $variables['attributes'];
    $attributes = (!empty($attributes)) ? ' ' . implode(' ', $attributes) : '';
    $output = '<' . $config['ow-el'] . $class . $attributes . '>' . $output . '</' . $config['ow-el'] . '>';
  }

  return $output;
}

/**
 * Implements hook_preprocess_region().
 */
function cr_layout_alpha_preprocess_region(&$vars){
  if(module_exists('devel')) {
    $vars['attributes_array']['data-themers-helper'] = $vars['attributes_array']['id'];
  }
  $vars['attributes_array']['class'] = array_values(array_diff($vars['attributes_array']['class'],array('region')));
  $vars['attributes_array']['class'] = preg_grep('/region-/', $vars['attributes_array']['class'], PREG_GREP_INVERT);
  unset($vars['attributes_array']['id']);
  if($vars['elements']['#region'] === 'content'){
    // Disable the grid for this element, as we are controlling this using our panel layout instead
    unset($vars['elements']['#grid']);
  }
}

/**
 * Implements hook_preprocess_html().
 *
 * No BS classes thanks Drupal.
 *
 */
function cr_layout_preprocess_html(&$vars) {
  $vars['classes_array'] = array_values(array_diff($vars['classes_array'],array('html','not-front','logged-in','not-logged-in','no-sidebars')));
  $vars['classes_array'] = preg_grep('/^page-node/', $vars['classes_array'], PREG_GREP_INVERT);
  //$vars['classes_array'] = preg_grep('/^node-type/', $vars['classes_array'], PREG_GREP_INVERT);
  $vars['classes_array'] = preg_grep('/^page-/', $vars['classes_array'], PREG_GREP_INVERT);

  // Adding the current users role(s) to the body attribute
  $body_classes = array($vars['classes_array']);
  if ($vars['user']) {
    foreach($vars['user']->roles as $key => $role){
      $role_class = 'role-' . str_replace(' ', '-', $role);
      $vars['classes_array'][] = $role_class;
    }
  }

}

/**
 * Implements hook_preprocess_block().
 */
function cr_layout_alpha_preprocess_block(&$vars) {
  if(module_exists('devel')) {
    $vars['attributes_array']['data-themers-helper'][] = 'block-' . $vars['block']->delta;
  }
  $vars['attributes_array']['class'] = array_values(array_diff($vars['attributes_array']['class'],array('block','odd','even')));
  $vars['attributes_array']['class'] = preg_grep('/^block-/', $vars['attributes_array']['class'], PREG_GREP_INVERT);
}

/**
 * Implements hook_preprocess_menu_block_wrapper().
 *
 * @see menu-block-wrapper.tpl.php
 */
function cr_layout_alpha_preprocess_menu_block_wrapper(&$vars) {
  $vars['classes_array'] = preg_grep('/^menu-block/', $vars['classes_array'], PREG_GREP_INVERT);
  $vars['classes_array'] = preg_grep('/^menu-name/', $vars['classes_array'], PREG_GREP_INVERT);
  $vars['classes_array'] = preg_grep('/^menu-level/', $vars['classes_array'], PREG_GREP_INVERT);
  $vars['classes_array'] = preg_grep('/^parent-mlid/', $vars['classes_array'], PREG_GREP_INVERT);
}

/**
 * Implements hook_preprocess_panels_pane().
 *
 * @see panels-pane.tpl.php
 */
function cr_layout_preprocess_panels_pane(&$vars) {
  // Remove unwanted panels pane classes.
  $vars['classes_array'] = array_values(array_diff($vars['classes_array'],array('panel-pane')));
  $vars['classes_array'] = preg_grep('/^pane-uuid-/', $vars['classes_array'], PREG_GREP_INVERT);

  // Unset pane_title of specific view mode
  $pane_title_array = array('basic_pod', 'intro', 'intro_headline_huge', 'tabs_grid_18', 'tabs_grid_24', 'image_first', 'promo_slider', 'basic_pod_image_first_grid8');
  if($vars['pane']->type == 'fieldable_panels_pane' && isset($vars['content']['#view_mode']) && in_array($vars['content']['#view_mode'], $pane_title_array)) {
    unset($vars['title']);
  }

  // Basic Pod header attribute change depends regions and/or columns
  if (strpos($vars['pane']->panel,'row') !== false
    && isset($vars['content']['#view_mode'])
    && $vars['pane']->type == 'fieldable_panels_pane'
    && $vars['content']['#view_mode'] == 'basic_pod') {
    $vars['header_attributes'] = 'h3';
    foreach($vars['display']->panels as $key => $item) {
      $total_columns = intval(substr($key, -1, 1));
        if($total_columns > 2) {
          $row = substr($key, 0, -5);
          if( strpos($vars['pane']->panel, $row) !== false )  {
            $vars['header_attributes'] = 'h4';
          }
        }
    }
    $vars['content']['title_field'][0]['#header_attributes'] = $vars['header_attributes'];
  }
    // subpod
    if (strpos($vars['pane']->panel,'subpod') !== false
        && isset($vars['content']['#view_mode'])
        && $vars['content']['#view_mode'] == 'basic_pod' ) {
      $vars['header_attributes'] = 'h5';
      $vars['content']['title_field'][0]['#header_attributes'] = $vars['header_attributes'];
    }
}

/**
 * Implements hook_preprocess_semantic_panels_pane().
 *
 * @see panels-pane.tpl.php
 */
function cr_layout_preprocess_semantic_panels_pane(&$vars) {
  $pane_title_array = array('basic_pod', 'intro', 'intro_headline_huge', 'tabs_grid_18', 'tabs_grid_24', 'image_first');
  if($vars['pane']->type == 'fieldable_panels_pane' && isset($vars['content']['#view_mode']) && in_array($vars['content']['#view_mode'], $pane_title_array)) {
    $vars['title_html'] =  false;
  }
}

/**
 * Implements hook_preprocess_views_view().
 *
 */
function cr_layout_preprocess_views_view(&$vars){
  if(module_exists('devel')) {
    $vars['attributes_array']['data-themers-helper'][] = 'view-' . $vars['name'];
  }
  $vars['classes_array'] = array_values(array_diff($vars['classes_array'],array('view', 'view-'.$vars['css_name'], 'view-'.$vars['name'], 'view-display-id-'.$vars['display_id'])));
}

function cr_layout_preprocess_views_view_list(&$vars) {
  cr_layout_preprocess_views_view_unformatted($vars);
}

function cr_layout_preprocess_views_view_unformatted(&$vars) {
  $view = $vars['view'];
  $rows = $vars['rows'];
  $style = $view->style_plugin;
  $options = $style->options;

  $vars['classes_array'] = array();
  $vars['classes'] = array();
  $default_row_class = isset($options['default_row_class']) ? $options['default_row_class'] : FALSE;
  $row_class_special = isset($options['row_class_special']) ? $options['row_class_special'] : FALSE;
  // Set up striping values.
  $count = 0;
  $max = count($rows);
  foreach ($rows as $id => $row) {
    $count++;
    // if ($default_row_class) {
    //   $vars['classes'][$id][] = 'views-row';
    //   $vars['classes'][$id][] = 'views-row-' . $count;
    // }
    // if ($row_class_special) {
    //   $vars['classes'][$id][] = 'views-row-' . ($count % 2 ? 'odd' : 'even');
    //   if ($count == 1) {
    //     $vars['classes'][$id][] = 'views-row-first';
    //   }
    //   if ($count == $max) {
    //     $vars['classes'][$id][] = 'views-row-last';
    //   }
    // }

    if ($row_class = $view->style_plugin->get_row_class($id)) {
      $vars['classes'][$id][] = $row_class;
    }

    // Flatten the classes to a string for each row for the template file.
    $vars['classes_array'][$id] = isset($vars['classes'][$id]) ? implode(' ', $vars['classes'][$id]) : '';
  }
}

function cr_layout_form_element($variables) {
  $element = &$variables['element'];
  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'] = array('form-item form-item-wrapper');
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'is-disabled';
  }
  // Add a grid classes.
  if (!empty($element['#grid'])) {
    $attributes['class'][] = $element['#grid'];
  }
  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if (!empty($element['#description'])) {
    $output .= '<div class="form-description">' . $element['#description'] . "</div>\n";
  }

  $output .= "</div>\n";

  return $output;
}

function cr_layout_textfield($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'text';
  element_set_attributes($element, array('id', 'name', 'value', 'size', 'maxlength'));
  _form_set_class($element, array('text-input'));

  $extra = '';
  if ($element['#autocomplete_path'] && drupal_valid_path($element['#autocomplete_path'])) {
    drupal_add_library('system', 'drupal.autocomplete');
    $element['#attributes']['class'][] = 'form-autocomplete';

    $attributes = array();
    $attributes['type'] = 'hidden';
    $attributes['id'] = $element['#attributes']['id'] . '-autocomplete';
    $attributes['value'] = url($element['#autocomplete_path'], array('absolute' => TRUE));
    $attributes['disabled'] = 'disabled';
    $attributes['class'][] = 'autocomplete';
    $extra = '<input' . drupal_attributes($attributes) . ' />';
  }

  $output = '<input' . drupal_attributes($element['#attributes']) . ' />';

  return $output . $extra;
}

function cr_layout_password($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'password';
  element_set_attributes($element, array('id', 'name', 'size', 'maxlength'));
  _form_set_class($element, array('text-input'));

  return '<input' . drupal_attributes($element['#attributes']) . ' />';
}

// theme_emailfield (HTML5) provided by elements.module
function cr_layout_emailfield($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'email';
  element_set_attributes($element, array('id', 'name', 'value', 'size', 'maxlength', 'placeholder'));
  _form_set_class($element, array('form-text', 'form-email', 'text-input'));

  $extra = elements_add_autocomplete($element);
  $output = '<input' . drupal_attributes($element['#attributes']) . ' />';

  return $output . $extra;
}

// theme_telfield (HTML5) provided by elements.module
function cr_layout_telfield($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'tel';
  element_set_attributes($element, array('id', 'name', 'value', 'size', 'maxlength', 'placeholder'));
  _form_set_class($element, array('form-text', 'form-tel', 'text-input'));

  $extra = elements_add_autocomplete($element);
  $output = '<input' . drupal_attributes($element['#attributes']) . ' />';

  return $output . $extra;
}

// theme_numberfield (HTML5) provided by elements.module
function cr_layout_numberfield($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'number';
  element_set_attributes($element, array('id', 'name', 'value', 'step', 'min', 'max', 'placeholder'));
  _form_set_class($element, array('form-text', 'form-number', 'text-input'));

  $output = '<input' . drupal_attributes($element['#attributes']) . ' />';

  return $output;
}
function cr_layout_textarea($variables) {
  $element = $variables['element'];
  element_set_attributes($element, array('id', 'name', 'cols', 'rows'));
  _form_set_class($element, array('text-input'));

  $output = '<textarea' . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</textarea>';
  return $output;
}

function cr_layout_button($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'submit';
  element_set_attributes($element, array('id', 'name', 'value'));

  $element['#attributes']['class'][] = 'button';
  if (!empty($element['#button_type'])) {
    $element['#attributes']['class'][] = 'button--' . $element['#button_type'];
  }
  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'is-disabled';
  }

  $output = '<input' . drupal_attributes($element['#attributes']) . ' />';
  return $output;
}

function cr_layout_form_element_label($variables) {
  $element = $variables['element'];
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // If title and required marker are both empty, output no label.
  if ((!isset($element['#title']) || $element['#title'] === '') && empty($element['#required'])) {
    return '';
  }

  // If the element is required, a required marker is appended to the label.
  $required = !empty($element['#required']) ? theme('form_required_marker', array('element' => $element)) : '';

  $title = filter_xss_admin($element['#title']);

  $attributes = array();
  $attributes['class'] = 'form-label';
  // Style the label as class option to display inline with the element.
  if ($element['#title_display'] == 'after') {
    $attributes['class'] = 'option';
  }
  // Show label only to screen readers to avoid disruption in visual flows.
  elseif ($element['#title_display'] == 'invisible') {
    $attributes['class'] = 'element-invisible';
  }

  if (!empty($element['#id'])) {
    $attributes['for'] = $element['#id'];
  }

  // The leading whitespace helps visually separate fields from inline labels.
  return ' <label' . drupal_attributes($attributes) . '>' . $t('!title !required', array('!title' => $title, '!required' => $required)) . "</label>\n";
}

function cr_layout_styleguide_alter(&$items) {
  // Remove unwanted items
  $keep = array('color_palette');
  foreach ($items as $key => $item) {
    if (!in_array($key, $keep)){
      unset($items[$key]);
    }
  }
  // Add new items
  $items['headings'] = array(
      'title' => 'Headings',
      'group' => 'Typography',
      'content' => '<h1 class="headline headline--huge">Huge Headline</h1>' .
                    '<h1 class="headline headline--larger">Larger Headline</h1>'.
                    '<h2>Title heading</h2>' .
                    '<h3>Title heading</h3>' .
                    '<h4>Title heading</h4>' .
                    '<h5>Title heading</h5>' .
                    '<h6>Title heading</h6>' ,
    );
  $items['body_copy'] = array(
      'title' => 'Body Copy',
      'group' => 'Typography',
      'content' => '<p>Lo-fi cillum Marfa ex, esse vinyl dolor. Pitchfork deserunt flannel, put a bird on it accusamus sint ad vegan consectetur VHS wayfarers polaroid. Fingerstache minim put a bird on it, actually irure cred do banjo shabby chic. Salvia 8-bit semiotics, lo-fi Marfa tumblr do hashtag nulla organic. Retro yr PBR hella ullamco Etsy fugiat, messenger bag +1 gentrify artisan accusamus. Small batch church-key blog, whatever kogi butcher deserunt ut Bushwick. PBR Marfa fingerstache odio, irure Wes Anderson Cosby sweater Odd Future plaid wolf culpa squid.</p>',
    );
  $items['inline_link'] = array(
      'title' => 'Inline Link',
      'group' => 'Typography',
      'content' => l('Link', '/') . '<br>' .
                   l('Link', '/', array('attributes' => array('class'=>array('link--grey')))),
    );
  $items['buttons'] = array(
      'title' => 'Buttons',
      'group' => 'Buttons',
      'content' => l('Button', '/', array('attributes' => array('class' => array('button')))) .
                   l('Button', '/', array('attributes' => array('class' => array('button', 'button--grey')))) .
                   l('Button', '/', array('attributes' => array('class' => array('button', 'button--light-grey')))),
    );
  $items['event_buttons'] = array(
      'title' => 'Event Buttons',
      'group' => 'Buttons',
      'content' => l('Swimming', '/', array('attributes' => array('class' => array('button', 'button--swim')))) .
                  l('Running', '/', array('attributes' => array('class' => array('button', 'button--run')))) .
                  l('Cycling', '/', array('attributes' => array('class' => array('button', 'button--cycle')))),
    );
  $items['large_buttons'] = array(
      'title' => 'Large Buttons',
      'group' => 'Buttons',
      'content' => l('Find out more', '/', array('attributes' => array('class' => array('button', 'button--large')))).
                  l('Find out more', '/', array('attributes' => array('class' => array('button', 'button--grey', 'button--large')))).
                  l('Find out more', '/', array('attributes' => array('class' => array('button', 'button--light-grey', 'button--large')))).
                  l('Swimming', '/', array('attributes' => array('class' => array('button', 'button--swim', 'button--large')))) .
                  l('Running', '/', array('attributes' => array('class' => array('button', 'button--run', 'button--large')))) .
                  l('Cycling', '/', array('attributes' => array('class' => array('button', 'button--cycle', 'button--large')))),
    );
  $items['pointers'] = array(
      'title' => 'Pointers',
      'group' => 'Typography',
      'content' => l('<i class="icon icon-pointer"></i>links', '/', array('html' => TRUE, 'attributes' => array('class' => array('pointer')))),
    );
  $items['cta'] = array(
      'title' => 'CTA',
      'group' => 'Typography',
      'content' => l('links', '/', array('html' => TRUE, 'attributes' => array('class' => array('cta')))),
    );
  $items['unordered_list'] = array(
      'title' => 'Unordered list',
      'group' => 'Typography',
      'content' => '<div class="field"><ul><li>Item 1</li><li>Item 2</li><li>Item 3</li><li>Item 4 <ul><li>Item 1</li><li>Item 2</li><li>Item 3</li><li>Item 4</li></ul></li></ul></div>',
    );
  $items['ordered_list'] = array(
      'title' => 'Ordered list',
      'group' => 'Typography',
      'content' => '<div class="field"><ol><li>Item 1</li><li>Item 2</li><li>Item 3</li><li>Item 4 <ol><li>Item 1</li><li>Item 2</li><li>Item 3</li><li>Item 4</li></ol></li><li>Item 5</li></ol></div>',
    );
  $items['quotes'] = array(
      'title' => 'Quotes',
      'group' => 'Typography',
      'content' => '<div class="grid-9"><blockquote><p>Fundraising for Sport Relief at work is a great way to have a laugh with workmates.</p></blockquote></div>' .
      '<div class="grid-9"><blockquote class="quote--bubble"><p>Fundraising for Sport Relief at work is a great way to have a laugh with workmates.</p></blockquote></div>',
    );
    $items['form'] = array(
      'title' => t('Form styles'),
      'content' => drupal_get_form('cr_layout_styleguide_form'),
      'group' => t('Forms'),
    );
    $items['form'] = array(
      'title' => t('Form styles'),
      'content' => drupal_get_form('cr_layout_styleguide_form'),
      'group' => t('Forms'),
    );
    $items['pod'] = array(
      'title' => t('Basic pods'),
      'content' => '<div class="container-24"> '.
        '<div class="grid-6"><div class="pod">' .
        '<h2 class="pod__title">Title</h2>' .
        '<div class="pod__body"><p>Williamsburg direct trade hoodie lo-fi. Organic food truck american apparel hoodie hashtag fingerstache viral, fashion axe ethnic bespoke 8-bit irony helvetica flexitarian master cleanse. Williamsburg put a bird on it cred art party church-key PBR. Freegan before they sold out sustainable, pitchfork scenester chambray asymmetrical ugh dreamcatcher tousled Bushwick Godard keytar cornhole. </p><p>' .
        l('Button', '/', array('attributes' => array('class' => array('button')))) .
        '</p></div></div></div>' .

        '<div class="grid-6"><div class="pod">' .
        '<h2 class="pod__title">Title</h2>' .
        '<div class="pod__body"><p>Williamsburg direct trade hoodie lo-fi. Organic food truck american apparel hoodie hashtag fingerstache viral. Freegan before they sold out sustainable. </p><p>' .
        l('Link to something', '/', array('attributes' => array('class' => array('cta')))) .
        '</p></div><img class="pod__image" src="/sites/sportrelief.com/themes/sport_relief_2014/images/pod-example.jpg" />' .
        '</div></div>' .
        '</div>',
      'group' => t('Pods'),
    );
    $items['needpod'] = array(
      'title' => t('Need pod'),
      'content' => '<div class="container-24"><div class="grid-6">' .
        '<div class="money-buy"><h2 class="money-buy__title">See what <br /> <em>your £500</em> could do</h2>' .
        '<p class="money-buy__body">£500 could enable a whole community living in a Kenyan slum to improve their health and sanitation by building a latrine.</p>' .
        '<div class="money-buy__teaser">' .
        '<img class="money-buy__image" src="/sites/sportrelief.com/themes/sport_relief_2014/images/money_buy.jpg" />' .
        '<div id="fun-fact" class="money-buy__fact"><img src="/sites/sportrelief.com/themes/sport_relief_2014/images/money_buy-tap.png" />' .
        '<p>40% of the world’s population live without proper sanitation</p><a class="money-buy__trigger" href="#fun-fact">Fun Fact</a></div>' .
        '</div></div></div></div>',
      'group' => t('Pods'),
    );
    $items['slider_controls'] = array(
      'title' => 'Flexslider Controls',
      'group' => 'Slider',
      'content' => '<div class="field"><div class="flex-nav-container"><div class="flexslider"><ol class="flex-control-nav flex-control-paging"><li><a class="">1</a></li><li><a class="flex-active">2</a></li></ol><ul class="flex-direction-nav"><li><a href="#" class="flex-prev">Previous</a></li><li><a href="#" class="flex-next">Next</a></li></ul></div></div></div>',
    );
    $items['accordion'] = array(
      'title' => 'Accordion',
      'group' => 'Accordion',
      'content' => '<div class="js-accordion accordion accordion--main"><details class="accordion-item"><summary class="accordion-title">Tab one</summary><div class="field field-name-field-body"><p>Williamsburg direct trade hoodie lo-fi. Organic food truck american apparel hoodie hashtag fingerstache viral, fashion axe ethnic bespoke 8-bit irony helvetica flexitarian master cleanse. Williamsburg put a bird on it cred art party church-key PBR. Freegan before they sold out sustainable, pitchfork scenester chambray asymmetrical ugh dreamcatcher tousled Bushwick Godard keytar cornhole. Fingerstache fanny pack freegan pickled, Tonx salvia wolf readymade next level mixtape. High Life quinoa small batch, typewriter +1 beard ennui seitan dreamcatcher synth chillwave helvetica lo-fi. Typewriter bicycle rights thundercats pickled yr, squid raw denim mixtape mumblecore ennui church-key mustache wolf artisan narwhal.</p></div></details><details class="accordion-item"><summary class="accordion-title">Pane Title</summary><div class="field field-name-field-body"><p>Apta quia to ipse modi soli toga im. Ne conservat adjuvetis in credendum. Putabo in quales ei scioli. Theologos tractarem tentassem experimur ex quocunque ex chimaeram mo. Tantummodo deveniatur tot deo nec objectivam rum secernitur.</p><p><a class="cta" id="CTA" name="CTA">CTA&nbsp;</a></p><p><a class="button" id="Button" name="Button">Button&nbsp;</a></p></div></details></div>',
    );
    $items['search_poscode'] = array(
      'title' => 'Postcode Search',
      'group' => 'Form Styles',
      'content' => '<div class="search-event grid-9 clearfix"><form id="frmSearchEvents" name="frmSearchEvents" class="search-events" method="post" action="/search/event"><fieldset><label for="search_query">Enter your postcode / town</label><div class="search-fields-wrap"><input type="search" value="" placeholder="Enter your postcode / town" name="q" id="search_query" class="text-input"><input type="hidden" value="" name="event-type" id="searchEvents_EventType"><input type="submit" value="Search" class="button" id="btnSubmit"></div></fieldset></form></div>' .
                   '<div class="search-event search-event--large grid-9 clearfix"><form id="frmSearchEvents" name="frmSearchEvents" class="search-events" method="post" action="/search/event"><fieldset><label for="search_query">Enter your postcode / town</label><div class="search-fields-wrap"><input type="search" value="" placeholder="Enter your postcode / town" name="q" id="search_query" class="text-input"><input type="hidden" value="" name="event-type" id="searchEvents_EventType"><input type="submit" value="Search" class="button" id="btnSubmit"></div></fieldset></form></div>' .
                   '<div class="search-event search-event--large search-event--white grid-9 clearfix"><form id="frmSearchEvents" name="frmSearchEvents" class="search-events" method="post" action="/search/event"><fieldset><label for="search_query">Enter your postcode / town</label><div class="search-fields-wrap"><input type="search" value="" placeholder="Enter your postcode / town" name="q" id="search_query" class="text-input"><input type="hidden" value="" name="event-type" id="searchEvents_EventType"><input type="submit" value="Search" class="button" id="btnSubmit"></div></fieldset></form></div>',
    );
}

/**
 * Sample form, showing all elements.
 */
function cr_layout_styleguide_form($form, &$form_state, $form_keys = array()) {
  $form = array();
  $options = array();
  $list = styleguide_list(2);
  foreach ($list as $item) {
    $options[$item] = $item;
  }
  $form['#prefix'] = '<div class="container-24"><div class="grid-9">';
  $form['#suffix'] = '</div></div>';
    $form['textfield'] = array(
    '#type' => 'textfield',
    '#title' => t('This is a label title'),
    '#default_value' => '',
    '#attributes' => array('placeholder' => array('Text field')),
    '#required' => TRUE,
    '#description' => styleguide_sentence(),
  );
  $form['select'] = array(
    '#type' => 'select',
    '#title' => t('This is a label title'),
    '#options' => $options,
    '#required' => TRUE,
    '#empty_value' => '',
  );
  $form['checkbox'] = array(
    '#type' => 'checkbox',
    '#title' => t('Checkbox'),
    '#value' => 1,
    '#default_value' => 1,
  );
  $form['radios'] = array(
    '#type' => 'radios',
    '#title' => t('Radios'),
    '#options' => $options,
    '#required' => TRUE,
  );
  $form['textarea'] = array(
    '#type' => 'textarea',
    '#title' => t('Textarea'),
    '#default_value' => styleguide_paragraph(1),
    '#required' => TRUE,
  );
  $form['date'] = array(
    '#type' => 'date',
    '#title' => t('Date'),
    '#required' => TRUE,
  );
  $form['file'] = array(
    '#type' => 'file',
    '#title' => t('File'),
    '#required' => TRUE,
  );
  $form['password'] = array(
    '#type' => 'password',
    '#title' => t('Password'),
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  if (!empty($form_keys)) {
    $items = array();
    foreach ($form_keys as $key) {
      if (isset($form[$key])) {
        $items[$key] = $form[$key];
      }
    }
    return $items;
  }
  return $form;
}

/**
 * Unset flexsliders css, all css should be in theme css flexslider.less file
 */
function cr_layout_css_alter(&$css) {
  if(!function_exists('libraries_get_path')) {
    module_load_include('module', 'libraries');
    $error_message = 'libraries module not available during load of theme';
    watchdog('libraries/theme', $error_message, array(), 'WATCHDOG_NOTICE', NULL);
    error_log($error_message, 0);
  }
  unset($css[libraries_get_path('flexslider') . '/flexslider.css']);
}

function cr_layout_pager($variables) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // first is the first page listed by this pager piece (re quantity)
  $pager_first = $pager_current - $pager_middle + 1;
  // last is the last page listed by this pager piece (re quantity)
  $pager_last = $pager_current + $quantity - $pager_middle;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.

  $li_first = theme('pager_first', array('text' => (isset($tags[0]) ? $tags[0] : t('« first')), 'element' => $element, 'parameters' => $parameters));
  $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('‹ previous')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t('next ›')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_last = theme('pager_last', array('text' => (isset($tags[4]) ? $tags[4] : t('last »')), 'element' => $element, 'parameters' => $parameters));

  $prev_inactive = '';
  $next_inactive = '';

  if (!$li_previous) {  $prev_inactive = 'inactive'; }
  if (!$li_next) {  $next_inactive = 'inactive'; }

  if ($pager_total[$element] > 1) {
    if ($li_first) {
      $items[] = array(
        'class' => array('pager-first'),
        'data' => $li_first,
      );
    }
    //if ($li_previous) {
      $items[] = array(
        'class' => array('pager-previous ' . $prev_inactive),
        'data' => $li_previous,
      );
    //}

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('pager-item pager-current'),
            'data' => $i,
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_next', array('text' => $i, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters)),
          );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
    }
    // End generation.
    //if ($li_next) {
      $items[] = array(
        'class' => array('pager-next ' . $next_inactive),
        'data' => $li_next,
      );
    //}
    if ($li_last) {
      $items[] = array(
        'class' => array('pager-last'),
        'data' => $li_last,
      );
    }
    return '<h2 class="element-invisible">' . t('Pages') . '</h2>' . theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pager')),
    ));
  }
}
