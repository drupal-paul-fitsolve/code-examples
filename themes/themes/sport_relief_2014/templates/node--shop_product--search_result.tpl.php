<article class="search-result search-result--shop-product with-icon">
  <?php hide($content['title_field']); ?>
  <?php hide($content['field_shop_url']); ?>
  <h3 class="search-result__title"><a href="<?php print check_plain($field_shop_url[0]['url']); ?>" title="<?php print check_plain($title_field[$language][0]['safe_value']); ?>"><?php print check_plain($title_field[$language][0]['safe_value']); ?></a></h3>
  <?php print render($content); ?>
  <a href="<?php print check_plain($field_shop_url[0]['url']); ?>" title="<?php print check_plain($title_field[$language][0]['safe_value']); ?>" class="cta">View more</a>
</article>
