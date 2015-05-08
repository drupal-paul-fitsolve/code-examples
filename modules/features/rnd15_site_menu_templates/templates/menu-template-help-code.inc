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

/**
 * Further help
 * 
 * To add .active, .active trail, .expanded and .menu-[mlid] classes to a list item, you can do this:
 *  <li<?php print drupal_attributes($menu['home']['#li_attributes']) ?>><?php print $menu['home']['#link'] ?></li>
 *
 * Note that the correct .active, .active-trail and .expanded classes have already been added to #link, based on current URL.
 *
 */