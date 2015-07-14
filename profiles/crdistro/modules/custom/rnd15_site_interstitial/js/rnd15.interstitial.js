(function ($) {
  /**
   * Behaviour for the RND15 Interstital Message
   *
   * Author: J.Pitt
   * Contributors: -
   * 
   * Last update: 31st August 2014
   * 
   * Description & additional notes:
   *
   * - Uses the data attributes to provide an interstitial message when redirecting users to 
   *   external urls
   * - Attributes are:
   *   data-interstitial="You will be redirected in 5 seconds."
   *   data-interstitial-delay="5000"
   *   
   */
  Drupal.behaviors.rnd15interstitial = {

    defaults : {
      mainSelector: '[data-interstitial]'
    },

    attach: function (context, settings) {
      var _base = Drupal.behaviors.rnd15interstitial;

      // Setup the Interstitial, passing in the relevant context
      $('body', context).once('rnd15interstitial', function(){
        // Extend the current behaviour with default values
        Drupal.settings.rnd15interstitial = $.extend({}, _base.defaults);
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
      var _base = Drupal.behaviors.rnd15interstitial;
      var _settings = Drupal.settings.rnd15interstitial;

      // Options custom to RND15
      var interstitialOptions = {
        textAttributes : {
          'class': 'type--lg type--white type--centred interstitial__message'
        },
        cancelButtonAttributes : {
          'class': 'interstitital__btn-cancel btn btn-red btn-ghost',
          href: '#close'
        }
      };

      // Simple ;)
      $(_settings.mainSelector, context).once('interstitial').interstitial(interstitialOptions);

    }
  };
})(jQuery);