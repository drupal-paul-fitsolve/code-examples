<?php
/**
 * @file
 * cr_news.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function cr_news_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sr_news_articles';
  $context->description = '';
  $context->tag = 'News';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'news_article' => 'news_article',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-news_article_title' => array(
          'module' => 'boxes',
          'delta' => 'news_article_title',
          'region' => 'preface_second',
          'weight' => '-10',
        ),
        'delta_blocks-messages' => array(
          'module' => 'delta_blocks',
          'delta' => 'messages',
          'region' => 'preface_second',
          'weight' => '-9',
        ),
        'delta_blocks-tabs' => array(
          'module' => 'delta_blocks',
          'delta' => 'tabs',
          'region' => 'preface_second',
          'weight' => '-8',
        ),
        'bean-media-bar-home-media' => array(
          'module' => 'bean',
          'delta' => 'media-bar-home-media',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'content_page',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('News');
  $export['sr_news_articles'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sr_news_articles_no_social';
  $context->description = '';
  $context->tag = 'News';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'news_article' => 'news_article',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'node_taxonomy' => array(
      'values' => array(
        60 => 60,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-media-bar-fun-and-games' => array(
          'module' => 'bean',
          'delta' => 'media-bar-fun-and-games',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
    'block_disable' => array(
      'blocks' => array(
        'bean' => array(
          'bean-media-bar-home-media' => 'bean-media-bar-home-media',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'content_page',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('News');
  $export['sr_news_articles_no_social'] = $context;

  return $export;
}
