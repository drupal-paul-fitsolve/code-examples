<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */
?>
<?php
  $counter = 1;
?>
<?php print $wrapper_prefix; ?>
  <?php if (!empty($title)) : ?>
    <h3><?php print $title; ?></h3>
  <?php endif; ?>
  <?php print $list_type_prefix; ?>
    <?php foreach ($rows as $id => $row): ?>
      <?php
      // Determine if first or last item in row
      if($counter % 4 == 1){
        $classes_array[$id] .= " narrow-alpha alpha";
      }elseif($counter % 4 == 0){
        $classes_array[$id] .= " narrow-omega omega";
      }

      ?>
      <li class="<?php print $classes_array[$id]; ?>"><?php print $row; ?></li>
      <?php $counter++; ?>
    <?php endforeach; ?>
  <?php print $list_type_suffix; ?>
<?php print $wrapper_suffix; ?>