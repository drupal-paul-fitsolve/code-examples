<?php
/**
 * @file
 * sr16splash_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sr16splash_search_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function sr16splash_search_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function sr16splash_search_node_info() {
  $items = array(
    'search_downloadable' => array(
      'name' => t('Search Downloadable'),
      'base' => 'node_content',
      'description' => t('Searchable clone for downloadable items.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'shop_product' => array(
      'name' => t('Shop product'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function sr16splash_search_default_search_api_index() {
  $items = array();
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default node index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : "search",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "20",
      "data_alter_callbacks" : {
        "cr_page_manager_search_api_exclude_item_alter" : { "status" : 0, "weight" : "-50", "settings" : [] },
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_exclude_filter" : { "status" : 1, "weight" : "-10", "settings" : [] },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "type" : true, "title" : true, "body:value" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      },
      "fields" : {
        "nid" : { "type" : "integer" },
        "vid" : { "type" : "integer" },
        "type" : { "type" : "string" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "url" : { "type" : "uri" },
        "promote" : { "type" : "boolean" },
        "sticky" : { "type" : "boolean" },
        "created" : { "type" : "date" },
        "changed" : { "type" : "date" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "field_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_media" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_shop_url" : { "type" : "string" },
        "field_search_dl_url_token" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "search_api_url" : { "type" : "uri" },
        "body:value" : { "type" : "text" },
        "body:summary" : { "type" : "string" },
        "field_site_image_xs:file" : { "type" : "integer", "entity_type" : "file" }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  $items['page_manager_pages'] = entity_import('search_api_index', '{
    "name" : "Page Manager pages",
    "machine_name" : "page_manager_pages",
    "description" : null,
    "server" : "search",
    "item_type" : "page_manager_search",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "20",
      "fields" : {
        "title" : { "type" : "text", "boost" : "5.0" },
        "content" : { "type" : "text" },
        "description" : { "type" : "text", "boost" : "2.0" },
        "title_string" : { "type" : "string" },
        "description_string" : { "type" : "string" },
        "image_url" : { "type" : "string" },
        "entity_type" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "search_api_url" : { "type" : "uri" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : false } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 1, "weight" : "0", "settings" : [] },
        "cr_page_manager_search_api_exclude_item_alter" : { "status" : 1, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "content" : true, "description" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "content" : true, "description" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "content" : true, "description" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "content" : true, "description" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_preprocess_views_view()
 * @param $vars
 */
function sr16splash_search_preprocess_views_view(&$vars) {
  if ($vars['view']->name == 'cr_search') {
    $tabs = array(
      'search' => t('All'),
      'search/pages' => t('Pages'),
      'search/downloads' => t('Downloads'),
      'search/videos' => t('Videos'),
      'search/news' => t('News'),
      'search/shop' => t('Stuff to order'),
    );

    foreach ($tabs as $path => &$tab) {
      $options = array();
      $options['attributes']['class'][] = 'tab-link btn btn-red';
      if (request_path() == $path) {
        $options['attributes']['class'][] = 'tabs-active';
      }

      if (!empty($_GET['query'])) {
        $options['query']['query'] = $_GET['query'];
      }

      // Generate tab link.
      $tab = l($tab, $path, $options);
    }

    // Generate list element.
    $vars['tabs'] = $tabs;
  }
}