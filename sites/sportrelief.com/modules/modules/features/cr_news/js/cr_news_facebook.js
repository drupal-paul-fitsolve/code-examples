(function($) {
  $.fbInit = function() {
    var $newDiv = $('<div />').attr('id','fb-root');
    $('body').prepend($newDiv);
    // Load the SDK Asynchronously
    (function(d, s, id) {
      var js, fjs = d.getElementsByTagName(s)[0];
      if (d.getElementById(id)) return;
      js = d.createElement(s); js.id = id;
      js.src = "//connect.facebook.net/en_US/all.js#xfbml=1&appId=527258650691001";
      fjs.parentNode.insertBefore(js, fjs);
    }(document, 'script', 'facebook-jssdk'));
  };

  $(document).ready(function(){
   $.fbInit();
  });

})(jQuery);