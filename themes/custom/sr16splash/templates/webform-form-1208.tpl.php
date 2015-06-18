<?php
  /**
    * webform-form-1208.tpl.php
    * Author: A.Phipps
    * Last updated: 22nd March 2015 
    */

?>
<section class="clearfix register-section">
  <div class="container">
    <div class="row row--content row--small">
      <div class="col-xs-12">
        <div class="row">
          <div class="col-xs-12 type--centred">
            <h2 class="type--margin-none">Simply fill out this short form</h2>
            <p class="register-intro">All fields marked with a <span class="form-required" title="This field is required.">*</span> are mandatory</p>
          </div>
        </div>
        <div class="row">
          <div class="col-xs-12 col-md-6 col-md-push-3">
            <?php print drupal_render($form['submitted']['first_name']);?>
          </div>
        </div>
        <div class="row">
          <div class="col-xs-12 col-md-6 col-md-push-3">
            <?php print drupal_render($form['submitted']['last_name']);?>
          </div>
        </div>
         <div class="row">
          <div class="col-xs-12 col-md-6 col-md-push-3">
            <?php print drupal_render($form['submitted']['email_address']);?>
          </div>
        </div>
        <div class="row">
          <div class="col-xs-12 col-md-6 col-md-push-3">
            <?php print drupal_render($form['submitted']['what_events_are_you_interested_in']);?>
          </div>
        </div>
        <div class="row">
          <div class="col-xs-12 col-md-6 col-md-push-3">
            <?php print drupal_render($form['submitted']['postcode']);?>
          </div>
        </div>
        <div class="row">
          <div class="col-xs-12 col-md-6 col-md-push-3">
            <p class="register-terms">By completing this Registration of Interest form, we will send you
              information by email regarding Comic Relief and Sport Relief events in
              your area.</p>
          </div>
        </div>
        <div class="row">
          <div class="col-xs-12 col-md-4 col-md-push-4">
            <?php print drupal_render($form['actions']['submit']);?>
          </div>
        </div>
      </div>
    </div>
  </div>
</section>

<?php print drupal_render_children($form); ?>