<?php
//dpm($video_settings);
$src = $video_attributes['src'];
$type = $video_attributes['type'];
// This should not be an attribute of video element
unset($video_attributes['src']);
unset($video_attributes['type']);
?>

<div class="cr-mediaelement-video">
  <!-- Picture start Frame -->
  <div class="cr_video_layer mejs-overlay mejs-layer mejs-overlay-play">
    <?php
    if(isset($video_poster) && $video_settings['start_frame'] == 0){
      print $video_poster;
    }
    ?>
    <div class="mejs-overlay-button"></div>
  </div>
  <?php

  # Don't show the video if the No Video is selected. This is for when we want to show only the start frame and play via colorbox.module
  if ($video_settings['no_video'] == 0) {
  ?>
  <!-- Video -->
  <video <?php print drupal_attributes($video_attributes);?>  >
    <source type="video/<?php print $type; ?>" src="<?php print $src; ?>"  />
    <?php
    if ($video_settings['download_link']) { ?>
      <div class="mediaelement-downldisoad-link"><a href="<?php print $src ?>"><?php filter_xss_admin($video_settings['download_text']) ?></a></div>
    <?php
    }
    ?>
  </video>
  <?php
  }
  ?>
</div>