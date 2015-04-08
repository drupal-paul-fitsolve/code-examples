<?php
/**
 * @file
 * sr_schools.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sr_schools_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'schools_toolbox';
  $view->description = 'Schools Promo Area';
  $view->tag = 'default';
  $view->base_table = 'fieldable_panels_panes';
  $view->human_name = 'Schools Toolbox';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Schools Toolbox';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['flexslider_views_slideshow']['optionset'] = 'main_slide';
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
    'field_image' => 0,
    'title' => 0,
    'field_body' => 0,
    'field_download_all' => 0,
    'field_download_item' => 0,
    'nothing' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_image' => 0,
    'title' => 0,
    'field_body' => 0,
    'field_download_all' => 0,
    'field_download_item' => 0,
    'nothing' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'grid-4-narrow',
    'image_link' => '',
  );
  /* Field: Fieldable pane: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'fieldable_panels_panes';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'p';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Filter criterion: Fieldable pane: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'fieldable_panels_panes';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = array(
    'schools_download' => 'schools_download',
  );
  /* Filter criterion: Fieldable panel pane: Schools Category (field_schools_category) */
  $handler->display->display_options['filters']['field_schools_category_tid']['id'] = 'field_schools_category_tid';
  $handler->display->display_options['filters']['field_schools_category_tid']['table'] = 'field_data_field_schools_category';
  $handler->display->display_options['filters']['field_schools_category_tid']['field'] = 'field_schools_category_tid';
  $handler->display->display_options['filters']['field_schools_category_tid']['value'] = array(
    0 => '14',
  );
  $handler->display->display_options['filters']['field_schools_category_tid']['vocabulary'] = 'schools_toolbox_category';

  /* Display: Primary Schools Main */
  $handler = $view->new_display('block', 'Primary Schools Main', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['row_class'] = 'schools-toolbox-slides';
  $handler->display->display_options['style_options']['wrapper_class'] = 'schools-toolbox-slides';
  $handler->display->display_options['style_options']['flexslider_views_slideshow']['optionset'] = 'schools_slides';
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
    'field_image' => 0,
    'title' => 0,
    'field_body' => 0,
    'field_download_all' => 0,
    'field_download_item' => 0,
    'nothing' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_image' => 0,
    'title' => 0,
    'field_body' => 0,
    'field_download_all' => 0,
    'field_download_item' => 0,
    'nothing' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Fieldable panel pane: Video */
  $handler->display->display_options['fields']['field_video']['id'] = 'field_video';
  $handler->display->display_options['fields']['field_video']['table'] = 'field_data_field_video';
  $handler->display->display_options['fields']['field_video']['field'] = 'field_video';
  $handler->display->display_options['fields']['field_video']['label'] = '';
  $handler->display->display_options['fields']['field_video']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_video']['element_class'] = 'grid-12 narrow-grid-24 alpha clearfix';
  $handler->display->display_options['fields']['field_video']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_video']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_video']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_video']['settings'] = array(
    'view_mode' => 'grid_12_promo_node',
    'links' => 0,
  );
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_image']['element_wrapper_class'] = 'grid-12 narrow-grid-24 alpha clearfix';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['type'] = 'picture';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'picture_group' => 'grid_12_promo',
    'fallback_image_style' => '',
    'image_link' => '',
    'colorbox' => 'grid_12_promo',
  );
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_image']['multi_type'] = 'ul';
  /* Field: Fieldable pane: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'fieldable_panels_panes';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Field: Description */
  $handler->display->display_options['fields']['field_body']['id'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['table'] = 'field_data_field_body';
  $handler->display->display_options['fields']['field_body']['field'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['label'] = '';
  $handler->display->display_options['fields']['field_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_body']['element_label_colon'] = FALSE;
  /* Field: Fieldable panel pane: Download All */
  $handler->display->display_options['fields']['field_download_all']['id'] = 'field_download_all';
  $handler->display->display_options['fields']['field_download_all']['table'] = 'field_data_field_download_all';
  $handler->display->display_options['fields']['field_download_all']['field'] = 'field_download_all';
  $handler->display->display_options['fields']['field_download_all']['label'] = '';
  $handler->display->display_options['fields']['field_download_all']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_download_all']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_download_all']['alter']['preserve_tags'] = '<a> <span>';
  $handler->display->display_options['fields']['field_download_all']['element_type'] = '0';
  $handler->display->display_options['fields']['field_download_all']['element_class'] = 'button button--large';
  $handler->display->display_options['fields']['field_download_all']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_download_all']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_download_all']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_download_all']['type'] = 'cr_general_list_downloadables_ctaonly';
  $handler->display->display_options['fields']['field_download_all']['settings'] = array(
    'field_name' => 'field_downloadable',
    'field_css_class' => '',
  );
  /* Field: Fieldable panel pane: Download Item */
  $handler->display->display_options['fields']['field_download_item']['id'] = 'field_download_item';
  $handler->display->display_options['fields']['field_download_item']['table'] = 'field_data_field_download_item';
  $handler->display->display_options['fields']['field_download_item']['field'] = 'field_download_item';
  $handler->display->display_options['fields']['field_download_item']['label'] = '';
  $handler->display->display_options['fields']['field_download_item']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_download_item']['element_class'] = 'cta--downloadable';
  $handler->display->display_options['fields']['field_download_item']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_download_item']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_download_item']['type'] = 'cr_general_list_downloadables_ctaonly';
  $handler->display->display_options['fields']['field_download_item']['settings'] = array(
    'field_name' => 'field_downloadable',
    'field_css_class' => '',
  );
  $handler->display->display_options['fields']['field_download_item']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="grid-12 narrow-grid-24 omega clearfix tab-slide">
	<h2 class="pod__title">[title]</h2>
	<div class="pod__body">
		[field_body]
		<p class="button--donwload-all">[field_download_all]</p>
		<div class="download-list">[field_download_item]</div>
	</div>
