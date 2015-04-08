<?php
/**
 * @file
 * otn_banners.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function otn_banners_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'otn_banner_donate';
  $mini->category = 'OTN Banners';
  $mini->admin_title = 'OTN Banner - Donate';
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
    $pane->subtype = 'uuid:34195827-23eb-453a-ab54-51111fca28af';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-6',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => '',
        'mobileColumns' => '',
        'alpha' => 1,
        'omega' => 1,
        'narrow-alpha' => 0,
        'narrow-omega' => 0,
        'mobile-alpha' => 0,
        'mobile-omega' => 0,
        'mobile-row' => 0,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 0,
        'text-align-center-mobile-only' => 0,
        'text-align-center-all' => 0,
        'container-center' => 0,
        'extraClasses' => 'otn-banner--image is-not-mobile',
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
    $pane->subtype = 'uuid:dd82a4b8-972d-4e9e-802e-593b72d2e684';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-12',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => '',
        'mobileColumns' => '',
        'alpha' => 0,
        'omega' => 0,
        'narrow-alpha' => 0,
        'narrow-omega' => 0,
        'mobile-alpha' => 0,
        'mobile-omega' => 0,
        'mobile-row' => 0,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 0,
        'text-align-center-mobile-only' => 0,
        'text-align-center-all' => 0,
        'container-center' => 0,
        'extraClasses' => 'otn-banner--text',
      ),
      'style' => 'grid',
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
    $pane->subtype = 'uuid:4b28b90a-6036-4485-8114-ac1e17641f3a';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-6',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => '',
        'mobileColumns' => '',
        'alpha' => 1,
        'omega' => 1,
        'narrow-alpha' => 0,
        'narrow-omega' => 0,
        'mobile-alpha' => 0,
        'mobile-omega' => 0,
        'mobile-row' => 0,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 0,
        'text-align-center-mobile-only' => 0,
        'text-align-center-all' => 0,
        'container-center' => 0,
        'extraClasses' => 'otn-banner--button',
      ),
      'style' => 'grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-3'] = $pane;
    $display->panels['middle'][2] = 'new-3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1';
  $mini->display = $display;
  $export['otn_banner_donate'] = $mini;

  return $export;
}
