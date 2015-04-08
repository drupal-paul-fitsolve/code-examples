<div class="cr-donate-row form-row clearfix">
  <div class="grid-8 narrow-grid-10 alpha narrow-alpha"><?php print drupal_render($form['title']); ?></div>
</div>
<div class="cr-donate-row form-row clearfix">
  <div class="grid-8 narrow-grid-10 alpha narrow-alpha"><?php print drupal_render($form['first_name']); ?></div>
  <div class="grid-8 narrow-grid-10 omega narrow-omega"><?php print drupal_render($form['last_name']); ?></div>
</div>

<?php print drupal_render_children($form); ?>
