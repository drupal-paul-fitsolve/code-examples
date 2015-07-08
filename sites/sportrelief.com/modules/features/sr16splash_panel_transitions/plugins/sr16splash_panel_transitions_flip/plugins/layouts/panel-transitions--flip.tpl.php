<?php
/**
 * @file panel-transitions--flip.tpl.php
 * 
 * Template file to render the regions in a panel-transition--flip
 * 
 * Author: P.Brady
 * Last updated: 10th September 2014
 *
 */
?>

<?php
/**
 * $transition_attributes probably aren't available if we're in the Page Manager UI.
 * Do an isset check first as drupal_attributes isn't very forgiving if given a null value.
 */ 
?>

<div<?php print (isset($transition_attributes) ? drupal_attributes($transition_attributes) : '') ?>>

  <?php if (is_array($transition_attributes['class']) && in_array('flip-left', $transition_attributes['class'])): ?>
    <div class="front" data-mh="flip">
  <?php else: ?>
    <div class="front">
  <?php endif; ?>

      <?php print $content['front'] ?>
    </div>
  
  <?php if($cta): ?>
    <?php print $cta ?>
  <?php endif; ?>
  
  <?php if (is_array($transition_attributes['class']) && in_array('flip-left', $transition_attributes['class'])): ?>
    <div class="back" data-mh="flip">
  <?php else: ?>
    <div class="back">
  <?php endif; ?>

      <?php print $content['back'] ?>
  </div>
  
  <?php if($cta): ?>
    </a>
  <?php endif; ?>

</div>