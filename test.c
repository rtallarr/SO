#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define SIZE 25      //Maximum Length of name of folder

int main() {

    int result = mkdir("/mnt/c/users/rodrigo/desktop/ubuntu/ola/", 0777);
    char dir[3] = "directorio";

    printf("esta volaita %s\n", dir);

    return 0;
}