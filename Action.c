#include <string.h>
#include <stdio.h>
#include "Action.h"

char * Action(char * msg) {
    char * ret;
    if (strcmp(msg,"") == 0) {
        return "BONJ";
    }
    else if (strcmp(msg,"WHO") == 0)
    {
        printf("Login :");
        scanf("%s",&ret);
        printf("\n");
        return ret;
    }
    else if (strcmp(msg,"PASSWD") == 0) {
        printf("Password :");
        scanf("%s",&ret);
        printf("\n");
        return ret;
    }
    else if (strcmp(msg,"WELC") == 0) {
        printf("Password :");
        scanf("%s",&ret);
        printf("\n");
        if (strcmp(ret,"rls"))
        {
            return ret;
        }
        else if (strcmp(ret,"rcd"))
        {
            return ret;
        }
        else if (strcmp(ret,"rpwd"))
        {
            return ret;
        }
        else if (strcmp(ret,"ls"))
        {
            /*command*/
        }
        else if (strcmp(ret,"cd"))
        {
            /*command*/
        }
        else if (strcmp(ret,"pwd"))
        {
            /*command*/
        }
        return ret;
    }
    return "";
}