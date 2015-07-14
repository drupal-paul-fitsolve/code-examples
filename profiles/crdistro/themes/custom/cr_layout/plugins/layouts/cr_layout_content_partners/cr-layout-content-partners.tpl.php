<div class="main-content main-content-partners">
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
    <div class="content-row-wrapper content-row-5-wrapper">
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
    <div class="content-row-wrapper content-row-6-wrapper">
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

<?php if(!empty($content['row7_col1']) || !empty($content['row7_col2']) || !empty($content['row7_col3'])): ?>
    <div class="content-row-wrapper content-row-7-wrapper">
      <div class="container-24">
        <div class="<?php print $panel_adjustments['rows']['7']['classes'] ?>">
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

  <?php if(!empty($content['row8_col1']) || !empty($content['row8_col2']) || !empty($content['row8_col3'])): ?>
    <div class="content-row-wrapper content-row-8-wrapper">
      <div class="container-24">
        <div class="<?php print $panel_adjustments['rows']['8']['classes'] ?>">
          <?php if(!empty($content['row8_col1'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['8']['columns']['1']['classes'] ?>">
                <?php print $content['row8_col1']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row8_col2'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['8']['columns']['2']['classes'] ?>">
                <?php print $content['row8_col2']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row8_col3'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['8']['columns']['3']['classes'] ?>">
                <?php print $content['row8_col3']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row8_col4'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['8']['columns']['4']['classes'] ?>">
                <?php print $content['row8_col4']; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if(!empty($content['row9_col1']) || !empty($content['row9_col2']) || !empty($content['row9_col3'])): ?>
    <div class="content-row-wrapper content-row-9-wrapper">
      <div class="container-24">
        <div class="<?php print $panel_adjustments['rows']['9']['classes'] ?>">
          <?php if(!empty($content['row9_col1'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['9']['columns']['1']['classes'] ?>">
                <?php print $content['row9_col1']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row9_col2'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['9']['columns']['2']['classes'] ?>">
                <?php print $content['row9_col2']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row9_col3'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['9']['columns']['3']['classes'] ?>">
                <?php print $content['row9_col3']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row9_col4'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['9']['columns']['4']['classes'] ?>">
                <?php print $content['row9_col4']; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if(!empty($content['row10_col1']) || !empty($content['row10_col2']) || !empty($content['row10_col3'])): ?>
    <div class="content-row-wrapper content-row-10-wrapper">
      <div class="container-24">
        <div class="<?php print $panel_adjustments['rows']['10']['classes'] ?>">
          <?php if(!empty($content['row10_col1'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['10']['columns']['1']['classes'] ?>">
                <?php print $content['row10_col1']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row10_col2'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['10']['columns']['2']['classes'] ?>">
                <?php print $content['row10_col2']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row10_col3'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['10']['columns']['3']['classes'] ?>">
                <?php print $content['row10_col3']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row10_col4'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['10']['columns']['4']['classes'] ?>">
                <?php print $content['row10_col4']; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if(!empty($content['row11_col1']) || !empty($content['row11_col2']) || !empty($content['row11_col3'])): ?>
    <div class="content-row-wrapper content-row-11-wrapper">
      <div class="container-24">
        <div class="<?php print $panel_adjustments['rows']['11']['classes'] ?>">
          <?php if(!empty($content['row11_col1'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['11']['columns']['1']['classes'] ?>">
                <?php print $content['row11_col1']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row11_col2'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['11']['columns']['2']['classes'] ?>">
                <?php print $content['row11_col2']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row11_col3'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['11']['columns']['3']['classes'] ?>">
                <?php print $content['row11_col3']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row11_col4'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['11']['columns']['4']['classes'] ?>">
                <?php print $content['row11_col4']; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if(!empty($content['row12_col1']) || !empty($content['row12_col2']) || !empty($content['row12_col3'])): ?>
    <div class="content-row-wrapper content-row-12-wrapper">
      <div class="container-24">
        <div class="<?php print $panel_adjustments['rows']['12']['classes'] ?>">
          <?php if(!empty($content['row12_col1'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['12']['columns']['1']['classes'] ?>">
                <?php print $content['row12_col1']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row12_col2'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['12']['columns']['2']['classes'] ?>">
                <?php print $content['row12_col2']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row12_col3'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['12']['columns']['3']['classes'] ?>">
                <?php print $content['row12_col3']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row12_col4'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['12']['columns']['4']['classes'] ?>">
                <?php print $content['row12_col4']; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if(!empty($content['row13_col1']) || !empty($content['row13_col2']) || !empty($content['row13_col3'])): ?>
    <div class="content-row-wrapper content-row-13-wrapper">
      <div class="container-24">
        <div class="<?php print $panel_adjustments['rows']['13']['classes'] ?>">
          <?php if(!empty($content['row13_col1'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['13']['columns']['1']['classes'] ?>">
                <?php print $content['row13_col1']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row13_col2'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['13']['columns']['2']['classes'] ?>">
                <?php print $content['row13_col2']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row13_col3'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['13']['columns']['3']['classes'] ?>">
                <?php print $content['row13_col3']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row13_col4'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['13']['columns']['4']['classes'] ?>">
                <?php print $content['row13_col4']; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if(!empty($content['row14_col1']) || !empty($content['row14_col2']) || !empty($content['row14_col3'])): ?>
    <div class="content-row-wrapper content-row-14-wrapper">
      <div class="container-24">
        <div class="<?php print $panel_adjustments['rows']['14']['classes'] ?>">
          <?php if(!empty($content['row14_col1'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['14']['columns']['1']['classes'] ?>">
                <?php print $content['row14_col1']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row14_col2'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['14']['columns']['2']['classes'] ?>">
                <?php print $content['row14_col2']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row14_col3'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['14']['columns']['3']['classes'] ?>">
                <?php print $content['row14_col3']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row14_col4'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['14']['columns']['4']['classes'] ?>">
                <?php print $content['row14_col4']; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if(!empty($content['row15_col1']) || !empty($content['row15_col2']) || !empty($content['row15_col3'])): ?>
    <div class="content-row-wrapper content-row-15-wrapper">
      <div class="container-24">
        <div class="<?php print $panel_adjustments['rows']['15']['classes'] ?>">
          <?php if(!empty($content['row15_col1'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['15']['columns']['1']['classes'] ?>">
                <?php print $content['row15_col1']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row15_col2'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['15']['columns']['2']['classes'] ?>">
                <?php print $content['row15_col2']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row15_col3'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['15']['columns']['3']['classes'] ?>">
                <?php print $content['row15_col3']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row15_col4'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['15']['columns']['4']['classes'] ?>">
                <?php print $content['row15_col4']; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if(!empty($content['row16_col1']) || !empty($content['row16_col2']) || !empty($content['row16_col3'])): ?>
    <div class="content-row-wrapper content-row-16-wrapper">
      <div class="container-24">
        <div class="<?php print $panel_adjustments['rows']['16']['classes'] ?>">
          <?php if(!empty($content['row16_col1'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['16']['columns']['1']['classes'] ?>">
                <?php print $content['row16_col1']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row16_col2'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['16']['columns']['2']['classes'] ?>">
                <?php print $content['row16_col2']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row16_col3'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['16']['columns']['3']['classes'] ?>">
                <?php print $content['row16_col3']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row16_col4'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['16']['columns']['4']['classes'] ?>">
                <?php print $content['row16_col4']; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if(!empty($content['row17_col1']) || !empty($content['row17_col2']) || !empty($content['row17_col3'])): ?>
    <div class="content-row-wrapper content-row-17-wrapper">
      <div class="container-24">
        <div class="<?php print $panel_adjustments['rows']['17']['classes'] ?>">
          <?php if(!empty($content['row17_col1'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['17']['columns']['1']['classes'] ?>">
                <?php print $content['row17_col1']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row17_col2'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['17']['columns']['2']['classes'] ?>">
                <?php print $content['row17_col2']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row17_col3'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['17']['columns']['3']['classes'] ?>">
                <?php print $content['row17_col3']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row17_col4'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['17']['columns']['4']['classes'] ?>">
                <?php print $content['row17_col4']; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if(!empty($content['row18_col1']) || !empty($content['row18_col2']) || !empty($content['row18_col3'])): ?>
    <div class="content-row-wrapper content-row-18-wrapper">
      <div class="container-24">
        <div class="<?php print $panel_adjustments['rows']['18']['classes'] ?>">
          <?php if(!empty($content['row18_col1'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['18']['columns']['1']['classes'] ?>">
                <?php print $content['row18_col1']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row18_col2'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['18']['columns']['2']['classes'] ?>">
                <?php print $content['row18_col2']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row18_col3'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['18']['columns']['3']['classes'] ?>">
                <?php print $content['row18_col3']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row18_col4'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['18']['columns']['4']['classes'] ?>">
                <?php print $content['row18_col4']; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if(!empty($content['row19_col1']) || !empty($content['row19_col2']) || !empty($content['row19_col3'])): ?>
    <div class="content-row-wrapper content-row-19-wrapper">
      <div class="container-24">
        <div class="<?php print $panel_adjustments['rows']['19']['classes'] ?>">
          <?php if(!empty($content['row19_col1'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['19']['columns']['1']['classes'] ?>">
                <?php print $content['row19_col1']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row19_col2'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['19']['columns']['2']['classes'] ?>">
                <?php print $content['row19_col2']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row19_col3'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['19']['columns']['3']['classes'] ?>">
                <?php print $content['row19_col3']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row19_col4'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['19']['columns']['4']['classes'] ?>">
                <?php print $content['row19_col4']; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if(!empty($content['row20_col1']) || !empty($content['row20_col2']) || !empty($content['row20_col3'])): ?>
    <div class="content-row-wrapper content-row-20-wrapper">
      <div class="container-24">
        <div class="<?php print $panel_adjustments['rows']['20']['classes'] ?>">
          <?php if(!empty($content['row20_col1'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['20']['columns']['1']['classes'] ?>">
                <?php print $content['row20_col1']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row20_col2'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['20']['columns']['2']['classes'] ?>">
                <?php print $content['row20_col2']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row20_col3'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['20']['columns']['3']['classes'] ?>">
                <?php print $content['row20_col3']; ?>
            </div>
          <?php endif; ?>
          <?php if(!empty($content['row20_col4'])): ?>
            <div class="column <?php print $panel_adjustments['rows']['20']['columns']['4']['classes'] ?>">
                <?php print $content['row20_col4']; ?>
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
