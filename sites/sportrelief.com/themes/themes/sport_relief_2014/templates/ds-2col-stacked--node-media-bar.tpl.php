<?php

/**
 * @file
 * Display Suite fluid 2 column stacked template.
 */

  // Add sidebar classes so that we can apply the correct width in css.
  if (($left && !$right) || ($right && !$left)) {
    $classes .= ' group-one-column';
  }
?>
<<?php print $layout_wrapper; print $layout_attributes; ?> class="ds-2col-stacked-fluid <?php print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>
  
  <?php print $header; ?>

  <?php if (isset($node->news_flash)): ?>
  <?php print t('<h6 class="node-news-article__news-flash--title">@flash_title <span class="icon"></span></h6>', array('@flash_title' => 'Event news flash')); ?>
  <?php endif; ?>

  <?php if ($left): ?>
    <<?php print $left_wrapper ?> class="media-bar__item-left<?php print $left_classes; ?>">
      <?php print $left; ?>
    </<?php print $left_wrapper ?>>
  <?php endif; ?>

  <?php if ($right): ?>
    <<?php print $right_wrapper ?> class="media-bar__item-right<?php print $right_classes; ?>">
      <?php print $right; ?>
    </<?php print $right_wrapper ?>>
  <?php endif; ?>

  <<?php print $footer_wrapper ?> class="media-bar__item-footer<?php print $footer_classes; ?>">
    <?php print $footer; ?>
  </<?php print $footer_wrapper ?>>

  <div class="media-bar__item-background"></div>
</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
