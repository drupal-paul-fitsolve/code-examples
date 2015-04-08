<?php
/**
 * @file
 * sr_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sr_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_multi_search';
  $view->human_name = 'search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Sorry there were no results found, please try again.';
  $handler->display->display_options['empty']['area']['format'] = 'wysiwyg';
  /* Field: Search: Default node index results */
  $handler->display->display_options['fields']['default_node_index']['id'] = 'default_node_index';
  $handler->display->display_options['fields']['default_node_index']['table'] = 'search_api_multi_search';
  $handler->display->display_options['fields']['default_node_index']['field'] = 'default_node_index';
  $handler->display->display_options['fields']['default_node_index']['label'] = '';
  $handler->display->display_options['fields']['default_node_index']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['default_node_index']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['default_node_index']['display'] = 'view';
  $handler->display->display_options['fields']['default_node_index']['view_mode'] = 'search_result';
  /* Field: Search: Downloadables results */
  $handler->display->display_options['fields']['downloadables']['id'] = 'downloadables';
  $handler->display->display_options['fields']['downloadables']['table'] = 'search_api_multi_search';
  $handler->display->display_options['fields']['downloadables']['field'] = 'downloadables';
  $handler->display->display_options['fields']['downloadables']['label'] = '';
  $handler->display->display_options['fields']['downloadables']['element_type'] = '0';
  $handler->display->display_options['fields']['downloadables']['element_label_type'] = '0';
  $handler->display->display_options['fields']['downloadables']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['downloadables']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['downloadables']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['downloadables']['display'] = 'view';
  $handler->display->display_options['fields']['downloadables']['view_mode'] = 'search_result';
  $handler->display->display_options['fields']['downloadables']['bypass_access'] = 0;
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_multi_search';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_multi_fulltext']['id'] = 'search_api_multi_fulltext';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['table'] = 'search_api_multi_search';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['field'] = 'search_api_multi_fulltext';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['operator_id'] = 'search_api_multi_fulltext_op';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['operator'] = 'search_api_multi_fulltext_op';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['identifier'] = 'query';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Search: Index */
  $handler->display->display_options['filters']['search_api_multi_index']['id'] = 'search_api_multi_index';
  $handler->display->display_options['filters']['search_api_multi_index']['table'] = 'search_api_multi_search';
  $handler->display->display_options['filters']['search_api_multi_index']['field'] = 'search_api_multi_index';
  $handler->display->display_options['filters']['search_api_multi_index']['value'] = array(
    'default_node_index' => 'default_node_index',
  );

  /* Display: All */
  $handler = $view->new_display('panel_pane', 'All', 'panel_pane_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_multi_fulltext']['id'] = 'search_api_multi_fulltext';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['table'] = 'search_api_multi_search';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['field'] = 'search_api_multi_fulltext';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['operator_id'] = 'search_api_multi_fulltext_op';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['operator'] = 'search_api_multi_fulltext_op';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['identifier'] = 'query';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Default node index: Content type (indexed) */
  $handler->display->display_options['filters']['default_node_index_type']['id'] = 'default_node_index_type';
  $handler->display->display_options['filters']['default_node_index_type']['table'] = 'search_api_multi_search';
  $handler->display->display_options['filters']['default_node_index_type']['field'] = 'default_node_index_type';
  $handler->display->display_options['filters']['default_node_index_type']['value'] = array(
    'panel' => 'panel',
    'news_article' => 'news_article',
    'shop_product' => 'shop_product',
    'video' => 'video',
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Pages */
  $handler = $view->new_display('panel_pane', 'Pages', 'panel_pane_2');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_multi_fulltext']['id'] = 'search_api_multi_fulltext';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['table'] = 'search_api_multi_search';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['field'] = 'search_api_multi_fulltext';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['operator_id'] = 'search_api_multi_fulltext_op';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['operator'] = 'search_api_multi_fulltext_op';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['identifier'] = 'query';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Default node index: Content type (indexed) */
  $handler->display->display_options['filters']['default_node_index_type']['id'] = 'default_node_index_type';
  $handler->display->display_options['filters']['default_node_index_type']['table'] = 'search_api_multi_search';
  $handler->display->display_options['filters']['default_node_index_type']['field'] = 'default_node_index_type';
  $handler->display->display_options['filters']['default_node_index_type']['value'] = array(
    'panel' => 'panel',
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Downloads */
  $handler = $view->new_display('panel_pane', 'Downloads', 'panel_pane_3');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_multi_fulltext']['id'] = 'search_api_multi_fulltext';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['table'] = 'search_api_multi_search';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['field'] = 'search_api_multi_fulltext';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['operator_id'] = 'search_api_multi_fulltext_op';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['operator'] = 'search_api_multi_fulltext_op';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['identifier'] = 'query';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Search: Index */
  $handler->display->display_options['filters']['search_api_multi_index']['id'] = 'search_api_multi_index';
  $handler->display->display_options['filters']['search_api_multi_index']['table'] = 'search_api_multi_search';
  $handler->display->display_options['filters']['search_api_multi_index']['field'] = 'search_api_multi_index';
  $handler->display->display_options['filters']['search_api_multi_index']['value'] = array(
    'downloadables' => 'downloadables',
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Videos */
  $handler = $view->new_display('panel_pane', 'Videos', 'panel_pane_4');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_multi_fulltext']['id'] = 'search_api_multi_fulltext';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['table'] = 'search_api_multi_search';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['field'] = 'search_api_multi_fulltext';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['operator_id'] = 'search_api_multi_fulltext_op';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['operator'] = 'search_api_multi_fulltext_op';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['identifier'] = 'query';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Default node index: Content type (indexed) */
  $handler->display->display_options['filters']['default_node_index_type']['id'] = 'default_node_index_type';
  $handler->display->display_options['filters']['default_node_index_type']['table'] = 'search_api_multi_search';
  $handler->display->display_options['filters']['default_node_index_type']['field'] = 'default_node_index_type';
  $handler->display->display_options['filters']['default_node_index_type']['value'] = array(
    'video' => 'video',
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: News Articles */
  $handler = $view->new_display('panel_pane', 'News Articles', 'panel_pane_5');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_multi_fulltext']['id'] = 'search_api_multi_fulltext';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['table'] = 'search_api_multi_search';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['field'] = 'search_api_multi_fulltext';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['operator_id'] = 'search_api_multi_fulltext_op';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['operator'] = 'search_api_multi_fulltext_op';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['identifier'] = 'query';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Default node index: Content type (indexed) */
  $handler->display->display_options['filters']['default_node_index_type']['id'] = 'default_node_index_type';
  $handler->display->display_options['filters']['default_node_index_type']['table'] = 'search_api_multi_search';
  $handler->display->display_options['filters']['default_node_index_type']['field'] = 'default_node_index_type';
  $handler->display->display_options['filters']['default_node_index_type']['value'] = array(
    'news_article' => 'news_article',
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Stuff to order */
  $handler = $view->new_display('panel_pane', 'Stuff to order', 'panel_pane_6');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_multi_fulltext']['id'] = 'search_api_multi_fulltext';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['table'] = 'search_api_multi_search';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['field'] = 'search_api_multi_fulltext';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['operator_id'] = 'search_api_multi_fulltext_op';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['operator'] = 'search_api_multi_fulltext_op';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['identifier'] = 'query';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Default node index: Content type (indexed) */
  $handler->display->display_options['filters']['default_node_index_type']['id'] = 'default_node_index_type';
  $handler->display->display_options['filters']['default_node_index_type']['table'] = 'search_api_multi_search';
  $handler->display->display_options['filters']['default_node_index_type']['field'] = 'default_node_index_type';
  $handler->display->display_options['filters']['default_node_index_type']['value'] = array(
    'shop_product' => 'shop_product',
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['search'] = $view;

  return $export;
}
