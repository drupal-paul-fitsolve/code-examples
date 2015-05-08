-- SUMMARY --

The Menu Templates feature allows developers to output a Drupal menu via a template file (.tpl.php) in the default theme.

Developers can also create multiple template files for the same menu. This enables the same menu to be rendered differently in different sections. Switching out of these menu's could be done with the core Drupal blocks UI, or the Context contrib module for example.


-- REQUIREMENTS --

Bean
Block
Menu

Enabling this feature enables these modules if they're not already enabled.


-- INSTALLATION --

Enable the feature 'RND15 Menu Templates' in the RND15 feature group

Note: After enabling the feature, you may need to set the correct Bean permissions.

      - visit admin/people/permissions
      - ensure Administrator has access to:
        - Menu template: Add Bean
        - Menu template: Edit Bean
        - Menu template: View Bean
        - Menu template: Bean Bean


-- HOW TO USE MENU TEMPLATES --

There are two steps involved in creating menu templates

  1) Creating the bean

  2) Creating the template file

Follow the steps below. You'll be menu templating ninja before you know it.


-- CREATING THE BEAN --

  1) Visit Content > Blocks (admin/content/blocks) Click 'Add Block'

  2) Give your menu block a name.

    The Menu template name you enter should read something like this:
     
     - Main Menu - Schools
     - Main Menu - Fun & Game
     - Footer Menu - Kids

     Putting the menu name first will ensure the menu template files in the theme are nicely grouped.

  3) You'll see the exact name for the .tpl file you need appear as you type.

     Copy this file name and create that file in the menu-templates folder in the default theme.

  4) From the drop-down, select the menu you want to template.

  5) Save.

     Note, it's better to create the file before you save this form, as the form submit rebuilds the theme registry.
     If you can't create it at this point, just do a Flush all caches > Theme registry after creating the tpl file in the theme.


-- TEMPLATING --

Menu links are available in your menu template file in the $menu array.

The menu link path is used as the key name so a menu link with the path fun-and-games is available to your tpl file as $menu['fun_and_games']['#link'].

A menu link with a path of about/contact-us is available to your tpl file as $menu['about_contact_us']['#link']

Demonstratng this further, to template a menu whose tree looks like this:

  * Home (/)
  * Schools (schools)
    * Fun & Games (schools/fun-and-games)
    * Information for Parents (schools/parents)
    * Information for Teachers (schools/teachers)
  * News (news)
  * Media Centre (media-centre)
    * Pictures (media-centre/pictures)
    * Videos (media-centre/videos)
    * Press Releases (media-centre/press-releases)

...you would do this in your menu-template--[menu-template-block-name].tpl.php:

  
  <ul>

    <?php if(isset($menu['home']['#link'])): ?>
      <li><?php print $menu['home']['#link'] ?></li>
    <?php endif; ?>

    <?php if(isset($menu['schools']['#link'])): ?>
      <li><?php print $menu['schools']['#link'] ?>
        <ul>
          <?php if(isset($menu['schools_fun_and_games']['#link'])): ?>
            <li><?php print $menu['schools_fun_and_games']['#link'] ?></li>
          <?php endif; ?>
          <?php if(isset($menu['schools_parents']['#link'])): ?>
            <li><?php print $menu['schools_parents']['#link'] ?></li>
          <?php endif; ?>
          <?php if(isset($menu['schools_teachers']['#link'])): ?>
            <li><?php print $menu['schools_teachers']['#link'] ?></li>
          <?php endif; ?>
        </ul>
      </li>
    <?php endif; ?>

    <?php if(isset($menu['news']['#link'])): ?>
      <li><?php print $menu['news']['#link'] ?></li>
    <?php endif; ?>
    
    <?php if(isset($menu['media_centre']['#link'])): ?>
      <li><?php print $menu['media_centre']['#link'] ?>
        <ul>
          <?php if(isset($menu['media_centre_pictures']['#link'])): ?>
            <li><?php print $menu['media_centre_pictures']['#link'] ?></li>
          <?php endif; ?>
          <?php if(isset($menu['media_centre_videos']['#link'])): ?>
            <li><?php print $menu['media_centre_videos']['#link'] ?></li>
          <?php endif; ?>
          <?php if(isset($menu['media_centre_press_releases']['#link'])): ?>
            <li><?php print $menu['media_centre_press_releases']['#link'] ?></li>
          <?php endif; ?>
        </ul>
      </li>
    <?php endif; ?>

  </ul>

Further help:
  
To add .active, .active trail, .expanded and .menu-[mlid] classes to a list item, you can do this:
  <li<?php print drupal_attributes($menu['home']['#li_attributes']) ?>><?php print $menu['home']['#link'] ?></li>
 
Note that the correct .active, .active-trail and .expanded classes have already been added to #link, based on current URL.


-- TROUBLESHOOTING --

* If the menu doesn't display, check the following:

  - Edit the bean. Ensure the name of the template file exists in the theme. Also, visiting Reports > Recent log messages will tell you if Drupal can't find a menu template file it needs.

  - Check that the region you've added this menu to is actually being rendered in the theme layout tpl files.


  -- END --