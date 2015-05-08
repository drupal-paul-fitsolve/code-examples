<?php
/**
 * cr-donate-pay-in-form.tpl.php
 * Payin form template - in order to change markup to fit the design
 * Author: J.Wang
 * Last updated: 19th February 2015  
 */
?>
<div class="payin__options">
  <div class="container">
    <div class="row">
      <div class="row">
        <div class="col-xs-12 col-sm-4">
          <h3 class="type--centred hidden-xs">Myself, friends or family</h3>
          <div class="payin__options-1 type--centred">
            <?php print drupal_render($form['options']['type']['general']); ?>
          </div>
        </div>
        <div class="col-xs-12 col-sm-4">
          <div class="payin__options-2 type--centred">
            <h3 class="type--centred hidden-xs">My school or nursery</h3>
            <?php print drupal_render($form['options']['type']['schools']); ?>
          </div>
        </div>
        <div class="col-xs-12 col-sm-4">
          <h3 class="type--centred hidden-xs">My workplace, university or organisation</h3>
          <div class="payin__options-3 type--centred">
              <?php print drupal_render($form['options']['type']['corporate']); ?>
          </div>
        </div>
      </div> 
    </div>
  </div>
</div>
<div class="payin__info">
  <div class="row row--content bg-color--grey-v-light">
    <div class="col-xs-12 col-md-8 col-md-offset-2">
      <div class="general form-wrapper" id="edit-general">
        <div class="row">
          <div class="col-xs-12">
            <label>Please let us know if you fundraised in one of the following ways<span class="form-required" title="This field is required.">*</span></label>
          </div>
          <div class="col-xs-12 col-md-6 payin__field payin__label-reset">
            <?php print drupal_render($form['container']['general']['general_fields_container']['general_event']); ?>
          </div>
          <div class="col-xs-12 payin__field">
            <?php print drupal_render($form['container']['general']['general_fields_container']['general_about']); ?>
          </div>
          <div class="col-xs-12 payin__field">
            <?php print drupal_render($form['container']['general']['general_fields_container']['general_contact']); ?>
          </div>
          <div class="col-xs-12 col-md-3 payin__field">
            <?php print drupal_render($form['container']['general']['general_fields_container']['submit']); ?>
          </div>
        </div> 
      </div>    
      <div class="schools form-wrapper" id="edit-schools">
          <div class="row">
            <div class="col-xs-12">
              <?php
                print drupal_render($form['container']['schools']['schools_fields_container']['establishment']['establishment_lookup']);
              ?>
            </div>
          </div>
          <div class="row">            
            <div id="manual-address-fields-container" class="form-wrapper payin__field">
              <div class="col-xs-12 col-md-6">
                <?php print drupal_render($form['container']['schools']['schools_fields_container']['establishment']['establishment_address_container']['schoolName']); ?>
              </div>
              <div class="col-xs-12 col-md-6">
                <?php print drupal_render($form['container']['schools']['schools_fields_container']['establishment']['establishment_address_container']['address1']); ?>
              </div>
              <div class="col-xs-12 col-md-6">
                <?php print drupal_render($form['container']['schools']['schools_fields_container']['establishment']['establishment_address_container']['address2']); ?>
              </div>
              <div class="col-xs-12 col-md-6">
                <?php print drupal_render($form['container']['schools']['schools_fields_container']['establishment']['establishment_address_container']['address3']); ?>
              </div>
              <div class="col-xs-12 col-md-6">
                <?php print drupal_render($form['container']['schools']['schools_fields_container']['establishment']['establishment_address_container']['town']); ?>
              </div>
              <div class="col-xs-12 col-md-6">
                <?php print drupal_render($form['container']['schools']['schools_fields_container']['establishment']['establishment_address_container']['postcode']); ?>
              </div>
            </div>
          </div>
          <div class="row payin__field">
            <div class="col-xs-12 col-md-6">
              <?php print drupal_render($form['container']['schools']['schools_fields_container']['establishment_type']); ?>
            </div>
            <div class="col-xs-12 col-md-6">
              <?php print drupal_render($form['container']['schools']['schools_fields_container']['area_job']); ?>
            </div>
          </div>
          <div class="row payin__field">
            <div class="col-xs-12 col-md-3">
              <?php print drupal_render($form['container']['schools']['schools_fields_container']['submit']); ?>
              <?php print drupal_render($form['container']['schools']['schools_fields_container']['establishment']['establishment_id']); ?>
            </div>
          </div>          
      </div> 
      <div class="corporate form-wrapper" id="edit-corporate">

          <div class="row payin__field">
            <div class="col-xs-12">
              <label for="edit-general-event">Please let us know if you fundraised in one of the following ways<span class="form-required" title="This field is required.">*</span> </label>
            </div>
            <div class="col-xs-12 col-md-6 payin__label-reset ">
              <?php print drupal_render($form['container']['corporate']['corporate_fields_container']['corporate_event']); ?>
            </div>
          </div>  
          <div class="row payin__field">
            <div class="col-xs-12">
              <label for="edit-organisation-dropdown">Select organisation, establishment or Red Nose Day corporate partner <span class="form-required" title="This field is required.">*</span> </label>
            </div>
             <div class="col-xs-12 col-md-6 payin__label-reset">
              <?php print drupal_render($form['container']['corporate']['corporate_fields_container']['organisation']['organisation_dropdown']); ?>
            </div>
            <div class="col-xs-12 col-md-6 payin__field-reset">
              <?php print drupal_render($form['container']['corporate']['corporate_fields_container']['organisation']['organisation_other']); ?>
            </div>
            <div class="col-xs-12">
              <?php print drupal_render($form['container']['corporate']['corporate_fields_container']['organisation']['organisation_tip']); ?>
            </div>
          </div>
          <div class="row payin__field">
            <div class="col-xs-12">
              <?php print drupal_render($form['container']['corporate']['corporate_fields_container']['corporate_about']); ?>
            </div>
          </div>  
          <div class="row payin__field">
            <div class="col-xs-12">
              <?php print drupal_render($form['container']['corporate']['corporate_fields_container']['corporate_contact']); ?>
            </div>
          </div>   
          <div class="row payin__field">
            <div class="col-xs-12 col-md-3">
              <?php print drupal_render($form['container']['corporate']['corporate_fields_container']['submit']); ?>
            </div>
          </div>  

      </div>  
    </div>
  </div>
