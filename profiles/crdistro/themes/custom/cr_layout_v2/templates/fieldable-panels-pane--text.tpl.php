<?php
/**
 * @file fieldable-panels-pane--text.tpl.php
 * CR Fieldable Panels Pane TEXT Template
 *
 * Variables available:
 * - Rendered fields are available in $fields
 * - Access individual fileds by render($content['field_name'])
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