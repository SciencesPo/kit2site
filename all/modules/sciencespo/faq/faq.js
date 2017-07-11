jQuery(document).ready(function() {
	$('.faq-reponse').hide();
	
	$('.faq-question').click(
		function(){
			$(this).next().slideToggle();
		}
	);
});

