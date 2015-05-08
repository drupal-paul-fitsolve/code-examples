<?php
/**
 * fieldable-panels-pane--donate-money-buy.tpl.php
 * Money buy template - in order to change markup to fit the design
 * Author: M.Wagg
 * Last updated: 13th January 2015
 */
?>
<div class="pane-bundle-donate-money-buy">
  <div class="money-buy__image">
    <?php print drupal_render($content['field_image']); ?> 
    <div class="money-buy__amount cr-donate-moneybuy-amount">
      <p class="type--centred type--lg field__item"><span><?php print $content['field_amount'][0]['#markup']; ?></span></p>
    </div>
  </div>
  <div class="money-buy__text">
    <?php print drupal_render($content['field_body']); ?>
  </div>
</div>