<div class="main-content">
  <div class="container-24 clearfix">
    <?php if(!empty($content['intro'])): ?>
      <div class="leader-double grid-24 alpha omega">
        <div class="column">
            <?php print $content['intro']; ?>
        </div>
      </div>
    <?php endif; ?>
  </div>

  <?php if(!empty($content['row1_col1']) || !empty($content['row1_col2']) || !empty($content['row1_col3'])): ?>
    <div class="content-row-wrapper content-row-1-wrapper">
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
    <div class="content-row-wrapper content-row-2-wrapper">
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
    <div class="content-row-wrapper content-row-3-wrapper">
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
    <div class="content-row-wrapper content-row-4-wrapper">
      <div class="container-24">
        <div class="<?php print $panel_adjustments['rows']['3']['classes'] ?>">
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
    <div class="content-row-wrapper content-row-5-wrapper">
      <div class="container-24">
        <div class="<?php print $panel_adjustments['rows']['3']['classes'] ?>">
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
    <div class="content-row-wrapper content-row-6-wrapper">
      <div class="container-24">
        <div class="<?php print $panel_adjustments['rows']['3']['classes'] ?>">
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

<?php if(!empty($content['row7_col1']) || !empty($content['row7_col2']) || !empty($content['row7_col3'])): ?>
    <div class="content-row-wrapper content-row-7-wrapper">
      <div class="container-24">
        <div class="<?php print $panel_adjustments['rows']['3']['classes'] ?>">
          <?php if(!empty($content['row7_col1'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['7']['columns']['1']['classes'] ?>">
                <?php print $content['row7_col1']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row7_col2'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['7']['columns']['2']['classes'] ?>">
                <?php print $content['row7_col2']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row7_col3'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['7']['columns']['3']['classes'] ?>">
                <?php print $content['row7_col3']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row7_col4'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['7']['columns']['4']['classes'] ?>">
                <?php print $content['row7_col4']; ?>
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
