#!/usr/bin/env bash

# verifie les paramètres donnés
if [ $# > 3 ]
 then
   echo "Execution de $0"
 else
    echo 'Usage : $0 < "update" pour crontab | "first" pour premier import > <dossier root de drupal ie:/store/www/kit2site>  < environnement ie: pprd.kit2site.sciencespo.fr | sciencespo.fr > < nom du site 1> < nom du site 2> < nom du site n>'
    exit 1
fi

OPTION=$1
ROOT=$2
ENV=$3
SITES=("$@")



for (( i = 3; i < $#; i++ )); do

 /store/www/drush/drush php-script --root=${ROOT} --uri=${ENV}.${SITES[i]} spire.import.inc ${OPTION} --script-path=/store/www/${ENV}/sites/${ENV}.${SITES[i]}/modules/spire;

done
