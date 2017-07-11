<?php

// print '<pre>';
// print '$content = ';
// //var_dump($content);
// print_r($content);
// print '</pre>';
// exit;


	global $base_url;
	$url = $base_url.'/'.$language->language.'/spire-list';
	$alpha = array("a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z");
	$pager = '<ul class="spire-pager-alpha">';
	
	for ($i=0; $i < count($alpha); $i++) {
		if($letter == $alpha[$i]){
			$pager .= '<li>'.l(strtoupper($alpha[$i]), $url.'/'.$alpha[$i], array('attributes' => array('class' => 'active'))).'</li>';
		}else{
			$pager .= '<li>'.l(strtoupper($alpha[$i]), $url.'/'.$alpha[$i]).'</li>';
		} 
	}
	$pager .= '</ul>';
	
	
?>
<h1 class="title-article"><?php print t('Spire Basic View'); ?></h1>
<?php if($letter != 'filtre') { print $pager; } ?>
<div id="spire-list-content">
	<?php if(!$content) { ?>
	<div class="spire-list-content-item">
		<h2 class="title">There are no item for this letter</h2>
	</div>		
	<?php }else{
		 
		foreach($content as $i => $node){ 
			$the = array();
			$aff = array();
			$tit = array();
			foreach($node->field_spch_affiliations as $id => $v){
				if(!empty($v['value'])) {
					$aff[] = $v['value'];
				}
			}
			foreach($node->field_spch_titles as $id => $v){
				if(!empty($v['value'])) {
					$tit[] = $v['value'];
				}
			}
			foreach($node->field_spch_research_cov_keyword as $id => $v){
				if(!empty($v['value'])) {
					$the[] = $v['value'];
				}
			}
	?>
		<div class="spire-list-content-item">
			<h2 class="title"><?php print l($node->title, $base_url.'/'.$node->path); ?></h2>
				<?php if(!empty($tit)): ?>
					<div class="titre">
						<strong><?php  print  implode(', ', $tit); ?></strong>
					</div>
				<?php endif; ?>
				<div class="email">
					<a href="mailto:<?php print $node->field_spch_emails[0]['value']; ?>"><?php print $node->field_spch_emails[0]['value']; ?></a>
				</div>
				<?php if($node->field_spch_tel[0]['value']): ?>
					<div class="tel">
					<em><?php print t('Tel:'); ?></em><?php print $node->field_spch_tel[0]['value']; ?>
					</div>
				<?php endif; ?>
				<?php if(!empty($aff)): ?>
					<div class="affiliation">
						<em><?php print t('Affiliated to:'); ?></em> <?php print implode(', ', $aff); ?>
					</div>
				<?php endif; ?>
				<?php if(!empty($the)): ?>
					<div class="themes">
						<em><?php print t('Research Themes:'); ?></em> <?php print implode(', ', $the); ?>
					</div>
				<?php endif; ?>
			<?php if($node->has_pub == true){ ?>
				<?php print l('Publications', $base_url.'/spire-publications/'.$node->nid); ?>
			<?php } ?>
		</div>
	<?php } ?>
<?php } ?>

</div>
<?php if($letter != 'filtre') { print $pager; } ?>

