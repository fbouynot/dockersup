//
// Created by felix on 21/07/16.
//

#include "Menu.h"
#include "stdlib.h"
#include "stdio.h"
#include "Query.h"
#include "SetServerIp.h"

int Menu()
{
    int choice;

    do
    {
        printf("Menu\n\n");
        printf("1. Enter server IP\n");
        printf("2. List containers\n");
        printf("3. Exit\n");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1: SetServerIp();
                break;
            case 2: Query();
                break;
            default: printf("Invalid choice!\n");
                break;
        }

    } while (choice != 3);
    return 0;
}