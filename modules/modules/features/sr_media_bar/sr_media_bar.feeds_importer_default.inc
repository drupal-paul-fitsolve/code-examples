<?php
/**
 * @file
 * sr_media_bar.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function sr_media_bar_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'twitter_feed_import';
  $feeds_importer->config = array(
    'name' => 'Twitter Feed Import',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'OAuthHTTPFetcher',
      'config' => array(
        'authenticator' => 'feeds_oauth_get_tokens',
        'site_id' => 'twitter',
        'consumer_key' => 'bsQZZ5iNjKBNxYnNcA4DGQ',
        'consumer_secret' => 'OicwTXldtihLfgzKuO9LSjNW7QTiZumJoSdq8bUe6Yg',
        'request_token_url' => 'https://api.twitter.com/oauth/request_token',
        'access_token_url' => 'https://api.twitter.com/oauth/access_token',
        'authorize_url' => 'https://api.twitter.com/oauth/authorize',
        'method' => 'post',
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsJSONPathParser',
      'config' => array(
        'context' => '$.*',
        'sources' => array(
          'jsonpath_parser:0' => 'id',
          'jsonpath_parser:1' => 'user.name',
          'jsonpath_parser:2' => 'text',
          'jsonpath_parser:3' => 'user.name',
          'jsonpath_parser:4' => 'user.id_str',
          'jsonpath_parser:5' => 'id',
          'jsonpath_parser:6' => 'entities.hashtags.*.text',
          'jsonpath_parser:7' => '{field_tweet_user_screen_name}',
          'jsonpath_parser:8' => 'user.screen_name',
          'jsonpath_parser:9' => 'created_at',
          'jsonpath_parser:10' => 'entities.media.*.media_url',
        ),
        'debug' => array(
          'options' => array(
            'context' => 0,
            'jsonpath_parser:0' => 0,
            'jsonpath_parser:1' => 0,
            'jsonpath_parser:2' => 0,
            'jsonpath_parser:3' => 0,
            'jsonpath_parser:4' => 0,
            'jsonpath_parser:5' => 0,
            'jsonpath_parser:6' => 0,
            'jsonpath_parser:7' => 0,
            'jsonpath_parser:8' => 0,
            'jsonpath_parser:9' => 0,
            'jsonpath_parser:10' => 0,
          ),
        ),
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'jsonpath_parser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'jsonpath_parser:1',
            'target' => 'title_field',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'jsonpath_parser:2',
            'target' => 'body',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'jsonpath_parser:3',
            'target' => 'field_tweet_user',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'jsonpath_parser:4',
            'target' => 'field_tweet_user_id',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'jsonpath_parser:5',
            'target' => 'field_tweet_id',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'jsonpath_parser:6',
            'target' => 'field_twitter_tag',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          7 => array(
            'source' => 'jsonpath_parser:7',
            'target' => 'field_tweet_user_link:title',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Blank source 1',
            'target' => 'field_tweet_user_link:url',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'jsonpath_parser:8',
            'target' => 'field_tweet_user_screen_name',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'jsonpath_parser:9',
            'target' => 'field_tweet_date:start',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'jsonpath_parser:10',
            'target' => 'field_tweet_image',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'tweets',
        'skip_hash_check' => 0,
        'bundle' => 'tweet',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['twitter_feed_import'] = $feeds_importer;

  return $export;
}
