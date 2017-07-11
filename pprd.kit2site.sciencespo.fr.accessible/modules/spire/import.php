<?php 


include('contrib/jsonrpc_client/jsonrpc_client.module');

spire_chercheur_import();
spire_publication_import();


function spire_chercheur_import() {


	//verifier que le role chercheur existe
	$roles = user_roles();
	if(!in_array('chercheur', $roles)){
		require_once(drupal_get_path('module', 'user') . "/user.admin.inc");
		$form_id = "user_admin_new_role";
		$form_values = array();
		$form_values["name"] = "chercheur";
		$form_values["op"] = t('Add role');
		$form_state = array();
		$form_state["values"] = $form_values;
		drupal_execute($form_id, $form_state);
	}
	


	$url = variable_get('spire_url', '');
	$client = new JsonRpcClient($url);
	
	
	
	$cs = variable_get('orgunits', array());
	
	foreach ($cs as $nid => $value) {
		if($value == 0){
			unset($centres[$nid]);
		}else{
			$centres[] = $nid;
		}
	}


	$params = requete_chercheurs($centres, 'tous');
	$result = $client->call('search', $params);




	//****************************************************************************************************************************
	$cenplus = variable_get('chercheurs_en_plus', array());
	if(!empty($cenplus)){
		$enplus = array_keys($cenplus);
		foreach($enplus as $i => $e) {
			$paramenplus = array(
				"kit2site",
				array (
					"filter_class" => "Person",
					"search_terms" => array('index' => "rec_id", 'operator' => '=', 'value' => $e),
				),
			);
			$resultenplus[] = $client->call('search', $paramenplus);
		}
		if($resultenplus){
			foreach($resultenplus as $i => $r){
				$result['result']['records'][] = $r['result']['records'][0];
			}
		}
	}
	//*********************************************************************************************************************
	
	// print '<pre>';
	// print '$result = ';
	// //var_dump($enplus);
	// print_r($result);
	// print '</pre>';
	// exit;
	

	$n = 0;
	foreach ($result['result']['records'] as $id => $r) {

		//creer ou updater le user
		$scpo_uid = null;
		if($r['identifiers']){
			foreach($r['identifiers'] as $i => $ident){
				if($ident['id_type'] && $ident['id_type'] == 'ldap'){
					$scpo_uid = $ident['value'];
				}
			}
		}
		
		if($scpo_uid){
			$u = user_load(array('name' => $scpo_uid));
			if(!$u) {
				$data = array();
	      $data['status'] = 1;
	      $data['name'] = $scpo_uid;
				if($r['emails']){
					foreach ($r['emails'] as $i => $value) {
						if($value['relation_type'] == 'work' && $value['visible'] == 1) {
							$data['mail'] = $value['value'];
						}
					}
				}
	      $data['init'] = $data['mail'];
	      $data['pass'] = '';
	      $data['created'] = date('U');
	      $data['access'] = 0;
				$u = user_save(null, $data);
				$roles_table = user_roles();
				$rid = array_search('chercheur', $roles_table);
	      $roles = $u->roles;
	      $roles[$rid] = 'chercheur';
	      user_save($u, array('roles' => $roles));
				
			}

		}else{
			continue;
		}


		$person = node_load(array('title' => $r['name_given'].' '.$r['name_family'], 'type' => 'spire_chercheur_type'));
		
		if($person === false) {
			$person = new stdClass();
			$person->type = 'spire_chercheur_type';
			$person->status = 1;
			$person->language = 'fr';
			$person->uid = $u->uid;
			$person->title = $r['name_given'].' '.$r['name_family'];
			node_save($person);
			$person = node_load(array('title' => $r['name_given'].' '.$r['name_family']));
		}

		$person->field_spch_nom[0]['value'] = $r['name_family'];
		$person->field_spch_prenom[0]['value'] = $r['name_given'];

		if($r['ressources']){
			foreach ($r['ressources'] as $i => $value) {
				if($value['relation_type'] == "picture"){
					$person->field_spch_ressource[0]['value'] = $value['url'];
					$person->field_spch_photo_alt[0]['value'] = $r['name_given'].' '.$r['name_family'];
				}
				if($value['relation_type'] == "cv"){
					$person->field_spch_cv[0]['value'] = $value['url'];
					$size = $value['file_size'];
					if($size > 99999) {
						$size = $size/1000;
						$size .= " Mo";
					}else if ($size > 9999){
						$size = $size/1000;
						$size .= " Ko";
					}else {
						$size .= " O";
					}
					$person->field_spch_cv_title[0]['value'] = "CV - ".$r['name_given'].' '.$r['name_family']." - ".$size.", PDF ";
				}
			}
		}
		if($r['date_birth']){
			$person->field_spch_date_birth[0]['value'] = $r['date_birth'];
		}
		if($r['gender']){
			$person->field_spch_gender[0]['value'] = $r['gender'];
		}
		if($r['skills']){
			foreach ($r['skills'] as $i => $value) {
				$fr = false;
				if($value['language'] == 'fr') {
					$fr = true;
					$person->field_spch_skills[$i]['value'] = $value['value'];
				}
				if($fr === false && $value['language'] == 'en'){
					$person->field_spch_skills[$i]['value'] = $value['value'];
				}
			}
		}
		if($r['affiliations']){
			foreach ($r['affiliations'] as $i => $value) {
				if($value['preferred'] == 1){
					$person->field_spch_statut[0]['value'] = $value['role'];
				}
					$person->field_spch_affiliations[$i]['value'] = $value['agent']['name'];
					if(!empty($value['agent']['acronym'])) {
						$person->field_spch_affiliations[$i]['value'] .= '('.$value['agent']['acronym'].')';
					}
			}
		}else{
			$person->field_spch_statut[0]['value'] = 'none';
		}
		if($r['addresses']){
			foreach ($r['addresses'] as $i => $value) {
				if($value['relation_type'] == 'work' && $value['visible'] == 1) {
					$person->field_spch_adresses[$i]['value'] = $value['street'].' - '.$value['post_code'].' '.$value['locality_city_town'].' - '.$value['country'];
				}
			}
		}
		if($r['phones']){
			foreach ($r['phones'] as $i => $value) {
				if($value['relation_type'] == 'work' && $value['preferred'] == 1 && $value['phone_type'] == 'voice' && $value['visible'] == 1) {
					$person->field_spch_tel[$i]['value'] = $value['formatted'];
				}
			}
		}
		if($r['emails']){
			foreach ($r['emails'] as $i => $value) {
				if($value['relation_type'] == 'work' && $value['visible'] == 1) {
					$person->field_spch_emails[$i]['value'] = $value['value'];
				}
			}
		}
		if($r['urls']){
			foreach ($r['urls'] as $i => $value) {
				if($value['relation_type'] == 'spire' && $value['visible'] == 1) {
					$person->field_spch_url[$i]['value'] = $value['value'];
				}
			}
		}
		if($r['language_capabilities']){
			foreach ($r['language_capabilities'] as $i => $value) {
				$person->field_spch_languages[$i]['value'] = $value['language'];
			}
		}
		if($r['biographies_short']){
			foreach ($r['biographies_short'] as $i => $value) {
				$fr = false;
				if($value['language'] == 'fr') {
					$fr = true;
					$person->teaser = $value['value'];
				}
				if($fr === false && $value['language'] == 'en'){
					$person->teaser = $value['value'];
				}
			}
		}
		if($r['biographies']){
			foreach ($r['biographies'] as $i => $value) {
				$fr = false;
				if($value['language'] == 'fr') {
					$fr = true;
					$person->body = $value['value'];
				}
				if($fr === false && $value['language'] == 'en'){
					$person->body = $value['value'];
				}
			}
		}
		if($r['titles']){
			foreach ($r['titles'] as $i => $value) {
				$fr = false;
				if($value['language'] == 'fr') {
					$fr = true;
					$person->field_spch_titles[$i]['value'] = $value['value'];
				}
				if($fr === false && $value['language'] == 'en'){
					$person->field_spch_titles[$i]['value'] = $value['value'];
				}
			}
		}
		if($r['responsabilities']){
			foreach ($r['responsabilities'] as $i => $value) {
				$fr = false;
				if($value['language'] == 'fr') {
					$fr = true;
					$person->field_spch_reponsabilities[$i]['value'] = $value['value'];
				}
				if($fr === false && $value['language'] == 'en'){
					$person->field_spch_reponsabilities[$i]['value'] = $value['value'];
				}
			}
		}
		if($r['degrees']){
			foreach ($r['degrees'] as $i => $value) {
					$degree = node_load(array('title' => $value['title']));
					if($degree === false) {
					$degree = new stdClass();
					$degree->type = 'spire_degree_type';
					$degree->status = 1;
					$degree->uid = 1;
					$degree->language = 'fr';
					$degree->title = $value['title'];
					$degree->field_spde_level[0]['value'] = $value['level'];
					$degree->field_spde_date[0]['value'] = $value['date'];
					$degree->field_spde_creator[0]['value'] = $value['creators'][0]['agent']['name'];
					foreach ($r['descriptions'] as $d => $v) {
						$fr = false;
						if($v['language'] == 'fr') {
							$fr = true;
							$degree->body = $v['value'];
						}
						if($fr === false && $v['language'] == 'en'){
							$degree->body = $v['value'];
						}
					}
					node_save($degree);
				}
				$person->field_spch_degrees[$i]['nid'] = $degree->nid;
			}
			
		}
		if($r['teachings']){
			foreach ($r['teachings'] as $i => $value) {
				$teaching = node_load(array('title' => $value['title']));
				if($teaching === false) {
					$teaching = new stdClass();
					$teaching->type = 'spire_teaching_type';
					$teaching->status = 1;
					$teaching->uid = 1;
					$teaching->language = 'fr';
					$teaching->title = $value['title'];
					$teaching->field_spte_level[0]['value'] = $value['level'];
					$teaching->field_spte_date[0]['value'] = $value['date_begin'];
					$teaching->field_spte_univ[0]['value'] = $value['creators'][0]['agent']['name'];
					$teaching->body = $value['descriptions'][0]['value'];
					node_save($teaching);
					$teaching = node_load(array('title' => $value['title']));
				}
				$person->field_spch_teachings[$i]['nid'] = $teaching->nid;
			}
			
		}
		$fr = false;
		if($r['research_coverage_keywords']['fr']){
			$fr = true;
			foreach ($r['research_coverage_keywords']['fr'] as $i => $value) {
				$person->field_spch_research_cov_keyword[$i]['value'] = $value;
			}
		}
		if($r['research_coverage_keywords']['en'] && $fr === false){
			foreach ($r['research_coverage_keywords']['en'] as $i => $value) {
				$person->field_spch_research_cov_keyword[$i]['value'] = $value;
			}
		}
		$fr = false;
		if($r['ongoing_researches']['fr']){
			$fr = true;
			foreach ($r['ongoing_researches']['fr'] as $i => $value) {
				$person->field_spch_ongoing_researches[$i]['value'] = $value;
			}
		}
		if($r['ongoing_researches']['en'] && $fr === false){
			foreach ($r['ongoing_researches']['en'] as $i => $value) {
				$person->field_spch_ongoing_researches[$i]['value'] = $value;
			}
		}
		if($r['relationships']){
			foreach ($r['relationships'] as $i => $value) {
				$relationship = node_load(array('title' => $value['agent']['name_given'].' '.$value['agent']['name_given']));
				if($relationship === false) {
					$relationship = new stdClass();
					$relationship->type = 'spire_relationship_type';
					$relationship->status = 1;
					$relationship->uid = 1;
					$relationship->language = 'fr';
					$relationship->title = $value['agent']['name_given'].' '.$value['agent']['name_given'];
					$relationship->field_spre_relation_type[0]['value'] = $value['relation_type'];
					$relationship->body = $value['descriptions'][0]['value'];
					node_save($relationship);
					$relationship = node_load(array('title' => $value['agent']['name_given'].' '.$value['agent']['name_given']));
				}
				$person->field_spch_relationships[$i]['nid'] = $relationship->nid;
			}
		}
		if($r['awards']){
			foreach ($r['awards'] as $i => $value) {
				$fr = false;
				if($value['language'] == 'fr') {
					$fr = true;
					$person->field_spch_awards[$i]['value'] = $value['value'];
				}
				if($value['language'] == 'en' && $fr === false) {
					$person->field_spch_awards[$i]['value'] = $value['value'];
				}
			}
		}
		
		$person->field_spch_rec_id[0]['value'] = $r['rec_id'];
		node_save($person);


		//traduction**************************************************************************

		$person_translation = node_load(array('tnid' => $person->nid, 'type' => 'spire_chercheur_type'));
		if($person_translation === false){
			$person_translation = node_load(array('nid' => $person->nid));
			unset($person_translation->nid);
			$person_translation->language = 'en';
			$person_translation->tnid = $person->nid;
			node_save($person_translation);
			$person_translation = node_load(array('tnid' => $person->nid));
		}
	


		if($r['awards']){
			foreach ($r['awards'] as $i => $value) {
				$en = false;
				if($value['language'] == 'en') {
					$en = true;
					$person_translation->field_spch_awards[$i]['value'] = $value['value'];
				}
				if($value['language'] == 'fr' && $en === false) {
					$person_translation->field_spch_awards[$i]['value'] = $value['value'];
				}
			}
		}
		if($r['relationships']){
			foreach ($r['relationships'] as $i => $value) {
				$relationship_translation = node_load(array('tnid' => $relationship->nid));
				if($relationship_translation === false) {
					$relationship_translation = node_load(array('nid' => $relationship->nid));
					unset($relationship_translation->nid);
					$relationship_translation->language = 'en';
					$relationship_translation->tnid = $relationship->nid;
					node_save($relationship_translation);
					$relationship_translation = node_load(array('tnid' => $relationship->nid));
				}
				$person_translation->field_spch_relationships[$i]['nid'] = $relationship_translation->nid;
			}
		}
		$en = false;
		if($r['research_coverage_keywords']['en']){
			$en = true;
			foreach ($r['research_coverage_keywords']['en'] as $i => $value) {
				$person_translation->field_spch_research_key_fr[$i]['value'] = $value;
			}
		}
		if($r['research_coverage_keywords']['fr'] && $en === false){
			foreach ($r['research_coverage_keywords']['fr'] as $i => $value) {
				$person_translation->field_spch_research_key_en[$i]['value'] = $value;
			}
		}
		$en = false;
		if($r['ongoing_researches']['en']){
			$en = true;
			foreach ($r['ongoing_researches']['en'] as $i => $value) {
				$person_translation->field_spch_ongoing_researches[$i]['value'] = $value;
			}
		}
		if($r['ongoing_researches']['fr'] && $en === false){
			foreach ($r['ongoing_researches']['fr'] as $i => $value) {
				$person_translation->field_spch_ongoing_researches[$i]['value'] = $value;
			}
		}
		if($r['degrees']){
			foreach ($r['degrees'] as $i => $value) {
				$degree_translation = node_load(array('tnid' => $degree->nid));
				if($degree_translation === false) {
					$degree_translation = node_load(array('nid' => $degree->nid));
					unset($degree_translation->nid);
					$degree_translation->language = 'en';
					$degree_translation->tnid = $degree->nid;
					foreach ($r['descriptions'] as $d => $v) {
						$en = false;
						if($v['language'] == 'en') {
							$en = true;
							$degree_translation->body = $v['value'];
						}
						if($en === false && $v['language'] == 'fr'){
							$degree_translation->body = $v['value'];
						}
					}
					node_save($degree_translation);
					$degree_translation = node_load(array('tnid' => $degree->nid));
				}
				$person_translation->field_spch_degrees[$i]['nid'] = $degree_translation->nid;
			}
			
		}
		if($r['teachings']){
			foreach ($r['teachings'] as $i => $value) {
				$teaching_translation = node_load(array('tnid' => $teaching->nid));
				if($teaching_translation === false) {
					$teaching_translation = node_load(array('nid' => $teaching->nid));
					unset($teaching_translation->nid);
					$teaching_translation->language = 'en';
					$teaching_translation->tnid = $teaching->nid;
					node_save($teaching_translation);
					$teaching_translation = node_load(array('tnid' => $teaching->nid));
				}
				$person_translation->field_spch_teachings[$i]['nid'] = $teaching_translation->nid;
			}
		}
		if($r['biographies_short']){
			foreach ($r['biographies_short'] as $i => $value) {
				$en = false;
				if($value['language'] == 'en') {
					$en = true;
					$person_translation->teaser = $value['value'];
				}
				if($en === false && $value['language'] == 'fr'){
					$person_translation->teaser = $value['value'];
				}
			}
		}
		if($r['biographies']){
			foreach ($r['biographies'] as $i => $value) {
				$en = false;
				if($value['language'] == 'en') {
					$en = true;
					$person_translation->body = $value['value'];
				}
				if($en === false && $value['language'] == 'fr'){
					$person_translation->body = $value['value'];
				}
			}
		}
		if($r['titles']){
			foreach ($r['titles'] as $i => $value) {
				$en = false;
				if($value['language'] == 'en') {
					$en = true;
					$person_translation->field_spch_titles[$i]['value'] = $value['value'];
				}
				if($en === false && $value['language'] == 'fr'){
					$person_translation->field_spch_titles[$i]['value'] = $value['value'];
				}
			}
		}
		if($r['responsabilities']){
			foreach ($r['responsabilities'] as $i => $value) {
				$en = false;
				if($value['language'] == 'en') {
					$en = true;
					$person_translation->field_spch_reponsabilities[$i]['value'] = $value['value'];
				}
				if($en === false && $value['language'] == 'fr'){
					$person_translation->field_spch_reponsabilities[$i]['value'] = $value['value'];
				}
			}
		}
		if($r['skills']){
			foreach ($r['skills'] as $i => $value) {
				$en = false;
				if($value['language'] == 'en') {
					$en = true;
					$person_translation->field_spch_skills[$i]['value'] = $value['value'];
				}
				if($en === false && $value['language'] == 'fr'){
					$person_translation->field_spch_skills[$i]['value'] = $value['value'];
				}
			}
		}
		if($r['ressources']){
			foreach ($r['ressources'] as $i => $value) {
				if($value['relation_type'] == "cv"){
					$person_translation->field_spch_cv[0]['value'] = $value['url'];
					$size = $value['file_size'];
					if($size > 99999) {
						$size = $size/1000;
						$size .= " Mb";
					}else if ($size > 9999){
						$size = $size/1000;
						$size .= " Kb";
					}else {
						$size .= " B";
					}
					$person_translation->field_spch_cv_title[0]['value'] = "CV - ".$r['name_given'].' '.$r['name_family']." - ".$size.", PDF ";
				}
			}
		}
		

		node_save($person_translation);

		$person = null;
		$person_translation = null;
		$degree = null;
		$degree_translation = null;
		$teaching = null;
		$teaching_translation = null;
		$relationship = null;
		$relationship_translation = null;
		$u = null;


	}

	return true;
}

