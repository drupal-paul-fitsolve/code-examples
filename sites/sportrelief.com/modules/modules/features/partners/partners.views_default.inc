<?php
/**
 * @file
 * partners.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function partners_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'partner_endpoint';
  $view->description = 'Returns a full view mode entity of your choice';
  $view->tag = 'endpoint';
  $view->base_table = 'fieldable_panels_panes';
  $view->human_name = 'Fieldable Panel Pane Endpoint';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Partner Endpoint';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  /* Field: Fieldable pane: Fieldable pane ID */
  $handler->display->display_options['fields']['fpid']['id'] = 'fpid';
  $handler->display->display_options['fields']['fpid']['table'] = 'fieldable_panels_panes';
  $handler->display->display_options['fields']['fpid']['field'] = 'fpid';
  /* Contextual filter: Fieldable pane: Fieldable panel pane UUID */
  $handler->display->display_options['arguments']['uuid']['id'] = 'uuid';
  $handler->display->display_options['arguments']['uuid']['table'] = 'fieldable_panels_panes';
  $handler->display->display_options['arguments']['uuid']['field'] = 'uuid';
  $handler->display->display_options['arguments']['uuid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uuid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uuid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uuid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uuid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uuid']['limit'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'fpp-endpoint';
  $export['partner_endpoint'] = $view;

  return $export;
}
