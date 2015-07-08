<?php
/**
 * cr-donate-giftaid.tpl.php
 * Giftaid template - in order to change markup to fit the design
 * Author: M.Wagg
 * Last updated: 13th January 2015
 */
?>

<?php
/**
 * Extra condition to stop title rendering at the bottom of the main giftaid page, yet still display on donate.
 */
?>
<?php if (isset($form['MC_permission_giftaid'])): ?>

  <?php if (isset($form['calculator'])): ?>
    <div class="giftaid-calculator">
      <h1 class="giftaid__title-image giftaid__title-text">Gift Aid It</h1>
      <h2 class="type--centred">Gift Aid: costs you nothing, helps us keep going.</h2>
      <?php print drupal_render($form['calculator']); ?>
    </div>
  <?php else: ?>
    <h1 class="giftaid__title-image giftaid__title-text">Gift Aid It</h1>
  <?php endif; ?>

  <div class="col-xs-12 col-md-8 col-md-offset-2 type--centred"><?php print drupal_render($form['MC_permission_giftaid']); ?></div>

<?php endif; ?>

<?php print drupal_render_children($form); ?>
