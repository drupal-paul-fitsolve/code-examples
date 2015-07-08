(function ($) {

  /**
   * Behaviour for the sr16splash Site ESU Strip
   *
   * Author: J.Pitt
   * Contributors: -
   * 
   * Last update: 13th October
   * 
   * Description & additional notes:
   * Provides functionality for the ESU Strip
   * - It is dependendent on the Site Menu JS script
   * 
   */
  Drupal.behaviors.sr16splashsiteESU = {

    defaults : {
      siteESUClass: 'form.cr-marketing-prefs-promo-form',
      errorMessageClass: 'messages--error',
      errorClass: 'error',

      previousStep : null,
      currentStep : 'step1',
      hasError : false,

      formSteps : {
        step1: 'cr-marketing-prefs-promo-form-general',
        step2: 'cr-marketing-prefs-promo-form-teacher',
        step3: 'cr-marketing-prefs-promo-form-complete'
      },

      $errorMessages : null,
      errorTextMessage : '',

      $siteESUBlock : null
    },

    attach: function (context, settings, selector) {
      var _base = Drupal.behaviors.sr16splashsiteESU;

      // Setup the email signup, passing in the relevant context
      $(_base.defaults.siteESUClass, context).once('sr16splashsiteESU', _base.setupESU);

      // If we do not have a ESU Header, the settings won't be there so just skip this behavior
      var _settings = Drupal.settings.sr16splashsiteESU;
      if (!_settings) return;

      // Process the context all the time, unless we don't have our settings.
      _base.processContext(context);
 
    },

    /*
     * Setup the ESU 
     */
    setupESU : function(context) {
      var _base = Drupal.behaviors.sr16splashsiteESU;

      // Extend the settings with the defaults.
      Drupal.settings.sr16splashsiteESU = $.extend({}, _base.defaults);

      var _settings = Drupal.settings.sr16splashsiteESU;

      /**
       * Cache JS & jQuery Objects we require
       */
      _settings.$siteESUBlock = $(_settings.siteESUClass, context);

    },

    /*
     * Process Context
     * Unlike the setup, we want to process this all the time.
     */
    processContext : function(context) {
      var $context = $(context);
      var _base = Drupal.behaviors.sr16splashsiteESU;
      var _settings = Drupal.settings.sr16splashsiteESU;

      // Reset the error flag
      _settings.hasError = false;

      // Handle errors so they appear AFTER the form item
      if ($context.hasClass(_base.defaults.errorMessageClass)) {
        $context.once('siteESU', _base.handleErrors);
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
      var _base = Drupal.behaviors.sr16splashsiteESU;
      var _settings = Drupal.settings.sr16splashsiteESU;

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
      var _settings = Drupal.settings.sr16splashsiteESU;

      // We want to only apply this to the ESU header, so check if we are in the right context
      if(!$(this).parents(_settings.siteESUClass).length) {
        return;
      }

      // Set the error messages from passed in context
      _settings.$errorMessages = $(this);
      var $submit = $('input[type="submit"]',_settings.siteESUClass);

      // Set the error text message
      _settings.hasError = _settings.$errorMessages.text();
      _settings.hasError = _settings.hasError.replace('Error message', '');

      // Simply move the error message
      _settings
        .$errorMessages
        .insertAfter($submit.parent())
        .addClass('messages-cross');
    },

    /**
     * ESU Sets the active form step
     * Helper function for tracking the form steps
     */
    setActiveStep : function() {
      var _settings = Drupal.settings.sr16splashsiteESU;
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
     * copied from sr16splash.gtm.js
     */
    trackESU: function() {
      if (!dataLayer) return;

      var _settings = Drupal.settings.sr16splashsiteESU;
      var esuEvent = {
        event: "sr16splash.esu",
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