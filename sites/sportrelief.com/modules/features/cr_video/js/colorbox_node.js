(function($) {
  Drupal.behaviors.colorboxNode = {
    // Lets find our class name and change our URL to
    // our defined menu path to open in a colorbox modal.
    attach : function(context, settings) {
      $.urlParams = function (url) {
          var p = {},
              e,
              a = /\+/g,  // Regex for replacing addition symbol with a space
              r = /([^&=]+)=?([^&]*)/g,
              d = function (s) { return decodeURIComponent(s.replace(a, ' ')); },
              q = url.split('?');
          while (e = r.exec(q[1])) {
            e[1] = d(e[1]);
            e[2] = d(e[2]);
            switch (e[2].toLowerCase()) {
              case 'true':
              case 'yes':
                e[2] = true;
                break;
              case 'false':
              case 'no':
                e[2] = false;
                break;
            }
            if (e[1] == 'width') { e[1] = 'innerWidth'; }
            if (e[1] == 'height') { e[1] = 'innerHeight'; }
            p[e[1]] = e[2];
          }
          return p;
        };

        var $colorboxes = $('.colorbox-node', context);
        if(Modernizr.touch) {
          $colorboxes = $('.colorbox-node:not(.node-video .colorbox-node, #views_fluidgrid_fundraiser_showcase_page .views-fluidgrid-item .colorbox-node, .dl-overlay .colorbox-node, .fr-showcase-filter .colorbox-node)', context);
        }
        $colorboxes.once('init-colorbox-node-processed', function() {
          var href = $(this).attr('data-href');
          if(typeof href == 'undefined' || href == false) {
            href = $(this).attr('href');
          }
        // Create an element so we can parse our a URL no matter if its internal or external.
        var parse = document.createElement('a');
        parse.href = href;
        // Lets add our colorbox link after the base path if necessary.
        var base_path = Drupal.settings.basePath;
        var pathname = parse.pathname;

        // Lets check to see if the pathname has a forward slash.
        // This problem happens in IE7/IE8
        if(pathname.charAt(0) != '/') {
          pathname = '/' + parse.pathname;
        }

        if(base_path != '/') {
          var link = pathname.replace(base_path, base_path + 'colorbox/') + parse.search;
        } else {
          var link = base_path + 'colorbox' + pathname + parse.search;
        }

        // Bind Ajax behaviors to all items showing the class.
          var element_settings = {};

          // This removes any loading/progress bar on the clicked link
        // and displays the colorbox loading screen instead.
        element_settings.progress = { 'type': 'none' };
        $(this).click(function() {
          var params = $.urlParams($(this).attr('href'));
          params.html = '<div id="colorboxNodeLoading"></div>';
              $.colorbox($.extend({}, settings.colorbox, params));
        });

          // For anchor tags, these will go to the target of the anchor rather
          // than the usual location.
          if ($(this).attr('href')) {
            element_settings.url = link;
            element_settings.event = 'click';
          }
          var base = $(this).attr('id');
          var cboxAjax = new Drupal.ajax(base, this, element_settings);
          cboxAjax.options.type = "GET";

          cboxAjax.options.beforeSend = function (xmlhttprequest, options) {
        //Cache for 1 week
        xmlhttprequest.setRequestHeader('Cache-Control', 'public, max-age=604800');
        cboxAjax.ajaxing = true;
        return cboxAjax.beforeSend(xmlhttprequest, options);
          };
          // Override Event Response
          cboxAjax.eventResponse = function(element, event){

        // Create a synonym for this to reduce code confusion.
        var ajax = this;

        // Do not perform another ajax command if one is already in progress.
        if (ajax.ajaxing) {
          return false;
        }

        try {
          if (ajax.form) {
            // If setClick is set, we must set this to ensure that the button's
            // value is passed.
            if (ajax.setClick) {
              // Mark the clicked button. 'form.clk' is a special variable for
              // ajaxSubmit that tells the system which element got clicked to
              // trigger the submit. Without it there would be no 'op' or
              // equivalent.
              element.form.clk = element;
            }

            ajax.form.ajaxSubmit(ajax.options);
          }
          else {
            ajax.beforeSerialize(ajax.element, ajax.options);
            ajax.options.data = {"js":true};
            // Send JS/CSS files if included
            if (typeof Drupal.settings.cr_video_mediaelement_paths !== "undefined") {
              for (var key in Drupal.settings.cr_video_mediaelement_paths.css) {
          ajax.options.data['ajax_page_state[css][' + key + ']'] = 1;
              }
              for (var key in Drupal.settings.cr_video_mediaelement_paths.js) {
          ajax.options.data['ajax_page_state[js][' + key + ']'] = 1;
              }
            }
            $.ajax(ajax.options);
          }
        }
        catch (e) {
          // Unset the ajax.ajaxing flag here because it won't be unset during
          // the complete response.
          ajax.ajaxing = false;
          alert("An error occurred while attempting to process " + ajax.options.url + ": " + e.message);
        }

        // For radio/checkbox, allow the default event. On IE, this means letting
        // it actually check the box.
        if (typeof element.type != 'undefined' && (element.type == 'checkbox' || element.type == 'radio')) {
          return true;
        }
        else {
          return false;
        }
         }

          Drupal.ajax[base] = cboxAjax;
      });

      // When using contextual links and clicking from within the colorbox
      // we need to close down colorbox when opening the built in overlay.
      $('ul.contextual-links a', context).once('colorboxNodeContextual').click(function() {
        $.colorbox.close();
      });
    }
  };

})(jQuery);
