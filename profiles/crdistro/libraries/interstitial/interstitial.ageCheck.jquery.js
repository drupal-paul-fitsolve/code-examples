(function ($) {
/**
 * Age Check Intertitial jQuery Plugin
 * Author: Jeremy P.
 * 
 * Usage:
 * HTML: <a href="/url" data-age-check-interstitial data-age-check-interstitial-options='{"question": "Age?", "ageLimig" : 18}'>Interstitial Age link</a>
 * You can pass in options via the options data attribute to override any setting below from line 32 forward
 * 
 * JS: $('[data-age-check-interstitial]').interstitialAgeCheck(options);
 * JS Options can be overidden by passing them into the function
 *
 * Example:
 * var options = { backgroundAttributes:{id:'foo', class:'bar'}, ageLimit: 21}
 * $('.my-link').interstitialAgeCheck(options);
 */
jQuery.fn.interstitialAgeCheck = function(options) {
  var $overlay,
      $overlayContent,
      $background,
      $text,
      $ageInput,
      $submitButton,
      $overlayContentQuestion,
      $cancelButton,
      $redirectButton,
      $promptTitle,
      $promptDescription,
      $overlayContentPrompt;

  // Default Options
  var settings = $.extend({
      question : "How old are you?",
      ageLimit : 16,
      promptTitle : "Grab a grown up",
      promptDescription : "If you are under 16, an adult has to enter the prize draw for you. <br>This is because they will need to accompany you if you win the prize..",
      promptRedirectUrl : '/who-nose/competition?age=under16',
      cancelButtonText : "I'll come back later",
      redirectButtonText : "I am a grown up, continue",
      submitButtonText : "Submit",
      ageInputLabel : "years old",
      overlayAttributes : {
        id : "interstitial",
        "class" : "interstitial interstitial--age-check"
      },
      backgroundAttributes : {
        id : "interstitial__background"
      },
      cancelButtonAttributes : {
        "class" : "interstitital__btn-cancel",
        href : "#close"
      },
      ageInputAttributes : {
        name : "age",
        type : "text",
        size : "3",
        "class" : "interstitital__age-input form-text"
      },
      redirectButtonAttributes : {
        "class" : "interstitital__btn-redirect"
      },
      submitButtonAttributes : {
        "class" : "interstitital__btn-submit"
      },textAttributes : {
        "class" : "interstitial__message"
      },
      promptDescriptionAttributes : {
        "class" : "interstitial__prompt-description"
      },
      promptTitleAttributes : {
        "class" : "interstitial__prompt-title"
      }
  }, options);
  
  // Set the redirect URL
  var redirectUrl = '/';

  // Set the ageLimit
  var ageLimit = settings.ageLimit;

  // Setup Overlay
  function setupOverlay(linkUserDataOptions) {
    var $body = $('body');

    var linkOptions = settings;

    // Extend options provided by user in data attribute
    if(linkUserDataOptions !==  null && typeof linkUserDataOptions === "object") {
      linkOptions = $.extend(settings, linkUserDataOptions);
    }

    // Set the age limit in case it's also set via the data options
    ageLimit = linkOptions.ageLimit;

    // Set the prompt redirect URL
    linkOptions.redirectButtonAttributes.href = linkOptions.promptRedirectUrl ? linkOptions.promptRedirectUrl : redirectUrl;

    // Setup the background div
    $background = $('<div/>')
      .attr(linkOptions.backgroundAttributes)
      .appendTo($body)
      .on('click', handleCancelClick);

    // Setup the overlay div
    $overlay = $('<div/>')
      .attr(linkOptions.overlayAttributes)
      .wrapInner('<div class="interstitial__content"><div class="interstitial__content-inner"><div class="interstitial__question"></div><div class="interstitial__prompt"></div></div></div>')
      .appendTo($body);

    /**
     * Setup the overlay questions
     */
    $text = $('<h2/>')
      .attr(linkOptions.textAttributes)
      .html(linkOptions.question);

    $ageInput = $("<input/>")
      .attr(linkOptions.ageInputAttributes)
      .after("<label>" + linkOptions.ageInputLabel + "</label>");

    $submitButton = $('<a/>')
      .attr(linkOptions.submitButtonAttributes)
      .text(linkOptions.submitButtonText)
      .on('click', handleSubmitClick);

    $overlayContentQuestion = $('.interstitial__content-inner .interstitial__question', $overlay)
      .append($text, $ageInput, $submitButton);

    // Only once added can we start wrapping elements
    $submitButton
      .add($ageInput)
      .wrapAll('<div class="interstitital__question-form "></div>')
      .end()
      .wrap("<p></p>");

    /**
     * Setup the overlay prompt
     */
    $cancelButton = $('<a/>')
      .attr(linkOptions.cancelButtonAttributes)
      .text(settings.cancelButtonText)
      .on('click', handleCancelClick);

    $redirectButton = $("<a/>")
      .attr(linkOptions.redirectButtonAttributes)
      .text(linkOptions.redirectButtonText);

    $promptTitle = $("<h2/>")
      .attr(linkOptions.promptTitleAttributes)
      .html(linkOptions.promptTitle);

    $promptDescription = $("<p/>")
      .attr(linkOptions.promptDescriptionAttributes)
      .html(linkOptions.promptDescription);

    // Construct the prompt section
    $overlayContentPrompt = $('.interstitial__content-inner .interstitial__prompt', $overlay)
      .hide()
      .append($promptTitle, $promptDescription, $redirectButton, $cancelButton);

    // We can only wrap once appending it to the dom
    $cancelButton
      .add($redirectButton)
      .wrapAll('<p class="interstitital__btn type--centred"></p>');
  }

  // Open Overlay
  function toggleOverlay() {
    var $link = $(this);
    var textMessage = $link.attr('data-interstitial') ? $link.attr('data-interstitial') : settings.default_message;
    var userOptions = $(this).data("age-check-interstitial-options");

    // Setup the overlay if it's not existent
    if(!$overlay) {
      setupOverlay(userOptions);
    }

    // Toggle the overlay (hide or show)
    $background.toggle();
    $overlay.toggle();

    // Return if the overlay is visible or not using jQuery's "is" function
    return $overlay.is(":visible");
  }

  // Check the age
  function isValidAge() {
    return $ageInput.val() >= ageLimit;
  }

  // Close the Overlay
  function closeOverlay(e) {
    $background.hide();
    $overlay.hide();
  }

  // Close the overlay
  function handleCancelClick(e) {
    e.preventDefault();
    closeOverlay();
  }

  // Handle the submit click
  function handleSubmitClick(e) {
    e.preventDefault();

    if(isValidAge()) {
      closeOverlay(e);
      window.location.href = redirectUrl;
    } else {
      $overlayContentQuestion.hide();
      $overlayContentPrompt.show();
    }
  }

  // Handle Interstitial Link Click
  function handleClick(e) {
    e.preventDefault();
    toggleOverlay.apply(this);
  }

  // Setup Link
  function setupLink() {
    var $link = $(this);
    // Do something to each element here.
    $link.on('click', handleClick);

    // Setup the redirect URL
    redirectUrl = $link.attr('href');
  }

  // This is so we can chain the interstitial :)
  return this.each(setupLink);
};
})(jQuery);