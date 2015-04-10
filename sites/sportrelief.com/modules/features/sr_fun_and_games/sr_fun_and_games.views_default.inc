<?php
/**
 * @file
 * sr_fun_and_games.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sr_fun_and_games_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'games_leaderboard';
  $view->description = 'High scores listings for each game';
  $view->tag = 'default';
  $view->base_table = 'cr_hs_scores';
  $view->human_name = 'Games Leaderboard';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'leaderboard__entry';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="leaderboard__entry">
<a class="button button--full-width button--large button--games" href="/">Play the game</a>
</div>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_type'] = 'strong';
  $handler->display->display_options['fields']['counter']['element_class'] = 'leaderboard__entry__position grid-2 alpha mobile-grid-6';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: High Scores Entry: Username */
  $handler->display->display_options['fields']['username']['id'] = 'username';
  $handler->display->display_options['fields']['username']['table'] = 'cr_hs_scores';
  $handler->display->display_options['fields']['username']['field'] = 'username';
  $handler->display->display_options['fields']['username']['label'] = '';
  $handler->display->display_options['fields']['username']['element_type'] = 'h3';
  $handler->display->display_options['fields']['username']['element_class'] = 'leaderboard__entry__name grid-3 mobile-grid-9';
  $handler->display->display_options['fields']['username']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['username']['element_default_classes'] = FALSE;
  /* Field: High Scores Entry: Score */
  $handler->display->display_options['fields']['score']['id'] = 'score';
  $handler->display->display_options['fields']['score']['table'] = 'cr_hs_scores';
  $handler->display->display_options['fields']['score']['field'] = 'score';
  $handler->display->display_options['fields']['score']['label'] = '';
  $handler->display->display_options['fields']['score']['element_type'] = 'div';
  $handler->display->display_options['fields']['score']['element_class'] = 'leaderboard__entry__score grid-1 omega mobile-grid-3';
  $handler->display->display_options['fields']['score']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['score']['element_default_classes'] = FALSE;
  /* Sort criterion: High Scores Entry: Score */
  $handler->display->display_options['sorts']['score']['id'] = 'score';
  $handler->display->display_options['sorts']['score']['table'] = 'cr_hs_scores';
  $handler->display->display_options['sorts']['score']['field'] = 'score';
  $handler->display->display_options['sorts']['score']['order'] = 'DESC';
  /* Filter criterion: High Scores Entry: Gameid */
  $handler->display->display_options['filters']['gameid']['id'] = 'gameid';
  $handler->display->display_options['filters']['gameid']['table'] = 'cr_hs_scores';
  $handler->display->display_options['filters']['gameid']['field'] = 'gameid';

  /* Display: Jump */
  $handler = $view->new_display('block', 'Jump', 'block_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: High Scores Entry: Gameid */
  $handler->display->display_options['filters']['gameid']['id'] = 'gameid';
  $handler->display->display_options['filters']['gameid']['table'] = 'cr_hs_scores';
  $handler->display->display_options['filters']['gameid']['field'] = 'gameid';
  $handler->display->display_options['filters']['gameid']['value'] = 'jump';

  /* Display: Drop */
  $handler = $view->new_display('block', 'Drop', 'block_2');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: High Scores Entry: Gameid */
  $handler->display->display_options['filters']['gameid']['id'] = 'gameid';
  $handler->display->display_options['filters']['gameid']['table'] = 'cr_hs_scores';
  $handler->display->display_options['filters']['gameid']['field'] = 'gameid';
  $handler->display->display_options['filters']['gameid']['value'] = 'drop';

  /* Display: Hatch */
  $handler = $view->new_display('block', 'Hatch', 'block_3');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: High Scores Entry: Gameid */
  $handler->display->display_options['filters']['gameid']['id'] = 'gameid';
  $handler->display->display_options['filters']['gameid']['table'] = 'cr_hs_scores';
  $handler->display->display_options['filters']['gameid']['field'] = 'gameid';
  $handler->display->display_options['filters']['gameid']['value'] = 'hatch';
  $export['games_leaderboard'] = $view;

  $view = new view();
  $view->name = 'pledge_listing';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'cr_ig_pledge';
  $view->human_name = 'Pledge Listing';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['row_class'] = 'pledge';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = 'pledge-listing';
  $handler->display->display_options['style_options']['flexslider_views_slideshow']['optionset'] = 'fun_and_games_pledge_three';
  $handler->display->display_options['style_options']['slideshow_type'] = 'flexslider_views_slideshow';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'name' => 0,
    'age' => 0,
    'pledge' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'name' => 0,
    'age' => 0,
    'pledge' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name' => 'name',
    'age' => 'age',
  );
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<h2>Pants!</h2>
<p>Pledges not found</p>';
  $handler->display->display_options['empty']['area']['format'] = 'wysiwyg';
  /* Field: Idea Generator Pledge: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_type'] = 'h3';
  $handler->display->display_options['fields']['name']['element_class'] = 'pledge__name';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Field: Idea Generator Pledge: Age */
  $handler->display->display_options['fields']['age']['id'] = 'age';
  $handler->display->display_options['fields']['age']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['fields']['age']['field'] = 'age';
  $handler->display->display_options['fields']['age']['label'] = '';
  $handler->display->display_options['fields']['age']['element_type'] = 'span';
  $handler->display->display_options['fields']['age']['element_class'] = 'pledge__age';
  $handler->display->display_options['fields']['age']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['age']['element_default_classes'] = FALSE;
  /* Field: Idea Generator Pledge: Pledge */
  $handler->display->display_options['fields']['pledge']['id'] = 'pledge';
  $handler->display->display_options['fields']['pledge']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['fields']['pledge']['field'] = 'pledge';
  $handler->display->display_options['fields']['pledge']['label'] = '';
  $handler->display->display_options['fields']['pledge']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['pledge']['alter']['text'] = 'wants to <span class=\'pledge__category__[pledge]\'>[pledge]</span>';
  $handler->display->display_options['fields']['pledge']['element_type'] = 'div';
  $handler->display->display_options['fields']['pledge']['element_class'] = 'pledge__category';
  $handler->display->display_options['fields']['pledge']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['pledge']['element_default_classes'] = FALSE;
  /* Sort criterion: Idea Generator Pledge: Idea generator pledge ID */
  $handler->display->display_options['sorts']['id']['id'] = 'id';
  $handler->display->display_options['sorts']['id']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['sorts']['id']['field'] = 'id';
  $handler->display->display_options['sorts']['id']['order'] = 'DESC';
  /* Filter criterion: Idea Generator Pledge: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value']['value'] = '1';
  /* Filter criterion: Idea Generator Pledge: Pledge */
  $handler->display->display_options['filters']['pledge']['id'] = 'pledge';
  $handler->display->display_options['filters']['pledge']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['filters']['pledge']['field'] = 'pledge';
  $handler->display->display_options['filters']['pledge']['value'] = 'swim';

  /* Display: List */
  $handler = $view->new_display('page', 'List', 'hof_search');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Idea Generator Pledge: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['default_argument_options']['argument'] = '{\'ig\':[{\'error\'}]}';
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  /* Contextual filter: Idea Generator Pledge: Age */
  $handler->display->display_options['arguments']['age']['id'] = 'age';
  $handler->display->display_options['arguments']['age']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['arguments']['age']['field'] = 'age';
  $handler->display->display_options['arguments']['age']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['age']['default_argument_options']['argument'] = '{\'ig\':[{\'error\'}]}';
  $handler->display->display_options['arguments']['age']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['age']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['age']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'fun-and-games/hall-of-fame/search';

  /* Display: Latest Swim */
  $handler = $view->new_display('block', 'Latest Swim', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['row_class'] = 'pledge';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = 'pledge-listing';
  $handler->display->display_options['style_options']['flexslider_views_slideshow']['optionset'] = 'fun_and_games_pledge_one';
  $handler->display->display_options['style_options']['slideshow_type'] = 'flexslider_views_slideshow';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'name' => 0,
    'age' => 0,
    'pledge' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'name' => 0,
    'age' => 0,
    'pledge' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name' => 'name',
    'age' => 'age',
  );
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['block_description'] = 'Swim Pledge Listing';

  /* Display: Latest Run */
  $handler = $view->new_display('block', 'Latest Run', 'block_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['row_class'] = 'pledge';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = 'pledge-listing';
  $handler->display->display_options['style_options']['flexslider_views_slideshow']['optionset'] = 'two';
  $handler->display->display_options['style_options']['slideshow_type'] = 'flexslider_views_slideshow';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'name' => 0,
    'age' => 0,
    'pledge' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'name' => 0,
    'age' => 0,
    'pledge' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name' => 'name',
    'age' => 'age',
  );
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Idea Generator Pledge: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value']['value'] = '1';
  /* Filter criterion: Idea Generator Pledge: Pledge */
  $handler->display->display_options['filters']['pledge']['id'] = 'pledge';
  $handler->display->display_options['filters']['pledge']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['filters']['pledge']['field'] = 'pledge';
  $handler->display->display_options['filters']['pledge']['value'] = 'run';

  /* Display: Latest Cycle */
  $handler = $view->new_display('block', 'Latest Cycle', 'block_3');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['row_class'] = 'pledge';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = 'pledge-listing';
  $handler->display->display_options['style_options']['flexslider_views_slideshow']['optionset'] = 'fun_and_games_pledge_three';
  $handler->display->display_options['style_options']['slideshow_type'] = 'flexslider_views_slideshow';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'name' => 0,
    'age' => 0,
    'pledge' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'name' => 0,
    'age' => 0,
    'pledge' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name' => 'name',
    'age' => 'age',
  );
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Idea Generator Pledge: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value']['value'] = '1';
  /* Filter criterion: Idea Generator Pledge: Pledge */
  $handler->display->display_options['filters']['pledge']['id'] = 'pledge';
  $handler->display->display_options['filters']['pledge']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['filters']['pledge']['field'] = 'pledge';
  $handler->display->display_options['filters']['pledge']['value'] = 'cycle';
  $export['pledge_listing'] = $view;

  return $export;
}
