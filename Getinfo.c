//
// Created by apunch on 7/21/16.
//

#include "Getinfo.h"
#include "stdio.h"
#include "stdlib.h"

void TestPopen () {
    char buff[BUFSIZ];
    FILE *fp = popen("docker ps -a", "r");
    while (fgets(buff, BUFSIZ, fp) != NULL) {
        printf("%s", buff);
    }
    pclose(fp);
}