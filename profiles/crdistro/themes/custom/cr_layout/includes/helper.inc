<?php
/**
 * Parses the structure of the panels layout and returns classes to be applied to each container and row
 *
 * This function is called from preprocess layout functions:
 * @see preprocess-poc2013-content.inc
 *
 * These classes get printed out in the layout template files:
 * @see poc2013-content.tpl.php
 *
 * @param array $structure
 *  A description of the rows and columns in this layout
 *   'max-rows' (integer)
 *   'max-columns' (integer)
 *   'grid-column-total' (integer)
 *
 * @param array $settings
 *  Additional settings to customise the output
 *  - prefix: A string to prefix to the grid classes
 *  - equal-heights: A boolean, adds equal height classes
 *
 * @return array $panels_adjustments
 *  An associative array containing:
 *  - rows: An array of rows containing:
 *    - classes: A string of classes to apply to that row
 *    - columns: An array of columns containing:
 *     - classes A string of classes to apply to that column
 */
function _cr_layout_calculate_panels_layout(&$vars, $structure = array(), $settings = array()){

  // Grab the classes prefix
  $class_prefix = (isset($settings['prefix']) ? $settings['prefix'] : '');
  //Print equal heights?
  $equal_heights = (isset($settings['equal-heights']) ? $settings['equal-heights'] : TRUE);
  // The layout should pass in it's total columns default to 24.
  $grid_column_total = (isset($structure['grid-column-total']) ? $structure['grid-column-total'] : 24);
  $panel_adjustments = array();
  $max_rows = (isset($structure['max-rows']) ? $structure['max-rows'] : 6);
  $max_columns = (isset($structure['max-columns']) ? $structure['max-columns'] : 3);

  // Loop through content variable, creating array items for each iteration
  foreach($vars['layout']['regions'] as $id => $region){
    // Grab the contents of that region too see if it's empty
    $is_empty = TRUE;
    foreach($vars['display']->content as $key => $column) {
      if($column->panel == $id) {
        $is_empty = FALSE;
      }
    }
    // Extract row/column from panel name using regex
    // @TODO refactor this so it doesn't rely on a specific region naming structure if possible
    $rownumber = preg_match( '/(?<=row)[0-9]*/', $id, $row_match );
    $columnnumber = preg_match( '/(?<=col)[0-9]*/', $id, $col_match );
    if(isset($row_match[0]) && isset($col_match[0])){
      $panel_adjustments['rows'][$row_match[0]]['columns'][$col_match[0]] = array('is_empty'=> $is_empty);
    }
  }

  // Loop through rows
  if(isset($panel_adjustments['rows'])){
  foreach($panel_adjustments['rows'] as $rowid => &$row){

    // Get size of array, and create total-columns item
    $row_columns = 0;
    foreach($row['columns'] as $columnid => &$columns){
      if(!$columns['is_empty']) {
        $row_columns++;
      }
    }
    // Divide the total number of columns by the number of columns for equal width columns
    if($row_columns != 0) {
      $columns_width = $grid_column_total / $row_columns;
    }
    else {
      $columns_width = $grid_column_total;
    }
    $row_classes = array();

    // Set row width class array
    // $row_classes[] = 'alpha';
    // $row_classes[] = 'omega';
    $row_classes[] = 'row';
    $row_classes[] = $class_prefix . 'grid-' . $grid_column_total;
    if ($equal_heights && $row_columns > 1) {
      $row_classes[] = 'equal-height-container';
    }

    // Set row classes string
    $row['classes'] = implode(" ", $row_classes);

    $column_count = 1;
    // Loop through columns and create classes
    foreach($row['columns'] as $columnid => &$columns){
      $column_classes = array();
      $column_classes[] = $class_prefix . 'grid-' . $columns_width;
      // If column is empty, hide it for non-admins
      if($columns['is_empty']) {
        $column_classes[] = 'admin-only';
      }
      else {
        if($equal_heights) {
          $column_classes[] = 'equal-height-element-two';
        }
        //If first column, add alpha class
        if($column_count === 1){
          $column_classes[] = $class_prefix . 'alpha';
        }
        //If last column, add omega class
        if($column_count === $row_columns){
          $column_classes[] = $class_prefix . 'omega';
        }
        $column_count++;
      }

      // Convert classes into a string
      $row['columns'][$columnid]['classes'] = implode($column_classes, " ");
    }
  }
}
  ksort($panel_adjustments['rows']);
  return $panel_adjustments;
}

?>
