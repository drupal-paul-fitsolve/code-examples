<?php


/* TYPEKIT */
function sport_relief_preprocess_html(&$vars) {
  drupal_add_js('//use.typekit.net/rne1lbl.js', array('type' => 'external', 'scope' => 'header'));
  drupal_add_js('try{Typekit.load();}catch(e){}',
      array('type' => 'inline', 'scope' => 'header'));
  if (isset($_GET['response_type']) && $_GET['response_type'] == 'contentonly') {
    $variables['theme_hook_suggestions'][] = 'html__contentonly';
  }
  // Sitewide autoheight
  //drupal_add_js(array('cr_auto_height' => array('autoheightselector' => '.autoheight-run')), 'setting');
}

/**
* theme_menu_link()
*/
function sport_relief_menu_link($variables) {

  // quick and dirty to replace invalid css character - AP
  $santisedName = str_replace("&", "and", $variables['element']['#title']);

  //add title related class for li - so percentage widths can be added -TG
	$variables['element']['#attributes']['class'][] = 'menu-' .  strtolower(str_replace(" ", "-", $santisedName));

  // hide the Sponsor menu when in kids section as per #SRSITE-638  
  if ('Sponsor & Donate' == $variables['element']['#title']) {
     if ( 0 !== strpos($_SERVER["REQUEST_URI"],'/play-games')) {
        return theme_menu_link($variables); 
     }    
  } else {
    return theme_menu_link($variables); 
  }
}

// a
function sport_relief_preprocess_menu_block_wrapper(&$variables, $hook) {
  $zebra = 0;
  foreach (element_children($variables['content']) as $mlid){
    $variables['content'][$mlid]['#attributes']['class'][] = ($zebra % 2) ? 'meganav-li meganav-odd' : 'meganav-li meganav-even';
    $zebra++;
  }
}


/**
 * Implements hook_preprocess_page().
 */
function sport_relief_preprocess_page(&$variables) {
  if (isset($_GET['response_type']) && $_GET['response_type'] == 'contentonly') {
    $variables['theme_hook_suggestions'][] = 'page__contentonly';
  }
  if (isset($variables['node']->type)) {
        $nodetype = $variables['node']->type;
        $variables['theme_hook_suggestions'][] = 'page__' . $nodetype;
  }
  if (isset($variables['node']->type) && $variables['node']->type == 'fundraiser_showcase') {
   // unset($variables['page']['header']);
   // unset($variables['page']['footer']);
    unset($variables['page']['content']['subpreface']);
  }

}

/**
 * Implements hook_preprocess_node().
 */
function sport_relief_preprocess_node(&$vars) {
  // Add template suggestion per view mode.
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__' . $vars['view_mode'];

  switch($vars['node_url']){
    case '/partners':
      flexslider_add('flexslider-2', 'default');
      break;
    case '/what-we-do':
      flexslider_add('flexslider-2', 'grid_12');
      break;
  }
  sport_relief_colorbox_video_search_link($vars);
}

/**
 * @param array $vars preprocess node variables
 * Update video search results to use colorbox
 */
function sport_relief_colorbox_video_search_link(&$vars) {
  if ($vars['node']->type == 'video' && $vars['view_mode'] == 'search_result') {
    if (function_exists('colorbox_node_menu')) {
      $node_link = l($vars['title'], 'node/' . $vars['node']->nid,
        array(
          'attributes' => array('class' => 'colorbox-node'),
          'query' => array('width' => '100', 'height'),
        )
      );
      $vars['content']['title_field'][0]['#markup'] = '<h3>' . $node_link . '</h3>';
    }
  }
}

/**
 * Implements hook_preprocess_cr_general_callback_content_wrapper
 *
 * This is a theme hook that brings in some wrapping markup and basic styles
 * for rendering markup / render arrays returned from menu callbacks as apposed
 * to panel pages
 */
function sport_relief_preprocess_cr_general_callback_content_wrapper(&$variables) {
  $path_to_css = drupal_get_path('theme', 'sport_relief') . '/css/callback_content_wrapper.less';
  drupal_add_css($path_to_css);
}



