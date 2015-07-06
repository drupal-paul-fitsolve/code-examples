<? 
 /*
 * ESU Strip template
 * - step 3 : Complete
 */
?>
<div class="esu-strip__container type--centred">
  <div class="esu-strip__icon esu-strip__thankyou">
    <span class="icon icon-circle icon--large type--green">
      <span class="icon icon-tick icon--large type--white"></span>
    </span>
  </div>
  <div class="esu-strip__intro">
    <h4><?php print drupal_render($form['intro']); ?></h4>
  </div>
  <div class="esu-strip__action">
  </div>
<?php print drupal_render_children($form); ?>
</div>