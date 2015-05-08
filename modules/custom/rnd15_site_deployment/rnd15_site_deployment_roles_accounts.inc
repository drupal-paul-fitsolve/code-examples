<?php
/*/**
 * @file
 * .inc file for rnd15_site_deployment module
 *
 * This file exists for helper functions, that return arrays of data for the deployment module,
 * These are used within the .install file.
 *
 * @author Carl Hinton for Comic Relief.
 * @date 3rd February 2015.
 */

/**
 * Simple function to return a list of roles.
 * @return array
 *   - The list of roles.
 */
function rnd15_site_deployment_get_roles_RED_1507() {
  return array(
    'developer',
    'page builder',
    'content editor',
  );
}

/**
 * Simple function to return a structured array listing roles to be applied to user names.
 * @return array
 *   - The structured array of users => roles.
 */
function rnd15_site_deployment_get_users_RED_1507() {
  $roles = array(
    'developer' => array(
      'c.hinton',
      'j.pitt',
      'g.nair',
      'a.phipps',
      'g.utton',
      'j.wang',
      'o.nwokeji',
      'p.wilkin',
      'p.brady',
      'm.wagg',
      'v.reddy',
    ),
    'content editor' => array(
      'm.mcmahon',
      'k.lampshire',
      'n.cowan',
      'e.day',
      'v.dzimwasha',
      'g.brown',
      'c.rabban',
      't.cooper',
      'f.wakefield',
      'k.smith',
      'l.morgan',
      'j.squire',
      'l.hall',
      'm.wagg',
      'm.keilty',
      'c.rabban',
      'd.ridge',
      'j.addeh',
    ),
    'page builder' => array(
      'v.dzimwasha',
      'g.brown',
      'c.rabban',
      't.cooper',
      'f.wakefield',
      'k.smith',
      'l.morgan',
      'j.squire',
      'l.hall',
      'm.wagg',
      't.cooper',
      'j.carney',
      'm.keilty',
      'c.rabban',
      'd.ridge',
      'j.addeh',
    ),
    'authenticated user' => array(
      's.mechineni',
      'k.pammi',
      'c.miryala',
    ),
  );

  // Flip the array around for easier use.
  $users = array();
  foreach ($roles as $key => $role) {
    foreach ($role as $user) {
      $users[$user][] = $key;
    }
  }

  return $users;

}

/**
 * A simple function that returns a structured array of permissions and the roles that hold those permissions.
 * @return array
 *  - The structure array
 *  - The array relates to (page builder, content editor); as developer is assumed to have all permissions.
 */
