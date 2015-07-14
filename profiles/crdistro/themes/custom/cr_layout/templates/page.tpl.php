<?php
/**
 * @file
 * Override of Alpha's theme implementation to display a single Drupal page.
 */
?>
<?php if (isset($page['header'])) : ?>
  <?php print render($page['header']); ?>
<?php endif; ?>

<?php if (isset($page['content'])) : ?>
  <?php print render($page['content']); ?>
<?php endif; ?>

<?php if (isset($page['footer'])) : ?>
  <?php print render($page['footer']); ?>
<?php endif; ?>
