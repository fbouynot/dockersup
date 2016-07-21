#include "ClientTCP.h"
#include "ServerTCP.h"
#include "Getinfo.h"
#include "Felix.h"
#include "Alex.h"
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    Felix();
    Alex();

    return 0;
}