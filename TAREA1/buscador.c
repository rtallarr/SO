#include <stdio.h>
#include <string.h>

/*
  Estructura frase, se encargara de almacenar las frases para luego
  imprimir por pantalla

*/
typedef struct frase
{
   char frase_1[100];
   char frase_2[100];
   char frase_3[100];
}frase;

/*
funcion check_laberinto
Input: no posee entradas
Output: retorna 1 si es verdadero 0 si es falso
Descripcion: verifica la existencia de la carpeta laberinto,
la cual posee los archivos frase.txt
*/
int check_laberinto(){
  FILE *cmd=popen("ls", "r");
  char salida[24];
  while (fgets(salida, sizeof(salida), cmd) !=NULL)
          if (strcmp("Laberinto\n",salida) == 0) {
            pclose(cmd);
            return 1;
          }
  pclose(cmd);
  return 0;
}

/*
funcion recorrer
Input: Estructura que almacenara la frase
Output: no realiza retorno
Descripcion: a través de la utilidad find se busca y lee el contenido
de los archivos frase.txt, luego estos son recortados y almacenados en la
estructura
*/
void recorrer(frase *frase_final){
  FILE *cmd=popen("find Laberinto -name frase.txt -exec cat {} \\;", "r");
  char salida[200];
  while (fgets(salida, sizeof(salida), cmd) !=NULL){
      char temp_file[50];
      strcpy(temp_file,salida);
      size_t len = strlen(temp_file);
      if (len > 0 && temp_file[len-1] == '\n') {
        temp_file[--len] = '\0';
      }
      if (temp_file[0] == '1') {
        char * nueva = strtok(temp_file, "1,");
        strcpy(frase_final->frase_1, nueva+1);
      }
      else if (temp_file[0] == '2') {
        char * nueva = strtok(temp_file, "2,");
        strcpy(frase_final->frase_2, nueva+1);
      }
      else if (temp_file[0] == '3') {
        char * nueva = strtok(temp_file, "3,");
        strcpy(frase_final->frase_3, nueva+1);
      }
  }
  pclose(cmd);
}

/*
funcion main
Input: no posee entradas
Output: retorna 0 si finaliza correctamente 1 si ocurre error
Descripcion: invoca a las funciones para cargar las frases y ser impresas por
pantalla
*/
int main() {
  struct frase frase_final;
  int laberinto= check_laberinto();
  if (laberinto == 1) {
    recorrer(&frase_final);
    printf("%s", frase_final.frase_1);
    printf("%s", frase_final.frase_2);
    printf("%s\n", frase_final.frase_3);
    return 0;
  }else{
    printf("Laberinto no encontrado, ejecute 'laberinto' para continuar...\n");
  }
  return 1;
}
