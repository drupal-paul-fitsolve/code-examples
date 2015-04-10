<?php
/**
 * @file
 * sr14_fundraiser_showcases.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sr14_fundraiser_showcases_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function sr14_fundraiser_showcases_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function sr14_fundraiser_showcases_image_default_styles() {
  $styles = array();

  // Exported image style: fr-showcase.
  $styles['fr-showcase'] = array(
    'name' => 'fr-showcase',
    'effects' => array(
      6 => array(
        'label' => 'Aspect switcher',
        'help' => 'Use different effects depending on whether the image is landscape of portrait shaped. This re-uses other preset definitions, and just chooses between them based on the rule.',
        'effect callback' => 'canvasactions_aspect_effect',
        'dimensions callback' => 'canvasactions_aspect_dimensions',
        'form callback' => 'canvasactions_aspect_form',
        'summary theme' => 'canvasactions_aspect_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_aspect',
        'data' => array(
          'portrait' => 'fr-showcase-square-or-portrait',
          'landscape' => 'fr-showcase-landscape',
          'ratio_adjustment' => 0.9,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'fr-showcase',
  );

  // Exported image style: fr-showcase-landscape.
  $styles['fr-showcase-landscape'] = array(
    'name' => 'fr-showcase-landscape',
    'effects' => array(
      10 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 622,
          'height' => 467,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'fr-showcase-landscape',
  );

  // Exported image style: fr-showcase-portrait.
  $styles['fr-showcase-portrait'] = array(
    'name' => 'fr-showcase-portrait',
    'effects' => array(
      11 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 462,
          'height' => 618,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'fr-showcase-portrait',
  );

  // Exported image style: fr-showcase-square.
  $styles['fr-showcase-square'] = array(
    'name' => 'fr-showcase-square',
    'effects' => array(
      7 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 462,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'fr-showcase-square',
  );

  // Exported image style: fr-showcase-square-or-portrait.
  $styles['fr-showcase-square-or-portrait'] = array(
    'name' => 'fr-showcase-square-or-portrait',
    'effects' => array(
      8 => array(
        'label' => 'Aspect switcher',
        'help' => 'Use different effects depending on whether the image is landscape of portrait shaped. This re-uses other preset definitions, and just chooses between them based on the rule.',
        'effect callback' => 'canvasactions_aspect_effect',
        'dimensions callback' => 'canvasactions_aspect_dimensions',
        'form callback' => 'canvasactions_aspect_form',
        'summary theme' => 'canvasactions_aspect_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_aspect',
        'data' => array(
          'portrait' => 'fr-showcase-portrait',
          'landscape' => 'fr-showcase-square',
          'ratio_adjustment' => 1.25,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'fr-showcase-square-or-portrait',
  );

  // Exported image style: fr-showcase-thumb.
  $styles['fr-showcase-thumb'] = array(
    'name' => 'fr-showcase-thumb',
    'effects' => array(
      5 => array(
        'label' => 'Aspect switcher',
        'help' => 'Use different effects depending on whether the image is landscape of portrait shaped. This re-uses other preset definitions, and just chooses between them based on the rule.',
        'effect callback' => 'canvasactions_aspect_effect',
        'dimensions callback' => 'canvasactions_aspect_dimensions',
        'form callback' => 'canvasactions_aspect_form',
        'summary theme' => 'canvasactions_aspect_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_aspect',
        'data' => array(
          'portrait' => 'fr-showcase-thumb-portrait',
          'landscape' => 'fr-showcase-thumb-landscape',
          'ratio_adjustment' => 1,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'fr-showcase-thumb',
  );

  // Exported image style: fr-showcase-thumb-landscape.
  $styles['fr-showcase-thumb-landscape'] = array(
    'name' => 'fr-showcase-thumb-landscape',
    'effects' => array(
      5 => array(
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
        'weight' => 1,
      ),
    ),
    'label' => 'fr-showcase-thumb-landscape',
  );

  // Exported image style: fr-showcase-thumb-portrait.
  $styles['fr-showcase-thumb-portrait'] = array(
    'name' => 'fr-showcase-thumb-portrait',
    'effects' => array(
      4 => array(
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
          'height' => 295,
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'fr-showcase-thumb-portrait',
  );

  // Exported image style: fr-showcase-thumb-video.
  $styles['fr-showcase-thumb-video'] = array(
    'name' => 'fr-showcase-thumb-video',
    'label' => 'fr-showcase-thumb-video',
    'effects' => array(
      70 => array(
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
          'height' => 158,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
