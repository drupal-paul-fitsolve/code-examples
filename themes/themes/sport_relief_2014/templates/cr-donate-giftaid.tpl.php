<div class="grid-16 narrow-grid-21 alpha omega">
  <div class="grid-2 alpha">
    <?php print theme('image', array('path' => drupal_get_path('module', 'cr_donate') . '/images/giftaid.png')); ?>
  </div>
  <div class="grid-14 narrow-grid-18 omega">
    <?php if (isset($form['calculator'])): ?>
      <div class="giftaid-calculator">
        <?php print drupal_render($form['calculator']); ?>
      </div>
    <?php endif; ?>
    <?php print drupal_render_children($form); ?>
  </div>
</div>
