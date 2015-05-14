<?php
/**
 * @file
 * Template 1 for Media Wall
 * Author: Andy E. Phipps
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout.
 */
?>
<div <?php print $attributes ?>>
  <div class="col-xs-12 col-sm-9 media-wall__region media-wall__region-1">
    <?php print $content['region_1']; ?>
  </div>
  <div class="col-xs-12 col-sm-3 media-wall__region media-wall__region-2">
    <?php print $content['region_2']; ?>
  </div>
  <div class="col-xs-12 col-sm-3 media-wall__region media-wall__region-3">
  <?php print $content['region_3']; ?>
  </div>
  <div class="col-xs-12 col-sm-6 col-sm-push-6 media-wall__region media-wall__region-4">
    <?php print $content['region_4']; ?>
  </div>

  <div class="col-xs-12 col-sm-6 col-sm-pull-6">
    <div class="row">
      <div class="col-xs-12 media-wall__region media-wall__region-5">
        <?php print $content['region_5']; ?>
      </div>
      <div class="col-xs-12 media-wall__region media-wall__region-6">
        <?php print $content['region_6']; ?>
      </div>
    </div>
  </div>

  <div class="col-xs-12 col-sm-4 media-wall__region media-wall__region-7">
    <?php print $content['region_7']; ?>
  </div>
  <div class="col-xs-12 col-sm-4 media-wall__region media-wall__region-8">
    <?php print $content['region_8']; ?>
  </div>
  <div class="col-xs-12 col-sm-4 media-wall__region media-wall__region-9">
    <?php print $content['region_9']; ?>
  </div>
</div>