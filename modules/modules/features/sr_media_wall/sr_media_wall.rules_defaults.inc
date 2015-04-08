<?php
/**
 * @file
 * sr_media_wall.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function sr_media_wall_default_rules_configuration() {
  $items = array();
  $items['rules_sr_media_wall'] = entity_import('rules_config', '{ "rules_sr_media_wall" : {
      "LABEL" : "SR Media Wall",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Sportrelief" ],
      "REQUIRES" : [ "rules", "php" ],
      "ON" : { "node_insert" : [], "node_update" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : {
                "media_images" : "media_images",
                "news_article" : "news_article",
                "video" : "video"
              }
            }
          }
        },
        { "AND" : [ { "node_is_published" : { "node" : [ "node" ] } } ] }
      ],
      "DO" : [
        { "php_eval" : { "code" : "cache_clear_all(\\u0027sr_media_wall\\u0027, \\u0027cache\\u0027, TRUE);\\r\\nwatchdog(\\u0027SR Media Wall\\u0027, \\u0027Purged Media Wall cache\\u0027, array(), WATCHDOG_INFO);" } },
        { "drupal_message" : { "message" : "Cleared Media Wall cache" } }
      ]
    }
  }');
  return $items;
}
