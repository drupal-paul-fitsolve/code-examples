<?php
/**
 * @file
 * sr14_menu.box.inc
 */

/**
 * Implements hook_default_box().
 */
function sr14_menu_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'search_header';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Search header';
  $box->options = array(
    'body' => array(
      'value' => '<a href="/search" class="icon icon--search">Search</a>
<form action="/search" method="get" accept-charset="UTF-8">

<input type="text" name="query" value="" placeholder="Search..." maxlength="128" class="text-input" />
<input type="submit" name="" value="Search" class="button button--submit" />
</form>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['search_header'] = $box;

  return $export;
}
