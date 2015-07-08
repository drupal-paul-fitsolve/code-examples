<?php
/**
 * @file
 * cr_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sr16splash_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'cr_search';
  $view->description = 'Comic Relief Search view based on Search API and Apache Solr';
  $view->tag = 'default';
  $view->base_table = 'search_api_multi_search';
  $view->human_name = 'CR Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = ' ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Sorry there were no results found, please try again.';
  $handler->display->display_options['empty']['area']['format'] = 'wysiwyg';
  /* Field: Default node index: Title (indexed) */
  $handler->display->display_options['fields']['default_node_index_title']['id'] = 'default_node_index_title';
  $handler->display->display_options['fields']['default_node_index_title']['table'] = 'search_api_multi_search';
  $handler->display->display_options['fields']['default_node_index_title']['field'] = 'default_node_index_title';
  $handler->display->display_options['fields']['default_node_index_title']['label'] = '';
  $handler->display->display_options['fields']['default_node_index_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['default_node_index_title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['default_node_index_title']['link_to_entity'] = 1;
  /* Field: Default node index: URL (indexed) */
  $handler->display->display_options['fields']['default_node_index_url']['id'] = 'default_node_index_url';
  $handler->display->display_options['fields']['default_node_index_url']['table'] = 'search_api_multi_search';
  $handler->display->display_options['fields']['default_node_index_url']['field'] = 'default_node_index_url';
  $handler->display->display_options['fields']['default_node_index_url']['label'] = '';
  $handler->display->display_options['fields']['default_node_index_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['default_node_index_url']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['default_node_index_url']['link_to_entity'] = 0;
  /* Field: Search: Relevance */
  $handler->display->display_options['fields']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['fields']['search_api_relevance']['table'] = 'search_api_multi_search';
  $handler->display->display_options['fields']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['fields']['search_api_relevance']['link_to_entity'] = 0;
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
  $handler = $view->new_display('panel_pane', 'All', 'pane_all');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Search - All';
  $handler->display->display_options['exposed_block'] = TRUE;
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
    'default_node_index' => 'default_node_index',
    'page_manager_pages' => 'page_manager_pages',
  );
  /* Filter criterion: Default node index: Content type (indexed) */
  $handler->display->display_options['filters']['default_node_index_type']['id'] = 'default_node_index_type';
  $handler->display->display_options['filters']['default_node_index_type']['table'] = 'search_api_multi_search';
  $handler->display->display_options['filters']['default_node_index_type']['field'] = 'default_node_index_type';
  $handler->display->display_options['filters']['default_node_index_type']['operator'] = '<>';
  $handler->display->display_options['filters']['default_node_index_type']['value'] = array(
    'article' => 'article',
    'page' => 'page',
    'fundraiser_showcase' => 'fundraiser_showcase',
    'media_image' => 'media_image',
    'panel' => 'panel',
    'webform' => 'webform',
  );
  $handler->display->display_options['pane_title'] = 'Search - All';
  $handler->display->display_options['pane_description'] = 'Search view for all content types';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 'path_override';
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '0';

  /* Display: Search form pane */
  $handler = $view->new_display('panel_pane', 'Search form pane', 'search_form');
  $handler->display->display_options['display_description'] = 'Pane providing the search form';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'search';
  $handler->display->display_options['exposed_block'] = TRUE;

  /* Display: Pages */
  $handler = $view->new_display('panel_pane', 'Pages', 'pane_page_manager_pages');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Search - Pages';
  $handler->display->display_options['display_description'] = 'Search pane listing panel nodes';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = '›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Search: Relevance */
  $handler->display->display_options['fields']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['fields']['search_api_relevance']['table'] = 'search_api_multi_search';
  $handler->display->display_options['fields']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['fields']['search_api_relevance']['label'] = '';
  $handler->display->display_options['fields']['search_api_relevance']['exclude'] = TRUE;
  $handler->display->display_options['fields']['search_api_relevance']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_relevance']['link_to_entity'] = 0;
  /* Field: Page Manager pages: Title (indexed) */
  $handler->display->display_options['fields']['page_manager_pages_title']['id'] = 'page_manager_pages_title';
  $handler->display->display_options['fields']['page_manager_pages_title']['table'] = 'search_api_multi_search';
  $handler->display->display_options['fields']['page_manager_pages_title']['field'] = 'page_manager_pages_title';
  $handler->display->display_options['fields']['page_manager_pages_title']['label'] = '';
  $handler->display->display_options['fields']['page_manager_pages_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['page_manager_pages_title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['page_manager_pages_title']['link_to_entity'] = 1;
  /* Field: Page Manager pages: Description (indexed) */
  $handler->display->display_options['fields']['page_manager_pages_description']['id'] = 'page_manager_pages_description';
  $handler->display->display_options['fields']['page_manager_pages_description']['table'] = 'search_api_multi_search';
  $handler->display->display_options['fields']['page_manager_pages_description']['field'] = 'page_manager_pages_description';
  $handler->display->display_options['fields']['page_manager_pages_description']['label'] = '';
  $handler->display->display_options['fields']['page_manager_pages_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['page_manager_pages_description']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['page_manager_pages_description']['link_to_entity'] = 0;
  /* Field: Page Manager pages: URI (indexed) */
  $handler->display->display_options['fields']['page_manager_pages_search_api_url']['id'] = 'page_manager_pages_search_api_url';
  $handler->display->display_options['fields']['page_manager_pages_search_api_url']['table'] = 'search_api_multi_search';
  $handler->display->display_options['fields']['page_manager_pages_search_api_url']['field'] = 'page_manager_pages_search_api_url';
  $handler->display->display_options['fields']['page_manager_pages_search_api_url']['label'] = '';
  $handler->display->display_options['fields']['page_manager_pages_search_api_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['page_manager_pages_search_api_url']['link_to_entity'] = 0;
  /* Field: Page Manager pages: Entity type (indexed) */
  $handler->display->display_options['fields']['page_manager_pages_entity_type']['id'] = 'page_manager_pages_entity_type';
  $handler->display->display_options['fields']['page_manager_pages_entity_type']['table'] = 'search_api_multi_search';
  $handler->display->display_options['fields']['page_manager_pages_entity_type']['field'] = 'page_manager_pages_entity_type';
  $handler->display->display_options['fields']['page_manager_pages_entity_type']['label'] = '';
  $handler->display->display_options['fields']['page_manager_pages_entity_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['page_manager_pages_entity_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['page_manager_pages_entity_type']['link_to_entity'] = 0;
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
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Search: Index */
  $handler->display->display_options['filters']['search_api_multi_index']['id'] = 'search_api_multi_index';
  $handler->display->display_options['filters']['search_api_multi_index']['table'] = 'search_api_multi_search';
  $handler->display->display_options['filters']['search_api_multi_index']['field'] = 'search_api_multi_index';
  $handler->display->display_options['filters']['search_api_multi_index']['value'] = array(
    'page_manager_pages' => 'page_manager_pages',
  );
  $handler->display->display_options['filters']['search_api_multi_index']['expose']['operator_id'] = 'search_api_multi_index_op';
  $handler->display->display_options['filters']['search_api_multi_index']['expose']['label'] = 'Index';
  $handler->display->display_options['filters']['search_api_multi_index']['expose']['operator'] = 'search_api_multi_index_op';
  $handler->display->display_options['filters']['search_api_multi_index']['expose']['identifier'] = 'search_api_multi_index';
  $handler->display->display_options['pane_title'] = 'Search - Page Manager Pages';
  $handler->display->display_options['pane_description'] = 'Search across landing pages';
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Shop Products */
  $handler = $view->new_display('panel_pane', 'Shop Products', 'pane_shop_products');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Search - Shop';
  $handler->display->display_options['display_description'] = 'Shop products (Stuff to order)';
  $handler->display->display_options['exposed_block'] = TRUE;
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
    'default_node_index' => 'default_node_index',
  );
  /* Filter criterion: Default node index: Content type (indexed) */
  $handler->display->display_options['filters']['default_node_index_type']['id'] = 'default_node_index_type';
  $handler->display->display_options['filters']['default_node_index_type']['table'] = 'search_api_multi_search';
  $handler->display->display_options['filters']['default_node_index_type']['field'] = 'default_node_index_type';
  $handler->display->display_options['filters']['default_node_index_type']['value'] = array(
    'shop_product' => 'shop_product',
  );
  $handler->display->display_options['pane_title'] = 'Search - Shop Products';
  $handler->display->display_options['pane_description'] = 'Search view for all content types';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 'path_override';
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '0';

  /* Display: News Articles */
  $handler = $view->new_display('panel_pane', 'News Articles', 'pane_news_articles');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Search - News';
  $handler->display->display_options['exposed_block'] = TRUE;
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
    'default_node_index' => 'default_node_index',
  );
  /* Filter criterion: Default node index: Content type (indexed) */
  $handler->display->display_options['filters']['default_node_index_type']['id'] = 'default_node_index_type';
  $handler->display->display_options['filters']['default_node_index_type']['table'] = 'search_api_multi_search';
  $handler->display->display_options['filters']['default_node_index_type']['field'] = 'default_node_index_type';
  $handler->display->display_options['filters']['default_node_index_type']['value'] = array(
    'news_article' => 'news_article',
  );
  $handler->display->display_options['pane_title'] = 'Search - News Articles';
  $handler->display->display_options['pane_description'] = 'Search view for news articles';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 'path_override';
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '0';

  /* Display: Downloadables */
  $handler = $view->new_display('panel_pane', 'Downloadables', 'pane_downloadables');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Search - Downloadables';
  $handler->display->display_options['display_description'] = 'Searchable Downloadables (special parallel content type for search)';
  $handler->display->display_options['exposed_block'] = TRUE;
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
    'default_node_index' => 'default_node_index',
  );
  /* Filter criterion: Default node index: Content type (indexed) */
  $handler->display->display_options['filters']['default_node_index_type']['id'] = 'default_node_index_type';
  $handler->display->display_options['filters']['default_node_index_type']['table'] = 'search_api_multi_search';
  $handler->display->display_options['filters']['default_node_index_type']['field'] = 'default_node_index_type';
  $handler->display->display_options['filters']['default_node_index_type']['value'] = array(
    'search_downloadable' => 'search_downloadable',
  );
  $handler->display->display_options['pane_title'] = 'Search - Searchable Downloadables';
  $handler->display->display_options['pane_description'] = 'Search view for downloadables (special search content type)';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 'path_override';
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '0';

  /* Display: Videos */
  $handler = $view->new_display('panel_pane', 'Videos', 'pane_videos');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Search - Videos';
  $handler->display->display_options['display_description'] = 'Videos';
  $handler->display->display_options['exposed_block'] = TRUE;
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
    'default_node_index' => 'default_node_index',
  );
  /* Filter criterion: Default node index: Content type (indexed) */
  $handler->display->display_options['filters']['default_node_index_type']['id'] = 'default_node_index_type';
  $handler->display->display_options['filters']['default_node_index_type']['table'] = 'search_api_multi_search';
  $handler->display->display_options['filters']['default_node_index_type']['field'] = 'default_node_index_type';
  $handler->display->display_options['filters']['default_node_index_type']['value'] = array(
    'video' => 'video',
  );
  $handler->display->display_options['pane_title'] = 'Search - Videos';
  $handler->display->display_options['pane_description'] = 'Search view for videos';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 'path_override';
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '0';
  $export['cr_search'] = $view;

  return $export;
}
