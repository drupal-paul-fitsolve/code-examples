<article class="search-result search-result--page">
  <h3 class="search-result__title"><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h3>
  <?php if (!empty($metatags)): ?>
    <p><?php print check_plain($metatags[$language]['description']['value']); ?></p>
  <?php endif; ?>
  <a href="<?php print $node_url; ?>" class="cta">View more</a>
</article>
