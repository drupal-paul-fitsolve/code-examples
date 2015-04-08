<?php
/**
 * @file
 * sr14_fundraiser_showcases.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sr14_fundraiser_showcases_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'fundraiser_showcase';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Fundraiser showcase';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Fundraiser showcase';
  $handler->display->display_options['css_class'] = 'fr-showcase autopager';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'Load more';
  $handler->display->display_options['style_plugin'] = 'views_fluidgrid';
  $handler->display->display_options['style_options']['column_width'] = '280';
  $handler->display->display_options['style_options']['gutter_width'] = '20';
  $handler->display->display_options['style_options']['resizable'] = 1;
  $handler->display->display_options['style_options']['rtl'] = 0;
  $handler->display->display_options['style_options']['fit_width'] = 0;
  $handler->display->display_options['style_options']['animate'] = 0;
  $handler->display->display_options['style_options']['animation_options'] = array(
    'use_css' => 0,
    'queue' => 0,
    'duration' => '',
  );
  $handler->display->display_options['style_options']['reload_on_window_load'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="fr-showcase-empty-result">Sorry, we couldn\'t find the photos you’re looking for. You can only search by name or town and the spelling does need to be correct.</div>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_height'] = '600';
  /* Field: Content: Video upload */
  $handler->display->display_options['fields']['field_video_upload']['id'] = 'field_video_upload';
  $handler->display->display_options['fields']['field_video_upload']['table'] = 'field_data_field_video_upload';
  $handler->display->display_options['fields']['field_video_upload']['field'] = 'field_video_upload';
  $handler->display->display_options['fields']['field_video_upload']['label'] = '';
  $handler->display->display_options['fields']['field_video_upload']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_video_upload']['alter']['text'] = '<a href="[path]?width=100&amp;height=100" class="colorbox-node">
[field_video_upload]
</a>';
  $handler->display->display_options['fields']['field_video_upload']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video_upload']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_video_upload']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_video_upload']['type'] = 'youtube_uploader_thumb';
  $handler->display->display_options['fields']['field_video_upload']['settings'] = array(
    'image_style' => 'fr-showcase-thumb-video',
    'display_title' => 0,
  );
  /* Field: Content: Photo upload */
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['id'] = 'field_fundrasier_showcase_images';
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['table'] = 'field_data_field_fundrasier_showcase_images';
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['field'] = 'field_fundrasier_showcase_images';
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['label'] = '';
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['alter']['text'] = '<a href="[path]?width=100&amp;height=100" class="colorbox-node">
<div class="total-circle"><div class="total"> </div><div class="total-text">PHOTOS</div></div>
[field_video_upload][field_fundrasier_showcase_images]
</a>';
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['settings'] = array(
    'image_style' => 'fr-showcase-thumb',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['delta_first_last'] = TRUE;
  $handler->display->display_options['fields']['field_fundrasier_showcase_images']['separator'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="">';
  $handler->display->display_options['fields']['title']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['title']['alter']['link_class'] = 'colorbox-node';
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  /* Field: Content: Town */
  $handler->display->display_options['fields']['field_town']['id'] = 'field_town';
  $handler->display->display_options['fields']['field_town']['table'] = 'field_data_field_town';
  $handler->display->display_options['fields']['field_town']['field'] = 'field_town';
  $handler->display->display_options['fields']['field_town']['label'] = '';
  $handler->display->display_options['fields']['field_town']['element_label_colon'] = FALSE;
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'fundraiser_showcase' => 'fundraiser_showcase',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'fundraise/fundraiser-showcase';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'fundraiser_showcase' => 'fundraiser_showcase',
  );
  $export['fundraiser_showcase'] = $view;

  return $export;
}
