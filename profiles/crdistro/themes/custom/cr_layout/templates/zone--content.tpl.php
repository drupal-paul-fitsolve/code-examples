<?php
$content_attributes_extra = ' class="clearfix container-24"';
//$content_attributes_stripped = ' id="zone-content" class="zone zone-content clearfix"';
?>

<div<?php print $content_attributes_extra; ?>>
  <?php if ($breadcrumb): ?>
    <div id="breadcrumb" class="grid-<?php print $columns; ?>"><?php print $breadcrumb; ?></div>
  <?php endif; ?>
  <?php if ($messages): ?>
    <div id="messages" class="grid-<?php print $columns; ?>"><?php print $messages; ?></div>
  <?php endif; ?>
</div>

<?php if ($wrapper): ?><div<?php print $attributes; ?>><?php endif; ?>
    <?php print $content; ?>
<?php if ($wrapper): ?></div><?php endif; ?>


<?php //  ?>