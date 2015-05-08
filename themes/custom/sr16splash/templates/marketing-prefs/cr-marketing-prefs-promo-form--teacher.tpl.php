<? 
 /*
 * ESU Strip template
 * - step 2 : teacher age group dropdown
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
    <div class="esu-strip__email"><?php print drupal_render($form['phase']); ?></div>
    <div class="esu-strip__submit esu-strip__submit_age"><?php print drupal_render($form['submit']); ?></div>
  </div>
<?php print drupal_render_children($form); ?>
</div>