<?php
/**
 * @file
 * cr_video.box.inc
 */

/**
 * Implements hook_default_box().
 */
function cr_video_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'video_article_title';
  $box->plugin_key = 'simple';
  $box->title = '<none>';
  $box->description = 'Video Title';
  $box->options = array(
    'body' => array(
      'value' => '<h1 class="text--padded-page-title">Videos</h1>',
      'format' => 'wysiwyg',
    ),
  );
  $export['video_article_title'] = $box;

  return $export;
}
