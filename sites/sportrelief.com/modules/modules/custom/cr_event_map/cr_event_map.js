
/**
 * Comic Relief Event Map JS
 */
(function ($) {
Drupal.behaviors.cr_event_map = {
  $map_container: null,

  search_form_selector: '#cr-event-map-search-form',
  search_wrapper_selector: '#edit-search-events',
  $search_form: null,
  $map_search_input: null,
  $map_filter_select: null,
  $map_search_wrapper: null,

  filterPositions : [
    // London
    { keywordCheck : /^Queen Elizabeth Olympic Park$/i, position: '51.5446483,-0.0135219' },
    { keywordCheck : /^Olympic Park$/i, position: '51.5446483,-0.0135219' },
    { keywordCheck : /^Olympics$/i, position: '51.5446483,-0.0135219' },
    { keywordCheck : /^Stadium$/i, position: '51.5446483,-0.0135219' },
    { keywordCheck : /^Olympic Stadium$/i, position: '51.5446483,-0.0135219' },
    { keywordCheck : /^Aquatics Centre$/i, position: '51.5401405,-0.0094729' },
    { keywordCheck : /^London Aquatics Centre$/i, position: '51.5401405,-0.0094729' },
    { keywordCheck : /^Olympic Pool$/i, position: '51.5401405,-0.0094729' },
    { keywordCheck : /^Lee Valley$/i, position: '51.5506116,-0.0141191' },
    { keywordCheck : /^Velopark$/i, position: '51.5506116,-0.0141191' },
    { keywordCheck : /^Velodrome$/i, position: '51.5506116,-0.0141191' },
    { keywordCheck : /^London Velodrome$/i, position: '51.5506116,-0.0141191' },

    // Glasgow
    { keywordCheck : /^Chris Hoy Velodrome$/i, position: '55.8464191,-4.2090061' },
    { keywordCheck : /^Chris Hoy Velopark$/i, position: '55.8464191,-4.2090061' },
    { keywordCheck : /^Tollcross Park$/i, position: '55.8478783,-4.1805348' },
    { keywordCheck : /^Tollcross pool$/i, position: '55.8450439,-4.176008' },

    // Manchester
    { keywordCheck : /^Old Trafford$/i, position: '53.4631439,-2.2913467' },
  ],
  
  isFilteredSearch : false,

  map: {},
  map_loaded: false,
  layer: {},
  
  userPosition: null,
  searchPosition: null,
  markers: [],
  currentFilter: '',

  breakpoint: '',
  
  config: {
    map_container_selector: '#gmap-container',
    tableid: null,
    apikey: null,
    default_filter: 'all',
    marker_limit: 10,
    info_bubble_height: 120,
    cycleZoomLevel: 7,
    filteredKeywordZoomLevel : 14,
    // For info bubble options please see:
    // http://google-maps-utility-library-v3.googlecode.com/svn/trunk/infobubble/src/infobubble.js
    info_bubble_options: {
      backgroundColor: '#292929',
      borderWidth: 0,
      borderColor: 'transparent',
      borderRadius: 3,
      padding: 20,
      minWidth: 300,
      maxWidth: 300,
      disableAutoPan: false,
      disableAnimation: false,
      arrowSize: 15,
      closeBoxURL: "http://www.google.com/intl/en_us/mapfiles/close.gif"
    },
    map_settings: {
      default_zoomlevel: 6,
      default_searchzoomlevel: 11,
      default_position: '53.943155,-2.373047'
    }
  },
  gMapDefaultOptions: {
    center: null,
    zoom: 6,
    scrollwheel: false,
    mapTypeId: google.maps.MapTypeId.ROADMAP
  },

  infoBubble: new InfoBubble(),
  geocoder: new google.maps.Geocoder(),

  attach: function(context, settings) {
    var _base = Drupal.behaviors.cr_event_map;

    // Check we have vital information
    if(!settings.cr_event_map.tableid || !settings.cr_event_map.apikey) {
      console.log('Error: No Table ID or API key specified');
      return;
    }

    // Extends our default config with cr_event_map settings
    _base.config = $.extend(_base.config, Drupal.settings.cr_event_map);

    // Initialize the gmap only running it once
    $(_base.config.map_container_selector, context).once('cr-event-map',_base.map_container_once);
  },

  /*
   * Core Initaliser
   */
  map_container_once: function() {
    var _base = Drupal.behaviors.cr_event_map;

    // Assign map container
    _base.$map_container = $(this);
    _base.$search_form = $(_base.search_form_selector);
    _base.$map_search_input = $('[name="map_search_field"]', _base.$search_form);
    _base.$map_filter_select = $('[name="search_filter"]', _base.$search_form);
    _base.$map_search_wrapper = $(_base.search_wrapper_selector, _base.$search_form);

    // Assign info bubble options
    _base.infoBubble.setValues(_base.config.info_bubble_options);

    // Handle position once map has loaded
    _base.$map_container.on('cr_event_map.map.loaded', _base.set_map_position);
    _base.$map_container.on('cr_event_map.map.loaded', function(e){ Drupal.behaviors.cr_event_map.map_loaded = true; });

    $(document).on('responsivelayout', _base.handle_map_resize);

    // Map Event Handler
    $('#map_search', _base.$search_form).on('click', _base.handle_search_formsubmit);
    _base.$map_filter_select.on('change', _base.handle_search_formsubmit);

    // Init the google map first off
    _base.initliaze_google_map();
  },

  /*
   * Initalize the google map
   */
  initliaze_google_map: function() {
    var _base = Drupal.behaviors.cr_event_map;
    var newPos = _base.config.map_settings.default_position.split(',');

    _base.gMapDefaultOptions.center = new google.maps.LatLng(newPos[0],newPos[1]);
    _base.gMapDefaultOptions.zoom = parseInt(_base.config.map_settings.default_zoom);

    _base.map = new google.maps.Map(_base.$map_container[0], _base.gMapDefaultOptions);
    google.maps.event.addListenerOnce(_base.map, 'idle', function(){
        // do something only the first time the map is loaded
        _base.$map_container.trigger('cr_event_map.map.loaded');
        _base.handle_map_resize();
    });
  },

  /*
   * Main Functions
   */
  fetch_fusion_table_data: function(position, filter) {
    var _base = Drupal.behaviors.cr_event_map;
    var position_lookup = null;

    if(position) {
      position_lookup = _base.searchPosition = position;
    } else {
      position_lookup = _base.userPosition;
    }

    var searchLatLngString = position_lookup.toString();

    // https://developers.google.com/fusiontables/docs/v1/sql-reference
    var query = 'SELECT name, description, Coordinates, type, status, cta FROM '+ _base.config.tableid;
    if(filter && filter !== 'all') {
      query += ' WHERE type = \''+filter+'\'';
    }
    query += ' ORDER BY ST_DISTANCE(Coordinates, LATLNG'+searchLatLngString+')';
    query += ' LIMIT '+_base.config.marker_limit;

    var encodedQuery = encodeURIComponent(query);

    // Construct the URL
    var url = ['https://www.googleapis.com/fusiontables/v1/query'];
        url.push('?sql=' + encodedQuery);
        url.push('&key=' + _base.config.apikey);
        url.push('&callback=?');

    // Send the JSONP request using jQuery
    $.ajax({
      url: url.join(''),
      dataType: 'jsonp',
      success: _base.handle_fusion_table_data_fetched
    });
  },
  handle_fusion_table_data_fetched: function(data) {
    var _base = Drupal.behaviors.cr_event_map, rows = data['rows'], iconUrl, content, coordinate, type, status,
    DEFAULT_ICON_URL = 'http://maps.gstatic.com/intl/en_ALL/mapfiles/ms/micons/blue-dot.png',
    coordinate_root,
    get_status_class = function(str){
      return str.split(" ")[0].toLowerCase();
    };

    _base.clearMarkers();

    if(_base.searchPosition) {
      var marker = new google.maps.Marker({
          map: _base.map,
          position: _base.searchPosition
      });
      _base.markers.push(marker);
    }

    _base.map.setCenter(_base.searchPosition);
    if(_base.currentFilter === 'cycle') {
      _base.map.setZoom(parseInt(_base.config.cycleZoomLevel, 10));
    } else if(_base.isFilteredSearch){
      _base.map.setZoom(parseInt(_base.config.filteredKeywordZoomLevel, 10));
    } else {
      _base.map.setZoom(parseInt(_base.config.map_settings.default_searchzoom, 10));
    }

    for (var i in rows) {
      coorinate_root = rows[i][2]['geometry']['coordinates'];
      coordinate = new google.maps.LatLng(coorinate_root[1],coorinate_root[0]);
      status = '<p class="status '+get_status_class(rows[i][4])+'">' + rows[i][4] + '</p>';
      cta = rows[i][5];
      content = rows[i][1] + status + cta;
      type = rows[i][3];
      iconUrl = DEFAULT_ICON_URL;

      if(_base.config.filter_markers[type]) {
        iconBase64 = _base.config.filter_markers[type];
      }
      _base.map_create_marker(coordinate, iconBase64, content, type);
    }
  },

  /* 
   * Event Handlers
   */
  handle_search_formsubmit: function(event) {
    event.preventDefault();
    var _base = Drupal.behaviors.cr_event_map;
    var search_string = _base.$map_search_input.val();
    _base.currentFilter = _base.$map_filter_select.val();

    // Track the click event on a search event
    _gaq.push(['_trackEvent', 'Map Form: ' + Drupal.settings.cr_event_map.default_filter, 'Submit', _base.currentFilter + ' custom filter']);

    if(_base.map_loaded) {
      if(search_string === '' && !_base.userPosition) {
        _base.throw_form_error('Please enter your Postcode or Town.');
        return false;
      } else{
        _base.remove_form_errors();
        // Filters any searches to predefined coordines
        var filteredSearchPosition = _base.filterSearch(search_string);

        // Sets global var so we know it's a filtered search
        _base.isFilteredSearch = filteredSearchPosition;

        _base.handleProximitySearch(search_string, filteredSearchPosition);
      }
    }
    return false;
  },

  /*
   * Filter Keywords
   */
  filterSearch: function(searchstr) {
    var _base = Drupal.behaviors.cr_event_map;
    var matches = [];
    var newPos = null;
    searchstr = $.trim(searchstr);

    // Filter through the keyewords and test the regular expression
    for (var i=0, len=_base.filterPositions.length; i<len; i++) {
      if(_base.filterPositions[i].keywordCheck.test(searchstr)) {
        // Create the gmap latlng object based on the matched position
        newPos = _base.filterPositions[i].position.split(',');
        newPos = new google.maps.LatLng(newPos[0], newPos[1]);
        break;
      }
    }

    // Returns either null or gmap object
    return newPos;
  },

  handleProximitySearch: function(search_string, coords) {
    var _base = Drupal.behaviors.cr_event_map;
    
    search_location = _base.userPosition;

    if(search_string !== '' && !coords) {
      _base.geocoder.geocode( { 'address': search_string + ', UK'}, function(results, status) {
        if (status == google.maps.GeocoderStatus.OK)
          search_location = results[0].geometry.location;
          _base.map.setCenter(search_location);
          _base.fetch_fusion_table_data(search_location, _base.currentFilter);
      });
    } else if(search_location || coords) {
      search_location = coords || search_location;
      _base.fetch_fusion_table_data(search_location, _base.currentFilter);
    }
  },
  success_callback_getCurrentPosition: function(position){
    var _base = Drupal.behaviors.cr_event_map;
    _base.userPosition = new google.maps.LatLng(position.coords.latitude, position.coords.longitude);
    _base.fetch_fusion_table_data(_base.userPosition, _base.config.default_filter);
  },
  error_callback_getCurrentPosition: function(PositionError){
    //var _base = Drupal.behaviors.cr_event_map;
  },


  /* 
   * Map Utility Functions
   */
  set_map_position: function() {
    var _base = Drupal.behaviors.cr_event_map;
    if(navigator.geolocation) {
      navigator.geolocation.getCurrentPosition(_base.success_callback_getCurrentPosition, _base.error_callback_getCurrentPosition, {timeout:3000});
    }
  },
  map_create_marker: function(coordinate, iconBase64, content, type) {
    var _base = Drupal.behaviors.cr_event_map;

    var marker = new google.maps.Marker({
      map: _base.map,
      position: coordinate,
      icon: 'data:image/png;base64,'+iconBase64
    });
    //new google.maps.MarkerImage(url)
    _base.markers.push(marker);
    google.maps.event.addListener(marker, 'click', function(event) {
      var marker_markup = '<div class="info-bubble-content info-event-type-'+type+'" style="height:'+_base.config.info_bubble_height+'px;">'+content+'</div>';
      _base.infoBubble.setContent(marker_markup);
      _base.infoBubble.open(_base.map, this);
    });
  },
  clearMarkers: function() {
    var _base = Drupal.behaviors.cr_event_map;
    for (var i = 0; i < _base.markers.length; i++ ) {
      _base.markers[i].setMap(null);
    }
    _base.markers = [];
  },
  handle_map_resize: function(e) {
    var _base = Drupal.behaviors.cr_event_map;
    var new_breakpoint = Drupal.omega.getCurrentLayout();
    
    if(new_breakpoint != Drupal.behaviors.cr_event_map.breakpoint) {

      var new_height = _base.config.map_settings.breakpoints[new_breakpoint].height;
      var center = _base.map.getCenter();

      _base.$map_container.css({'height':new_height});
      google.maps.event.trigger(_base.map, "resize");
      _base.map.setCenter(center);

      _base.breakpint = new_breakpoint;
    }

    if(typeof Drupal.behaviors.omegaEqualHeights == 'function') {
      Drupal.behaviors.omegaEqualHeights(_base.$map_container.parents('.equal-height-container'));
    }
  },

  throw_form_error: function(message) {
    var _base = Drupal.behaviors.cr_event_map;
    if(!_base.hasError) {
      $('<div class="clientside-error error"><p class="error">'+message+'</p></div>').insertAfter(_base.$map_search_wrapper);
      _base.hasError = true;
    }
  },
  remove_form_errors: function() {
    var _base = Drupal.behaviors.cr_event_map;
    _base.$map_search_wrapper.siblings('.clientside-error').fadeOut('fast', function(){ $(this).remove(); });
  }

}; // End Drupal.behaviors.cr_event_map

})(jQuery);
