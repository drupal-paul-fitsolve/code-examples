(function ($) {

  /**
   * Behaviour for the sr16splash Site Tabs
   *
   * Author: Andy E. Phipps
   * Contributors: -
   * 
   * Last update: 11th September 2014
   * 
   * Description & additional notes:
   *
   * - Sets up the sr16splash_site_tabs produced markup to work with the History JS plug-in,
   *   allowing URL-based switching between tabbed content, as well as smooth scrolling
   *   to any named anchors sitting withing that content.
   * 
   * - Expected URL form is pagename#/tab-name, or 'pagename#/tab-name/anchorname' 
   *
   */
  Drupal.behaviors.sr16splashTabs = {

    defaults : {
      tabsWrapperClass: '.tabs__wrapper',
      tabsContentWrapperClass: '.tabs__content__wrapper',
      tabsListClass: '.tabs__list',
      tabActiveClass: '.active',

      $tabs : null,
      $currentTabsWrapper : null,
      $currentTab : null,
      $tabs_list : null,

      // To prevent scroll to initial default tab content on load (on xs breakpoint)
      firstTab: true
    },

    /*
     * Attaches the sr16splash Tabs Behaviour
     */
    attach: function (context, settings) {

      var _base = Drupal.behaviors.sr16splashTabs;

      // Handle settings
      var default_settings = Drupal.settings.sr16splashTabs ? Drupal.settings.sr16splashTabs : {};
      Drupal.settings.sr16splashTabs = $.extend(default_settings, _base.defaults);

      var _settings = Drupal.settings.sr16splashTabs;

      // Setup the Tabs, passing in the relevant context
      // Once ensures it runs once
      $(_settings.tabsWrapperClass, context).once('sr16splashTabs', _base.setupTabs);
    },

    /*
     * The main function to setup Tabs
     * this = the rabs wrapper once was applied on above on line 44
     */
    setupTabs: function() {
      var _base = Drupal.behaviors.sr16splashTabs;
      var _settings = Drupal.settings.sr16splashTabs;

      // Setup and cache the variables we require
      $currentTabsWrapper = $(this);
      $tabs = $(_settings.tabsContentWrapperClass, $currentTabsWrapper).children();
      $currentTab = $('a[data-tab="'+_settings.default_tab+'"]', $currentTabsWrapper);

      // Hides all tabs before showing selected one upon page load
      $tabs.hide(0);
      
      // _settings.default_tab provided by Drupal JS and the Panels Plugin
      _settings.currentTab = $currentTab.attr('href').substring(2);
      $.History.bind(_base.handleHistoryJS);
      $.History.trigger();
    },

    /*
     * The main history JS handler
     * State = string of the current state
     */
    handleHistoryJS: function(state) {

      var _base = Drupal.behaviors.sr16splashTabs;
      var _settings = Drupal.settings.sr16splashTabs;

      //split up URL 'state' - expected format 'pagename#/tabname/anchorname'
      stateArray = state.split('/');

      stateTab = typeof state[1] !== 'undefined' ? stateArray[1] : false;

      // Set the current tab
      if(stateTab) {
        _settings.currentTab = stateTab;
      }

      // Hides all tabs before showing selected tab
      $tabs = $(_settings.tabsContentWrapperClass, $currentTabsWrapper).children();
      $tabs.hide(0);

      // Update the menu to the current tab
      _base.updateTabMenu(_settings.currentTab);

      // Show selected tab && scroll to anchor if stipulated in url
      $('#'+_settings.currentTab).stop(true,true).fadeIn(300, function(){
        _base.loadAnchorFromState(state);
      });

    },

    /*
     * Loads an Anchor from a HistoryJs state
     * state can be an Array or String
     */
    loadAnchorFromState: function(state) {
      var _base = Drupal.behaviors.sr16splashTabs;

      // Turn the state var into an array if we have to
      var stateArray = typeof state !== 'Array' ? state.split('/') : state;

      // Get the state anchor
      var stateAnchor = stateArray[2];

      // Let's scroll to it, if it doesn't exist, the function will handle it for us
      // as it would pass in 'undefined'
      _base.scrollToAnchor(stateAnchor);
    },

    /*
     * Updates the tab menu
     */
    updateTabMenu: function(state){
      var _base = Drupal.behaviors.sr16splashTabs;
      var _settings = Drupal.settings.sr16splashTabs;
      $tabs_list = $(_settings.tabsListClass);

      // Add active class to 'state' button, remove class from other buttons
      $tabs_list
        .children('li:has(a[href="#/'+state+'"])')
        .addClass(_settings.tabActiveClass.substr(1))
        .siblings(_settings.tabActiveClass)
        .removeClass(_settings.tabActiveClass.substr(1));
        
      // Scroll to content only on xs breakpoint
      if (Drupal.settings.crl2.breakpointActive === 'xs' && _settings.firstTab === false) {
        _base.scrollToAnchor(state);
      }
    },

    /*
     * Helper Function to Scroll to an Anchor
     */
    scrollToAnchor: function(el){
      var _settings = Drupal.settings.sr16splashTabs;
      _settings.firstTab = false;

      if (typeof el !== 'undefined') {
        setTimeout(function(){
          $('html, body').animate({
            'scrollTop': $('#'+el).offset().top - 50},500);
        },500);
      }
    }
  };
})(jQuery);