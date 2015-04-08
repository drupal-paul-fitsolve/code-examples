<div class="cr-donate-row form-row clearfix">
  <div class="grid-8 narrow-grid-10 alpha"><?php print drupal_render($form['title']); ?></div>
  <div class="grid-8 narrow-grid-10 omega"><?php print drupal_render($form['tel']); ?></div>
</div>
<div class="cr-donate-row form-row clearfix">
  <div class="grid-8 narrow-grid-10 alpha"><?php print drupal_render($form['MC_firstname']); ?></div>
  <div class="grid-8 narrow-grid-10 omega"><?php print drupal_render($form['MC_lastname']); ?></div>
</div>
<div class="cr-donate-row form-row clearfix">
  <div class="grid-8 narrow-grid-10 alpha"><?php print drupal_render($form['email']); ?></div>
  <div class="grid-8 narrow-grid-10 omega"><?php print drupal_render($form['email_confirm']); ?></div>
</div>

<?php print drupal_render_children($form); ?>
