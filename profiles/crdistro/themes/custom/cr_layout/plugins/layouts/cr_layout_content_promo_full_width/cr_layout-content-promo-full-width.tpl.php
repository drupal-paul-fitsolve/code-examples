<div class="promo-wrapper equal-height-container">
  <div class="clearfix">
  <?php if(!empty($content['intro'])): ?>
      <div class="">
          <?php print $content['intro']; ?>
      </div>
  <?php endif; ?>

  <?php if(!empty($content['top'])): ?>
    <div class="">
      <?php print $content['top']; ?>
    </div>
  <?php endif; ?>
  </div>
</div>

<?php if(!empty($content['promo_bottom'])): ?>
  <div class="promo-bottom-wrapper equal-height-container">
    <div class="container-24 clearfix">
      <div class="grid-24 column">
        <?php print $content['promo_bottom']; ?>
      </div>
    </div>
  </div>
<?php endif; ?>

<div class="main-content">
  <?php if(!empty($content['row1_col1']) || !empty($content['row1_col2']) || !empty($content['row1_col3'])): ?>
    <div class="content-row-wrapper content-row-1-wrapper<?php (isset($variables['display']->context['panel-node']->data->field_row_wrapper_class['und'][0]['safe_value']) ? print " " . $variables['display']->context['panel-node']->data->field_row_wrapper_class['und'][0]['safe_value'] : NULL); ?>">
      <div class="container-24">
        <div class="<?php print $panel_adjustments['rows']['1']['classes'] ?>">
          <?php if(!empty($content['row1_col1'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['1']['columns']['1']['classes'] ?>">
                <?php print $content['row1_col1']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row1_col2'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['1']['columns']['2']['classes'] ?>">
                <?php print $content['row1_col2']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row1_col3'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['1']['columns']['3']['classes'] ?>">
                <?php print $content['row1_col3']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row1_col4'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['1']['columns']['4']['classes'] ?>">
                <?php print $content['row1_col4']; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if(!empty($content['row2_col1']) || !empty($content['row2_col2']) || !empty($content['row2_col3'])): ?>
    <div class="content-row-wrapper content-row-2-wrapper<?php (isset($variables['display']->context['panel-node']->data->field_row_2_wrapper_class['und'][0]['safe_value']) ? print " " . $variables['display']->context['panel-node']->data->field_row_2_wrapper_class['und'][0]['safe_value'] : NULL); ?>">
      <div class="container-24">
        <div class="<?php print $panel_adjustments['rows']['2']['classes'] ?>">
          <?php if(!empty($content['row2_col1'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['2']['columns']['1']['classes'] ?>">
                <?php print $content['row2_col1']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row2_col2'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['2']['columns']['2']['classes'] ?>">
                <?php print $content['row2_col2']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row2_col3'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['2']['columns']['3']['classes'] ?>">
                <?php print $content['row2_col3']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row2_col4'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['2']['columns']['4']['classes'] ?>">
                <?php print $content['row2_col4']; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if(!empty($content['row3_col1']) || !empty($content['row3_col2']) || !empty($content['row3_col3'])): ?>
    <div class="content-row-wrapper content-row-3-wrapper<?php (isset($variables['display']->context['panel-node']->data->field_row_3_wrapper_class['und'][0]['safe_value']) ? print " " . $variables['display']->context['panel-node']->data->field_row_3_wrapper_class['und'][0]['safe_value'] : NULL); ?>">
      <div class="container-24">
        <div class="<?php print $panel_adjustments['rows']['3']['classes'] ?>">
          <?php if(!empty($content['row3_col1'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['3']['columns']['1']['classes'] ?>">
                <?php print $content['row3_col1']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row3_col2'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['3']['columns']['2']['classes'] ?>">
                <?php print $content['row3_col2']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row3_col3'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['3']['columns']['3']['classes'] ?>">
                <?php print $content['row3_col3']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row3_col4'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['3']['columns']['4']['classes'] ?>">
                <?php print $content['row3_col4']; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>


  <?php if(!empty($content['row4_col1']) || !empty($content['row4_col2']) || !empty($content['row4_col3'])): ?>
    <div class="content-row-wrapper content-row-4-wrapper<?php (isset($variables['display']->context['panel-node']->data->field_row_4_wrapper_class['und'][0]['safe_value']) ? print " " . $variables['display']->context['panel-node']->data->field_row_4_wrapper_class['und'][0]['safe_value'] : NULL); ?>">
      <div class="container-24">
        <div class="<?php print $panel_adjustments['rows']['4']['classes'] ?>">
          <?php if(!empty($content['row4_col1'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['4']['columns']['1']['classes'] ?>">
                <?php print $content['row4_col1']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row4_col2'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['4']['columns']['2']['classes'] ?>">
                <?php print $content['row4_col2']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row4_col3'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['4']['columns']['3']['classes'] ?>">
                <?php print $content['row4_col3']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row4_col4'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['4']['columns']['4']['classes'] ?>">
                <?php print $content['row4_col4']; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if(!empty($content['row5_col1']) || !empty($content['row5_col2']) || !empty($content['row5_col3'])): ?>
    <div class="content-row-wrapper content-row-5-wrapper<?php (isset($variables['display']->context['panel-node']->data->field_row_5_wrapper_class['und'][0]['safe_value']) ? print " " . $variables['display']->context['panel-node']->data->field_row_5_wrapper_class['und'][0]['safe_value'] : NULL); ?>">
      <div class="container-24">
        <div class="<?php print $panel_adjustments['rows']['5']['classes'] ?>">
          <?php if(!empty($content['row5_col1'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['5']['columns']['1']['classes'] ?>">
                <?php print $content['row5_col1']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row5_col2'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['5']['columns']['2']['classes'] ?>">
                <?php print $content['row5_col2']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row5_col3'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['5']['columns']['3']['classes'] ?>">
                <?php print $content['row5_col3']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row5_col4'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['5']['columns']['4']['classes'] ?>">
                <?php print $content['row5_col4']; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if(!empty($content['row6_col1']) || !empty($content['row6_col2']) || !empty($content['row6_col3'])): ?>
    <div class="content-row-wrapper content-row-6-wrapper<?php (isset($variables['display']->context['panel-node']->data->field_row_6_wrapper_class['und'][0]['safe_value']) ? print " " . $variables['display']->context['panel-node']->data->field_row_6_wrapper_class['und'][0]['safe_value'] : NULL); ?>">
      <div class="container-24">
        <div class="<?php print $panel_adjustments['rows']['6']['classes'] ?>">
          <?php if(!empty($content['row6_col1'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['6']['columns']['1']['classes'] ?>">
                <?php print $content['row6_col1']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row6_col2'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['6']['columns']['2']['classes'] ?>">
                <?php print $content['row6_col2']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row6_col3'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['6']['columns']['3']['classes'] ?>">
                <?php print $content['row6_col3']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row6_col4'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['6']['columns']['4']['classes'] ?>">
                <?php print $content['row6_col4']; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>
</div>

<!--Subpod markup is in cr_subpods.php-->
<?php
include(dirname(__FILE__) . '/../cr_subpods.php');
?>

