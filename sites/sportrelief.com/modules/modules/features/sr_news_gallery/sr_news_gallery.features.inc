<?php
/**
 * @file
 * sr_news_gallery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sr_news_gallery_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
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
}

/**
 * Implements hook_views_api().
 */
function sr_news_gallery_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function sr_news_gallery_image_default_styles() {
  $styles = array();

  // Exported image style: tile_grid_6breakpoints_theme_cr_layout_fluid_1x.
  $styles['tile_grid_6breakpoints_theme_cr_layout_fluid_1x'] = array(
    'name' => 'tile_grid_6breakpoints_theme_cr_layout_fluid_1x',
    'label' => 'tile_grid_6breakpoints_theme_cr_layout_fluid_1x',
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
          'width' => 220,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 0,
      ),
      66 => array(
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

  // Exported image style: tile_grid_6breakpoints_theme_cr_layout_narrow_1x.
  $styles['tile_grid_6breakpoints_theme_cr_layout_narrow_1x'] = array(
    'name' => 'tile_grid_6breakpoints_theme_cr_layout_narrow_1x',
    'label' => 'tile_grid_6breakpoints_theme_cr_layout_narrow_1x',
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
          'width' => 220,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: tile_grid_6breakpoints_theme_cr_layout_normal_1x.
  $styles['tile_grid_6breakpoints_theme_cr_layout_normal_1x'] = array(
    'name' => 'tile_grid_6breakpoints_theme_cr_layout_normal_1x',
    'label' => 'tile_grid_6breakpoints_theme_cr_layout_normal_1x',
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
          'width' => 220,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 0,
      ),
      56 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 220,
          'height' => 130,
          'anchor' => 'center-top',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: tile_grid_6breakpoints_theme_cr_layout_wide_1x.
  $styles['tile_grid_6breakpoints_theme_cr_layout_wide_1x'] = array(
    'name' => 'tile_grid_6breakpoints_theme_cr_layout_wide_1x',
    'label' => 'tile_grid_6breakpoints_theme_cr_layout_wide_1x',
    'effects' => array(
      55 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 280,
          'height' => '',
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
          'width' => 280,
          'height' => 130,
          'anchor' => 'center-top',
        ),
        'weight' => -9,
      ),
    ),
  );

  return $styles;
}
