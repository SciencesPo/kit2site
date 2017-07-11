<?php

/*
 * inscription à la newsletter
 * Appel soap
 */
function newsletter_inscription() {
	global $default;
   
	$sympa = variable_get('sympa', $default);
	$soapFileWsdl = $sympa['soapFileWsdl'];
	$soapServer = $sympa['soapServer'];
	$trusted_application = $sympa['trusted_application'];
	$trusted_application_password = $sympa['trusted_application_password'];
	$proxy_vars = $sympa['proxy_vars'];
	
	$action = 'review';
	$topic = 'listB';
	$service_parameters = array($topic);


	$wsdlOk =  file_get_contents($soapFileWsdl, FILE_TEXT, stream_context_create(array('http' => array('timeout' => 1))), 0, 1);
	echo "<br>  Verif presence WSDL : [";
	echo ($wsdlOk == '<' ? 'OK' : 'ERREUR');
	echo "]";
	
	$options	= array(
						'compression'=>false,
						'exceptions'=>false,
						'wsdl_cache' => 0,
						'trace'=>true,
						'uri' =>$soapServer,
						'location' => $soapServer
					);
	
	echo "<br>  APPEL SoapClient";
	$soapclient = new SoapClient(null, $options);
	
	echo "<br>  APPEL __getLastResponse";
	echo $soapclient->__getLastResponse();	// Retourne la dernière réponse SOAP
	
	echo "<br>  APPEL __getLastRequest";
	echo $soapclient->__getLastRequest ();	// Retourne la dernière requête SOAP
	
	try 
	{
		echo "<br>====================================<br>";
		echo "TRY:".$action."<br>";
		print '$service_parameters = ';
		print_r ($service_parameters);
		echo "<br>====================================<br>";
		use_soap_error_handler(true);
		$retourAppAndRun = $soapclient->authenticateRemoteAppAndRun($trusted_application,$trusted_application_password,$proxy_vars,'lists');
	}
	catch (Exception $soapFault) 
	{
		echo "Exception SOAP : [".$soapFault.", ".$retourAppAndRun."]";
	}
	if (!empty ($retourAppAndRun->faultstring))
	{
		echo "<br><br>L'opération demandée a échoué pour la raison suivante :".$retourAppAndRun->faultstring;
	}
	
	unset($soapclient); 
}




function newsletter_get_lists(){
	// global $sympa_lists;
	// global $abonnes;
	global $default;
	global $textes;
   
      //connexion SOAP
   $sympa = variable_get('sympa', $default);
   $options = array('compression'=>false, 'exceptions'=>false, 'wsdl_cache' => 0, 'trace'=>true, 'uri' => $sympa['soapServer'], 'location' => $sympa['soapServer'] );
   $soapclient = new SoapClient(null, $options);
   //listes disponibles dans SYMPA
   try {
      use_soap_error_handler(true);
      $sympaLists = $soapclient->authenticateRemoteAppAndRun($sympa['trusted_application'], $sympa['trusted_application_password'], $sympa['proxy_vars'], 'lists');
   }catch (Exception $soapFault) {
      $message = $soapFault.", ".$sympaLists;
		
      drupal_set_message($message, $type = 'error', $repeat = TRUE);
   }
      if (!empty ($sympaLists->faultstring)){
         $message = "L'opération demandée a échoué pour la raison suivante :".$sympaLists->faultstring;
         drupal_set_message($message, $type = 'error', $repeat = TRUE);
      }
		
		
      foreach($sympaLists as $li) {
			
				$list_param = explode(';', $li);
            $list_subject = explode('=', $list_param[1]);
            $list_name = explode('=', $list_param[0]);
            $list_names = explode('/', $list_name[1]);
            $name = str_replace('.', '_', $list_names[count($list_names) - 1]);
            // $name = $list_names[count($list_names) - 1];
				
				
            $sympa_lists[$name] = $list_subject[1];
            $abonnes[$name]['abonnes'] = $soapclient->authenticateRemoteAppAndRun($sympa['trusted_application'], $sympa['trusted_application_password'], $sympa['proxy_vars'], 'review', array(str_replace('_', '.', $name)));

				
            $abonnes[$name]['count'] = count($abonnes[$name]['abonnes']);
            //unset($abonnes[$name]['abonnes']);

      }
		
		
	return array($sympa_lists, $abonnes); 
   
}