function spire_publication_import() {

	$url = variable_get('spire_url', '');
	$client = new JsonRpcClient($url);
	
	$sql = "SELECT nid FROM node WHERE type LIKE '%s' AND language LIKE 'fr'";
	$r = db_query($sql, array('spire_chercheur_type'));
	while ($row = db_fetch_object($r)) {
		$chercheurs[] = $row->nid;  
	}

	$result = array();
	foreach ($chercheurs as $id => $nid) {
		$c = node_load(array('nid' => $nid));
		$cid = $c->field_spch_rec_id[0]['value'];
		$search_terms = array (
			"index" => "creator_id",
			"operator" => "=",
			"value" => $cid,
		);
		$params = array (
			"kit2site",
			array (
				"filter_class" => "Document",
				"result_citation_styles" => array("chicago"),
				"search_terms" => $search_terms,
			),
		);
		$result = $client->call('search', $params);

		foreach ($result['result']['records'] as $id => $pub) {
						
			$title = '';
			if($pub['title_non_sort']){
				$title = $pub['title_non_sort'];
			}
			$title .= $pub['title'];
			
			$publication = node_load(array('title' => $pub['title'], 'type' => 'spire_publication_type'));

			//nouvelle publication si elle n'existe pas déjà
			if($publication === false) {
				$publication = new stdClass();
				$publication->type = 'spire_publication_type';
				$publication->uid = 1;
				$publication->language = 'fr';
				$publication->status = 1;
				$publication->title = $title;
				node_save($publication);
				$publication = node_load(array('title' => $title, 'type' => 'spire_publication_type'));
			}

			$publication->field_sppu_rec_id[0]['value'] = $pub['rec_id'];
			$publication->field_sppu_date_issued[0]['value'] = $pub['date_issued'];
			$publication->field_sppu_rec_type[0]['value'] = $pub['rec_type'];
			$publication->body = $pub['citations']['html']['chicago'];
			
			foreach($pub['creators'] as $i => $v){
				if($v['role'] == "aut"){
					$auteur = node_load(array('title' => $v['agent']['name_given'].' '.$v['agent']['name_family'], 'type' => 'spire_chercheur_type'));
					if($auteur === false){
						$auteur = node_load(array('title' => $v['agent']['name_given'].' '.$v['agent']['name_family'], 'type' => 'spire_auteur_type'));
						if($auteur === false){
							$auteur = new stdClass();
							$auteur->type = 'spire_auteur_type';
							$auteur->uid = 1;
							$auteur->title = $v['agent']['name_given'].' '.$v['agent']['name_family'];
							$auteur->status = 1;
							node_save($auteur);
							$auteur = node_load(array('title' => $v['agent']['name_given'].' '.$v['agent']['name_family'], 'type' => 'spire_auteur_type'));
						}
					}
					$publication->field_sppu_auteurs[$i]['nid'] = $auteur->nid;
				}
			}
			if($pub['descriptions']){
				foreach($pub['descriptions'] as $i => $v){
					$fr = false;
					if($v['language'] == 'fr'){
						$publication->field_sppu_desc[0]['value'] = $v['value'];
						$fr = true;
					}
					if($fr === false && $v['language'] == 'en'){
						$publication->field_sppu_desc[0]['value'] = $v['value'];
					}
				}
			}
			node_save($publication);
			$publication = node_load(array('title' => $title, 'type' => 'spire_publication_type'));

			$publication_translation = node_load(array('tnid' => $publication->nid, 'type' => 'spire_publication_type'));
			if($publication_translation === false){
				$publication_translation = node_load(array('nid' => $publication->nid));
				unset($publication_translation->nid);
				$publication_translation->language = 'en';
				$publication_translation->tnid = $publication->nid;
				node_save($publication_translation);
				$publication_translation = node_load(array('tnid' => $publication->nid));
			}
			if($pub['descriptions']){
				foreach($pub['descriptions'] as $i => $v){
					$en = false;
					if($v['language'] == 'en'){
						$publication_translation->field_sppu_desc[0]['value'] = $v['value'];
						$en = true;
					}
					if($en === false && $v['language'] == 'fr'){
						$publication_translation->field_sppu_desc[0]['value'] = $v['value'];
					}
				}
			}
			node_save($publication_translation);

		}
	}
	$publication = null;
	$publication_translation = null;
	$auteur = null;
	return true;
	
}

