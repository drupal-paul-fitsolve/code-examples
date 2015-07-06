
PB: 26/6/14
-----------

You can use the function below to programmatically assign image
effects to the required image presets.

Putting this in a seperate README so it doesn't get overidden by
feature downloads.

Process:
--------

1: Alter the column widths etc in the $presets array to what you need.

2: Replace the entire crl2_images_image_default_styles() funtion in
   crl2_images.features.inc with the function below.

3: Visit admin/structure/features/crl2_images/recreate in your browser
   to rebuild the image styles.

4: Check everything looks good in the image style settings in the CMS.

5: Download the crl2_images feature to overwrite.


Function:
---------

/**
 * Implements hook_image_default_styles().
 */
function crl2_images_image_default_styles() {
  $styles = array();

  $presets = array(
    'xs' => array(
      'breakpoint' => 'xs',
      'column_width' => 738,
      'column_width_increase' => 0,
    ),
    'sm' => array(
      'breakpoint' => 'sm',
      'column_width' => 30,
      'column_width_increase' => 60,
    ),
    'md' => array(
      'breakpoint' => 'md',
      'column_width' => 50,
      'column_width_increase' => 80,
    ),
    'lg' => array(
      'breakpoint' => 'lg',
      'column_width' => 70,
      'column_width_increase' => 100,
    ),
  );

  foreach ($presets as $preset) {
    
    for ($i = 1; $i <= 12 ; $i++) { 
      
      if ($i > 1) { // Only increase the column width if not the first column
        $preset['column_width'] = $preset['column_width'] + $preset['column_width_increase'];
      }

      $styles['col_' . $i . '_' . $preset['breakpoint']] = array(
        'name' => 'col_' . $i . '_' . $preset['breakpoint'],
        'label' => 'col_' . $i . '_' . $preset['breakpoint'],
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
              'width' => $preset['column_width'],
              'height' => '',
              'upscale' => 0,
            ),
            'weight' => 1,
          ),
        ),
      );

      // Exported image style: col_1_xs_2x.
      $styles['col_' . $i . '_' . $preset['breakpoint'] . '_2x'] = array(
        'name' => 'col_' . $i . '_' . $preset['breakpoint'] . '_2x',
        'label' => 'col_' . $i . '_' . $preset['breakpoint'] . '_2x',
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
              'width' => $preset['column_width'] * 2,
              'height' => '',
              'upscale' => 0,
            ),
            'weight' => 1,
          ),
          4 => array(
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
            'weight' => 2,
          ),
        ),
      );
    }

  }

  return $styles;
}