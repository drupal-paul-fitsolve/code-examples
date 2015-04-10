<?php
/**
 * @file
 * Override of Alpha's theme implementation to display a single Drupal page.
 */
?>

<?php if (isset($page['content'])) : ?>
  <?php print render($page['content']); ?>
<?php endif; ?>
