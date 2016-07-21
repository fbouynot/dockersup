//
// Created by felix on 21/07/16.
//

#include "SetServerIp.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void SetServerIp()
{
    char line[1024];
    printf("Saisir l'ip du serveur cible, au format IPV4.\n");
    scanf ("%s", line);
    FILE * fp;
    fp = fopen("ip.conf", "w");
    if (fp == NULL) {
        printf("Echec d'ouverture du fichier, erreur numéro %d\n", errno);
        exit(-1);
    }
    fprintf(fp, line);
    fclose(fp);
}