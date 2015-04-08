<div class="<?php print $region_classes ?>">
  <?php //TODO: Not the cleanest, but works for now
  $has_emph = strpos($region_classes, "pod--emphasis");
  if($has_emph !== FALSE && is_int($has_emph) === true) : ?>
    <span class="pod--emphasis__colorone"></span>
    <span class="pod--emphasis__colortwo"></span>
    <span class="pod--emphasis__colorthree"></span>
  <?php endif; ?>
  <?php print $pane_content ?>
</div>
