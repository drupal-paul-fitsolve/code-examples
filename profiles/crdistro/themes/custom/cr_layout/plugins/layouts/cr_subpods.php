<?php
  // Only display subpods if all 3 have content (unless user has admin priviledges)
if(!empty($content['subpod1']) && !empty($content['subpod2']) && !empty($content['subpod3'])): ?>
  <div class="subpod-wrapper <?php (!empty($variables['display']->context['panel-node']->data->field_subpod_wrapper_class['und'][0]['safe_value']) ? print $variables['display']->context['panel-node']->data->field_subpod_wrapper_class['und'][0]['safe_value'] : "" ); ?>">
    <div class="container-24 clearfix">
        <div class="leader grid-24 omega-grid equal-height-container">
            <div class="column grid-8 alpha equal-height-element-two">
              <?php print $content['subpod1']; ?>
            </div>
            <div class="column grid-8 equal-height-element-two">
              <?php print $content['subpod2']; ?>
            </div>
            <div class="column grid-8 omega equal-height-element-two">
              <?php print $content['subpod3']; ?>
            </div>
        </div>
    </div>
  </div>
<?php endif; ?>
