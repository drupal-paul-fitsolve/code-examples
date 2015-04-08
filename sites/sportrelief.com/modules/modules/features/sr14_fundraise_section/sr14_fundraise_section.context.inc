<?php
/**
 * @file
 * sr14_fundraise_section.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sr14_fundraise_section_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sr14_fundraise_showcase_scroller';
  $context->description = 'Body classes and CSS documents required on /fundraise.';
  $context->tag = 'CSS';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'fundraise' => 'fundraise',
        'news-and-video-gallery' => 'news-and-video-gallery',
        'schools/secondary' => 'schools/secondary',
        'schools/primary' => 'schools/primary',
        'schools/nurseries' => 'schools/nurseries',
        'schools/youth-groups' => 'schools/youth-groups',
      ),
    ),
  );
  $context->reactions = array(
    'css' => array(
      'Sport Relief 2014' => array(
        'sites/sportrelief.com/themes/sport_relief_2014/css/components/showcase-scroller.less' => 'sites/sportrelief.com/themes/sport_relief_2014/css/components/showcase-scroller.less',
      ),
    ),
    'theme_html' => array(
      'class' => 'FundraiseShowcaseScroller',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Body classes and CSS documents required on /fundraise.');
  t('CSS');
  $export['sr14_fundraise_showcase_scroller'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sr14_fundraiser_showcase';
  $context->description = 'Body classes and CSS documents required on /fundraise/fundraiser-showcase';
  $context->tag = 'CSS';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'fundraise/fundraiser-showcase' => 'fundraise/fundraiser-showcase',
        'ugc_image/*' => 'ugc_image/*',
        'node/add/fundraiser-showcase*' => 'node/add/fundraiser-showcase*',
      ),
    ),
  );
  $context->reactions = array(
    'css' => array(
      'Sport Relief 2014' => array(
        'sites/sportrelief.com/themes/sport_relief_2014/css/components/fundraiser-showcase.less' => 'sites/sportrelief.com/themes/sport_relief_2014/css/components/fundraiser-showcase.less',
        'sites/sportrelief.com/themes/sport_relief_2014/css/components/fundraiser-showcase-upload.less' => 'sites/sportrelief.com/themes/sport_relief_2014/css/components/fundraiser-showcase-upload.less',
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Body classes and CSS documents required on /fundraise/fundraiser-showcase');
  t('CSS');
  $export['sr14_fundraiser_showcase'] = $context;

  return $export;
}
