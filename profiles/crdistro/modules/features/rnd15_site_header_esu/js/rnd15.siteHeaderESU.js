(function ($) {

  /**
   * Behaviour for the RND15 Site ESU Header
   *
   * Author: J.Pitt
   * Contributors: -
   * 
   * Last update: 11th September
   * 
   * Description & additional notes:
   * Provides functionality for the ESU Header
   * - It is dependendent on the Site Menu JS script
   * - It adds a 'opened' class once the animation has finished so dropkick can be used
   * 
   */
  Drupal.behaviors.rnd15siteHeaderESU = {

    defaults : {
      mainNavClass: 'nav.nav',
      toggleButtonClass: 'button.button-esu--toggle',
      siteHeaderESUClass: 'div.esu-header',
      siteHeaderESUBlockTitleClass: '.esu-header__title.block__title',
      siteHeaderESUCloseButtonClass: 'a.esu-header__close',
      mainNavTouchClass: 'nav--touch',
      expandedOpenClass: 'open',
      errorMessageClass: 'messages--error',
      errorClass: 'error',

      previousStep : null,
      currentStep : 'step1',
      hasError : false,

      formSteps : {
        step1: 'cr-marketing-prefs-header-form-general',
        step2: 'cr-marketing-prefs-header-form-teacher',
        step3: 'cr-marketing-prefs-header-form-complete'
      },

      // Used to add .opened class and remove overflow hidden (To show dropkick)
      transitionOverflowDelay: 1200,

      $navSite : null,
      $errorMessages : null,
      errorTextMessage : '',

      $toggleButton : null,
      
      $siteHeaderESUBlockTitle : null,
      $siteHeaderESUBlock : null,
      $siteHeaderESUCloseButton : null,

      esuCollapsed : true
    },

    attach: function (context, settings) {
      var _base = Drupal.behaviors.rnd15siteHeaderESU;

      // Setup the email signup, passing in the relevant context
      $(_base.defaults.siteHeaderESUClass, context).once('rnd15siteHeaderESU', _base.setupESU);

      // If we do not have a ESU Header, the settings won't be there so just skip this behavior
      var _settings = Drupal.settings.rnd15siteHeaderESU;
      if (!_settings) return;

      // Process the context all the time, unless we don't have our settings.
      _base.processContext(context);
 
    },

    /*
     * Setup the ESU 
     */
    setupESU : function(context) {
      var _base = Drupal.behaviors.rnd15siteHeaderESU;

      // Extend the settings with the defaults.
      Drupal.settings.rnd15siteHeaderESU = $.extend({}, _base.defaults);

      var _settings = Drupal.settings.rnd15siteHeaderESU;

      /**
       * Cache JS & jQuery Objects we require
       */
      _settings.$navSite = $(_settings.mainNavClass, context);
      _settings.$toggleButton = $(_settings.toggleButtonClass, _settings.$navSite);
      
      // Main Email sign up block
      _settings.$siteHeaderESUBlock = $(_settings.siteHeaderESUClass, context);
      _settings.$siteHeaderESUCloseButton = $(_settings.siteHeaderESUCloseButtonClass, context);

      // Setup the ESU Menu
      _base.setupsiteHeaderESUMenu(context);
    },

    /*
     * Process Context
     * Unlike the setup, we want to process this all the time.
     */
    processContext : function(context) {
      var $context = $(context);
      var _base = Drupal.behaviors.rnd15siteHeaderESU;
      var _settings = Drupal.settings.rnd15siteHeaderESU;

      // Reset the error flag
      _settings.hasError = false;

      // Handle errors so they appear AFTER the form item
      if ($context.hasClass(_base.defaults.errorMessageClass)) {
        $context.once('siteHeaderESU', _base.handleErrors);
      }

      // Handle the second and third step of the form
      if ($context.hasClass(_base.defaults.formSteps.step2) || $context.hasClass(_base.defaults.formSteps.step3) || _settings.hasError) {
        $context.once('steps', _base.handleSteps);
      }
    },

    /*
     * Handle Form Steps
     * this = context
     */
    handleSteps : function() {
      var _base = Drupal.behaviors.rnd15siteHeaderESU;
      var _settings = Drupal.settings.rnd15siteHeaderESU;

      // Set the active and previous steps
      _base.setActiveStep.call(this);

      // Check if we have a previous step, previous and current don't match OR we have an error
      // If so, let's track the ESU
      if ((_settings.previousStep !== null && _settings.previousStep !== _settings.currentStep) || _settings.hasError) {
        // Track the ESU with an option error message if we have one
        _base.trackESU();
      }
    },

    /*
     * Handle error messages
     * this = context
     */
    handleErrors : function() {
      var _settings = Drupal.settings.rnd15siteHeaderESU;

      // We want to only apply this to the ESU header, so check if we are in the right context
      if(!$(this).parents(_settings.siteHeaderESUClass).length) {
        return;
      }

      // Set the error messages from passed in context
      _settings.$errorMessages = $(this);

      var $submit = $('input[type="submit"]', _settings.$siteHeaderESUBlock);

      // Set the error text message
      _settings.hasError = _settings.$errorMessages.text();
      _settings.hasError = _settings.hasError.replace('Error message', '');

      // Simply move the error message
      _settings.$errorMessages.insertAfter($submit);
    },

    /**
     * Sets up the Email Sign Up
     *
     * @param  {object} context context passed in by Drupal
     */
    setupsiteHeaderESUMenu : function(context) {
      var _base = Drupal.behaviors.rnd15siteHeaderESU;
      var _settings = Drupal.settings.rnd15siteHeaderESU;

      /**
       * Attach event handlers to show/hide the ESU
       */
      _settings.$toggleButton.on('click', _base.EH_toggleESU);
      _settings.$siteHeaderESUCloseButton.on('click', _base.EH_toggleESU);
    },

    /**
     * ESU Toggle Event handler
     * 
     * Handles the ESU toggle button functionality
     * @param {Objects} e event handler object
     */
    EH_toggleESU : function(e, eventParam) {
      var _base = Drupal.behaviors.rnd15siteHeaderESU;
      var _menuBase = Drupal.behaviors.rnd15touchMenu;
      var _settings = Drupal.settings.rnd15siteHeaderESU;
      e.preventDefault();

      _settings.$siteHeaderESUBlock = $(_settings.siteHeaderESUClass);
      _settings.$toggleButton = $(_settings.toggleButtonClass, _settings.$navSite);

      // Set the nav collapsed status
      _settings.esuCollapsed = _settings.$siteHeaderESUBlock.hasClass(_settings.expandedOpenClass);

      // Toggle the class on the nav site element
      _settings.$siteHeaderESUBlock.toggleClass(_settings.expandedOpenClass);

      // Handles the opened class once the transition has finished
      if (!_settings.esuCollapsed) {
        // _settings.animationDelay
        _settings.$siteHeaderESUBlock.delay(_settings.transitionOverflowDelay).queue(function(next){
            $(this).addClass('opened');
            next();
        });
      } else {
        _settings.$siteHeaderESUBlock.removeClass('opened');
        _base.resetErrors();
      }
      
      // Toggle the class on the toggle button
      _settings.$toggleButton.toggleClass('active');

      // Close existing nav buttons if it's a genuine click
      if (eventParam !== 'closeAll')  _menuBase.closeNavButtons.apply(_settings.$toggleButton);
    },

    /**
     * ESU Reset Errors
     * Helper function to reset errors when toggling the ESU header
     */
    resetErrors : function() {
      var _settings = Drupal.settings.rnd15siteHeaderESU;
      var $currentESUBlock = $(_settings.siteHeaderESUClass);
      $('.' + _settings.errorMessageClass, $currentESUBlock).hide();
      $('.' + _settings.errorClass, $currentESUBlock).removeClass(_settings.errorClass);
    },

    /**
     * ESU Sets the active form step
     * Helper function for tracking the form steps
     */
    setActiveStep : function() {
      var _settings = Drupal.settings.rnd15siteHeaderESU;
      var formStepClass = '';
      for (var key in _settings.formSteps) {
        formStepClass = _settings.formSteps[key];
        if ($(this).hasClass(formStepClass)) {
          _settings.previousStep = _settings.currentStep;
          _settings.currentStep = key;
        }
      }
    },

    /**
     * Track ESU
     * copied from rnd15.gtm.js
     */
    trackESU: function() {
      if (!dataLayer) return;

      var _settings = Drupal.settings.rnd15siteHeaderESU;
      var esuEvent = {
        event: "rnd15.esuHeader",
        activeStep : String(_settings.currentStep),
        previousStep : String(_settings.previousStep)
      };

      // Track errors
      if (_settings.hasError) {
        esuEvent.error = String(_settings.hasError);
      }

      // Push the esu event object
      dataLayer.push(esuEvent);
    }

  };

})(jQuery);