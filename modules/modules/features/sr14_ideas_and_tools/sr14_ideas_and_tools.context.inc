<?php
/**
 * @file
 * sr14_ideas_and_tools.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sr14_ideas_and_tools_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sr14_ideas_and_tools_tools_overlay';
  $context->description = 'Body classes and CSS documents required on /fundraise/ideas-and-tools';
  $context->tag = 'CSS';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'fundraise/ideas-and-tools*' => 'fundraise/ideas-and-tools*',
      ),
    ),
  );
  $context->reactions = array(
    'css' => array(
      'Sport Relief 2014' => array(
        'sites/sportrelief.com/themes/sport_relief_2014/css/components/sponsorship-forms.less' => 'sites/sportrelief.com/themes/sport_relief_2014/css/components/sponsorship-forms.less',
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Body classes and CSS documents required on /fundraise/ideas-and-tools');
  t('CSS');
  $export['sr14_ideas_and_tools_tools_overlay'] = $context;

  return $export;
}
