(function ($) {

  /**
   * Behaviour for the rnd15 Pane Filter
   *
   * Author: Andy E. Phipps & Jeremy Pitt
   * Contributors: -
   * 
   * Last update: 9th January 2015
   * 
   * Description & additional notes:
   *
   *  - Employs the History JS plug-in to switch between panes which use the data-attribute pane
   *    plugin via either supplied buttons or the filter criteria defined in URL.
   *
   * - Please see enclosed README.txt for full documentation regarding required markup and usage.
   */

  Drupal.behaviors.rnd15PaneFilter = {

    defaults : {

      // Custom class used on region within 'section' plugin
      sectionWrapperClass : '.pane-filter-section',
      contentWrapperClass : '.pane-filter-content',
      paneFilterGroupClass : '.pane-filter-group',
      panelPaneClass : '.panel-pane',
      activeButtonClass : 'active',
      lastButtonClass : 'last',
      lastGroupClass : 'last',

      filterButtonClass : '.filter__button',
      dataFilterGroupSelector : 'data-filter-group',
      dataFilterValueSelector : 'data-filter-value',
      dataFilterPrefix : '[data-filter-',
      dataFilterSuffix : '"]',

      // Used for filter buttons that reset their respective group
      dataFilterResetSelector : 'all',

      // To store current state of HistoryJS 'state' and therefore our filters
      filterArray : [],

      // Reusable cached objects
      $buttons: null,
      $panes: null,
      $filterGroups: null,
      $sectionWrapper: null,

      paneHideClass : 'pane-filter-pane__hide',

      // The two main variables holding the active filter and button selectors
      currentFilterSelector : '',
      currentActiveButtonsSelector : ''
    },

    attach: function (context, settings) {
      // Functionality is not required on mobile/xs, so stop loading everything right away
      if (Drupal.settings.crl2.breakpointActive == 'xs') {
        return;
      }

      var _base = Drupal.behaviors.rnd15PaneFilter;

      var default_settings = Drupal.settings.rnd15PaneFilter ? Drupal.settings.rnd15PaneFilter : {};
      Drupal.settings.rnd15PaneFilter = $.extend(default_settings, _base.defaults);

      var _settings = Drupal.settings.rnd15PaneFilter;

      // Attach yourself to the entire page as we have elements all over the page we require
      // This means only one pane filter per page
      $(_settings.sectionWrapperClass, context).once('rnd15PaneFilter', _base.init);
    },

    /*
     * Sets up the filter functionality; dynamically adding classes to specific elements required
     * for styling, producing URLs for each button based on their data-attribute values and binds the
     * handeHistoryJS function to any URL updates that constitute HistoryJS functionality
     */
    init: function() {

      var _base = Drupal.behaviors.rnd15PaneFilter;
      var _settings = Drupal.settings.rnd15PaneFilter;

      /**
       * Let's cache all objects we require for this whole shebang to work
       * Use context where we can
       */
      _settings.$sectionWrapper = $(this);
      _settings.$filterGroups = $(_settings.paneFilterGroupClass, _settings.$sectionWrapper);
      _settings.$buttons = $(_settings.filterButtonClass, _settings.$filterGroups);
      _settings.$panes = $(_settings.contentWrapperClass + " " + _settings.panelPaneClass, _settings.$sectionWrapper);

      // Add 'last' class to final filter group
      _settings.$filterGroups
        .last()
        .addClass(_settings.lastGroupClass);

      // Add the 'last' class to the final button in each filter group using last-child
      _settings.$buttons
        .filter(':last-child')
        .addClass(_settings.lastButtonClass);

      _base.resetGroupActiveButtons();

      _base.updateURLs();

      // Bind HistoryJS state changes (URL updates) to the handleHistoryJS function
      $.History.bind(_base.handleHistoryJS);
    },

    /**
     * Saves the current state of the URL (which is updated by our buttons) to our filterArray,
     * used by the filterPanes function to show/hide the relevant content panes
     */
    handleHistoryJS: function(state) {
      var _settings = Drupal.settings.rnd15PaneFilter;
      var _base = Drupal.behaviors.rnd15PaneFilter;

      // Reset the filter array for new filter parameters
      _settings.filterArray = [];

      // Split current HistoryJS 'state' from the current url, first remove any tracking string:
      var historyJsStates = state.split('?');

      // Assign non-tracking url section back to variable
      historyJsStates = historyJsStates.shift();

      // Split-up remaining url fragments to get at our filter groups and values
      historyJsStates = historyJsStates.split('/');

      // Ditch empty first element
      historyJsStates.shift();

      // Assign values into array as objects
      for (i=0; i<historyJsStates.length; i+=2){
        _settings.filterArray.push({ filterGroup:historyJsStates[i], filterValue:historyJsStates[i+1] });
      }
      // Start doing filter stuff
      _base.filterPanes();
    },

    /**
     * Main Filter Function
     * A series of functions to update the page to reflect the current HistoryJS 'state' and
     * therefore filterArray
     */
    filterPanes: function() {
      var _base = Drupal.behaviors.rnd15PaneFilter;

      _base.setCurrentFilterAndActiveButtonSelectors();

      _base.resetGroupActiveButtons();

      _base.updateURLs();

      _base.togglePaneVisibility();
    },

    /**
     * Update each button's href url
     */
    updateURLs: function() {
      var _settings = Drupal.settings.rnd15PaneFilter;
      var _base = Drupal.behaviors.rnd15PaneFilter;

      _settings.$buttons
        .each(_base.updateIndividualButtonHref);
    },

    /**
     * Reset Group Active Buttons
     */
    resetGroupActiveButtons: function(){
      var _settings = Drupal.settings.rnd15PaneFilter;
      var _base = Drupal.behaviors.rnd15PaneFilter;

      // Check if we have an empty filter array
      if(_settings.filterArray.length === 0) {
        // Let's make sure the reset buttons get their active classes
        _settings.$buttons
          .filter('[data-filter-value="' + _settings.dataFilterResetSelector + '"]')
          .addClass(_settings.activeButtonClass);
      } else {
        // Only reset buttons within a specific group that has no active button
        _settings.$filterGroups.each(_base.resetActiveButtonsByGroup);
      }
    },

    /**
     * Toggles filter panes
     * Use classes rather than .hide/.show functions due to existing style overrides
     */
    togglePaneVisibility:function() {
      var _settings = Drupal.settings.rnd15PaneFilter;

      // Hide all Panes and show the filtered panes or show all existing panes
      if (_settings.currentFilterSelector !== '') {
        _settings.$panes
          .addClass(_settings.paneHideClass)
          .filter(_settings.currentFilterSelector)
          .removeClass(_settings.paneHideClass);
      } else {
        _settings.$panes
          .removeClass(_settings.paneHideClass);
      }
    },

    /**
     * Main function that sets current filter and active button selectors
     * - _settings.currentFilterSelector
     * - _settings.currentActiveButtonsSelector
     */
    setCurrentFilterAndActiveButtonSelectors : function() {
      var _settings = Drupal.settings.rnd15PaneFilter;
      var _base = Drupal.behaviors.rnd15PaneFilter;

      // Add it to the relevant button, using both group and value data attributes in the selector
      var activeButtonSelectorArray = [];
      var currentFilterSelectorString = '';

      // Loop through the filter array and do magic!
      for (i = 0; i<_settings.filterArray.length; i++) {
        // Create Active Buttons Selector
        activeButtonSelectorArray.push(
          '[' + _settings.dataFilterValueSelector + '=' + _settings.filterArray[i].filterValue + ']' +
          '[' + _settings.dataFilterGroupSelector + '=' + _settings.filterArray[i].filterGroup+']');
        
        // Create Currently Active Filters Selector - skip 'all'
        if(_settings.filterArray[i].filterValue !== _settings.dataFilterResetSelector) {
          currentFilterSelectorString += _settings.dataFilterPrefix + _settings.filterArray[i].filterGroup + '*="' + _settings.filterArray[i].filterValue + _settings.dataFilterSuffix;
        }
      }

      // Assign the current filter selector and active button selectors
      _settings.currentFilterSelector = currentFilterSelectorString;
      _settings.currentActiveButtonsSelector = activeButtonSelectorArray.join();
    },


    /**
     * Helper Function to Update an individual buttons href
     */
    updateIndividualButtonHref: function() {
      var _settings = Drupal.settings.rnd15PaneFilter;

      // Cache button attributes
      var $button = $(this);
      var buttonGroup = $button.attr(_settings.dataFilterGroupSelector);
      var buttonValue = $button.attr(_settings.dataFilterValueSelector);
      var newButtonHref = "#/" + buttonGroup + "/" + buttonValue;

      // If the filter group isn't the same as the buttons own filter group, add this group and value
      for (i=0; i < _settings.filterArray.length; i++) {

        var filterGroup = _settings.filterArray[i].filterGroup;
        var filterValue = _settings.filterArray[i].filterValue;

      if (filterGroup !== buttonGroup) {
         newButtonHref = newButtonHref.concat("/" + filterGroup + "/" + filterValue);
        }
      }

      // Assign the new updated link back to the element
      $button.attr("href", newButtonHref);
    },

    /**
     * Helper function reset an individual groups active button
     */
    resetActiveButtonsByGroup: function() {
      var _settings = Drupal.settings.rnd15PaneFilter;
      var currentGroup = this;

      // If we find an active button, find its siblings, remove the active class and apply it to the filtered one one
      $(_settings.$buttons, currentGroup)
        .filter(_settings.currentActiveButtonsSelector)
        .siblings()
        .removeClass(_settings.activeButtonClass)
        .end()
        .addClass(_settings.activeButtonClass);
    }
  };
})(jQuery);