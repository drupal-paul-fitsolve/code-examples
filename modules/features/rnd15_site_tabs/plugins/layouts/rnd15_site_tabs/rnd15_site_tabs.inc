<?php
/**
 * @file rnd15_site_tabs.inc
 *
 * Code for Panels Layout Plugin - Tab
 *
 * Author: Andy E. Phipps
 */

/**
 * Implements hook_panels_layouts().
 */
function rnd15_site_tabs_rnd15_site_tabs_panels_layouts() {
  $items['rnd15_site_tabs'] = array(
    'title' => t('Tab'),
    'category' => t('Tab Layouts'),
    'icon' => 'rnd15_site_tabs.png',
    'theme' => 'rnd15_site_tabs',
    'regions' => array(
      '1' => t('First tab'),
      '2' => t('Second tab'),
      '3' => t('Third tab'),
      '4' => t('Fourth tab'),
      '5' => t('Fifth tab'),
      '6' => t('Sixth tab'),
      '7' => t('Seventh tab'),
      '8' => t('Eighth tab'),
      '9' => t('Ninth tab'),
      '10' => t('Tenth tab'),
      '11' => t('Eleventh tab'),
      '12' => t('Twelth tab'),
      '13' => t('Thirteenth tab'),
      '14' => t('Fourteenth tab'),
      '15' => t('Fifteenth tab'),
      '16' => t('Sixteenth tab'),
    ),
  );  
  return $items;
}

/**
 * Implementation of hook_theme()
 */
function rnd15_site_tabs_theme(){
  return array(
    'tabs_output' => array(
      'variables' => array('item' => NULL, 'id' => NULL, 'delta' => NULL),
    ),
    'button_output' => array(
      'variables' => array('title' => NULL, 'id' => NULL, 'delta' => NULL),
    ),
    'heading_output' => array(
      'variables' => array('heading' => NULL),
    ),
  );
}

/**
 * Theme hook that creates markup for the tab panes (where the content is rendered),
 * using a delta to produce 'data-tab' attribute, an identifier used to allow the 
 * 'default tab' functionality.
 */
function theme_rnd15_site_tabs_tabs_output($variables) {
  $tabsOut = '<div data-tab="'.($variables['delta']).'" id="'.$variables['id'].'" class="tabs__content clearfix">';
  $tabsOut .= $variables['item'];
  $tabsOut .= '</div>';
  return $tabsOut;
}

/**
 * Theme hooks to create markup for the h3 heading rendered above the tab buttons,
 * applying required type classes to style the element.
 */
function theme_rnd15_site_tabs_heading_output($variables) {
  $headingOut = '<h3 class="tabs__heading type--centred type--black">' .$variables['heading']. '</h3>';
  return $headingOut;
}

/**
 * Theme hook that produces an unordered list of tab buttons, being passed an array of 
 * identifiers to connect each tab button to its associated tab content 
 */
function theme_rnd15_site_tabs_button_output($variables) {  
  $delta = 1;
  $buttonOut = '<ul class="tabs__list">';

  foreach ($variables as $item){
    $buttonOut .= '<li class="tabs__list-item"><a class="btn btn-light-grey tabs__button type--light type--centred" href="#/'
    .$item['id'].'" data-tab="'
    .$item['delta'].'">'
    .$item['title'].'</a></li>';
    $delta++;
  }

  $buttonOut .= '</ul>';
  return $buttonOut;
}


/**
 * Preprocess function for rnd15_site_tabs.tpl.php
 */
