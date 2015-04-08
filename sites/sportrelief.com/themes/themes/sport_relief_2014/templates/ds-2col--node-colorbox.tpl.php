<?php

/**
 * @file
 * Display Suite 2 column template.
 */
?>

<<?php print $layout_wrapper; print $layout_attributes; ?> class="ds-2col container-24 colorbox-container <?php print $classes;?> clearfix">
  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <<?php print $left_wrapper ?> class="colorbox--top omega alpha grid-16 <?php print $left_classes; ?>">
    <?php print $left; ?>
  </<?php print $left_wrapper ?>>

  <<?php print $right_wrapper ?> class="colorbox--bottom omega alpha grid-16 <?php print $right_classes; ?>">
    <?php print $right; ?>
  </<?php print $right_wrapper ?>>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
