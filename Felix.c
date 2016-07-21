//
// Created by felix on 21/07/16.
//

#include "Felix.h"
#include "ServerTCP.h"
#include "ClientTCP.h"
#include <sys/types.h>
#include <unistd.h>

int Felix()
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        Server();
    }
    else
    {
        sleep(5);
        Client();
    }
    return 0;
}