<?php
/**
 * @file
 * rnd15_donate.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function rnd15_donate_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cr_donate_giftaid_calculator';
  $strongarm->value = '<p class="type--centred type--lg col-xs-12 col-md-8 col-md-offset-2">When you tick the Gift Aid box, Comic Relief will receive an extra <span class="giftaid-calculator-amount">25%</span> on top of your <span class="giftaid-calculator-donation"></span> donation to help run itself, and it doesn\'t cost you a penny.</p>';
  $export['cr_donate_giftaid_calculator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cr_donate_giftaid_text';
  $strongarm->value = '<p class="type--centred">If you\'re paying in a personal donation, pay UK tax* and tick the Gift Aid box, the Goverment will give us 25% on top of your donation, which we use to help cover our running costs. It won\'t go towards helping to transform people\'s lives in the UK and across Africa. Please give your full name and home address and tick the box or we can\'t claim Gift Aid.</p><p class="type--centred">* You will need to have paid enough UK Income Tax and/or Capital Gains Tax in the current tax year to cover the 25% that Comic Relief and any other charities and Community Amateur Sports Clubs that you donate to will claim for the current tax year. (Council Tax and VAT do not count). <a class="link--inline-grey" href="/frequently-asked-questions#/gift-aid/gift-aid" target="_blank">Find out more about Gift Aid</a>.</p>';
  $export['cr_donate_giftaid_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cr_donate_marketing_prefs_email_text';
  $strongarm->value = 'Would you like us to keep you informed using your email address about what Comic Relief\'s up to?';
  $export['cr_donate_marketing_prefs_email_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cr_donate_marketing_prefs_post_text';
  $strongarm->value = 'Would you like to be kept informed by post about what Comic Relief\'s up to? Please untick the box if you\'d rather not.';
  $export['cr_donate_marketing_prefs_post_text'] = $strongarm;

  return $export;
}
