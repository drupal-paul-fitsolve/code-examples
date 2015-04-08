<?php
/**
 * @file
 * cr_news.box.inc
 */

/**
 * Implements hook_default_box().
 */
function cr_news_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'news_article_title';
  $box->plugin_key = 'simple';
  $box->title = '<none>';
  $box->description = 'News Articles Title';
  $box->options = array(
    'body' => array(
      'value' => '<h1 class="text--padded-page-title">News</h1>',
      'format' => 'wysiwyg',
    ),
    'additional_classes' => '',
  );
  $export['news_article_title'] = $box;

  return $export;
}
