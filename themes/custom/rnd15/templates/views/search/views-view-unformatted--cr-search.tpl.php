<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>

<?php foreach ($view->solr_results as $id => $row): ?>
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .' container"';  } ?>>
    <div class="search__row">
      <div class="col-xs-12 col-md-offset-2 col-md-8 bg-color--white">
        <div class="row search__result">
          <div class="col-xs-2 col-sm-1 bg-color--white search__result__icon">
            <p class="type--hide search__result__show-icon search__result__show-<?php print $row['type']; ?>">Print type here</p>
          </div>
          <div class="col-xs-10 col-sm-11 bg-color--white search__result__copy">
            <h3><a class="link--red" href="<?php print $row['search_api_url']; ?>"><?php print $row['title']; ?></a></h3>
            <p><?php print $row['description']; ?></p>
            <p class="type--semibold"><a class="link--red" href="<?php print $row['search_api_url']; ?>">Read more</a></p>
          </div>
        </div>
      </div>
    </div>
  </div>
<?php endforeach; ?>
