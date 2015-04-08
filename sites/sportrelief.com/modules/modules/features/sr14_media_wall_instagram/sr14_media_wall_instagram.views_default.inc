<?php
/**
 * @file
 * sr14_media_wall_instagram.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sr14_media_wall_instagram_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'media_wall_instagram';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'drupagram';
  $view->human_name = 'Media Wall: Instagram';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Media Wall: Instagram';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Instagram: Instagram image */
  $handler->display->display_options['fields']['images']['id'] = 'images';
  $handler->display->display_options['fields']['images']['table'] = 'drupagram';
  $handler->display->display_options['fields']['images']['field'] = 'images';
  $handler->display->display_options['fields']['images']['label'] = '';
  $handler->display->display_options['fields']['images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['images']['link_to_post'] = 0;
  $handler->display->display_options['fields']['images']['image_style'] = 'grid-4-normal';

  /* Display: Instagram: "sportrelief" */
  $handler = $view->new_display('block', 'Instagram: "sportrelief"', 'block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Instagram Account: Instagram account username */
  $handler->display->display_options['fields']['username']['id'] = 'username';
  $handler->display->display_options['fields']['username']['table'] = 'drupagram_account';
  $handler->display->display_options['fields']['username']['field'] = 'username';
  $handler->display->display_options['fields']['username']['label'] = '';
  $handler->display->display_options['fields']['username']['exclude'] = TRUE;
  $handler->display->display_options['fields']['username']['element_label_colon'] = FALSE;
  /* Field: Instagram: Large image */
  $handler->display->display_options['fields']['images_1']['id'] = 'images_1';
  $handler->display->display_options['fields']['images_1']['table'] = 'drupagram';
  $handler->display->display_options['fields']['images_1']['field'] = 'images';
  $handler->display->display_options['fields']['images_1']['ui_name'] = 'Instagram: Large image';
  $handler->display->display_options['fields']['images_1']['label'] = '';
  $handler->display->display_options['fields']['images_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['images_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['images_1']['source'] = 'standard_resolution';
  $handler->display->display_options['fields']['images_1']['link_to_post'] = 0;
  $handler->display->display_options['fields']['images_1']['url_only'] = 1;
  /* Field: Instagram: Instagram image */
  $handler->display->display_options['fields']['images']['id'] = 'images';
  $handler->display->display_options['fields']['images']['table'] = 'drupagram';
  $handler->display->display_options['fields']['images']['field'] = 'images';
  $handler->display->display_options['fields']['images']['label'] = '';
  $handler->display->display_options['fields']['images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['images']['link_to_post'] = 0;
  $handler->display->display_options['fields']['images']['image_style'] = 'grid-4-normal';
  /* Field: Colobox link */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Colobox link';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a class="node-link colorbox-load" href="[images_1]?width=640&height=640&iframe=true" title="View [username] account instagram image"><span class="text">[username]</span><span class="node-link-icon"></span><span class="node-link-background"></span></a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Instagram: Created time */
  $handler->display->display_options['sorts']['created_time']['id'] = 'created_time';
  $handler->display->display_options['sorts']['created_time']['table'] = 'drupagram';
  $handler->display->display_options['sorts']['created_time']['field'] = 'created_time';
  $handler->display->display_options['sorts']['created_time']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Instagram Account: Instagram account username */
  $handler->display->display_options['filters']['username']['id'] = 'username';
  $handler->display->display_options['filters']['username']['table'] = 'drupagram_account';
  $handler->display->display_options['filters']['username']['field'] = 'username';
  $handler->display->display_options['filters']['username']['value'] = 'sportrelief';

  /* Display: Instagram: #mixersinmotion */
  $handler = $view->new_display('block', 'Instagram: #mixersinmotion', 'instagram_mixersinmotion');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Instagram Account: Instagram account username */
  $handler->display->display_options['fields']['username']['id'] = 'username';
  $handler->display->display_options['fields']['username']['table'] = 'drupagram_account';
  $handler->display->display_options['fields']['username']['field'] = 'username';
  $handler->display->display_options['fields']['username']['label'] = '';
  $handler->display->display_options['fields']['username']['exclude'] = TRUE;
  $handler->display->display_options['fields']['username']['element_label_colon'] = FALSE;
  /* Field: Instagram: Large image */
  $handler->display->display_options['fields']['images_1']['id'] = 'images_1';
  $handler->display->display_options['fields']['images_1']['table'] = 'drupagram';
  $handler->display->display_options['fields']['images_1']['field'] = 'images';
  $handler->display->display_options['fields']['images_1']['ui_name'] = 'Instagram: Large image';
  $handler->display->display_options['fields']['images_1']['label'] = '';
  $handler->display->display_options['fields']['images_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['images_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['images_1']['source'] = 'standard_resolution';
  $handler->display->display_options['fields']['images_1']['link_to_post'] = 0;
  /* Field: Instagram: Instagram image */
  $handler->display->display_options['fields']['images']['id'] = 'images';
  $handler->display->display_options['fields']['images']['table'] = 'drupagram';
  $handler->display->display_options['fields']['images']['field'] = 'images';
  $handler->display->display_options['fields']['images']['label'] = '';
  $handler->display->display_options['fields']['images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['images']['link_to_post'] = 0;
  $handler->display->display_options['fields']['images']['image_style'] = 'grid-4-normal';
  /* Field: Colobox link */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Colobox link';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a class="node-link colorbox-inline" href="?width=640&height=640&inline=true#instagram-content" title="View [username] account instagram image"><span class="text">[username]</span><span class="node-link-icon"></span><span class="node-link-background"></span></a>

<div class="hide">
<div id="instagram-content">[images_1]</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Instagram: Created time */
  $handler->display->display_options['sorts']['created_time']['id'] = 'created_time';
  $handler->display->display_options['sorts']['created_time']['table'] = 'drupagram';
  $handler->display->display_options['sorts']['created_time']['field'] = 'created_time';
  $handler->display->display_options['sorts']['created_time']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Instagram Account: Instagram account username */
  $handler->display->display_options['filters']['username']['id'] = 'username';
  $handler->display->display_options['filters']['username']['table'] = 'drupagram_account';
  $handler->display->display_options['filters']['username']['field'] = 'username';
  $handler->display->display_options['filters']['username']['value'] = 'sportrelief';
  /* Filter criterion: Instagram: Caption */
  $handler->display->display_options['filters']['caption']['id'] = 'caption';
  $handler->display->display_options['filters']['caption']['table'] = 'drupagram';
  $handler->display->display_options['filters']['caption']['field'] = 'caption';
  $handler->display->display_options['filters']['caption']['operator'] = 'contains';
  $handler->display->display_options['filters']['caption']['value'] = '#mixersinmotion';
  $export['media_wall_instagram'] = $view;

  return $export;
}
