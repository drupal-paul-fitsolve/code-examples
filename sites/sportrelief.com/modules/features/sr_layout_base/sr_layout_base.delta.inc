<?php
/**
 * @file
 * sr_layout_base.delta.inc
 */

/**
 * Implements hook_delta_default_templates().
 */
function sr_layout_base_delta_default_templates() {
  $export = array();

  $delta = new stdClass();
  $delta->disabled = FALSE; /* Edit this to true to make a default delta disabled initially */
  $delta->api_version = 3;
  $delta->machine_name = 'basic_page';
  $delta->name = 'Basic Page';
  $delta->description = 'A basic page layout';
  $delta->theme = 'sport_relief';
  $delta->mode = 'preserve';
  $delta->parent = '';
  $delta->settings = array(
    'theme_sport_relief_settings' => array(
      'alpha_region_content_css' => 'pod pod--padding trailer leader container-24',
    ),
  );
  $export['basic_page'] = $delta;

  $delta = new stdClass();
  $delta->disabled = FALSE; /* Edit this to true to make a default delta disabled initially */
  $delta->api_version = 3;
  $delta->machine_name = 'content_page';
  $delta->name = 'Content Page';
  $delta->description = 'A Content Page with sidebar regions';
  $delta->theme = 'sport_relief';
  $delta->mode = 'preserve';
  $delta->parent = '';
  $delta->settings = array(
    'theme_sport_relief_settings' => array(
      'alpha_exclude' => array(
        'sites/all/modules/contrib/date/date_api/date.css' => 'sites/all/modules/contrib/date/date_api/date.css',
        'modules/field/theme/field.css' => 'modules/field/theme/field.css',
        'sites/all/modules/contrib/flexslider/assets/css/flexslider_img.css' => 'sites/all/modules/contrib/flexslider/assets/css/flexslider_img.css',
        'modules/node/node.css' => 'modules/node/node.css',
        'sites/all/modules/contrib/picture/picture_wysiwyg.css' => 'sites/all/modules/contrib/picture/picture_wysiwyg.css',
        'modules/search/search.css' => 'modules/search/search.css',
        'modules/user/user.css' => 'modules/user/user.css',
        'sites/all/modules/contrib/views/css/views.css' => 'sites/all/modules/contrib/views/css/views.css',
        'misc/vertical-tabs.css' => 'misc/vertical-tabs.css',
        'modules/aggregator/aggregator.css' => 'modules/aggregator/aggregator.css',
        'modules/block/block.css' => 'modules/block/block.css',
        'modules/dblog/dblog.css' => 'modules/dblog/dblog.css',
        'modules/file/file.css' => 'modules/file/file.css',
        'modules/filter/filter.css' => 'modules/filter/filter.css',
        'modules/help/help.css' => 'modules/help/help.css',
        'modules/menu/menu.css' => 'modules/menu/menu.css',
        'modules/openid/openid.css' => 'modules/openid/openid.css',
        'modules/profile/profile.css' => 'modules/profile/profile.css',
        'modules/statistics/statistics.css' => 'modules/statistics/statistics.css',
        'modules/syslog/syslog.css' => 'modules/syslog/syslog.css',
        'modules/system/admin.css' => 'modules/system/admin.css',
        'modules/system/maintenance.css' => 'modules/system/maintenance.css',
        'modules/system/system.css' => 'modules/system/system.css',
        'modules/system/system.admin.css' => 'modules/system/system.admin.css',
        'modules/system/system.maintenance.css' => 'modules/system/system.maintenance.css',
        'modules/system/system.theme.css' => 'modules/system/system.theme.css',
        'modules/taxonomy/taxonomy.css' => 'modules/taxonomy/taxonomy.css',
        'modules/tracker/tracker.css' => 'modules/tracker/tracker.css',
        'modules/update/update.css' => 'modules/update/update.css',
        'sites/all/modules/contrib/colorbox_node/colorbox_node.css' => 0,
        'sites/all/themes/custom/cr_layout/css/cr_layout-all.less' => 0,
        'sites/sportrelief.com/themes/sport_relief_2014/css/utilities-and-base.less' => 0,
        'sites/sportrelief.com/themes/sport_relief_2014/css/all-components1.less' => 0,
        'sites/sportrelief.com/themes/sport_relief_2014/css/all-components2.less' => 0,
        'sites/sportrelief.com/themes/sport_relief_2014/css/styleguide-and-overrides.less' => 0,
        'modules/system/system.base.css' => 0,
        'modules/system/system.menus.css' => 0,
        'modules/system/system.messages.css' => 0,
      ),
      'alpha_region_sidebar_first_zone' => NULL,
      'alpha_region_sidebar_first_equal_height_element' => FALSE,
      'alpha_zone_content_wrapper' => 1,
      'alpha_zone_content_css' => 'row',
      'alpha_zone_content_wrapper_css' => 'container-24 clearfix',
      'alpha_region_content_force' => 1,
      'alpha_region_content_columns' => '18',
      'alpha_region_content_css' => 'grid-18 narrow-grid-24 narrow-no-equality',
      'alpha_region_sidebar_second_force' => 1,
      'alpha_region_sidebar_second_columns' => '6',
      'alpha_region_sidebar_second_css' => 'row grid-6 narrow-grid-24 narrow-no-equality auto-height__100 autoheight-run',
    ),
  );
  $export['content_page'] = $delta;

  return $export;
}
