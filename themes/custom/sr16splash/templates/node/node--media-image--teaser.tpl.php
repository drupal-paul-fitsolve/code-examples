<a title="<?php print $title ?>" href="<?php print $node_url ?>">
  <div class="flip flip-instant">
    <div class="front node-image--gradient-60 badge badge--photo">
      <div>
        <?php print render($content['field_site_image']) ?>
      </div>
      <div>
        <p><?php print $title ?></p>
      </div>
    </div>
    <div class="back">
      <div class="bg-color--red">
        <p class="type--semibold type--white type--centred vertical-centre"><span class="link--white">View photo</span></p>
      </div>
    </div>
  </div>
</a>