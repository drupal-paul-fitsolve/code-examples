<?php
/**
 * @file
 * sr_fun_and_games.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function sr_fun_and_games_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cvm_enabled_content_types';
  $strongarm->value = array(
    0 => 'media_images',
    1 => 'news_article',
    2 => 'video',
  );
  $export['cvm_enabled_content_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cvm_global_content_type_modes';
  $strongarm->value = array(
    'media' => array(
      'images_fun_games_content' => 'full_content_no_social',
    ),
    'news' => array(
      'article_fun_games_content' => 'full_content_no_social',
    ),
    'video' => array(
      'fun_games_content' => 'full_content_no_social',
    ),
  );
  $export['cvm_global_content_type_modes'] = $strongarm;

  return $export;
}
