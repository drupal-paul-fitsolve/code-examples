/**
 * @file
 * Javascript logic for the pledge submission flow.
 */

(function ($) {

  Drupal.behaviors.srPledgeSubmit = {
    attach: function (context) {
      Drupal.behaviors.srPledgeSubmit.init();
    }
  };

  /**
   *  Attach global events and kick off step one
   */
  Drupal.behaviors.srPledgeSubmit.init = function() {
    Drupal.behaviors.srPledgeSubmit.steps = $('.pledge-step');
    Drupal.behaviors.srPledgeSubmit.stepOne();
    Drupal.behaviors.srPledgeSubmit.steps.find('[href=#pledge-step--four]').scrollTo({ offset: -200, speed: 5000, easing: 'swing'});

    // The user can scroll down to the step four form at any time.
    Drupal.behaviors.srPledgeSubmit.stepFour.init();
  };

  /**
   *  Attach events to buttons
   */
  Drupal.behaviors.srPledgeSubmit.stepOne = function() {
    var step = Drupal.behaviors.srPledgeSubmit.changeStep('one');
    step.on("click", ".button", function() {
      var href = $(this).attr('href');
      if(href === '#pledge-step--two') {
        Drupal.behaviors.srPledgeSubmit.stepTwo();
      }
      if(href === '#pledge-step--four') {
        Drupal.behaviors.srPledgeSubmit.stepFour();
      }
    });
  };

  /**
   *  Submit the form asynccronusly, await any errors returned
   */
  Drupal.behaviors.srPledgeSubmit.stepTwo = function() {
    Drupal.behaviors.srPledgeSubmit.changeStep('two');
      var $pledgeForm = $('#sr-fun-and-games-pledge-submit-form');
      $pledgeForm.on('submit', function(e) {

        e.preventDefault();
        $pledgeForm.find('input').removeClass('error');
        //pass value of first select list chosen by the user down to the ideas machine select list
        var selectVal = $( "#edit-pledge--2 option:selected" ).text();
        selectVal = selectVal.toLowerCase();
        $("#edit-pledge").val(selectVal);
        $pledgeForm.addClass('is-loading');
        var action = $pledgeForm.attr('action');
        var formData = $pledgeForm.serialize();
        $.post(action, formData, function(data) {
          $pledgeForm.removeClass('is-loading');
          if(data === null) {
            Drupal.behaviors.srPledgeSubmit.stepTwo.addPledge(formData);
            Drupal.behaviors.srPledgeSubmit.stepThree();
            $('.kids-pledge-bg .promo-wrapper .container-24').css('background-image','url(/sites/sportrelief.com/themes/sport_relief_2014/images/components/backgrounds/Name_Ticker_Clicked.gif?'+Math.random().toString(36).replace(/[^a-z]+/g, '') + ')');
            setTimeout(function() { $('.kids-pledge-bg .promo-wrapper .container-24').css('background-image','')} , 2000  );
          }
          else {
            Drupal.behaviors.srPledgeSubmit.stepTwo.validate(data);
          }
        }, 'json');
      });
  };

  /**
   *  Add the form submission data as a new pledge to the correct flexslider
   *  @param formData
   *    The information from the pledge submission form.
   */
  Drupal.behaviors.srPledgeSubmit.stepTwo.addPledge = function(formData) {
    var data = formData.split('&');

    // Objectify form data
    var pledge = {};
    for (var i = data.length - 1; i >= 0; i--) {
      var values = data[i].split('=');
      pledge[values[0]] = values[1];
    }

    Drupal.behaviors.srPledgeSubmit.stepTwo.pledge = pledge;

    var newSlide = Drupal.behaviors.srPledgeSubmit.pledgeTemplate(pledge);
    var slider;

    if(pledge.pledge === 'swim') {
      flexsliderTarget = Drupal.settings.flexslider_views_slideshow['#flexslider_views_slideshow_main_pledge_listing-block_1'].targetId;
      slider = $(flexsliderTarget + ' .flexslider').data('flexslider');
      $("#flexslider_views_slideshow_main_pledge_listing-block_2 .flexslider").fadeTo("slow", 0.3);
      $("#flexslider_views_slideshow_main_pledge_listing-block_3 .flexslider").fadeTo("slow", 0.3);
      $('#flexslider_views_slideshow_pledge_listing-block_1 li:nth-child(2) h3').text(pledge.name);
    }
    if(pledge.pledge === 'run') {
      flexsliderTarget = Drupal.settings.flexslider_views_slideshow['#flexslider_views_slideshow_main_pledge_listing-block_2'].targetId;
      slider = $(flexsliderTarget + ' .flexslider').data('flexslider');
      $("#flexslider_views_slideshow_main_pledge_listing-block_1 .flexslider").fadeTo("slow", 0.3);
      $("#flexslider_views_slideshow_main_pledge_listing-block_3 .flexslider").fadeTo("slow", 0.3);
      $('#flexslider_views_slideshow_pledge_listing-block_2 li:nth-child(2) h3').text(pledge.name);
    }
    if(pledge.pledge === 'cycle') {
      flexsliderTarget = Drupal.settings.flexslider_views_slideshow['#flexslider_views_slideshow_main_pledge_listing-block_3'].targetId;
      slider = $(flexsliderTarget + ' .flexslider').data('flexslider');
      $("#flexslider_views_slideshow_main_pledge_listing-block_1 .flexslider").fadeTo("slow", 0.3);
      $("#flexslider_views_slideshow_main_pledge_listing-block_2 .flexslider").fadeTo("slow", 0.3);
      $('#flexslider_views_slideshow_pledge_listing-block_3 li:nth-child(2)  h3').text(pledge.name);
    }
    
    slider.flexAnimate(2);

  };

  /**
   * This html template for a pledge
   * @param data
   *   An object containing the pledge information:
   *   - name: The name of the person making the pledge
   *   - age: The age of the person making the pledge
   *   - pledge: The pledge category. Run/Cyce/Swim/Something.
   */
  Drupal.behaviors.srPledgeSubmit.pledgeTemplate = function(data) {
    var output = '<li class="flexslider-views-slideshow-main-frame-row flexslider_views_slideshow_slide views_slideshow_cycle_hidden views-row-odd">';
    output += '<h3 class="pledge__name">' + data.name + '</h3>';
    output += '<span class="pledge__age">' + data.age + '</span>';
    output += '<div class="pledge__category">wants to <span class="pledge__category__run">' + data.pledge + '</span></div>';
    output += '</li>';
    return output;
  };

  /**
   * Output the validation data to the form
   * @param data
   *   An object containing the information returns from the server
   *   - error: The first form item to error
   * @todo This could be much better but there are no error designs.
   *   Add Also the php function reurns minimal info.
   * @see cr_ig_add_pledge()
   * @todo Add clientside validation. Less hits on the server.
   */
  Drupal.behaviors.srPledgeSubmit.stepTwo.validate = function(data) {
    $('input[name=' + data.error + ']').addClass('error');
    if ('name' == data.error) $('#validationmessage').text('X Just your first name!');
    if ('age' == data.error) $('#validationmessage').text('X Your age must be between 0-99 years');  
  };

  /**
   *  Add the form submission data as a new pledge to the correct flexslider
   *  @param formData
   *    The information from the pledge submission form.
   */
  Drupal.behaviors.srPledgeSubmit.stepThree = function() {
    var step = Drupal.behaviors.srPledgeSubmit.changeStep('three');
    step.on("click", ".button", function() {
      Drupal.behaviors.srPledgeSubmit.stepFour(
        Drupal.behaviors.srPledgeSubmit.stepTwo.pledge.pledge
     );
     setTimeout(
       function() { 
         var pledgetype = $('#sr-fun-and-games-pledge-submit-form li.dk_option_current a').attr('data-dk-dropdown-value');
         $('a[data-dk-dropdown-value="' + pledgetype + '"]').trigger('click'); 
       }, 5000); 
    });
  };

  /**
   *  All this does is pregenerate an idea.
   *  @param category
   *    The pledge category to display an idea from.
   */
  Drupal.behaviors.srPledgeSubmit.stepFour = function(category) {
    var step = Drupal.behaviors.srPledgeSubmit.changeStep('four');
    if(category) {
      Drupal.behaviors.srPledgeSubmit.stepFour.generateIdea(category);
    }
  };

  /**
   *  Step four is always shown, so the events need to be initialised on load.
   */
  Drupal.behaviors.srPledgeSubmit.stepFour.init = function() {
    var $ideaForm = $('.idea-generation-form');
    $ideaForm.on('submit', function(e) {
      e.preventDefault();
      var category = $ideaForm.find('#edit-pledge').val();
      Drupal.behaviors.srPledgeSubmit.stepFour(category);
      $('.kids-pledge-bg .content-row-2-wrapper').css('background-image','url(/sites/sportrelief.com/themes/sport_relief_2014/images/components/backgrounds/Lab_Clicked.gif?'+Math.random().toString(36).replace(/[^a-z]+/g, '') + ')');
      setTimeout(function() { $('.kids-pledge-bg .content-row-2-wrapper').css('background-image','')} , 2000  );
    });
    $('.pledge-step--four').on('click', '#buttonlike', function(e) {
      var buttonVal = $(this).parent().parent().find('h6').attr('class');
      if(buttonVal == 'pledge-idea__title pledge-idea__title--freestyle') {
        $('.enter-event').hide();
        $('.giving-page').show();
      }else {
        $('.giving-page').hide();
        $('.enter-event').show();
      }
      e.preventDefault();
      $('.kids-pledge-bg .content-row-2-wrapper').css('background-image','url(/sites/sportrelief.com/themes/sport_relief_2014/images/components/backgrounds/Lab_Clicked.gif?'+Math.random().toString(36).replace(/[^a-z]+/g, '') + ')');
      setTimeout(function() { $('.kids-pledge-bg .content-row-2-wrapper').css('background-image','')} , 2000  );
      Drupal.behaviors.srPledgeSubmit.stepFive();
    });
    $('.pledge-step--four').on('click', '#buttonanother', function(e) {
      e.preventDefault();
      var category = $ideaForm.find('#edit-pledge').val();
      Drupal.behaviors.srPledgeSubmit.stepFour(category);
      $('.kids-pledge-bg .content-row-2-wrapper').css('background-image','url(/sites/sportrelief.com/themes/sport_relief_2014/images/components/backgrounds/Lab_Clicked.gif?'+Math.random().toString(36).replace(/[^a-z]+/g, '') + ')');
      setTimeout(function() { $('.kids-pledge-bg .content-row-2-wrapper').css('background-image','')} , 2000  );
    });
    $('.pledge-step--four').on('click', '#btnback', function(e) {
      e.preventDefault();
      if ($('#btnback').hasClass('enabled')) {
        var prev = Drupal.behaviors.srPledgeSubmit.ideasprevious.pop();
        if (undefined === prev) {
          $('#btnback').removeClass('enabled');
        } else {
          Drupal.behaviors.srPledgeSubmit.ideasnext.push($('#ideatext').text());
          $('#btnnext').addClass('enabled');
          $('#ideatext').text(prev);
          if (2 > Drupal.behaviors.srPledgeSubmit.ideasprevious.length) $('#btnback').removeClass('enabled');
        }
      }
    });
    $('.pledge-step--four').on('click', '#btnnext', function(e) {
      e.preventDefault();
      if ($('#btnnext').hasClass('enabled')) {
        var next =  Drupal.behaviors.srPledgeSubmit.ideasnext.pop();
        if (undefined === next) {
          $('#btnnext').removeClass('enabled');
        } else {
          Drupal.behaviors.srPledgeSubmit.ideasprevious.push($('#ideatext').text());
          $('#btnback').addClass('enabled');
          $('#ideatext').text(next);
          if (1 > Drupal.behaviors.srPledgeSubmit.ideasnext.length) $('#btnnext').removeClass('enabled');
        }
      }
    });
    $('#edit-pledge').dropkick({
      change: function (value, label) {
        Drupal.behaviors.srPledgeSubmit.stepFour(value);
      }
    });
  };


  /**
   *  Selects an idea at random and adds it to the page.
   *  @param category
   *    The pledge category to display an idea from.
   */
  Drupal.behaviors.srPledgeSubmit.stepFour.generateIdea = function(category) {
    $('.pledge-step--four').show();
    var ideas = Drupal.behaviors.srPledgeSubmit.ideas[ category ];
    var idea = ideas[Math.floor(Math.random()*ideas.length)];
    Drupal.behaviors.srPledgeSubmit.ideasprevious.push(idea.text);
    var ideaMarkup = Drupal.behaviors.srPledgeSubmit.stepFour.ideaTemplate(category, idea);
    $('.pledge-step--four').html(ideaMarkup);
    if (1 < Drupal.behaviors.srPledgeSubmit.ideasprevious.length) $('#btnback').addClass('enabled');
  };

  /**
   *  HTML template for an idea.
   *  @param category
   *    The pledge category to display an idea from.
   */
  Drupal.behaviors.srPledgeSubmit.stepFour.ideaTemplate = function(category, data) {
    var output = '<h6 id="ideatext" class="pledge-idea__title pledge-idea__title--' + category + '">' + data.text + '</h6>';
    output += '<p class="text-align-center leader pledge-idea__buttons" ><a id="btnback" href="#">back</a><a id="buttonlike" class="button button--run button--large" href="#">I want to do this idea!</a>&nbsp;<a id="buttonanother" class="button button--run button--large" href="#">Give me another idea</a><a id="btnnext" href="#">Next</a></p>';
    return output;
  };

  /**
   *  Show the final step.
   */
  Drupal.behaviors.srPledgeSubmit.stepFive = function() {
    $('.pledge-step--four').hide();
    Drupal.behaviors.srPledgeSubmit.changeStep('five');
  };


  // Change the active step aka hide/show
  // Returns the active step as a jquery object so you can reduce your selectors
  Drupal.behaviors.srPledgeSubmit.changeStep = function(step) {
    var nextStep = Drupal.behaviors.srPledgeSubmit.steps.removeClass('is-active').filter('.pledge-step--' + step).addClass('is-active');
    return nextStep;
  };

  /**
   *  Turn off the pledge sliders. For performance.
   *  @todo build this
   */
  Drupal.behaviors.srPledgeSubmit.killSliders = function() {
  };

  /**
   *  The idea content.
   *  @todo Possibly better to store this on the server side and load this into
   *  Drupal.settings. In theory we could make the content accessible to no JS.
   */
  Drupal.behaviors.srPledgeSubmit.ideasnext = [];
  Drupal.behaviors.srPledgeSubmit.ideasprevious = [];
  Drupal.behaviors.srPledgeSubmit.ideas =  {};
  Drupal.behaviors.srPledgeSubmit.ideas.swim = new Array(
    {
      text: 'Tell friends and family how they money you’re raising helps change lives.',
    },
    {
      text: 'Get sponsored to try different swim strokes.',
    },
    {
      text: 'Ask your teachers to sponsor you.',
    },
    {
      text: 'Post updates about your training on your Giving Page.',
    },
    {
      text: 'Give out your Giving Page details so friends can sponsor you.',
    },
    {
      text: 'Ask your parents to get sponsors for you at work.',
    },
    {
      text: 'Ask your most generous friend first to sponsor you and others might copy.',
    },
    {
      text: 'Set a fundraising target and tell everyone so they help you reach it.',
    },
    {
      text: 'Sell some home-baked cakes with your family to raise cash.',
    },
    {
      text: 'Try a sponsored silence to help you raise even more money.',
    }
 );
  Drupal.behaviors.srPledgeSubmit.ideas.run = new Array(
    {
      text: 'Get sponsored to run in your favourite fancy dress outfit.',
    },
    {
      text: 'Do the Mile three-legged with someone in your family.',
    },
    {
      text: 'Run with an egg and spoon for more sponsorship cash.',
    },
    {
      text: 'Get sponsored to do the Mile on a space hopper.',
    },
    {
      text: 'Give out your Giving Page details so friends can sponsor you.',
    },
    {
      text: 'Ask your parents to get sponsors for you at work.',
    },
    {
      text: 'Ask your teachers to sponsor you.',
    },
    {
      text: 'Set a fundraising target and tell everyone so they help you reach it.',
    },
    {
      text: 'Sell some home-baked cakes with your family to raise cash.',
    },
    {
      text: 'Try a sponsored silence to help you raise even more money.',
    }

 );
  Drupal.behaviors.srPledgeSubmit.ideas.cycle = new Array(
    {
      text: 'Tell friends and family how they money you’re raising helps change lives.',
    },
    {
      text: 'Get on your bike in fancy dress to raise even more money.',
    },
    {
      text: 'Ask your teachers to sponsor you.',
    },
    {
      text: 'Post updates about your training on your Giving Page.',
    },
    {
      text: 'Give out your Giving Page details so friends can sponsor you.',
    },
    {
      text: 'Ask your parents to get sponsors for you at work.',
    },
    {
      text: 'Ask your most generous friend to sponsor you first and others might copy.',
    },
    {
      text: 'Set a fundraising target and tell everyone so they help you reach it.',
    },
    {
      text: 'Sell some home-baked cakes with your family to raise cash.',
    },
    {
      text: 'Try a sponsored silence to help you raise even more money.',
    }
 );
  Drupal.behaviors.srPledgeSubmit.ideas.freestyle = new Array(
    {
      text: 'Get sponsored to wear a rival’s football shirt to a match.',
    },
    {
      text: 'Get sponsored to space hop around your house for a day. ',
    },
    {
      text: 'Get sponsored to walk or cycle to school for a week.',
    },
    {
      text: 'Try a sponsored silence to help you raise even more money.',
    },
    {
      text: 'Set up a Glee club with your friends and put on a show.',
    },
    {
      text: 'Do your own bike ride with a parent/guardian.',
    },
    {
      text: 'Get sponsored to give up your favourite food for a week.',
    },
    {
      text: 'Dress up as your favourite sports star for the day.',
    },
    {
      text: 'Get paid to do the housework.',
    },
    {
      text: 'Sell some home-baked cakes with your family to raise cash.',
    }
 );


})(jQuery);
