<?php
/**
 * @file
 * cr_video.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function cr_video_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cr_videos';
  $context->description = '';
  $context->tag = 'Videos';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'video' => 'video',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-video_article_title' => array(
          'module' => 'boxes',
          'delta' => 'video_article_title',
          'region' => 'preface_first',
          'weight' => '-10',
        ),
        'delta_blocks-messages' => array(
          'module' => 'delta_blocks',
          'delta' => 'messages',
          'region' => 'preface_first',
          'weight' => '-9',
        ),
        'delta_blocks-tabs' => array(
          'module' => 'delta_blocks',
          'delta' => 'tabs',
          'region' => 'preface_first',
          'weight' => '-8',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'content_page',
    ),
    'theme_html' => array(
      'class' => 'context-video',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Videos');
  $export['cr_videos'] = $context;

  return $export;
}
