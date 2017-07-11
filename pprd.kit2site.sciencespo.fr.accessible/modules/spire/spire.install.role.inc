$content['type']  = array (
  'name' => 'Spire Role des auteurs',
  'type' => 'role_auteur',
  'description' => 'Les rôles possibles des auteurs de publication',
  'title_label' => 'Trigramme',
  'body_label' => '',
  'min_word_count' => '0',
  'help' => '',
  'node_options' => 
  array (
    'status' => true,
    'promote' => false,
    'sticky' => false,
    'revision' => false,
  ),
  'language_content_type' => '0',
  'upload' => '0',
  'old_type' => 'role_auteur',
  'orig_type' => '',
  'module' => 'node',
  'custom' => '1',
  'modified' => '1',
  'locked' => '0',
  'nodewords_edit_metatags' => 1,
  'nodewords_metatags_generation_method' => '0',
  'nodewords_metatags_generation_source' => '2',
  'nodewords_use_alt_attribute' => 1,
  'nodewords_filter_modules_output' => 
  array (
    'imagebrowser' => false,
    'img_assist' => false,
  ),
  'nodewords_filter_regexp' => '',
  'links_related_types' => '0',
  'print_display' => 1,
  'print_display_comment' => 0,
  'print_display_urllist' => 1,
  'print_mail_display' => 1,
  'print_mail_display_comment' => 0,
  'print_mail_display_urllist' => 1,
  'print_pdf_display' => 1,
  'print_pdf_display_comment' => 0,
  'print_pdf_display_urllist' => 1,
  'feedapi' => 
  array (
    'enabled' => false,
    'upload_method' => 'url',
    'refresh_on_create' => 0,
    'update_existing' => 1,
    'refresh_time' => 1800,
    'items_delete' => 0,
    'parsers' => 
    array (
      'parser_common_syndication' => 
      array (
        'enabled' => false,
        'weight' => 0,
        'accept_invalid_cert' => false,
      ),
    ),
    'processors' => 
    array (
      'feedapi_node' => 
      array (
        'enabled' => false,
        'weight' => 0,
        'content_type' => 'accessibilite',
        'input_format' => 0,
        'node_date' => 'feed',
        'x_dedupe' => 0,
      ),
    ),
  ),
  'i18n_newnode_current' => 0,
  'i18n_required_node' => 0,
  'i18n_lock_node' => 0,
  'i18n_node' => 1,
  'i18nsync_nodeapi' => 
  array (
    'name' => false,
    'status' => false,
    'promote' => false,
    'moderate' => false,
    'sticky' => false,
    'revision' => false,
    'parent' => false,
    'taxonomy' => false,
    'files' => false,
    'field_role_fr' => false,
    'field_role_en' => false,
  ),
);
$content['fields']  = array (
  0 => 
  array (
    'label' => 'Role fr',
    'field_name' => 'field_role_fr',
    'type' => 'text',
    'widget_type' => 'text_textfield',
    'change' => 'Modifier les informations de base',
    'weight' => '-4',
    'rows' => 5,
    'size' => '60',
    'description' => '',
    'default_value' => 
    array (
      0 => 
      array (
        'value' => '',
        '_error_element' => 'default_value_widget][field_role_fr][0][value',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => NULL,
    'group' => false,
    'required' => 0,
    'multiple' => '0',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'op' => 'Enregistrer les paramètres du champ',
    'module' => 'text',
    'widget_module' => 'text',
    'columns' => 
    array (
      'value' => 
      array (
        'type' => 'text',
        'size' => 'big',
        'not null' => false,
        'sortable' => true,
        'views' => true,
      ),
    ),
    'display_settings' => 
    array (
      'label' => 
      array (
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      4 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      2 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      3 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      5 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
  1 => 
  array (
    'label' => 'Role en',
    'field_name' => 'field_role_en',
    'type' => 'text',
    'widget_type' => 'text_textfield',
    'change' => 'Modifier les informations de base',
    'weight' => '-3',
    'rows' => 5,
    'size' => '60',
    'description' => '',
    'default_value' => 
    array (
      0 => 
      array (
        'value' => '',
        '_error_element' => 'default_value_widget][field_role_en][0][value',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => NULL,
    'group' => false,
    'required' => 0,
    'multiple' => '0',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'op' => 'Enregistrer les paramètres du champ',
    'module' => 'text',
    'widget_module' => 'text',
    'columns' => 
    array (
      'value' => 
      array (
        'type' => 'text',
        'size' => 'big',
        'not null' => false,
        'sortable' => true,
        'views' => true,
      ),
    ),
    'display_settings' => 
    array (
      'label' => 
      array (
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      4 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      2 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      3 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      5 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
);
$content['extra']  = array (
  'title' => '-5',
  'revision_information' => '2',
  'author' => '1',
  'options' => '3',
  'menu' => '-2',
  'path' => '5',
  'print' => '4',
  'workflow' => '-1',
  'nodewords' => '0',
);


//initialisation des roles d'auteurs. A mettre dans l'install du module.
//inutilisée pour le moment
// function roles() {
// 
// 
//     $tab = array (
//         array (
//             "labels" => array (
//                 "en" => "Actor", 
//                 "fr" => "Acteur"
//             ), 
//             "major" => true, 
//             "type_id" => "act"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Adapter", 
//                 "fr" => "Adaptateur"
//             ), 
//             "type_id" => "adp"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Author of afterword, colophon, etc.", 
//                 "fr" => "Postface"
//             ), 
//             "major" => true, 
//             "type_id" => "aft"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Annotator", 
//                 "fr" => "Annotateur"
//             ), 
//             "type_id" => "ann"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Bibliographic antecedent", 
//                 "fr" => "Auteur adapté / Précédent"
//             ), 
//             "type_id" => "ant"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Applicant", 
//                 "fr" => "Demandeur candidat postulant array (doctorant ?)"
//             ), 
//             "type_id" => "app"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Author in quotations or text extracts", 
//                 "fr" => "Auteur de citation ou d'extrait de texte"
//             ), 
//             "type_id" => "aqt"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Architect", 
//                 "fr" => "Architecte"
//             ), 
//             "type_id" => "arc"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Arranger", 
//                 "fr" => "Arrangeur"
//             ), 
//             "type_id" => "arr"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Artist", 
//                 "fr" => "Artiste"
//             ), 
//             "type_id" => "art"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Assignee", 
//                 "fr" => "Nouveau détenteur du privilège"
//             ), 
//             "type_id" => "asg"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Associated name", 
//                 "fr" => "Nom associé"
//             ), 
//             "type_id" => "asn"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Attributed name", 
//                 "fr" => "Nom attribué array (auteur supposé ?)"
//             ), 
//             "type_id" => "att"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Auctioneer", 
//                 "fr" => "Commissaire-priseur"
//             ), 
//             "type_id" => "auc"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Author of dialog", 
//                 "fr" => "Dialoguiste"
//             ), 
//             "type_id" => "aud"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Author of introduction, etc.", 
//                 "fr" => "Préface"
//             ), 
//             "major" => true, 
//             "type_id" => "aui"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Author of screenplay, etc.", 
//                 "fr" => "Auteur de scénario, etc."
//             ), 
//             "type_id" => "aus"
//         ), 
//         array (
//             "default" => true, 
//             "labels" => array (
//                 "en" => "Author", 
//                 "fr" => "Auteur"
//             ), 
//             "major" => true, 
//             "type_id" => "aut"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Binding designer", 
//                 "fr" => "Dessinateur de la reliure"
//             ), 
//             "type_id" => "bdd"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Bookjacket designer", 
//                 "fr" => "Dessinateur de la jaquette"
//             ), 
//             "type_id" => "bjd"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Book designer", 
//                 "fr" => "Maquettiste de livres"
//             ), 
//             "type_id" => "bkd"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Book producer", 
//                 "fr" => "Editeur"
//             ), 
//             "type_id" => "bkp"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Binder", 
//                 "fr" => "Relieur"
//             ), 
//             "type_id" => "bnd"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Bookplate designer", 
//                 "fr" => "Dessinateur d'ex-libris"
//             ), 
//             "type_id" => "bpd"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Bookseller", 
//                 "fr" => "Libraire"
//             ), 
//             "type_id" => "bsl"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Conceptor", 
//                 "fr" => "Concepteur auteur de l'idée originale"
//             ), 
//             "type_id" => "ccp"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Choreographer", 
//                 "fr" => "Chorégraphe"
//             ), 
//             "type_id" => "chr"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Collaborator", 
//                 "fr" => "Collaborateur"
//             ), 
//             "type_id" => "clb"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Client", 
//                 "fr" => "Client"
//             ), 
//             "type_id" => "cli"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Calligrapher", 
//                 "fr" => "Calligraphe"
//             ), 
//             "type_id" => "cll"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Collotyper", 
//                 "fr" => "Phototypeur"
//             ), 
//             "type_id" => "clt"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Commentator", 
//                 "fr" => "Commentateur"
//             ), 
//             "major" => true, 
//             "type_id" => "cmm"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Composer", 
//                 "fr" => "Compositeur"
//             ), 
//             "type_id" => "cmp"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Compositor", 
//                 "fr" => "Typographe"
//             ), 
//             "type_id" => "cmt"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Conductor", 
//                 "fr" => "Chef d'orchestre"
//             ), 
//             "type_id" => "cnd"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Censor", 
//                 "fr" => "Censeur"
//             ), 
//             "type_id" => "cns"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Contestant-appellee", 
//                 "fr" => "Partie Civile devant une juridiction d'appel"
//             ), 
//             "type_id" => "coe"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Collector", 
//                 "fr" => "Collectionneur array (contrôleur ?)"
//             ), 
//             "type_id" => "col"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Compiler", 
//                 "fr" => "Compilateur"
//             ), 
//             "major" => true, 
//             "type_id" => "com"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Contestant", 
//                 "fr" => "Partie civile contestante"
//             ), 
//             "type_id" => "cos"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Contestant-appellant", 
//                 "fr" => "Partie civile contestante en appel"
//             ), 
//             "type_id" => "cot"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Copyright claimant", 
//                 "fr" => "Requérant en droits d'auteur"
//             ), 
//             "type_id" => "cpc"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Complainant-appellee", 
//                 "fr" => "Partie Plaignant devant une juridiction d'appel"
//             ), 
//             "type_id" => "cpe"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Copyright holder", 
//                 "fr" => "Détenteur de droits d'auteur"
//             ), 
//             "major" => true, 
//             "type_id" => "cph"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Complainant", 
//                 "fr" => "Partie plaignante"
//             ), 
//             "type_id" => "cpl"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Complainant-appellant", 
//                 "fr" => "Partie plaignante allant en appel"
//             ), 
//             "type_id" => "cpt"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Creator", 
//                 "fr" => "Créateur"
//             ), 
//             "type_id" => "cre"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Correspondent", 
//                 "fr" => "Correspondant array (reporter ? destinataire d'un courrier ?)"
//             ), 
//             "type_id" => "crp"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Corrector", 
//                 "fr" => "Correcteur imprimés"
//             ), 
//             "major" => true, 
//             "type_id" => "crr"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Consultant", 
//                 "fr" => "Consultant"
//             ), 
//             "type_id" => "csl"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Consultant to a project", 
//                 "fr" => "Consultant"
//             ), 
//             "type_id" => "csp"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Costume designer", 
//                 "fr" => "Costumier scénographe éclairagiste décorateur"
//             ), 
//             "type_id" => "cst"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Contributor", 
//                 "fr" => "Collaborateur"
//             ), 
//             "major" => true, 
//             "type_id" => "ctb"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Contestee-appellee", 
//                 "fr" => "Partie civile contestée en appel"
//             ), 
//             "type_id" => "cte"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Cartographer", 
//                 "fr" => "Cartographe"
//             ), 
//             "major" => true, 
//             "type_id" => "ctg"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Contractor", 
//                 "fr" => "Partie contractante"
//             ), 
//             "type_id" => "ctr"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Contestee", 
//                 "fr" => "Partie civile contestée"
//             ), 
//             "type_id" => "cts"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Contestee-appellant", 
//                 "fr" => "Partie civile contestée en appel"
//             ), 
//             "type_id" => "ctt"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Curator of an exhibition", 
//                 "fr" => "Commissaire d'une exposition"
//             ), 
//             "type_id" => "cur"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Commentator for written text", 
//                 "fr" => "Commentateur d'un texte"
//             ), 
//             "type_id" => "cwt"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Defendant", 
//                 "fr" => "Accusé"
//             ), 
//             "type_id" => "dfd"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Defendant-appellee", 
//                 "fr" => "Accusé allant en appel"
//             ), 
//             "type_id" => "dfe"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Defendant-appellant", 
//                 "fr" => "Accusé en appel"
//             ), 
//             "type_id" => "dft"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Degree grantor", 
//                 "fr" => "Institution délivrant des diplômes"
//             ), 
//             "major" => true, 
//             "type_id" => "dgg"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Dissertant", 
//                 "fr" => "Doctorant"
//             ), 
//             "type_id" => "dis"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Delineator", 
//                 "fr" => "Exécuteur de sketchs ? array (humoriste 207) array (illustrateur 440)"
//             ), 
//             "type_id" => "dln"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Dancer", 
//                 "fr" => "Danseur"
//             ), 
//             "type_id" => "dnc"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Donor", 
//                 "fr" => "Donateur"
//             ), 
//             "type_id" => "dnr"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Depositor", 
//                 "fr" => "Déposant"
//             ), 
//             "type_id" => "dpt"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Draftsman", 
//                 "fr" => "Dessinateur"
//             ), 
//             "type_id" => "drm"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Director", 
//                 "fr" => "Réalisateur ou metteur en scène"
//             ), 
//             "major" => true, 
//             "type_id" => "drt"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Designer", 
//                 "fr" => "Styliste ou maquettiste"
//             ), 
//             "type_id" => "dsr"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Distributor", 
//                 "fr" => "Distributeur"
//             ), 
//             "major" => true, 
//             "type_id" => "dst"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Dedicatee", 
//                 "fr" => "Récipiendaire d'une dédicace"
//             ), 
//             "type_id" => "dte"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Dedicator", 
//                 "fr" => "Auteur d'une dédicace"
//             ), 
//             "type_id" => "dto"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Dubious author", 
//                 "fr" => "Auteur incertain/supposé"
//             ), 
//             "major" => true, 
//             "type_id" => "dub"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Editor", 
//                 "fr" => "Editeur scientifique"
//             ), 
//             "major" => true, 
//             "type_id" => "edt"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Engraver", 
//                 "fr" => "Graveur"
//             ), 
//             "type_id" => "egr"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Electrotyper", 
//                 "fr" => "Electrotypographe"
//             ), 
//             "type_id" => "elt"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Engineer", 
//                 "fr" => "Ingénieur"
//             ), 
//             "type_id" => "eng"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Etcher", 
//                 "fr" => "Graveur d'eaux-fortes/Aquafortiste"
//             ), 
//             "type_id" => "etr"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Expert", 
//                 "fr" => "Expert"
//             ), 
//             "type_id" => "exp"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Facsimilist", 
//                 "fr" => "Editeur de copie fac-similaires"
//             ), 
//             "type_id" => "fac"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Film editor", 
//                 "fr" => "Monteur de films"
//             ), 
//             "type_id" => "flm"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Former owner", 
//                 "fr" => "Précédent propriétaire"
//             ), 
//             "type_id" => "fmo"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Funder", 
//                 "fr" => "Mécène"
//             ), 
//             "type_id" => "fnd"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Forger", 
//                 "fr" => "Faussaire"
//             ), 
//             "type_id" => "frg"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Graphic technician", 
//                 "fr" => "Technicien graphique coloriste"
//             ), 
//             "type_id" => "grt"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Honoree", 
//                 "fr" => "Personne honorée"
//             ), 
//             "type_id" => "hnr"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Host", 
//                 "fr" => "Hôte array (serveur ?)"
//             ), 
//             "type_id" => "hst"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Illustrator", 
//                 "fr" => "Illustrateur"
//             ), 
//             "major" => true, 
//             "type_id" => "ill"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Illuminator", 
//                 "fr" => "Enlumineur"
//             ), 
//             "type_id" => "ilu"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Illuminator", 
//                 "fr" => "Eclairagiste"
//             ), 
//             "type_id" => "ilu"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Inscriber", 
//                 "fr" => "Graveur"
//             ), 
//             "type_id" => "ins"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Inventor", 
//                 "fr" => "Inventeur"
//             ), 
//             "type_id" => "inv"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Instrumentalist", 
//                 "fr" => "Instrumentiste"
//             ), 
//             "type_id" => "itr"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Interviewee", 
//                 "fr" => "Personne interviewée"
//             ), 
//             "major" => true, 
//             "type_id" => "ive"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Interviewer", 
//                 "fr" => "Intervieweur"
//             ), 
//             "major" => true, 
//             "type_id" => "ivr"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Librettist", 
//                 "fr" => "Librettiste"
//             ), 
//             "type_id" => "lbt"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Libelee-appellee", 
//                 "fr" => "Plaignant en appel dans un procès en diffamation"
//             ), 
//             "type_id" => "lee"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Libelee", 
//                 "fr" => "Personne victime de diffamation"
//             ), 
//             "type_id" => "lel"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Lender", 
//                 "fr" => "Prêteur"
//             ), 
//             "type_id" => "len"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Libelee-appellant", 
//                 "fr" => "Plaignant en appel victime de diffamation"
//             ), 
//             "type_id" => "let"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Libelant-appellee", 
//                 "fr" => "Auteur de diffamation en appel"
//             ), 
//             "type_id" => "lie"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Libelant", 
//                 "fr" => "Plaignant accusé de diffamation"
//             ), 
//             "type_id" => "lil"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Libelant-appellant", 
//                 "fr" => "Plaignant accusé de diffamation en appel"
//             ), 
//             "type_id" => "lit"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Landscape architec", 
//                 "fr" => "Architecte paysagiste"
//             ), 
//             "type_id" => "lsa"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Licensee", 
//                 "fr" => "Concessionnaire d'une licence"
//             ), 
//             "type_id" => "lse"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Licensor", 
//                 "fr" => "Celui qui accorde une licence"
//             ), 
//             "type_id" => "lso"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Lithographer", 
//                 "fr" => "Lithographe"
//             ), 
//             "type_id" => "ltg"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Lyricist", 
//                 "fr" => "Parolier"
//             ), 
//             "type_id" => "lyr"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Metadata contact", 
//                 "fr" => "Contact pour les métadonnées"
//             ), 
//             "type_id" => "mdc"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Moderator", 
//                 "fr" => "Modérateur"
//             ), 
//             "type_id" => "mod"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Monitor", 
//                 "fr" => "Contrôleur"
//             ), 
//             "type_id" => "mon"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Metal-engraver", 
//                 "fr" => "Graveur sur métal"
//             ), 
//             "type_id" => "mte"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Musician", 
//                 "fr" => "Musicien"
//             ), 
//             "type_id" => "mus"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Narrator", 
//                 "fr" => "Narrateur"
//             ), 
//             "major" => true, 
//             "type_id" => "nrt"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Opponent", 
//                 "fr" => "Adversaire"
//             ), 
//             "type_id" => "opn"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Originator", 
//                 "fr" => "Créateur"
//             ), 
//             "type_id" => "org"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Organizer of meeting", 
//                 "fr" => "Organisateur d'une réunion"
//             ), 
//             "major" => true, 
//             "type_id" => "orm"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Other", 
//                 "fr" => "Autre"
//             ), 
//             "major" => true, 
//             "type_id" => "oth"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Owner", 
//                 "fr" => "Possesseur, propriétaire précédent"
//             ), 
//             "type_id" => "own"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Patron", 
//                 "fr" => "Patron ou client ?"
//             ), 
//             "type_id" => "pat"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Publishing director", 
//                 "fr" => "Directeur de publication ou de collection"
//             ), 
//             "major" => true, 
//             "type_id" => "pbd"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Publisher", 
//                 "fr" => "Editeur commercial"
//             ), 
//             "type_id" => "pbl"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Proofreader", 
//                 "fr" => "Correcteur d'épreuves"
//             ), 
//             "type_id" => "pfr"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Photographer", 
//                 "fr" => "Photographe"
//             ), 
//             "type_id" => "pht"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Platemaker", 
//                 "fr" => "Clicheur array (maquettiste ?)"
//             ), 
//             "type_id" => "plt"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Printer of plates", 
//                 "fr" => "Imprimeur de gravures"
//             ), 
//             "type_id" => "pop"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Papermaker", 
//                 "fr" => "Fabriquant de papier"
//             ), 
//             "type_id" => "ppm"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Process contact", 
//                 "fr" => "Fabrication d'épreuves par contact ??"
//             ), 
//             "type_id" => "prc"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Production personnel", 
//                 "fr" => "Equipe de production array (collaborateur ?)"
//             ), 
//             "type_id" => "prd"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Performer", 
//                 "fr" => "Exécutant"
//             ), 
//             "type_id" => "prf"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Programmer", 
//                 "fr" => "Programmeur"
//             ), 
//             "type_id" => "prg"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Producer", 
//                 "fr" => "Producteur"
//             ), 
//             "major" => true, 
//             "type_id" => "pro"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Printer", 
//                 "fr" => "Imprimeur"
//             ), 
//             "type_id" => "prt"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Patent applicant", 
//                 "fr" => "Demandeur de brevet"
//             ), 
//             "type_id" => "pta"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Plaintiff-appellee", 
//                 "fr" => "Plaignant en appel"
//             ), 
//             "type_id" => "pte"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Plaintiff", 
//                 "fr" => "Plaignant"
//             ), 
//             "type_id" => "ptf"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Patent holder", 
//                 "fr" => "Détenteur d'un brevet"
//             ), 
//             "type_id" => "pth"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Plaintiff-appellant", 
//                 "fr" => "Partie Plaignante en appel"
//             ), 
//             "type_id" => "ptt"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Rubricator", 
//                 "fr" => "Rubricateur"
//             ), 
//             "type_id" => "rbr"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Recording engineer", 
//                 "fr" => "Ingénieur du son"
//             ), 
//             "type_id" => "rce"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Recipient", 
//                 "fr" => "Destinataire"
//             ), 
//             "type_id" => "rcp"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Redactor", 
//                 "fr" => "Rédacteur"
//             ), 
//             "type_id" => "red"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Renderer", 
//                 "fr" => "Celui qui met en valeur une personne, un texte etc."
//             ), 
//             "type_id" => "ren"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Researcher", 
//                 "fr" => "Chercheur"
//             ), 
//             "type_id" => "res"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Reviewer", 
//                 "fr" => "Critique / Membre du comité de lecture"
//             ), 
//             "major" => true, 
//             "type_id" => "rev"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Respondent-appellee", 
//                 "fr" => "Partie civile en appel"
//             ), 
//             "type_id" => "rse"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Respondent", 
//                 "fr" => "Partie civile"
//             ), 
//             "type_id" => "rsp"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Respondent-appellant", 
//                 "fr" => "Partie civile allant en appel"
//             ), 
//             "type_id" => "rst"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Research team head", 
//                 "fr" => "Directeur d'équipe de recherche"
//             ), 
//             "major" => true, 
//             "type_id" => "rth"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Research team member", 
//                 "fr" => "Membre d'équipe de recherche"
//             ), 
//             "major" => true, 
//             "type_id" => "rtm"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Scientific advisor", 
//                 "fr" => "Conseiller scientifique"
//             ), 
//             "type_id" => "sad"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Scenarist", 
//                 "fr" => "Scénariste"
//             ), 
//             "major" => true, 
//             "type_id" => "sce"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Sculptor", 
//                 "fr" => "Sculpteur"
//             ), 
//             "type_id" => "scl"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Scribe", 
//                 "fr" => "Scribe"
//             ), 
//             "type_id" => "scr"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Secretary", 
//                 "fr" => "Attaché de presse, secrétaire, rapporteur"
//             ), 
//             "type_id" => "sec"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Signer", 
//                 "fr" => "Signataire"
//             ), 
//             "type_id" => "sgn"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Singer", 
//                 "fr" => "Chanteur"
//             ), 
//             "type_id" => "sng"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Speaker", 
//                 "fr" => "Conférencier"
//             ), 
//             "major" => true, 
//             "type_id" => "spk"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Sponsor", 
//                 "fr" => "Commanditaire"
//             ), 
//             "major" => true, 
//             "type_id" => "spn"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Surveyor", 
//                 "fr" => "Contrôleur ?"
//             ), 
//             "type_id" => "srv"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Standards body", 
//                 "fr" => "Agence de normalisation"
//             ), 
//             "type_id" => "stn"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Stereotyper", 
//                 "fr" => "Stéréotypeur"
//             ), 
//             "type_id" => "str"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Thesis advisor", 
//                 "fr" => "Directeur de thèse ou de mémoire"
//             ), 
//             "major" => true, 
//             "type_id" => "ths"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Transcriber", 
//                 "fr" => "Transcripteur"
//             ), 
//             "type_id" => "trc"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Translator", 
//                 "fr" => "Traducteur"
//             ), 
//             "major" => true, 
//             "type_id" => "trl"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Type designer", 
//                 "fr" => "Dessinateur de caractères d'imprimerie"
//             ), 
//             "type_id" => "tyd"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Typographer", 
//                 "fr" => "Typographe"
//             ), 
//             "type_id" => "tyg"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Vocalist", 
//                 "fr" => "Chanteur, lecteur avec ou sans accompagnement musical"
//             ), 
//             "type_id" => "voc"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Writer of accompanying material", 
//                 "fr" => "Auteur du matériel d'accompagnement"
//             ), 
//             "type_id" => "wam"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Woodcutter", 
//                 "fr" => "Graveur sur métal"
//             ), 
//             "type_id" => "wdc"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Wood-engraver", 
//                 "fr" => "Graveur sur bois"
//             ), 
//             "type_id" => "wde"
//         ), 
//         array (
//             "labels" => array (
//                 "en" => "Witness", 
//                 "fr" => "Témoin"
//             ), 
//             "type_id" => "wit"
//         )
//     ); 
// 	foreach ($tab as $o => $a) {
// 		$n = node_load(array("title" => $a["type_id"]));
// 		if($n === false) {
// 			$n = new stdClass();
// 			$n->type = 'role_auteur';
// 			$n->status = 1;
// 			$n->title = $a["type_id"];
// 			node_save($n);
// 			$n = node_load(array('title' => $a["type_id"]));
// 		}
// 		
// 		$n->uid = 1;
// 		$n->field_role_fr[0]['value'] = $a["labels"]["fr"];
// 		$n->field_role_en[0]['value'] = $a["labels"]["en"];
// 		node_save($n);
// 		
// 	}
// 
// }
