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
    FILE * fp;
    fp = fopen("ip.conf", "r");
    if (fp == NULL) {
        printf ("Echec d'ouverture du fichier, erreur numéro %d\n", errno);
        exit(-1);
    }
    fclose(fp);
    Client("127.0.0.1");
}