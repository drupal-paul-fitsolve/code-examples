<?php
/**
 * @file
 * sr16splash_site_page_manager_node.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function sr16splash_site_page_manager_node_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Videos',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => 'node-type-video',
    'body_classes_to_add' => 'node--video',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'video' => 'video',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'cr-content';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'first' => array(
        'section_full_width' => 0,
        'classes_section' => '',
        'classes_container' => '',
        'classes_row' => '',
      ),
      'third' => array(
        'section_full_width' => 0,
        'classes_section' => '',
        'classes_container' => '',
        'classes_row' => '',
      ),
      'fourth' => array(
        'section_full_width' => 0,
        'classes_section' => '',
        'classes_container' => '',
        'classes_row' => '',
      ),
      'fifth' => NULL,
      'sixth' => NULL,
      'seven' => NULL,
      'eight' => NULL,
      'ninth' => NULL,
      'tenth' => NULL,
      'eleventh' => NULL,
      'twelfth' => NULL,
      'second' => array(
        'section_full_width' => 0,
        'classes_section' => '',
        'classes_container' => '',
        'classes_row' => 'row--padding-none',
      ),
    ),
    'second' => array(
      'style' => 'section',
    ),
    'first' => array(
      'style' => 'section',
    ),
    'third' => array(
      'style' => 'section',
    ),
    'fourth' => array(
      'style' => 'section',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f845de71-1f71-4871-a4ee-bab6aa43d19f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fb973e29-c057-4cb7-83b9-26aa476ba07a';
    $pane->panel = 'first';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => 'type--centred type--md',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'pane',
      'settings' => array(
        'use_columns' => 1,
        'columns' => array(
          'xs' => 'col_xs_12',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
          'images_only' => 0,
        ),
        'use_offset' => 0,
        'offset' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_push' => 0,
        'push' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_pull' => 0,
        'pull' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_visibility' => 0,
        'visibility' => array(
          'show_help' => 0,
          'hidden' => array(
            'hidden_xs' => 0,
            'hidden_sm' => 0,
            'hidden_md' => 0,
            'hidden_lg' => 0,
          ),
        ),
        'use_custom_classes' => 0,
        'custom_classes' => array(
          'show_help' => 0,
          'custom_classes' => '',
        ),
        'use_matchheight' => 0,
        'matchheight' => array(
          'group_existing' => '_new',
          'group_new' => '',
        ),
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fb973e29-c057-4cb7-83b9-26aa476ba07a';
    $display->content['new-fb973e29-c057-4cb7-83b9-26aa476ba07a'] = $pane;
    $display->panels['first'][0] = 'new-fb973e29-c057-4cb7-83b9-26aa476ba07a';
    $pane = new stdClass();
    $pane->pid = 'new-77f8cbe0-ddeb-4f56-8e65-c06a5089bf54';
    $pane->panel = 'second';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'pane',
      'settings' => array(
        'use_columns' => 1,
        'columns' => array(
          'xs' => 'col_xs_12',
          'sm' => 'col_sm_8',
          'md' => 'inherit',
          'lg' => 'inherit',
          'images_only' => 0,
        ),
        'use_offset' => 0,
        'offset' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_push' => 1,
        'push' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'col_sm_push_2',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_pull' => 0,
        'pull' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_visibility' => 0,
        'visibility' => array(
          'show_help' => 0,
          'hidden' => array(
            'hidden_xs' => 0,
            'hidden_sm' => 0,
            'hidden_md' => 0,
            'hidden_lg' => 0,
          ),
        ),
        'use_custom_classes' => 0,
        'custom_classes' => array(
          'show_help' => 0,
          'custom_classes' => '',
        ),
        'use_data_attributes' => 0,
        'data_attributes' => array(
          'data_attribute' => array(
            1 => array(
              'key' => '',
              'value' => '',
            ),
            2 => array(
              'key' => '',
              'value' => '',
            ),
            3 => array(
              'key' => '',
              'value' => '',
            ),
            4 => array(
              'key' => '',
              'value' => '',
            ),
            5 => array(
              'key' => '',
              'value' => '',
            ),
          ),
        ),
        'use_matchheight' => 0,
        'matchheight' => array(
          'group_existing' => '_new',
          'group_new' => '',
        ),
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '77f8cbe0-ddeb-4f56-8e65-c06a5089bf54';
    $display->content['new-77f8cbe0-ddeb-4f56-8e65-c06a5089bf54'] = $pane;
    $display->panels['second'][0] = 'new-77f8cbe0-ddeb-4f56-8e65-c06a5089bf54';
    $pane = new stdClass();
    $pane->pid = 'new-2f37490a-7d5b-469f-a7d1-859d5b2642fd';
    $pane->panel = 'third';
    $pane->type = 'bean_panels';
    $pane->subtype = 'bean_panels';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'default',
      'bean_delta' => 'share-links-all-media',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'pane',
      'settings' => array(
        'use_columns' => 1,
        'columns' => array(
          'xs' => 'col_xs_12',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
          'images_only' => 0,
        ),
        'use_offset' => 0,
        'offset' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_push' => 0,
        'push' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_pull' => 0,
        'pull' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_visibility' => 0,
        'visibility' => array(
          'show_help' => 0,
          'hidden' => array(
            'hidden_xs' => 0,
            'hidden_sm' => 0,
            'hidden_md' => 0,
            'hidden_lg' => 0,
          ),
        ),
        'use_custom_classes' => 0,
        'custom_classes' => array(
          'show_help' => 0,
          'custom_classes' => '',
        ),
        'use_data_attributes' => 0,
        'data_attributes' => array(
          'data_attribute' => array(
            1 => array(
              'key' => '',
              'value' => '',
            ),
            2 => array(
              'key' => '',
              'value' => '',
            ),
            3 => array(
              'key' => '',
              'value' => '',
            ),
            4 => array(
              'key' => '',
              'value' => '',
            ),
            5 => array(
              'key' => '',
              'value' => '',
            ),
          ),
        ),
        'use_matchheight' => 0,
        'matchheight' => array(
          'group_existing' => '_new',
          'group_new' => '',
        ),
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2f37490a-7d5b-469f-a7d1-859d5b2642fd';
    $display->content['new-2f37490a-7d5b-469f-a7d1-859d5b2642fd'] = $pane;
    $display->panels['third'][0] = 'new-2f37490a-7d5b-469f-a7d1-859d5b2642fd';
    $pane = new stdClass();
    $pane->pid = 'new-b40df39e-eae3-4d2d-b334-2597cce1be3f';
    $pane->panel = 'third';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'pane',
      'settings' => array(
        'use_columns' => 1,
        'columns' => array(
          'xs' => 'col_xs_12',
          'sm' => 'col_sm_8',
          'md' => 'inherit',
          'lg' => 'inherit',
          'images_only' => 0,
        ),
        'use_offset' => 0,
        'offset' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_push' => 1,
        'push' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'col_sm_push_2',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_pull' => 0,
        'pull' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_visibility' => 0,
        'visibility' => array(
          'show_help' => 0,
          'hidden' => array(
            'hidden_xs' => 0,
            'hidden_sm' => 0,
            'hidden_md' => 0,
            'hidden_lg' => 0,
          ),
        ),
        'use_custom_classes' => 1,
        'custom_classes' => array(
          'show_help' => 0,
          'custom_classes' => 'type--centred',
        ),
        'use_data_attributes' => 0,
        'data_attributes' => array(
          'data_attribute' => array(
            1 => array(
              'key' => '',
              'value' => '',
            ),
            2 => array(
              'key' => '',
              'value' => '',
            ),
            3 => array(
              'key' => '',
              'value' => '',
            ),
            4 => array(
              'key' => '',
              'value' => '',
            ),
            5 => array(
              'key' => '',
              'value' => '',
            ),
          ),
        ),
        'use_matchheight' => 0,
        'matchheight' => array(
          'group_existing' => '_new',
          'group_new' => '',
        ),
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b40df39e-eae3-4d2d-b334-2597cce1be3f';
    $display->content['new-b40df39e-eae3-4d2d-b334-2597cce1be3f'] = $pane;
    $display->panels['third'][1] = 'new-b40df39e-eae3-4d2d-b334-2597cce1be3f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'News articles',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => 'node-type-news-article',
    'body_classes_to_add' => 'node--news-article',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'news_article' => 'news_article',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'cr-content';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'first' => array(
        'section_full_width' => 0,
        'classes_section' => '',
        'classes_container' => '',
        'classes_row' => 'row--small',
      ),
      'third' => array(
        'section_full_width' => 0,
        'classes_section' => '',
        'classes_container' => '',
        'classes_row' => 'row--extra-small type--red type--centred',
      ),
      'fourth' => array(
        'section_full_width' => 0,
        'classes_section' => '',
        'classes_container' => '',
        'classes_row' => 'row--padding-none',
      ),
      'fifth' => array(
        'section_full_width' => 0,
        'classes_section' => '',
        'classes_container' => '',
        'classes_row' => 'row--extra-small',
      ),
      'sixth' => array(
        'section_full_width' => 0,
        'classes_section' => '',
        'classes_container' => '',
        'classes_row' => 'row--extra-small',
      ),
      'seven' => array(
        'section_full_width' => 0,
        'classes_section' => '',
        'classes_container' => '',
        'classes_row' => 'row--extra-small',
      ),
      'eight' => NULL,
      'ninth' => NULL,
      'tenth' => NULL,
      'eleventh' => NULL,
      'twelfth' => NULL,
      'second' => array(
        'section_full_width' => 0,
        'classes_section' => '',
        'classes_container' => '',
        'classes_row' => 'row--padding-none',
      ),
    ),
    'second' => array(
      'style' => 'section',
    ),
    'first' => array(
      'style' => 'section',
    ),
    'third' => array(
      'style' => 'section',
    ),
    'fourth' => array(
      'style' => 'section',
    ),
    'fifth' => array(
      'style' => 'section',
    ),
    'sixth' => array(
      'style' => 'section',
    ),
    'seven' => array(
      'style' => 'section',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f845de71-1f71-4871-a4ee-bab6aa43d19f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-10aeabe6-f262-453a-b13b-65e527cad882';
    $pane->panel = 'fifth';
    $pane->type = 'token';
    $pane->subtype = 'node:summary';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'pane',
      'settings' => array(
        'use_columns' => 1,
        'columns' => array(
          'xs' => 'col_xs_12',
          'sm' => 'col_sm_10',
          'md' => 'col_md_8',
          'lg' => 'inherit',
          'images_only' => 0,
        ),
        'use_offset' => 0,
        'offset' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_push' => 1,
        'push' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'col_sm_push_1',
          'md' => 'col_md_push_2',
          'lg' => 'inherit',
        ),
        'use_pull' => 0,
        'pull' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_visibility' => 0,
        'visibility' => array(
          'show_help' => 0,
          'hidden' => array(
            'hidden_xs' => 0,
            'hidden_sm' => 0,
            'hidden_md' => 0,
            'hidden_lg' => 0,
          ),
        ),
        'use_custom_classes' => 1,
        'custom_classes' => array(
          'show_help' => 0,
          'custom_classes' => 'type--centred',
        ),
        'use_data_attributes' => 0,
        'data_attributes' => array(
          'data_attribute' => array(
            1 => array(
              'key' => '',
              'value' => '',
            ),
            2 => array(
              'key' => '',
              'value' => '',
            ),
            3 => array(
              'key' => '',
              'value' => '',
            ),
            4 => array(
              'key' => '',
              'value' => '',
            ),
            5 => array(
              'key' => '',
              'value' => '',
            ),
          ),
        ),
        'use_matchheight' => 0,
        'matchheight' => array(
          'group_existing' => '_new',
          'group_new' => '',
        ),
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '10aeabe6-f262-453a-b13b-65e527cad882';
    $display->content['new-10aeabe6-f262-453a-b13b-65e527cad882'] = $pane;
    $display->panels['fifth'][0] = 'new-10aeabe6-f262-453a-b13b-65e527cad882';
    $pane = new stdClass();
    $pane->pid = 'new-866b5f78-4ec9-4123-bdc3-13e3c1d080dd';
    $pane->panel = 'first';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_site_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'picture',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_link' => '',
        'picture_group' => 'col_8',
        'fallback_image_style' => 'col_8_lg',
        'colorbox' => 'col_8',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'pane',
      'settings' => array(
        'use_columns' => 1,
        'columns' => array(
          'xs' => 'col_xs_12',
          'sm' => 'col_sm_10',
          'md' => 'col_md_8',
          'lg' => 'inherit',
          'images_only' => 0,
        ),
        'use_offset' => 0,
        'offset' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_push' => 1,
        'push' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'col_sm_push_1',
          'md' => 'col_md_push_2',
          'lg' => 'inherit',
        ),
        'use_pull' => 0,
        'pull' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_visibility' => 0,
        'visibility' => array(
          'show_help' => 0,
          'hidden' => array(
            'hidden_xs' => 0,
            'hidden_sm' => 0,
            'hidden_md' => 0,
            'hidden_lg' => 0,
          ),
        ),
        'use_custom_classes' => 0,
        'custom_classes' => array(
          'show_help' => 0,
          'custom_classes' => '',
        ),
        'use_data_attributes' => 0,
        'data_attributes' => array(
          'data_attribute' => array(
            1 => array(
              'key' => '',
              'value' => '',
            ),
            2 => array(
              'key' => '',
              'value' => '',
            ),
            3 => array(
              'key' => '',
              'value' => '',
            ),
            4 => array(
              'key' => '',
              'value' => '',
            ),
            5 => array(
              'key' => '',
              'value' => '',
            ),
          ),
        ),
        'use_matchheight' => 0,
        'matchheight' => array(
          'group_existing' => '_new',
          'group_new' => '',
        ),
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '866b5f78-4ec9-4123-bdc3-13e3c1d080dd';
    $display->content['new-866b5f78-4ec9-4123-bdc3-13e3c1d080dd'] = $pane;
    $display->panels['first'][0] = 'new-866b5f78-4ec9-4123-bdc3-13e3c1d080dd';
    $pane = new stdClass();
    $pane->pid = 'new-a22f4a5a-ae33-46a2-a5cb-2d3e344f0314';
    $pane->panel = 'fourth';
    $pane->type = 'bean_panels';
    $pane->subtype = 'bean_panels';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'default',
      'bean_delta' => 'share-links-all-media',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'pane',
      'settings' => array(
        'use_columns' => 1,
        'columns' => array(
          'xs' => 'col_xs_12',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
          'images_only' => 0,
        ),
        'use_offset' => 0,
        'offset' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_push' => 0,
        'push' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_pull' => 0,
        'pull' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_visibility' => 0,
        'visibility' => array(
          'show_help' => 0,
          'hidden' => array(
            'hidden_xs' => 0,
            'hidden_sm' => 0,
            'hidden_md' => 0,
            'hidden_lg' => 0,
          ),
        ),
        'use_custom_classes' => 0,
        'custom_classes' => array(
          'show_help' => 0,
          'custom_classes' => '',
        ),
        'use_data_attributes' => 0,
        'data_attributes' => array(
          'data_attribute' => array(
            1 => array(
              'key' => '',
              'value' => '',
            ),
            2 => array(
              'key' => '',
              'value' => '',
            ),
            3 => array(
              'key' => '',
              'value' => '',
            ),
            4 => array(
              'key' => '',
              'value' => '',
            ),
            5 => array(
              'key' => '',
              'value' => '',
            ),
          ),
        ),
        'use_matchheight' => 0,
        'matchheight' => array(
          'group_existing' => '_new',
          'group_new' => '',
        ),
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a22f4a5a-ae33-46a2-a5cb-2d3e344f0314';
    $display->content['new-a22f4a5a-ae33-46a2-a5cb-2d3e344f0314'] = $pane;
    $display->panels['fourth'][0] = 'new-a22f4a5a-ae33-46a2-a5cb-2d3e344f0314';
    $pane = new stdClass();
    $pane->pid = 'new-fb973e29-c057-4cb7-83b9-26aa476ba07a';
    $pane->panel = 'second';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => 'type--sm',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'pane',
      'settings' => array(
        'use_columns' => 1,
        'columns' => array(
          'xs' => 'col_xs_12',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
          'images_only' => 0,
        ),
        'use_offset' => 0,
        'offset' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_push' => 0,
        'push' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_pull' => 0,
        'pull' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_visibility' => 0,
        'visibility' => array(
          'show_help' => 0,
          'hidden' => array(
            'hidden_xs' => 0,
            'hidden_sm' => 0,
            'hidden_md' => 0,
            'hidden_lg' => 0,
          ),
        ),
        'use_custom_classes' => 1,
        'custom_classes' => array(
          'show_help' => 0,
          'custom_classes' => 'type--centred',
        ),
        'use_data_attributes' => 0,
        'data_attributes' => array(
          'data_attribute' => array(
            1 => array(
              'key' => '',
              'value' => '',
            ),
            2 => array(
              'key' => '',
              'value' => '',
            ),
            3 => array(
              'key' => '',
              'value' => '',
            ),
            4 => array(
              'key' => '',
              'value' => '',
            ),
            5 => array(
              'key' => '',
              'value' => '',
            ),
          ),
        ),
        'use_matchheight' => 0,
        'matchheight' => array(
          'group_existing' => '_new',
          'group_new' => '',
        ),
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fb973e29-c057-4cb7-83b9-26aa476ba07a';
    $display->content['new-fb973e29-c057-4cb7-83b9-26aa476ba07a'] = $pane;
    $display->panels['second'][0] = 'new-fb973e29-c057-4cb7-83b9-26aa476ba07a';
    $pane = new stdClass();
    $pane->pid = 'new-b49a65f2-2da2-4ab6-b4c8-d4fc9adf934a';
    $pane->panel = 'seven';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Bottom line',
      'title' => '',
      'body' => '<hr class="hr--red">',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'pane',
      'settings' => array(
        'use_columns' => 1,
        'columns' => array(
          'xs' => 'col_xs_2',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
          'images_only' => 0,
        ),
        'use_offset' => 0,
        'offset' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_push' => 1,
        'push' => array(
          'show_help' => 0,
          'xs' => 'col_xs_push_5',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_pull' => 0,
        'pull' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_visibility' => 0,
        'visibility' => array(
          'show_help' => 0,
          'hidden' => array(
            'hidden_xs' => 0,
            'hidden_sm' => 0,
            'hidden_md' => 0,
            'hidden_lg' => 0,
          ),
        ),
        'use_custom_classes' => 0,
        'custom_classes' => array(
          'show_help' => 0,
          'custom_classes' => '',
        ),
        'use_data_attributes' => 0,
        'data_attributes' => array(
          'data_attribute' => array(
            1 => array(
              'key' => '',
              'value' => '',
            ),
            2 => array(
              'key' => '',
              'value' => '',
            ),
            3 => array(
              'key' => '',
              'value' => '',
            ),
            4 => array(
              'key' => '',
              'value' => '',
            ),
            5 => array(
              'key' => '',
              'value' => '',
            ),
          ),
        ),
        'use_matchheight' => 0,
        'matchheight' => array(
          'group_existing' => '_new',
          'group_new' => '',
        ),
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b49a65f2-2da2-4ab6-b4c8-d4fc9adf934a';
    $display->content['new-b49a65f2-2da2-4ab6-b4c8-d4fc9adf934a'] = $pane;
    $display->panels['seven'][0] = 'new-b49a65f2-2da2-4ab6-b4c8-d4fc9adf934a';
    $pane = new stdClass();
    $pane->pid = 'new-f795f22f-70ae-4040-aef1-82a5b2fa37b6';
    $pane->panel = 'sixth';
    $pane->type = 'token';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'pane',
      'settings' => array(
        'use_columns' => 1,
        'columns' => array(
          'xs' => 'col_xs_12',
          'sm' => 'col_sm_10',
          'md' => 'col_md_8',
          'lg' => 'inherit',
          'images_only' => 0,
        ),
        'use_offset' => 0,
        'offset' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_push' => 1,
        'push' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'col_sm_push_1',
          'md' => 'col_md_push_2',
          'lg' => 'inherit',
        ),
        'use_pull' => 0,
        'pull' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_visibility' => 0,
        'visibility' => array(
          'show_help' => 0,
          'hidden' => array(
            'hidden_xs' => 0,
            'hidden_sm' => 0,
            'hidden_md' => 0,
            'hidden_lg' => 0,
          ),
        ),
        'use_custom_classes' => 0,
        'custom_classes' => array(
          'show_help' => 0,
          'custom_classes' => '',
        ),
        'use_data_attributes' => 0,
        'data_attributes' => array(
          'data_attribute' => array(
            1 => array(
              'key' => '',
              'value' => '',
            ),
            2 => array(
              'key' => '',
              'value' => '',
            ),
            3 => array(
              'key' => '',
              'value' => '',
            ),
            4 => array(
              'key' => '',
              'value' => '',
            ),
            5 => array(
              'key' => '',
              'value' => '',
            ),
          ),
        ),
        'use_matchheight' => 0,
        'matchheight' => array(
          'group_existing' => '_new',
          'group_new' => '',
        ),
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f795f22f-70ae-4040-aef1-82a5b2fa37b6';
    $display->content['new-f795f22f-70ae-4040-aef1-82a5b2fa37b6'] = $pane;
    $display->panels['sixth'][0] = 'new-f795f22f-70ae-4040-aef1-82a5b2fa37b6';
    $pane = new stdClass();
    $pane->pid = 'new-49545c61-50f7-4c51-8eda-d9d234fa3c65';
    $pane->panel = 'third';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_site_publish_date';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'date_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_type' => 'month_day_year',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'both',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'pane',
      'settings' => array(
        'use_columns' => 1,
        'columns' => array(
          'xs' => 'col_xs_12',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
          'images_only' => 0,
        ),
        'use_offset' => 0,
        'offset' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_push' => 0,
        'push' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_pull' => 0,
        'pull' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_visibility' => 0,
        'visibility' => array(
          'show_help' => 0,
          'hidden' => array(
            'hidden_xs' => 0,
            'hidden_sm' => 0,
            'hidden_md' => 0,
            'hidden_lg' => 0,
          ),
        ),
        'use_custom_classes' => 1,
        'custom_classes' => array(
          'show_help' => 0,
          'custom_classes' => 'type--italic',
        ),
        'use_data_attributes' => 0,
        'data_attributes' => array(
          'data_attribute' => array(
            1 => array(
              'key' => '',
              'value' => '',
            ),
            2 => array(
              'key' => '',
              'value' => '',
            ),
            3 => array(
              'key' => '',
              'value' => '',
            ),
            4 => array(
              'key' => '',
              'value' => '',
            ),
            5 => array(
              'key' => '',
              'value' => '',
            ),
          ),
        ),
        'use_matchheight' => 0,
        'matchheight' => array(
          'group_existing' => '_new',
          'group_new' => '',
        ),
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '49545c61-50f7-4c51-8eda-d9d234fa3c65';
    $display->content['new-49545c61-50f7-4c51-8eda-d9d234fa3c65'] = $pane;
    $display->panels['third'][0] = 'new-49545c61-50f7-4c51-8eda-d9d234fa3c65';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_3';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Media images',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => 'node-type-media-image',
    'body_classes_to_add' => 'node--media-image',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'media_image' => 'media_image',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'cr-content';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'first' => array(
        'section_full_width' => 0,
        'classes_section' => '',
        'classes_container' => '',
        'classes_row' => '',
      ),
      'third' => array(
        'section_full_width' => 0,
        'classes_section' => '',
        'classes_container' => '',
        'classes_row' => '',
      ),
      'fourth' => array(
        'section_full_width' => 0,
        'classes_section' => '',
        'classes_container' => '',
        'classes_row' => '',
      ),
      'fifth' => NULL,
      'sixth' => NULL,
      'seven' => NULL,
      'eight' => NULL,
      'ninth' => NULL,
      'tenth' => NULL,
      'eleventh' => NULL,
      'twelfth' => NULL,
      'second' => array(
        'section_full_width' => 0,
        'classes_section' => '',
        'classes_container' => '',
        'classes_row' => 'row--padding-none',
      ),
    ),
    'second' => array(
      'style' => 'section',
    ),
    'first' => array(
      'style' => 'section',
    ),
    'third' => array(
      'style' => 'section',
    ),
    'fourth' => array(
      'style' => 'section',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f845de71-1f71-4871-a4ee-bab6aa43d19f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fb973e29-c057-4cb7-83b9-26aa476ba07a';
    $pane->panel = 'first';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => 'type--centred type--md',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'pane',
      'settings' => array(
        'use_columns' => 1,
        'columns' => array(
          'xs' => 'col_xs_12',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
          'images_only' => 0,
        ),
        'use_offset' => 0,
        'offset' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_push' => 0,
        'push' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_pull' => 0,
        'pull' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_visibility' => 0,
        'visibility' => array(
          'show_help' => 0,
          'hidden' => array(
            'hidden_xs' => 0,
            'hidden_sm' => 0,
            'hidden_md' => 0,
            'hidden_lg' => 0,
          ),
        ),
        'use_custom_classes' => 0,
        'custom_classes' => array(
          'show_help' => 0,
          'custom_classes' => '',
        ),
        'use_matchheight' => 0,
        'matchheight' => array(
          'group_existing' => '_new',
          'group_new' => '',
        ),
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fb973e29-c057-4cb7-83b9-26aa476ba07a';
    $display->content['new-fb973e29-c057-4cb7-83b9-26aa476ba07a'] = $pane;
    $display->panels['first'][0] = 'new-fb973e29-c057-4cb7-83b9-26aa476ba07a';
    $pane = new stdClass();
    $pane->pid = 'new-77f8cbe0-ddeb-4f56-8e65-c06a5089bf54';
    $pane->panel = 'second';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'pane',
      'settings' => array(
        'use_columns' => 1,
        'columns' => array(
          'xs' => 'col_xs_12',
          'sm' => 'inherit',
          'md' => 'col_md_8',
          'lg' => 'inherit',
          'images_only' => 0,
        ),
        'use_offset' => 0,
        'offset' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_push' => 1,
        'push' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'col_md_push_2',
          'lg' => 'inherit',
        ),
        'use_pull' => 0,
        'pull' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_visibility' => 0,
        'visibility' => array(
          'show_help' => 0,
          'hidden' => array(
            'hidden_xs' => 0,
            'hidden_sm' => 0,
            'hidden_md' => 0,
            'hidden_lg' => 0,
          ),
        ),
        'use_custom_classes' => 0,
        'custom_classes' => array(
          'show_help' => 0,
          'custom_classes' => '',
        ),
        'use_data_attributes' => 0,
        'data_attributes' => array(
          'data_attribute' => array(
            1 => array(
              'key' => '',
              'value' => '',
            ),
            2 => array(
              'key' => '',
              'value' => '',
            ),
            3 => array(
              'key' => '',
              'value' => '',
            ),
            4 => array(
              'key' => '',
              'value' => '',
            ),
            5 => array(
              'key' => '',
              'value' => '',
            ),
          ),
        ),
        'use_matchheight' => 0,
        'matchheight' => array(
          'group_existing' => '_new',
          'group_new' => '',
        ),
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '77f8cbe0-ddeb-4f56-8e65-c06a5089bf54';
    $display->content['new-77f8cbe0-ddeb-4f56-8e65-c06a5089bf54'] = $pane;
    $display->panels['second'][0] = 'new-77f8cbe0-ddeb-4f56-8e65-c06a5089bf54';
    $pane = new stdClass();
    $pane->pid = 'new-99c76111-635f-4859-b7a8-447e5cbc729b';
    $pane->panel = 'third';
    $pane->type = 'bean_panels';
    $pane->subtype = 'bean_panels';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'default',
      'bean_delta' => 'share-links-all-media',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'pane',
      'settings' => array(
        'use_columns' => 1,
        'columns' => array(
          'xs' => 'col_xs_12',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_offset' => 0,
        'use_push' => 0,
        'use_pull' => 0,
        'use_visibility' => 0,
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '99c76111-635f-4859-b7a8-447e5cbc729b';
    $display->content['new-99c76111-635f-4859-b7a8-447e5cbc729b'] = $pane;
    $display->panels['third'][0] = 'new-99c76111-635f-4859-b7a8-447e5cbc729b';
    $pane = new stdClass();
    $pane->pid = 'new-b40df39e-eae3-4d2d-b334-2597cce1be3f';
    $pane->panel = 'third';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'pane',
      'settings' => array(
        'use_columns' => 1,
        'columns' => array(
          'xs' => 'col_xs_12',
          'sm' => 'col_sm_8',
          'md' => 'inherit',
          'lg' => 'inherit',
          'images_only' => 0,
        ),
        'use_offset' => 0,
        'offset' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_push' => 1,
        'push' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'col_sm_push_2',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_pull' => 0,
        'pull' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_visibility' => 0,
        'visibility' => array(
          'show_help' => 0,
          'hidden' => array(
            'hidden_xs' => 0,
            'hidden_sm' => 0,
            'hidden_md' => 0,
            'hidden_lg' => 0,
          ),
        ),
        'use_custom_classes' => 1,
        'custom_classes' => array(
          'show_help' => 0,
          'custom_classes' => 'type--centred',
        ),
        'use_data_attributes' => 0,
        'data_attributes' => array(
          'data_attribute' => array(
            1 => array(
              'key' => '',
              'value' => '',
            ),
            2 => array(
              'key' => '',
              'value' => '',
            ),
            3 => array(
              'key' => '',
              'value' => '',
            ),
            4 => array(
              'key' => '',
              'value' => '',
            ),
            5 => array(
              'key' => '',
              'value' => '',
            ),
          ),
        ),
        'use_matchheight' => 0,
        'matchheight' => array(
          'group_existing' => '_new',
          'group_new' => '',
        ),
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b40df39e-eae3-4d2d-b334-2597cce1be3f';
    $display->content['new-b40df39e-eae3-4d2d-b334-2597cce1be3f'] = $pane;
    $display->panels['third'][1] = 'new-b40df39e-eae3-4d2d-b334-2597cce1be3f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_3'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_4';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'title' => 'Fundraiser showcases',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => 'node-type-fundraiser-showcase',
    'body_classes_to_add' => 'node--fundraiser-showcase',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'fundraiser_showcase' => 'fundraiser_showcase',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'cr-content';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'first' => array(
        'section_full_width' => 0,
        'classes_section' => 'bg-color--grey-v-light',
        'classes_container' => '',
        'classes_row' => 'row--fundraise-ideas-links',
        'use_background_pane' => 0,
        'background_pane_container' => array(
          'background_pane' => '_none',
          'use_match_height' => 0,
          'overlay_content_breakpoint' => 'md',
          'picture_group' => '_none',
        ),
      ),
      'fourth' => array(
        'section_full_width' => 0,
        'classes_section' => 'node--fundraiser-showcase__images',
        'classes_container' => '',
        'classes_row' => 'row--small',
      ),
      'fifth' => NULL,
      'sixth' => NULL,
      'seven' => NULL,
      'eight' => NULL,
      'ninth' => NULL,
      'tenth' => NULL,
      'eleventh' => NULL,
      'twelfth' => NULL,
      'second' => array(
        'section_full_width' => 0,
        'classes_section' => 'node--fundraiser-showcase__heading',
        'classes_container' => '',
        'classes_row' => 'row--small',
      ),
      'third' => array(
        'section_full_width' => 0,
        'classes_section' => 'node--fundraiser-showcase__caption',
        'classes_container' => '',
        'classes_row' => 'row--padding-none',
      ),
    ),
    'second' => array(
      'style' => 'section',
    ),
    'first' => array(
      'style' => 'section',
    ),
    'third' => array(
      'style' => 'section',
    ),
    'fourth' => array(
      'style' => 'section',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f845de71-1f71-4871-a4ee-bab6aa43d19f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e7be1877-83c7-47e7-900a-fd432200822f';
    $pane->panel = 'fourth';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_fundraiser_showcase_images';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'picture',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'image_link' => '',
        'picture_group' => 'fundraiser_showcase_page',
        'fallback_image_style' => 'col_6_md',
        'colorbox' => 'col_1',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'pane',
      'settings' => array(
        'use_columns' => 1,
        'columns' => array(
          'xs' => 'col_xs_12',
          'sm' => 'col_sm_10',
          'md' => 'col_md_6',
          'lg' => 'inherit',
          'images_only' => 0,
        ),
        'use_offset' => 0,
        'offset' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_push' => 1,
        'push' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'col_sm_push_1',
          'md' => 'col_md_push_3',
          'lg' => 'inherit',
        ),
        'use_pull' => 0,
        'pull' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_visibility' => 0,
        'visibility' => array(
          'show_help' => 0,
          'hidden' => array(
            'hidden_xs' => 0,
            'hidden_sm' => 0,
            'hidden_md' => 0,
            'hidden_lg' => 0,
          ),
        ),
        'use_custom_classes' => 0,
        'custom_classes' => array(
          'show_help' => 0,
          'custom_classes' => '',
        ),
        'use_data_attributes' => 0,
        'data_attributes' => array(
          'data_attribute' => array(
            1 => array(
              'key' => '',
              'value' => '',
            ),
            2 => array(
              'key' => '',
              'value' => '',
            ),
            3 => array(
              'key' => '',
              'value' => '',
            ),
            4 => array(
              'key' => '',
              'value' => '',
            ),
            5 => array(
              'key' => '',
              'value' => '',
            ),
          ),
        ),
        'use_matchheight' => 0,
        'matchheight' => array(
          'group_existing' => '_new',
          'group_new' => '',
        ),
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e7be1877-83c7-47e7-900a-fd432200822f';
    $display->content['new-e7be1877-83c7-47e7-900a-fd432200822f'] = $pane;
    $display->panels['fourth'][0] = 'new-e7be1877-83c7-47e7-900a-fd432200822f';
    $pane = new stdClass();
    $pane->pid = 'new-fb973e29-c057-4cb7-83b9-26aa476ba07a';
    $pane->panel = 'second';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => 'type--centred type--md type--white type--lower',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'pane',
      'settings' => array(
        'use_columns' => 1,
        'columns' => array(
          'xs' => 'col_xs_12',
          'sm' => 'col_sm_8',
          'md' => 'col_md_6',
          'lg' => 'inherit',
          'images_only' => 0,
        ),
        'use_offset' => 0,
        'offset' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_push' => 1,
        'push' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'col_sm_push_2',
          'md' => 'col_md_push_3',
          'lg' => 'inherit',
        ),
        'use_pull' => 0,
        'pull' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_visibility' => 0,
        'visibility' => array(
          'show_help' => 0,
          'hidden' => array(
            'hidden_xs' => 0,
            'hidden_sm' => 0,
            'hidden_md' => 0,
            'hidden_lg' => 0,
          ),
        ),
        'use_custom_classes' => 1,
        'custom_classes' => array(
          'show_help' => 0,
          'custom_classes' => '',
        ),
        'use_data_attributes' => 0,
        'data_attributes' => array(
          'data_attribute' => array(
            1 => array(
              'key' => '',
              'value' => '',
            ),
            2 => array(
              'key' => '',
              'value' => '',
            ),
            3 => array(
              'key' => '',
              'value' => '',
            ),
            4 => array(
              'key' => '',
              'value' => '',
            ),
            5 => array(
              'key' => '',
              'value' => '',
            ),
          ),
        ),
        'use_matchheight' => 0,
        'matchheight' => array(
          'group_existing' => '_new',
          'group_new' => '',
        ),
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fb973e29-c057-4cb7-83b9-26aa476ba07a';
    $display->content['new-fb973e29-c057-4cb7-83b9-26aa476ba07a'] = $pane;
    $display->panels['second'][0] = 'new-fb973e29-c057-4cb7-83b9-26aa476ba07a';
    $pane = new stdClass();
    $pane->pid = 'new-17369a1e-33bf-4296-8230-725bb51e3cb3';
    $pane->panel = 'third';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'pane',
      'settings' => array(
        'use_columns' => 1,
        'columns' => array(
          'xs' => 'col_xs_12',
          'sm' => 'col_sm_8',
          'md' => 'col_md_6',
          'lg' => 'inherit',
          'images_only' => 0,
        ),
        'use_offset' => 0,
        'offset' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_push' => 1,
        'push' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'col_sm_push_2',
          'md' => 'col_md_push_3',
          'lg' => 'inherit',
        ),
        'use_pull' => 0,
        'pull' => array(
          'show_help' => 0,
          'xs' => 'none',
          'sm' => 'inherit',
          'md' => 'inherit',
          'lg' => 'inherit',
        ),
        'use_visibility' => 0,
        'visibility' => array(
          'show_help' => 0,
          'hidden' => array(
            'hidden_xs' => 0,
            'hidden_sm' => 0,
            'hidden_md' => 0,
            'hidden_lg' => 0,
          ),
        ),
        'use_custom_classes' => 1,
        'custom_classes' => array(
          'show_help' => 0,
          'custom_classes' => 'type--white type--centred',
        ),
        'use_data_attributes' => 0,
        'data_attributes' => array(
          'data_attribute' => array(
            1 => array(
              'key' => '',
              'value' => '',
            ),
            2 => array(
              'key' => '',
              'value' => '',
            ),
            3 => array(
              'key' => '',
              'value' => '',
            ),
            4 => array(
              'key' => '',
              'value' => '',
            ),
            5 => array(
              'key' => '',
              'value' => '',
            ),
          ),
        ),
        'use_matchheight' => 0,
        'matchheight' => array(
          'group_existing' => '_new',
          'group_new' => '',
        ),
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '17369a1e-33bf-4296-8230-725bb51e3cb3';
    $display->content['new-17369a1e-33bf-4296-8230-725bb51e3cb3'] = $pane;
    $display->panels['third'][0] = 'new-17369a1e-33bf-4296-8230-725bb51e3cb3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_4'] = $handler;

  return $export;
}
