<?php
/**
 * @file
 * cr_video.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function cr_video_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|video|colorbox';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'video';
  $ds_fieldsetting->view_mode = 'colorbox';
  $ds_fieldsetting->settings = array(
    'social_share_links' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'pod--article__sharelinks sharelinks--colorbox',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h4',
        'class' => '',
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|video|colorbox'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|video|colorbox_no_social';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'video';
  $ds_fieldsetting->view_mode = 'colorbox_no_social';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h4',
        'class' => '',
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|video|colorbox_no_social'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|video|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'video';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'service_links_displays_group' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'sld_group_text',
    ),
  );
  $export['node|video|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|video|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'video';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'social_share_links' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'pod--article__sharelinks',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'facebook_comments' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'pod--article__comments',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
        ),
      ),
    ),
    'field_publish_date' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'text--lead',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|video|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|video|full_content_no_social';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'video';
  $ds_fieldsetting->view_mode = 'full_content_no_social';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
        ),
      ),
    ),
    'field_publish_date' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'text--lead',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|video|full_content_no_social'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|video|media_bar';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'video';
  $ds_fieldsetting->view_mode = 'media_bar';
  $ds_fieldsetting->settings = array(
    'colorbox_node_link' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'media_bar_image_icon' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'media_bar_watch_now' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'video_youtube' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'media-bar__tweet__text',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|video|media_bar'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|video|media_bar_no_social';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'video';
  $ds_fieldsetting->view_mode = 'media_bar_no_social';
  $ds_fieldsetting->settings = array(
    'colorbox_node_link' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'media_bar_image_icon' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'media_bar_watch_now' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'video_youtube' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'media-bar__tweet__text',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|video|media_bar_no_social'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function cr_video_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'media_bar_watch_now';
  $ds_field->label = 'Media Bar Watch Now';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'news_article|media_bar
video|media_bar';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<p class="media-bar__readmore cta">watch now</p>',
      'format' => 'full_html',
    ),
    'use_token' => 1,
  );
  $export['media_bar_watch_now'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'video_youtube';
  $ds_field->label = 'Video Image Youtube';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php //dsm($entity); dsm(field_get_items(\'node\', $entity, \'field_video_url\')); ?> 
<?php
$url = field_get_items(\'node\', $entity, \'field_video_url\');

if(isset($url[0][\'url\'])){
  $pos = (strpos($url[0][\'url\'],\'?\')+3);
  $id = substr($url[0][\'url\'],$pos);
  $image_path = "http://img.youtube.com/vi/{$id}/default.jpg";
}

if(isset($image_path)){
  $variables = array(
     \'path\' => $image_path, 
     \'alt\' => check_plain($entity->title),
     \'title\' => check_plain($entity->title),
     \'attributes\' => array(\'class\' => \'class_1\',),
   );
  $img = theme(\'image\', $variables);
  print $img;
}

?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['video_youtube'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function cr_video_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|video|colorbox';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'colorbox';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_video_url',
        1 => 'field_mediaelement_video',
      ),
      'right' => array(
        2 => 'title',
        3 => 'body',
        4 => 'social_share_links',
      ),
    ),
    'fields' => array(
      'field_video_url' => 'left',
      'field_mediaelement_video' => 'left',
      'title' => 'right',
      'body' => 'right',
      'social_share_links' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|video|colorbox'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|video|colorbox_no_social';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'colorbox_no_social';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_video_url',
        1 => 'field_mediaelement_video',
      ),
      'right' => array(
        2 => 'title',
        3 => 'body',
      ),
    ),
    'fields' => array(
      'field_video_url' => 'left',
      'field_mediaelement_video' => 'left',
      'title' => 'right',
      'body' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        'container-24' => 'container-24',
        'colorbox-container' => 'colorbox-container',
      ),
      'left' => array(
        'colorbox--top' => 'colorbox--top',
        'alpha' => 'alpha',
        'omega' => 'omega',
        'grid-16' => 'grid-16',
      ),
      'right' => array(
        'colorbox--bottom' => 'colorbox--bottom',
        'alpha' => 'alpha',
        'omega' => 'omega',
        'grid-16' => 'grid-16',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|video|colorbox_no_social'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|video|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'field_video_url',
        2 => 'field_mediaelement_video',
        3 => 'body',
      ),
      'right' => array(
        4 => 'service_links_displays_group',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_video_url' => 'left',
      'field_mediaelement_video' => 'left',
      'body' => 'left',
      'service_links_displays_group' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|video|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|video|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'field_publish_date',
        2 => 'field_video_url',
        3 => 'field_mediaelement_video',
        4 => 'body',
      ),
      'right' => array(
        5 => 'social_share_links',
        6 => 'facebook_comments',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_publish_date' => 'left',
      'field_video_url' => 'left',
      'field_mediaelement_video' => 'left',
      'body' => 'left',
      'social_share_links' => 'right',
      'facebook_comments' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|video|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|video|full_content_no_social';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'full_content_no_social';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'field_publish_date',
        2 => 'field_video_url',
        3 => 'field_mediaelement_video',
        4 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_publish_date' => 'left',
      'field_video_url' => 'left',
      'field_mediaelement_video' => 'left',
      'body' => 'left',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|video|full_content_no_social'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|video|media_bar';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'media_bar';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'right' => array(
        0 => 'media_bar_image_icon',
        4 => 'video_youtube',
      ),
      'header' => array(
        1 => 'colorbox_node_link',
      ),
      'left' => array(
        2 => 'title_field',
        3 => 'media_bar_watch_now',
      ),
    ),
    'fields' => array(
      'media_bar_image_icon' => 'right',
      'colorbox_node_link' => 'header',
      'title_field' => 'left',
      'media_bar_watch_now' => 'left',
      'video_youtube' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|video|media_bar'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function cr_video_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'colorbox_no_social';
  $ds_view_mode->label = 'Colorbox No social';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['colorbox_no_social'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'full_content_no_social';
  $ds_view_mode->label = 'Full content no social';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['full_content_no_social'] = $ds_view_mode;

  return $export;
}
