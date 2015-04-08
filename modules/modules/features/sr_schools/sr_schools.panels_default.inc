<?php
/**
 * @file
 * sr_schools.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function sr_schools_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'primary_need';
  $mini->category = 'Schools';
  $mini->admin_title = 'Primary Need';
  $mini->admin_description = '';
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
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:efe903e7-143f-4021-993a-03c72c4c5cb0';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'basic_pod',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-5',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 1,
        'omega' => 0,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 1,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
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
    $pane->subtype = 'uuid:b47ade17-0fc9-43c5-8125-d274183083bd';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'grid_13_promo',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-13',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 0,
        'omega' => 1,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 0,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-2'] = $pane;
    $display->panels['middle'][1] = 'new-2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1';
  $mini->display = $display;
  $export['primary_need'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'primary_need_1';
  $mini->category = 'Schools';
  $mini->admin_title = 'Primary Need 1';
  $mini->admin_description = '';
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
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:85f01176-5101-4278-8816-13d2f8916142';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'basic_pod',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-5',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 1,
        'omega' => 0,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 1,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-3'] = $pane;
    $display->panels['middle'][0] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:ff39e547-8a0a-4e8a-aade-7bc7b9ccb78d';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'grid_13_promo',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-13',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 0,
        'omega' => 1,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 0,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-4'] = $pane;
    $display->panels['middle'][1] = 'new-4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-3';
  $mini->display = $display;
  $export['primary_need_1'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'primary_need_2';
  $mini->category = 'Schools';
  $mini->admin_title = 'Primary Need 2';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:3c06d971-8efa-447d-9a55-fbc0b6a7126a';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'basic_pod',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-5',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 1,
        'omega' => 0,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 1,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-5'] = $pane;
    $display->panels['middle'][0] = 'new-5';
    $pane = new stdClass();
    $pane->pid = 'new-6';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:f56c2588-1011-4589-a4db-88cf8a3652f2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'grid_13_promo',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-13',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 0,
        'omega' => 1,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 0,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-6'] = $pane;
    $display->panels['middle'][1] = 'new-6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5';
  $mini->display = $display;
  $export['primary_need_2'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'primary_need_3';
  $mini->category = 'Schools';
  $mini->admin_title = 'Primary Need 3';
  $mini->admin_description = '';
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
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:4869ff5c-37c5-42d2-8913-a796acdc773d';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'basic_pod',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-5',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 1,
        'omega' => 0,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 1,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-7'] = $pane;
    $display->panels['middle'][0] = 'new-7';
    $pane = new stdClass();
    $pane->pid = 'new-8';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:11e2256e-7b46-4deb-a39c-bfb0687534d3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'grid_13_promo',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-13',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 0,
        'omega' => 1,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 0,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-8'] = $pane;
    $display->panels['middle'][1] = 'new-8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-7';
  $mini->display = $display;
  $export['primary_need_3'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'primary_need_4';
  $mini->category = 'Schools';
  $mini->admin_title = 'Primary Need 4';
  $mini->admin_description = '';
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
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:e4d74df5-2395-471b-8ff5-7b4401f3c578';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'basic_pod',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-5',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 1,
        'omega' => 0,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 1,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-9'] = $pane;
    $display->panels['middle'][0] = 'new-9';
    $pane = new stdClass();
    $pane->pid = 'new-10';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:858fb724-a3ef-4bc6-b9b9-6abdafa1d38e';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'grid_13_promo',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-13',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 0,
        'omega' => 1,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 0,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-10'] = $pane;
    $display->panels['middle'][1] = 'new-10';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-9';
  $mini->display = $display;
  $export['primary_need_4'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'primary_need_5';
  $mini->category = 'Schools';
  $mini->admin_title = 'Primary Need 5';
  $mini->admin_description = '';
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
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-11';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:e1125614-eb05-4cf2-b978-71f7c6e99fb7';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'basic_pod',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-5',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 1,
        'omega' => 0,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 1,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-11'] = $pane;
    $display->panels['middle'][0] = 'new-11';
    $pane = new stdClass();
    $pane->pid = 'new-12';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:051e6619-9cdb-4d9f-b6bb-39c321ea5223';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'grid_13_promo',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-13',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 0,
        'omega' => 1,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 0,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-12'] = $pane;
    $display->panels['middle'][1] = 'new-12';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-11';
  $mini->display = $display;
  $export['primary_need_5'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'secondary_need';
  $mini->category = 'Schools';
  $mini->admin_title = 'Secondary Need';
  $mini->admin_description = '';
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
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-13';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:6503a1da-9da3-44f5-acdf-a333bd93c0b4';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'basic_pod',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-5',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 1,
        'omega' => 0,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 1,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-13'] = $pane;
    $display->panels['middle'][0] = 'new-13';
    $pane = new stdClass();
    $pane->pid = 'new-14';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:f658f373-f31b-4f46-9546-55e68707fdf9';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'grid_13_promo',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-13',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 0,
        'omega' => 1,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 1,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-14'] = $pane;
    $display->panels['middle'][1] = 'new-14';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-13';
  $mini->display = $display;
  $export['secondary_need'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'secondary_need_1';
  $mini->category = 'Schools';
  $mini->admin_title = 'Secondary Need 1';
  $mini->admin_description = '';
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
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-15';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:5f57b6f3-73af-49ec-929e-0133731eb21f';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'basic_pod',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-5',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 1,
        'omega' => 0,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 1,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-15'] = $pane;
    $display->panels['middle'][0] = 'new-15';
    $pane = new stdClass();
    $pane->pid = 'new-16';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:a50b9291-0535-4e6f-a7d7-e9867df2f314';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'grid_13_promo',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-13',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 0,
        'omega' => 1,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 0,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-16'] = $pane;
    $display->panels['middle'][1] = 'new-16';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-15';
  $mini->display = $display;
  $export['secondary_need_1'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'secondary_need_2';
  $mini->category = 'Schools';
  $mini->admin_title = 'Secondary Need 2';
  $mini->admin_description = '';
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
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-17';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:05608faa-6e03-4a54-b663-69e3ca3c9046';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'basic_pod',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-5',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 1,
        'omega' => 0,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 1,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-17'] = $pane;
    $display->panels['middle'][0] = 'new-17';
    $pane = new stdClass();
    $pane->pid = 'new-18';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:922bb8d8-a896-409d-9521-b780e5974eed';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'grid_13_promo',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-13',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 0,
        'omega' => 1,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 0,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-18'] = $pane;
    $display->panels['middle'][1] = 'new-18';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-17';
  $mini->display = $display;
  $export['secondary_need_2'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'secondary_need_3';
  $mini->category = 'Schools';
  $mini->admin_title = 'Secondary Need 3';
  $mini->admin_description = '';
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
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-19';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:082de3cd-5a1a-4253-89b4-cf3ef0a3e38a';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'basic_pod',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-5',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 1,
        'omega' => 0,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 1,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-19'] = $pane;
    $display->panels['middle'][0] = 'new-19';
    $pane = new stdClass();
    $pane->pid = 'new-20';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:fd8c4ae3-0910-48c6-9026-3bf40d7b0c60';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'grid_13_promo',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-13',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 0,
        'omega' => 1,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 0,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-20'] = $pane;
    $display->panels['middle'][1] = 'new-20';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-19';
  $mini->display = $display;
  $export['secondary_need_3'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'secondary_need_4';
  $mini->category = 'Schools';
  $mini->admin_title = 'Secondary Need 4';
  $mini->admin_description = '';
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
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-21';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:e475b371-54a5-41e9-8fe8-65ede60a89d7';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'basic_pod',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-5',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 1,
        'omega' => 0,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 1,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-21'] = $pane;
    $display->panels['middle'][0] = 'new-21';
    $pane = new stdClass();
    $pane->pid = 'new-22';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:4598be14-24e3-45a5-ac1a-430581a5789d';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'grid_13_promo',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-13',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 0,
        'omega' => 1,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 0,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-22'] = $pane;
    $display->panels['middle'][1] = 'new-22';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-21';
  $mini->display = $display;
  $export['secondary_need_4'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'secondary_need_5';
  $mini->category = 'Schools';
  $mini->admin_title = 'Secondary Need 5';
  $mini->admin_description = '';
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
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-23';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:91f904a1-f779-4dc2-a319-7ca727f75162';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'basic_pod',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-5',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 1,
        'omega' => 0,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 1,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-23'] = $pane;
    $display->panels['middle'][0] = 'new-23';
    $pane = new stdClass();
    $pane->pid = 'new-24';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:655af141-4740-41ab-b92d-1894abd9213c';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'grid_13_promo',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-13',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 0,
        'omega' => 1,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 0,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-24'] = $pane;
    $display->panels['middle'][1] = 'new-24';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-23';
  $mini->display = $display;
  $export['secondary_need_5'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'secondary_need_6';
  $mini->category = 'Schools';
  $mini->admin_title = 'Secondary Need 6';
  $mini->admin_description = '';
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
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-25';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:1457163f-6975-4bbd-8e8e-e164d7aae044';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'basic_pod',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-5',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 1,
        'omega' => 0,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 1,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-25'] = $pane;
    $display->panels['middle'][0] = 'new-25';
    $pane = new stdClass();
    $pane->pid = 'new-26';
    $pane->panel = 'middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:ade9be27-aef8-457c-8752-23283a50ec36';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'grid_13_promo',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-13',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => 'narrow-grid-24',
        'alpha' => 0,
        'omega' => 1,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 0,
        'text-align-center-mobile-only' => 0,
        'extraClasses' => '',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-26'] = $pane;
    $display->panels['middle'][1] = 'new-26';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-25';
  $mini->display = $display;
  $export['secondary_need_6'] = $mini;

  return $export;
}
