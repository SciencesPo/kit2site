$(document).ready(function() {

	$('fieldset.selection-gabarit select').click(function(){
		oldVal = $(this).val();
	});
	
	$('fieldset.selection-gabarit select').change(function(){
	
		curVal = $(this).val();
		curName = $(this).attr('name');
		
		changeStyle($(this));
		
		$('fieldset.selection-gabarit select').each(function(){
			//Cas ou on diminue la valeur
			if (curVal < oldVal) {
				if ($(this).val() >= curVal && $(this).val() < oldVal && $(this).attr('name') != curName) {
					newVal = parseInt($(this).val()) + 1;
					$(this).find('option[value="' + newVal + '"]').attr('selected', 'selected');
					changeStyle($(this));
				}
			//Cas ou on augmente la  valeur
			} else {
				if (($(this).val() >= curVal || $(this).val() < oldVal) && $(this).attr('name') != curName) {
					newVal = parseInt($(this).val()) + 1;
					if (newVal == 7) { newVal = 1; }
					$(this).find('option[value="' + newVal + '"]').attr('selected', 'selected');
					changeStyle($(this));
				}
			}
		});
		
		$('fieldset.selection-gabarit .description').html('L\'ordre sera pris en compte après enregistrement').css('display', 'block');
		
	});
	
	function changeStyle(elem) {
		$(elem).parents('tr').find('td').css({
			backgroundColor: '#ffffcc',
			border: '2px solid #ffcc00',
			color: '#000000'
		});
		$(elem).parents('td ').find('.modif').html('*').css('display', 'inline');
	}
	
});

