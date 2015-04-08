<?php
/**
 * @file
 * sr_media_wall.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sr_media_wall_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  list($module, $api) = func_get_args();
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function sr_media_wall_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function sr_media_wall_image_default_styles() {
  $styles = array();

  // Exported image style: media-wall-defaultbreakpoints_theme_cr_layout_narrow_1x.
  $styles['media-wall-defaultbreakpoints_theme_cr_layout_narrow_1x'] = array(
    'name' => 'media-wall-defaultbreakpoints_theme_cr_layout_narrow_1x',
    'effects' => array(
      37 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 160,
          'height' => 124,
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'media-wall-defaultbreakpoints_theme_cr_layout_narrow_1x',
  );

  // Exported image style: media-wall-defaultbreakpoints_theme_cr_layout_normal_1x.
  $styles['media-wall-defaultbreakpoints_theme_cr_layout_normal_1x'] = array(
    'name' => 'media-wall-defaultbreakpoints_theme_cr_layout_normal_1x',
    'effects' => array(
      36 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 220,
          'height' => 124,
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'media-wall-defaultbreakpoints_theme_cr_layout_normal_1x',
  );

  // Exported image style: media-wall-defaultbreakpoints_theme_cr_layout_wide_1x.
  $styles['media-wall-defaultbreakpoints_theme_cr_layout_wide_1x'] = array(
    'name' => 'media-wall-defaultbreakpoints_theme_cr_layout_wide_1x',
    'label' => 'media-wall-defaultbreakpoints_theme_cr_layout_wide_1x',
    'effects' => array(
      51 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 300,
          'height' => 225,
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
      52 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 280,
          'height' => 200,
          'anchor' => 'center-top',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: media-wall-promo-1breakpoints_theme_cr_layout_normal_1x.
  $styles['media-wall-promo-1breakpoints_theme_cr_layout_normal_1x'] = array(
    'name' => 'media-wall-promo-1breakpoints_theme_cr_layout_normal_1x',
    'effects' => array(
      23 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 300,
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'media-wall-promo-1breakpoints_theme_cr_layout_normal_1x',
  );

  // Exported image style: media-wall-promo-1breakpoints_theme_cr_layout_wide_1x.
  $styles['media-wall-promo-1breakpoints_theme_cr_layout_wide_1x'] = array(
    'name' => 'media-wall-promo-1breakpoints_theme_cr_layout_wide_1x',
    'label' => 'media-wall-promo-1breakpoints_theme_cr_layout_wide_1x',
    'effects' => array(
      49 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 600,
          'height' => 450,
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
      50 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 380,
          'height' => 300,
          'anchor' => 'center-top',
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: media-wall-promo-2breakpoints_theme_cr_layout_narrow_1x.
  $styles['media-wall-promo-2breakpoints_theme_cr_layout_narrow_1x'] = array(
    'name' => 'media-wall-promo-2breakpoints_theme_cr_layout_narrow_1x',
    'effects' => array(
      31 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 350,
          'height' => 300,
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'media-wall-promo-2breakpoints_theme_cr_layout_narrow_1x',
  );

  // Exported image style: media-wall-promo-2breakpoints_theme_cr_layout_normal_1x.
  $styles['media-wall-promo-2breakpoints_theme_cr_layout_normal_1x'] = array(
    'name' => 'media-wall-promo-2breakpoints_theme_cr_layout_normal_1x',
    'effects' => array(
      30 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 220,
          'height' => 300,
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'media-wall-promo-2breakpoints_theme_cr_layout_normal_1x',
  );

  // Exported image style: media-wall-promo-2breakpoints_theme_cr_layout_wide_1x.
  $styles['media-wall-promo-2breakpoints_theme_cr_layout_wide_1x'] = array(
    'name' => 'media-wall-promo-2breakpoints_theme_cr_layout_wide_1x',
    'effects' => array(
      29 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 280,
          'height' => 300,
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'media-wall-promo-2breakpoints_theme_cr_layout_wide_1x',
  );

  // Exported image style: media-wall-promo-breakpoints_theme_cr_layout_narrow_1x.
  $styles['media-wall-promo-breakpoints_theme_cr_layout_narrow_1x'] = array(
    'name' => 'media-wall-promo-breakpoints_theme_cr_layout_narrow_1x',
    'effects' => array(
      25 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 250,
          'height' => 320,
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'media-wall-promo-breakpoints_theme_cr_layout_narrow_1x',
  );

  // Exported image style: media_wall_breakpoints_theme_cr_layout_fluid_1x.
  $styles['media_wall_breakpoints_theme_cr_layout_fluid_1x'] = array(
    'name' => 'media_wall_breakpoints_theme_cr_layout_fluid_1x',
    'label' => 'media_wall_breakpoints_theme_cr_layout_fluid_1x',
    'effects' => array(
      73 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 740,
          'height' => 1000,
          'upscale' => 0,
        ),
        'weight' => -10,
      ),
      74 => array(
        'label' => 'Define canvas',
        'help' => 'Define the size of the working canvas and background color, this controls the dimensions of the output image.',
        'effect callback' => 'canvasactions_definecanvas_effect',
        'dimensions callback' => 'canvasactions_definecanvas_dimensions',
        'form callback' => 'canvasactions_definecanvas_form',
        'summary theme' => 'canvasactions_definecanvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '#1d1d1d',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 739,
            'height' => 420,
            'xpos' => 'center',
            'ypos' => 'top',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => -9,
      ),
      77 => array(
        'label' => 'Quality',
        'help' => 'Define the image quality for JPEG manipulations. Ranges from 0 to 100. Higher values mean better image quality but bigger files.',
        'effect callback' => '_image_style_quality_apply',
        'form callback' => 'image_style_quality_style_form',
        'dimensions passthrough' => TRUE,
        'summary theme' => 'image_style_quality_summary',
        'module' => 'image_style_quality',
        'name' => 'image_style_quality',
        'data' => array(
          'quality' => 30,
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: media_wall_touch_breakpoints_theme_cr_layout_fluid_1_5x.
  $styles['media_wall_touch_breakpoints_theme_cr_layout_fluid_1_5x'] = array(
    'name' => 'media_wall_touch_breakpoints_theme_cr_layout_fluid_1_5x',
    'label' => 'media_wall_touch_breakpoints_theme_cr_layout_fluid_1_5x',
    'effects' => array(
      72 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 340,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 0,
      ),
      76 => array(
        'label' => 'Quality',
        'help' => 'Define the image quality for JPEG manipulations. Ranges from 0 to 100. Higher values mean better image quality but bigger files.',
        'effect callback' => '_image_style_quality_apply',
        'form callback' => 'image_style_quality_style_form',
        'dimensions passthrough' => TRUE,
        'summary theme' => 'image_style_quality_summary',
        'module' => 'image_style_quality',
        'name' => 'image_style_quality',
        'data' => array(
          'quality' => 30,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: media_wall_touch_breakpoints_theme_cr_layout_fluid_1x.
  $styles['media_wall_touch_breakpoints_theme_cr_layout_fluid_1x'] = array(
    'name' => 'media_wall_touch_breakpoints_theme_cr_layout_fluid_1x',
    'label' => 'media_wall_touch_breakpoints_theme_cr_layout_fluid_1x',
    'effects' => array(
      71 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 340,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 0,
      ),
      75 => array(
        'label' => 'Quality',
        'help' => 'Define the image quality for JPEG manipulations. Ranges from 0 to 100. Higher values mean better image quality but bigger files.',
        'effect callback' => '_image_style_quality_apply',
        'form callback' => 'image_style_quality_style_form',
        'dimensions passthrough' => TRUE,
        'summary theme' => 'image_style_quality_summary',
        'module' => 'image_style_quality',
        'name' => 'image_style_quality',
        'data' => array(
          'quality' => 30,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: media_wall_touch_breakpoints_theme_cr_layout_narrow_1_5x.
  $styles['media_wall_touch_breakpoints_theme_cr_layout_narrow_1_5x'] = array(
    'name' => 'media_wall_touch_breakpoints_theme_cr_layout_narrow_1_5x',
    'label' => 'media_wall_touch_breakpoints_theme_cr_layout_narrow_1_5x',
    'effects' => array(
      32 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 340,
          'height' => 300,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: media_wall_touch_breakpoints_theme_cr_layout_narrow_1x.
  $styles['media_wall_touch_breakpoints_theme_cr_layout_narrow_1x'] = array(
    'name' => 'media_wall_touch_breakpoints_theme_cr_layout_narrow_1x',
    'label' => 'media_wall_touch_breakpoints_theme_cr_layout_narrow_1x',
    'effects' => array(
      53 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 400,
          'height' => 300,
          'upscale' => 1,
        ),
        'weight' => -10,
      ),
      54 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 340,
          'height' => 300,
          'anchor' => 'center-top',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: media_wall_touch_breakpoints_theme_cr_layout_normal_1x.
  $styles['media_wall_touch_breakpoints_theme_cr_layout_normal_1x'] = array(
    'name' => 'media_wall_touch_breakpoints_theme_cr_layout_normal_1x',
    'label' => 'media_wall_touch_breakpoints_theme_cr_layout_normal_1x',
    'effects' => array(
      48 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 740,
          'height' => 416,
          'upscale' => 1,
        ),
        'weight' => -10,
      ),
      49 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 460,
          'height' => 300,
          'anchor' => 'center-top',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: media_wall_touch_breakpoints_theme_cr_layout_normal_2x.
  $styles['media_wall_touch_breakpoints_theme_cr_layout_normal_2x'] = array(
    'name' => 'media_wall_touch_breakpoints_theme_cr_layout_normal_2x',
    'label' => 'media_wall_touch_breakpoints_theme_cr_layout_normal_2x',
    'effects' => array(
      50 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 740,
          'height' => 416,
          'upscale' => 1,
        ),
        'weight' => -10,
      ),
      51 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 460,
          'height' => 300,
          'anchor' => 'center-top',
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}
