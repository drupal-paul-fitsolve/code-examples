<?php

function cr_event_kml_parser_info() {

	$parsers = array(
		'cr_event_map_kml_parser_default' => array(
			'name' => 'Default KML to CSV'
		),
		'cr_event_map_kml_parser_sr14' => array(
			'name' => 'SR14 KML to CSV'
		),

	);

	return $parsers;
}

/*
 * Default Parser
 * Params: 
 * $kml_file = Drupal File Object
 * $machine_name = Machine friendly name of the Event Data Source
 */
function cr_event_map_kml_parser_default($machine_name, $kml_file, $verbose = false) {
  $csv_directory = CR_CSV_LOCATION;
  if(!file_prepare_directory($csv_directory, FILE_CREATE_DIRECTORY)) {
    drupal_set_message(t('Could not create required folder.'));
    return;
  }

  $kml_file_path = drupal_realpath($kml_file->uri);

  $csv_destination = $csv_directory . $machine_name . '.csv';
  $csv_file_path = drupal_realpath($csv_destination);

  $xml = new SimpleXMLElement($kml_file_path, NULL, TRUE);
  
  $f = fopen($csv_file_path, 'w');
  foreach($xml->Document->Placemark as $event) {
    $old_coords = (string)$event->Point->coordinates;
    $coord = preg_split('/,/',$old_coords);
    $new_coords = $coord[1].','.$coord[0].','.$coord[2];
    $event->Point->coordinates = $new_coords;

    $fields = array($event->description, $event->name, '<Point><coordinates>'.$event->Point->coordinates.'</coordinates></Point>');
    fputcsv($f, $fields,',');
    //$event->iconUrl = 'http://maps.gstatic.com/intl/en_ALL/mapfiles/ms/micons/red-dot.png';
  }
  fclose($f);

  return $csv_file_path;
}

function cr_event_map_kml_parser_sr14($machine_name, $kml_file, $verbose = false) {
  $csv_directory = CR_CSV_LOCATION;
  if(!file_prepare_directory($csv_directory, FILE_CREATE_DIRECTORY)) {
    drupal_set_message(t('Could not create required folder.'));
    return false;
  }

  $kml_file_path = drupal_realpath($kml_file->uri);

  $csv_destination = $csv_directory . $machine_name . '.csv';
  $csv_file_path = drupal_realpath($csv_destination);

  if(!file_exists($kml_file_path)) {
    watchdog('cr_event_map', 'There was no KML file to choose from.', array(), WATCHDOG_ERROR);
    if($verbose) {
      drupal_set_message('There was no KML file to choose from.', WATCHDOG_ERROR);
    }
    return false;
  }
  
  try {
    $xml = new SimpleXMLElement($kml_file_path, NULL, TRUE);
  } catch (Exception $e) { 
    watchdog_exception('cr_event_map', $e);
    if($verbose) {
      drupal_set_message('Caught Exception in XML Parser: '.$e->getMessage());
    }
    return false;
  }
  
  // If we have an xml file, parse it, otherwise throw error
  if(!$xml) {
    if($verbose) {
      drupal_set_message('There was an error parsing the XML data.');
    }
    watchdog('cr_event_map', 'There was an error parsing the XML data.', array(), WATCHDOG_ERROR);
  }

  // We should be fine to run the parsing now.
  $f = fopen($csv_file_path, 'w');
  foreach($xml->Document->Placemark as $event) {
    $old_coords = (string)$event->Point->coordinates;
    $coord = preg_split('/,/',$old_coords);
    $new_coords = $coord[1].','.$coord[0].','.$coord[2];
    $event->Point->coordinates = $new_coords;

    $desc_dom = new DOMDocument();
    @$desc_dom->loadHTML($event->description);

    $links = $desc_dom->getElementsByTagName('a');
    foreach ($links as $link) {
      $cta = $desc_dom->saveHTML($link);
    }

    $desc_dom->removeChild($desc_dom->firstChild);# remove <!DOCTYPE 
    $desc_dom->replaceChild($desc_dom->firstChild->firstChild->firstChild, $desc_dom->firstChild);# remove <html><body></body></html> 
    
    // Save description and remove the link
    $description = $desc_dom->saveHTML();
    $description = str_replace('<br>'.$cta,'', $description);

    $fields = array(
    	$description, 
    	$event->name, 
      '<Point><coordinates>'.$event->Point->coordinates.'</coordinates></Point>', 
    	substr($event->styleUrl, 1), // Removes hash from style 
      $cta,
    	$event->status
    );
    fputcsv($f, $fields,',');
    //$event->iconUrl = 'http://maps.gstatic.com/intl/en_ALL/mapfiles/ms/micons/red-dot.png';
  }
  fclose($f);


  return $csv_file_path;
}