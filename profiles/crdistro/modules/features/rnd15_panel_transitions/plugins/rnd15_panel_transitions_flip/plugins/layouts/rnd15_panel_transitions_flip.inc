<?php
/**
 * @file panel_transitions_flip.inc
 * 
 * Define a Panels layout plugin for Transitions: Flip mini-panels.
 * 
 * Author: P.Brady
 * Last updated: 10th September 2014
 *
 */

$plugin = array(
  'title' => t('Transition: Flip'),
  'category' => t('Transitions'),
  'icon' => 'panel-transitions--flip.png',
  'theme' => 'panel_transitions__flip', // panel-transitions-flip.tpl.php
  'regions' => array(
    'front' => t('Front'),
    'back' => t('Back'),    
  ),
  'hook theme' => array(
    'rnd15_panel_transitions_flip_regions' => array(
      'variables' => array(
        'content' => NULL,
      ),
      'template' => 'panel-transitions--flip',
    ),
  ),
);

