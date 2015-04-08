<?php
/**
 * @file
 * sr14_menu.ctools_content.inc
 */

/**
 * Implements hook_default_ctools_custom_content().
 */
function sr14_menu_default_ctools_custom_content() {
  $export = array();

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'event_info_menu_pane';
  $content->admin_title = 'event_info_menu_pane';
  $content->admin_description = '';
  $content->category = 'Mega Menu';
  $content->settings = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<p>Run</p><p>Lorem ipsum dolor sit amet consectetuer adipiscing nibh.</p><p><a class="button" href="#">Find out more</a></p><p>&nbsp;</p><p>Swim</p><p>Lorem ipsum dolor sit amet consectetuer adipiscing nibh.</p><p><a class="button" href="#">Find out more</a></p><p>&nbsp;</p><p>Cycle</p><p>Lorem ipsum dolor sit amet consectetuer adipiscing nibh.</p><p><a class="button" href="#">Find out more</a></p>',
    'format' => 'wysiwyg',
    'substitute' => 1,
  );
  $export['event_info_menu_pane'] = $content;

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'fundraise_menu_pane';
  $content->admin_title = 'fundraise_menu_pane';
  $content->admin_description = '';
  $content->category = 'Mega Menu';
  $content->settings = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<p>Start collecting sponsorship</p><p><a class="cta" href="#">download a form</a></p>',
    'format' => 'wysiwyg',
    'substitute' => 1,
  );
  $export['fundraise_menu_pane'] = $content;

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'schools_menu_pane';
  $content->admin_title = 'schools_menu_pane';
  $content->admin_description = '';
  $content->category = 'Mega Menu';
  $content->settings = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<p>Look the part &amp; get the kit</p><p><a class="cta" href="#">Go to the shop</a></p>',
    'format' => 'wysiwyg',
    'substitute' => 1,
  );
  $export['schools_menu_pane'] = $content;

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'support_menu_pane';
  $content->admin_title = 'support_menu_pane';
  $content->admin_description = '';
  $content->category = 'Mega Menu';
  $content->settings = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<p>Your money makes a difference</p><p><a class="cta" href="#">find out how</a></p>',
    'format' => 'wysiwyg',
    'substitute' => 1,
  );
  $export['support_menu_pane'] = $content;

  return $export;
}
