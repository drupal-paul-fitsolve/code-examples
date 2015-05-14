(function ($) {

  /**
   * Behaviour for the sr16splash Touch Navigation
   *
   * Author: J.Pitt
   * Contributors: -
   * 
   * Last update: 31st August 2014
   * 
   * Description & additional notes:
   *
   * - Checks if the device is touch or matches a certain breakpoint and provides a touch interface.
   * - The styling is modified by adding the 'mainNavTouchClass' class to the nav.
   * - Advanced debug mode to test the touch navigation across pages.
   * -- Debug mode can be enabled/disabled by setting ?touch=true or ?touch=false in the URL
   * -- The debug mode is stored in a cookie and therefore persistent, setting the above var to 
   *    false will delete it.
   * - The only performance hit in this script is that it loops through all menus and 
   *   stores the max-heigh value for clean CSS transitions. This is done via the 
   *   refreshMenuAttributes function.
   * - The touch menu is triggered on XS and SM Breakpoints.
   * - This script relies on:
   * -- Modernizr
   * -- CRL2 Breakpoints
   */
  Drupal.settings.sr16splashtouchMenu = Drupal.settings.sr16splashtouchMenu || {};

  Drupal.behaviors.sr16splashtouchMenu = {

    defaults : {
      mainNavClass : 'nav.nav.collapsible',
      toggleButtonClass : 'button.button-nav--toggle',
      mainNavTouchClass : 'nav--touch',
      expandedOpenClass : 'open',
      transitionDurationPer100px : 40,

      touchNavBreakpoint : '(max-width: 1149px)',
      noneTouchNavBreakpoint : '(min-width: 1150px)',

      $navSite : null,

      $toggleButton : null,
      
      $menus : null,
      $primaryNav : null,
      $primaryNavListItems : null,
      $primaryNavListItemsExpanded : null,
      $primaryNavLinkExpanded : null,

      $secondaryNav: null,

      navCollapsed : true,
      isLtIe9 : false,
      isDebug : false
    },

    attach: function (context, settings) {
      var _base = Drupal.behaviors.sr16splashtouchMenu;

      // Setup the menu, passing in the relevant context
      $(_base.defaults.mainNavClass, context).once('sr16splashtouchMenu', function(){
        // Extend the current behaviour with default values
        Drupal.settings.sr16splashtouchMenu = $.extend({}, Drupal.settings.sr16splashtouchMenu, _base.defaults);

        // Setup the menu
        _base.setupTouchMenu(context);
      });
    },

    /**
     * Sets up the touch menu
     *
     * - Declares the menu wide objects required and caches them
     * - Enables responsive touch so the menu works from non-touch to touch and vice versa
     * - Provides a debug mode (append ?touch=true/false to test the menu)
     * - Checks if we are on a touch device OR on XS/SM breakpoint
     * - Sets up the menu with some data attributes so we can nicely animate it
     * - 
     * @param  {[type]} context [description]
     * @return {[type]}         [description]
     */
    setupTouchMenu : function(context) {
      var _base = Drupal.behaviors.sr16splashtouchMenu;
      var _settings = Drupal.settings.sr16splashtouchMenu;

      // Skip lower than ie9 browsers
      _base.isLtIe9 = $('html',context).hasClass('lt-ie9');
      if(_base.isLtIe9) return;

      /**
       * Cache JS & jQuery Objects we require
       */
      _settings.$navSite = $(_settings.mainNavClass, context);
      _settings.$menus = $('ul.menu', _settings.$navSite);
      _settings.$toggleButton = $(_settings.toggleButtonClass, _settings.$navSite);
      // Primary nav elements
      _settings.$primaryNav = $('> ul.menu', _settings.$navSite);
      _settings.$primaryNavListItems = $('> li', _settings.$primaryNav);
      _settings.$primaryNavListItemsExpanded = $('li.expanded', _settings.$primaryNav);
      _settings.$primaryNavLinkExpanded = $('> a', _settings.$primaryNavListItemsExpanded);
      // Secondary nav elements
      _settings.$secondaryNav = $('> ul.menu', _settings.$primaryNavListItemsExpanded);

      /**
       * We have to handle debugging, especially for non-touch devices
       *
       * The debugging can be turned on by appending the URL which sets a persistent cookie
       * www.rednoseday.com/?touch=true > Turns on touch and sets the cookie
       * www.rednoseday.com/?touch=false > Deletes cookied and sets debugging to false
       */
      _settings.isDebug = _base.checkDebugMode();
      // Further debug handling.
      if(_settings.isDebug) {
        _settings.isTouch = true;
        _settings.$navSite.addClass(_settings.mainNavTouchClass);
        $('html').addClass('touch').removeClass('no-touch');
      }

      /** 
       * Responsive Touch is an exception
       * It's to ensure that if we are on a non touch device
       * the nav falls back to touch on < md breakpoints
       */
      _base.responsiveTouch();

      /**
       * Attach event handlers and process the menu
       */
      // Add clas to nav so we know it's touch
      if(_settings.isTouch) {
        _settings.$navSite.not('.' + _settings.mainNavTouchClass).addClass(_settings.mainNavTouchClass);
      }

      // Save the attributes of every menu
      _base.refreshMenuAttributes();

      // Apply event handler on main toggle button
      _settings.$toggleButton.on('click', _base.EH_toggleNav);

      // Apply event handler for secondary and tertiary menus
      _settings.$primaryNavLinkExpanded.on('click', _base.EH_handleSubNav);
    },

    /**
     * Menu Toggle Event handler
     * 
     * Handles the main toggle button functionality
     * @param {Objects} e event handler object
     */
    EH_toggleNav : function(e, eventParam) {
      var _base = Drupal.behaviors.sr16splashtouchMenu;
      var _settings = Drupal.settings.sr16splashtouchMenu;

      // Set the nav collapsed status
      _settings.navCollapsed = _settings.$navSite.hasClass('collapsed');

      // Handle height to allow the sliding of the menu
      var menuMaxHeight = _settings.navCollapsed ? _settings.$primaryNav.data('menu-height') : 0;

      // Toggle the class on the nav site element
      _settings.$navSite.toggleClass('collapsed');

      // Toggle the class on the toggle button
      _settings.$toggleButton.toggleClass('active');

      // Close all open secondary navs
      if(!_settings.navCollapsed) _base.closeAllSecondaryMenus(null);

      // Remove blur from button on close
      if(!_settings.navCollapsed) _settings.$toggleButton.trigger('blur');

      // Set CSS properties in the right order
      _settings.$primaryNav.css({
        // First set the transition
        '-webkit-transition-duration' : _settings.$primaryNav.data('menu-transition-duration'),
        'transition-duration' : _settings.$primaryNav.data('menu-transition-duration'),
        // Then set the menu height and overflow
        'max-height' : menuMaxHeight,
        'overflow' : 'hidden'
      });

      // Close existing nav buttons if it's a genuine click
      if(eventParam !== 'closeAll')  _base.closeNavButtons.apply(_settings.$toggleButton);
    },

    /**
     * Flexible navigation handler
     */
    EH_handleSubNav: function(e) {
      var _base = Drupal.behaviors.sr16splashtouchMenu;
      var _settings = Drupal.settings.sr16splashtouchMenu;

      // We want to specifically skip this shiz if we're not using touch
      if(!_settings.isTouch) return;

      // Prevent click...
      e.preventDefault();

      // Set vars needed to handle the navigation
      var $currentPrimaryNav = $(this).parent('li.expanded');
      var $currentSecondaryNav = $('> ul.menu', $currentPrimaryNav);

      // This is where toggle between open and closed using max-height
      var navOpen = $currentSecondaryNav.hasClass(_settings.expandedOpenClass);

      var navMaxHeightToggle = navOpen ? 0 : $currentSecondaryNav.data('menu-height');

      $currentSecondaryNav.css({
        // Set the transition duration
        '-webkit-transition-duration' : $currentSecondaryNav.data('menu-transition-duration'),
        'transition-duration' : $currentSecondaryNav.data('menu-transition-duration'),
        // Animate the sub menu
        'max-height': navMaxHeightToggle
      });

      // Parent menus require max-height to close menu
      // We are just using an arbitrary number which is taller than all menus open
      $currentSecondaryNav
        .parents('ul.menu').css({
          'max-height' : 1400
        });

      // Set the open class on the nav
      $currentSecondaryNav.toggleClass(_settings.expandedOpenClass);

      // Close all non active menus
      var $activeTrail = $currentSecondaryNav.parents('.' + _settings.expandedOpenClass).andSelf();
      _base.closeAllSecondaryMenus($activeTrail);
    },

    /*
     * Responsive Touch
     * Uses enquire js to trigger the touch menu on breakpoint < MD
     */
    responsiveTouch: function() {
      var _base = Drupal.behaviors.sr16splashtouchMenu;
      var _settings = Drupal.settings.sr16splashtouchMenu;

      // We use the exception handler in case enquire.js is not available
      try {
        // Attach enquire JS events
        enquire
          .register(_settings.touchNavBreakpoint, {
            unmatch : _base.refreshMenuAttributes
          })
          .register(_settings.noneTouchNavBreakpoint, {
            match: _base.touchNavOff,
            unmatch: _base.touchNavOn
          }, true);
      }
      catch(err) {
        // Output the error
        if (window.console) {
          console.log(err);
        }
      }
    },

    /*
     * Helper function
     * For a smooth transition, calculates the transition 
     * duration based on number of li elements
     */
    calculateTransitionDuration: function(h) {
      var _settings = Drupal.settings.sr16splashtouchMenu;
      return ((100 / _settings.transitionDurationPer100px) * h);
    },

    /*
     * Refresh the menu attributes
     * - Loops through all ul.menus and... 
     * -- Saves the max height which we can animate to
     */
    refreshMenuAttributes: function() {
      var _base = Drupal.behaviors.sr16splashtouchMenu;
      var _settings = Drupal.settings.sr16splashtouchMenu;

      _settings.$toggleButton.removeClass('active');
      _settings.$menus.each(_base._menuStoreAttributes);
      _settings.navCollapsed = false;
      _settings.$navSite.not('.collapsed').addClass('collapsed');
      _base.closeAllSecondaryMenus();
    },

    /**
     * Helper function
     * - Sets the menus max height as a data attribute for future use
     * - Sets the transition duration for future use
     */
    _menuStoreAttributes: function(i, k){
      var _base = Drupal.behaviors.sr16splashtouchMenu;
      var _settings = Drupal.settings.sr16splashtouchMenu;

      var $elem = $(this);
      
      // Hide and set max height to 0 so we can get the real height
      $elem
        .css({
          'visibility': 'hidden',
          'max-height': 'none'
        });

      //var height = $elem.outerHeight();
      var h = ($elem.prop('scrollHeight'), $elem.outerHeight(), $elem.height());
      var height = Math.max($elem.prop('scrollHeight'));
      var transitionDuration = _base.calculateTransitionDuration(height);
      // Save the atributes and restore the menu
      $elem
        // Save data attribs
        .data('menu-height', height)
        .data('menu-transition-duration', transitionDuration);
      

      //  // Revert styling
      $elem.css({
          'max-height': _settings.isTouch ? 0 : 'none',
          'visibility': 'visible'
        });
    },

    /**
     * Helper function
     * Closes all open menu items, can pass in an exception 
     * e.g. for the active menu
     */
    closeAllSecondaryMenus: function($not){
      var _base = Drupal.behaviors.sr16splashtouchMenu;
      var _settings = Drupal.settings.sr16splashtouchMenu;

      // Close all other menu items
      _settings.$menus
        .filter('.'+_settings.expandedOpenClass)
        .not($not)
        .removeClass(_settings.expandedOpenClass)
        .css({
          'max-height' : 0
        });
    },

    /**
     * Turn touch on and off
     */
    touchNavOn: function() {
      var _base = Drupal.behaviors.sr16splashtouchMenu;
      var _settings = Drupal.settings.sr16splashtouchMenu;

      if(!_settings.isTouch && !_settings.isDebug) {
        _settings.$navSite.addClass(_settings.mainNavTouchClass);
        _settings.$primaryNav.css({'overflow':'hidden', 'max-height':'0'});
        _settings.$secondaryNav.css({'overflow':'hidden', 'max-height':'0'});
        _settings.isTouch = true;
      }
      _base.refreshMenuAttributes();
    },
    touchNavOff: function() {
      var _base = Drupal.behaviors.sr16splashtouchMenu;
      var _settings = Drupal.settings.sr16splashtouchMenu;
      if(!_settings.isTouchDevice && !_settings.isDebug) {
        _settings.$navSite.removeClass(_settings.mainNavTouchClass);
        _settings.$primaryNav.css({'overflow':'visible', 'max-height':'none'});
        _settings.$secondaryNav.css({'overflow':'visible', 'max-height':'none'});
        _settings.isTouch = false;
      }
    },

    /*
     * Checks debug mode is on from cookie
     */
    checkDebugMode: function(){
      var toggleDebug = $.getUrlVar('touch');
      if(toggleDebug && typeof $.cookie !== 'undefined') {
        $.cookie('sr16splashtouchMenuDebug', toggleDebug, { expires: 1, path: '/'});
        if(toggleDebug === 'false') {
          // Deletes the cookie
          $.cookie('sr16splashtouchMenuDebug', null, { expires: 1, path: '/' });
        }
      }
      return (typeof $.cookie !== 'undefined') ? ($.cookie('sr16splashtouchMenuDebug') === 'true') : false;
    },

    /*
     * Close All Nav Buttons
     *
     * Also used by external scripts so you can close this one when another
     * nav button opens
     * To use this function run it as such:
     * Drupal.behaviors.sr16splashtouchMenu.closeNavButtons.apply($(navButton));
     */
    closeNavButtons: function(){
      // Use this to get the current button
      $currentNavButton = $(this);

      // Trigger click to close all active buttons
      // Pass in extra parameter so we can differentiate a faux and a real click event
      $(this)
        .siblings('.active')
        .trigger('click', ['closeAll']);
    },

    /**
     * Gets executed before attach behavior to ensure the touch menu is instantly setup
     */
    fastTouchDetect: function() {
      var _base = Drupal.behaviors.sr16splashtouchMenu;
      var _settings = Drupal.settings.sr16splashtouchMenu;

      // Because we want to be QUICK and not wait for jQuery OR Drupal Attach behaviors
      _settings.isTouch = _settings.isTouchDevice = (typeof Modernizr !== 'undefined') && Modernizr.touch;

      // If we have match media on a non touch, let's check the window width!
      if((typeof window.matchMedia !== 'undefined') && !_settings.isTouch) {
        var matchQueryObject = window.matchMedia(_base.defaults.touchNavBreakpoint);
        _settings.isTouch = matchQueryObject.matches;
        _settings.matchesTouchNavBreakpoint = matchQueryObject.matches;
      }

      // If is touch, let's add the nav touch class NOW!
      if(_settings.isTouch) {
        var nav = document.querySelector(_base.defaults.mainNavClass);
        nav.className = nav.className + " nav--touch";
      }
    }
  };

  // Helper function to get param from URL
  // https://gist.github.com/varemenos/2531765
  $.getUrlVar = function(key){
    var result = new RegExp(key + "=([^&]*)", "i").exec(window.location.search);
    return result && unescape(result[1]) || "";
  };

  // Because... FLASH!!! - a-ah - saviour of the universe. Flash - a-ah - he'll save everyone of us ...
  Drupal.behaviors.sr16splashtouchMenu.fastTouchDetect();

})(jQuery, window);