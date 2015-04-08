<?php
/**
 * @file
 * sr_media_wall_images.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function sr_media_wall_images_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|media_images|media_wall';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'media_images';
  $ds_fieldsetting->view_mode = 'media_wall';
  $ds_fieldsetting->settings = array(
    'media_wall_cbox_cta_node_link' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'taxonomy_term_id_field' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h5',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|media_images|media_wall'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|media_images|media_wall_promo_2';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'media_images';
  $ds_fieldsetting->view_mode = 'media_wall_promo_2';
  $ds_fieldsetting->settings = array(
    'media_wall_cbox_cta_node_link' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'taxonomy_term_id_field' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h5',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['node|media_images|media_wall_promo_2'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|media_images|media_wall_promo_3';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'media_images';
  $ds_fieldsetting->view_mode = 'media_wall_promo_3';
  $ds_fieldsetting->settings = array(
    'media_wall_cbox_cta_node_link' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'taxonomy_term_id_field' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '12',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h5',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['node|media_images|media_wall_promo_3'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|media_images|media_wall_touch_device';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'media_images';
  $ds_fieldsetting->view_mode = 'media_wall_touch_device';
  $ds_fieldsetting->settings = array(
    'taxonomy_term_id_field' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'media_wall_cbox_cta_node_link' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|media_images|media_wall_touch_device'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function sr_media_wall_images_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'media_wall_cbox_cta_node_link';
  $ds_field->label = 'Media Wall: CBox/CTA Node Link';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'media_images|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
// Display CTA link if flagged by user (Media Wall Promotion checkbox in node edit form)
if( isset($entity->field_media_wall_promotion ) && count($entity->field_media_wall_promotion) > 0 ){
  if($entity->field_media_wall_promotion[$entity->language][0][\'value\'] == 1){
    $entity->field_cta[$entity->language][0][\'attributes\'] = array(\'class\' => \'node-link news-link\');
    $entity->field_cta[$entity->language][0][\'title\'] = "<span class=\'text\'>" . $entity->field_cta[$entity->language][0][\'title\'] . "</span><span class=\'node-link-icon\'></span>";
    // Display rendered markup
    $display = array(\'label\' => \'hidden\');
    print render(field_view_field(\'node\', $entity, \'field_cta\', $display)); 
  }
}else{
  ?>
  <a class="node-link colorbox-node" href="[node:url]?width=100&height=100" title="View"><span class="text">[node:title]</span><span class="node-link-icon"></span><span class="node-link-background"></span></a>
  <?
}
?>
',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['media_wall_cbox_cta_node_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'media_wall_instagram_feed';
  $ds_field->label = 'Media Wall: Instagram Feed';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'bean' => 'bean',
  );
  $ds_field->ui_limit = 'media_wall|*';
  $ds_field->properties = array(
    'block' => 'views|media_wall_instagram-block',
    'block_render' => '3',
  );
  $export['media_wall_instagram_feed'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'node_image_link';
  $ds_field->label = 'Node image link';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'media_images|*
';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<a class="node-link-image" href="[node:url">[node:field_image]</a>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['node_image_link'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function sr_media_wall_images_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|media_images|media_wall';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'media_images';
  $ds_layout->view_mode = 'media_wall';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'taxonomy_term_id_field',
        1 => 'field_image',
        2 => 'media_wall_cbox_cta_node_link',
        3 => 'title',
        4 => 'group_mw_caption',
      ),
    ),
    'fields' => array(
      'taxonomy_term_id_field' => 'ds_content',
      'field_image' => 'ds_content',
      'media_wall_cbox_cta_node_link' => 'ds_content',
      'title' => 'ds_content',
      'group_mw_caption' => 'ds_content',
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
  $export['node|media_images|media_wall'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|media_images|media_wall_instagram';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'media_images';
  $ds_layout->view_mode = 'media_wall_instagram';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'colorbox_node_link',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'colorbox_node_link' => 'ds_content',
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
  $export['node|media_images|media_wall_instagram'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|media_images|media_wall_promo_2';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'media_images';
  $ds_layout->view_mode = 'media_wall_promo_2';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'taxonomy_term_id_field',
        1 => 'field_image',
        2 => 'media_wall_cbox_cta_node_link',
        3 => 'title',
        4 => 'group_mw_caption',
      ),
    ),
    'fields' => array(
      'taxonomy_term_id_field' => 'ds_content',
      'field_image' => 'ds_content',
      'media_wall_cbox_cta_node_link' => 'ds_content',
      'title' => 'ds_content',
      'group_mw_caption' => 'ds_content',
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
  $export['node|media_images|media_wall_promo_2'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|media_images|media_wall_promo_3';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'media_images';
  $ds_layout->view_mode = 'media_wall_promo_3';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'media_wall_cbox_cta_node_link',
        2 => 'group_mw_caption',
        3 => 'taxonomy_term_id_field',
        4 => 'title',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'media_wall_cbox_cta_node_link' => 'ds_content',
      'group_mw_caption' => 'ds_content',
      'taxonomy_term_id_field' => 'ds_content',
      'title' => 'ds_content',
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
  $export['node|media_images|media_wall_promo_3'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|media_images|media_wall_touch_device';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'media_images';
  $ds_layout->view_mode = 'media_wall_touch_device';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'media_wall_cbox_cta_node_link',
        2 => 'group_mw_caption_touch',
        3 => 'taxonomy_term_id_field',
        4 => 'title_field',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'media_wall_cbox_cta_node_link' => 'ds_content',
      'group_mw_caption_touch' => 'ds_content',
      'taxonomy_term_id_field' => 'ds_content',
      'title_field' => 'ds_content',
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
  $export['node|media_images|media_wall_touch_device'] = $ds_layout;

  return $export;
}
