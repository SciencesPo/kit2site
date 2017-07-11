; $Id$

Drupal CAS + LDAP Integration
=============================

The ldapcas module extends the functionality of ldap_integration
(http://drupal.org/project/ldap_integration) to allow fetching of
LDAP user data when a user logs in via CAS.

Required Modules:
-----------------
LDAP Integration - http://drupal.org/project/ldap_integration
CAS - http://drupal.org/project/cas
Profile - (built in)

Suggested Modules:
------------------
RealName - http://drupal.org/project/realname

Installation:
-------------
Install and enable the following modules:
 * cas
 * profile
 * ldapdata or ldapgroups (part of ldap_integration)
 * ldapauth (part of ldap_integration)
 * ldapcas (this module)

Configure CAS, being sure to set the following options:
    "Is Drupal also the CAS user repository?"  =>  No

Configure LDAP Authentication, adding your LDAP server.

Configure LDAP Data, using the LDAP server you just created in LDAP Authentication.

Configure LDAP CAS.


Debugging:
----------
Don't forget to install and activate the ldap module in php.  In Ubuntu:
    sudo apt-get install php5-ldap
    sudo /etc/init.d/apache2 restart

Authors:
--------
* kassissieh (http://drupal.org/user/117382)
* Bradley Froehle (brad.froehle@gmail.com)
