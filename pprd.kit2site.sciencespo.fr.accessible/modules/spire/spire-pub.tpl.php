<?php

	global $base_url;


?>

<h1 class="title-article"><?php print t('Publications de'); ?> <?php print $name; ?></h1>
<div id="spire-list-content">

	<?php foreach($content as $i => $node){ ?>
		<div class="spire-list-content-item">
			<div class="date">
				<?php
					$d = explode('-', $node->field_sppu_date_issued[0]['value']);
					if($d[1]){
						print $d[1].'/';
					}
					if($d[0]){
						print $d[0];
					} 
				?>
			</div>
			<h2 class="title"><?php print $node->title; ?></h2>
			<div class="chicago">
				<?php print $node->body; ?>
			</div>
		</div>		
	<?php } ?>
</div>
