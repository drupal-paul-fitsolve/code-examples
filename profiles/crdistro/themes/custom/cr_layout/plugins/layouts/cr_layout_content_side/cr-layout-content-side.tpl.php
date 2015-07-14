<div class="main-content">
  <div class="container-24 clearfix">
    <div class="leader-double grid-24 narrow-grid-24 ">
      <?php if(!empty($content['intro'])): ?>
        <div class="column">
            <?php print $content['intro']; ?>
        </div>
      <?php endif; ?>
    </div>

    <div class="grid-24">
      <div class="grid-18 narrow-grid-24 narrow-no-equality alpha">
        <?php if(!empty($content['row1_col1']) || !empty($content['row1_col2']) || !empty($content['row1_col3'])): ?>
          <div class="alpha omega <?php print $panel_adjustments['rows']['1']['classes'] ?> <?php print $narrow_panel_adjustments['rows']['1']['classes'] ?>">
            <?php if(!empty($content['row1_col1'])): ?>
              <div class="column <?php print $panel_adjustments['rows']['1']['columns']['1']['classes'] ?> <?php print $narrow_panel_adjustments['rows']['1']['columns']['1']['classes'] ?>">
                  <?php print $content['row1_col1']; ?>
              </div>
            <?php endif; ?>
            <?php if(!empty($content['row1_col2'])): ?>
              <div class="column <?php print $panel_adjustments['rows']['1']['columns']['2']['classes'] ?> <?php print $narrow_panel_adjustments['rows']['1']['columns']['2']['classes'] ?>">
                  <?php print $content['row1_col2']; ?>
              </div>
            <?php endif; ?>
            <?php if(!empty($content['row1_col3'])): ?>
              <div class="column <?php print $panel_adjustments['rows']['1']['columns']['3']['classes'] ?> <?php print $narrow_panel_adjustments['rows']['1']['columns']['3']['classes'] ?>">
                  <?php print $content['row1_col3']; ?>
              </div>
            <?php endif; ?>
          </div>
        <?php endif; ?>

        <?php if(!empty($content['row2_col1']) || !empty($content['row2_col2']) || !empty($content['row2_col3'])): ?>
          <div class="alpha omega <?php print $panel_adjustments['rows']['2']['classes'] ?> <?php print $narrow_panel_adjustments['rows']['2']['classes'] ?>">
            <?php if(!empty($content['row2_col1'])): ?>
              <div class="column <?php print $panel_adjustments['rows']['2']['columns']['1']['classes'] ?> <?php print $narrow_panel_adjustments['rows']['2']['columns']['1']['classes'] ?>">
                  <?php print $content['row2_col1']; ?>
              </div>
            <?php endif; ?>
            <?php if(!empty($content['row2_col2'])): ?>
              <div class="column <?php print $panel_adjustments['rows']['2']['columns']['2']['classes'] ?> <?php print $narrow_panel_adjustments['rows']['2']['columns']['2']['classes'] ?>">
                  <?php print $content['row2_col2']; ?>
              </div>
            <?php endif; ?>
            <?php if(!empty($content['row2_col3'])): ?>
              <div class="column <?php print $panel_adjustments['rows']['2']['columns']['3']['classes'] ?> <?php print $narrow_panel_adjustments['rows']['2']['columns']['3']['classes'] ?>">
                  <?php print $content['row2_col3']; ?>
              </div>
            <?php endif; ?>
          </div>
        <?php endif; ?>

        <?php if(!empty($content['row3_col1']) || !empty($content['row3_col2']) || !empty($content['row3_col3'])): ?>
          <div class="alpha omega <?php print $panel_adjustments['rows']['3']['classes'] ?> <?php print $narrow_panel_adjustments['rows']['3']['classes'] ?>">
            <?php if(!empty($content['row3_col1'])): ?>
              <div class="column <?php print $panel_adjustments['rows']['3']['columns']['1']['classes'] ?> <?php print $narrow_panel_adjustments['rows']['3']['columns']['1']['classes'] ?>">
                  <?php print $content['row3_col1']; ?>
              </div>
            <?php endif; ?>
            <?php if(!empty($content['row3_col2'])): ?>
              <div class="column <?php print $panel_adjustments['rows']['3']['columns']['2']['classes'] ?> <?php print $narrow_panel_adjustments['rows']['3']['columns']['2']['classes'] ?>">
                  <?php print $content['row3_col2']; ?>
              </div>
            <?php endif; ?>
            <?php if(!empty($content['row3_col3'])): ?>
              <div class="column <?php print $panel_adjustments['rows']['3']['columns']['3']['classes'] ?> <?php print $narrow_panel_adjustments['rows']['3']['columns']['3']['classes'] ?>">
                  <?php print $content['row3_col3']; ?>
              </div>
            <?php endif; ?>
          </div>
        <?php endif; ?>

        <?php if(!empty($content['row4_col1']) || !empty($content['row4_col2']) || !empty($content['row4_col3'])): ?>
          <div class="alpha omega <?php print $panel_adjustments['rows']['4']['classes'] ?> <?php print $narrow_panel_adjustments['rows']['4']['classes'] ?>">
            <?php if(!empty($content['row4_col1'])): ?>
              <div class="column <?php print $panel_adjustments['rows']['4']['columns']['1']['classes'] ?> <?php print $narrow_panel_adjustments['rows']['4']['columns']['1']['classes'] ?>">
                  <?php print $content['row4_col1']; ?>
              </div>
            <?php endif; ?>
            <?php if(!empty($content['row4_col2'])): ?>
              <div class="column <?php print $panel_adjustments['rows']['4']['columns']['2']['classes'] ?> <?php print $narrow_panel_adjustments['rows']['4']['columns']['2']['classes'] ?>">
                  <?php print $content['row4_col2']; ?>
              </div>
            <?php endif; ?>
            <?php if(!empty($content['row4_col3'])): ?>
              <div class="column <?php print $panel_adjustments['rows']['4']['columns']['3']['classes'] ?> <?php print $narrow_panel_adjustments['rows']['4']['columns']['3']['classes'] ?>">
                  <?php print $content['row4_col3']; ?>
              </div>
            <?php endif; ?>
          </div>
        <?php endif; ?>

        <?php if(!empty($content['row5_col1']) || !empty($content['row5_col2']) || !empty($content['row5_col3'])): ?>
          <div class="alpha omega <?php print $panel_adjustments['rows']['5']['classes'] ?> <?php print $narrow_panel_adjustments['rows']['5']['classes'] ?>">
            <?php if(!empty($content['row5_col1'])): ?>
              <div class="column <?php print $panel_adjustments['rows']['5']['columns']['1']['classes'] ?> <?php print $narrow_panel_adjustments['rows']['5']['columns']['1']['classes'] ?>">
                  <?php print $content['row5_col1']; ?>
              </div>
            <?php endif; ?>
            <?php if(!empty($content['row5_col2'])): ?>
              <div class="column <?php print $panel_adjustments['rows']['5']['columns']['2']['classes'] ?> <?php print $narrow_panel_adjustments['rows']['5']['columns']['2']['classes'] ?>">
                  <?php print $content['row5_col2']; ?>
              </div>
            <?php endif; ?>
            <?php if(!empty($content['row5_col3'])): ?>
              <div class="column <?php print $panel_adjustments['rows']['5']['columns']['3']['classes'] ?> <?php print $narrow_panel_adjustments['rows']['5']['columns']['3']['classes'] ?>">
                  <?php print $content['row5_col3']; ?>
              </div>
            <?php endif; ?>
          </div>
        <?php endif; ?>

        <?php if(!empty($content['row6_col1']) || !empty($content['row6_col2']) || !empty($content['row6_col3'])): ?>
          <div class="alpha omega <?php print $panel_adjustments['rows']['6']['classes'] ?> <?php print $narrow_panel_adjustments['rows']['6']['classes'] ?>">
            <?php if(!empty($content['row6_col1'])): ?>
              <div class="column <?php print $panel_adjustments['rows']['6']['columns']['1']['classes'] ?> <?php print $narrow_panel_adjustments['rows']['6']['columns']['1']['classes'] ?>">
                  <?php print $content['row6_col1']; ?>
              </div>
            <?php endif; ?>
            <?php if(!empty($content['row6_col2'])): ?>
              <div class="column <?php print $panel_adjustments['rows']['6']['columns']['2']['classes'] ?> <?php print $narrow_panel_adjustments['rows']['6']['columns']['2']['classes'] ?>">
                  <?php print $content['row6_col2']; ?>
              </div>
            <?php endif; ?>
            <?php if(!empty($content['row6_col3'])): ?>
              <div class="column <?php print $panel_adjustments['rows']['6']['columns']['3']['classes'] ?> <?php print $narrow_panel_adjustments['rows']['6']['columns']['3']['classes'] ?>">
                  <?php print $content['row6_col3']; ?>
              </div>
            <?php endif; ?>
          </div>
        <?php endif; ?>
      </div>
      <div class="row grid-6 narrow-grid-24 narrow-no-equality omega">
        <?php if(!empty($content['sidebar'])): ?>
          <div class="column">
            <?php print $content['sidebar']; ?>
          </div>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>

<!--Subpod markup is in cr_subpods.php-->
<?php
include(dirname(__FILE__) . '/../cr_subpods.php');
?>
