<?php print $doctype; ?>
<!--[if lt IE 7]>      <html class="ie ie6" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf->version . $rdf->namespaces; ?>> <![endif]-->
<!--[if IE 7]>         <html class="ie ie7" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf->version . $rdf->namespaces; ?>> <![endif]-->
<!--[if IE 8]>         <html class="ie ie8" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf->version . $rdf->namespaces; ?>> <![endif]-->
<!--[if gt IE 8]><!--> <html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf->version . $rdf->namespaces; ?>> <!--<![endif]-->
<head<?php print $rdf->profile; ?>>
  <?php print $head; ?>
  <meta name="google-site-verification" content="8w3i7lnjr_hEaeKEpsqrhNrLY6-u5iKi6I9azSTN0ww" />
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>

  <!-- Facebook Conversion Code for conversions pixel on fb -->
  <script type='text/javascript'>
    var fb_param = {};
    fb_param.pixel_id = '6014007043200';
    fb_param.value = '0.00';
    fb_param.currency = 'GBP';
    (function()
    { var fpw = document.createElement('script'); fpw.async = true; fpw.src = '//connect.facebook.net/en_US/fp.js'; var ref = document.getElementsByTagName('script')[0]; ref.parentNode.insertBefore(fpw, ref); }
    )();
  </script>
  <noscript><img height='1' width='1' alt='' style='display:none' src='https://www.facebook.com/offsite_event.php?id=6014007043200&value=0&currency=GBP'/></noscript>
  
  <!--[if lt IE 9]><script src="//html5shiv.googlecode.com/svn/trunk/html5.js"></script><![endif]-->
</head>
<body<?php print $attributes;?>>
  <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>
</html>