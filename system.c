#include <stdio.h>
#include <stdlib.h> //system()
#include <string.h> //strcat()
#include <unistd.h> //chdir()

int main() {
    //primera capa
    system("mkdir 1");
    system("mkdir 2");
    system("mkdir 3");

    //segunda capa
    //char buffer[5]; //para guardar I en str
    //char bufferJ[5]; //para guardar J en str
    //char s[100];

    //for(int j=1; j<=3; j++){
    //    snprintf(bufferJ, sizeof(bufferJ), "%d", j); //convertir j. int->str
    //    chdir(bufferJ);
    //    for(int i=1; i<=3; i++){
    //        char mdir[10] = "mkdir "; //variable para guardar el comando
    //        snprintf(buffer, sizeof(buffer), "%d", i); //convert i. int->str
    //        strcat(mdir, buffer);
    //        system(mdir); //strcat se guarda en el primer string
    //        printf("%s\n", getcwd(s, 100));
    //    }
    //    chdir("..");
    //}

    //system("ls");
    return 0;
}