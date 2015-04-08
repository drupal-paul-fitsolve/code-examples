<?php
/**
 * @file
 * partners.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function partners_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'partners';
  $page->task = 'page';
  $page->admin_title = 'Partners';
  $page->admin_description = 'The Partner listing page';
  $page->path = 'partners';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Partners',
    'weight' => '0',
    'name' => 'main-menu',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'weight' => 0,
      'name' => 'navigation',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_partners_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'partners';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Landing page',
    'no_blocks' => FALSE,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'cr_layout_content_promo';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'row1_col1' => NULL,
      'row1_col2' => NULL,
      'row1_col3' => NULL,
      'row1_col4' => NULL,
      'row2_col1' => NULL,
      'row2_col2' => NULL,
      'row2_col3' => NULL,
      'row2_col4' => NULL,
      'row3_col2' => NULL,
      'row3_col3' => NULL,
      'row3_col4' => NULL,
      'row4_col1' => NULL,
      'row4_col2' => NULL,
      'row4_col3' => NULL,
      'row4_col4' => NULL,
      'row5_col1' => NULL,
      'row5_col2' => NULL,
      'row5_col3' => NULL,
      'row5_col4' => NULL,
      'row6_col1' => NULL,
      'row6_col2' => NULL,
      'row6_col3' => NULL,
      'row6_col4' => NULL,
      'subpod1' => NULL,
      'subpod2' => NULL,
      'subpod3' => NULL,
    ),
    'top' => array(
      'style' => 'naked',
    ),
    'row3_col1' => array(
      'style' => 'grey',
    ),
    'row3_col2' => array(
      'style' => 'grey',
    ),
  );
  $display->cache = array();
  $display->title = 'Partners';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'row1_col1';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:940fe5b7-1214-47f6-9b40-5608607861f1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'panelayout',
      'settings' => array(),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-1'] = $pane;
    $display->panels['row1_col1'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'row2_col1';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:f00a71a9-d37f-450b-ae75-163998a8a7e3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'panelayout',
      'settings' => array(),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-2'] = $pane;
    $display->panels['row2_col1'][0] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'row3_col1';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:39fe71e8-d2a1-4bcf-a71a-59011d3ab9b7';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'list_view',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'semantic_panels',
      'settings' => array(
        'element_title' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_content' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_wrapper' => array(
          'type' => 'div',
          'class_enable' => 1,
          'class' => 'partner',
          'attributes' => array(),
          'attributes_array' => array(),
        ),
        'add_default_classes' => 0,
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-3'] = $pane;
    $display->panels['row3_col1'][0] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'row3_col2';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:978e78d5-b6ac-4a2d-a799-60165225c047';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'list_view',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'semantic_panels',
      'settings' => array(
        'element_title' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_content' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_wrapper' => array(
          'type' => '',
          'class_enable' => 1,
          'class' => 'partner',
          'attributes' => array(),
          'attributes_array' => array(),
        ),
        'add_default_classes' => 0,
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-4'] = $pane;
    $display->panels['row3_col2'][0] = 'new-4';
    $pane = new stdClass();
    $pane->pid = 'new-5';
    $pane->panel = 'row3_col3';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:b41d4743-4b4a-46fc-a13e-24a18899fe54';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'list_view',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'semantic_panels',
      'settings' => array(
        'element_title' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_content' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_wrapper' => array(
          'type' => '',
          'class_enable' => 1,
          'class' => 'partner',
          'attributes' => array(),
          'attributes_array' => array(),
        ),
        'add_default_classes' => 0,
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-5'] = $pane;
    $display->panels['row3_col3'][0] = 'new-5';
    $pane = new stdClass();
    $pane->pid = 'new-6';
    $pane->panel = 'row3_col4';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:0286bd50-6981-4365-9a28-5a17a1552b0a';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'list_view',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'semantic_panels',
      'settings' => array(
        'element_title' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_content' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_wrapper' => array(
          'type' => '',
          'class_enable' => 1,
          'class' => 'partner',
          'attributes' => array(),
          'attributes_array' => array(),
        ),
        'add_default_classes' => 0,
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-6'] = $pane;
    $display->panels['row3_col4'][0] = 'new-6';
    $pane = new stdClass();
    $pane->pid = 'new-7';
    $pane->panel = 'row4_col1';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:088ec53b-477a-47c4-ba1f-21c5dce3afb8';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'list_view',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'semantic_panels',
      'settings' => array(
        'element_title' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_content' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_wrapper' => array(
          'type' => '',
          'class_enable' => 1,
          'class' => 'partner',
          'attributes' => array(),
          'attributes_array' => array(),
        ),
        'add_default_classes' => 0,
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-7'] = $pane;
    $display->panels['row4_col1'][0] = 'new-7';
    $pane = new stdClass();
    $pane->pid = 'new-8';
    $pane->panel = 'row4_col2';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:4f9ee22d-ed64-4233-a790-60f92b03fb46';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'list_view',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'semantic_panels',
      'settings' => array(
        'element_title' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_content' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_wrapper' => array(
          'type' => '',
          'class_enable' => 1,
          'class' => 'partner',
          'attributes' => array(),
          'attributes_array' => array(),
        ),
        'add_default_classes' => 0,
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-8'] = $pane;
    $display->panels['row4_col2'][0] = 'new-8';
    $pane = new stdClass();
    $pane->pid = 'new-9';
    $pane->panel = 'row4_col3';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:645eba1d-7629-4441-8b91-949322347b19';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'list_view',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'semantic_panels',
      'settings' => array(
        'element_title' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_content' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_wrapper' => array(
          'type' => '',
          'class_enable' => 1,
          'class' => 'partner',
          'attributes' => array(),
          'attributes_array' => array(),
        ),
        'add_default_classes' => 0,
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-9'] = $pane;
    $display->panels['row4_col3'][0] = 'new-9';
    $pane = new stdClass();
    $pane->pid = 'new-10';
    $pane->panel = 'row4_col4';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:103fbaba-8865-4fed-863a-e528d160473f';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'list_view',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'semantic_panels',
      'settings' => array(
        'element_title' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_content' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_wrapper' => array(
          'type' => '',
          'class_enable' => 1,
          'class' => 'partner',
          'attributes' => array(),
          'attributes_array' => array(),
        ),
        'add_default_classes' => 0,
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-10'] = $pane;
    $display->panels['row4_col4'][0] = 'new-10';
    $pane = new stdClass();
    $pane->pid = 'new-11';
    $pane->panel = 'row5_col1';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:8913e696-8f5f-4193-834c-1d803f2b428e';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'list_view',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'semantic_panels',
      'settings' => array(
        'element_title' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_content' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_wrapper' => array(
          'type' => '',
          'class_enable' => 1,
          'class' => 'partner',
          'attributes' => array(),
          'attributes_array' => array(),
        ),
        'add_default_classes' => 0,
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-11'] = $pane;
    $display->panels['row5_col1'][0] = 'new-11';
    $pane = new stdClass();
    $pane->pid = 'new-12';
    $pane->panel = 'row5_col2';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:720c11b1-5570-47d2-af7d-9b7f3e079033';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'list_view',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'semantic_panels',
      'settings' => array(
        'element_title' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_content' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_wrapper' => array(
          'type' => '',
          'class_enable' => 1,
          'class' => 'partner',
          'attributes' => array(),
          'attributes_array' => array(),
        ),
        'add_default_classes' => 0,
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-12'] = $pane;
    $display->panels['row5_col2'][0] = 'new-12';
    $pane = new stdClass();
    $pane->pid = 'new-13';
    $pane->panel = 'row5_col3';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:5c88591f-76f9-4a85-ab8c-a3a97ed838b5';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'list_view',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'semantic_panels',
      'settings' => array(
        'element_title' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_content' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_wrapper' => array(
          'type' => '',
          'class_enable' => 1,
          'class' => 'partner',
          'attributes' => array(),
          'attributes_array' => array(),
        ),
        'add_default_classes' => 0,
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-13'] = $pane;
    $display->panels['row5_col3'][0] = 'new-13';
    $pane = new stdClass();
    $pane->pid = 'new-14';
    $pane->panel = 'row5_col4';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:c289aff1-3f9c-4819-987a-4e113a06ea3a';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'list_view',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'semantic_panels',
      'settings' => array(
        'element_title' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_content' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_wrapper' => array(
          'type' => '',
          'class_enable' => 1,
          'class' => 'partner',
          'attributes' => array(),
          'attributes_array' => array(),
        ),
        'add_default_classes' => 0,
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-14'] = $pane;
    $display->panels['row5_col4'][0] = 'new-14';
    $pane = new stdClass();
    $pane->pid = 'new-15';
    $pane->panel = 'row6_col1';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:a44d28a9-43a1-4630-966a-d72a42fcdeb0';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'panelayout',
      'settings' => array(),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-15'] = $pane;
    $display->panels['row6_col1'][0] = 'new-15';
    $pane = new stdClass();
    $pane->pid = 'new-16';
    $pane->panel = 'row7_col1';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:b8c93416-489b-4fc2-bf47-12db30079e89';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'list_view',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'semantic_panels',
      'settings' => array(
        'element_title' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_content' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_wrapper' => array(
          'type' => '',
          'class_enable' => 1,
          'class' => 'partner',
          'attributes' => array(),
          'attributes_array' => array(),
        ),
        'add_default_classes' => 0,
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-16'] = $pane;
    $display->panels['row7_col1'][0] = 'new-16';
    $pane = new stdClass();
    $pane->pid = 'new-17';
    $pane->panel = 'row7_col2';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:36b1ccc9-e50d-48e6-8aa7-77e66c260682';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'list_view',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'semantic_panels',
      'settings' => array(
        'element_title' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_content' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_wrapper' => array(
          'type' => '',
          'class_enable' => 1,
          'class' => 'partner',
          'attributes' => array(),
          'attributes_array' => array(),
        ),
        'add_default_classes' => 0,
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-17'] = $pane;
    $display->panels['row7_col2'][0] = 'new-17';
    $pane = new stdClass();
    $pane->pid = 'new-18';
    $pane->panel = 'row7_col3';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:83a8ae24-a32a-4f2e-a993-76c38279c2ba';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'list_view',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'semantic_panels',
      'settings' => array(
        'element_title' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_content' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_wrapper' => array(
          'type' => '',
          'class_enable' => 1,
          'class' => 'partner',
          'attributes' => array(),
          'attributes_array' => array(),
        ),
        'add_default_classes' => 0,
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-18'] = $pane;
    $display->panels['row7_col3'][0] = 'new-18';
    $pane = new stdClass();
    $pane->pid = 'new-19';
    $pane->panel = 'row7_col4';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:fdc6edd1-2942-4abf-8972-6dbbfca8940c';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'list_view',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'semantic_panels',
      'settings' => array(
        'element_title' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_content' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_wrapper' => array(
          'type' => '',
          'class_enable' => 1,
          'class' => 'partner',
          'attributes' => array(),
          'attributes_array' => array(),
        ),
        'add_default_classes' => 0,
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-19'] = $pane;
    $display->panels['row7_col4'][0] = 'new-19';
    $pane = new stdClass();
    $pane->pid = 'new-20';
    $pane->panel = 'row8_col1';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:9b0bf8dc-a7cc-4090-8dab-ef226738ca6a';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'panelayout',
      'settings' => array(),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-20'] = $pane;
    $display->panels['row8_col1'][0] = 'new-20';
    $pane = new stdClass();
    $pane->pid = 'new-21';
    $pane->panel = 'row9_col1';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:a0fe884c-81a6-4ca5-8b51-72236c087797';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'list_view',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'semantic_panels',
      'settings' => array(
        'element_title' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_content' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_wrapper' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => 'partner',
          'attributes' => array(),
          'attributes_array' => array(),
        ),
        'add_default_classes' => 0,
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-21'] = $pane;
    $display->panels['row9_col1'][0] = 'new-21';
    $pane = new stdClass();
    $pane->pid = 'new-22';
    $pane->panel = 'row9_col2';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:5473d67a-4e94-43d6-8cd7-05b3092098bd';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'list_view',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'semantic_panels',
      'settings' => array(
        'element_title' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_content' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_wrapper' => array(
          'type' => '',
          'class_enable' => 1,
          'class' => 'partner',
          'attributes' => array(),
          'attributes_array' => array(),
        ),
        'add_default_classes' => 0,
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-22'] = $pane;
    $display->panels['row9_col2'][0] = 'new-22';
    $pane = new stdClass();
    $pane->pid = 'new-23';
    $pane->panel = 'row9_col3';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:bd195d9b-2773-4c8b-ad4f-ca685a7c29d8';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'list_view',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'semantic_panels',
      'settings' => array(
        'element_title' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_content' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_wrapper' => array(
          'type' => '',
          'class_enable' => 1,
          'class' => 'partner',
          'attributes' => array(),
          'attributes_array' => array(),
        ),
        'add_default_classes' => 0,
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-23'] = $pane;
    $display->panels['row9_col3'][0] = 'new-23';
    $pane = new stdClass();
    $pane->pid = 'new-24';
    $pane->panel = 'row9_col4';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:8bc3c53a-1d63-43e0-9726-d2b121a5b79f';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'list_view',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'semantic_panels',
      'settings' => array(
        'element_title' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_content' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_wrapper' => array(
          'type' => '',
          'class_enable' => 1,
          'class' => 'partner',
          'attributes' => array(),
          'attributes_array' => array(),
        ),
        'add_default_classes' => 0,
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-24'] = $pane;
    $display->panels['row9_col4'][0] = 'new-24';
    $pane = new stdClass();
    $pane->pid = 'new-25';
    $pane->panel = 'top';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:4e6955fc-7dfa-49b6-8a44-50c722b650cd';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'semantic_panels',
      'settings' => array(
        'element_title' => array(
          'type' => '0',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_content' => array(
          'type' => '0',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_wrapper' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => 'grey-background leader',
          'attributes' => array(),
          'attributes_array' => array(),
        ),
        'add_default_classes' => 0,
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-25'] = $pane;
    $display->panels['top'][0] = 'new-25';
    $pane = new stdClass();
    $pane->pid = 'new-26';
    $pane->panel = 'top';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:5efe3205-d97d-4bda-aab1-fbc72a192f31';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'semantic_panels',
      'settings' => array(
        'element_title' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_content' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => '',
          'attributes' => array(),
          'link_enabled' => 0,
          'link' => array(
            'path' => '',
            'class_enable' => 0,
            'class' => '',
            'attributes' => array(),
            'attributes_array' => array(),
          ),
          'attributes_array' => array(),
        ),
        'element_wrapper' => array(
          'type' => '',
          'class_enable' => 0,
          'class' => 'leader-minor text-align-center',
          'attributes' => array(),
          'attributes_array' => array(),
        ),
        'add_default_classes' => 0,
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-26'] = $pane;
    $display->panels['top'][1] = 'new-26';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['partners'] = $page;

  return $pages;

}
