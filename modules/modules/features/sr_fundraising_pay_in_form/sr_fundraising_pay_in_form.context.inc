<?php
/**
 * @file
 * sr_fundraising_pay_in_form.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sr_fundraising_pay_in_form_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'pay_in_fundraising_money';
  $context->description = 'Form to specify fundraising activity and pay in';
  $context->tag = 'Fundraise';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'pay-in-fundraising-money' => 'pay-in-fundraising-money',
      ),
    ),
  );
  $context->reactions = array(
    'css' => array(
      'Sport Relief 2014' => array(
        'sites/sportrelief.com/themes/sport_relief_2014/css/components/pay-fundraising-money.less' => 'sites/sportrelief.com/themes/sport_relief_2014/css/components/pay-fundraising-money.less',
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Form to specify fundraising activity and pay in');
  t('Fundraise');
  $export['pay_in_fundraising_money'] = $context;

  return $export;
}
