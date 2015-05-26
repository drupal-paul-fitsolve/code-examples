<?php

/**
 * @file
 * Contains a pre-process hook for 'node'.
 */

/**
 * Implements hook_preprocess_node().
 *
 * Ensure all view modes of a node type can be templated.
 *
 * IE. A Video node type with a View Mode of teaser would allow:
 * you to theme it's output using:
 * 
 * node--video--teaser.tpl.php
 *
 * or 
 * 
 * theme_node__video__teaser(&$variables){ ... }
 * 
 */
function sr16splash_preprocess_node(&$variables) { 

  // I think a view mode is always present in $variables but
  // let's check anyway.
  if(isset($variables['view_mode'])){
    $variables['theme_hook_suggestions'][] = 'node__' . $variables['type'] . '__' . $variables['view_mode'];
  }

  // Re. Fundraiser Showcase gallery.
  // Adds an image count class to fundraiser_showcase nodes, based on the 
  // number of images present on the node.
  // Used in node--fundraiser-showcase--teaser.tpl.php as $badge_class_with_count.
  if($variables['type'] == 'fundraiser_showcase' && $variables['view_mode'] == 'teaser' && is_array($variables['field_fundraiser_showcase_images'])){
      $variables['badge_class_with_count'] = '';
      $image_count = count($variables['field_fundraiser_showcase_images']);
      switch ($image_count) {
        case 1:
          $variables['badge_class_with_count'] = 'badge--photo--count-one';
          break;
        case 2:
          $variables['badge_class_with_count'] = 'badge--photo--count-two';
          break;
        case 3:
          $variables['badge_class_with_count'] = 'badge--photo--count-three';
          break;
      }
    }

    else if ($variables['type'] == 'webform') {
      dpm($variables['title']);
      // I think this could done better, but I don't find a better function... And there's not machine name
      $result = preg_replace('/[^a-z]/','_', strtolower($variables['title']));
      $variables['theme_hook_suggestions'][] = 'html__node__' . $result;
    }
  
  }