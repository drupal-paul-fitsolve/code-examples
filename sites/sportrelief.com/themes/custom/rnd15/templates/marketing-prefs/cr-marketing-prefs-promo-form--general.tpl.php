<? 
 /*
 * ESU Strip template 
 * - step 1 : general email sign up
 */
?>
<div class="esu-strip__container type--centred">
  <div class="esu-strip__icon">
  </div>
  <div class="esu-strip__intro">
    <h4><?php print drupal_render($form['intro']); ?></h4>
  </div>
  <div class="esu-strip__action">
    <div class="esu-strip__email">
      <?php print drupal_render($form['email']); ?>
    </div>
    <div class="esu-strip__submit"><?php print drupal_render($form['submit']); ?></div>
  </div>
<?php print drupal_render_children($form); ?>
</div>

