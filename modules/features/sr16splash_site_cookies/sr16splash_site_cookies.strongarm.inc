<?php
/**
 * @file
 * sr16splash_site_cookies.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function sr16splash_site_cookies_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'eu_cookie_compliance_en';
  $strongarm->value = array(
    'popup_enabled' => 1,
    'post_enabled' => 1,
    'popup_clicking_confirmation' => 0,
    'popup_position' => 1,
    'popup_info' => array(
      'value' => '<p><strong>Our site uses cookies.</strong> By continuing to use this site you\'re agreeing to our use of cookies. For more info on what cookies are, and how we use them, <a class="type--white" href="/legal#/privacy-policy/cookies">click here.</a></p>',
      'format' => 'full_html',
    ),
    'popup_agreed_enabled' => 0,
    'popup_hide_agreed' => 1,
    'popup_agreed' => array(
      'value' => '<h2>Thank you for accepting cookies</h2><p>You can now hide this message or find out more about cookies.</p>',
      'format' => 'plain_text',
    ),
    'popup_link' => 'legal#/privacy-policy/cookies ',
    'popup_height' => '',
    'popup_width' => '100%',
    'popup_delay' => '1',
    'popup_bg_hex' => '000000',
    'popup_text_hex' => 'ffffff',
  );
  $export['eu_cookie_compliance_en'] = $strongarm;

  return $export;
}
