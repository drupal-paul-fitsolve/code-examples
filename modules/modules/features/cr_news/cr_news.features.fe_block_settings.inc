<?php
/**
 * @file
 * cr_news.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function cr_news_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['boxes-news_article_title'] = array(
    'cache' => -2,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'news_article_title',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'cr_layout' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'cr_layout',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'sport_relief' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sport_relief',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