function rnd15_site_deployment_get_role_perms_RED_1507() {

  return array(
    'administer blocks' =>
      array(),
    'access all webform results' =>
      array(),
    'edit all webform submissions' =>
      array(),
    'delete all webform submissions' =>
      array(),
    'access own webform submissions' =>
      array(),
    'edit own webform submissions' =>
      array(),
    'delete own webform submissions' =>
      array(),
    'access backup and migrate' =>
      array(),
    'perform backup' =>
      array(),
    'access backup files' =>
      array(),
    'delete backup files' =>
      array(),
    'restore from backup' =>
      array(),
    'administer backup and migrate' =>
      array(),
    'administer bean types' =>
      array(),
    'administer beans' =>
      array(),
    'access bean overview' =>
      array(),
    'edit bean view mode' =>
      array(),
    'view bean page' =>
      array(),
    'administer bean settings' =>
      array(),
    'view bean revisions' =>
      array(),
    'create any cr_optional_info bean' =>
      array(),
    'edit any cr_optional_info bean' =>
      array(),
    'view any cr_optional_info bean' =>
      array(),
    'delete any cr_optional_info bean' =>
      array(),
    'create any cr_share bean' =>
      array(),
    'edit any cr_share bean' =>
      array(),
    'view any cr_share bean' =>
      array(),
    'delete any cr_share bean' =>
      array(),
    'edit boxes' =>
      array(),
    'administer boxes' =>
      array(),
    'administer breakpoints' =>
      array(),
    'administer CDN configuration' =>
      array(),
    'access per-page statistics' =>
      array(),
    'access files on CDN when in testing mode' =>
      array(),
    'touch files' =>
      array(),
    'administer ckeditor' =>
      array(),
    'customize ckeditor' =>
      array(),
    'administer contact forms' =>
      array(),
    'access site-wide contact form' =>
      array(),
    'access user contact forms' =>
      array(),
    'access contextual links' =>
      array(),
    'administer contexts' =>
      array(),
    'context ajax block access' =>
      array(),
    'administer downloadable' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'access dashboard' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'administer delta blocks' =>
      array(),
    'administer EU Cookie Compliance popup' =>
      array(),
    'display EU Cookie Compliance popup' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
        RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'administer fieldable panels panes' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'create fieldable fieldable_panels_pane' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'edit fieldable fieldable_panels_pane' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'delete fieldable fieldable_panels_pane' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'create fieldable donate_money_buy' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'edit fieldable donate_money_buy' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'delete fieldable donate_money_buy' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'create fieldable money_buy' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'edit fieldable money_buy' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'delete fieldable money_buy' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'create fieldable money_buy_fundraiser' =>
      array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'edit fieldable money_buy_fundraiser' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'delete fieldable money_buy_fundraiser' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'create fieldable image' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
        RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'edit fieldable image' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
        RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'delete fieldable image' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
        RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'create fieldable image_overlay' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
        RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'edit fieldable image_overlay' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
        RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'delete fieldable image_overlay' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
        RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'create fieldable video' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
        RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'edit fieldable video' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
        RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'delete fieldable video' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
        RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'create fieldable text' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
        RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'edit fieldable text' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
        RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'delete fieldable text' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
        RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'create fieldable svg' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
        RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'edit fieldable svg' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
        RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'delete fieldable svg' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
        RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'administer filters' =>
      array(),
    'use text format wysiwyg' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
        RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'use text format full_html' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
        RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'use text format links' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
        RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'use text format filtered_html' => array(
        RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
        RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'administer flexslider' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'administer google tag manager' =>
      array(),
    'administer image styles' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'administer menu' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'administer meta tags' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'edit meta tags' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'administer module filter' =>
      array(),
    'bypass node access' =>
      array(),
    'administer content types' =>
      array(),
    'administer nodes' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'access content overview' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'access content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'view own unpublished content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'view revisions' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'revert revisions' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'delete revisions' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'create article content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'edit own article content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'edit any article content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'delete own article content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'delete any article content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'create media_image content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'edit own media_image content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'edit any media_image content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'delete own media_image content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'delete any media_image content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'create video content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'edit own video content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'edit any video content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'delete own video content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'delete any video content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'create news_article content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'edit own news_article content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'edit any news_article content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'delete own news_article content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'delete any news_article content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'create panel content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'edit own panel content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'edit any panel content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'delete own panel content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'delete any panel content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'create page content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'edit own page content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'edit any page content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'delete own page content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'delete any page content' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'create webform content' => array(),
    'edit own webform content' => array(),
    'edit any webform content' => array(),
    'delete own webform content' => array(),
    'delete any webform content' => array(),
    'use panels dashboard' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'view pane admin links' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'administer pane access' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'use panels in place editing' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'change layouts in place editing' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'administer advanced pane settings' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'administer panels layouts' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'administer panels styles' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'use panels caching features' => array(),
    'use panels locks' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'use ipe with page manager' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'create mini panels' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'administer mini panels' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'administer url aliases' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'create url aliases' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'administer pictures' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'administer redirects' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'administer shortcuts' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'customize shortcut links' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'switch shortcut sets' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'access site map' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'view style guides' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'administer modules' => array(),
    'administer site configuration' => array(),
    'administer themes' => array(),
    'administer software updates' => array(),
    'administer actions' => array(),
    'access administration pages' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'access site in maintenance mode' => array(),
    'view the administration theme' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'access site reports' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'block IP addresses' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'administer taxonomy' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'edit terms in 2' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'delete terms in 2' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'edit terms in 3' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'delete terms in 3' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'edit terms in 1' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'delete terms in 1' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'administer permissions' => array(),
    'administer users' => array(),
    'access user profiles' => array(),
    'change own username' => array(),
    'cancel account' => array(),
    'select account cancellation method' => array(),
    'administer varnish' => array(),
    'administer web services' => array(),
    'interact with cr_marketing_preferences' => array(),
    'admin_display_suite' => array(),
    'administer fieldgroups' => array(),
    'administer pathauto' => array(),
    'notify of path changes' => array(),
    'administer xmlsitemap' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER),
    'administer menu attributes' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'administer views' => array(),
    'access all views' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'create panel-nodes' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'edit any panel-nodes' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'edit own panel-nodes' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'administer panel-nodes' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'delete any panel-nodes' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'delete own panel-nodes' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'administer features' =>
      array(),
    'manage features' =>
      array(),
    'access devel information' =>
      array(),
    'execute php code' =>
      array(),
    'switch users' =>
      array(),
    'use page manager' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'administer page manager' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'access administration menu' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'flush caches' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'display drupal links' => array(
      RND_15_SITE_DEPLOYMENT_ROLE_PAGE_BUILDER,
      RND_15_SITE_DEPLOYMENT_ROLE_CONTENT_EDITOR),
    'administer minify' =>
      array(),
    'administer inline form errors' =>
      array(),);

}