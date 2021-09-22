#include <stdio.h>
#include <stdlib.h> //system()
#include <unistd.h> //chdir()
#include <time.h> //time()

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

    //printf("num1: %d\nnum2: %d\nnum3: %d\n", num1, num2, num3);

    snprintf(NUM1, sizeof(NUM1), "%d", num1); //int->str
    snprintf(NUM2, sizeof(NUM2), "%d", num2);
    snprintf(NUM3, sizeof(NUM3), "%d", num3);
    
    chdir(NUM1);
    chdir(NUM2);
    chdir(NUM3);

    FILE *fp1;
    fp1 = fopen("frase.txt", "w");
    fprintf(fp1, "1, los hurones del \n");
    fclose(fp1);

    //FILE 2

    num1 = rando(3, 1); //numero 3-1
    num2 = rando(3, 1);
    num3 = rando(3, 1);

    snprintf(NUM1, sizeof(NUM1), "%d", num1); //int->str
    snprintf(NUM2, sizeof(NUM2), "%d", num2);
    snprintf(NUM3, sizeof(NUM3), "%d", num3);

    if (access("frase.txt", F_OK ) == 0 ) {
        num1 = rando(3, 1); 
        num2 = rando(3, 1);
        num3 = rando(3, 1);
        snprintf(NUM1, sizeof(NUM1), "%d", num1);
        snprintf(NUM2, sizeof(NUM2), "%d", num2);
        snprintf(NUM3, sizeof(NUM3), "%d", num3);
    }

    chdir(NUM1);
    chdir(NUM2);
    chdir(NUM3);
    
    FILE *fp2;
    fp2 = fopen("frase.txt", "w");
    fprintf(fp2, "2, profesor de sistemas operativos son \n");
    fclose(fp2);

    return 0;
}