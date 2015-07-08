<?php
/**
 * @file fieldable-panels-pane--video.tpl.php
 * CR Fieldable Panels Pane Video Template
 *
 * Variables available:
 * - Rendered fields are available in $fields
 * - Access individual fields by render($content['field_name'])
 * - Default classes and attributes that may be passed in via preprocess hook
 */
?>
<?php if(!empty($classes) || !empty($attributes)) : ?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
<?php endif; ?>

  <div class="media-video">
    <div class="media-video__content">
      <div class="media-video__overlay-button"></div>
      <?php print render($content['field_site_image']); ?>
      <?php print render($content['field_site_video_url']); ?>
    </div>
  </div>

  <?php if(!empty($content['field_custom_body'])) : ?>
  <div class="pane-video__caption">
    <?php print render($content['field_custom_body']); ?>
  </div>
  <?php endif; ?>

<?php if(!empty($classes) || !empty($attributes)) : ?>
</div>
<?php endif; ?>