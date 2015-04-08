<?php
/**
 * @file
 * sr_news_gallery.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sr_news_gallery_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sr14_news_and_video_gallery';
  $context->description = 'Body classes and CSS documents required on /news-and-video-gallery';
  $context->tag = 'CSS';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'news-and-video-gallery' => 'news-and-video-gallery',
      ),
    ),
  );
  $context->reactions = array(
    'css' => array(
      'Sport Relief 2014' => array(
        'sites/sportrelief.com/themes/sport_relief_2014/css/components/tile-grid.less' => 'sites/sportrelief.com/themes/sport_relief_2014/css/components/tile-grid.less',
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Body classes and CSS documents required on /news-and-video-gallery');
  t('CSS');
  $export['sr14_news_and_video_gallery'] = $context;

  return $export;
}
