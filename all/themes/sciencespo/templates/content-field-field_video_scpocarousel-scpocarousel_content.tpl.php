<?php if (!$field_empty) : ?>
	<div class="border"></div>
	<div class="field field-type-<?php print $field_type_css ?> field-<?php print $field_name_css ?>">
		<?php 
			foreach ($items as $delta => $item) {
				if (!$item['empty']) {
					if ($item['value'] != '') {
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

						$item['value'] = $video;
					}
				}
			}
			print $item['value'];
		?>
	</div>
<?php endif; ?>

