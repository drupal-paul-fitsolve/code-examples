(function ($) {
  /**
   * Behaviour for the rnd15 Age Check Interstitial Message
   *
   * Author: J.Pitt
   * Contributors: -
   * 
   * Last update: 30th December 2014
   * 
   * Description & additional notes:
   * - Libraries reside in sites/all/libraries/interstitial which contain futher information on how to use this plugin
   * - Parameters can be set either directly when initialising the age check link or via data attribute
   * - To pass in options to for instance change the age limit and prompt title, do the following:
   * HTML: <a href="/url" data-age-check-interstitial data-age-check-interstitial-options='{"question": "Age?", "promptTitle" : "Yo gotta be older, grab an adult.", "ageLimit" : 18}'>Interstitial Age link</a>
   *   
   */
  Drupal.behaviors.rnd15ageCheckInterstitial = {

    defaults : {
      mainSelector: '[data-age-check-interstitial]'
    },

    attach: function (context, settings) {
      var _base = Drupal.behaviors.rnd15ageCheckInterstitial;

      // Setup the Interstitial, passing in the relevant context
      $('body', context).once('rnd15ageCheckInterstitial', function(){
        // Extend the current behaviour with default values
        Drupal.settings.rnd15ageCheckInterstitial = $.extend({}, _base.defaults);
      });
      
      // Attach the interstitials
      _base.attachInterstitials(context);
    },

    /**
     * Sets up the Interstitials
     * - Simply applies the interstitial plugin to all main link selectors
     * @param  {[type]} context [description]
     */
    attachInterstitials : function(context) {
      var _base = Drupal.behaviors.rnd15ageCheckInterstitial;
      var _settings = Drupal.settings.rnd15ageCheckInterstitial;

      // Options custom to rnd15
      var interstitialOptions = {
        textAttributes : {
          'class': 'type--lg type--white type--centred interstitial__message'
        },
        cancelButtonAttributes : {
          'class': 'interstitital__btn-cancel btn btn-red btn-ghost',
          href: '#close'
        },
        redirectButtonAttributes : {
          'class': 'interstitital__btn-redirect btn btn-red btn-ghost'
        },
        submitButtonAttributes : {
          'class': 'interstitital__btn-submit btn btn-red btn-ghost'
        },
        promptDescriptionAttributes : {
          'class': 'interstitital__prompt-description type--white type--centred'
        },
        promptTitleAttributes : {
          'class': 'interstitital__prompt-title type--white type--centred'
        }
      };

      // Simple ;)
      $(_settings.mainSelector, context).once('interstitial').interstitialAgeCheck(interstitialOptions);

    }
  };
})(jQuery);