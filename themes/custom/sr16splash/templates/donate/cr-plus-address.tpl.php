<?php
/**
 * cr-plus-address.tpl.php
 * Author: M.Wagg
 * Markup required amending to fit design
 * Last updated: 15th January 2015
 */
?>
<div class="row">
  <div class="col-xs-12 col-md-5 col-md-offset-7 col-md-pull-6"><?php print drupal_render($form['address1']); ?></div>
</div>

<div class="row">
  <div class="col-xs-12 col-md-5 col-md-offset-1"><?php print drupal_render($form['address2']); ?></div>
  <div class="col-xs-12 col-md-5"><?php print drupal_render($form['address3']); ?></div>
</div>

<div class="row">
  <div class="col-xs-12 col-md-5 col-md-offset-1"><?php print drupal_render($form['town']); ?></div>
  <div class="col-xs-12 col-md-5"><?php print drupal_render($form['country']); ?></div>
</div>

<?php print drupal_render_children($form); ?>
