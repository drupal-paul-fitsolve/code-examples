<?php
/**
 * @file
 * This is a template file for a pop-up prompting user to give their consent for
 * the website to set cookies.
 *
 * When overriding this template it is important to note that jQuery will use
 * the following classes to assign actions to buttons:
 *
 * agree-button      - agree to setting cookies
 * find-more-button  - link to an information page
 *
 * Variables available:
 * - $message:  Contains the text that will be display whithin the pop-up
 */
?>

<div>
  <div class ="container-24 cookies-wrapper">
    <div class="cookies leader-minor trailer-minor grid-24 alpha omega">
      <?php print $message ?>
    </div>
    <button type="button" class="agree-button cookies__close"><?php print t("Yes, I agree"); ?></button>
  </div>
</div>
