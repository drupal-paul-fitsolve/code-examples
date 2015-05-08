<?php
/**
 * @file
 * All custom code of the RND15 Site Media Wall Feature
 */

/**
 * implementation of HOOK_entity_info_alter
 */
function rnd15_site_media_wall_entity_info_alter(&$entity_info) {
  $module_path = drupal_get_path('module', 'rnd15_site_media_wall');

  $entity_info['fieldable_panels_pane']['bundles']['media_wall'] = array(
    'label' => t('Media Wall Pane'),
    'pane top level' => TRUE, // set to true to make this show as a top level icon
    'pane icon' => $module_path . '/icon-pane-media-wall.png',
    'admin' => array(
      'path' => 'admin/structure/fieldable-panels-panes/manage/%fieldable_panels_panes_type',
      'bundle argument' => 4,
      'real path' => 'admin/structure/fieldable-panels-panes/manage/media-wall',
      'access arguments' => array('administer fieldable panels panes'),
    ),
  );
}

/**
 * implementation of HOOK_preprocess_panels_pane()
 *
 */
function rnd15_site_media_wall_preprocess_panels_pane(&$vars) {
  // SKIP if no type or it is not a fieldable panels pane
  if(empty($vars['pane']->type) || $vars['pane']->type != 'fieldable_panels_pane' || empty($vars['content']['#bundle']) || $vars['content']['#bundle'] != 'media_wall') return;

  // Use the field_site_cta field to provide the information we need to turn panel into a link
  $vars['pane_link'] = $vars['content']['field_site_cta']['#items'][0];
  $vars['pane_link']['attributes']['id'] = !empty($vars['id']) ? substr($vars['id'], 5, -1) : $vars['pane']->pid;
  $vars['pane_link']['attributes']['class'][] = 'pane-media-wall--content';
  $vars['pane_link']['attributes']['class'][] = 'pane-media-wall--link';
  $vars['pane_link']['attributes']['href'] = $vars['pane_link']['url'];
  $vars['pane_link']['attributes']['title'] = $vars['pane_link']['title'];

  // Provide a badge class; we know the field is required, so no checking required
  $badge = $vars['content']['field_site_media_wall_badge']['#items'][0]['value'];
  if ($badge !== 'none') {
    $vars['pane_link']['attributes']['class'][] = 'badge';
    $vars['pane_link']['attributes']['class'][] = 'badge badge--' . $badge;
  }

  // Once we have captured the ID, let's remove it so we don't have another id on the pane itself
  $vars['id'] = '';

  // Convert from attributes array to string
  $vars['pane_link']['attributes'] = drupal_attributes($vars['pane_link']['attributes']);
}