//
// Created by felix on 21/07/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "Query.h"
#include "ClientTCP.h"

void Query()
{
    char* server_ip;
    FILE * fp;
    fp = fopen("ip.conf", "r");
    if (fp == NULL) {
        printf ("Echec d'ouverture du fichier, erreur numéro %d\n", errno);
        exit(-1);
    }
    // On lit le ficher de configuration qui contient l'IP du serveur cible
    // "%29[^\n]" signifie que fscnaf lira tous les carracteres de fp sauf '\n'
    // et s'arretera s'il le rencontre
    fscanf(fp, "%29[^\n]", server_ip);
    printf(Client(server_ip));
    fclose(fp);
}