</div>
';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Fieldable pane: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'fieldable_panels_panes';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = array(
    'schools_download' => 'schools_download',
  );
  /* Filter criterion: Fieldable panel pane: Schools Category (field_schools_category) */
  $handler->display->display_options['filters']['field_schools_category_tid']['id'] = 'field_schools_category_tid';
  $handler->display->display_options['filters']['field_schools_category_tid']['table'] = 'field_data_field_schools_category';
  $handler->display->display_options['filters']['field_schools_category_tid']['field'] = 'field_schools_category_tid';
  $handler->display->display_options['filters']['field_schools_category_tid']['value'] = array(
    14 => '14',
  );
  $handler->display->display_options['filters']['field_schools_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_schools_category_tid']['vocabulary'] = 'schools_toolbox_category';

  /* Display: Primary Schools Control */
  $handler = $view->new_display('attachment', 'Primary Schools Control', 'attachment_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'tabs--schools-nav';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['flexslider_views_slideshow']['optionset'] = 'schools_nav';
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
    'field_image' => 0,
    'title' => 0,
    'nothing' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_image' => 0,
    'title' => 0,
    'nothing' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['type'] = 'picture';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'picture_group' => 'grid_4',
    'fallback_image_style' => '',
    'image_link' => '',
    'colorbox' => 'grid_4',
  );
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Fieldable pane: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'fieldable_panels_panes';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="grid-8">
	<div class="content-container grid-7 prefix-1">
		<div class="tab-nav--image grid-3">[field_image]</div>
		<div class="tab-nav--title grid-4"><p>[title]</p></div>
	</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'block' => 'block',
    'default' => 0,
  );

  /* Display: Secondary Schools Main */
  $handler = $view->new_display('block', 'Secondary Schools Main', 'block_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'tab-test';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['row_class'] = 'schools-toolbox-slides';
  $handler->display->display_options['style_options']['wrapper_class'] = 'schools-toolbox-slides';
  $handler->display->display_options['style_options']['flexslider_views_slideshow']['optionset'] = 'schools_slides';
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
    'field_image' => 0,
    'title' => 0,
    'field_body' => 0,
    'field_download_all' => 0,
    'field_download_item' => 0,
    'nothing' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_image' => 0,
    'title' => 0,
    'field_body' => 0,
    'field_download_all' => 0,
    'field_download_item' => 0,
    'nothing' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Fieldable panel pane: Video */
  $handler->display->display_options['fields']['field_video']['id'] = 'field_video';
  $handler->display->display_options['fields']['field_video']['table'] = 'field_data_field_video';
  $handler->display->display_options['fields']['field_video']['field'] = 'field_video';
  $handler->display->display_options['fields']['field_video']['label'] = '';
  $handler->display->display_options['fields']['field_video']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_video']['element_class'] = 'grid-12 narrow-grid-24 alpha clearfix';
  $handler->display->display_options['fields']['field_video']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_video']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_video']['settings'] = array(
    'view_mode' => 'grid_12_promo_node',
    'links' => 0,
  );
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_image']['element_wrapper_class'] = 'grid-12 narrow-grid-24 alpha clearfix';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['type'] = 'picture';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'picture_group' => 'grid_12_promo',
    'fallback_image_style' => '',
    'image_link' => '',
    'colorbox' => 'grid_13_promo',
  );
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_image']['multi_type'] = 'ul';
  /* Field: Fieldable pane: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'fieldable_panels_panes';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Field: Description */
  $handler->display->display_options['fields']['field_body']['id'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['table'] = 'field_data_field_body';
  $handler->display->display_options['fields']['field_body']['field'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['label'] = '';
  $handler->display->display_options['fields']['field_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_body']['element_label_colon'] = FALSE;
  /* Field: Fieldable panel pane: Download All */
  $handler->display->display_options['fields']['field_download_all']['id'] = 'field_download_all';
  $handler->display->display_options['fields']['field_download_all']['table'] = 'field_data_field_download_all';
  $handler->display->display_options['fields']['field_download_all']['field'] = 'field_download_all';
  $handler->display->display_options['fields']['field_download_all']['label'] = '';
  $handler->display->display_options['fields']['field_download_all']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_download_all']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_download_all']['alter']['preserve_tags'] = '<a> <span>';
  $handler->display->display_options['fields']['field_download_all']['element_type'] = '0';
  $handler->display->display_options['fields']['field_download_all']['element_class'] = 'button button--large';
  $handler->display->display_options['fields']['field_download_all']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_download_all']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_download_all']['type'] = 'cr_general_list_downloadables_ctaonly';
  $handler->display->display_options['fields']['field_download_all']['settings'] = array(
    'field_name' => 'field_downloadable',
  );
  /* Field: Fieldable panel pane: Download Item */
  $handler->display->display_options['fields']['field_download_item']['id'] = 'field_download_item';
  $handler->display->display_options['fields']['field_download_item']['table'] = 'field_data_field_download_item';
  $handler->display->display_options['fields']['field_download_item']['field'] = 'field_download_item';
  $handler->display->display_options['fields']['field_download_item']['label'] = '';
  $handler->display->display_options['fields']['field_download_item']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_download_item']['element_class'] = 'cta--downloadable';
  $handler->display->display_options['fields']['field_download_item']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_download_item']['type'] = 'cr_general_list_downloadables_ctaonly';
  $handler->display->display_options['fields']['field_download_item']['settings'] = array(
    'field_name' => 'field_downloadable',
  );
  $handler->display->display_options['fields']['field_download_item']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="grid-12 narrow-grid-24 omega clearfix tab-slide">
	<h2 class="pod__title">[title]</h2>
	<div class="pod__body">
		[field_body]
		<p class="button--donwload-all">[field_download_all]</p>
		<div class="download-list">[field_download_item]</div>
	</div>
