<?php
/**
 * cr-donate-giftaid-form.tpl.php
 * Giftaid form template - in order to change markup to fit the design
 * Author: M.Wagg
 * Last updated: 18th January 2015  
 */

/**
 * Displays Gift Aid top section  
 */
?>
<section class="clearfix">
  <div class="container">
    <div class="row row--content">
      <div class="col-xs-12 giftaid">
        <h1 class="giftaid__title-image giftaid__title-text">Gift Aid It</h1>
        <h2 class="type--centred">Enter your mobile number <span class="form-required" title="This field is required.">*</span></h2>
        <p class="type--centred">The one you used for your text donation...</p>
        <div class="col-xs-12 col-md-6 col-md-offset-3 giftaid__phone-input">
          <?php print drupal_render($form['main']['phone']); ?>
          
        </div>
        <div class="col-xs-12 col-md-8 col-md-offset-2 giftaid__checkbox">
          <?php print drupal_render($form['main']['donate-giftaid']['giftaid']); ?>
        </div>
      </div>
    </div>
  </div>
</section>

<?php
/**
 * Displays Billing section  
 */
?>
<section class="clearfix bg-color--grey-v-light">
  <div class="container">
    <div class="row row--content">
      <div class="col-xs-12 billing">
        <h2 class="type--centred">Billing details</h2>
        <p class="type--centred billing__copy">Fields marked with a <span class="form-required">*</span> are mandatory</p>
        <div class="row">
            <div class="col-xs-12 col-md-5 col-md-offset-7 col-md-pull-6">
              <?php print drupal_render($form['billing']['title']); ?>
            </div>
        </div>
        <div class="row">
          <div class="col-xs-12 col-md-5 col-md-offset-1">
            <?php print drupal_render($form['billing']['first_name']); ?>
          </div>
          <div class="col-xs-12 col-md-5">
            <?php print drupal_render($form['billing']['last_name']); ?>
          </div>
        </div>
        <div class="row">
          <div class="col-xs-12 col-md-5 col-md-offset-7 col-md-pull-6">
            <?php hide($form['billing']['address']['address']); ?>
            <?php print drupal_render($form['billing']['address']); ?>
          </div>
        </div>
        <div class="billing__address-manual">
          <?php print render($form['billing']['address']['address']); ?>
        </div>
      </div>
    </div>
  </div>
</section>

<?php
/**
 * Displays Submit button  
 */
?>
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
