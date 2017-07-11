<?php
/**
* Administration du zoning
*/
function page_accueil_admin_zoning()
{
	global $language;
	global $base_url;
	$tables = variable_get('page_accueil_tables', array());
	$page_accueil = variable_get('page_accueil', array('fr' => array('zoning' => 'zoning_1_2_3'), 'en' => array('zoning' => 'zoning_1_2_3')));
		
	$form = array();
	
	$accueil_languages = i18n_supported_languages();
	
	$form['page_accueil_language'] = array(
		'#type' => 'select',
		'#options' => $accueil_languages,
		'#default_value' => $language->language,
		'#title' => t('Language'),
		'#attributes' => array('onchange' => 'location.href="'.$base_url.'/" + this.value + "/admin/content/page_accueil"'),
	);
	
	$options = array();
	foreach ($tables as $k => $table) {
		$options[$k] = $table;
	}
	
	$form['page_accueil_zoning'] = array(
		'#type' => 'radios',
		'#title' => t('Schema'),
		'#description' => t('Choose the template you want.'),
		'#default_value' => $page_accueil[$language->language]['zoning'],
		'#prefix' => '<div id="page_accueil_zoning">',
		'#options' => $options,
		'#suffix' => '</div>',
	);
	
	$form['submit'] = array(
		'#type'  => 'submit',
		'#value' => t('Save configuration'),
	);

	//return system_settings_form($form);
	return $form;
}

/**
 * Submit hook for the settings form.
 */
function page_accueil_admin_zoning_submit($form, &$form_state)
{
	$values = $form_state['values'];

	$page_accueil = variable_get('page_accueil', array('fr' => array('zoning' => 'zoning_1_2_3'), 'en' => array('zoning' => 'zoning_1_2_3')));
	$page_accueil[$values['page_accueil_language']]['zoning'] = $values['page_accueil_zoning'];
	
	variable_set('page_accueil', $page_accueil);
	drupal_set_message(t('The configuration options have been saved.'));
}