</div>
';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Fieldable pane: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'fieldable_panels_panes';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = array(
    'schools_download' => 'schools_download',
  );
  /* Filter criterion: Fieldable panel pane: Schools Category (field_schools_category) */
  $handler->display->display_options['filters']['field_schools_category_tid']['id'] = 'field_schools_category_tid';
  $handler->display->display_options['filters']['field_schools_category_tid']['table'] = 'field_data_field_schools_category';
  $handler->display->display_options['filters']['field_schools_category_tid']['field'] = 'field_schools_category_tid';
  $handler->display->display_options['filters']['field_schools_category_tid']['value'] = array(
    15 => '15',
  );
  $handler->display->display_options['filters']['field_schools_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_schools_category_tid']['vocabulary'] = 'schools_toolbox_category';

  /* Display: Secondary Schools Control */
  $handler = $view->new_display('attachment', 'Secondary Schools Control', 'attachment_2');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'tabs--schools-nav';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['flexslider_views_slideshow']['optionset'] = 'schools_nav';
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
    'field_image' => 0,
    'title' => 0,
    'nothing' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_image' => 0,
    'title' => 0,
    'nothing' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['type'] = 'picture';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'picture_group' => 'grid_4',
    'fallback_image_style' => '',
    'image_link' => '',
    'colorbox' => 'grid_4',
  );
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Fieldable pane: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'fieldable_panels_panes';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="grid-8">
	<div class="content-container grid-7 prefix-1">
		<div class="tab-nav--image grid-3">[field_image]</div>
		<div class="tab-nav--title grid-4"><p>[title]</p></div>
	</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Fieldable pane: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'fieldable_panels_panes';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = array(
    'schools_download' => 'schools_download',
  );
  /* Filter criterion: Fieldable panel pane: Schools Category (field_schools_category) */
  $handler->display->display_options['filters']['field_schools_category_tid']['id'] = 'field_schools_category_tid';
  $handler->display->display_options['filters']['field_schools_category_tid']['table'] = 'field_data_field_schools_category';
  $handler->display->display_options['filters']['field_schools_category_tid']['field'] = 'field_schools_category_tid';
  $handler->display->display_options['filters']['field_schools_category_tid']['value'] = array(
    0 => '15',
  );
  $handler->display->display_options['filters']['field_schools_category_tid']['vocabulary'] = 'schools_toolbox_category';
  $handler->display->display_options['displays'] = array(
    'block_1' => 'block_1',
    'default' => 0,
    'block' => 0,
  );
  $export['schools_toolbox'] = $view;

  return $export;
}
