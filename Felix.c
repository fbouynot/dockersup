//
// Created by felix on 21/07/16.
//

#include "Felix.h"
#include "ServerTCP.h"
#include "ClientTCP.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int Felix()
{
    pid_t pid;
    pid = fork();
    if (pid == -1)
    {
        printf("Le fork a échoué, le client et le serveur ne peuvent pas s'exécuter en même temps.\n");
        exit(-1);
    }
    else if (pid == 0)
    {
        Server();
    }
    else
    {
        sleep(5);
        printf("%s", Client("127.0.0.1"));
    }
    return 0;
}