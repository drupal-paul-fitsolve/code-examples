<?php
/**
 * @file
 * rnd15_site_news_article.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function rnd15_site_news_article_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function rnd15_site_news_article_node_info() {
  $items = array(
    'news_article' => array(
      'name' => t('News article'),
      'base' => 'node_content',
      'description' => t('Use a \'News article\' to publish an article in the News section. Supports title, image, body, publish date and and media tags.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
