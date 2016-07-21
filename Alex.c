//
// Created by felix on 21/07/16.
//

#include "Alex.h"
#include "Getinfo.h"
#include "stdio.h"
#include "stdlib.h"

int Alex()
{
    char* info = GetInfo();
    printf("%s\n", info);
    return 0;
}