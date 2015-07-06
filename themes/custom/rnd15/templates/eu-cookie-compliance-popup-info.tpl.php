<?php
/** 
 * eu-cookie-compliance-popup-info.tpl.php
 * Cookie Banner Template file override
 * Author: P.Brady
 * Last updated: 12th September 2014
 *
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
 * - $message:  Contains the text that will be display within the pop-up
 */
?>

<div>
  <div class="container cookie-banner">
    <div class="row">
      <div class="col-xs-12">
        <div class ="cookie-banner__content">
          <div id="popup-text">
            <?php print $message ?>
          </div>
          <div class="cookie-banner__agree-wrapper">        
            <button id="cookie-banner__agree" class="agree-button cookie-banner__agree" type="button">
              <span class="type--white icon icon-cross"></span>
              <span class="hidden-all">Agree to Cookies?</span>
            </button>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>