<?php
/**
 * @file
 * what_we_do.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function what_we_do_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'clone_of_how_we_spend_your_money';
  $mini->category = '';
  $mini->admin_title = 'How we spend your money desktop';
  $mini->admin_description = 'A list of ways we spend money';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
    'middle' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:ac08f351-197f-436a-830d-aabaffa14538';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'element_title' => array(
          'type' => 'h3',
          'class_enable' => 1,
          'class' => 'spend-area__section__title',
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
          'class_enable' => 1,
          'class' => 'spend-area__content',
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
          'class' => 'spend-area__section spend-area__section--first',
          'attributes' => array(
            'data-bottom-center' => array(
              'enabled' => 1,
              'value' => 'transform:translate(355px, -175px) scale(0.4); z-index: 4; opacity: 0;',
            ),
            'data--100-bottom-bottom' => array(
              'enabled' => 1,
              'value' => 'transform:translate(0px, 0px) scale(1); z-index: 10; opacity: 1;',
            ),
          ),
          'attributes_array' => array(
            'data-bottom-center' => 'transform:translate(355px, -175px) scale(0.4); z-index: 4; opacity: 0;',
            'data--100-bottom-bottom' => 'transform:translate(0px, 0px) scale(1); z-index: 10; opacity: 1;',
          ),
        ),
        'add_default_classes' => 0,
      ),
      'style' => 'semantic_panels',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-1'] = $pane;
    $display->panels['middle'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:1da35703-aeb1-458d-9754-6ea959994446';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'element_title' => array(
          'type' => 'h3',
          'class_enable' => 1,
          'class' => 'spend-area__section__title',
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
          'class_enable' => 1,
          'class' => 'spend-area__content',
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
          'class' => 'spend-area__section spend-area__section--second',
          'attributes' => array(
            'data-bottom-center' => array(
              'enabled' => 1,
              'value' => 'transform:translate(185px, -255px) scale(0.4); z-index: 4; opacity: 0;',
            ),
            'data--100-bottom-bottom' => array(
              'enabled' => 1,
              'value' => 'transform:translate(0px, 0px) scale(1); z-index: 10; opacity: 1;',
            ),
          ),
          'attributes_array' => array(
            'data-bottom-center' => 'transform:translate(185px, -255px) scale(0.4); z-index: 4; opacity: 0;',
            'data--100-bottom-bottom' => 'transform:translate(0px, 0px) scale(1); z-index: 10; opacity: 1;',
          ),
        ),
        'add_default_classes' => 0,
      ),
      'style' => 'semantic_panels',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-2'] = $pane;
    $display->panels['middle'][1] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:d7ed3637-4d07-45e1-a7b4-767d1b6e5949';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'element_title' => array(
          'type' => 'h3',
          'class_enable' => 1,
          'class' => 'spend-area__section__title',
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
          'class_enable' => 1,
          'class' => 'spend-area__content',
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
          'class' => 'spend-area__section spend-area__section--third',
          'attributes' => array(
            'data-bottom-center' => array(
              'enabled' => 1,
              'value' => 'transform:translate(5px, -290px) scale(0.4); z-index: 4; opacity: 0;',
            ),
            'data--100-bottom-bottom' => array(
              'enabled' => 1,
              'value' => 'transform:translate(0px, 0px) scale(1); z-index: 10; opacity: 1;',
            ),
          ),
          'attributes_array' => array(
            'data-bottom-center' => 'transform:translate(5px, -290px) scale(0.4); z-index: 4; opacity: 0;',
            'data--100-bottom-bottom' => 'transform:translate(0px, 0px) scale(1); z-index: 10; opacity: 1;',
          ),
        ),
        'add_default_classes' => 0,
      ),
      'style' => 'semantic_panels',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-3'] = $pane;
    $display->panels['middle'][2] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:67e0ee51-93e8-45dd-9616-835c1410dab7';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'element_title' => array(
          'type' => 'h3',
          'class_enable' => 1,
          'class' => 'spend-area__section__title',
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
          'class_enable' => 1,
          'class' => 'spend-area__content',
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
          'class' => 'spend-area__section spend-area__section--fourth',
          'attributes' => array(
            'data-bottom-center' => array(
              'enabled' => 1,
              'value' => 'transform:translate(-195px, -255px) scale(0.4); z-index: 4; opacity: 0;',
            ),
            'data--100-bottom-bottom' => array(
              'enabled' => 1,
              'value' => 'transform:translate(0, 0) scale(1); z-index: 10; opacity: 1;',
            ),
          ),
          'attributes_array' => array(
            'data-bottom-center' => 'transform:translate(-195px, -255px) scale(0.4); z-index: 4; opacity: 0;',
            'data--100-bottom-bottom' => 'transform:translate(0, 0) scale(1); z-index: 10; opacity: 1;',
          ),
        ),
        'add_default_classes' => 0,
      ),
      'style' => 'semantic_panels',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $display->content['new-4'] = $pane;
    $display->panels['middle'][3] = 'new-4';
    $pane = new stdClass();
    $pane->pid = 'new-5';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:960d0616-264d-4f90-b73e-0c3de99e3f0b';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'element_title' => array(
          'type' => 'h3',
          'class_enable' => 1,
          'class' => 'spend-area__section__title',
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
          'class_enable' => 1,
          'class' => 'spend-area__content',
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
          'class' => 'spend-area__section spend-area__section--fifth',
          'attributes' => array(
            'data-bottom-center' => array(
              'enabled' => 1,
              'value' => 'transform:translate(-365px, -175px) scale(0.4); z-index: 4; opacity: 0;',
            ),
            'data--100-bottom-bottom' => array(
              'enabled' => 1,
              'value' => 'transform:translate(0px, 0px) scale(1); z-index: 10; opacity: 1;',
            ),
          ),
          'attributes_array' => array(
            'data-bottom-center' => 'transform:translate(-365px, -175px) scale(0.4); z-index: 4; opacity: 0;',
            'data--100-bottom-bottom' => 'transform:translate(0px, 0px) scale(1); z-index: 10; opacity: 1;',
          ),
        ),
        'add_default_classes' => 0,
      ),
      'style' => 'semantic_panels',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $display->content['new-5'] = $pane;
    $display->panels['middle'][4] = 'new-5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['clone_of_how_we_spend_your_money'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'how_we_spend_your_money';
  $mini->category = '';
  $mini->admin_title = 'How we spend your money';
  $mini->admin_description = 'A list of ways we spend money';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => array(
        'style' => 'color',
        'open_accordion' => '0',
        'desktop_state' => '',
        'panels_tabs_style_render_region_form' => array(
          'tabs_pane_title' => '',
          'style' => 'main',
          'transition' => 'slide',
          'open_tab' => '0',
          'direction_nav' => 'false',
          'direction_nav_text_prev' => '',
          'direction_nav_text_next' => '',
          'equal_height_element' => 1,
        ),
        'panels_list_style_render_region_form' => array(
          'list_type' => 'ul',
        ),
      ),
    ),
    'middle' => array(
      'style' => 'accordion',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:ac08f351-197f-436a-830d-aabaffa14538';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-6'] = $pane;
    $display->panels['middle'][0] = 'new-6';
    $pane = new stdClass();
    $pane->pid = 'new-7';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:1da35703-aeb1-458d-9754-6ea959994446';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-7'] = $pane;
    $display->panels['middle'][1] = 'new-7';
    $pane = new stdClass();
    $pane->pid = 'new-8';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:d7ed3637-4d07-45e1-a7b4-767d1b6e5949';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-8'] = $pane;
    $display->panels['middle'][2] = 'new-8';
    $pane = new stdClass();
    $pane->pid = 'new-9';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:67e0ee51-93e8-45dd-9616-835c1410dab7';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $display->content['new-9'] = $pane;
    $display->panels['middle'][3] = 'new-9';
    $pane = new stdClass();
    $pane->pid = 'new-10';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:960d0616-264d-4f90-b73e-0c3de99e3f0b';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $display->content['new-10'] = $pane;
    $display->panels['middle'][4] = 'new-10';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['how_we_spend_your_money'] = $mini;

  return $export;
}
