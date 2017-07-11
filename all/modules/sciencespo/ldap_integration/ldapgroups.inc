<?php
// $Id: ldapgroups.inc,v 1.2 2009/08/25 13:53:20 miglius Exp $

/**
 * @file
 * ldapgroups include file.
 */

//////////////////////////////////////////////////////////////////////////////
// hook_user() functions

/**
 * Implements hook_user() login operation.
 */
//DSIEED_MODIF:DEBUT
// avant -> function ldapgroups_user_login(&$account) {
// apres -> function ldapgroups_user_login($account) {
//DSIEED_MODIF:FIN

function ldapgroups_user_login($account) {


// echo "Debut de function ldapgroups_user_login avec account=";
// print_r ($account);

  $authmap = user_get_authmaps($account->name);
  if (!isset($authmap['ldapauth'])) {
    // This user is not authenticated via lapauth.
    return;
  }

  // Setup the global $_ldapgroups_ldap object.
  if (!_ldapgroups_ldap_init($account))
    return;

  // First, we figure out the appropriate groups.
  $groups = _ldapgroups_detect_groups($account);

// echo "verif si groups appropries ,groups=";
// print_r ($groups);
// exit;




  // Apply groups restrictions.
  if (count($groups_allow = _ldapgroups_ldap_info($account, 'ldapgroups_groups')) > 0 && count(array_intersect($groups, $groups_allow)) == 0) {
//echo "user_load(0)==> return !";
    $account = user_load(0);
    return;
  }
//echo "groups_allow = _ldapgroups_ldap_info(account, 'ldapgroups_groups')) =";
//print_r ($groups_allow);
//groups_allow:
//(
//    [0] => cn=ssm-EXPERTDRUPAL,ou=roles,ou=Applications,o=sciences-po,c=fr
//)

  // Then, we take every mapped role from the user, later below
  // we'll grant back those deserved.
  $account->ldap_drupal_roles = isset($account->ldap_drupal_roles) ? $account->ldap_drupal_roles : array();

  foreach ($account->ldap_drupal_roles as $role) {
    _ldapgroups_deny_role($account, $role);
  }

  // Are there LDAP groups for the user?
  if ($groups === FALSE)
  {
//echo "if (groups === FALSE)==>return !";
    return TRUE;
  }

  // Next, we apply site-specific rules.
  $groups = _ldapgroups_filter($account, $groups);

	// DSIEED_MODIF : DEBUT, ADD
	if (sizeof($groups)==0)
	{
		$groups[]="sansrole";
	}
	// DSIEED_MODIF : FIN
  // At this point, the roles are in the full DN format.
  $roles	= array();
  if (!empty($groups)) {
    $ldapgroups_mappings = _ldapgroups_ldap_info($account, 'ldapgroups_mappings');
//echo "ldapgroups_mappings = _ldapgroups_ldap_info(account, 'ldapgroups_mappings') = ";
//print_r($ldapgroups_mappings);
    foreach ($groups as $group) {
      $role = _ldapgroups_mapping($account, $group);
//echo "role = _ldapgroups_mapping($account, $group) = ";
//print_r($role);
      _ldapgroups_create_role($role);
      _ldapgroups_grant_role($account, $role);
      $roles[] = $role;
    }
  }
// DSIEED_MODIF : DEBUT, ADD
if ( (sizeof($roles)==0) && ($groups[0]="sansrole") )
{
	$roles[]="sansrole";
}
if(sizeof($roles) > 1 && in_array('sansrole', $roles)) {
	$roles = array_slice($roles, array_search('sansrole', $roles));
} 

// DSIEED_MODIF : FIN
  // Store roles in the user object so we know which ones
  // were granted here.
  user_save($account, array('ldap_drupal_roles' => $roles));
}

//////////////////////////////////////////////////////////////////////////////
// Auxiliary functions

/**
 * Detect user groups from the LDAP.
 *
 * @param $user
 *   A user object.
 *
 * @return
 *   An array of user groups.
 */
