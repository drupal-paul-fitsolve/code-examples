<?php
/**
 * @file
 * sr_events.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function sr_events_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'postcode_search_banner';
  $mini->category = '';
  $mini->admin_title = 'Postcode Search Banner';
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
      'intro' => NULL,
      'row1_col1' => array(
        'separator' => array(
          'active' => 1,
          'element_type' => 'div',
          'show_css' => 1,
          'element_class' => 'postcode-search-banner',
        ),
      ),
      'row1_col2' => NULL,
      'row1_col3' => NULL,
      'row1_col4' => NULL,
      'row2_col1' => NULL,
      'row2_col2' => NULL,
      'row2_col3' => NULL,
      'row2_col4' => NULL,
      'row3_col1' => NULL,
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
      'middle' => NULL,
    ),
    'row1_col1' => array(
      'style' => 'semantic_panels',
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
    $pane->subtype = 'uuid:cfcd6789-2ca7-4ac9-bf71-409d687b18b7';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-9',
        'prefix' => 'prefix-5',
        'suffix' => '',
        'narrowColumns' => '',
        'alpha' => 0,
        'omega' => 0,
        'force-end-desktop' => 0,
        'text-align-center-narrow-mobile' => 0,
        'text-align-center-mobile-only' => 0,
        'container-center' => 0,
        'extraClasses' => 'postcode-search-banner--copy leader',
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
    $pane->subtype = 'uuid:c53127ca-edab-4293-b7d1-e1154b223380';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'columns' => 'grid-9',
        'prefix' => '',
        'suffix' => '',
        'narrowColumns' => '',
        'alpha' => 0,
        'omega' => 0,
        'force-end-desktop' => 1,
        'text-align-center-narrow-mobile' => 0,
        'text-align-center-mobile-only' => 0,
        'container-center' => 0,
        'extraClasses' => 'leader',
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
  $export['postcode_search_banner'] = $mini;

  return $export;
}
