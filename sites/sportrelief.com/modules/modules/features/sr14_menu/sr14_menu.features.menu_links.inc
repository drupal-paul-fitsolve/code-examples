<?php
/**
 * @file
 * sr14_menu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function sr14_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:<front>
  $menu_links['main-menu:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: main-menu:node/15
  $menu_links['main-menu:node/15'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/15',
    'router_path' => 'node/%',
    'link_title' => 'Schools',
    'options' => array(
      'minipanel' => 'schools_menu_hover',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -46,
  );
  // Exported menu link: main-menu:node/2
  $menu_links['main-menu:node/2'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/2',
    'router_path' => 'node/%',
    'link_title' => 'Fundraising Ideas, Tips and Tools',
    'options' => array(
      'minipanel' => '',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'parent_path' => 'node/374',
  );
  // Exported menu link: main-menu:node/23
  $menu_links['main-menu:node/23'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/23',
    'router_path' => 'node/%',
    'link_title' => 'What we do',
    'options' => array(
      'minipanel' => '',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -40,
  );
  // Exported menu link: main-menu:node/27
  $menu_links['main-menu:node/27'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/27',
    'router_path' => 'node/%',
    'link_title' => 'Events',
    'options' => array(
      'minipanel' => 'events_menu_hover',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -48,
  );
  // Exported menu link: main-menu:node/28
  $menu_links['main-menu:node/28'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/28',
    'router_path' => 'node/%',
    'link_title' => 'The Swimathon',
    'options' => array(
      'minipanel' => '',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'parent_path' => 'node/27',
  );
  // Exported menu link: main-menu:node/29
  $menu_links['main-menu:node/29'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/29',
    'router_path' => 'node/%',
    'link_title' => 'The Cycle',
    'options' => array(
      'minipanel' => '',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'parent_path' => 'node/27',
  );
  // Exported menu link: main-menu:node/30
  $menu_links['main-menu:node/30'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/30',
    'router_path' => 'node/%',
    'link_title' => 'The Mile',
    'options' => array(
      'minipanel' => '',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'parent_path' => 'node/27',
  );
  // Exported menu link: main-menu:node/35
  $menu_links['main-menu:node/35'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/35',
    'router_path' => 'node/%',
    'link_title' => 'Queen Elizabeth Olympic Park',
    'options' => array(
      'minipanel' => '',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'parent_path' => 'node/27',
  );
  // Exported menu link: main-menu:node/39
  $menu_links['main-menu:node/39'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/39',
    'router_path' => 'node/%',
    'link_title' => 'Primary Schools',
    'options' => array(
      'minipanel' => '',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'parent_path' => 'node/15',
  );
  // Exported menu link: main-menu:node/42
  $menu_links['main-menu:node/42'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/42',
    'router_path' => 'node/%',
    'link_title' => 'Secondary Schools',
    'options' => array(
      'minipanel' => '',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'parent_path' => 'node/15',
  );
  // Exported menu link: main-menu:node/46
  $menu_links['main-menu:node/46'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/46',
    'router_path' => 'node/%',
    'link_title' => 'Enter Now',
    'options' => array(
      'minipanel' => '',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
  );
  // Exported menu link: main-menu:node/49
  $menu_links['main-menu:node/49'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/49',
    'router_path' => 'node/%',
    'link_title' => 'Become a call centre',
    'options' => array(
      'minipanel' => '',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'parent_path' => 'node/51',
  );
  // Exported menu link: main-menu:node/50
  $menu_links['main-menu:node/50'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/50',
    'router_path' => 'node/%',
    'link_title' => 'Nurseries',
    'options' => array(),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'parent_path' => 'node/15',
  );
  // Exported menu link: main-menu:node/51
  $menu_links['main-menu:node/51'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/51',
    'router_path' => 'node/%',
    'link_title' => 'Support Sport Relief',
    'options' => array(
      'minipanel' => 'support_menu_hover',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -42,
  );
  // Exported menu link: main-menu:node/56
  $menu_links['main-menu:node/56'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/56',
    'router_path' => 'node/%',
    'link_title' => 'Organise a Mile',
    'options' => array(
      'minipanel' => '',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'parent_path' => 'node/51',
  );
  // Exported menu link: main-menu:partners
  $menu_links['main-menu:partners'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'partners',
    'router_path' => 'partners',
    'link_title' => 'Partners',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'node/51',
  );
  // Exported menu link: menu-footer-menu:http://www.comicrelief.com/jobs
  $menu_links['menu-footer-menu:http://www.comicrelief.com/jobs'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'http://www.comicrelief.com/jobs',
    'router_path' => '',
    'link_title' => 'Jobs',
    'options' => array(
      'minipanel' => '',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -39,
  );
  // Exported menu link: menu-footer-menu:node/38
  $menu_links['menu-footer-menu:node/38'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/38',
    'router_path' => 'node/%',
    'link_title' => 'FAQs',
    'options' => array(
      'minipanel' => '',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
  );
  // Exported menu link: menu-footer-menu:node/45
  $menu_links['menu-footer-menu:node/45'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/45',
    'router_path' => 'node/%',
    'link_title' => 'Legal',
    'options' => array(
      'minipanel' => '',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
  );
  // Exported menu link: menu-footer-menu:node/47
  $menu_links['menu-footer-menu:node/47'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/47',
    'router_path' => 'node/%',
    'link_title' => 'Privacy policy',
    'options' => array(
      'minipanel' => '',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
  );
  // Exported menu link: menu-footer-menu:node/49
  $menu_links['menu-footer-menu:node/49'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/49',
    'router_path' => 'node/%',
    'link_title' => 'Call centres',
    'options' => array(
      'minipanel' => '',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
  );
  // Exported menu link: menu-footer-menu:node/52
  $menu_links['menu-footer-menu:node/52'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/52',
    'router_path' => 'node/%',
    'link_title' => 'Partners',
    'options' => array(
      'minipanel' => '',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
  );
  // Exported menu link: menu-footer-menu:node/53
  $menu_links['menu-footer-menu:node/53'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/53',
    'router_path' => 'node/%',
    'link_title' => 'Contact us',
    'options' => array(
      'minipanel' => '',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
  );
  // Exported menu link: menu-footer-menu:node/56
  $menu_links['menu-footer-menu:node/56'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/56',
    'router_path' => 'node/%',
    'link_title' => 'Organise a Mile',
    'options' => array(
      'minipanel' => '',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: menu-footer-menu:node/57
  $menu_links['menu-footer-menu:node/57'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/57',
    'router_path' => 'node/%',
    'link_title' => 'Accessibility',
    'options' => array(
      'minipanel' => '',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
  );
  // Exported menu link: menu-footer-menu:node/58
  $menu_links['menu-footer-menu:node/58'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/58',
    'router_path' => 'node/%',
    'link_title' => 'Media centre',
    'options' => array(
      'minipanel' => '',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
  );
  // Exported menu link: menu-footer-menu:sitemap
  $menu_links['menu-footer-menu:sitemap'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'sitemap',
    'router_path' => 'sitemap',
    'link_title' => 'Sitemap',
    'options' => array(
      'minipanel' => '',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -40,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Accessibility');
  t('Become a call centre');
  t('Call centres');
  t('Contact us');
  t('Enter Now');
  t('Events');
  t('FAQs');
  t('Fundraising Ideas, Tips and Tools');
  t('Home');
  t('Jobs');
  t('Legal');
  t('Media centre');
  t('Nurseries');
  t('Organise a Mile');
  t('Partners');
  t('Primary Schools');
  t('Privacy policy');
  t('Queen Elizabeth Olympic Park');
  t('Schools');
  t('Secondary Schools');
  t('Sitemap');
  t('Support Sport Relief');
  t('The Cycle');
  t('The Mile');
  t('The Swimathon');
  t('What we do');


  return $menu_links;
}
