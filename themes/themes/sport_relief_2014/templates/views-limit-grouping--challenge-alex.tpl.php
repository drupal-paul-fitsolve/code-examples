<li class="challenge-main-slides">
  <?php foreach ($rows as $id => $row): ?>
    <div class="views-row views-row-<?php print $zebra; ?> <?php print $classes; ?>">
      <?php print $row; ?>
      <?php if (!empty($title)): ?>
        <h3><?php print $title; ?></h3>
      <?php endif; ?>
    </div>
  <?php endforeach; ?>
</li>
