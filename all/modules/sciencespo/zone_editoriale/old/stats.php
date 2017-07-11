<?php

	$dir_name = '.';
	$dir = opendir($dir_name);
	$files = array();

	//On liste le repertoire
	while($element = readdir($dir)) {
		//On vérifie si il s'agit d'un fichier de log
		if (is_file($dir_name.'/'.$element)) {
			if (strpos($element, 'stats') !== false && strpos($element, '.log') !== false) {
				$files[] = $element;
			}
		}
	}
	
	//Si il existe des log vieux de 2 ans, on les supprimes
	foreach ($files as $f) {
		$matches = array();
		if (preg_match('/stats([0-9]{2})([0-9]{4}).log/', $f, $matches)) {
			$current_date  = mktime(0, 0, 0, date("m")  , 0, date("Y"));
			$file_date = mktime(0, 0, 0, $matches[1], 0, $matches[2] + 2);
			if ($current_date >= $file_date) {
				unlink($f);
			}
		}
	}
	
	//Opération sur les données à écrire
	$date = date('d M Y - H:i:s');
	
	$info = $_POST['info'];
	$info = explode(';', $info);
	
	$ligne = $date.' - '.$info[0].' - '.$info[1].' - '.$info[2].' - '.$info[3].' - '.$info[4];
	
	//Ecriture dans le fichier
	//On crée un fichier de log par mois
	$filename = 'stats'.date('mY').'.log';
	$file = fopen($filename, 'a+');
	fputs($file, $ligne."\r\n");
	fclose($file);

