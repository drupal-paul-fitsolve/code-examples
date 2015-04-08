/**
 * @file
 * Calculate the user's region using geolocation, then modify the views filter.
 * REQUIRES: jquery.inview.js
 */

 var viewsFilerGeo = {};

(function ($) {


  $(window).load(function() {
    viewsFilerGeo.wrapper = $('#edit-field-project-region-tid-wrapper');
    viewsFilerGeo.exposedFilter = $('#edit-field-project-region-tid');
    if(viewsFilerGeo.exposedFilter.length == 0) {
      return;
    }
    $(viewsFilerGeo.wrapper).on('inview', function(event, isInView, visiblePartX, visiblePartY) {
      if (isInView && visiblePartY == 'both') {
        viewsFilerGeo.getGeo();
        $(viewsFilerGeo.wrapper).off('inview');
      }
    });
  });

  /**
   * If availiable, get the Geo location from the user's device.
   */
  viewsFilerGeo.getGeo = function() {
    if ("geolocation" in navigator) {
      navigator.geolocation.getCurrentPosition(function(position) {
        viewsFilerGeo.calculateRegion(position.coords.latitude, position.coords.longitude);
      });
    }
  };

  /**
   * Ping google maps for a address, then do your best to match it to the availiable options.
   */
  viewsFilerGeo.calculateRegion = function(lat,lng) {
    var api = 'http://maps.googleapis.com/maps/api/geocode/json?latlng=' + lat + ',' + lng + '&sensor=true';
    var filterOptions = viewsFilerGeo.getFilterOptions();
    $.getJSON(api, {}, function(data) {
      if( data.results.length === 0) {
        return;
      }
      var result = data.results[0];
      for (var i = result.address_components.length - 1; i >= 0; i--) {
        var longName = result.address_components[i].long_name;
        var matchingOptions = $(filterOptions).filter(function(){
            return this.name == longName;
        });
        if(matchingOptions.length > 0){
          viewsFilerGeo.setFilterOption(matchingOptions);
          return;
        }
      };
    });
  }

  /**
   * Grab the options availiable in the views filter and return them as an array.
   */
  viewsFilerGeo.getFilterOptions = function() {
    var options = Array();
    var optionElements = $(viewsFilerGeo.exposedFilter).find('option:not(:selected)');
    for (var i = optionElements.length - 1; i >= 0; i--) {
      options.push(
        { name: $(optionElements[i]).text(),
          value: $(optionElements[i]).val(),
      });
    };
    return options;
  }

  /**
   * Set the option of the views filter.
   */
  viewsFilerGeo.setFilterOption = function(options) {
    $(viewsFilerGeo.exposedFilter).val(options[0].value).change();
  }

})(jQuery);