/**
 * Override for flexslider_list_item
 */
function sport_relief_flexslider_list_item(&$vars) {
  // Reference configuration variables
  $item = &$vars['item'];
  $attributes = &$vars['settings']['attributes'];

  if ($vars['optionset']->options['controlNav'] === "thumbnails" &&
      isset($vars['thumb'])
  ) {
    $attributes['data-thumb'] = $vars['thumb'];
  }

  $caption = '';
  if (!empty($vars['caption'])) {
    $caption = '<p class="flex-caption"><span class="flex-caption-inner">' . $vars['caption'] . '</span></p>';
  }

  $output = '';
  $output .= '<li' . drupal_attributes($attributes) . '>' . $item . $caption . "</li>\n";

  return $output;
}

/**
 * prev / next api
 */
function pn_node($node, $mode = 'n') {
  if (!function_exists('prev_next_nid')) {
    return NULL;
  }
 
  switch($mode) {
    case 'p':
      $n_nid = prev_next_nid($node->nid, 'prev');
        $link_text = 'previous';
      break;
    
    case 'n':
      $n_nid = prev_next_nid($node->nid, 'next');
      $link_text = 'next';
    break;
    
    default:
    return NULL;
  }
 
  if ($n_nid) {
    $n_node = node_load($n_nid);
    
    switch($n_node->type) { 
      case 'fundraiser_showcase': 
        if ($mode == 'p') { $link_text = 'Next fundraiser'; }
        else { $link_text = 'Previous fundraiser'; }
        $html = l($link_text , 'node/'.$n_nid, array('attributes' => array('class' => 'colorbox-node'), 'query' => array('width' => '100', 'height' => '100')));
      return $html; 
    }
  }
}



/**
 * Implements hook_js_alter().
 */
function sport_relief_js_alter(&$javascript){
  $omega_path = drupal_get_path('theme', 'omega');
  if(isset($javascript[$omega_path.'/js/omega-mediaqueries.js'])) {
    $javascript[$omega_path.'/js/omega-mediaqueries.js']['group'] = -100;
  }
  $javascript['misc/drupal.js']['force header'] = true;
  $javascript['https://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js']['force header'] = true;
}

/**
 * Implements hook_css_alter().
 * Alter CSS files before they are output on the page.
 */
function sport_relief_css_alter(&$css) {
  uasort($css, 'drupal_sort_css_js');
	$i = 1;
	foreach($css as $name => $script){
		switch($script['data']){
			/*
			 * These CSS files are being grouped into small aggregated files which is
			 * causing unnecessary HTTP requests, blocking other scripts from
			 * downloading. Combining into CSS_DEFAULT group
			 */
			case drupal_get_path('module', 'colorbox_node') . "/colorbox_node.css" :
			case drupal_get_path('module', 'cr_donate') . "/cr_donate.css" :
			case drupal_get_path('module', 'ctools') . "/css/ctools.css" :
					$css[$name]['group'] = CSS_DEFAULT;
					$css[$name]['every_page'] = FALSE;
					$css[$name]['weight'] = $i;
					$i++;
				break;
		}
	}

}


/**
 * Implements hook_preprocess_panels_pane().
 *
 * @see panels-pane.tpl.php
 */
function sport_relief_preprocess_panels_pane(&$vars) {
  // Remove unwanted panels pane classes.
  $vars['classes_array'] = array_values(array_diff($vars['classes_array'],array('panel-pane')));
  $vars['classes_array'] = preg_grep('/^pane-uuid-/', $vars['classes_array'], PREG_GREP_INVERT);

  // Unset pane_title of specific view mode
  $pane_title_array = array(
    'basic_pod',
    'intro',
    'intro_headline_huge',
    'tabs_grid_18',
    'tabs_grid_24',
    'image_first',
    'promo_slider',
    'basic_pod_image_first_grid8',
    'basic_pod_h3_title'
  );

  if($vars['pane']->type == 'fieldable_panels_pane' && isset($vars['content']['#view_mode'])
&& in_array($vars['content']['#view_mode'], $pane_title_array)) {

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
