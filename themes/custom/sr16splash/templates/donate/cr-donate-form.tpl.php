<?php
/**
 * cr-donate-form.tpl.php
 * Donate form template - in order to change markup to fit the design
 * Author: M.Wagg
 * Last updated: 13th January 2015  
 */
?>
<section class="clearfix bg-color--grey-v-light money-buy">
  <div class="container">
    <div class="row--content money-buy__row-bottom">
      <?php print drupal_render($form['amount']); ?>
    </div>
  </div>
</section>

<!-- displays giftaid -->
<section class="clearfix">
  <div class="container">
    <div class="row row--content">
      <div class="col-xs-12 giftaid">
        <?php print drupal_render($form['giftaid']); ?>
      </div>
    </div>
  </div>
</section>

<!-- displays pay by card or paypal with paypal button -->
<section class="clearfix bg-color--grey-v-light">
  <div class="container">
    <div class="row row--content">
      <div class="payment">
        <h2 class="type--centred payment__title">Select your payment method <span class="form-required" title="This field is required.">*</span></h2>
        <div class="col-xs-12 col-md-6 payment__card">
          <h3 class="type--centred">Donate by card</h3>
          <p class="type--centred">If you wish to pay by credit or debit make sure you have entered an amount above and continue below.</p>
          <p class="type--xl hidden-xs hidden-sm payment__card-or">OR</p>
          <?php print drupal_render($form['method']['paymentType']); ?>
        </div>
        <div class="col-xs-12 col-md-6 payment__paypal">
          <h3 class="type--centred">Donate by Paypal</h3>
          <p class="type--centred">If you wish to pay by Paypal make sure you have entered an amount above and click the button.</p>
          <?php print render($form['card_or_paypal']['paypal']); ?>
          <div class="payment__pingit hidden-sm hidden-md hidden-lg">
            <h3 class="type--centred">Donate using Barclays Pingit</h3>
            <p class="type--centred">If you wish to donate with Barclays Pingit, click the button below.</p>
            <p class="type--centred payment__pingit-image payment__pingit-hide-text"><a href="<?php print $form['pingit_url']['#value']; ?>">Donate with Barclays Pingit</a></p>
          </div>
        </div>
      </div>
    </div>
  </div>
</section>

<!-- displays billing form -->
<section class="clearfix">
  <div class="container">
    <div class="row--content">
      <div class="billing">
        <h2 class="type--centred">Billing details</h2>
        <p class="type--centred billing__copy">Fields marked with a <span class="form-required">*</span> are mandatory</p>
        <?php print drupal_render($form['billing']['title']); ?>
        <?php print drupal_render($form['billing']['MC_firstname']); ?>
        <?php print drupal_render($form['billing']['MC_lastname']); ?>
        <?php print drupal_render($form['billing']['email']); ?>
        <?php print drupal_render($form['billing']['email_confirm']); ?>
        <?php print drupal_render($form['billing']['tel']); ?>
        <?php hide($form['billing']['address']['address']); ?>
        <?php print drupal_render($form['billing']['address']); ?>

        <div class="billing__address-manual"><?php print render($form['billing']['address']['address']); ?></div>
      </div>
    </div>
  </div>
</section>

<!-- displays keep me posted section -->
<section class="clearfix bg-color--grey-v-light">
  <div class="container">
    <div class="row row--content">
      <div class="subscribe">
        <?php print drupal_render($form['subscribe']); ?>
      </div>
    </div>
  </div>
</section>

<!-- displays submit button -->
<section class="clearfix">
  <div class="container">
    <div class="row row--content">
      <div class="col-xs-12 col-sm-4 col-sm-offset-4">
        <?php print drupal_render($form['submit']); ?>
      </div>
    </div>
  </div>
</section>

<?php print drupal_render_children($form); ?>