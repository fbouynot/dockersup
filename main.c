#include "ServerTCP.h"
#include "Menu.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
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
        sleep(1);
        Menu();
    }

    return 0;
}