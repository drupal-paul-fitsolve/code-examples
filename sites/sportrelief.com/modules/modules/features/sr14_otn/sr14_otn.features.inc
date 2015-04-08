<?php
/**
 * @file
 * sr14_otn.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sr14_otn_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "delta" && $api == "delta") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function sr14_otn_image_default_styles() {
  $styles = array();

  // Exported image style: otnbreakpoints_theme_cr_layout_narrow_1x.
  $styles['otnbreakpoints_theme_cr_layout_narrow_1x'] = array(
    'name' => 'otnbreakpoints_theme_cr_layout_narrow_1x',
    'label' => 'otnbreakpoints_theme_cr_layout_narrow_1x',
    'effects' => array(
      59 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 800,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => -10,
      ),
      58 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 740,
          'height' => 495,
          'anchor' => 'center-top',
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: otnbreakpoints_theme_cr_layout_narrow_2x.
  $styles['otnbreakpoints_theme_cr_layout_narrow_2x'] = array(
    'name' => 'otnbreakpoints_theme_cr_layout_narrow_2x',
    'label' => 'otnbreakpoints_theme_cr_layout_narrow_2x',
    'effects' => array(
      62 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 1600,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => -9,
      ),
      61 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 1480,
          'height' => 990,
          'anchor' => 'center-top',
        ),
        'weight' => -8,
      ),
    ),
  );

  // Exported image style: otnbreakpoints_theme_cr_layout_normal_1x.
  $styles['otnbreakpoints_theme_cr_layout_normal_1x'] = array(
    'name' => 'otnbreakpoints_theme_cr_layout_normal_1x',
    'label' => 'otnbreakpoints_theme_cr_layout_normal_1x',
    'effects' => array(
      77 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 630,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => -10,
      ),
      76 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 620,
          'height' => 428,
          'anchor' => 'center-top',
        ),
        'weight' => -8,
      ),
      78 => array(
        'label' => 'Overlay (watermark)',
        'help' => 'Choose the file image you wish to use as an overlay, and position it in a layer on top of the canvas.',
        'effect callback' => 'canvasactions_file2canvas_effect',
        'dimensions passthrough' => TRUE,
        'form callback' => 'canvasactions_file2canvas_form',
        'summary theme' => 'canvasactions_file2canvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 0,
          'ypos' => 0,
          'alpha' => 100,
          'path' => 'sites/sportrelief.com/themes/sport_relief_2014/images/gradient-normal.png',
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: otnbreakpoints_theme_cr_layout_wide_1x.
  $styles['otnbreakpoints_theme_cr_layout_wide_1x'] = array(
    'name' => 'otnbreakpoints_theme_cr_layout_wide_1x',
    'label' => 'otnbreakpoints_theme_cr_layout_wide_1x',
    'effects' => array(
      74 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 790,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => -10,
      ),
      72 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 780,
          'height' => 428,
          'anchor' => 'center-top',
        ),
        'weight' => -8,
      ),
      73 => array(
        'label' => 'Overlay (watermark)',
        'help' => 'Choose the file image you wish to use as an overlay, and position it in a layer on top of the canvas.',
        'effect callback' => 'canvasactions_file2canvas_effect',
        'dimensions passthrough' => TRUE,
        'form callback' => 'canvasactions_file2canvas_form',
        'summary theme' => 'canvasactions_file2canvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 'center',
          'ypos' => 'top',
          'alpha' => 100,
          'path' => 'sites/sportrelief.com/themes/sport_relief_2014/images/gradient-wide.png',
        ),
        'weight' => -7,
      ),
    ),
  );

  return $styles;
}