function _ldapgroups_detect_groups($user) {
  global $_ldapgroups_ldap;
// echo "\n_ldapgroups_detect_groups (user): ";
// print_r($user);
// exit;
  // Nothing to do if the user is not LDAP authentified
  // or there are no groups configured.
  if (!(_ldapgroups_ldap_info($user, 'ldapgroups_in_dn') || _ldapgroups_ldap_info($user, 'ldapgroups_in_attr') || _ldapgroups_ldap_info($user, 'ldapgroups_as_entries')))
{
// echo "\n retour FALSE sur _ldapgroups_detect_groups\n";
    return FALSE;
}
  // First try to connect with the stored user's DN and password.
  // If unsuccessful, connect with the BINDDN and BINDPW stored in the database for this config.
  $dn = isset($_SESSION['ldap_login']['dn']) ? $_SESSION['ldap_login']['dn'] : '';
  $pass = isset($_SESSION['ldap_login']['pass']) ? $_SESSION['ldap_login']['pass'] : '';

  // If I try to connect using a blank dn and pass, I dont get an error until ldap_read,
  // so I just check to see if they would be blank, based on ldap_forget_passwords, and
  // make it read from the database.
  if (LDAPAUTH_FORGET_PASSWORDS || !$_ldapgroups_ldap->connect($dn, $pass)) {
    $row2 = db_fetch_object(db_query("SELECT binddn, bindpw FROM {ldapauth} WHERE sid = %d", $_ldapgroups_ldap->getOption('sid')));
    $dn = $row2->binddn;
    $pass = $row2->bindpw;
    if (!$_ldapgroups_ldap->connect($dn, $pass)) {
      watchdog('ldapgroups', "User login: user %name data could not be read in the LDAP directory", array('%name' => $user->name), WATCHDOG_WARNING);
      return FALSE;
    }
  }

  // Strategy 1: group extracted from user's DN.
  $dn_groups = array();
  if (_ldapgroups_ldap_info($user, 'ldapgroups_in_dn')) {
// echo "\n Strategy 1:";
    $pairs = explode(',', $user->ldap_dn);
    foreach ($pairs as $p) {
      $pair = explode('=', $p);
      if (drupal_strtolower(trim($pair[0])) == drupal_strtolower(_ldapgroups_ldap_info($user, 'ldapgroups_dn_attribute')))
        $dn_groups[] = trim($pair[1]);
    }
  }

  // Strategy 2: groups in user attributes.
  $attrib_groups = array();
  if (_ldapgroups_ldap_info($user, 'ldapgroups_in_attr')) {
// echo "\n Strategy 2:";
    foreach (_ldapgroups_ldap_info($user, 'ldapgroups_attr') as $attribute)
      $attrib_groups = array_merge($attrib_groups, $_ldapgroups_ldap->retrieveMultiAttribute($user->ldap_dn, $attribute));
  }

  // Strategy 3: groups as entries.
  $entries_groups = array();
// Note:  ldapgroups_entries_attribute contient uniqueMember
  $ldapgroups_entries_attribute = _ldapgroups_ldap_info($user, 'ldapgroups_entries_attribute');
// print_r ($ldapgroups_entries_attribute);
  if (_ldapgroups_ldap_info($user, 'ldapgroups_as_entries')) {
//echo "\n Strategy 2:";
//DSIEED_MODIF : DEBUT, ADD, commentaire
// Pour le kit2site on passe obligatoirement par Strategy 3, quand l'utilisateur est associe a un role on obtient un equivalent de ceci :
// ENTRIES=>Array
//(
//    [count] => 1
//    [0] => Array
//        (
//            [uniquemember] => Array
//                (
//                    [count] => 6
//                    [0] => uid=peplum.admin,ou=Users,o=sciences-po,c=fr
//                    [1] => uid=malika.sadaoui,ou=Users,o=sciences-po,c=fr
//                    [2] => uid=eve.demaziere,ou=Users,o=sciences-po,c=fr
//                    [3] => uid=djeff.regottaz,ou=Users,o=sciences-po,c=fr
//                    [4] => uid=frederic.buchwalter,ou=Users,o=sciences-po,c=fr
//                    [5] => uid=julien.rault,ou=Users,o=sciences-po,c=fr
//                )
//
//            [0] => uniquemember
//            [count] => 1
//            [dn] => cn=ssm-ADMIN,ou=roles,ou=Applications,o=sciences-po,c=fr
//        )
//
//)
// Sinon c'est vide !
//DSIEED_MODIF:FIN
    foreach (_ldapgroups_ldap_info($user, 'ldapgroups_entries') as $branch) {
      $entries = $_ldapgroups_ldap->search($branch, $ldapgroups_entries_attribute .'='. $user->ldap_dn, array($ldapgroups_entries_attribute));

      if (empty($entries) || $entries['count'] == 0)
        $entries = $_ldapgroups_ldap->search($branch, $ldapgroups_entries_attribute .'='. $user->name, array($ldapgroups_entries_attribute));
// echo "\n ENTRIES=>";
// print_r ($entries);
      foreach ($entries as $entry) {
        if (isset($entry['dn']))
          $entries_groups[] = $entry['dn'];
      }
    }
  }

// echo "\n LABEL 10 MLE-";
// echo "\n dn_groups:";
// print_r($dn_groups);
// echo "\n attrib_groups:";
// print_r($attrib_groups);
// echo "\n entries_groups:";
// print_r($entries_groups);
// exit;
// 
//DSIEED_MODIF : DEBUT, ADD
// Pour le kit2site on a $dn_groups et $attrib_groups vide et $entries_groups egal a :
//Array
//(
//    [0] => cn=ssm-EXPERTDRUPAL,ou=roles,ou=Applications,o=sciences-po,c=fr
//)
// Il faut récupérer le nom de l'application (ssm par exemple) et créé de toute piece le role SANSROLE pour l'utilisateur connecté

if ( (sizeof($dn_groups)==0) && (sizeof($attrib_groups)==0) && (sizeof($entries_groups)==0) )
{
	$ldapgroups_tempo = _ldapgroups_ldap_info($user, 'ldapgroups_mappings');
	$cle_cn = array_keys($ldapgroups_tempo);
	$mastring = $cle_cn[0];
	$nomCourtAppli = substr ($mastring, 3, strpos($mastring, '-')-3 );
  $entries_groups[] = "cn=".$nomCourtAppli."-SANSROLE,ou=roles,ou=Applications,o=sciences-po,c=fr";
}
//DSIEED_MODIF:FIN
  $_ldapgroups_ldap->disconnect();
  return array_unique(array_merge($dn_groups, $attrib_groups, $entries_groups));
}

