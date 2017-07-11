function tailleImage(){

	var screenW = 0, screenH = 0;
	if( typeof( window.innerWidth ) == 'number' ) {
		//Non-IE
		screenW = window.innerWidth;
		screenH = window.innerHeight;
	} else if( document.documentElement && ( document.documentElement.clientWidth || document.documentElement.clientHeight ) ) {
		//IE 6+ in 'standards compliant mode'
		screenW = document.documentElement.clientWidth;
		screenH = document.documentElement.clientHeight;
	} else if( document.body && ( document.body.clientWidth || document.body.clientHeight ) ) {
		//IE 4 compatible
		screenW = document.body.clientWidth;
		screenH = document.body.clientHeight;
	}


	if (screenH/screenW <= 3/4){
		//100% largeur
		document.getElementById("imgFond").style.width = screenW+"px";
		document.getElementById("imgFond").style.height = screenW*3/4+"px";

	}else if (screenH/screenW > 3/4){
		//100% hauteur
		document.getElementById("imgFond").style.width = screenH*4/3+"px";
		document.getElementById("imgFond").style.height = screenH+"px";
	}

	//var margeDivScroll = 75;

	//document.getElementById("scroll").style.height = (screenH*77/100-8-margeDivScroll)+"px";
	// document.getElementById("cadreblanc").style.height = screenH-20+"px";
	// document.getElementById("cadreblanc").style.width = screenW-20+"px";

}

function tailleBloc(){

	var screenW = 0, screenH = 0;
	if( typeof( window.innerWidth ) == 'number' ) {
		 //Non-IE
		screenW = window.innerWidth;
		screenH = window.innerHeight;
	} else if( document.documentElement && ( document.documentElement.clientWidth || document.documentElement.clientHeight ) ) {
		 //IE 6+ in 'standards compliant mode'
		screenW = document.documentElement.clientWidth;
		screenH = document.documentElement.clientHeight;
	} else if( document.body && ( document.body.clientWidth || document.body.clientHeight ) ) {
		//IE 4 compatible
		screenW = document.body.clientWidth;
		screenH = document.body.clientHeight;
	}


	var margeDivScroll = 75;

//	document.getElementById("Scroll").style.height = (screenH*77/100-8-margeDivScroll)+"px";

} 

//code HTML pour utiliser script

// <body onLoad="tailleImage(); tailleBloc(); initScrollLayer();" onResize="tailleImage(); tailleBloc();">
	// <div id="conteneur">
		// <div id="imgFond">
			// <img src="background/303_tesse-image3.jpg" width="100%" height="100%" onLoad="tailleImage(); tailleBloc();"/>
		// </div>
	// </div>
	// <div id="cadreblanc"></div>



	
// ou 
// jquery supersized
