<?php
/**
 * @file
 * sr14_menu.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sr14_menu_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'share';
  $context->description = 'Share links placed above the footer.';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'news_article' => 'news_article',
        'panel' => 'panel',
        'video' => 'video',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'node/*' => 'node/*',
        '~node/*/edit' => '~node/*/edit',
        '~donate' => '~donate',
        '~donate/*' => '~donate/*',
        '~giftaid' => '~giftaid',
        '~giftaid/*' => '~giftaid/*',
        '~pay-in-fundraising-money' => '~pay-in-fundraising-money',
        '~pay-in-fundraising-money/*' => '~pay-in-fundraising-money/*',
        '~play-games' => '~play-games',
        '~play-games/*' => '~play-games/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'cr_general-share' => array(
          'module' => 'cr_general',
          'delta' => 'share',
          'region' => 'footer_social',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Share links placed above the footer.');
  $export['share'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sport_relief_general';
  $context->description = '';
  $context->tag = 'Header and footer';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*' => '*',
        '~donate' => '~donate',
        '~donate/*' => '~donate/*',
        '~giftaid' => '~giftaid',
        '~giftaid/*' => '~giftaid/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'delta_blocks-messages' => array(
          'module' => 'delta_blocks',
          'delta' => 'messages',
          'region' => 'content',
          'weight' => '-10',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'header_first',
          'weight' => '-10',
        ),
        'block-2' => array(
          'module' => 'block',
          'delta' => '2',
          'region' => 'header_second',
          'weight' => '-10',
        ),
        'block-6' => array(
          'module' => 'block',
          'delta' => '6',
          'region' => 'header_second',
          'weight' => '-9',
        ),
        'boxes-search_header' => array(
          'module' => 'boxes',
          'delta' => 'search_header',
          'region' => 'header_second',
          'weight' => '-8',
        ),
        'boxes-user_menu' => array(
          'module' => 'boxes',
          'delta' => 'user_menu',
          'region' => 'header_second',
          'weight' => '-7',
        ),
        'cr_marketing_prefs-esu_header' => array(
          'module' => 'cr_marketing_prefs',
          'delta' => 'esu_header',
          'region' => 'header_second',
          'weight' => '-6',
        ),
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'menu',
          'weight' => '-10',
        ),
        'panels_mini-event_info_menu_hover' => array(
          'module' => 'panels_mini',
          'delta' => 'event_info_menu_hover',
          'region' => 'megamenu',
          'weight' => '-10',
        ),
        'panels_mini-schools_menu_hover' => array(
          'module' => 'panels_mini',
          'delta' => 'schools_menu_hover',
          'region' => 'megamenu',
          'weight' => '-9',
        ),
        'panels_mini-fundraise_info_menu' => array(
          'module' => 'panels_mini',
          'delta' => 'fundraise_info_menu',
          'region' => 'megamenu',
          'weight' => '-8',
        ),
        'panels_mini-support_menu_hover' => array(
          'module' => 'panels_mini',
          'delta' => 'support_menu_hover',
          'region' => 'megamenu',
          'weight' => '-7',
        ),
        'panels_mini-sponsor_menu_hover' => array(
          'module' => 'panels_mini',
          'delta' => 'sponsor_menu_hover',
          'region' => 'megamenu',
          'weight' => '-6',
        ),
        'panels_mini-play_games_menu_hover' => array(
          'module' => 'panels_mini',
          'delta' => 'play_games_menu_hover',
          'region' => 'megamenu',
          'weight' => '-5',
        ),
        'panels_mini-latest_menu_hover' => array(
          'module' => 'panels_mini',
          'delta' => 'latest_menu_hover',
          'region' => 'megamenu',
          'weight' => '-4',
        ),
        'panels_mini-events_menu_hover' => array(
          'module' => 'panels_mini',
          'delta' => 'events_menu_hover',
          'region' => 'megamenu',
          'weight' => '-3',
        ),
        'delta_blocks-breadcrumb' => array(
          'module' => 'delta_blocks',
          'delta' => 'breadcrumb',
          'region' => 'breadcrumb',
          'weight' => '-10',
        ),
        'menu-menu-footer-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-menu',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
        'block-4' => array(
          'module' => 'block',
          'delta' => '4',
          'region' => 'footer_first',
          'weight' => '-9',
        ),
        'block-5' => array(
          'module' => 'block',
          'delta' => '5',
          'region' => 'footer_first',
          'weight' => '-8',
        ),
        'block-3' => array(
          'module' => 'block',
          'delta' => '3',
          'region' => 'footer_first',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Header and footer');
  $export['sport_relief_general'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sport_relief_simple_nav';
  $context->description = '';
  $context->tag = 'Header and footer';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'donate' => 'donate',
        'donate/*' => 'donate/*',
        'giftaid' => 'giftaid',
        'giftaid/*' => 'giftaid/*',
        'pay-in-fundraising-money' => 'pay-in-fundraising-money',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'delta_blocks-messages' => array(
          'module' => 'delta_blocks',
          'delta' => 'messages',
          'region' => 'content',
          'weight' => '-10',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'header_first',
          'weight' => '-10',
        ),
        'boxes-global_simple_nav' => array(
          'module' => 'boxes',
          'delta' => 'global_simple_nav',
          'region' => 'header_second',
          'weight' => '-10',
        ),
        'menu-menu-footer-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-menu',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
        'block-4' => array(
          'module' => 'block',
          'delta' => '4',
          'region' => 'footer_first',
          'weight' => '-9',
        ),
        'block-5' => array(
          'module' => 'block',
          'delta' => '5',
          'region' => 'footer_first',
          'weight' => '-8',
        ),
        'block-3' => array(
          'module' => 'block',
          'delta' => '3',
          'region' => 'footer_first',
          'weight' => '-7',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'simple_nav',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Header and footer');
  $export['sport_relief_simple_nav'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ssrg_lockup';
  $context->description = '';
  $context->tag = 'Header and footer';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'enter-sainsburys-sport-relief-games' => 'enter-sainsburys-sport-relief-games',
        'sainsburys-sport-relief-games' => 'sainsburys-sport-relief-games',
        'sainsburys-sport-relief-games-queen-elizabeth-olympic-park' => 'sainsburys-sport-relief-games-queen-elizabeth-olympic-park',
        'sainsburys-sport-relief-mile' => 'sainsburys-sport-relief-mile',
        'sainsburys-sport-relief-swimathon' => 'sainsburys-sport-relief-swimathon',
        'sainsburys-sport-relief-cycle' => 'sainsburys-sport-relief-cycle',
        'organise-sainsburys-sport-relief-mile' => 'organise-sainsburys-sport-relief-mile',
        'enter-now' => 'enter-now',
        'event-info' => 'event-info',
        'event-info/*' => 'event-info/*',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'ssrg',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Header and footer');
  $export['ssrg_lockup'] = $context;

  return $export;
}
