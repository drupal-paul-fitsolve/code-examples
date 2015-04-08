<?php
/**
 * @file
 * sr_media_bar.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function sr_media_bar_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'twitter_feed_import-blank_source_1-rewrite';
  $feeds_tamper->importer = 'twitter_feed_import';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => 'https://twitter.com/[jsonpath_parser:8]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Twitter User Link';
  $export['twitter_feed_import-blank_source_1-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'twitter_feed_import-jsonpath_parser_7-twitter_link_title_rewrite';
  $feeds_tamper->importer = 'twitter_feed_import';
  $feeds_tamper->source = 'jsonpath_parser:7';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[jsonpath_parser:3] <span class="media-bar__twitter-username">@[jsonpath_parser:8]</span>',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Twitter Link Rewrite';
  $export['twitter_feed_import-jsonpath_parser_7-twitter_link_title_rewrite'] = $feeds_tamper;

  return $export;
}
