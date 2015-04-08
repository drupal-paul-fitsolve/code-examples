<?php
/**
 * The "example_behavior_plugin" Entity Reference plugin.
 */
class CrVideoInstanceBehaviorPlugin extends EntityReference_BehaviorHandler_Abstract {
  /**
   * Generate a settings form for this handler.
   */
  public function settingsForm($field, $instance) {
    $field_name = $field['field_name'];
    dsm($field);
    dsm($instance);
    $form['video_token_insert'] = array(
      '#type' => 'checkbox',
      '#title' => t('Apply video token insert'),
      '#description' => t('Applying a predetermined video token and an insert button'),
    );

    return $form;
  }
}
?>