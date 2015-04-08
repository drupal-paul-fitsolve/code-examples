<?php
/**
 * @file
 * cr_cookies.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cr_cookies_strongarm() {
  
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'eu_cookie_compliance_en';
  $strongarm->value = array(
    'popup_enabled' => 1,
    'popup_clicking_confirmation' => 1,
    'popup_position' => 1,
    'popup_info' => array(
      'value' => '<p><strong>Our site uses cookies.</strong> By continuing to use this site you\'re agreeing to our use of cookies. For more info on what cookies are, are how we use them, <a href="/privacy-policy#cookies?cookies">click here.</a></p>',
      'format' => 'full_html',
    ),
    'popup_agreed_enabled' => 0,
    'popup_hide_agreed' => 1,
    'popup_agreed' => array(
      'value' => '<p><strong>Thank you for accepting cookies.</strong> You can now hide this message or find out more about cookies.</p>',
      'format' => 'full_html',
    ),
    'popup_link' => '/privacy-policy#cookies?cookies',
    'popup_height' => '',
    'popup_width' => '100%',
    'popup_delay' => '1',
    'popup_bg_hex' => '000',
    'popup_text_hex' => 'ffffff',
  );
  $export['eu_cookie_compliance_en'] = $strongarm;

  return $export;
}
