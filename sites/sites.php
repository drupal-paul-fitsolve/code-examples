<?php
if (strpos($_SERVER['HTTP_HOST'], 'rnd15') !== false) {
  $sites[$_SERVER['HTTP_HOST']] = 'rednoseday.com';
}

if (strpos($_SERVER['HTTP_HOST'], 'sr16') !== false) {
  $sites[$_SERVER['HTTP_HOST']] = 'sportrelief.com';
}

if (strpos($_SERVER['HTTP_HOST'], 'cr13') !== false) {
  $sites[$_SERVER['HTTP_HOST']] = 'comicrelief.com';
}

if (strpos($_SERVER['HTTP_HOST'], 'cr-lay') !== false) {
  $sites[$_SERVER['HTTP_HOST']] = 'layout.comicrelief.com';
}

if (strpos($_SERVER['HTTP_HOST'], 'layout') !== false) {
  $sites[$_SERVER['HTTP_HOST']] = 'layout.comicrelief.com';
}
?>
