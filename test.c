#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define SIZE 25      //Maximum Length of name of folder

int rando(int up, int low){
    int num = (rand() % (up - low + 1)) + low;
    return num;
}

int main() {
    srand(time(NULL));
    //int result = mkdir("/mnt/c/users/rodrigo/desktop/ubuntu/ola/", 0777);
    //char dir[3] = "directorio";

    //printf("esta volaita %s\n", dir);

    int x = rando(3, 1);

    printf("num: %d\n",x);

    return 0;
}