/**
 * Grant a user with a role.
 *
 * @param $user
 *   A user object.
 * @param $rolename
 *   A name of the role.
 *
 * @return
 */
function _ldapgroups_grant_role($user, $rolename) {
  $result = db_query("SELECT * FROM {role} WHERE name = '%s'", $rolename);
  if ($row = db_fetch_object($result)) {
    $result = db_query("SELECT * FROM {users_roles} WHERE uid = %d AND rid = %d", $user->uid, $row->rid);
    if (!db_fetch_object($result)) {
      db_query("INSERT INTO {users_roles} (uid, rid) VALUES (%d, %d)", $user->uid, $row->rid);
    }
  }
}

/**
 * Deny a user with a role.
 *
 * @param $user
 *   A user object.
 * @param $rolename
 *   A name of the role.
 *
 * @return
 */
function _ldapgroups_deny_role($user, $rolename) {
  $result = db_query("SELECT * FROM {role} WHERE name = '%s'", $rolename);
  if ($row = db_fetch_object($result)) {
    $result = db_query("SELECT * FROM {users_roles} WHERE uid = %d AND rid = %d", $user->uid, $row->rid);
    if (db_fetch_object($result)) {
      db_query("DELETE FROM {users_roles} WHERE uid = %d AND rid = %d", $user->uid, $row->rid);
    }
  }
}

/**
 * Create a new role.
 *
 * @param $rolename
 *   A name of the role.
 *
 * @return
 */
function _ldapgroups_create_role($rolename) {
  $result = db_query("SELECT * FROM {role} WHERE name = '%s'", $rolename);
  if (!($row = db_fetch_object($result)))
    db_query("INSERT INTO {role} (name) VALUES ('%s')", $rolename);
}

/**
 * Filters groups only to a explicitely defined groups.
 *
 * @param $groups
 *   An array of the LDAP groups.
 *
 * @return
 *   An array of the filtered groups.
 */
function _ldapgroups_filter($account, $groups) {
  if (_ldapgroups_ldap_info($account, 'ldapgroups_mappings_filter') && count(_ldapgroups_ldap_info($account, 'ldapgroups_mappings') > 0)) {
    $groups_new = array();
    foreach ($groups as $group) {
      foreach (_ldapgroups_ldap_info($account, 'ldapgroups_mappings') as $group_approved => $role) {
        if (strcasecmp($group_approved, $group) == 0)
          $groups_new[] = $role;
      }
    }
    $groups = $groups_new;
  }

  if ($code = _ldapgroups_ldap_info($account, 'ldapgroups_filter_php'))
    $groups = drupal_eval($code);

  return $groups;
}

/**
 * Maps LDAP group name to a Drupal role.
 *
 * @param $user
 *   A user object.
 * @param $group
 *   A LDAP group name.
 *
 * @return
 *   An Drupal role.
 */
