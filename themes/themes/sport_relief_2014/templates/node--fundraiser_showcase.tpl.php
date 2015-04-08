<?php 
//print render($content); dpm($content);
$nextPost = pn_node($node, 'n');  
$prevPost = pn_node($node, 'p');   
//dpm($content);
?>
<article class="node node-fundraiser-showcase clearfix">
 <div class="frsc-wrapper">	
    <div class="frsc-prev-next">
        <div class="frsc-prev first"><?php if ($nextPost != NULL) {  print $nextPost; } ?></div>
        <div class="frsc-next last"><?php if ($prevPost != NULL) {  print $prevPost; } ?></div> 
    </div>  
    <div class="frsc-prev-next back-to-page">
        <div class="frsc-prev first"><?php print l('Back to fundraiser showcase', 'fundraise/fundraiser-showcase'); ?></div>
    </div>  
  <div class="frsc-content">
    <div class="top">  

    </div>
    
  	<div class="left">
    <div class="fr-title"><?php print render($content['title_field']); ?></div>
    <div class="fr-info">
      <div class="fr-total"><div class="field-name-field-total"><div class="field-item"> 
          <?php if(isset($content['field_fundrasier_showcase_images'])) { print count($content['field_fundrasier_showcase_images']['#items']). ' photos'; } ?>
          <?php if(isset($content['field_video_upload'])) { print '1 video'; } ?>
        </div></div></div>
      <div class="fr-town"><?php print render($content['field_town']); ?></div>
    </div>
    <div class="fr-body"><div class="fr-body-inner"><?php print render($content['body']); ?></div></div>
    </div>
    <div class="right">
    <?php if(isset($content['field_video_upload']) && !empty($content['field_video_upload'][0]['#video_id'])) { print render($content['field_video_upload']); } ?>
    <?php if(isset($content['field_fundrasier_showcase_images'])) { print render($content['field_fundrasier_showcase_images']); } ?>
    </div>
  

  </div>
 </div>
</article>
