<?php
/**
 * @file
 * Template for Fundraisier showcase submission form
 * Author: Andy E. Phipps
 */
?>

<div class="fundraiser-showcase__step-1">
  <div class="container">
    <div class="row row--content">
    <div class="col-xs-12">
      <div class="row">
        <div class="col-xs-12 col-md-6 col-md-offset-3">
          <div class="fundraiser-showcase__upload-intro type--centred">
            <h2 class="type--centred">Step 1. Upload your photos</h2>
            <p class="type--centred fundraiser-showcase__upload-intro-filesize"><?php print($form['field_fundraiser_showcase_images'][LANGUAGE_NONE]['#file_upload_description']); ?></p>
            <p class="type--centred fundraiser-showcase__upload-intro-terms">For full terms and conditions, <a href="/legal#/terms-of-use" target="_blank">click here</a>.</p>
          </div>
        </div>
      </div> 
      <div class="row">
        <div class="col-xs-12 col-md-8 col-md-offset-2">
          <div class="fundraiser-showcase__uploader type--centred">
           <?php print drupal_render($form['field_fundraiser_showcase_images']); ?> 
          </div>
        </div>
      </div> 
      <div class="row">
        <div class="col-xs-12 col-md-8 col-md-offset-2">
          <div class="fundraiser-showcase__caption">
           <?php print drupal_render($form['body']); ?> 
          </div>
        </div>
      </div>
    </div>
    </div>
  </div>
</div>

<div class="fundraiser-showcase__step-2 bg-color--grey-v-light">
  <div class="container">
    <div class="row row--content">
      <div class="col-xs-12">
      <div class="row">
        <div class="col-xs-12 col-md-6 col-md-offset-3">
          <div class="fundraiser-showcase__upload-intro type--centred">
            <h2 class="type--centred">Step 2. Tell us about yourself</h2>
          </div>
        </div>
      </div>
      <div class="row">
        <div class="col-xs-12 col-md-6 fundraiser-showcase__first-name">
          <?php print drupal_render($form['field_site_first_name']); ?> 
        </div>
        <div class="col-xs-12 col-md-6 fundraiser-showcase__first-name">
          <?php print drupal_render($form['field_site_last_name']); ?> 
        </div>
      </div>
      <div class="row">
        <div class="col-xs-12 col-md-6 fundraiser-showcase__establishment">
          <?php print drupal_render($form['field_site_establishment']); ?> 
        </div>
        <div class="col-xs-12 col-md-6 fundraiser-showcase__town">
          <?php print drupal_render($form['field_site_town']); ?> 
        </div>
      </div>
      <div class="row">
        <div class="col-xs-12 col-md-6 fundraiser-showcase__email">
          <?php print drupal_render($form['field_site_email']); ?> 
        </div>

        <div class="col-xs-12 col-md-6 fundraiser-showcase__context">
          <?php print drupal_render($form['field_site_fundraising_context']); ?> 
        </div>
      </div>
      <div class="row">
        <div class="col-xs-12 col-md-8 col-md-offset-2 fundraiser-showcase__consent">
          <?php print drupal_render($form['field_site_consent']); ?> 
        </div>
      </div>
      <div class="row">
        <div class="col-xs-12 col-md-4 col-md-offset-4 fundraiser-showcase__submit">
          <?php print drupal_render($form['submit']); ?> 
        </div>
      </div>
    </div>
    </div>
  </div>
</div>
<?php print drupal_render_children($form); ?>
