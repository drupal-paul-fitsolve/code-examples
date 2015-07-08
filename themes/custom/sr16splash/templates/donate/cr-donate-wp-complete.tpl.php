<?php
// This output from this rendered template will be shown on the worldpay site
// which will provide the doctype / html element etc
?>

<head>
  <meta http-equiv="refresh" content="1;url='<?php print $refresh_url; ?>'" />
  <meta name="viewport" content="width=device-width, initial-scale=1">
</head>

<style>

  body.container {
    text-align: center;
    background-color:#f5f2ed;
    color: #666;
    font: 12px Arial, Helvetica, sans-serif
  }

  div.banner {
    text-align: left;
    max-width: 730px;
    padding: 70px 20px 20px;
    margin: 0 auto;
    background:url(https://secure.worldpay.com/i/132683/2014_background_top_v2.png) no-repeat center top;
  }

  p.logo {
    margin-top: 10px
  }

  table.bannercontainer {
    margin-left:auto;
    margin-right:auto;
    width:400px;
  }

  p.bannercontainer {
    margin-left:auto;
    margin-right:auto;
    max-width:380px;
  }

</style>

<body class="container">
<p class="logo">
  <a href="http://www.rednoseday.com"><img src="https://secure.worldpay.com/i/25760/2015_logo.png" alt="sr16splash Logo" width="139" height="216" border="0"/></a>
</p>
<div class="banner">
  <wpdisplay item=banner default="">
    <p class="bannercontainer">Redirecting you to <wpdisplay item=MC_domain>.</br>If you are not redirected automatically,</br><a href="<?php print check_plain($refresh_url); ?>">click here</a>.</p>
</div>
</body>