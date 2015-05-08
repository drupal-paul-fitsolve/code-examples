<div<?php print $attributes; ?>>
  <header class="header" role="banner">
    <div class="header__content container">
      <div class="row header__row">
        <div class="branding">
          <a href="<?php print $front_page; ?>" title="<?php print $site_name; ?>" rel="home" class="branding__logo"><span><?php print $site_name; ?></span></a>
          <p class="branding__slogan"><?php print $site_slogan; ?></p>
        </div>
      </div>
    </div>
    <?php print render($page['header']); ?>
  </header>

  <?php if (!empty($page['highlighted'])): ?>
    <div class="l-highlighted-wrapper">
      <?php print render($page['highlighted']); ?>
    </div>
  <?php endif; ?>

  <div class="main-content-wrapper clearfix">
    <a id="main-content"></a>
    <?php print render($tabs); ?>
    <?php print $messages; ?>
    <?php print render($page['help']); ?>

    <div class="content" role="main">
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
      <?php print $feed_icons; ?>
    </div>
  </div>

    <footer class="footer type--centred type--white" role="contentinfo">
        <?php print render($page['footer']); ?>
    </footer>