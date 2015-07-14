<?php
/**
 * @file panels-pane.tpl.php
 * CR Panel Pane Template
 *
 * This is used to add a wrapper around fieldable Panel Panes
 *
 * @author Jeremy P.
 *
 * Variables available:
 * - $pane->type: the content type inside this pane
 * - $pane->subtype: The subtype, if applicable. If a view it will be the
 *   view name; if a node it will be the nid, etc.
 * - $title: The title of the content
 * - $content: The actual content
 * - $links: Any links associated with the content
 * - $more: An optional 'more' link (destination only)
 * - $admin_links: Administrative links associated with the content
 * - $feeds: Any feed icons or associated with the content
 * - $display: The complete panels display object containing all kinds of
 *   data including the contexts and all of the other panes being displayed.
 * - $h_tag: Header Appearance module H tag for title
 * - $title_attributes: Contains the header appearance title attributes such as custom classes
 * - $pane_prefix/$pane_suffix: Default suffix/prefix provided by panels module.
 */
?>
<?php if ($pane_prefix && !empty($pane_prefix)): ?>
  <?php print $pane_prefix; ?>
<?php endif; ?>

<?php if (!empty($attributes)): ?>
  <div <?php print $attributes; ?>>
<?php endif; ?>

<?php if ($admin_links): ?>
  <?php print $admin_links; ?>
<?php endif; ?>

<?php if (!empty($pane_link)): ?>
  <a <?php print $pane_link['attributes']; ?>>
<?php endif; ?>

  <?php print render($content); ?>

<?php if (!empty($pane_link)): ?>
  </a>
<?php endif; ?>


<?php if (!empty($attributes)): ?>
  </div>
<?php endif; ?>
<?php if ($pane_suffix && !empty($pane_suffix)): ?>
  <?php print $pane_suffix; ?>
<?php endif; ?>