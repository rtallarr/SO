#include <stdio.h>
#include <stdlib.h> //system()
#include <unistd.h> //chdir()
#include <time.h> //time()
#include <string.h>

void create_dirs(){
    system("mkdir 1");
    system("mkdir 2");
    system("mkdir 3");
}

//numero random entre up y low
int rando(int up, int low){
    int num = (rand() % (up - low + 1)) + low;
    return num;
}

//concatena 3 numeros INT en la variable var -> STR
char* concatenate(char* var, int one, int two, int three){
    char buffer2[10];
    char buffer3[10];
    snprintf(var, 10, "%d", one); //int->str
    snprintf(buffer2, sizeof(buffer2), "%d", two); //int->str
    snprintf(buffer3, sizeof(buffer3), "%d", three);
    strcat(var, buffer2);
    strcat(var, buffer3);
    return var;
}

int main() {
    srand(time(NULL)/2); //set seed
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

    //FILE 1

    int num1 = rando(3, 1); //numero 3-1
    int num2 = rando(3, 1);
    int num3 = rando(3, 1);

    char NUM1[2]; //str
    char NUM2[2];
    char NUM3[2];

    snprintf(NUM1, sizeof(NUM1), "%d", num1); //int->str
    snprintf(NUM2, sizeof(NUM2), "%d", num2);
    snprintf(NUM3, sizeof(NUM3), "%d", num3);

    char conca1[10];
    concatenate(conca1, num1, num2, num3); //concatenate combination of folders 
    printf("conca1: %s\n", conca1);
    
    chdir(NUM1);
    chdir(NUM2);
    chdir(NUM3);

    FILE *fp1;
    fp1 = fopen("frase.txt", "w");
    fprintf(fp1, "1, los hurones del ");
    fclose(fp1);

    chdir("..");
    chdir("..");
    chdir("..");

    //FILE 2

    num1 = rando(3, 1); //numero 3-1
    num2 = rando(3, 1);
    num3 = rando(3, 1);

    char conca2[10];
    concatenate(conca2, num1, num2, num3); //concatenate combination of folders 
    printf("conca2: %s\n", conca2);

    while (conca1 == conca2) {
        num1 = rando(3, 1); //volver a generar los numeros
        num2 = rando(3, 1);
        num3 = rando(3, 1);
    }

    snprintf(NUM1, sizeof(NUM1), "%d", num1); //int->str
    snprintf(NUM2, sizeof(NUM2), "%d", num2);
    snprintf(NUM3, sizeof(NUM3), "%d", num3);

    chdir(NUM1);
    chdir(NUM2);
    chdir(NUM3);

    FILE *fp2;
    fp2 = fopen("frase.txt", "w");
    fprintf(fp2, "2, profesor de sistemas operativos son "); //3, un mob del minecraft altamente peligroso y temido por millones
    fclose(fp2);

    chdir("..");
    chdir("..");
    chdir("..");

    //FILE 3

    num1 = rando(3, 1); //numero 3-1
    num2 = rando(3, 1);
    num3 = rando(3, 1);

    char conca3[10];
    concatenate(conca3, num1, num2, num3); //concatenate combination of folders 
    printf("conca3: %s\n", conca3);

    while (conca1 == conca3 || conca2 == conca3) {
        num1 = rando(3, 1); //volver a generar los numeros
        num2 = rando(3, 1);
        num3 = rando(3, 1);
    }

    snprintf(NUM1, sizeof(NUM1), "%d", num1); //int->str
    snprintf(NUM2, sizeof(NUM2), "%d", num2);
    snprintf(NUM3, sizeof(NUM3), "%d", num3);

    chdir(NUM1);
    chdir(NUM2);
    chdir(NUM3);
    
    //char t[150];
    //printf("working dir: %s\n", getcwd(t, 100));

    FILE *fp3;
    fp3 = fopen("frase.txt", "w");
    fprintf(fp3, "3, un mob del minecraft altamente peligroso y temido por millones");
    fclose(fp3);

    chdir("..");
    chdir("..");
    chdir("..");

    return 0;
}