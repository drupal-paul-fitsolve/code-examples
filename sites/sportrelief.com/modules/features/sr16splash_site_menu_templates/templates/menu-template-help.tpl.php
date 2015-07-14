<p>Menu links are available in your menu template file in the <strong>$menu array</strong>.</p>
<p>The menu link path is used as the key name so a menu link with the path <strong>fun-and-games</strong> is available to your tpl file as <strong>$menu['fun_and_games']['#link']</strong>.</p>
<p>A menu link with a path of <strong>about/contact-us</strong> is available to your tpl file as <strong>$menu['about_contact_us']['#link']</strong></p>
<p></p>
<p>Demonstrating this further, to template a menu whose tree looks like this:</p>
<ul>
  <li><strong>Home</strong> (/)</li>
  <li><strong>Schools</strong> (schools)
    <ul>
      <li><strong>Fun & Games</strong> (schools/fun-and-games)</li>
      <li><strong>Information for Parents</strong> (schools/parents)</li>
      <li><strong>Information for Teachers</strong> (schools/teachers)</li>
    </ul>
  </li>
  <li><strong>News</strong> (news)</li>
  <li><strong>Media Centre</strong> (media-centre) 
    <ul>
      <li><strong>Pictures</strong> (media-centre/pictures)</li>
      <li><strong>Videos</strong> (media-centre/videos)</li>
      <li><strong>Press Releases</strong> (media-centre/press-releases)</li>
    </ul>
  </li>
</ul>
<p>...you would do this in your menu-template--[menu-template-block-name].tpl.php:</p>
<pre>  
  <?php print check_plain(file_get_contents(drupal_get_path('module', 'sr16splash_site_menu_templates') . '/templates/menu-template-help-code.inc')) ?>
</pre>