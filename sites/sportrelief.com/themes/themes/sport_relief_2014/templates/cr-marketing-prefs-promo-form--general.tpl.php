<div class="grid-12">
  <?php print drupal_render($form['intro']); ?>
</div>

<div class="grid-5">
  <?php print drupal_render($form['email']); ?>
</div>

<div class="grid-2">
  <?php print drupal_render($form['submit']); ?>
</div>

<?php echo drupal_render_children($form); ?>
