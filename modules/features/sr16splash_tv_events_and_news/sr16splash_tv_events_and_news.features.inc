<?php
/**
 * @file
 * sr16splash_tv_events_and_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sr16splash_tv_events_and_news_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "breakpoints" && $api == "default_breakpoints") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function sr16splash_tv_events_and_news_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function sr16splash_tv_events_and_news_image_default_styles() {
  $styles = array();

  // Exported image style: media_image_lg.
  $styles['media_image_lg'] = array(
    'name' => 'media_image_lg',
    'label' => 'media_image_lg',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 277,
          'upscale' => 1,
        ),
        'weight' => -10,
      ),
      2 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 370,
          'height' => 277,
          'anchor' => 'center-top',
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: media_image_lg_2x.
  $styles['media_image_lg_2x'] = array(
    'name' => 'media_image_lg_2x',
    'label' => 'media_image_lg_2x',
    'effects' => array(
      3 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 555,
          'upscale' => 1,
        ),
        'weight' => -10,
      ),
      4 => array(
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
          'height' => 555,
          'anchor' => 'center-top',
        ),
        'weight' => -9,
      ),
      5 => array(
        'label' => 'Quality',
        'help' => 'Define the image quality for JPEG manipulations. Ranges from 0 to 100. Higher values mean better image quality but bigger files.',
        'effect callback' => '_image_style_quality_apply',
        'form callback' => 'image_style_quality_style_form',
        'dimensions passthrough' => TRUE,
        'summary theme' => 'image_style_quality_summary',
        'module' => 'image_style_quality',
        'name' => 'image_style_quality',
        'data' => array(
          'quality' => 40,
        ),
        'weight' => -8,
      ),
    ),
  );

  // Exported image style: media_image_md.
  $styles['media_image_md'] = array(
    'name' => 'media_image_md',
    'label' => 'media_image_md',
    'effects' => array(
      21 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 217,
          'upscale' => 1,
        ),
        'weight' => 2,
      ),
      22 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 290,
          'height' => 217,
          'anchor' => 'center-top',
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: media_image_md_2x.
  $styles['media_image_md_2x'] = array(
    'name' => 'media_image_md_2x',
    'label' => 'media_image_md_2x',
    'effects' => array(
      8 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 435,
          'upscale' => 1,
        ),
        'weight' => -10,
      ),
      9 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 580,
          'height' => 435,
          'anchor' => 'center-top',
        ),
        'weight' => -9,
      ),
      10 => array(
        'label' => 'Quality',
        'help' => 'Define the image quality for JPEG manipulations. Ranges from 0 to 100. Higher values mean better image quality but bigger files.',
        'effect callback' => '_image_style_quality_apply',
        'form callback' => 'image_style_quality_style_form',
        'dimensions passthrough' => TRUE,
        'summary theme' => 'image_style_quality_summary',
        'module' => 'image_style_quality',
        'name' => 'image_style_quality',
        'data' => array(
          'quality' => 40,
        ),
        'weight' => -7,
      ),
    ),
  );

  // Exported image style: media_image_sm.
  $styles['media_image_sm'] = array(
    'name' => 'media_image_sm',
    'label' => 'media_image_sm',
    'effects' => array(
      11 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 247,
          'upscale' => 1,
        ),
        'weight' => 2,
      ),
      12 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 330,
          'height' => 247,
          'anchor' => 'center-top',
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: media_image_sm_2x.
  $styles['media_image_sm_2x'] = array(
    'name' => 'media_image_sm_2x',
    'label' => 'media_image_sm_2x',
    'effects' => array(
      13 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 495,
          'upscale' => 1,
        ),
        'weight' => -10,
      ),
      14 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 660,
          'height' => 495,
          'anchor' => 'center-top',
        ),
        'weight' => -9,
      ),
      15 => array(
        'label' => 'Quality',
        'help' => 'Define the image quality for JPEG manipulations. Ranges from 0 to 100. Higher values mean better image quality but bigger files.',
        'effect callback' => '_image_style_quality_apply',
        'form callback' => 'image_style_quality_style_form',
        'dimensions passthrough' => TRUE,
        'summary theme' => 'image_style_quality_summary',
        'module' => 'image_style_quality',
        'name' => 'image_style_quality',
        'data' => array(
          'quality' => 40,
        ),
        'weight' => -8,
      ),
    ),
  );

  // Exported image style: media_image_xs.
  $styles['media_image_xs'] = array(
    'name' => 'media_image_xs',
    'label' => 'media_image_xs',
    'effects' => array(
      25 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 553,
          'upscale' => 1,
        ),
        'weight' => 2,
      ),
      26 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 738,
          'height' => 553,
          'anchor' => 'center-top',
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: media_image_xs_2x.
  $styles['media_image_xs_2x'] = array(
    'name' => 'media_image_xs_2x',
    'label' => 'media_image_xs_2x',
    'effects' => array(
      17 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 1107,
          'upscale' => 1,
        ),
        'weight' => -10,
      ),
      18 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 1476,
          'height' => 1107,
          'anchor' => 'center-top',
        ),
        'weight' => -9,
      ),
      12 => array(
        'label' => 'Quality',
        'help' => 'Define the image quality for JPEG manipulations. Ranges from 0 to 100. Higher values mean better image quality but bigger files.',
        'effect callback' => '_image_style_quality_apply',
        'form callback' => 'image_style_quality_style_form',
        'dimensions passthrough' => TRUE,
        'summary theme' => 'image_style_quality_summary',
        'module' => 'image_style_quality',
        'name' => 'image_style_quality',
        'data' => array(
          'quality' => 40,
        ),
        'weight' => -7,
      ),
    ),
  );

  return $styles;
}