/**
* Administration du contenu
*/
function page_accueil_admin_contenu()
{
	global $language;
	global $base_url;
	
	$tables = variable_get('page_accueil_tables', array());
	$page_accueil = variable_get('page_accueil', array('fr' => array('zoning' => 'zoning_1_2_3'), 'en' => array('zoning' => 'zoning_1_2_3')));
	$types = node_get_types($op = 'names', $node = NULL, $reset = FALSE);

	/* On construit la liste des types pour la requête */
	$types_types = node_get_types($op = 'types', $node = NULL, $reset = FALSE);
	$count = 1;
	$in = '';
	foreach ($types_types as $type) {
		if($count == count($types_types)) {
			$in .= '"'.$type->type.'"';
		} else {
			$in .= '"'.$type->type.'", ';
		}
		$count++;
	}
	
	$in = '"agenda", "page_interne", "scpocarousel", "actualite", "axe_de_recherche", "projet", "seminaire"';
	
	$q = '	SELECT n.nid, n.title, n.type, DATE_FORMAT(FROM_UNIXTIME(n.created), "%%d %%m %%Y") AS date, u.name 
			FROM {node} n 
			LEFT JOIN {users} u ON u.uid = n.uid 
			WHERE n.type IN ('.$in.')
				AND (n.language = "%s" OR n.language = "")
				AND	n.status = %d
			ORDER BY n.type, n.title';

	$r = db_query($q, array($language->language, 1));
	
	while ($row = db_fetch_array($r)) {
		$t = $types[$row['type']];
		if(isset($nodes[$t])) {
			$nodes[$t][$row['nid']] = $row['title'].' ('.$row['name'].' - '.$row['date'].')';
		}else{
			$nodes[$t] = array();
			$nodes[$t][$row['nid']] = $row['title'].' ('.$row['name'].' - '.$row['date'].')';
		}
	}

	$tds = explode('<td', $tables[$page_accueil[$language->language]['zoning']]);
	
	$form = array();

	//Tableau des champs possibles dans les contenus
	$champs = array(
		'titre' => 'titre', 
		'extrait_du_titre' => 'extrait du titre', 
		'sous-titre' => 'sous-titre', 
		'extrait_du_sous-titre' => 'extrait du sous-titre', 
		'texte' => 'texte', 
		'extrait_du_texte' => 'extrait du texte', 
		'exergue' => 'exergue', 
		'extrait_de_exergue' => 'extrait de exergue', 
		'carrousel' => 'carrousel', 
		'graphique' => 'graphique', 
		'lien_relatif' => 'lien relatif',
		//'fichier_attache' => 'fichier attaché',
	);
	
	$accueil_languages = i18n_supported_languages();
	
	$form['page_accueil_language'] = array(
		'#type' => 'select',
		'#options' => $accueil_languages,
		'#default_value' => $language->language,
		'#title' => t('Language'),
		'#attributes' => array('onchange' => 'location.href="'.$base_url.'/" + this.value + "/admin/content/page_accueil/contenu"'),
	);
	
	$zone = 1;
	foreach ($tds as $v) {
		if(strpos($v, '</td>')) {
			$td = explode('ZONE '.$zone, $v);
			$form['autre'][] = array(
				'#value' => '<td',
			);
			$form['autre'][] = array(
				'#value' => $td[0],
			);
			$form['autre'][] = array(
				'#value' => t('ZONE').' '.$zone,
			);
			
			/* Si on choisi un type de contenu "Scpocarousel", on cache les options du desous */
			$onchange = '
				if ($(this).find(\'option:selected\').parent().attr(\'label\') == \'Scpocarrousel\') {
					$(\'#edit-champs'.$zone.'\').hide()
				} else {
					$(\'#edit-champs'.$zone.'\').show()
				}
			';
			
			/* Si le type de contenu est "Scpocarousel" quand on charge la page, on cache également les options */
			$c = node_load($page_accueil[$language->language]['contenu']['zone'.$zone]['id']);
			$c->type == 'scpocarousel' ? $style = "display:none;" : $style = '';
			
			$form['autre']['zone'.$zone] = array(
				'#type' => 'select',
				'#options' => $nodes,
				'#default_value' => $page_accueil[$language->language]['contenu']['zone'.$zone]['id'],
				'#attributes' => array('onchange' => $onchange),
			);
			$form['autre']['champs'.$zone] = array(
				'#multiple' => TRUE,
				'#type' => 'select',
				'#options' => $champs,
				'#default_value' => $page_accueil[$language->language]['contenu']['zone'.$zone]['champs'],
				'#attributes' => array('style' => $style),
			);
			$form['autre'][] = array(
				'#value' => $td[1],
			);
			$zone++;
		} else {
			$form['autre'][] = array(
				'#value' => $v,
			);
		}
	}
	
	$form['submit'] = array(
		'#type'  => 'submit',
		'#value' => t('Save configuration'),
	);
	
	return $form;
}

/**
 * Submit hook for the settings form.
 */
function page_accueil_admin_contenu_submit($form, &$form_state)
{
	$values = $form_state['values'];

	$page_accueil = variable_get('page_accueil', array('fr' => array('zoning' => 'zoning_1_2_3'), 'en' => array('zoning' => 'zoning_1_2_3')));
	
	$page_accueil[$values['page_accueil_language']]['contenu'] = array();
	$zone = 1;
	foreach ($values as $key => $value) {
		if (strstr($key, 'zone')) {
			$page_accueil[$values['page_accueil_language']]['contenu'][$key]['id'] = $value;
			$page_accueil[$values['page_accueil_language']]['contenu'][$key]['champs'] = $values['champs'.$zone];
			$zone++;
		}
	}
	
	variable_set('page_accueil', $page_accueil);
	drupal_set_message(t('The configuration options have been saved.'));
}

/**
* Administration des paramètres
*/
function page_accueil_admin_settings()
{
	$forms = array();
	
	$form['page_accueil_title_words'] = array(
		'#type' => 'textfield',
		'#title' => t('Title extract'),
		'#description' => t('Choose the number of words you want to print.'),
		'#default_value' => variable_get('page_accueil_title_words', 3),
		'#size' => '5',
	);
	$form['page_accueil_subtitle_words'] = array(
		'#type' => 'textfield',
		'#title' => t('Subtitle extract'),
		'#description' => t('Choose the number of words you want to print.'),
		'#default_value' => variable_get('page_accueil_subtitle_words', 3),
		'#size' => '5',
	);
	
	return system_settings_form($form);
}