function _ldapgroups_mapping($user, $group) {
  $ldapgroups_mappings = _ldapgroups_ldap_info($user, 'ldapgroups_mappings');
  if (isset($ldapgroups_mappings[$group]))
    return $ldapgroups_mappings[$group];
  else if (preg_match('/^[^=]+=([^,]+),.*$/', $group, $matches))
    return $matches[1];
  else
    return $group;
}

/**
 * Initiates the LDAPInterfase class.
 *
 * @param $sid
 *   A server ID or user object.
 *
 * @return
 */
function _ldapgroups_ldap_init($sid) {
  global $_ldapgroups_ldap;
  
  // //debug start *************************************
  // 	print "<pre>\$_ldapgroups_ldap =";
  // 	// var_dump($_ldapgroups_ldap);
  // 	print_r($_ldapgroups_ldap);
  // 	print '</pre>';
  // 	exit;
  // //debug end ***************************************

  if (!($sid = is_object($sid) ? (isset($sid->ldap_config) ? $sid->ldap_config : NULL) : $sid))
    return;

  static $servers = array();
  if (!isset($servers[$sid]))
    $servers[$sid] = db_fetch_object(db_query("SELECT * FROM {ldapauth} WHERE status = 1 AND sid = %d", $sid));


  if ($servers[$sid]) {
    $_ldapgroups_ldap = new LDAPInterface();
    $_ldapgroups_ldap->setOption('sid', $sid);
    $_ldapgroups_ldap->setOption('name', $servers[$sid]->name);
    $_ldapgroups_ldap->setOption('server', $servers[$sid]->server);
    $_ldapgroups_ldap->setOption('port', $servers[$sid]->port);
    $_ldapgroups_ldap->setOption('tls', $servers[$sid]->tls);
    $_ldapgroups_ldap->setOption('encrypted', $servers[$sid]->encrypted);
    $_ldapgroups_ldap->setOption('basedn', $servers[$sid]->basedn);
    $_ldapgroups_ldap->setOption('user_attr', $servers[$sid]->user_attr);
    return $_ldapgroups_ldap;
  }
}
/**
 * Retrieve the saved ldapgroups saved setting.
 *
 * @param $sid
 *   A server ID or user object.
 * @param $req
 *   An attribute name.
 *
 * @return
 *   The attribute value.
 */
function _ldapgroups_ldap_info($sid, $req) {
  if (!($sid = is_object($sid) ? (isset($sid->ldap_config) ? $sid->ldap_config : NULL) : $sid))
    return;

  static $servers = array();
  if (!isset($servers[$sid]))
    $servers[$sid] = db_fetch_object(db_query("SELECT * FROM {ldapauth} WHERE sid = %d", $sid));
//echo "\n_ldapgroups_ldap_info (".$sid.",".$req.") avec servers=";
//print_r($servers);
  switch ($req) {
    case 'ldapgroups_in_dn':
      return $servers[$sid]->ldapgroups_in_dn;
    case 'ldapgroups_dn_attribute':
      return !empty($servers[$sid]->ldapgroups_dn_attribute) ? $servers[$sid]->ldapgroups_dn_attribute : LDAPGROUPS_DEFAULT_DN_ATTRIBUTE;
    case 'ldapgroups_in_attr':
      return $servers[$sid]->ldapgroups_in_attr;
    case 'ldapgroups_attr':
      return !empty($servers[$sid]->ldapgroups_attr) ? unserialize($servers[$sid]->ldapgroups_attr) : array();
    case 'ldapgroups_as_entries':
      return $servers[$sid]->ldapgroups_as_entries;
    case 'ldapgroups_entries':
      return !empty($servers[$sid]->ldapgroups_entries) ? unserialize($servers[$sid]->ldapgroups_entries) : array();
    case 'ldapgroups_entries_attribute':
      return !empty($servers[$sid]->ldapgroups_entries_attribute) ? $servers[$sid]->ldapgroups_entries_attribute : LDAPGROUPS_DEFAULT_ENTRIES_ATTRIBUTE;
    case 'ldapgroups_mappings':
      return !empty($servers[$sid]->ldapgroups_mappings) ? unserialize($servers[$sid]->ldapgroups_mappings) : array();
    case 'ldapgroups_mappings_filter':
      return $servers[$sid]->ldapgroups_mappings_filter;
    case 'ldapgroups_filter_php':
      return $servers[$sid]->ldapgroups_filter_php;
    case 'ldapgroups_groups':
      return !empty($servers[$sid]->ldapgroups_groups) ? unserialize($servers[$sid]->ldapgroups_groups) : array();
  }
}