</div>
<div class="payin__amount">
  <div class="container">
    <div class="row row--content">
      <h2 class="type--centred">Enter the amount you are paying in <span class="form-required" title="This field is required.">*</span></h2>
      <div class="col-xs-12 col-md-6 col-md-offset-6 col-md-pull-3">
        <?php print drupal_render($form['amount']['amount']); ?>
        <?php print drupal_render($form['amount']['currency']); ?>
      </div>
    </div>
  </div>
</div>
<div class="payin__method payment__card">
  <div class="row row--content bg-color--grey-v-light">
    <h2 class="type--centred payment__title">Select your payment method <span class="form-required" title="This field is required.">*</span></h2>
    <div class="container">
      <div class="row form-type-radios">
        <div class="col-xs-6 col-sm-4 col-md-2 col-md-offset-1">
          <?php print drupal_render($form['method']['paymentType']['PAYPAL']); ?>
        </div>    
        <div class="col-xs-6 col-sm-4 col-md-2">
          <?php print drupal_render($form['method']['paymentType']['AMEX']); ?>
        </div>
        <div class="col-xs-6 col-sm-4 col-md-2">
          <?php print drupal_render($form['method']['paymentType']['JCB']); ?>
        </div>
        <div class="col-xs-6 col-sm-4 col-md-2">
          <?php print drupal_render($form['method']['paymentType']['MSCD']); ?>
        </div>
        <div class="col-xs-6 col-sm-4 col-md-2">
          <?php print drupal_render($form['method']['paymentType']['DMC']); ?>
        </div>
        <div class="col-xs-6 col-sm-4 col-md-2 col-md-offset-2">
          <?php print drupal_render($form['method']['paymentType']['MAES']); ?>
        </div>
        <div class="col-xs-6 col-sm-4 col-md-2">
          <?php print drupal_render($form['method']['paymentType']['VISA']); ?>
        </div>
        <div class="col-xs-6 col-sm-4 col-md-2">
          <?php print drupal_render($form['method']['paymentType']['VISD']); ?>
        </div>
        <div class="col-xs-6 col-sm-4 col-md-2">
          <?php print drupal_render($form['method']['paymentType']['VIED']); ?>
        </div>
      </div>
    </div>
  </div>
</div>
<div class="payin__billing">
  <div class="container">
    <div class="row row--content">
      <div class="billing">
        <h2 class="type--centred">Billing address</h2>
        <p class="type--centred billing__copy">Fields marked with a <span class="form-required">*</span> are mandatory</p>
        <div class="row">
            <div class="col-xs-12 col-md-5 col-md-offset-7 col-md-pull-6">
              <?php print drupal_render($form['billing']['title']); ?>
            </div>
        </div>
        <div class="row">
          <div class="col-xs-12 col-md-5 col-md-offset-1">
            <?php print drupal_render($form['billing']['MC_firstname']); ?>
          </div>
          <div class="col-xs-12 col-md-5">
            <?php print drupal_render($form['billing']['MC_lastname']); ?>
          </div>
        </div>
        <div class="row">
          <div class="col-xs-12 col-md-5 col-md-offset-1">
            <?php print drupal_render($form['billing']['email']); ?>
          </div>
          <div class="col-xs-12 col-md-5">
            <?php print drupal_render($form['billing']['email_confirm']); ?>
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
</div>
<div class="payin__subscribe">
  <div class="row row--content bg-color--grey-v-light">
    <h2 class="type--centred">Keep me posted</h2>
    <p class="type--centred type--lg subscribe__type-padding col-xs-12 col-md-8 col-md-offset-2">
      Don't worry, we definitely won't send you spam or junk mail, or give your details to anyone else. We don't like that sort of thing - <a class="link--inline-grey" href="/legal#/privacy-policy/privacy-policy" target="_blank">see our privacy policy</a>.
    </p>
    <div class="col-xs-12 col-sm-8 col-sm-offset-2 col-md-6 col-md-offset-3">
      <?php print drupal_render($form['subscribe']['MC_permission_email']); ?>
    </div>
    <div class="col-xs-12 col-sm-8 col-sm-offset-2 col-md-6 col-md-offset-3">
      <?php print drupal_render($form['subscribe']['MC_permission_post']); ?>
    </div>
  </div>
</div>
<div class="payin__make_payment">
  <div class="container">
    <div class="row row--content">
      <div class="col-xs-12 col-sm-4 col-sm-offset-4">
        <?php print drupal_render($form['submit']); ?>
      </div>
    </div>
  </div>
</div>
<?php 
  hide($form['options']); 
  hide($form['container']['disabled']); 
  hide($form['container']['#theme_wrappers']); 
  hide($form['container']['general']['#theme_wrappers']); 
  hide($form['container']['schools']['#theme_wrappers']); 
  hide($form['container']['corporate']['#theme_wrappers']); 
  print drupal_render_children($form); 
?>
