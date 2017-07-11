<?php
// $Id: content-field.tpl.php,v 1.1.2.6 2009/09/11 09:20:37 markuspetrux Exp $

/**
 * @file content-field.tpl.php
 * Default theme implementation to display the value of a field.
 *
 * Available variables:
 * - $node: The node object.
 * - $field: The field array.
 * - $items: An array of values for each item in the field array.
 * - $teaser: Whether this is displayed as a teaser.
 * - $page: Whether this is displayed as a page.
 * - $field_name: The field name.
 * - $field_type: The field type.
 * - $field_name_css: The css-compatible field name.
 * - $field_type_css: The css-compatible field type.
 * - $label: The item label.
 * - $label_display: Position of label display, inline, above, or hidden.
 * - $field_empty: Whether the field has any valid value.
 *
 * Each $item in $items contains:
 * - 'view' - the themed view for that item
 *
 * @see template_preprocess_content_field()
 */
?>
<?php if (!$field_empty) : ?>
	<?php if ($field['type_name'] == 'page_interne' && ($field['field_name'] == 'field_image' || $field['field_name'] == 'field_video')) : ?>

		<div class="border"></div>
		<div class="field field-type-<?php print $field_type_css ?> field-<?php print $field_name_css ?>">
		    <?php 
				foreach ($items as $delta => $item) {
					if (!$item['empty']) {
						if(!empty($item['value'])) {
							//exploser le champ pour séparer video et description textuelle s'il y en a une
							$fieldContent = explode('<!--break-->', $item['value']);
							$video = $fieldContent[0];
							$transtext = $fieldContent[1];
							$video = str_replace(array('<p>', '</p>'), '', $video);
							$video = html_entity_decode($video);
							$video = str_replace('&amp;', '&', $video);
							$pp = '/(<p>.*<\/p>)/';
							preg_match($pp, $video, $pmatches);
							$title = preg_replace('/<a(.*?)>/', '', $pmatches[1]);
							$title = str_replace('</a>', '', $title);
							$title = str_replace('<p>', '', $title);
							if(!empty($title)){
								$title = 'title="'.str_replace('</p>', '', $title).'"';
							}else{
								$title = NULL;
							}



							if(!strstr($_GET['q'], 'description-textuelle')){//pas de description textuelle de la video a afficher
								$longdesc = ''; 
								if(!empty($transtext)) {
									$ppp = '/src="(.*?)"/';
									preg_match($ppp, $item['value'], $ppmatches);
									$src = $ppmatches[1];
									$srcs = explode('?', $src);
									$src = str_replace('http://', '', $srcs[0]);
									$src = str_replace('//', '', $src);
									$longdesc = ' longdesc="node/'.$node->nid.'/description-textuelle/'.$src.'"';
								}
								if($title) {
									$v = '<iframe$2 '.$longdesc.' '.$title.'>$3</iframe>';
								}else{
									$v = '<iframe$2 '.$longdesc.'>$3</iframe>';
								}
								$video = preg_replace('/(.*)<iframe(.*)>(.*)<\/iframe>(.*)/', $v, $video);
							}else{//afficher la transcription textuelle
								if(!empty($transtext)) {
									$video = preg_replace('/(.*)<iframe(.*)>(.*)<\/iframe>(.*)/', '<iframe$2 '.$title.'>$3</iframe>', $video);
					               $video .= '<span class="transcription-textuelle">'.$transtext.'</span><br />';
					               $video .= '<span class="alt-display-container">'.l(t('Close the text alternative for the video'), drupal_get_path_alias('node/'.$node->nid)).'</span><br />';
								}
							}

							$li[] = $video;
						}else{

							$image = $item['view'];
							$image = preg_replace('/height="([0-9]|px|%)*"/', '', $image);
							$image = preg_replace('/width="([0-9]|px|%)*"/', '', $image);	
							$li[] = $image;
						}
					}
				}
				print theme_carousel('#node-'.$node->nid.' .field-field-image', $li, array('ratio' => true));
			?>
		</div>

	<?php elseif($field['field_name'] != 'field_image' || $field['field_name'] != 'field_video'): ?>

	
	<?php if ($field['field_name'] != 'field_sous_titre') : ?>
		<div class="border"></div>
	<?php endif;?>
	<div class="field field-type-<?php print $field_type_css ?> field-<?php print $field_name_css ?>">
	  <?php if ($label_display == 'above') : ?>
	    <div class="field-label"><?php print t($label) ?>:&nbsp;</div>
	  <?php endif;?>

	  <div class="field-items">
	    <?php $count = 1;
	    foreach ($items as $delta => $item) :
	      if (!$item['empty']) : ?>
	        <div class="field-item <?php print ($count % 2 ? 'odd' : 'even') ?>">
	          <?php if ($label_display == 'inline') { ?>
	            <div class="field-label-inline<?php print($delta ? '' : '-first')?>">
	              <?php print t($label) ?>:&nbsp;</div>
	          <?php } ?>
	          <?php print $item['view'] ?>
	        </div>
	      <?php $count++;
	      endif;
	    endforeach;?>
	  </div>
	</div>
	<?php endif; ?>

<?php endif; ?>
