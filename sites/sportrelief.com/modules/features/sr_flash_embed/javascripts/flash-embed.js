/**
 * A HTML parse and quick init, better to keep these together
 * Lewis Nyman
 *
 **/

(function($) {

  $(document).ready(function() {
    var character = 0;
    if(getQueryVar('character') != null)
    {
        character = getQueryVar('character');
    }
   
    if(isNaN(character) || (character < 0))
    {
        character = 0;
    }
    var flashContainer = $('.flash-container');
    if(flashContainer.length !== 0) {
      for (var i = 0; i < flashContainer.length; i++) {
        var $this = $(flashContainer[i]),
        src = $($this).data('flash-src'),
        height = $($this).data('flash-height'),
        width = $($this).data('flash-width'),
        vars = $($this).data('flash-vars');
        wmode = $($this).data('flash-wmode');

        if (hasflash()) {
          $($this).bind('click.flashifyTarget', function(div) {
            if ("interstitial" == div.target.className) {
              var flashvars = $.parseJSON(this.attributes['data-flash-vars'].nodeValue.replace(/&#039;/g,'"'));
              flashvars.character = character;
              // Remove and replace flash element after the promo header text.
              $('.leader-double .FlashTestElement').remove();
              $('.leader-double').append('<div id="flashgame" class="FlashTestElement"></div>');
  /*           $('.leader-double .FlashTestElement').flash({
                src: this.attributes['data-flash-src'].nodeValue,
                width: this.attributes['data-flash-width'].nodeValue,
                height: this.attributes['data-flash-height'].nodeValue,
                flashvars: flashvars ,
                wmode: wmode,
                character: character,
                'allowscriptaccess' : 'always',
                'class' : 'flash-replaced FlashTestElement'
              },
              {
                update: false
              });
  */
              var src = this.attributes['data-flash-src'].nodeValue;
              var height = this.attributes['data-flash-height'].nodeValue;
              var width = this.attributes['data-flash-width'].nodeValue;
              var params = {
                    menu: "false",
                    scale: "noScale",
                    allowFullscreen: "true",
                    allowScriptAccess: "always",
                    bgcolor: "#FFFFFF"
                  };
              var attributes = { id:"siteloader" , 'class' : "flash-replaced FlashTestElement" };
              swfobject.embedSWF(src, "flashgame", width, height, "10.0.0", "expressInstall.swf", flashvars, params, attributes);
            }
          });

          // This will destroy the flash game so that the FlexSlider operates as per usual.
          $('.playgames.kids-bg #flexslider-1 .tab-link').bind('click.removeFlashTarget', function(div) {
            $('.leader-double .FlashTestElement').remove();
          });

          $(this).find('.fallback').hide();
          $($this).append('<div class="interstitial"></div>');
          $(window).addClass('hasflash');
        } else {
          $($this).css('background-image','none');
          if (i == 0) {
            var src = $('iframe.fallback').attr('src');
            src = src + '?character=' + character;
            $('iframe.fallback').attr('src', src);

          } 
          $(window).addClass('no-flash'); 
        }
      }
    }
  });
  $(window).load(function() {
     if (!hasflash()) $('#mini-panel-fun_and_games_landing').bind('click',function() { window.document.location.href = $('iframe.fallback').attr('src');  }); 
  });

})(jQuery);

(function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
(i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
})(window,document,'script','//www.google-analytics.com/analytics.js','ga');

ga('create', 'UA-43451738-1', 'auto');
ga('send', 'pageview');

/* SportRelief, using Google Analytics - Bespoke SportRelief events */
window.sportReliefActionEvent = function(category, action, label)
{
    if(window.ga)
    {
        console.log("\n **sportReliefActionEvent \n category: " + category + "\n action: " + action + "\n label: " + label);
        ga('send', 'event', category, action, label);
    }
}
 
getQueryVar = function(variable)
{
    var query = window.location.search.substring(1);
    var vars = query.split('&');
    for (var i = 0; i < vars.length; i++) {
        var pair = vars[i].split('=');
        if (decodeURIComponent(pair[0]) == variable) {
            return decodeURIComponent(pair[1]);
        }
    }   
    return null;
}


function GetURLParameter(sParam)
{
    var sPageURL = window.location.search.substring(1);
    var sURLVariables = sPageURL.split('&');
    for (var i = 0; i < sURLVariables.length; i++)
    {
        var sParameterName = sURLVariables[i].split('=');
        if (sParameterName[0] == sParam)
        {
            return sParameterName[1];
        }
    }
}


// IE doesn't have navigator.plugins, it uses ActiveXObject instead. >.>
var isie = function() { var p = navigator.plugins; return (p && p.length) ? false : true; };

if(isie()) {
        // IE uses an ancient version of Javascript, so let's add the missing indexOf method in manually.
        Array.prototype.indexOf = function(o,i){
                for(var j = this.length, i = i < 0 ? i + j < 0 ? 0 : i + j : i || 0; i < j && this[i] !== o; i++);
                return j <= i ? - 1 : i;
        };
}

// Check if browser has flash installed.
var hasflash = function() {
        return (flashversion())
                ? true
                : false;
};

// Check what version of flash is installed.
var flashversion = function() {
        if(isie()) {
                var key = 'ShockwaveFlash.ShockwaveFlash';
                try {
                        var axo = new ActiveXObject(key+'.7');
                } catch(e) {
                        try {
                                var axo = new ActiveXObject(key+'.6');
                                return [6, 0, 21];
                        } catch(e) {};
                        try {
                                axo = new ActiveXObject(key);
                        } catch(e) {};
                }
                if (axo != null) {
                        return axo.GetVariable("$version").split(" ")[1].split(",");
                }
        } else {
                var p = navigator.plugins;
                var f = p['Shockwave Flash'];
                if (f && f.description) {
                        return f.description.replace(/([a-zA-Z]|\s)+/, "").replace(/(\s+r|\s+b[0-9]+)/, ".").split(".");
                } else if (p['Shockwave Flash 2.0']) {
                        return '2.0.0.11';
                }
        }
};

