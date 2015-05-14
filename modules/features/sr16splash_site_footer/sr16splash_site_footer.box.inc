<?php
/**
 * @file
 * sr16splash_site_footer.box.inc
 */

/**
 * Implements hook_default_box().
 */
function sr16splash_site_footer_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'footer_branding_box';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Footer branding box';
  $box->options = array(
    'body' => array(
      'value' => '<a title="Comic Relief" href="http://www.comicrelief.com/" rel="home" target="_blank"><span>Comic Relief</span></a>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['footer_branding_box'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'footer_copyright_box';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Footer copyright box';
  $box->options = array(
    'body' => array(
      'value' => '<p>&copy; Comic Relief 2015. Comic Relief, registered charity 326568 (England/Wales); SC039730 (Scotland)</p>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['footer_copyright_box'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'footer_social_links_box';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Footer social links box';
  $box->options = array(
    'body' => array(
      'value' => '<h4 class="type--white">Follow us...</h4>
<ul>
<li><a class="icon icon-facebook icon--large" href="https://www.facebook.com/officialrednoseday?ref=ts&fref=ts" title="Facebook" target="_blank"><span>Facebook</span></a></li>
<li><a class="icon icon-twitter icon--large" href="https://twitter.com/rednoseday" title="Twitter" target="_blank"><span>Twitter</span></a></li>
<li><a class="icon icon-youtube icon--large" href="https://www.youtube.com/user/rednoseday" title="Youtube" target="_blank"><span>Youtube</span></a></li>
<li><a class="icon icon-instagram icon--large" href="http://www.instagram.com/rednoseday" title="Instagram" target="_blank"><span>Instagram</span></a></li>
<li><a class="icon icon-google-plus icon--large" href="https://plus.google.com/+rednoseday/posts" title="Google Plus" target="_blank"><span>Google Plus</span></a></li>
</ul>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['footer_social_links_box'] = $box;

  return $export;
}
