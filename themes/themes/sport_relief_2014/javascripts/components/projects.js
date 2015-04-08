/**
   * Add a class to the project wrapper on load
   */

(function ($) {
    Drupal.behaviors.sportrelief_2014.projects = function(context) {
      var $projectSelect = $('#edit-field-project-region-tid', context);
      if($projectSelect.length == 0) {
        return;
      }
      var region = $projectSelect.val();
      var $regionBackground = $('.projects-region-background');
      $regionBackground.removeClass (function (index, css) {
          return (css.match (/\bprojects-region-background--\S+/g) || []).join(' ');
      }).addClass('projects-region-background--' + region);

      // This is a hack to get auto submit working FML
    //   $projectSelect.on('change', function(){
    //     var $this = $projectSelect.closest('form.ctools-auto-submit-full-form');
    //     if (!$this.hasClass('ctools-ajaxing')) {
    //       $this.find('.ctools-auto-submit-click').click();
    //     }
    //   });
    };

})(jQuery);
