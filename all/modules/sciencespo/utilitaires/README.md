UTILITAIRES
===========
Module de connexion à l'annuaire de Sciences Po pour Drupal 7
-------------------------------------------------------------

*Auteur : philippe Hubert philippe.hubert@sciencespo.fr*

###But :
Le module permet la connexion à l'annuaire ldap V2 de Sciences Po, avec ou sans connexion au CAS.


###Principe :
Un hook form_alter intercepte le formulaire `user_login`. Si le tableau `$_SESSION['phpcas']` n'est pas créé, le module renvoie le formulaire de connexion au CAS. Si le CAS n'est pas utilisé, le module renvoie le formulaire de login de Drupal.
Dans les deux cas, il récupère l'uid de l'utilisateur, puis cherche les rôles qui lui sont assignés pour l'appli concernée.
Enfin, si l'utilisateur est autorisé, il lui assigne les rôles pour l'appli et créé la variable globale `$user`.

###Paramètres : 
Les paramètres sont passés via un formulaire à l'adresse admin/settings/utilitaires

Les paramètres sont : 

* 	cas\_oui -> le CAS est-il utilisé ?
*	cas\_server -> url du CAS
*	cas\_port -> port du CAS
*	cas\_context -> namespace (ou context) du CAS
*	ldap -> url du serveur ldap
*	ldap\_app -> nom de l'application pour l'attirbution des rôles
*	ldap\_mail -> attribut email
*	ldap\_userName -> attribut nom d'utilisateur
*	ldap\_roles -> mapping des rôles ldap:appli
*	ldap\_consultator -> dn consultator  (compte habilité à se connecter au ldap)
*	ldap\_consultator_pwd -> mot de passe consultator

###Installation :
1. Désactiver tous les modules de connexion, comme ldap, cas, cas server, ldap authentication, etc...
2. Vider les caches
3. Activer le modules "utilitaires"
4. Renseigner les paramètres CAS et LDAP à l'adresse /admin/settings/utilitaires ou en utilisant le menu "Configuration du site -> Réglages CAS & LDAP"

