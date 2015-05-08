<?php
/**
 * @file fieldable-panels-pane--pane-media-wall.tpl.php
 * CR Fieldable Panels Pane Media Wall Template
 *
 * Variables available:
 * - Rendered fields are available in $fields
 * - Access individual fields by render($content['field_name'])
 * - Default classes and attributes that may be passed in via preprocess hook
 */
?>
<div class="row pane-media-wall__row-background">
  <div class="hidden-xs">
    <?php print render($content['field_site_image']); ?>
  </div>
</div>

<div class="row pane-media-wall__row-xs pane-media-wall__caption">

  <div class="pane-media-wall__mobile-image col-xs-4 hidden-sm hidden-md hidden-lg">
    <?php print render($content['field_site_image_xs']); ?>
  </div>

  <div class="pane-media-wall__caption-content col-xs-8 col-sm-12">
    <?php if(!empty($title)): ?>
    <h3 class="pane-media-wall__title"><?php print $title; ?></h3>
    <?php endif; ?>
    <?php if(!empty($content['field_body'][0])): ?>
      <p class="pane-media-wall__paragraph"><?php print render($content['field_body'][0]); ?></p>
    <?php endif; ?>
    
  </div>

</div>