function requete_chercheurs($centres, $what){
	$search_terms = array();
	$count = count($centres);

	if($what == 'tous'){
		$egal = "=";
		$op = "or";
	}
	if($what == 'sauf'){
		$egal = '<>';
		$op = "and";
	}

	if($count == 1) {
		$o = node_load(array('nid' => $centres[0]));

		$a = array('index' => "affiliation_id", 'operator' => $egal, 'value' => $o->field_spor_rec_id[0]['value']);
		$search_terms = $a;
	} else if ($count > 1) {
		if($count == 2) {
			$o = node_load(array('nid' => $centres[0]));
			$a = array('index' => "affiliation_id", 'operator' => $egal, 'value' => $o->field_spor_rec_id[0]['value']);
			$search_terms['left'] = $a;
			$search_terms['operator'] = $op;
			$o = node_load(array('nid' => $centres[1]));
			$a = array('index' => "affiliation_id", 'operator' => $egal, 'value' => $o->field_spor_rec_id[0]['value']);
			$search_terms['right'] = $a;
		}
		if($count > 2) {
			$keys = array_keys($centres);
			for ($i=0; $i < $count; $i++) {
				$o = node_load(array('nid' => $centres[$keys[$i]]));
				
				$a = array('index' => 'affiliation_id', 'operator' => $egal, 'value' => $o->field_spor_rec_id[0]['value']);
				// determiner pour quel $i on doit afficher left right etc...
				$r = "['right']";
				$s = "";
				for($j=0; $j < $i; $j++){
					$s .= $r;
				}
				if($i % 2 == 0){
					if($i == $count - 1) {//dernier item
						$sl = $s;
						eval("\$search_terms$sl = \$a;");
					} else {
						$sl = $s."['left']";
						$so = $s."['operator'] = '$op'";
						eval("\$search_terms$sl = \$a;");
						eval("\$search_terms$so;");
					}
				} else {
					if($i == $count - 1) {//dernier item
						$sr = $s;
						eval("\$search_terms$sr = \$a;");
					} else {
						$sr = $s."['left']";
						$sl = $s."['left']";
						$so = $s."['operator'] = '$op'";
						eval("\$search_terms$sl = \$a;");
						eval("\$search_terms$so;");
						eval("\$search_terms$sr = \$a;");
					}
				}
			}
		}
	}
	
	$params = array(
		"kit2site",
		array (
			"filter_class" => "Person",
			"search_terms" => $search_terms,
			"result_batch_size" => 630,
		),
	);

	return $params;
	
}


?>