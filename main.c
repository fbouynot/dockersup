#include "ServerTCP.h"
#include "ClientTCP.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    /* Afin, pour les tests, de lancer serveur et client dans le même programme, nous utilisons un fork qui lance le
     * serveur et le client */
    pid_t pid;
    pid = fork();
    if (pid == -1)
    {
        printf("Le fork a échoué, le client et le serveur ne peuvent pas s'exécuter en même temps.\n");
        exit(-1);
    }
    else if (pid == 0)
    {
        /* Bloc du serveur */
        /* Création d'un serveur TCP */
        Server(5000);
    }
    else
    {
        /* Bloc du client */
        /* On attend une seconde que le serveur soit lancé */
        sleep(1);
        /* Création d'un Client TCP */
        Client("127.0.0.1",5000);
        printf("Déconnexion du serveur.");
    }

    return 0;

}