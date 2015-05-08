<?php

class Rnd15SiteMenuTemplates extends BeanPlugin {
  public function values() {
    $values = array(
      'menu_name' => 'main-menu',
    );

    return $values;
  }

/**
 * Build the Form for Bean settings
 */
  public function form($bean, $form, &$form_state) {
    $menus = menu_get_menus();
    $form['menu_name'] = array(
      '#type' => 'select',
      '#title' => t('Menu'),
      '#description' => t('Select the menu to render through a template file.'),
      '#default_value' => $bean->menu_name,
      '#options' => $menus,
    );

    $form['help'] = array(
      '#type' => 'fieldset',
      '#title' => t('Theming help'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
  
    $form['help']['help'] = array(
        '#markup' => theme('menu_template_help'),
    );

    $form['#attached']['js'] = array(
      drupal_get_path('module', 'rnd15_site_menu_templates') . '/js/rnd15_site_menu_templates.js',
    );

    return $form;
  }

/**
 * Outputs the Bean instance.
 *
 * Essentially, build the menu, flatten the array and pass each variable to the
 * required tpl file.
 */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    $menuName = $bean->menu_name;
    $label = strtolower(preg_replace(array(
      '/[^a-zA-Z0-9]+/',
      '/-+/',
      '/^-+/',
      '/-+$/',
    ), array('-', '-', '', ''), $bean->label));

    $themeFile = 'menu-template--' . $label;

    // Load the full menu
    $menuTreeData = menu_tree_all_data($menuName);

    // Have to add active trail classes here as menu_tree_all_data doesn't add them :(
    _rnd15_site_menu_templates_add_active_trail($menuTreeData);

    // Prepare the $menuTreeData array.
    $menu = array();
    $menu = _rnd15_site_menu_templates_prepare_menu_vars($menuTreeData, $menu);

    // Theme the menu via the .tpl file, passing the $menu array
    return theme(str_replace('-', '_', $themeFile), array('menu' => $menu));
  }

}