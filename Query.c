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
    char* server_ip = malloc(sizeof(char) * 1024);
    FILE * fp;
    fp = fopen("ip.conf", "r");
    if (fp == NULL) {
        printf ("Echec d'ouverture du fichier, erreur numéro %d\n", errno);
        exit(-1);
    }
    // On lit le ficher de configuration qui contient l'IP du serveur cible
    // "%15[^\n]" signifie que fscnaf lira tous les carracteres de fp sauf '\n'
    // et s'arretera s'il le rencontre ou apres les 15er carracteres.
    fscanf(fp, "%15[^\n]", server_ip);
    printf(Client(server_ip, 5011));
    fclose(fp);
    free(server_ip);
}