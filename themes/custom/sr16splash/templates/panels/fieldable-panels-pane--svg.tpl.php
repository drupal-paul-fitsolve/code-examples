<?php
/**
 * @file fieldable-panels-pane--svg.tpl.php
 * CR Fieldable Panels Pane SVG Template
 *
 * Variables available:
 * - Rendered fields are available in $fields
 * - Access individual fields by render($content['field_name'])
 * - Default Fieldable Panles Pane classes and attributes that may be passed in via preprocess hook
 */
?>
<?php if(!empty($classes) || !empty($attributes)) : ?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
<?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php print $fields; ?>
<?php if(!empty($classes) || !empty($attributes)) : ?>
</div>
<?php endif; ?>