function template_preprocess_rnd15_site_tabs(&$vars) {
  // Declare variables
  $is_admin = $vars['renderer']->admin;
  $contents = &$vars['content'];

  /** 
   * Any extra classes added to the container via the Tab style plug-in, 
   * set in the Display Settings form in the minipanel UI
   */
  $extra_classes = isset($vars['display']->panel_settings['style_settings']['default']['extraClasses']) ? $vars['display']->panel_settings['style_settings']['default']['extraClasses'] : null;

  // Default tab defaults to first if not set
  $default_tab = isset($vars['display']->panel_settings['style_settings']['default']['defaultTab']) ? $vars['display']->panel_settings['style_settings']['default']['defaultTab'] : '1';
  drupal_add_js(array('rnd15Tabs' => array('default_tab' => $default_tab)), 'setting');

  // Heading rendered above Tabs
  $tabs_heading = isset($vars['display']->panel_settings['style_settings']['default']['tabsHeading']) ? $vars['display']->panel_settings['style_settings']['default']['tabsHeading'] : null;

  // Create container   
  $element['tabs'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'tabs__wrapper',
          'container',
          'section',
        $extra_classes
        ),
      'data-default-tab' => $default_tab,
    ),
     'tabs_heading' => array(
      'type' => 'markup',
    ),
    'tabs_buttons' => array(
      'type' => 'markup',
    ),
    'tabs_content' => array(
      'type' => 'markup',
    ),
  );        

  $output = '';
  $tab_titles = array();
  $tabOutput = array();
  $buttonOutput = array();

  // remove empty regions
  $contents = array_filter($contents, 'strlen');
  $delta = 1;

  // Loop through contents, assign content to array
  foreach ($contents as $region_id => $item) {

    $output .= $item;

    // Grab the selected title pane's fpid from settings array for each region
    $tab_titles[$delta]['title_pane_fpid'] = isset($vars['display']->panel_settings['style_settings'][$region_id]['title_pane']) ? $vars['display']->panel_settings['style_settings'][$region_id]['title_pane'] : '' ;

    // Check fpp and its title actually exist
    $this_fpp = fieldable_panels_panes_load($tab_titles[$delta]['title_pane_fpid']);
    $this_fpp_title = isset($this_fpp->title) ? $this_fpp->title : "";

    // Use fpid to access the pane's title
    // - This can be updated in future to grab image, SVG etc to act as title - 
    $tab_titles[$delta]['title_pane_text'] = isset($this_fpp) && isset($this_fpp_title) ? $this_fpp_title : '';
    $delta++;
  }
  
  $delta = 1;

  foreach ($contents as &$value) {

    // Grab the title for each region, using delta as a placeholder if the title hasn't been set
    $this_title = isset($tab_titles[$delta]['title_pane_text']) ? $tab_titles[$delta]['title_pane_text'] : $delta;
    $this_title_safe = drupal_html_id($this_title);

    // create tabs with content, and ID based on the title pane
    $tabOutput[] = theme_rnd15_site_tabs_tabs_output( array(
      'item' => $value,
      'id' => $this_title_safe,
      'delta' => $delta)
    );
    
    // Generate button in array for each tabbed pane
    $buttonOutput[$delta]['title'] = $this_title;
    $buttonOutput[$delta]['id'] = $this_title_safe;
    $buttonOutput[$delta]['delta'] = $delta;
    $delta++;
  }

  // theme button array
  $buttonOutput = theme_rnd15_site_tabs_button_output($buttonOutput);
  $element['tabs']['tabs_buttons']['#markup'] = $buttonOutput;
  
  // theme heading 
  $headingOutput = theme_rnd15_site_tabs_heading_output( array('heading' => $tabs_heading) );
  $element['tabs']['tabs_heading']['#markup'] = $headingOutput;

  $tabOutput = join("",$tabOutput);
  $tabOutput = '<div class="tabs__content__wrapper">'.$tabOutput.'</div>';
  $element['tabs']['tabs_content']['#markup'] = $tabOutput;

  $contents = array(
    '#markup' => $tabOutput,
  );

  // Only add tabs to node display page 
  if(isset($is_admin) && $is_admin != '1') { 
     // Push array for contents
     $contents = array(
        '#markup' => drupal_render($element),
      );   
  } 
}