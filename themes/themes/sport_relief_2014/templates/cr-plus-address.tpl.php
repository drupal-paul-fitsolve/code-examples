<div class="cr-donate-row form-row clearfix">
  <div class="grid-8 narrow-grid-10 alpha narrow-alpha"><?php print drupal_render($form['address1']); ?></div>
  <div class="grid-8 narrow-grid-10 omega narrow-omega"><?php print drupal_render($form['address2']); ?></div>
</div>

<div class="cr-donate-row form-row clearfix">
  <div class="grid-8 narrow-grid-10 alpha narrow-alpha"><?php print drupal_render($form['address3']); ?></div>
  <div class="grid-8 narrow-grid-10 omega narrow-omega"><?php print drupal_render($form['town']); ?></div>
</div>

<div class="cr-donate-row form-row clearfix">
  <div class="grid-8 narrow-grid-10 alpha narrow-alpha"><?php print drupal_render($form['country']); ?></div>
</div>

<?php print drupal_render_children($form); ?>
