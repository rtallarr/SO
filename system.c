#include <stdio.h>
#include <stdlib.h> //system()
#include <string.h> //strcat()
#include <unistd.h> //chdir()

void create_dirs(){
    system("mkdir 1");
    system("mkdir 2");
    system("mkdir 3");
}

int main() {

    char I[5]; // i pero en str
    char J[5];
    
    //capa 1
    create_dirs();

    //capa 2
    for(int i = 1; i <= 3; i++){ // 1 2 3
        snprintf(I, sizeof(I), "%d", i); //guardar i en I como str
        chdir(I);
        create_dirs();
        chdir("..");
    }
    
    //capa 3
    for(int i = 1; i <= 3; i++) {
        snprintf(I, sizeof(I), "%d", i); //guardar i en I como str
        chdir(I);
        for (int j = 1; j <= 3; j++) {
            snprintf(J, sizeof(J), "%d", j); //guardar j en J como str
            chdir(J);
            create_dirs();
            chdir("..");
        }
        chdir("..");
    }

    return 0;
}