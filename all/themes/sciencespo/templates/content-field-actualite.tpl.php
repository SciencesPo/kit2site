<?php if (!$field_empty) : ?>

	<?php if ($field['field_name'] != 'field_sous_titre_actualite' && $field['field_name'] != 'field_soustitre2_actualite') : ?>
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

