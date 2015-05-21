<?php
  /**
   * @file
   * Customize the display of a complete webform.
   *
   * This file may be renamed "webform-form-[nid].tpl.php" to target a specific
   * webform on your site. Or you can leave it "webform-form.tpl.php" to affect
   * all webforms on your site.
   *
   * Available variables:
   * - $form: The complete form array.
   * - $nid: The node ID of the Webform.
   *
   * The $form array contains two main pieces:
   * - $form['submitted']: The main content of the user-created form.
   * - $form['details']: Internal information stored by Webform.
   */

  dpm($form['submitted']);
  ?>

<section class="clearfix">
  <div class="container">
    <div class="row row--content">
      <div class="col-xs-12 type--centred">
        <h2>Simply fill out the form below</h2>
        <p>All fields marked with a <span class="form-required" title="This field is required.">*</span> are mandatory</p>
      </div>

      <div class="col-xs-12 col-md-6 col-md-push-3">
        <?php print drupal_render($form['submitted']['choose_your_fundraising_kit']);?>
      </div>
    </div>
  </div>
</section>

<section class="clearfix bg-color--grey-v-light">
  <div class="container">
    <div class="row row--content">
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

<section class="clearfix">
  <div class="container school-address-details">
    <div class="row row--content">
      <div class="col-xs-12">
        <div class="row">
            <div class="col-xs-12 type--centred">
              <h2>School address details</h2>
            </div>
        </div>
         <div class="row">
            <div class="col-xs-12 col-md-6 col-md-push-3">
              <?php print drupal_render($form['submitted']['postcode_lookup']);?>
            </div>
        </div>
      </div>
    </div>
  </div>
</section>

<section class="clearfix bg-color--grey-v-light">
  <div class="container">
    <div class="row row--content">
      <div class="col-xs-12">

        <div class="row">
          <div class="col-xs-12 col-md-10 col-md-push-1">
            <?php print drupal_render($form['submitted']['postal_updates']);?>
          </div>
        </div>
        <div class="row">
          <div class="col-xs-12 col-md-10 col-md-push-1">
            <?php print drupal_render($form['submitted']['tcs']);?>
          </div>
        </div>
        <div class="row">
          <div class="col-xs-12 col-md-10 col-md-push-1">
            <?php print drupal_render($form['submitted']['email_updates']);?>
          </div>
        </div>
        
      </div>
    </div>
  </div>
</section>

<?php
// Print out the main part of the form.
// Feel free to break this up and move the pieces within the array.
//print drupal_render($form['submitted']);
// Always print out the entire $form. This renders the remaining pieces of the
// form that haven't yet been rendered above.
print drupal_render_children($form);