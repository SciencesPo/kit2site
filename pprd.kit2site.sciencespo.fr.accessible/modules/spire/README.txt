Module Spire pour Drupal 6.

Ce module permet l'importation depuis spire des centres de recherche
(orgunit) puis des chercheurs et leurs publications associées pour les centres
sélectionnés.
La mise à jour des données importées est faite une fois par jour.


INSTALLATION

- installer le module
- créer un vocabulaire 'Spire Thèmes de recherche' et l'associer à Spire
  Chercheurs
- dans Multilingual options, cocher 'Per language terms. Different terms will
  be allowed for each language and they can be translated.'
- s'assurer que le script spire.sh soit dans /store/scripts/kit2site/

PREMIERE IMPORTATION

- utiliser la commande : sh /store/scripts/kit2site/spire.sh first
  <environnement> <nom du site>

UPDATES

- le site doit être ajouté à la commande crontab qui appelle spire.sh, sous la
  forme sh /store/scripts/kit2site/spire.sh update <environnement> <site1>
<site2> ... <siteN>
