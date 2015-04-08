<?php
/**
 * @file
 * sr_media_bar.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function sr_media_bar_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|tweet|media_bar';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'tweet';
  $ds_fieldsetting->view_mode = 'media_bar';
  $ds_fieldsetting->settings = array(
    'image_data_attribute' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'tweet_action_links' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'media-bar__item__sidebar',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'p',
          'ow-cl' => 'media-bar__tweet__text',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_tweet_date' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'media-bar__tweet__date',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_tweet_user_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|tweet|media_bar'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function sr_media_bar_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'colorbox_node_link';
  $ds_field->label = 'Colorbox Node Link';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'news_article|media_bar
video|media_bar
video|video_start_frame_only
video|video_start_frame_only_large
media_images|media_bar
video|media_wall
video|media_wall_promo_2
video|media_wall_promo_3
video|media_wall_touch_device
media_images|media_wall_instagram
media_images|media_bar
media_images|media_wall
media_images|media_wall_promo_3
media_images|media_wall_promo_2
video|tile_grid_6
media_images|tile_grid_6';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<a class="node-link colorbox-node" href="[node:url]?width=100&height=100" title="View"><span class="text">[node:title]</span><span class="node-link-icon"></span><span class="node-link-background"></span></a>',
      'format' => 'full_html',
    ),
    'use_token' => 1,
  );
  $export['colorbox_node_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'image_data_attribute';
  $ds_field->label = 'Image HTML5 data attribute';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'tweet|media_bar';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
if(!empty($entity->field_tweet_image)){
  $images = $entity->field_tweet_image[$entity->language];
  //Output image(s) as data attribute a
  if(is_array($images) && count($images) > 0){
    foreach($images as $image){
   
      $variables = array(
        \'style_name\' => \'grid-4-normal\',
        \'width\' => $image[\'width\'],
        \'height\' =>$image[\'height\'],
        \'alt\' =>$image[\'alt\'],
        \'path\' => $image[\'uri\']
      );

      $dimensions = array(
        \'width\' => $image[\'width\'],
        \'height\' =>$image[\'height\'],
      );

      // Process 
      $image_path = image_style_url($variables[\'style_name\'],  $image[\'uri\']);
      image_style_transform_dimensions($variables[\'style_name\'], $dimensions);
      $options = array(
        \'data-image-width\' =>  $dimensions[\'width\'],
        \'data-image-height\' => $dimensions[\'height\'],
       \'data-image-alt\' => $variables[\'alt\'],
      );

     print \'<span class="sr-media-bar-image" data-image-src="\' . $image_path . \'" \' . drupal_attributes($options) .\'></span>\';
     }
  }

}
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['image_data_attribute'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'media_bar_read_more';
  $ds_field->label = 'Media Bar Read More';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'news_article|media_bar
video|media_bar';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<p class="media-bar__readmore cta">read more</p>',
      'format' => 'full_html',
    ),
    'use_token' => 0,
  );
  $export['media_bar_read_more'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'node_link_field';
  $ds_field->label = 'Node Link';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'news_article|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<a class="node-link" href="[node:url]" title="View full article."><span class="text">[node:title]</span><span class="node-link-icon"></span><span class="node-link-background"></span></a>',
      'format' => 'full_html',
    ),
    'use_token' => 1,
  );
  $export['node_link_field'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'tweet_action_links';
  $ds_field->label = 'Tweet Action Links';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'tweet|media_bar';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<ul class="tweet-action-links">
<li><a href="https://twitter.com/intent/tweet?in_reply_to=[node:field_tweet_id]" class="tweet-action-links__tweet"><span class="text">Tweet</span></a></li>
<li><a href="https://twitter.com/intent/retweet?tweet_id=[node:field_tweet_id]" class="tweet-action-links__retweet"><span class="text">Retweet</span></a></li>
<li><a href="https://twitter.com/intent/favorite?tweet_id=[node:field_tweet_id]" class="tweet-action-links__favorite"><span class="text">Favourite</span></a></li>
</ul>',
      'format' => 'full_html',
    ),
    'use_token' => 1,
  );
  $export['tweet_action_links'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function sr_media_bar_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|news_article|media_bar';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'news_article';
  $ds_layout->view_mode = 'media_bar';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'node_link_field',
      ),
      'left' => array(
        1 => 'title',
        2 => 'media_bar_read_more',
      ),
      'right' => array(
        3 => 'field_image',
      ),
    ),
    'fields' => array(
      'node_link_field' => 'header',
      'title' => 'left',
      'media_bar_read_more' => 'left',
      'field_image' => 'right',
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
  $export['node|news_article|media_bar'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|tweet|media_bar';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'tweet';
  $ds_layout->view_mode = 'media_bar';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_tweet_user_link',
        1 => 'body',
        2 => 'image_data_attribute',
        3 => 'field_tweet_date',
        4 => 'tweet_action_links',
      ),
    ),
    'fields' => array(
      'field_tweet_user_link' => 'ds_content',
      'body' => 'ds_content',
      'image_data_attribute' => 'ds_content',
      'field_tweet_date' => 'ds_content',
      'tweet_action_links' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|tweet|media_bar'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function sr_media_bar_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'media_bar';
  $ds_view_mode->label = 'Media Bar';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['media_bar'] = $ds_view_mode;

  return $export;
}