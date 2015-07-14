<a title="<?php print $title ?>" href="<?php print $node_url ?>">
  <div class="flip flip-instant">
    <div class="front node-image--gradient-60 badge <?php print $badge_class_with_count ?>">
      <div>
        <?php print render($content['field_fundraiser_showcase_images'][0]) ?>
      </div>
      <div>
        <p class="type--xl type--white"><?php print $content['field_site_first_name'][0]['#markup'] ?></p>
        <p><?php print $content['field_site_town'][0]['#markup'] ?></p>
      </div>
    </div>
    <div class="back">
      <div class="bg-color--black">
        <p class="type--semibold type--white type--centred vertical-centre"><span class="icon icon-zoom icon--large"></span></p>
      </div>
    </div>
  </div>
</a>