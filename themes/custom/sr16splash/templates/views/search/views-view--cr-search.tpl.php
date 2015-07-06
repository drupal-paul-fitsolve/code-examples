<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<div class="<?php print $classes; ?> bg-color--grey-v-light search__view">
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>

  <?php if ($exposed): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

  <?php if ($rows): ?>
      <h2 class="type--centred search__result__total col-xs-12">We've found <strong><?php print $view->total_rows; ?></strong> results that match your search</h2>
  <?php endif; ?>

  <?php if ($tabs): ?>
    <div class="search__tabs container">
      <div class="item-list row">
        <ul class="search__tabs-list">
          <li class="col-xs-6 col-md-3"><?php print $tabs['search']; ?></li>
          <li class="col-xs-6 col-md-3"><?php print $tabs['search/pages']; ?></li>
          <li class="col-xs-6 col-md-3"><?php print $tabs['search/downloads']; ?></li>
          <li class="col-xs-6 col-md-3"><?php print $tabs['search/videos']; ?></li>
          <li class="col-xs-6 col-md-3 col-md-offset-3"><?php print $tabs['search/news']; ?></li>
          <li class="col-xs-6 col-md-3"><?php print $tabs['search/shop']; ?></li>
        </ul>
      </div>
    </div>
    <p class="type--centred type--lg container search__frost__link"><a href="http://my.rednoseday.com/sponsor" class="link--red">Looking for someone to sponsor?</a></p>
  <?php endif; ?>

  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>

  <?php if ($rows): ?>
    <div class="view-content search-results">
      <?php print $rows; ?>
    </div>
  <?php elseif ($empty): ?>
    <div class="view-empty container search__view__empty">
      <p class="type--centred"><?php print $empty; ?></p>
    </div>
  <?php endif; ?>

  <div class="bg-color--grey-v-light">
    <?php if ($pager): ?>
      <?php print $pager; ?>
    <?php endif; ?>
  </div>

  <?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <?php print $more; ?>
  <?php endif; ?>

  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>

</div><?php /* class view */ ?>
