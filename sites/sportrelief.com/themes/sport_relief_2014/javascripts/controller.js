/**
 * @file
 * This file is the initiative for other Javascript modules. Include mobile/desktop/Modernizr conditions here.
 */

/* Helper Functions */

function cleanCssIdentifier(name) {
  return name.replace(/[^a-z0-9]/g, function (s) {
    var c = s.charCodeAt(0);
    // spaces to dashes
    if (c === 32) return '-';
    // convert uppercase A-Z to lowercase a-z
    if (c >= 65 && c <= 90) return s.toLowerCase();
    return '__' + ('000' + c.toString(16)).slice(-4);
  });
}

(function ($) {

  // Implement a reliable cross-browser "console" mostly for IE8.
  var method;
  var noop = function () {};
  var methods = [
    'assert', 'clear', 'count', 'debug', 'dir', 'dirxml', 'error',
    'exception', 'group', 'groupCollapsed', 'groupEnd', 'info', 'log',
    'markTimeline', 'profile', 'profileEnd', 'table', 'time', 'timeEnd',
    'timeStamp', 'trace', 'warn'
  ];
  var length = methods.length;
  var console = (window.console = window.console || {});

  while (length--) {
    method = methods[length];

    // Only stub undefined methods.
    if (!console[method]) {
      console[method] = noop;
    }
  }

  Drupal.behaviors.sportrelief_2014 = {
    attach: function (context) {
      Drupal.behaviors.sportrelief_2014.megamenu(context);
      Drupal.behaviors.sportrelief_2014.moneybuy(context);
      Drupal.behaviors.sportrelief_2014.schoolanimation(context);
      Drupal.behaviors.sportrelief_2014.schoolflexslidedownloads(context);
      Drupal.behaviors.sportrelief_2014.challenge_davina(context);
      Drupal.behaviors.sportrelief_2014.challenge_alex(context);
      // Drupal.behaviors.sportrelief_2014.formhelp(context);
      Drupal.behaviors.sportrelief_2014.selectlists(context);
      Drupal.behaviors.sportrelief_2014.grantsections(context);
      Drupal.behaviors.sportrelief_2014.esu_submit_button(context);
      Drupal.behaviors.sportrelief_2014.mobile_trans_source(context);
      Drupal.behaviors.sportrelief_2014.projects(context);
      Drupal.behaviors.sportrelief_2014.viewsAccordion(context);
      Drupal.behaviors.sportrelief_2014.ga(context);
      Drupal.behaviors.sportrelief_2014.search_page_sponsorship_form_colorbox(context);
      Drupal.behaviors.sportrelief_2014.front_full_width_promo_slider(context);
      Drupal.behaviors.sportrelief_2014.downloadables_overlay(context);
      Drupal.behaviors.sportrelief_2014.schoolstoolbox(context);
      Drupal.behaviors.sportrelief_2014.esuheader(context);
      Drupal.behaviors.sportrelief_2014.spendareas(context);
      Drupal.behaviors.sportrelief_2014.partners(context);
      Drupal.behaviors.sportrelief_2014.ctadown(context);
      Drupal.behaviors.sportrelief_2014.peoplehelped(context);
      Drupal.behaviors.sportrelief_2014.givingwheel(context);
      Drupal.behaviors.sportrelief_2014.event_promo_slider(context);
      Drupal.behaviors.sportrelief_2014.kids_play_games_section();
      Drupal.behaviors.sportrelief_2014.fundraise_winner();
      Drupal.behaviors.sportrelief_2014.partners_carousel();

    }
  };
  // click text to reveal hidden text
  Drupal.behaviors.sportrelief_2014.fundraise_winner = function (context) {
    if ($('body').find('.context-fundraise').length === 0) {
      $( ".winner-link" ).click(function() {
        $(this).parents(".panels-ipe-sort-container").css("height", "auto");
        $(this).siblings(".winner-box").slideToggle( "fast", function() {
          // Animation complete.
          $('.equal-height-container').trigger('resize.omegaequalheights');
          $(this).parents(".panels-ipe-sort-container").css("height", "100%");
        });
      });
    }
  }
  // Flexslider and video carousel for Davina challenge
  Drupal.behaviors.sportrelief_2014.challenge_davina = function (context) {

    // Prevent the JS wizardry below happening if you are not on the Davina page
    if ($('body').find('.challenge-davina-main').length === 0) {
      return;
    }

    var $videoParent = $('.context-challenge-davina .challenge-davina-main .challenge-davina-main-slides'),
        $videoChild = $('.context-challenge-davina .challenge-davina-attachment .challenge-davina-attachment-slides');

    $videoParent.on('click', function () {
      var $this = $(this),
          $img = $this.find('img'),
          index = $videoParent.index ($this);

      // Only show child items when they are available
      if ($img.length) {
        $videoChild.hide();
        $videoChild.eq(index).show();
      }
    });

    // Append the close button to video overlays
    if (!$videoChild.find ('.button').length) {
      $videoChild.append ('<p><a href="#" class="button button--light-grey">Back</a></p>');
    }

    // Close overlay popups
    $videoChild.on('click', '.button', function (context) {
      context.preventDefault ();
      $videoChild.hide ();
    });


    // Define the number of carousel slides to show 1 slide for mobile and 3 for everything else
    var minSlides;
    if ($(window).width() <= 740 || Drupal.omega.getCurrentLayout() === "mobile") {
      minSlides = 1;
    } else {
      minSlides = 3;
    }

    // A super flexible flexslider for Challenge pages - 3 items for desktop reduces to 1 item on mobile.
    if ($('.context-challenge-davina .challenge-davina-video-pod').length) {
      $('.context-challenge-davina .challenge-davina-video-pod .challenge-davina-main').flexslider({
        controlNav: false,
        animation: "slide",
        slideshow: false,
        animationLoop: false,
        startAt: 5,
        itemWidth: 300,
        itemMargin: 0,
        move: 1,
        minItems: minSlides,
        maxItems: 0
      });
    }

  };

  Drupal.behaviors.sportrelief_2014.challenge_davina_render = function (context) {

    // Prevent the JS wizardry below happening if you are not on the Davina page
    if ($('body').find('.challenge-davina-main').length === 0) {
      return;
    }

    // This function counts the number of videos for each challenge day
    // @return int
    function getDavinaVideoCount (slidesTitle) {

      var slidesTotal;

      $('.challenge-davina-attachment-slides').find('h3').each(function () {
        if ($(this).html() === slidesTitle) {
          // If the field doesn't have an image assume no videos.
          if ($(this).parent().find('img').length === 0) {
            slidesTotal = 0;
          } else {
            slidesTotal = $(this).parent().find('li').length;
          }
        }
      });

      if (slidesTotal !== undefined) {
        return slidesTotal;
      } else {
        return 0;
      }

    }

    // Go through all "Main Slides" and append a video slide count.
    function processDavinaVideoCountView () {

      $('.challenge-davina-main-slides h3').each(function () {

        if ($(this).parent().find('.davina-main-slides-video-count').length === 0) {

          var videoCount = getDavinaVideoCount($(this).html());

          // pluralise videos
          if (videoCount > 1) {
            $(this).after('<div class="davina-main-slides-video-count">'+videoCount+' videos</div>');
          }

          // singular video
          if (videoCount === 1) {
            $(this).after('<div class="davina-main-slides-video-count">'+videoCount+' video</div>');
          }

          // no videos / coming soon frame.
          if (videoCount === 0) {
            // Left as a placeholder. Do not display anything.
          }

        }

      });

    }

    processDavinaVideoCountView();

  };

  // Flexslider and video carousel for Alex challenge
  Drupal.behaviors.sportrelief_2014.challenge_alex = function (context) {

    // Prevent the JS wizardry below happening if you are not on the Alex page
    if ($('body').hasClass('.context-challenge-alex') && $('body').find('.challenge-main').length === 0) {
      return;
    }

    var $videoParent = $('.context-challenge-alex .challenge-main .challenge-main-slides'),
      $videoChild = $('.context-challenge-alex .challenge-attachment .challenge-attachment-slides');

    $videoParent.on('click', function () {
      var $this = $(this),
        $img = $this.find('img'),
        index = $videoParent.index ($this);

      // Only show child items when they are available
      if ($img.length) {
        $videoChild.hide();
        $videoChild.eq(index).show();
      }
    });

    // Append the close button to video overlays
    if (!$videoChild.find ('.button').length) {
      $videoChild.append ('<p><a href="#" class="button button--light-grey">Back</a></p>');
    }

    // Close overlay popups
    $videoChild.on('click', '.button', function (context) {
      context.preventDefault ();
      $videoChild.hide ();
    });


    // Define the number of carousel slides to show 1 slide for mobile and 3 for everything else
    var minSlides;
    if ($(window).width() <= 740 || Drupal.omega.getCurrentLayout() === "mobile") {
      minSlides = 1;
    } else {
      minSlides = 3;
    }

    // A super flexible flexslider for Challenge pages - 3 items for desktop reduces to 1 item on mobile.
    if ($('.context-challenge-alex .challenge-video-pod').length) {
      $('.context-challenge-alex .challenge-video-pod .challenge-main').flexslider({
        controlNav: false,
        animation: "slide",
        slideshow: false,
        animationLoop: false,
        startAt: 1,
        itemWidth: 300,
        itemMargin: 0,
        move: 1,
        minItems: minSlides,
        maxItems: 0
      });
    }

  };

  Drupal.behaviors.sportrelief_2014.challenge_alex_render = function (context) {

    // Prevent the JS wizardry below happening if you are not on the Alex page
    if ($('body').hasClass('.context-challenge-alex') && $('body').find('.challenge-main').length === 0) {
      return;
    }

    // This function counts the number of videos for each challenge day
    // @return int
    function getChallengeVideoCount (slidesTitle) {

      var slidesTotal;

      $('.context-challenge-alex .challenge-attachment-slides').find('h3').each(function () {
        if ($(this).html() === slidesTitle) {
          // If the field doesn't have an image assume no videos.
          if ($(this).parent().find('img').length === 0) {
            slidesTotal = 0;
          } else {
            slidesTotal = $(this).parent().find('li').length;
          }
        }
      });

      if (slidesTotal !== undefined) {
        return slidesTotal;
      } else {
        return 0;
      }

    }

    // Go through all "Main Slides" and append a video slide count.
    function processChallengeVideoCount () {

      $('.context-challenge-alex .challenge-main-slides h3').each(function () {

        if ($(this).parent().find('.main-slides-video-count').length === 0) {

          var videoCount = getChallengeVideoCount($(this).html());

          // pluralise videos
          if (videoCount > 1) {
            $(this).after('<div class="main-slides-video-count">'+videoCount+' videos</div>');
          }

          // singular video
          if (videoCount === 1) {
            $(this).after('<div class="main-slides-video-count">'+videoCount+' video</div>');
          }

          // no videos / coming soon frame.
          if (videoCount === 0) {
            // Left as a placeholder. Do not display anything.
          }

        }

      });

    }

    processChallengeVideoCount();

  };

  // AJAX loading expanding thing on the partners page
  Drupal.behaviors.sportrelief_2014.partners = function (context) {

    var partnerElements = $(context).find('.partner');
    if (partnerElements.length === 0) {
      return;
    }
    $(partnerElements).each(function () {
      var uuid = $(this).find('.js-partner-uuid').text();
      var appendElement;

      if (Drupal.omega.getCurrentLayout() === "mobile") {
        appendElement = $(this);
      } else {
        appendElement = $(this).closest('.grid-24');
      }
      $(this).gridExpander({
        url : /fpp-endpoint/ + uuid + '?response_type=contentonly',
        appendElement : appendElement,
        wrapperClasses : 'grid-24 grid-expander leader trailer pod alpha omega',
        groupSelect : '.grid-expander',
      });
    });

    var basicPartners = $(context).find('.partner-basic--wrapper .field-name-field-external-link a');
    if (basicPartners.length > 0) {
      $(basicPartners).each(function () {
        $(this).attr('target','_blank');
      });
    }

  };

  // Load in the full view of people on the what we do page
  Drupal.behaviors.sportrelief_2014.peoplehelped = function (context) {

    // We need to duplicate the navigation on mobile.
    var peopleHelped = $(context).find('.people-helped');
    if (peopleHelped.length === 0) {
      return;
    }
    if (Drupal.omega.getCurrentLayout() === 'mobile') {
      var $peopleHelpedContainer = $('.content-row-2-wrapper');
      var nav = $peopleHelpedContainer.html();
      $peopleHelpedContainer.after(nav);
    }
    var $appendElement = $('.content-row-2-wrapper').find('.row.grid-24').not('.admin-only');
    $(peopleHelped).each(function () {
      var uuid = $(this).find('.js-people-helped-uuid').text();
      $(this).flipCards({
        url : /fpp-endpoint/ + uuid + '?response_type=contentonly',
        appendElement : $appendElement,
        wrapperClasses : 'flip-cards people-helped-info',
      });
    });
    // We want to have the first open by default on mobile
    if (Drupal.omega.getCurrentLayout() === 'mobile') {
      $(peopleHelped).first().trigger('click');
    }

  };

  // Add class to grantsections on people helped
  Drupal.behaviors.sportrelief_2014.grantsections = function (context) {

    var grantSections = $(context).find('.people-helped-section');
    if (grantSections.length === 0) {
      return;
    }
    for (var i = grantSections.length - 1; i >= 0; i--) {
      var value = $(grantSections[i]).text();

      var cssClass = 'people-helped-section--' + cleanCssIdentifier(value);
      $(grantSections[i]).addClass(cssClass);
    }

  };

  // Add functionality to form help links
  // Drupal.behaviors.sportrelief_2014.formhelp = function (context) {
  //   var formHelpers = $(context).find('.form-help');
  //   if (typeof formHelpers === "undefined") {
  //     return;
  //   }
  //   $(formHelpers).activateTarget();
  // }

  // Add scrollTo cta down
  Drupal.behaviors.sportrelief_2014.ctadown = function (context) {

    var ctas = $(context).find('.cta--down');

    if (typeof ctas === "undefined") {
      return;
    }

    $(ctas).scrollTo({ speed: 1100, easing: 'swing' });

    // Add CTA to Shop order-stuff page for enabling show/hide toggle
    $('.context-order-stuff .pre-order-pod .cta-button').click(function () {
      $(this).toggleClass('is-active');
        // $('.context-order-stuff .pre-order-pod .cta-block').toggleClass('is-active');
        $('.context-order-stuff .pre-order-pod .cta-block').slideToggle('fast');

        // for page-rehash
        // $(this).closest('.field-item').find('p.cta-block').slideToggle('slow');
   });

  };

  // Add functionality to money buys
  Drupal.behaviors.sportrelief_2014.moneybuy = function (context) {
    var moneybuyTriggers = $(context).find('.money-buy__trigger');
    if (typeof moneybuyTriggers === "undefined") {
      return;
    }
    $(moneybuyTriggers).activateTarget();
    $('.money-buy__fact').on('click', function () {
      $(this).removeClass('is-active');
    });

    $('.pane-bundle-money-buy .field-name-field-fact').click(function () {
      $(this).toggleClass('is-active');
    });
  };

  // Add animation functionality to schools banner
  Drupal.behaviors.sportrelief_2014.schoolanimation = function (context) {

    // Set the width in a variable to cache it
    var wW = $(window).width();

    // No animation on mobile devices
    if (wW < 739) {
      return;
    }
    var $bannerSlides = $(context).find('.school-animation').children(), timeout = 3000;
    if (typeof $bannerSlides === "undefined") {
      return;
    }

    $bannerSlides.hide().first().addClass('is-active').show();

    function showNextSlide() {
      $bannerSlides.filter('.is-active').fadeOut (function () {
        var $this = $(this).removeClass('is-active'),
          $next = $this.next();

        if (!$next.length) {
          $next = $bannerSlides.first();
        }

        $next.fadeIn (function () {
          setTimeout(showNextSlide, timeout);
        }).addClass('is-active');
      });

    }

    setTimeout(showNextSlide, timeout);
  };

  Drupal.behaviors.sportrelief_2014.schoolflexslidedownloads = function (context) {
    if ($('body').hasClass('context-schools')) {
      $('.schools-toolbox .download-list a').attr('target','_blank');
    }
  };

  // Add functionality to megamenu
  Drupal.behaviors.sportrelief_2014.megamenu = function (context) {
    var megaMenuWrapper = $('.zone-megamenu-wrapper');
    var menuWrapper = $('.zone-menu-wrapper');

    if (typeof megaMenuWrapper === "undefined") {
      return;
    }

    if (megaMenuWrapper.length === 0) {
      menuWrapper.addClass('is-collapsed');
      return;
    }

    var wW = $(window).width();

    if (wW >= 980 || Drupal.omega.crappyBrowser()) {
      $(megaMenuWrapper).megaMenu(context, 'desktop', menuWrapper);
    } else {
      $(megaMenuWrapper).megaMenu(context, 'mobile', menuWrapper);
    }

    $('body').bind('responsivelayout', function (e, d) {

      var from = d.from;
      var to = d.to;

      if ((to === "narrow" || to === "mobile") && (from === "wide" || from === "normal"))  {
        $(megaMenuWrapper).megaMenu(context, 'mobile', menuWrapper);
      } else if ( (to === "wide" || to === "normal") && (from === "narrow" || from === "mobile")) {
        $(megaMenuWrapper).megaMenu(context, 'desktop', menuWrapper);
      }

    });

  };

  // Add functionality to email signup header
  Drupal.behaviors.sportrelief_2014.esuheader = function (context) {
    // Flag to indicate whether to ignore a document click.
    var data = { ignore: false };

    var $esuHeader = $('#block-cr-marketing-prefs-esu-header');
    // Show ESU header pod when the link is clicked.
    $('.user-esu', context).click(data, function (event) {
      if (!$esuHeader.is(':visible')) {
       $.fn.megaMenu.pause();
      }
      $esuHeader.toggle();
      event.data.ignore = true;
    });

    // Ignore the click if it is inside the header.
    $esuHeader.click(data, function (event) {
      event.data.ignore = true;
    });

    // Hide the ESU header if the document was clicked and the flag is not set.
    $(document).click(data, function (event) {
      if (!event.data.ignore) {
        $esuHeader.hide();
        $.fn.megaMenu.unpause();
      }
      event.data.ignore = false;
    });

    // Hide the ESU header if the close button was clicked.
    $esuHeader.find('.close-button').click(function () {
      $esuHeader.hide();
      $.fn.megaMenu.unpause();
    });
  };

  // Alter the select lists on the site for easy styling
  Drupal.behaviors.sportrelief_2014.selectlists = function (context) {
    if (('ontouchstart' in window) || window.DocumentTouch && document instanceof DocumentTouch ) {
    } else {
      $('select', context).each(function () {
        $(this).attr('tabindex', 0);
      }).dropkick({
        change: function (value, label) {
          $(this).change();

          // The AJAX views exposed filter object get's stale, this is a bit of a  hack but it works.
          var $selector = $(this).attr('id');
          if ($selector === "edit-field-project-region-tid" || $selector === "edit-term-node-tid-depth") {
            $('#' + $selector).val(value).change();
          }
        }
      });
    }
  };

  /**
   * Can't use form states with dropkick
   */
  Drupal.behaviors.sportrelief_2014.esu_submit_button = function (context) {
    // Hide the submit button until a phase is selected.
    // This should be done with states API, but it does not seem to work
    // in conjunction with the Ajax form replacement.
    $('select[name=phase]', context).change(function () {
      $(this).closest('form').not('.cr-marketing-prefs-signup-form').find('.button--submit').toggle($(this).val() !== '');
    }).change();
  };

  /**
   * Putting in here because of the late setting of activeLayout
   * Also because activeLayout does not respond to resize events
   */
  Drupal.behaviors.sportrelief_2014.mobile_trans_source = function (context) {
    if ($(window).width() <= 740) {
      $('input[name="platform"]', context).val('mobile');
    }
  };

  // Add functionality to accordions
  Drupal.behaviors.sportrelief_2014.viewsAccordion = function (context) {

    var accordionContainer = $('.schools-toolbox');

    if (typeof accordionContainer === "undefined" || $(window).width() >= 740 || Drupal.omega.crappyBrowser()) {
      return;
    }

    $(accordionContainer).viewsAccordion();

  };

  // Attach colorbox node behavior directly to downloadable form popups.
  Drupal.behaviors.sportrelief_2014.search_page_sponsorship_form_colorbox = function (context) {
    if (window.location.pathname.substring(0, 7) === '/search') {
      var downloadables = $('.pane-downloadables', context);
      if (downloadables.length) {
        // Hide this for now
        //downloadables.find('a[href *= "/sponsorship-forms/"]').closest('li').hide();

        downloadables.find('a[href *= "/sponsorship-forms/"]').addClass('colorbox-node');
        Drupal.behaviors.colorboxNode.attach(downloadables, Drupal.settings);
      }
    }
  };

  // Will only run giving wheel JS when not mobile breakpoint and wheel is present
  Drupal.behaviors.sportrelief_2014.givingwheel = function (context) {

    var wheel = $(context).find('.givingwheel--wrapper');

    if ( $(window).width() >= 980 && wheel.length > 0) {
      $('.givingwheel--wrapper').givingwheelAnim();
    } else {
      return;
    }
  };

  Drupal.behaviors.sportrelief_2014.showcase_scroller = function (context) {

    var scroller = $(context).find('.showcase-scroller');

    if (Drupal.omega.getCurrentLayout() !== "mobile" && scroller.length > 0) {

      // Weight of JS on load seems to stop this firing properly, so a small delay helps it out here
      setTimeout(function () {
        $(".showcase-scroller").simplyScroll();
      }, 2000);
    } else {
      return;
    }
  };

  // Event section
  // Promo image/video slider caption
  Drupal.behaviors.sportrelief_2014.event_promo_slider = function (context) {

    var slider = $(context).find('.price--media');
    var img = $('.field-name-field-image img', slider);
    var vid = $('.node-video', slider);

    if ((('ontouchstart' in window) || window.DocumentTouch && document instanceof DocumentTouch) || $(window).width() <= 740) {
      // Placeholder
    } else {
      vid.on({
        mouseenter: function (event) {
          $(this).addClass('hover');
        },
        mouseleave: function (event) {
          $(this).removeClass('hover');
        },
        click: function (event) {
          $(this).find('.field-name-body').hide();
        }
      });
    }

    img.each(function () {
          var caption = $(this).attr('title');
          var parent = $(this).parent();
          $('<div class="field-name-body">' + caption + '</div>').appendTo(parent);
    });
  };

  // Downloadables_overlay
  Drupal.behaviors.sportrelief_2014.downloadables_overlay = function (context) {
    var overlays = $('.dl-overlay', context);
    var colorbox_inline_width = '1180';
    var path;

    if (Drupal.omega.getCurrentLayout() === "wide") { colorbox_inline_width = '1180'; }
    if (Drupal.omega.getCurrentLayout() === "normal") {  colorbox_inline_width = '940'; }
    if (Drupal.omega.getCurrentLayout() === "narrow") {  colorbox_inline_width = '700'; }

    overlays.each(function () {
      path = $(this).find('.title').text().toLowerCase().replace(/\s/g, '-');
      var overlayheight;

      if (path === "giving-page-banners" || path === "facebook-cover" || path === "intranet-banner") {
        overlayheight=  800;
        $(this).find('.tile').addClass('digitool--tile');
      } else {
        overlayheight= 490;
      }

      $(this).find('a').removeAttr('class').addClass('colorbox-node').attr({href: '/' + path + '/all?width=' + colorbox_inline_width + '&height='+overlayheight});
      Drupal.behaviors.colorboxNode.attach(overlays, Drupal.settings);
    });

    // add class to colorbox overlay
    if ( overlays.length > 0 ) {
      $('#colorbox', context).ajaxSuccess(function (){
        $(this).addClass('dl-overlay-box');
        if (path === "giving-page-banners" || path === "facebook-cover" || path === "intranet-banner") {
          $(this).addClass('digitool--colorbox');
        }
      });
    }

    if ((('ontouchstart' in window) || (window.DocumentTouch && document instanceof DocumentTouch)) && ($(window).width() <= 740)) {

        $('.digitool--tile').click(function (event) {
          event.preventDefault();
          /* Stop-gap before proper implementation */
          window.alert('Please visit this page on a desktop computer to download this content.');
        });
    }

    //digitools stuff
      var sponsorUrl  = $('.addcode--wrapper .textbox').val();
      var re = new RegExp(sponsorUrl,"g");
      var copiedCode;

      $('.addcode--wrapper .button').click(function () {
        copiedCode = $(this).parent().find(".textbox").val();
        $('.copycode--wrapper .textbox').each( function (){
          $(this).text($(this).text().replace(re, copiedCode));
        });
      });

      $('.copycode--wrapper .button').click(function () {
        $(this).parent().find(".textbox").select();
      });
  };

  Drupal.behaviors.sportrelief_2014.schoolstoolbox = function (context) {

    var schoolbox = $(context).find('.view-id-schools_toolbox');

    if (schoolbox.length === 0) {
      return;
    }

    var tabArray = [];
    var tabArray2 = [];
    var delta = 0;

    $('.tab-nav--title').each(function (){
      delta++;
      tabArray[delta-1] = $(this).text();
      tabArray2[delta-1] = $(this).text().replace(/\s/g,"-").replace(/[^a-zA-Z0-9\-]+/g,'').toLowerCase();
    });

    var param = document.URL.split('#')[1];

    if (param) {
      var anchor = param.split('?')[0];
      if (anchor) {
        var x = tabArray2.indexOf(anchor);
        $('.tab-nav--title:contains("'+tabArray[x]+'")').trigger('click');
      }
    }

  };


  // Homepage video show/hide
  Drupal.behaviors.sportrelief_2014.front_full_width_promo_slider = function (context) {
    var fullWidthSlider = $('.front .slider--full-width');
    var oldId = null;
    var alreadyPlayed = false;
    var videoElement;

    // On touch device, pause slider auto-rotate, hide pause button
    if (('ontouchstart' in window) || window.DocumentTouch && document instanceof DocumentTouch ) {
      if ($('.front .slider--full-width').length > 0 ){
        fullWidthSlider.flexslider("pause");
      }
    }

    fullWidthSlider.find('.mejs-overlay-play').on('click', null, function (){
      videoElement = $(this).parent();
      var currId = videoElement.closest('.slider-content').attr("id");

      if (currId !== oldId && alreadyPlayed) {
        alreadyPlayed = false;
        videoElement.find('.mejs-container').show();
      }

      if (alreadyPlayed === true) {
        videoElement.find('.mejs-container, #cboxClose').toggle();
      } else {
        videoElement.append('<button type="button" id="cboxClose">Close</button>');
        alreadyPlayed = true;
      }

      oldId = currId;
      fullWidthSlider.flexslider("pause");
      fullWidthSlider.addClass('video-active');

    });

    fullWidthSlider.on('click', '#cboxClose', function (){
      videoElement = $(this).parent();
      videoElement.find('#cboxClose').hide();
      videoElement.find('.mejs-container').hide();
      videoElement.find('.mejs-overlay-play').show();
      videoElement.find('.mejs-button')[0].click();
      fullWidthSlider.removeClass('video-active');
    });
  };

  // Custom js for partners scroller/carousel to allow more control than flexslider
  Drupal.behaviors.sportrelief_2014.partners_carousel = function () {

    var carousel = $('body').find('.partners-carousel--wrapper');
    if (carousel.length === 0 || $(window).width() <= 740) {
      return;
    }

    var partnerArray = []; 
    var partners = carousel.find('span');

    $(partners).each(function () {
      partnerArray.push($(this).data('imgclass'));
    });

    var partnersTotal = partnerArray.length;
    var delta = 0;
    $('.partners-carousel--wrapper').addClass("" + String(partnerArray[delta]));

    setInterval(function(){
      setTimeout(function(){
        $('.partners-carousel--wrapper').fadeOut(350,function(){
          $('.partners-carousel--wrapper').removeClass("" + String(partnerArray[delta]));
          delta++;
          if (delta >= partnersTotal) { delta = 0;}
          $('.partners-carousel--wrapper').addClass("" + String(partnerArray[delta]));
          $('.partners-carousel--wrapper').fadeIn(350);
        });
      },500);
    },3000);
  };


  // Specific kids play games section JS
  Drupal.behaviors.sportrelief_2014.kids_play_games_section = function (context) {

    if ($('body').hasClass('context-play-games')) {

      // Change a number of classes on unpredictable FlexSlider work.
      $('.context-play-games .promo-wrapper .pledge-listing--swim').removeClass('prefix-2').addClass('prefix-3');
      $('.context-play-games .promo-wrapper .pledge-listing--run').removeClass('prefix-1').removeClass('suffix-1');

      // This is not the best solution but a timeboxed hack.
      $('.context-play-games .subpod-wrapper .alpha').addClass('prefix-3').removeClass('alpha');
      $('.context-play-games .subpod-wrapper .grid-8').removeClass('grid-8').addClass('grid-6');

      // Add CTA to bottom of play-games widget.
      // This is horrible.
      $('.kids-bg .subpod-wrapper .container-24').append('<div class="kids-pledge-widget--wrapper"><div class="kids-pledge-widget--cta"><a class="kids-pledge-widget--noformatlink" href="/play-games/welcome-to-the-super-duper-ideas-machine">Get your name on the display!</a><a class="button" href="/event-info/enter-now">Grab a grown up and enter an event here.</a></div><h2 class="kids-pledge-widget--leader">Which event do you want to do?</h2><div class="kids-pledge-widget--text"><a href="/play-games/info-for-parents-and-guardians">Parents/guardians, get more info.</div></div>');

      // Remove various elements from DOM on narrow version.
      $('.responsive-layout-narrow.context-play-games.kids-bg .promo-wrapper #flexslider_views_slideshow_pledge_listing-block_3').remove();

      $('.responsive-layout-narrow.context-play-games.kids-bg .promo-wrapper .pledge-listing--run').removeClass('grid-6').addClass('grid-9');
      $('.responsive-layout-narrow.context-play-games.kids-bg .promo-wrapper .pledge-listing--swim').removeClass('grid-6').addClass('grid-9');

/*
      // SRSITE-1401 Show Feedback bar on Kids Section
      // Find if in /play-games/ section, any page.
      if (window.location.pathname.split("/")[1] === "play-games" && $(window).width() > 1024) {
        $("body").prepend('<a class="kids-section-pop-up-survey" href="https://www.surveymonkey.com/s/SportRelief2014" target="_blank">Take The Survey</a>');
      }
*/
    }

  };

  // If you are considering adding code to the $(document).ready(), consider if
  // creating a Drupal.behavior.group.fn (context) {}; is cleaner or appropriate
  $(document).ready(function () {

    // OPTIONAL Highlight empty hrefs
    // $('a[href=""]').addClass('dead-link');

    // Open downloads and those explicitly with the external class as _blank
    $('a.download-link, a.external-link').not('.normal-link').attr('target', '_blank');

    // If a.external-link tag contains mailto, do not open new window
    $('a.external-link[href^="mailto:"]').attr('target', '_self');

    // Autosubmits any forms with 'autosubmit-select' class select boxes
    $('.autosubmit-select').on('change', function (){
      $(this).closest("form").submit();
    });

    // Highlight high scores widget
    // e.g. you go to the page via /play-games/high-scores?game-jump
    // the Jump Game column will become highlighted.
    if (this.location.pathname === '/play-games/high-scores') {
      if (this.location.search.indexOf('game-jump') !== -1) {
        $('#game-jump').addClass('selected');
      }
      if (this.location.search.indexOf('game-drop') !== -1) {
        $('#game-drop').addClass('selected');
      }
      if (this.location.search.indexOf('game-hatch') !== -1) {
        $('#game-hatch').addClass('selected');
      }
    }

    if (Drupal.ajax) {
      Drupal.ajax.prototype.commands.viewsScrollTop = null;
    }

    // @todo understand why this needs to be here and not in Drupal.behaviors
    Drupal.behaviors.sportrelief_2014.challenge_davina_render();
    Drupal.behaviors.sportrelief_2014.challenge_alex_render();
    Drupal.behaviors.sportrelief_2014.showcase_scroller($("body"));
    Drupal.behaviors.sportrelief_2014.colorbox_metatags($("body"));


  });

  Drupal.behaviors.sportrelief_2014.colorbox_metatags = function (context) {

    /* Deals with creating information for the share pop-up when a video is shared via the colorbox overlay. */

    if ($('body').find('.node-link.colorbox-node').length === 0 || $('body').hasClass('no-social')) {
      return;
    }

    var url, image, title, body;

    $('.node-link.colorbox-node').on("click", function () {

      url = $(this).attr('href');
      url = url.substring(0, url.lastIndexOf('?width'));

      $(document).ajaxStop(function () {

        title = encodeURIComponent($('#cboxLoadedContent .node-video').find('h4').text());

        body = $('#cboxLoadedContent .node-video').find('.field-name-body').text();

        if( body.length > 100 ) {
          body = body.substring(0,97)+"...";
        }

        body = encodeURIComponent(body);

        image = $('#cboxLoadedContent .node-video .field-name-field-video-url .cr_video_layer span img').attr("src");

        if (image.substring(0, 7) !== "http://") {
          image = "http://" + image;
        }

        image = encodeURIComponent(image);

        // Share markup as used in CR General module
        var twitterblock = '<li><a href="#" onclick="window.open(\'http://twitter.com/home/?status=' + body + ': ' +url+ '\',\'MyWindows\',\'width=626,height=436\');return false;"><span class="nav-social-sprite sprite-tweet"></span></a></li></a></li>';

        var colorboxShare = '<ul class="share-links"><li class="facebook"><a href="#" onclick="window.open(\'http://www.facebook.com/sharer.php?s=100&p[url]='+ url+'&p[images][0]='+image+'&p[title]='+title+'&p[summary]='+body+'\',\'MyWindows\',\'width=626,height=436\');return false;"><span class="nav-social-sprite sprite-fb"></span></a></li>' + twitterblock + '<li><a href="#" onclick="window.open(\'https://plus.google.com/share?url=' + url +'\',\'MyWindows\',\'width=626,height=436\');return false;"><span class="nav-social-sprite sprite-google"></span></a></li></ul>';

        $('#cboxLoadedContent').find('.sharelinks--colorbox ul.share-links').replaceWith(colorboxShare);
      });

    });

  };


  // Use this $(window).load() with caution, it's not a good idea to mix
  // $(document).ready(), Drupal.behavior and window.load() for no real reason.
  // Some exceptions are to be made e.g. with Flash Games and image-heavy
  // widgets on the website.
  $(window).load(function () {
    // allow /play-games#hash to persist 'selected' slide.
    if ($('body').hasClass('context-play-games')) {
      if(window.location.hash !== '') {
        var playGamesHashSlide = window.location.hash.split("tabs-fun_and_games_landing-middle-")[1].replace(/[^0-9]/g,'');

        // if this is not an integer, do not process.
        if (playGamesHashSlide % 1 === 0) { return; }

        // Change FlexSlider slide and click an anchor.
        $("#mini-panel-fun_and_games_landing #flexslider-1").flexslider(playGamesHashSlide);
        $('a[href="#tabs-fun_and_games_landing-middle-' + playGamesHashSlide + '"]').trigger('click');
      }
      if (0 < window.location.search.indexOf('character')) {
        $('div#tabs-fun_and_games_landing-middle-0 .interstitial').trigger('click');
      }
    }
  });

})(jQuery);
