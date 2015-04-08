(function ($) {

$(document).ready(function () {
  $.fn.healthQuiz({});
});

$.fn.healthQuiz = function (options) {

    $.fn.healthQuiz.settings = $.extend({
      container : '.health-quiz-container'
    }, options );

    $.fn.healthQuiz.dataSetup( function() {
      fancySteps.build(fancySteps.init);
    });

  };

fancySteps = {};

/**
 * Initial behaviour.
 */
fancySteps.init = function () {
  fancySteps.stepIn($('.fancy-multistep__step.is-active'));
};

/**
 * Build the initial quiz state.
 * @param callback
 *   Callback function
 */
fancySteps.build = function(callback) {
  output = '<ul class="fancy-multistep health-quiz">';
  output += '</ul>';
  $($.fn.healthQuiz.settings.container).html(output);
  fancySteps.buildStep('step1');
  callback();
};

/**
 * Build a single quiz step.
 * @param step
 *   The kind of step it is. Final or no?
 */
fancySteps.buildStep = function(step) {
  if(step === 'final') {
    finalStep = healthQuizLogic.calculateFinalStep();
    $.fn.healthQuiz.data[finalStep].id = finalStep;
    output = fancySteps.templates.multiStepFinal($.fn.healthQuiz.data[finalStep]);
  } else {
    output = fancySteps.templates.multiStep($.fn.healthQuiz.data[step]);
  }
  $('.health-quiz').append(output);
  fancySteps.attach();
};


/**
 * Attach events to a health quiz step.
 */
fancySteps.attach = function() {
  $('.fancy-multistep__choice').on('click.fancy', function(e) {
    var nextStep = $(this).attr('data-next-step');
    var id = $(this).attr('id');
    if(nextStep !== 'final') {
      healthQuizLogic.log(id);
    }
    fancySteps.buildStep(nextStep);
    fancySteps.stepOut($('.fancy-multistep__step.is-active'));
  });
  $('.health-quiz__back').on('click.fancy', function(e) {
    e.preventDefault();
    healthQuizLogic.wipe(function() {
      fancySteps.build(fancySteps.init);
    });
  });
};

/**
 * Move a step off stage.
 * @param $active
 *   A jQuery object of the active step.
 */
fancySteps.stepOut = function($active) {
  fancySteps.textOut($active);
  fancySteps.rollOut($active);
};

/**
 * Move a step on stage.
 * @param $active
 *   A jQuery object of the active step.
 */
fancySteps.stepIn = function($active) {
   fancySteps.textIn($active);
   fancySteps.rollIn($active);
};

/**
 * Fade out the text for an active step.
 * @param $active
 *   A jQuery object of the active step.
 */
fancySteps.textOut = function($active) {
  var $fancyText = $active.find('.fancy-multistep__subtitle, .fancy-multistep__title, .fancy-multistep__final-title, .fancy-multistep__choice__text');
  $fancyText.removeClass('fade-in').addClass('fade-out');
};

/**
 * Fade in the text for an active step.
 * @param $active
 *   A jQuery object of the active step.
 */
fancySteps.textIn = function($active) {
  var $fancyText = $active.find('.fancy-multistep__subtitle, .fancy-multistep__title, .fancy-multistep__final-title, .fancy-multistep__choice__text');
  if(Modernizr.csstransitions) {
    $fancyText.last().one("webkitTransitionEnd transitionend msTransitionEnd oTransitionEnd", fancySteps.rollIn);
    $fancyText.removeClass('fade-out').addClass('fade-in');
  }
  else {
    fancySteps.rollIn();
  }
};

/**
 * Slide out choices for an active step.
 * @param $active
 *   A jQuery object of the active step.
 */
fancySteps.rollOut = function($active) {
  var $fancyChoices = $active.find('.fancy-multistep__choice');
  if(Modernizr.csstransitions) {
    $fancyChoices.last().one("webkitTransitionEnd transitionend msTransitionEnd oTransitionEnd", fancySteps.next);
    $fancyChoices.removeClass('rollin').addClass('rollout');
  }
  else {
    fancySteps.next();
  }
};

/**
 * Slide in choices for an active step.
 * @param $active
 *   A jQuery object of the active step.
 */
fancySteps.rollIn = function() {
  var $active = $('.fancy-multistep__step.is-active');
   var $fancyChoices = $active.find('.fancy-multistep__choice, .health-quiz__actions');
   $fancyChoices.removeClass('rollout').addClass('rollin');
};

/**
 * Trigger the stepIn once stepOut has completed.
 * @param e
 *   The triggering event, if there is one.
 */
fancySteps.next = function(e) {
  if (typeof e !== 'undefined') {
    e.stopPropagation();
  }
  var $current = $('.fancy-multistep__step.is-active');
  var $next = $('.fancy-multistep__step.is-active + .fancy-multistep__step');
  $current.removeClass('is-active');
  $next.addClass('is-active');
  timeoutID = window.setTimeout(function(){
    fancySteps.stepIn($next);
  }, 100);
};

fancySteps.templates = {};

/**
 * The HTML template for a a helath quiz step.
 * @param data
 *   An object containing data about the step.
 *   - isActive
 *       Boolean
 *   - pager
 *     Information about the pager.
 *     @see fancySteps.templates.pager().
 *   - title
 *     Text for the main step title/question.
 *   - subtitle
 *     Text for the subtitle.
 *   - choices
 *     An array of answer choices for the step.
 *     @see fancySteps.templates.choice().
 */
fancySteps.templates.multiStep = function(data) {
  theClasses = 'fancy-multistep__step';
  if(data.isActive){
    theClasses += ' is-active';
  }
  var output = '<li class="' + theClasses + '">';
  if(data.pager !== 0) {
   output += fancySteps.templates.pager(data.pager);
  }
  if(data.subtitle) {
    output += '<h3 class="fancy-multistep__subtitle text-align-center">';
    output += data.subtitle;
    output += '</h3>';
  }
  output += '<h3 class="fancy-multistep__title text-align-center trailer">';
  output += data.title;
  output += '</h3>';
  if(data.choices) {
    output += '<ul class="fancy-multistep__choices grid-24 alpha omega">';
    for (var key in data.choices) {
      output += fancySteps.templates.choice(data.choices[key]);
    }
    output += '</ul>';
  }
  output += '</li>';
  return output;
};

/**
 * HTML template for the final steps.
 * @param data
 *   An object containing data about the step.
 *   - id
 *     This unique id for this step, so we can apply the correct background image.
 *   - title
 *     Text for the main step title/question.
 *   - subtitle
 *     Text for the subtitle.
 *   - ctas
 *     An array of objects containing the information for the three cta links.
 *     - href
 *     - text
 *     - onclick
 *       The onclick JS for sharing.
 */
fancySteps.templates.multiStepFinal = function(data) {
  var output = '<li class="fancy-multistep__step fancy-multistep__step--final ' + data.id + '" >';
  output += '<div class="grid-18 prefix-3 narrow-grid-24 narrow-prefix-0">';
    output += '<div class="grid-9 narrow-grid-12 leader-double">';
      output += '<h2 class="fancy-multistep__final-title">';

      output += '<span class="grey">';
        output += data.subtitle;
      output += '</span>';

      output += data.title;
      output += '</h2>';
    output += '</div>';
  output += '</div>';

  output += '<a href="#" class="health-quiz__back">Back to Start</a>';
  output += '<div class="leader-minor health-quiz__actions">';
  output += '<div class="grid-18 narrow-grid-24 container-center">';
  output += '<a href="' + data.ctas.download.href + '" class="button button--large button--dark-grey">' + data.ctas.download.text + '</a>';
  output += '<a href="' + data.ctas.enter.href + '" class="button button--large button--' + data.category + '">' + data.ctas.enter.text + '</a>';
  output += '<a onclick="' + data.ctas.facebook.onclick + '" href="' + data.ctas.facebook.href + '" class="button button--large button--facebook">' + data.ctas.facebook.text + '</a>';
  output += '<a onclick="' + data.ctas.twitter.onclick + '" href="' + data.ctas.twitter.href + '" class="button button--large button--twitter">' + data.ctas.twitter.text + '</a>';
  output += '</div>';
  output += '</div>';
  output += '</li>';
  return output;
};

/**
 * HTML template for the quiz pager.
 * This is rebuilt on every step.
 * @param activeStep
 *   An integer decribing the current active step.
 * @todo The number of steps could be global.
 */
fancySteps.templates.pager = function(activeStep) {
 var steps = 4;
 var output = '<ul class="fancy-multistep-pager">';
  for (var i = 1; i <= steps; i++) {
    CSSClasses = 'fancy-multistep-pager__item';
    if(i <= activeStep) {
      CSSClasses += ' is-active';
    }
    output += '<li class="' + CSSClasses + '">';
    output += i;
    output += '</li>';
  }
 output += '</ul>';
 return output;
};

/**
 * HTML template for a step choice.
 * There is usually three choices in one step.
 * @param data
 *   An object containing data about the choice.
 *   - nextStep
 *       The next step in the quiz.
 *   - id
 *     The unique idea for this choice.
 *     This is important to track the choices made.
 *     We also use it to set the correct icon.
 *     @see healthQuizLogic.log().
 *   - text
 */
fancySteps.templates.choice = function(data) {

  var nextStep = '';
  if(data.nextStep){
   nextStep = ' data-next-step="' + data.nextStep + '"';
  }
  else {
    nextStep = ' data-next-step="final"';
  }
  var output = '<li id="' + data.id + '" class="fancy-multistep__choice clearfix grid-8 leader-mobile omega" ' + nextStep + '>';
  output += '<span class="mobile-grid-8 mobile-alpha fancy-multistep__choice__icon fancy-multistep__choice__icon--' + data.id + '"></span>';
  output += '<span class="mobile-grid-16 mobile-omega fancy-multistep__choice__text">';
  output += data.text;
  output += '</span>';
  output += '</li>';

 return output;

};

healthQuizLogic = {

  /**
   * An array of steps taken by the user.
   */
  steps : [],

  /**
   * Logs the steps taken by the user.
   * This is important so we know which final step to serve.
   * @param step
   *   The unique id of the step taken.
   */
  log : function(step) {
    healthQuizLogic.steps.push(step);
  },
  wipe : function(callback) {
    healthQuizLogic.steps.length = 0;
    callback();
  },

  /**
   * Generates the unique ID of the final step.
   * @return finalStep
   *   The unique id of the final step.
   */
  calculateFinalStep : function() {
    finalStep = healthQuizLogic.steps.join('--');
    return finalStep;
  }
};

/**
 * Constructor for the health quiz step content.
 */
function HealthQuizStep(pager, title, subtitle, category, ctas) {
  this.pager = pager;
  this.subtitle = subtitle;
  this.title = title;
  this.category = category;
  this.ctas = ctas;
}

/**
 * Constructor for the health quiz choice content.
 */
function HealthQuizStepChoice(id, text, nextStep) {
  this.id = id;
  this.text = text;
  this.nextStep = nextStep;
}

/**
 * Health quiz content.
 */
$.fn.healthQuiz.dataSetup = function(callback) {
  $.fn.healthQuiz.data = [];
  $.fn.healthQuiz.data['step1'] = new HealthQuizStep(0, 'Choose your event to get started...', 'Running, Swimming or Cycling? How ready are you?');
  $.fn.healthQuiz.data['step1'].isActive = true;
  $.fn.healthQuiz.data['step1'].choices = [];
  $.fn.healthQuiz.data['step1'].choices['choice1'] = new HealthQuizStepChoice('step1-mile', 'The Mile', 'step2-mile');
  $.fn.healthQuiz.data['step1'].choices['choice2'] = new HealthQuizStepChoice('step1-swim', 'The Swimathon', 'step2-swim');
  $.fn.healthQuiz.data['step1'].choices['choice3'] = new HealthQuizStepChoice('step1-cycle', 'The Cycle', 'step2-cycle');

  $.fn.healthQuiz.data['step2-mile'] = new HealthQuizStep(2, 'What\'s your distance?');
  $.fn.healthQuiz.data['step2-mile'].choices = [];
  $.fn.healthQuiz.data['step2-mile'].choices['choice1'] = new HealthQuizStepChoice('step2-1mile', '1 Mile', 'step3-mile');
  $.fn.healthQuiz.data['step2-mile'].choices['choice2'] = new HealthQuizStepChoice('step2-3mile', '3 Mile', 'step3-mile');
  $.fn.healthQuiz.data['step2-mile'].choices['choice3'] = new HealthQuizStepChoice('step2-6mile', '6 Mile', 'step3-mile');

  $.fn.healthQuiz.data['step3-mile'] = new HealthQuizStep(3, 'How good a runner are you?');
  $.fn.healthQuiz.data['step3-mile'].choices = [];
  $.fn.healthQuiz.data['step3-mile'].choices['choice1'] = new HealthQuizStepChoice('step3-highmile', 'I can run a marathon.', 'step4-mile');
  $.fn.healthQuiz.data['step3-mile'].choices['choice2'] = new HealthQuizStepChoice('step3-middlemile', 'I can probably run few miles.', 'step4-mile');
  $.fn.healthQuiz.data['step3-mile'].choices['choice3'] = new HealthQuizStepChoice('step3-lowmile', 'The only time I run is for the bus.', 'step4-mile');

  $.fn.healthQuiz.data['step4-mile'] = new HealthQuizStep(4, 'How will you run your Mile?');
  $.fn.healthQuiz.data['step4-mile'].choices = [];
  $.fn.healthQuiz.data['step4-mile'].choices['choice1'] = new HealthQuizStepChoice('step4-1mile', 'In sports gear.');
  $.fn.healthQuiz.data['step4-mile'].choices['choice2'] = new HealthQuizStepChoice('step4-2mile', 'In casual, loose clothing');
  $.fn.healthQuiz.data['step4-mile'].choices['choice3'] = new HealthQuizStepChoice('step4-3mile', 'In a ridiculous costume that\'s entirely inappropriate for the demands of running.');

  $.fn.healthQuiz.data['step2-swim'] = new HealthQuizStep(2, 'What\'s your distance?');
  $.fn.healthQuiz.data['step2-swim'].choices = [];
  $.fn.healthQuiz.data['step2-swim'].choices['choice1'] = new HealthQuizStepChoice('step2-1swim', '1.5 km', 'step3-swim');
  $.fn.healthQuiz.data['step2-swim'].choices['choice2'] = new HealthQuizStepChoice('step2-3swim', '2.5 km', 'step3-swim');
  $.fn.healthQuiz.data['step2-swim'].choices['choice3'] = new HealthQuizStepChoice('step2-5swim', '5 km', 'step3-swim');

  $.fn.healthQuiz.data['step3-swim'] = new HealthQuizStep(3, 'How good a swimmer are you?');
  $.fn.healthQuiz.data['step3-swim'].choices = [];
  $.fn.healthQuiz.data['step3-swim'].choices['choice1'] = new HealthQuizStepChoice('step3-highswim', 'I\'m an excellent swimmer', 'step4-swim');
  $.fn.healthQuiz.data['step3-swim'].choices['choice2'] = new HealthQuizStepChoice('step3-middleswim', 'I\'m a decent swimmer', 'step4-swim');
  $.fn.healthQuiz.data['step3-swim'].choices['choice3'] = new HealthQuizStepChoice('step3-lowswim', 'I\'m something of a beginner', 'step4-swim');

  $.fn.healthQuiz.data['step4-swim'] = new HealthQuizStep(4, 'How will you start your swim?');
  $.fn.healthQuiz.data['step4-swim'].choices = [];
  $.fn.healthQuiz.data['step4-swim'].choices['choice1'] = new HealthQuizStepChoice('step4-1swim', 'With a textbook arm-stand back double somersault tuck');
  $.fn.healthQuiz.data['step4-swim'].choices['choice2'] = new HealthQuizStepChoice('step4-2swim', 'I\'ll just sort of jump in and get on with it');
  $.fn.healthQuiz.data['step4-swim'].choices['choice3'] = new HealthQuizStepChoice('step4-3swim', 'With a belly flop');

  $.fn.healthQuiz.data['step2-cycle'] = new HealthQuizStep(2, 'What\'s your distance?');
  $.fn.healthQuiz.data['step2-cycle'].choices = [];
  $.fn.healthQuiz.data['step2-cycle'].choices['choice1'] = new HealthQuizStepChoice('step2-3cycle', '3 Mile', 'step3-cycle');
  $.fn.healthQuiz.data['step2-cycle'].choices['choice2'] = new HealthQuizStepChoice('step2-25cycle', '25 Mile', 'step3-cycle');
  $.fn.healthQuiz.data['step2-cycle'].choices['choice3'] = new HealthQuizStepChoice('step2-50cycle', '50 Mile', 'step3-cycle');

  $.fn.healthQuiz.data['step3-cycle'] = new HealthQuizStep(3, 'How good a cyclist are you?');
  $.fn.healthQuiz.data['step3-cycle'].choices = [];
  $.fn.healthQuiz.data['step3-cycle'].choices['choice1'] = new HealthQuizStepChoice('step3-highcycle', 'I taught Mark Cavendish everything he knows', 'step4-cycle');
  $.fn.healthQuiz.data['step3-cycle'].choices['choice2'] = new HealthQuizStepChoice('step3-middlecycle', 'I\'m not exactly Bradley Wiggins, but I get by.', 'step4-cycle');
  $.fn.healthQuiz.data['step3-cycle'].choices['choice3'] = new HealthQuizStepChoice('step3-lowcycle', 'I can just about ride a child\'s tricycle around my next-door neighbour\'s patio.', 'step4-cycle');

  $.fn.healthQuiz.data['step4-cycle'] = new HealthQuizStep(4, 'How will you start your cycle?');
  $.fn.healthQuiz.data['step4-cycle'].choices = [];
  $.fn.healthQuiz.data['step4-cycle'].choices['choice1'] = new HealthQuizStepChoice('step4-1cycle', 'Proper cycling gear.');
  $.fn.healthQuiz.data['step4-cycle'].choices['choice2'] = new HealthQuizStepChoice('step4-2cycle', 'Skin-tight Lycra, and a pair of stick-on Wiggo sideburns.');
  $.fn.healthQuiz.data['step4-cycle'].choices['choice3'] = new HealthQuizStepChoice('step4-3cycle', 'Fancy Dress.');

  facebookShare = "window.open('http://www.facebook.com/sharer.php?s=100&p[url]=http://www.sportrelief.com/trainingtips&p[images][0]=http://www.sportrelief.com/sites/all/modules/features/sr14_ideas_and_tools/css/images/fb_thumbnail_fitt.png&p[title]=The Sainsbury%27s Sport Relief Games&p[summary]=Just got my training plan for the Sainsbury%27s Sport Relief Games. Enter now and get yours at sportrelief.com/trainingtips', 'facebook-share-dialog', 'width=626,height=436'); return false;";

  twitterShare = "window.open('https://twitter.com/intent/tweet?text=Just+got+my+training+plan+for+the+Sainsbury%27s+Sport+Relief+Games.+Enter+now+and+get+yours+at+sportrelief.com%2Ftrainingtips+%23SR14&source=clicktotweet','twitter-share-dialog','width=626,height=436'); return false;";

  // Provide mileCta defaults as reference.
  mileCtas = { download: { text: 'Download a training plan', href: '#' }, enter: { text: 'Enter the Mile', href: '/event-info/sainsburys-sport-relief-mile'}, facebook: { text: 'Share', href: '#', onclick: facebookShare}, twitter: { text: 'Tweet', href: '#', onclick: twitterShare } };

  // Override CTAs per case
  OneMileCtas = { download: { text: 'Download a training plan', href: '/sites/sportrelief.com/files/files/downloadables/sr14_one_mile_plan.pdf' }, enter: { text: 'Enter the Mile', href: '/event-info/sainsburys-sport-relief-mile'}, facebook: { text: 'Share', href: '#', onclick: facebookShare}, twitter: { text: 'Tweet', href: '#', onclick: twitterShare } };

  OneMileBeginnerCtas = { download: { text: 'Download a training plan', href: '/sites/sportrelief.com/files/files/downloadables/sr14_one_mile_plan_beginner.pdf' }, enter: { text: 'Enter the Mile', href: '/event-info/sainsburys-sport-relief-mile'}, facebook: { text: 'Share', href: '#', onclick: facebookShare}, twitter: { text: 'Tweet', href: '#', onclick: twitterShare } };

  ThreeMileCtas = { download: { text: 'Download a training plan', href: '/sites/sportrelief.com/files/files/downloadables/sr14_three_mile_plan.pdf' }, enter: { text: 'Enter the Mile', href: '/event-info/sainsburys-sport-relief-mile'}, facebook: { text: 'Share', href: '#', onclick: facebookShare}, twitter: { text: 'Tweet', href: '#', onclick: twitterShare } };

  ThreeMileBeginnerCtas = { download: { text: 'Download a training plan', href: '/sites/sportrelief.com/files/files/downloadables/sr14_three_mile_plan_beginner.pdf' }, enter: { text: 'Enter the Mile', href: '/event-info/sainsburys-sport-relief-mile'}, facebook: { text: 'Share', href: '#', onclick: facebookShare}, twitter: { text: 'Tweet', href: '#', onclick: twitterShare } };

  SixMileCtas = { download: { text: 'Download a training plan', href: '/sites/sportrelief.com/files/files/downloadables/sr14_six_mile_plan.pdf' }, enter: { text: 'Enter the Mile', href: '/event-info/sainsburys-sport-relief-mile'}, facebook: { text: 'Share', href: '#', onclick: facebookShare}, twitter: { text: 'Tweet', href: '#', onclick: twitterShare } };

  SixMileBeginnerCtas = { download: { text: 'Download a training plan', href: '/sites/sportrelief.com/files/files/downloadables/sr14_six_mile_plan_beginner.pdf' }, enter: { text: 'Enter the Mile', href: '/event-info/sainsburys-sport-relief-mile'}, facebook: { text: 'Share', href: '#', onclick: facebookShare}, twitter: { text: 'Tweet', href: '#', onclick: twitterShare } };

  $.fn.healthQuiz.data['step1-mile--step2-1mile--step3-highmile'] = new HealthQuizStep(0, 'Just soak up the crowds, the atmosphere and enjoy.', 'For you, no sweat.', 'run', OneMileCtas);

  $.fn.healthQuiz.data['step1-mile--step2-1mile--step3-middlemile'] = new HealthQuizStep(0, 'Just soak up the crowds, the atmosphere and enjoy.', 'You\'ll be fine.', 'run', OneMileCtas);

  $.fn.healthQuiz.data['step1-mile--step2-1mile--step3-lowmile'] = new HealthQuizStep(0, 'you might work up a sweat, but it\'ll be well worth it.', 'Sure,', 'run', OneMileBeginnerCtas);

  $.fn.healthQuiz.data['step1-mile--step2-3mile--step3-highmile'] = new HealthQuizStep(0, 'Just soak up the crowds, the atmosphere and enjoy.', 'You\'ll be fine.', 'run', ThreeMileCtas);

  $.fn.healthQuiz.data['step1-mile--step2-3mile--step3-middlemile'] = new HealthQuizStep(0,  'Just soak up the crowds, the atmosphere and enjoy.', 'You\'ll be fine.', 'run', ThreeMileCtas);

  $.fn.healthQuiz.data['step1-mile--step2-3mile--step3-lowmile'] = new HealthQuizStep(0, 'but no walk in the park. When you finish, you\'ll feel great.', 'Not a marathon,', 'run', ThreeMileBeginnerCtas);

  $.fn.healthQuiz.data['step1-mile--step2-6mile--step3-highmile'] = new HealthQuizStep(0, 'to give you a good workout and a fantastic feeling too.', 'A decent distance', 'run', SixMileCtas);

  $.fn.healthQuiz.data['step1-mile--step2-6mile--step3-middlemile'] = new HealthQuizStep(0, 'but no walk in the park. When you finish, you\'ll feel great.', 'Not a marathon,', 'run', SixMileCtas);

  $.fn.healthQuiz.data['step1-mile--step2-6mile--step3-lowmile'] = new HealthQuizStep(0, 'you\'ll feel amazing to complete it. You can do it!', 'As a newbie to running,', 'run', SixMileBeginnerCtas);

  swimCtas = {
    download: { text: 'Get your plan at swimathon.org', href: 'http://www.swimathon.org/page.php?page=Training' },
    enter: { text: 'Enter the Swimathon', href: '/sainsburys-sport-relief-swimathon' },
    facebook: { text: 'Share', href: '#', onclick: facebookShare },
    twitter: { text: 'Tweet', href: '#', onclick: twitterShare }
  };

  $.fn.healthQuiz.data['step1-swim--step2-1swim--step3-highswim'] = new HealthQuizStep(0, 'this is a chance to just dive in and do your thing.', 'For a serious swimmer like you,', 'swim', swimCtas);
  $.fn.healthQuiz.data['step1-swim--step2-1swim--step3-middleswim'] = new HealthQuizStep(0, 'and an even better feeling for conquering it.', 'It\'ll give you a decent workout', 'swim', swimCtas);
  $.fn.healthQuiz.data['step1-swim--step2-1swim--step3-lowswim'] = new HealthQuizStep(0, 'you\'ll feel amazing to complete it. You can do it!', 'As a newbie to swimming,', 'swim', swimCtas);
  $.fn.healthQuiz.data['step1-swim--step2-3swim--step3-highswim'] = new HealthQuizStep(0, 'this is a chance to just dive in and do your thing.', 'For a serious swimmer like you,', 'swim', swimCtas);
  $.fn.healthQuiz.data['step1-swim--step2-3swim--step3-middleswim'] = new HealthQuizStep(0, 'that you\'ll feel incredible for having conquered.', 'A tough challenge', 'swim', swimCtas);
  $.fn.healthQuiz.data['step1-swim--step2-3swim--step3-lowswim'] = new HealthQuizStep(0, 'you\'ll feel amazing to complete it. You can do it!', 'As a newbie to swimming,', 'swim', swimCtas);
  $.fn.healthQuiz.data['step1-swim--step2-5swim--step3-highswim'] = new HealthQuizStep(0, ' but seems you\'re used to being in at the deep end. Go for it!', 'A long old swim,', 'swim', swimCtas);
  $.fn.healthQuiz.data['step1-swim--step2-5swim--step3-middleswim'] = new HealthQuizStep(0, 'and then soak up the adulation: it\'ll be fully deserved.', 'Complete this tough swim', 'swim', swimCtas);
  $.fn.healthQuiz.data['step1-swim--step2-5swim--step3-lowswim'] = new HealthQuizStep(0, 'If you\'re entering the pool as a novice,', 'you\'ll emerge at the end as a legend.', 'swim', swimCtas);

  cycleCtas = { download: { text: 'Get sponsorship tips', href: '/fundraise/ideas-and-tools#sponsorship_tips' }, enter: { text: 'Enter the Cycle', href: '/sainsburys-sport-relief-cycle'}, facebook: { text: 'Share', href: '#', onclick: facebookShare }, twitter: { text: 'Tweet', href: '#', onclick: twitterShare } };
  $.fn.healthQuiz.data['step1-cycle--step2-3cycle--step3-highcycle'] = new HealthQuizStep(0, 'Just soak up the fun, family atmosphere and enjoy.', 'For you, no sweat.', 'cycle', cycleCtas);
  $.fn.healthQuiz.data['step1-cycle--step2-3cycle--step3-middlecycle'] = new HealthQuizStep(0, 'Just soak up the fun, family atmosphere and enjoy.', 'For you, no sweat.', 'cycle', cycleCtas);
  $.fn.healthQuiz.data['step1-cycle--step2-3cycle--step3-lowcycle'] = new HealthQuizStep(0, 'to cycling, with a fun, friendly atmosphere.', 'Your perfect introduction', 'cycle', cycleCtas);

  cycleCtas25Mile = { download: { text: 'Download your plan', href: '/sites/sportrelief.com/files/files/downloadables/sr14_25_mile_cycle_plan.pdf' }, enter: { text: 'Enter the Cycle', href: '/sainsburys-sport-relief-cycle'}, facebook: { text: 'Share', href: '#', onclick: facebookShare}, twitter: { text: 'Tweet', href: '#', onclick: twitterShare } };
  cycleCtas25MileBeginner = { download: { text: 'Download your plan', href: '/sites/sportrelief.com/files/files/downloadables/sr14_25_mile_cycle_plan_beginner.pdf' }, enter: { text: 'Enter the Cycle', href: '/sainsburys-sport-relief-cycle'}, facebook: { text: 'Share', href: '#', onclick: facebookShare}, twitter: { text: 'Tweet', href: '#', onclick: twitterShare } };

  cycleCtas50Mile = { download: { text: 'Download your plan', href: '/sites/sportrelief.com/files/files/downloadables/sr14_50_mile_cycle_plan.pdf' }, enter: { text: 'Enter the Cycle', href: '/sainsburys-sport-relief-cycle'}, facebook: { text: 'Share', href: '#', onclick: facebookShare}, twitter: { text: 'Tweet', href: '#', onclick: twitterShare } };
  cycleCtas50MileBeginner = { download: { text: 'Download your plan', href: '/sites/sportrelief.com/files/files/downloadables/sr14_50_mile_cycle_plan_beginner.pdf' }, enter: { text: 'Enter the Cycle', href: '/sainsburys-sport-relief-cycle'}, facebook: { text: 'Share', href: '#', onclick: facebookShare }, twitter: { text: 'Tweet', href: '#', onclick: twitterShare } };

  $.fn.healthQuiz.data['step1-cycle--step2-25cycle--step3-highcycle'] = new HealthQuizStep(0, 'in a great atmosphere full of fellow proven peddlers.', 'You\'ll get a nice workout', 'cycle', cycleCtas25Mile);

  $.fn.healthQuiz.data['step1-cycle--step2-25cycle--step3-middlecycle'] = new HealthQuizStep(0, 'to give you a good workout and a fantastic feeling too.', 'A decent distance', 'cycle', cycleCtas25Mile);

  $.fn.healthQuiz.data['step1-cycle--step2-25cycle--step3-lowcycle'] = new HealthQuizStep(0, 'you\'ll feel amazing to complete it. You can do it!', 'As a newbie to cycling', 'cycle', cycleCtas25MileBeginner);

  $.fn.healthQuiz.data['step1-cycle--step2-50cycle--step3-highcycle'] = new HealthQuizStep(0, 'in a great atmosphere full of fellow proven peddlers.', 'You\'ll get a good workout', 'cycle', cycleCtas50Mile);

  $.fn.healthQuiz.data['step1-cycle--step2-50cycle--step3-middlecycle'] = new HealthQuizStep(0, 'that\'ll give you a tough workout and a truly fantastic feeling.', 'A proper ride', 'cycle', cycleCtas50Mile);

  $.fn.healthQuiz.data['step1-cycle--step2-50cycle--step3-lowcycle'] = new HealthQuizStep(0, 'you\'ll feel amazing to complete it. You can do it!', 'As a newbie to cycling', 'cycle', cycleCtas50MileBeginner);
  callback();
};

})(jQuery);

