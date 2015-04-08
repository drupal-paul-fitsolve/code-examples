<div class="grid-13 dotted-right">
  <?php print drupal_render($form['intro']); ?>
</div>

<div class="grid-5 prefix-1">
  <?php print drupal_render($form['phase']); ?>
</div>

<div class="grid-2">
  <?php print drupal_render($form['submit']); ?>
</div>

<?php echo drupal_render_children($form); ?>
