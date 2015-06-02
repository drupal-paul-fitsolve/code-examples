<?php
  /**
    * webform-form-1207.tpl.php
    * 'Pre-order your fundraising kit' webform template
    * Author: A.Phipps
    * Last updated: 22nd March 2015 
    */
  
  ?>
<section class="clearfix preorder-section preorder--type">
  <div class="container">
    <div class="row row--content row--small">
      <div class="col-xs-12">
        <div class="row">
          <div class="col-xs-12 type--centred">
            <h2 class="type--margin-none">Simply fill out the form below</h2>
            <p>All fields marked with a <span class="form-required" title="This field is required.">*</span> are mandatory</p>
          </div>
        </div>
        <div class="row">
          <div class="col-xs-12 col-md-6 col-md-push-3">
            <?php print drupal_render($form['submitted']['choose_your_fundraising_kit']);?>
          </div>
        </div>
      </div>
    </div>
  </div>
</section>
<section class="clearfix bg-color--grey-v-light preorder-section preorder--teachers-details">
  <div class="container">
    <div class="row row--content row--small">
      <div class="col-xs-12">
        <div class="row">
          <div class="col-xs-12 type--centred">
            <h2>Teacher's details</h2>
          </div>
          <div class="col-xs-12 col-md-6">
            <?php print drupal_render($form['submitted']['title']);?>
          </div>
        </div>
        <div class="row">
          <div class="col-xs-12 col-md-6">
            <?php print drupal_render($form['submitted']['first_name']);?>
          </div>
          <div class="col-xs-12 col-md-6">
            <?php print drupal_render($form['submitted']['last_name']);?>
          </div>
          <div class="col-xs-12 col-md-6">
            <?php print drupal_render($form['submitted']['job_title']);?>
          </div>
          <div class="col-xs-12 col-md-6">
            <?php print drupal_render($form['submitted']['establishment_type']);?>
          </div>
          <div class="col-xs-12 col-md-6">
            <?php print drupal_render($form['submitted']['email_address']);?>
          </div>
          <div class="col-xs-12 col-md-6">
            <?php print drupal_render($form['submitted']['telephone']);?>
          </div>
        </div>
      </div>
    </div>
  </div>
</section>
<section class="clearfix preorder-section preorder--school-details">
  <div class="container">
    <div class="row row--content row--small">
      <div class="col-xs-12 schools form-wrapper" id="edit-schools">
        <div class="row">
          <div class="col-xs-12 type--centred">
            <h2>School address details</h2>
          </div>
        </div>
        <div class="row">
          <div class="col-xs-12 col-md-8 col-md-push-2">
            <?php print drupal_render($form['submitted']['postcode_lookup']);?>
          </div>
        </div>
      </div>
    </div>
  </div>
</section>
<section class="clearfix bg-color--grey-v-light preorder-section preorder--checkboxes">
  <div class="container">
    <div class="row row--content row--small">
      <div class="col-xs-12">
        <div class="row">
          <div class="col-xs-12 col-md-8 col-md-push-2">
            <?php print drupal_render($form['submitted']['postal_updates']);?>
          </div>
        </div>
        <div class="row">
          <div class="col-xs-12 col-md-8 col-md-push-2">
            <?php print drupal_render($form['submitted']['tcs']);?>
          </div>
        </div>
        <div class="row">
          <div class="col-xs-12 col-md-8 col-md-push-2">
            <?php print drupal_render($form['submitted']['email_updates']);?>
          </div>
        </div>
      </div>
    </div>
  </div>
</section>
<section class="clearfix preorder-section preorder--submit">
  <div class="container">
    <div class="row row--content row--small">
      <div class="col-xs-12">
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