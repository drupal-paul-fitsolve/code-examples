/*
 * Google Analytics Tracking
 * SR14
 * Dan Duke
 *
 * This works by passing an anchor tag and some variables through to a gaAddTracking variable on click
 */

(function ($) {

    'use strict';

    function gaAddClickTracking(theLink, gaBase) {

      var action,
          category,
          optLabel,
          pageTitle,
          pageTitleEnd;

      // Setup the category
      if ($(theLink).hasClass('cta') && gaBase[3] !== 'no-extra') {
        category = 'cta';
      } else {
        category = gaBase[0];
      } // eg link, cta

      // Setup the action
      action = gaBase[1]; // eg. click

      // Extract the pageTitle and label
      pageTitle = document.title;
      pageTitleEnd = pageTitle.indexOf("|");

      // if no-extra has been added to the array
      // then we don't want the following extra bits added to the data
      if (gaBase[3] === 'no-extra') {
        optLabel = '';
      } else {
        optLabel = 'from-';

        if (pageTitleEnd > 0) {
          optLabel += pageTitle.substring(0, pageTitleEnd-1) + ' : ';
        } else {
          optLabel += pageTitle + ' : ';
        }
      }

      // Setup the label
      if (gaBase[3] === 'no-extra') {
        optLabel += gaBase[2];
      } else {
        if (gaBase[2] !== "") {
          // If some extra info is required, add it here (eg. (footer))
          optLabel += gaBase[2] + ' : '; // destination title eg. Schools
        }
        optLabel += 'to-' + theLink.text + ' ' + theLink.href;
      }

      optLabel = optLabel.replace(/http\:\/\/(shop|www|my|local|dev|local|staging|qa|uat)?(-sept)?(\.)?sportrelief.com/g,"");

      _gaq.push(['_trackEvent', category, action, optLabel]);

    }

    Drupal.behaviors.sportrelief_2014.ga = function (context) {

    var arrowVal,
        catTitle,
        currentPage,
        gaBase,
        gaLabel,
        lastChar,
        mediaType,
        menuTitle,
        pageTitle,
        parentId,
        pathName,
        titleValue,
        videoLocation,
        videoValue;

    // Track a link using the class
    $('a.addtracking', context).on('click', function () {
      gaBase = ["Link", "Click", ""];

      if ($(this).parents('.promo-wrapper, .promo-bottom-wrapper').length) {
        gaBase = ["Link", "Click", "main-content"];
      }

      if ($(this).parents('.main-content').length) {
        gaBase = ["Link", "Click", "promo"];
      }

      gaAddClickTracking(this, gaBase);
    });

    // Track footer links
    $('.footer-zone-wrapper a', context).on('click', function () {
      gaBase = ["Link", "Click", "FOOTER"];
      gaAddClickTracking(this, gaBase);
    });

    // Track 'specific' header links
    $('.header-section-wrapper .page-menu-block a, .header-section-wrapper .pod__body a', context).on('click', function () {
      gaBase = ["Link", "Click", "HEADER dropdown"];
      gaAddClickTracking(this, gaBase);
    });

    // Track media bar links (vary depending on type)
    $('.view-mode-media_bar a.node-link', context).on('click', function () {
      // Get media bar type, and pass in as media variable
      mediaType = 'mediabar-' + $(this).parent().attr('id').replace(/^(node-)([a-z\-]*)([0-9]*)$/g,"$2");
      gaBase = ["Link", "Click", mediaType];
      gaAddClickTracking(this, gaBase);
    });

    //media wall - promo 1
    $('.field-name-field-media-wall-promo .node-link-icon', context).on('click', function () {
      titleValue = $('.field-name-field-media-wall-promo').find('.text').text();
      gaLabel = 'Media Wall | Promo 1 | ' + titleValue;
      gaBase = ["Homepage", "Promo Click", gaLabel, "no-extra"];
      gaAddClickTracking(this, gaBase);
    });
    //media wall - promo 2
    $('.field-name-field-media-wall-promo-2 .node-link-icon', context).on('click', function () {
      titleValue = $('.field-name-field-media-wall-promo-2').find('.text').text();
      gaLabel = 'Media Wall | Promo 2 | ' + titleValue;
      gaBase = ["Homepage", "Promo Click", gaLabel, "no-extra"];
      gaAddClickTracking(this, gaBase);
    });

    //media wall - promo 3
    $('.field-name-field-media-wall-promo-3 .node-link-icon', context).on('click', function () {
      titleValue = $('.field-name-field-media-wall-promo-3').find('.text').text();
      gaLabel = 'Media Wall | Promo 3 | ' + titleValue;
      gaBase = ["Homepage", "Promo Click", gaLabel, "no-extra"];
      gaAddClickTracking(this, gaBase);
    });

    //media wall - promo 4
    $('.field-name-field-media-wall-promo-4 .node-link-icon', context).on('click', function () {
      titleValue = $('.field-name-field-media-wall-promo-4').find('.text').text();
      gaLabel = 'Media Wall | Promo 4 | ' + titleValue;
      gaBase = ["Homepage", "Promo Click", gaLabel, "no-extra"];
      gaAddClickTracking(this, gaBase);
    });

    //media wall - instagram image
    $('.view-id-media_wall_instagram .node-link-icon', context).on('click', function () {
      titleValue = $('.view-id-media_wall_instagram').find('.text').text();
      gaLabel = 'Media Wall | Instagram image | ' + titleValue;
      gaBase = ["Homepage", "Instagram image click", gaLabel, "no-extra"];
      gaAddClickTracking(this, gaBase);
    });

    //media wall - pinned news article
    $('#tabs-0-row2_col1-0 .view-id-media_wall .media-wall__small-tile .node-link-icon', context).on('click', function () {
      titleValue = $('.view-id-media_wall .media-wall__small-tile').find('.text').text();
      gaLabel = 'Media Wall | Pinned news article | ' + titleValue;
      gaBase = ["Homepage", "Pinned news click", gaLabel, "no-extra"];
      gaAddClickTracking(this, gaBase);
    });

    //media wall - fundraising kit
    $('.media-wall__fundraising-kit a', context).on('click', function () {
      titleValue = $(this).text();
      gaLabel = 'Media Wall | fundraising kit | ' + titleValue;
      gaBase = ["Homepage", "fundraising kit click", gaLabel, "no-extra"];
      gaAddClickTracking(this, gaBase);
    });

    //media wall - arrows
    $('.media-wall .flex-direction-nav li', context).on('click', function () {
      titleValue = $(this).find('a').attr("class");
      if (titleValue === 'flex-prev') {
        titleValue = 'left';
      }
      if (titleValue === 'flex-next') {
        titleValue = 'right';
      }
      gaLabel = 'Media Wall | Arrows | ' + titleValue;
      gaBase = ["Homepage", "Arrow click", gaLabel, "no-extra"];
      gaAddClickTracking(this, gaBase);
    });

    //homepage - top pager - arrows
    $('.front .promo-wrapper .slider--full-width .flex-direction-nav li', context).on('click', function () {
      arrowVal = $(this).find('a').attr("class");
      if (arrowVal === 'flex-prev') {
        arrowVal = 'Left arrow';
      } else if (arrowVal === 'flex-next') {
        arrowVal = 'Right arrow';
      }
      gaLabel = 'Home Page | Top Pod Images | ' + arrowVal;
      gaBase = ["Home Page", "Button", gaLabel, "no-extra"];
      gaAddClickTracking(this, gaBase);
    });

    //homepage - top pager - enter now
    $('.front .promo-wrapper .slider--full-width .button', context).on('click', function () {
      gaLabel = 'Home Page | Top Pod Images | Enter now button';
      gaBase = ["Home Page", "Button", gaLabel, "no-extra"];
      gaAddClickTracking(this, gaBase);
    });

    //homepage - schools and nurseries pod - visit schools section
    $('.front .content-row-3-wrapper .button', context).on('click', function () {
      gaLabel = 'Home Page | Schools and Nurseries Pod | Visit schools section';
      gaBase = ["Home Page", "Button", gaLabel, "no-extra"];
      gaAddClickTracking(this, gaBase);
    });

    //homepage - schools and nurseries pod - Order a free schools pack
    $('.front .content-row-3-wrapper .cta', context).on('click', function () {
      gaLabel = 'Home Page | Schools and Nurseries Pod | Order a free schools pack';
      gaBase = ["Home Page", "Button", gaLabel, "no-extra"];
      gaAddClickTracking(this, gaBase);
    });

    //track video start frame clicks
    $('.cr-mediaelement-video', context).on('click', function () {
      videoValue = $(this).find('source').attr('src');
      pageTitle = $('title').text();
      pageTitle = pageTitle.split(' | ');
      pageTitle = pageTitle[0];

      //if video is clicked inside promo wrapper on homepage
      if ($(this).parents().hasClass('promo-wrapper') && $(this).parents().hasClass('front')) {
        parentId = $(this).parents('.slider-content').attr('id');
        lastChar = parentId.substr(parentId.length - 1);
        lastChar++;
        videoLocation = 'Top Promo - Slide ' + lastChar + ' | ';
      }

      //if video is clicked inside media wall on homepage
      if ($(this).parents().hasClass('media-wall')) {
        videoLocation = 'Media Wall | ';
      }

      //if video clicked is in a sub pod
      if ($(this).parents().hasClass('front') && $(this).parents().hasClass('content-row-4-wrapper')) {
        parentId = $(this).parents('.panels-ipe-region').attr('id');
        lastChar = parentId.substr(parentId.length - 1);
        videoLocation = 'Sub Pod ' + lastChar + ' | ';
      }

      gaLabel = 'Page Title - ' + pageTitle + ' | ' + videoLocation + 'Video - ' + pageTitle + ' | ' + videoValue;
      gaBase = ["video start frame", "Play button", gaLabel, "no-extra"];
      gaAddClickTracking(this, gaBase);
    });

    //homepage - event strip - event llink click
    $('.promo-bottom-wrapper a', context).on('click', function () {
      var eventTitle = $(this).parents('.pod__body').siblings('.pod__title').text().replace('The ', '');
      gaLabel = 'Home Page | Mid Pod - Find out more CTA | ' + eventTitle + ' CTA';
      gaBase = ["Home Page ", "Button ", gaLabel, "no-extra"];
      gaAddClickTracking(this, gaBase);
    });

    //homepage - event strip - posctcode search click
    $('.promo-bottom-wrapper #btnSubmit', context).on('click', function () {
      gaLabel = 'Home Page | Mid Pod - Postcode Search | Postcode Search';
      gaBase = ["Home Page ", "Button ", gaLabel, "no-extra"];
      gaAddClickTracking(this, gaBase);
    });

    //track schools toolbox tab clicks
    $('.view-id-schools_toolbox .flex-viewport li', context).on('click', function () {
      pathName = window.location.pathname;
      pathName = pathName.substring(pathName.lastIndexOf('/') + 1);
      pathName = pathName.charAt(0).toUpperCase() + pathName.substring(1);
      titleValue = $(this).find('.tab-nav--title').text();
      gaLabel = pathName + ' Schools Section | Top Pod | ' + titleValue;
      gaBase = ["Schools Section", "Pod Click", gaLabel, "no-extra"];
      gaAddClickTracking(this, gaBase);
    });

    //track schools - gold mining page clicks
    $('.context-schools .pod--content-media-player ~ .flex-direction-nav a', context).on('click', function () {
      pathName = window.location.pathname;
      pathName = pathName.substring(pathName.lastIndexOf('/') + 1);
      pathName = pathName.charAt(0).toUpperCase() + pathName.substring(1);

      currentPage = parseInt($('.current-slide').text(), 0);

      if ($(this).hasClass('flex-next')) {
        currentPage++;
      } else if ($(this).hasClass('flex-prev')) {
        currentPage--;
      }

      if (currentPage === 0) {
        currentPage = 7;
      }

      if (currentPage === 8) {
        currentPage = 1;
      }

      gaLabel = pathName + ' Schools Section | Gold Mining in Ghana | Story - Page ' + currentPage;
      gaBase = ["Schools Section", "Pod Click", gaLabel, "no-extra"];
      gaAddClickTracking(this, gaBase);
    });

    //track schools - audio play, headphone & quote
    $('.context-schools .pod--content-media-player ~ .flex-pauseplay a', context).on('click', function () {
      var clickedControl = $(this).attr('class');

      if (clickedControl === 'flex-play' || clickedControl === 'flex-pause') {
        clickedControl = 'Play';
      } else if (clickedControl === 'flex-music' || clickedControl === 'flex-music active') {
        clickedControl = 'Headphone';
      } else if (clickedControl === 'flex-quote' || clickedControl === 'flex-quote active') {
        clickedControl = 'Quote';
      }

      pathName = window.location.pathname;
      pathName = pathName.substring(pathName.lastIndexOf('/') + 1);
      pathName = pathName.charAt(0).toUpperCase() + pathName.substring(1);

      gaLabel = pathName + ' Schools Section | Gold Mining in Ghana | Toggle tools - ' + clickedControl;
      gaBase = ["Schools Section", "Pod Click", gaLabel, "no-extra"];
      gaAddClickTracking(this, gaBase);
    });

    // Main nav tracking
    $('#block-system-main-menu a', context).on('click', function () {
      var menuTitle = $(this).text();
      gaLabel = 'Top Nav | Top Nav | ' + menuTitle;
      gaBase = ["Top Site Nav", "Link", gaLabel, "no-extra"];
      gaAddClickTracking(this, gaBase);
    });

    // Main menu - sub menus tracking
    $('.zone-megamenu-wrapper a', context).on('click', function () {
      menuTitle = $(this).text();
      catTitle = '';
      if ($(this).hasClass('button') || $(this).hasClass('cta')) {
        catTitle = $(this).closest('.panel-panel').find('.menu li.first a').text();
      } else {
        catTitle = $(this).closest('.menu').find('li.first a').text();
      }
      gaLabel = 'Top Nav | Sub Nav - ' + catTitle + ' | ' + menuTitle;
      gaBase = ["Top Site Nav", "Link", gaLabel, "no-extra"];
      gaAddClickTracking(this, gaBase);
    });

    // Little Mix, Button, Little Mix | Top pod | Itunes pre order button
    $('.littlemix-promo-bottom-itunes-preorder a', context).on('click', function () {
      gaBase = ["Little Mix", "Button", "Little Mix | Top pod | Itunes pre order button", "no-extra"];
      gaAddClickTracking(this, gaBase);
    });

    // Little Mix, Button, Little Mix | Top pod | Download ITunes button
    $('.littlemix-promo-bottom-itunes-download a', context).on('click', function () {
      gaBase = ["Little Mix", "Button", "Little Mix | Top pod | Download Itunes button", "no-extra"];
      gaAddClickTracking(this, gaBase);
    });

    // Little Mix, Link, Little Mix | Do your fundraising pod | Get a fundraising idea
    $('.little-mix-mixersinmotion-row1 a[href="/ideas"]', context).on('click', function () {
      gaBase = ["Little Mix", "Button", "Little Mix | Do your fundraising pod | Get a fundraising idea", "no-extra"];
      gaAddClickTracking(this, gaBase);
    });

    // Little Mix, Link, Little Mix | Giving page | Set up giving page
    $('.little-mix-mixersinmotion-row1 a[href="http://my.sportrelief.com/registration"]', context).on('click', function () {
      gaBase = ["Little Mix", "Link", "Little Mix | Giving page | Set up giving page", "no-extra"];
      gaAddClickTracking(this, gaBase);
    });

    //SRSITE-1093 GA tracking for Kids Section page interaction
    $('body.play-games-landing-page div.view-mode-media_bar a.node-link', context).on('click', function (e) {
      gaAddClickTracking(this, ["Kids:Game", "Link", "Kids Games | Pinned news article | " + $(this).text(), "no-extra"]);
    });

    $('body.context-play-games div.subpod-wrapper', context).on('click', function (e) {
      if (e.target.nodeName === 'A') {
        if (e.target.pathname === '/event-info/enter-now') {
          gaAddClickTracking(this, ["Kids:Game", "Button", "Kids Games | Event Display | Bottom of Pages | Grab a Grown up and Enter", "no-extra"]);
        }
        if (e.target.pathname === '/play-games/info-for-parents-and-guardians') {
          gaAddClickTracking(this, ["Kids:Game", "Button", "Kids Games | Event Display | Bottom of Pages | Parents get more info", "no-extra"]);
        }
      }
    });

    $('a[href="#pledge-step--two"]', context).on('click', function (e) {
       gaAddClickTracking(this, ["Kids:Game", "Button", "Kids Games | Super duper ideas machine | Get your name on the display", "no-extra"]);
    });

    $('a[href="#pledge-step--four"]', context).on('click', function (e) {
       gaAddClickTracking(this, ["Kids:Game", "Button", "Kids Games | Super duper ideas machine | Check out the lab", "no-extra"]);
    });

    $('div.pane-sr-fun-and-games-fg-pledge-submission input#edit-submit--2', context).on('click', function (e) {
       gaAddClickTracking(this, ["Kids:Game", "Button", "Kids Games | Super duper ideas machine | Add your name", "no-extra"]);
    });

    $('div.pledge-step--four', context).on('click', function (e) {
      if (e.target.nodeName === 'A') {
        if (e.target.id === 'buttonlike') {
          gaAddClickTracking(this, ["Kids:Game", "Button", "Kids Games | Ideas Lab | I want to do this idea", "no-extra"]);
        }
        if (e.target.id === 'buttonanother') {
          gaAddClickTracking(this, ["Kids:Game", "Button", "Kids Games | Ideas Lab | Give me another idea", "no-extra"]);
        }
      }
    });

    $('form#sr-fun-and-games-idea-generation-form', context).on('submit', function (e) {
       gaAddClickTracking(this, ["Kids:Game", "Button", "Kids Games | Ideas Lab | Generate idea", "no-extra"]);
    });

    $('#node-panel-383 a[href="/event-info"]', context).on('click', function (e) {
       gaAddClickTracking(this, ["Kids:Game", "Button", "Kids Games | Info for Parents and Guardians | About Sport Relief for kids pod | Find out more", "no-extra"]);
    });

    $('#node-panel-383 div.alpha.pod a[href="/event-info/enter-now"]', context).on('click', function (e) {
       gaAddClickTracking(this, ["Kids:Game", "Button", "Kids Games | Info for Parents and Guardians | About Sport Relief for kids pod | Enter an event now", "no-extra"]);
    });

    $('#node-panel-383 a#Help-your-kids-raise-money-Enter-an-event-now', context).on('click', function (e) {
       gaAddClickTracking(this, ["Kids:Game", "Button", "Kids Games | Info for Parents and Guardians | Help your kids raise money pod | Enter an event now", "no-extra"]);
    });

    $('#node-panel-383 a#Help-your-kids-raise-money-get-a-form', context).on('click', function (e) {
       gaAddClickTracking(this, ["Kids:Game", "Button", "Kids Games | Info for Parents and Guardians | Help your kids raise money pod | Get a kids sponsorship form", "no-extra"]);
    });

    $('#node-panel-383 a[href="https://my.sportrelief.com/registration"]', context).on('click', function (e) {
       gaAddClickTracking(this, ["Kids:Game", "Button", "Kids Games | Info for Parents and Guardians | Can’t make an event pod | Set up an under 16 giving page", "no-extra"]);
    });

    $('#node-panel-383 div.omega.pod a[href="/sites/sportrelief.com/files/files/downloadables/sr14_SSRG_u16_sponsorship_form.pdf"]', context).on('click', function (e) {
       gaAddClickTracking(this, ["Kids:Game", "Button", "Kids Games | Info for Parents and Guardians | Can’t make an event pod | Get a kids sponsorship form", "no-extra"]);
    });

    /* Battle of the Backsides */
    $('.BattleOfTheBacksides .promo-wrapper .button', context).on('click', function (e) {
       gaAddClickTracking(this, ["Wembley Challenge", "Button", "SR site - Wembley Challenge BotB | Top Pod Image | Enter the competition", "no-extra"]);
    });

    $('.BattleOfTheBacksides .botb-competition-enter-promo-cta .button', context).on('click', function (e) {
       gaAddClickTracking(this, ["Wembley Challenge", "Button", "SR site - Wembley Challenge BotB | Middle Pod | Enter the competition", "no-extra"]);
    });

    $('.BattleOfTheBacksides .subpod-wrapper a.button[href="/enter-now"]', context).on('click', function (e) {
       gaAddClickTracking(this, ["Wembley Challenge", "Button", "SR site - Wembley Challenge BotB | Bottom Pod | Enter today", "no-extra"]);
    });

    /* Alex Challenge - Alex vs The Rock */
    $('body.context-challenge-alex .promo-wrapper .challenge-header .challenge-sponsor .button', context).on('click', function (e) {
      gaAddClickTracking(this, ["Alex Against the Rock", "Button", "Alex Against the Rock | Top Pod Button | Sponsor Alex", "no-extra"]);
    });

    $('body.context-challenge-alex .promo-wrapper a[href="/event-info/enter-now"]', context).on('click', function (e) {
      gaAddClickTracking(this, ["Alex Against the Rock", "Link", "Alex Against the Rock | Top Pod Link | Take on your own challenge", "no-extra"]);
    });

    $('body.context-challenge-alex .subpod-wrapper a[href="/event-info/enter-now"]', context).on('click', function (e) {
      gaAddClickTracking(this, ["Alex Against the Rock", "Button", "Alex Against the Rock | Bottom Pod Button | Enter an event now", "no-extra"]);
    });

    $('body.context-challenge-alex .subpod-wrapper a[href="/alex"]', context).on('click', function (e) {
      gaAddClickTracking(this, ["Alex Against the Rock", "Button", "Alex Against the Rock | Bottom Pod Button | Other ways to sponsor Alex", "no-extra"]);
    });

  };

})(jQuery);
