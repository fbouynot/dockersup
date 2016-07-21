//
// Created by apunch on 7/21/16.
//

#include "Getinfo.h"
#include "stdio.h"
#include "stdlib.h"
#include <string.h>

char* GetInfo() {
    char buff[BUFSIZ];
    char* msg_popen = malloc(sizeof(char) * 1024);
    /* On utilise la fonction système "docker ps -a" pour récupérer les informations voulues.
     * popen nous permet de récupérer le retour de la fonction dans une variable et non dans stdout */
    FILE *fp = popen("docker ps -a", "r");
    while (fgets(buff, BUFSIZ, fp) != NULL) {
        strcat(msg_popen, buff);
    }
    pclose(fp);
    free(msg_popen);
    return msg_popen;
}