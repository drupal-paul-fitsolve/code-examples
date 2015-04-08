<?php
/**
 * @file
 * sr_showcase_scroller.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sr_showcase_scroller_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
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
function sr_showcase_scroller_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function sr_showcase_scroller_image_default_styles() {
  $styles = array();

  // Exported image style: schools_showcase_scoller.
  $styles['schools_showcase_scoller'] = array(
    'name' => 'schools_showcase_scoller',
    'label' => 'schools_showcase_scoller',
    'effects' => array(
      18 => array(
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
          'height' => 150,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: showcase-scroller--fluid.
  $styles['showcase-scroller--fluid'] = array(
    'name' => 'showcase-scroller--fluid',
    'label' => 'showcase-scroller--fluid',
    'effects' => array(
      60 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 246,
          'height' => 246,
        ),
        'weight' => 1,
      ),
      67 => array(
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

  // Exported image style: showcase-scroller--narrow.
  $styles['showcase-scroller--narrow'] = array(
    'name' => 'showcase-scroller--narrow',
    'label' => 'showcase-scroller--narrow',
    'effects' => array(
      47 => array(
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
          'height' => 175,
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: showcase-scroller--normal.
  $styles['showcase-scroller--normal'] = array(
    'name' => 'showcase-scroller--normal',
    'label' => 'showcase-scroller--normal',
    'effects' => array(
      46 => array(
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
          'height' => 175,
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: showcase-scroller--wide.
  $styles['showcase-scroller--wide'] = array(
    'name' => 'showcase-scroller--wide',
    'label' => 'showcase-scroller--wide',
    'effects' => array(
      45 => array(
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
          'height' => 175,
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function sr_showcase_scroller_node_info() {
  $items = array(
    'fundraiser_showcase' => array(
      'name' => t('Fundraiser showcase'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
