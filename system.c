#include <stdio.h>
#include <stdlib.h> //system()
#include <string.h> //strcat()
#include <unistd.h> //chdir()

int main() {
    //primera capa
    system("mkdir 1");
    //system("mkdir 2");
    //system("mkdir 3");

    //segunda capa
    char string[25];
    chdir("1");
    for(int i=1; i<=3; i++){
        snprintf(string, sizeof(string), "%d", i);
        //strcat("mkdir", string);
        printf("%d\n", i);
    }

    //system("ls");
    return 0;
}