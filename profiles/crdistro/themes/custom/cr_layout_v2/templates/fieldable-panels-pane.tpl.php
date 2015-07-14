<?php if(!empty($classes) || !empty($attributes)) : ?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
<?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php print $fields; ?>
<?php if(!empty($classes) || !empty($attributes)) : ?>
</div>
<?php endif; ?>