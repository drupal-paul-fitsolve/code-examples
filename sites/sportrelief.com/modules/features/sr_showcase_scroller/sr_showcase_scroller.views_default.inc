<?php
/**
 * @file
 * sr_showcase_scroller.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sr_showcase_scroller_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'showcase_slider';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'showcase_slider';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h6 class="is-not-mobile showcase-scroller--cta" id="showcase-scroller--desktop-upload">
<span aria-hidden="true" class="scroller-cta"></span>Upload your own photos and videos
</h6>

<a href="/fundraise/fundraiser-showcase" >
<div class="showcase-scroller--button" id="showcase-scroller--view-button">
<div id="scroller-eye"></div>
View our gallery
</div>
</a>
';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="is-mobile-only" id="showcase-scroller--mobile-upload">

<h4 id="showcase-scroller--mobile-share">Got something to share?</h4>
<h4 id="showcase-scroller--mobile-upload">Upload your own photos and videos</h4>

<a href="/">
<h5 class="showcase-scroller--cta" id="showcase-scroller--mobile-cta">
<span aria-hidden="true" class="scroller-cta"></span>
Upload now</h5>
</a>
</div>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  /* Field: Content: Photo upload */
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['id'] = 'field_fundrasier_showcase_images';
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['table'] = 'field_data_field_fundrasier_showcase_images';
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['field'] = 'field_fundrasier_showcase_images';
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['label'] = '';
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['type'] = 'picture';
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['settings'] = array(
    'picture_group' => 'schools_showcase_scoller',
    'fallback_image_style' => 'schools_showcase_scoller',
    'image_link' => '',
    'colorbox' => 'schools_showcase_scoller',
  );
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Photo upload (field_fundrasier_showcase_images:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_fundrasier_showcase_images';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['operator'] = 'not empty';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['class'] = 'showcase-scroller';
  $handler->display->display_options['style_options']['wrapper_class'] = 'item-list clearfix';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Photo upload */
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['id'] = 'field_fundrasier_showcase_images';
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['table'] = 'field_data_field_fundrasier_showcase_images';
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['field'] = 'field_fundrasier_showcase_images';
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['label'] = '';
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['type'] = 'picture';
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['settings'] = array(
    'picture_group' => 'showcase_scroller',
    'fallback_image_style' => 'showcase-scroller--normal',
    'image_link' => '',
    'colorbox' => 'showcase_scroller',
  );
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['delta_offset'] = '0';

  /* Display: schools showcase slider */
  $handler = $view->new_display('block', 'schools showcase slider', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['class'] = 'showcase-scroller';
  $handler->display->display_options['style_options']['wrapper_class'] = 'item-list clearfix';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="is-mobile-only" id="showcase-scroller--mobile-upload">

<h4 id="showcase-scroller--mobile-share">Got something to share?</h4>
<h4 id="showcase-scroller--mobile-upload-text">Upload your own photos and videos</h4>

<a href="/">
<h5 class="showcase-scroller--cta" id="showcase-scroller--mobile-cta">
<span aria-hidden="true" class="scroller-cta"></span>
Upload now</h5>
</a>
</div>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $export['showcase_slider'] = $view;

  return $export;
}
