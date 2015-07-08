<?php
/**
 * @file cr-donate-thank-you.tpl.php
 * CR Panel Pane Template
 *
 * This is used to add a wrapper around fieldable Panel Panes
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
 */
?>

<?php if (isset($transaction_id)): ?> 
  <p class="type--lg type--centred">Here's your payment transaction ID: <?php print $transaction_id; ?></p>
<?php endif; ?>