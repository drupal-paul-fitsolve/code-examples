<?php
// This template can be used via a #theme_wrapper attribute on a render array
// in order to render callback markup in the content area of the page
// see cr_donate_confirm_cancel_giftaid_thankyou for example use
?>
<div id="callback-content-wrapper">
  <div class="container-24 clearfix">
    <div class="leader-double grid-24">
      <?php print render($element['#children']); ?>
    </div>
  </div>
</div>
