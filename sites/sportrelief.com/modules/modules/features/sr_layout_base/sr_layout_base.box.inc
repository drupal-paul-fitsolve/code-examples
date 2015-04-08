<?php
/**
 * @file
 * sr_layout_base.box.inc
 */

/**
 * Implements hook_default_box().
 */
function sr_layout_base_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'user_menu';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'User menu';
  $box->options = array(
    'body' => array(
      'value' => '<ul class="user-menu">
<!--<li><a class="user-login" href="#">Login</a></li>-->
<li><a class="user-esu" href="#">Get all the latest</a></li>
</ul>',
      'format' => 'wysiwyg',
    ),
    'additional_classes' => '',
  );
  $export['user_menu'] = $box;

  return $export;
}
