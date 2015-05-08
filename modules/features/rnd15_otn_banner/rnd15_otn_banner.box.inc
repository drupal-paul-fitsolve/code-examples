<?php
/**
 * @file
 * rnd15_otn_banner.box.inc
 */

/**
 * Implements hook_default_box().
 */
function rnd15_otn_banner_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'otn';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'OTN Banner: on the night';
  $box->options = array(
    'body' => array(
      'value' => '
        <div class="container otn-banner otn-banner__otn">
          <div class="row">
            <div class="otn-banner__img col-sm-2 col-lg-offset-1 hidden-xs">
            </div>
            <div class="otn-banner__copy col-xs-12 col-sm-7 col-md-8 col-lg-6">
              <p class="type--xl type--centred type--black">Donate now and <strong>transform lives</strong> in the UK and across Africa</p>
            </div>
            <div class="otn-banner__cta col-xs-12 col-sm-3 col-md-2">
              <p class="type--centred"><a href="https://secure.donate.comicrelief.com" id="otn-banner-one-btn-donate" class="btn btn-red" title="Donate now and transform lives">Donate now</a></p>
            </div>
          </div>
        </div>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['otn'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'otn_after';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'OTN Banner: after';
  $box->options = array(
    'body' => array(
      'value' => '
        <div class="container otn-banner otn-banner__after">
          <div class="row">
            <div class="otn-banner__img col-sm-2 col-lg-offset-1 hidden-xs">
            </div>
            <div class="otn-banner__copy col-xs-12 col-sm-4 col-md-5 col-lg-5">
              <p class="type--xl type--centred type--black"><strong>Donate now</strong> and transform lives in the UK and across Africa</p>
            </div>
            <div class="otn-banner__cta col-xs-12 col-sm-6 col-md-5 col-lg-4">
              <p class="type--centred"><a href="https://secure.donate.comicrelief.com" id="otn-banner-two-btn-donate" class="btn btn-red" title="Donate now and transform lives">Donate now</a><a href="/fundraise/how-to-pay-in-your-fundraising" id="otn-banner-two-btn-pay-in" class="btn btn-red" title="Pay in now">Pay in now</a></p>
            </div>
          </div>
        </div>',
      'format' => 'full_html',
    ),
  );
  $export['otn_after'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'otn_monday';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'OTN Banner: monday';
  $box->options = array(
    'body' => array(
      'value' => '
        <div class="container otn-banner otn-banner__monday">
          <div class="row">
            <div class="otn-banner__img col-sm-2 col-lg-offset-1 hidden-xs">
            </div>
            <div class="otn-banner__copy col-xs-12 col-sm-7 col-md-8 col-lg-6">
              <p class="type--xl type--centred type--black"><strong>Raise money?</strong> Pay in now to start changing lives</p>
            </div>
            <div class="otn-banner__cta col-xs-12 col-sm-3 col-md-2">
              <p class="type--centred"><a href="/fundraise/how-to-pay-in-your-fundraising" id="otn-banner-three-btn-pay-in" class="btn btn-red" title="Pay in now">Pay in now</a></p>
            </div>
          </div>
        </div>',
      'format' => 'full_html',
    ),
  );
  $export['otn_monday'] = $box;

  return $export;
}
