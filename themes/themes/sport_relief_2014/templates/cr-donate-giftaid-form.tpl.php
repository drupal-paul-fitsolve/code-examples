<div class="giftaid-section-header giftaid-section-1"></div>
<div class="giftaid-form-wrapper">
  <div class="container-24">
    <div class="grid-16 narrow-grid-20 alpha omega narrow-alpha narrow-omega">
      <?php print drupal_render($form['main']); ?>
    </div>
  </div>
</div>

<div class="giftaid-section-header giftaid-section-2"></div>
<div class="giftaid-form-wrapper">
  <div class="container-24">
    <div class="grid-16 narrow-grid-20 alpha omega narrow-alpha narrow-omega">
      <?php print drupal_render_children($form); ?>
    </div>
  </div>
</div>
