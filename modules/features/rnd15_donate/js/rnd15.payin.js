(function ($) {

  /**
   * Behaviour for the rnd15 Pay In form
   *
   * Author: Andy E. Phipps
   * Last updated: 25th February 2015
   */

  Drupal.behaviors.rnd15PayIn = {

    defaults : {
      form1WrapperSelector: '.cr-fundraising-form-step-1',
      form2WrapperSelector: '.cr-fundraising-form-step-2',
      formToShowSelector: '.cr-fundraising-form-step-1 .payin__info',
      radioButtonSelector: '.cr-fundraising-form-step-1 .form-radio',
      submitButtonSelector: '#edit-submit--2',
      payInIntroSelector: '.payin--intro',
      clicked: false
    },

    /*
     * Attaches the rnd15 rnd15PayIn Behaviour
     */
    attach: function (context, settings) {
      var _base = Drupal.behaviors.rnd15PayIn;

      // Handle settings
      var default_settings = Drupal.settings.rnd15PayIn ? Drupal.settings.rnd15PayIn : {};
      Drupal.settings.rnd15PayIn = $.extend(default_settings, _base.defaults);

      var _settings = Drupal.settings.rnd15PayIn;

      $('body', context).once('rnd15PayIn', _base.setup);

      // Hide our intro once the form state changes, by checking 2nd state wrapper exists
      if ( _settings.$form2Wrapper.length > 0 && _settings.$payInIntro.is(':visible')) {
        _settings.$payInIntro.hide();
      }
    },

    /**
     * Cache all jquery objects and prepare event handlers
     */
    setup: function() {
      var _settings = Drupal.settings.rnd15PayIn;
      var _base = Drupal.behaviors.rnd15PayIn;
      var context = this;

      // Cache all the jQuery objects we need for use
      _settings.$form1Wrapper = $(_settings.form1WrapperSelector, context);
      _settings.$form2Wrapper = $(_settings.form2WrapperSelector, context);
      _settings.$formToShow = $(_settings.formToShowSelector, context);
      _settings.$radioButtons = $(_settings.radioButtonSelector, context);
      _settings.$payInIntro = $(_settings.payInIntroSelector, context);

      // Show the rest of the form once the initial choice has been made
      _settings.$radioButtons.change(_base.handleRadioButtonChange);
    },

    /**
     * Event handler on radio buttons to show the form once clicked
     */
    handleRadioButtonChange: function(e) {
      var _settings = Drupal.settings.rnd15PayIn;
      if (!_settings.clicked) {
        _settings.$formToShow.show();
        _settings.clicked = true;
      }
    }
  };
})(jQuery);