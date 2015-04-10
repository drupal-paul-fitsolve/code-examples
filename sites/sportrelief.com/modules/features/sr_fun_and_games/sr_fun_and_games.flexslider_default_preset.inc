<?php
/**
 * @file
 * sr_fun_and_games.flexslider_default_preset.inc
 */

/**
 * Implements hook_flexslider_default_presets().
 */
function sr_fun_and_games_flexslider_default_presets() {
  $export = array();

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->name = 'fun_and_games_pledge_one';
  $preset->title = 'Fun and games pledge one';
  $preset->theme = 'classic';
  $preset->imagestyle_normal = 'flexslider_full';
  $preset->imagestyle_thumbnail = 'flexslider_thumbnail';
  $preset->options = array(
    'namespace' => 'flex-',
    'selector' => '.slides > li',
    'easing' => 'swing',
    'direction' => 'vertical',
    'reverse' => 1,
    'smoothHeight' => 0,
    'startAt' => '0',
    'animationSpeed' => '300',
    'initDelay' => '0',
    'useCSS' => 1,
    'touch' => 1,
    'video' => 0,
    'keyboard' => 0,
    'multipleKeyboard' => 0,
    'mousewheel' => 0,
    'controlsContainer' => '.flex-control-nav-container',
    'sync' => '',
    'asNavFor' => '',
    'itemWidth' => '0',
    'itemMargin' => '0',
    'minItems' => '0',
    'maxItems' => '0',
    'move' => '0',
    'animation' => 'slide',
    'slideshow' => 1,
    'slideshowSpeed' => '3000',
    'directionNav' => 0,
    'controlNav' => '0',
    'prevText' => 'Previous',
    'nextText' => 'Next',
    'pausePlay' => 0,
    'pauseText' => 'Pause',
    'playText' => 'Play',
    'randomize' => 1,
    'animationLoop' => 1,
    'pauseOnAction' => 0,
    'pauseOnHover' => 1,
    'manualControls' => '',
    'disableMobile' => 0,
  );
  $preset->imagestyle_type = 'picture_mapping';
  $preset->mapping = 'grid_13_promo';
  $export['fun_and_games_pledge_one'] = $preset;

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->name = 'fun_and_games_pledge_three';
  $preset->title = 'Fun and games pledge three';
  $preset->theme = 'classic';
  $preset->imagestyle_normal = 'flexslider_full';
  $preset->imagestyle_thumbnail = 'flexslider_thumbnail';
  $preset->options = array(
    'namespace' => 'flex-',
    'selector' => '.slides > li',
    'easing' => 'swing',
    'direction' => 'vertical',
    'reverse' => 1,
    'smoothHeight' => 0,
    'startAt' => '0',
    'animationSpeed' => '300',
    'initDelay' => '1000',
    'useCSS' => 1,
    'touch' => 1,
    'video' => 0,
    'keyboard' => 0,
    'multipleKeyboard' => 0,
    'mousewheel' => 0,
    'controlsContainer' => '.flex-control-nav-container',
    'sync' => '',
    'asNavFor' => '',
    'itemWidth' => '0',
    'itemMargin' => '0',
    'minItems' => '0',
    'maxItems' => '0',
    'move' => '0',
    'animation' => 'slide',
    'slideshow' => 1,
    'slideshowSpeed' => '3000',
    'directionNav' => 0,
    'controlNav' => '0',
    'prevText' => 'Previous',
    'nextText' => 'Next',
    'pausePlay' => 0,
    'pauseText' => 'Pause',
    'playText' => 'Play',
    'randomize' => 0,
    'animationLoop' => 1,
    'pauseOnAction' => 0,
    'pauseOnHover' => 1,
    'manualControls' => '',
    'disableMobile' => 0,
  );
  $preset->imagestyle_type = 'picture_mapping';
  $preset->mapping = 'grid_13_promo';
  $export['fun_and_games_pledge_three'] = $preset;

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->name = 'two';
  $preset->title = 'Fun and games pledge two';
  $preset->theme = 'classic';
  $preset->imagestyle_normal = 'flexslider_full';
  $preset->imagestyle_thumbnail = 'flexslider_thumbnail';
  $preset->options = array(
    'namespace' => 'flex-',
    'selector' => '.slides > li',
    'easing' => 'swing',
    'direction' => 'vertical',
    'reverse' => 1,
    'smoothHeight' => 0,
    'startAt' => '0',
    'animationSpeed' => '300',
    'initDelay' => '2000',
    'useCSS' => 1,
    'touch' => 1,
    'video' => 0,
    'keyboard' => 0,
    'multipleKeyboard' => 0,
    'mousewheel' => 0,
    'controlsContainer' => '.flex-control-nav-container',
    'sync' => '',
    'asNavFor' => '',
    'itemWidth' => '0',
    'itemMargin' => '0',
    'minItems' => '0',
    'maxItems' => '0',
    'move' => '0',
    'animation' => 'slide',
    'slideshow' => 1,
    'slideshowSpeed' => '3000',
    'directionNav' => 0,
    'controlNav' => '0',
    'prevText' => 'Previous',
    'nextText' => 'Next',
    'pausePlay' => 0,
    'pauseText' => 'Pause',
    'playText' => 'Play',
    'randomize' => 0,
    'animationLoop' => 1,
    'pauseOnAction' => 0,
    'pauseOnHover' => 1,
    'manualControls' => '',
    'disableMobile' => 0,
  );
  $preset->imagestyle_type = 'picture_mapping';
  $preset->mapping = 'grid_13_promo';
  $export['two'] = $preset;

  return $export;
}
