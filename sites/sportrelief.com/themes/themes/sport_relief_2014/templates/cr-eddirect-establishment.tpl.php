<?php
  // These vars can't be created in preprocessor as template receives vars
  // by value rather than reference meaning that as we drupal_render each element
  // the $form var is not updated with the elements renderedness, and so when
  // we call drupal_render_children($form)

  $establishment_lookup = &$form['establishment_lookup'];
  $establishment_id = &$form['establishment_id'];
  $establishment_address_container = &$form['establishment_address_container'];
  $address_container_id = $establishment_address_container['#attributes']['id'];
  $address_container = &$establishment_address_container;

  $establishment_schoolname = &$address_container['schoolName'];
  $establishment_address1 = &$address_container['address1'];
  $establishment_address2 = &$address_container['address2'];
  $establishment_address3 = &$address_container['address3'];
  $establishment_town = &$address_container['town'];
  $establishment_postcode = &$address_container['postcode'];
?>

<?php print drupal_render($establishment_lookup); ?>

<div class="establishment-address" id="<?php print $address_container_id; ?>">
  <?php print drupal_render($establishment_schoolname); ?>
  <div class="address-fields-row-1">
    <?php print drupal_render($establishment_address1); ?>
    <?php print drupal_render($establishment_address2); ?>
  </div>
  <div class="address-fields-row-2">
    <?php print drupal_render($establishment_address3); ?>
    <?php print drupal_render($establishment_town); ?>
  </div>
  <?php print drupal_render($establishment_postcode); ?>
</div>

<!--normally we would call drupal_render($form) here to output any as yet-->
<!--unrendered elements, however this causes an infinite recursion so-->
<!--we call drupal_render_children which works.  Not yet clear on why-->
<!--this is-->
<!--@todo Find out why-->
<?php print drupal_render_children($form); ?>
