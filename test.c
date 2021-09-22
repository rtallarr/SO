#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define SIZE 25      //Maximum Length of name of folder

int rando(int up, int low){
    int num;
    for (int i = 0; i < 10; i++){
        num = (rand() % (up - low + 1)) + low;
        printf("num: %d\n",num);
    }
}

int main() {
    srand(time(NULL));
    //int result = mkdir("/mnt/c/users/rodrigo/desktop/ubuntu/ola/", 0777);
    //char dir[3] = "directorio";

    //printf("esta volaita %s\n", dir);

    rando(3, 1);

    //printf("num: %d\n", x);

    return 0;
}