$(document).ready(function(){
   //les trois blocs sont repliés en javascript. Si le javascript est désactivé, il sont ouverts pour accessibilité.
   $('#block-topboxes-langues .hiddenlist').removeClass("ouvert").addClass("ferme");
   $('#block-topboxes-SPlogin .hiddenlist').removeClass("ouvert").addClass("ferme");
   $('#block-topboxes-custom .hiddenlist').removeClass("ouvert").addClass("ferme");
   
   
//langues
	$('#block-topboxes-langues ul.mainlist').mouseover(function(){
		$('#block-topboxes-langues .hiddenlist').removeClass("ferme").addClass("ouvert");
		$('#langues_fleche').html('<img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/icon_flechebas.png" alt=""/>');
		$('#block-topboxes-langues .first').css('border-bottom', '1px dotted black');
 	  
		
	});
	$('#block-topboxes-langues ul.mainlist').mouseout(function(){
		$('#block-topboxes-langues .hiddenlist').removeClass("ouvert").addClass("ferme");
		$('#langues_fleche').html('<img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/icon_flechedroite.png" alt=""/>');
		$('#block-topboxes-langues .first').css('border-bottom', '0 none transparent');
   	
	});
	$('#block-topboxes-langues li.first a').focus(function(){
		$('#block-topboxes-langues .hiddenlist').removeClass("ferme").addClass("ouvert");
		$('#langues_fleche').html('<img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/icon_flechebas.png" alt=""/>');
		$('#block-topboxes-langues .first').css('border-bottom', '1px dotted black');
 	  
	});
	$('#block-topboxes-langues li.first a').blur(function(){
		$('#block-topboxes-langues .hiddenlist').removeClass("ouvert").addClass("ferme");
		$('#langues_fleche').html('<img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/icon_flechedroite.png" alt=""/>');
		$('#block-topboxes-langues .first').css('border-bottom', '0 none transparent');
   	
	});
	$('#block-topboxes-langues .hiddenlist a').focus(function(){
		$('#block-topboxes-langues .hiddenlist').removeClass("ferme").addClass("ouvert");
		$('#langues_fleche').html('<img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/icon_flechebas.png" alt=""/>');
		$('#block-topboxes-langues .first').css('border-bottom', '1px dotted black');
 	  
	});
	$('#block-topboxes-langues .hiddenlist a').blur(function(){
		$('#block-topboxes-langues .hiddenlist').removeClass("ouvert").addClass("ferme");
		$('#langues_fleche').html('<img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/icon_flechedroite.png" alt=""/>');
		$('#block-topboxes-langues .first').css('border-bottom', '0 none transparent');
   	
	});
//SPlogin
   $('#block-topboxes-SPlogin ul.mainlist').mouseover(function(){
   	$('#block-topboxes-SPlogin .hiddenlist').removeClass("ferme").addClass("ouvert");
   	$('#SPlogin_fleche').html('<img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/icon_flechebas.png" alt=""/>');
		$('#block-topboxes-SPlogin .first').css('border-bottom', '1px dotted black');
 	  
   });
   $('#block-topboxes-SPlogin ul.mainlist').mouseout(function(){
   	$('#block-topboxes-SPlogin .hiddenlist').removeClass("ouvert").addClass("ferme");
   	$('#SPlogin_fleche').html('<img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/icon_flechedroite.png" alt=""/>');
		$('#block-topboxes-SPlogin .first').css('border-bottom', '0 none transparent');
   	
   });
   $('#block-topboxes-SPlogin li.first a').focus(function(){
   	$('#block-topboxes-SPlogin .hiddenlist').removeClass("ferme").addClass("ouvert");
   	$('#SPlogin_fleche').html('<img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/icon_flechebas.png" alt=""/>');
		$('#block-topboxes-SPlogin .first').css('border-bottom', '1px dotted black');
 	  
   });
   $('#block-topboxes-SPlogin li.first a').blur(function(){
   	$('#block-topboxes-SPlogin .hiddenlist').removeClass("ouvert").addClass("ferme");
   	$('#SPlogin_fleche').html('<img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/icon_flechedroite.png" alt=""/>');
		$('#block-topboxes-SPlogin .first').css('border-bottom', '0 none transparent');
   	
   });
   $('#block-topboxes-SPlogin .hiddenlist a').focus(function(){
   	$('#block-topboxes-SPlogin .hiddenlist').removeClass("ferme").addClass("ouvert");
   	$('#SPlogin_fleche').html('<img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/icon_flechebas.png" alt=""/>');
		$('#block-topboxes-SPlogin .first').css('border-bottom', '1px dotted black');
 	  
   });
   $('#block-topboxes-SPlogin .hiddenlist a').blur(function(){
   	$('#block-topboxes-SPlogin .hiddenlist').removeClass("ouvert").addClass("ferme");
   	$('#SPlogin_fleche').html('<img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/icon_flechedroite.png" alt=""/>');
		$('#block-topboxes-SPlogin .first').css('border-bottom', '0 none transparent');
   	
   });
//custom
   $('#block-topboxes-custom ul.mainlist').mouseover(function(){
   	$('#block-topboxes-custom .hiddenlist').removeClass("ferme").addClass("ouvert");
   	$('#custom_fleche').html('<img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/icon_flechebas.png" alt=""/>');
		$('#block-topboxes-custom .first').css('border-bottom', '1px dotted black');
 	  
   });
   $('#block-topboxes-custom ul.mainlist').mouseout(function(){
   	$('#block-topboxes-custom .hiddenlist').removeClass("ouvert").addClass("ferme");
   	$('#custom_fleche').html('<img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/icon_flechedroite.png" alt=""/>');
		$('#block-topboxes-custom .first').css('border-bottom', '0 none transparent');
   	
   });
   $('#block-topboxes-custom li.first a').focus(function(){
   	$('#block-topboxes-custom .hiddenlist').removeClass("ferme").addClass("ouvert");
   	$('#custom_fleche').html('<img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/icon_flechebas.png" alt=""/>');
		$('#block-topboxes-custom .first').css('border-bottom', '1px dotted black');
 	  
   });
   $('#block-topboxes-custom li.first a').blur(function(){
   	$('#block-topboxes-custom .hiddenlist').removeClass("ouvert").addClass("ferme");
   	$('#custom_fleche').html('<img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/icon_flechedroite.png" alt=""/>');
		$('#block-topboxes-custom .first').css('border-bottom', '0 none transparent');
   	
   });
   $('#block-topboxes-custom .hiddenlist a').focus(function(){
   	$('#block-topboxes-custom .hiddenlist').removeClass("ferme").addClass("ouvert");
   	$('#custom_fleche').html('<img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/icon_flechebas.png" alt=""/>');
		$('#block-topboxes-custom .first').css('border-bottom', '1px dotted black');
 	  
   });
   $('#block-topboxes-custom .hiddenlist a').blur(function(){
   	$('#block-topboxes-custom .hiddenlist').removeClass("ouvert").addClass("ferme");
   	$('#custom_fleche').html('<img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/icon_flechedroite.png" alt=""/>');
		$('#block-topboxes-custom .first').css('border-bottom', '0 none transparent');
   	
   });
});
