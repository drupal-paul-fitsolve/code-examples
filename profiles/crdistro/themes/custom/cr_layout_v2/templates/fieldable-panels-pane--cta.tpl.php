<?php
/**
 * @file fieldable-panels-pane--cta.tpl.php
 * CR Fieldable Panels Pane CTA Template
 *
 * Variables available:
 * - Rendered fields are available in $fields
 * - Access individual fileds by render($content['field_name'])
 */
?>

<?php if($cta_link): ?>
<a href="<?php print $cta_link; ?>" <?php print drupal_attributes($cta_attributes); ?>>
<?php endif; ?>

  <?php print drupal_render($content); ?>
  <?php print render($title_suffix); ?>

<?php if($cta_link): ?>
</a>
<?php endif; ?>


