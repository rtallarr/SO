#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h> //time()
#include <signal.h> //SIGKILL
#include <string.h>



//numero random entre up y low
int rando(int up, int low){
    int num = (rand() % (up - low + 1)) + low;
    return num;
}

//display del tablero inicial
void tablero(){
    printf(" ________________________________________________________\n");
    printf("| Jail  |+75|-50|  -50   |+75|   +75   |Back 3|   Free   |\n");
    printf("|  -25  |¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|Forward 3 |\n");
    printf("|  +50  |                       L  Y          |   +50    |\n");
    printf("| Back 2|                 P  O                |  Back 4  |\n");
    printf("|  -25  |           N  O                      |   +50    |\n");
    printf("|  +50  |      M  O                           |   -50    |\n");
    printf("|  +50  |_____________________________________|   -25    |\n");
    printf("| Start |-75|-25| Back 4 |+75|Forward 5|  +75 |   Jail   |\n");
    printf(" ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
}
void tablero_current(int position, char* value){
    char casillas[28][10] = {"Start", "+50", "+50", "-25", "Back 2", "+50", "-25",
                           "Jail", "+75", "-50", "-50", "+75", "+75", "Back 3",
                           "Free", "Forward 3", "+50", "Back 4", "+50", "-50", "-25",
                           "Jail", "+75", "Forward 5", "+75", "Back 4", "-25", "-75"};
    strcpy(casillas[position], value);
    printf(" ________________________________________________________\n");
    printf("| %s  |%s|%s|  %s   |%s|   %s   |%s|   %s   |\n"
    ,casillas[7],casillas[8],casillas[9],casillas[10],casillas[11],casillas[12]
    ,casillas[13],casillas[14]);
    printf("|  %s  |¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|%s |\n"
    ,casillas[6],casillas[15]);
    printf("|  %s  |                       L  Y          |   %s    |\n"
    ,casillas[5],casillas[16]);
    printf("| %s|                 P  O                |  %s  |\n"
    ,casillas[4], casillas[17]);
    printf("|  %s  |           N  O                      |   %s    |\n"
    ,casillas[3], casillas[18]);
    printf("|  %s  |      M  O                           |   %s    |\n"
    ,casillas[2], casillas[19]);
    printf("|  %s  |_____________________________________|   %s    |\n"
    ,casillas[1], casillas[20]);
    printf("| %s |%s|%s| %s |%s|%s|  %s |   %s   |\n"
    ,casillas[0],casillas[27],casillas[26],casillas[25],casillas[24]
    ,casillas[23],casillas[22],casillas[21]);
    printf(" ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");

}

//termina el proceso de id pid
void kill_childs(int pid){
    kill(pid, SIGKILL);
}

int main() {
    char casillas[28][10] = {"Start", "+50", "+50", "-25", "Back 2", "+50", "-25",
                             "Jail", "+75", "-50", "-50", "+75", "+75", "Back 3",
                             "Free", "Forward 3", "+50", "Back 4", "+50", "-50", "-25",
                             "Jail", "+75", "Forward 5", "+75", "Back 4", "-25", "-75"};
    int monedas[28]={0,50,50,-25,0,50,-25,
                0,75,-50,-50,75,75,0,
                0,0,50,0,50,-50,-25,
                0,75,0,75,0,-25,-75};
    tablero();
    sleep(2);
    //printf("casilla %s\n", casillas[27]);

    //CREAR PIPES
    //[0]: Lectura
    //[1]: Escritura
    int pipe_pj[2]; //pipe pj es el proceso p enviando al j
    int pipe_jp[2];
    int pipe_j1_c1[2];
    int pipe_c1_c2[2];
    int pipe_c2_p[2];
    int pipe_c1_p[2];

    //INICIAR PIPES
    pipe(pipe_pj); //padre->jugador
    pipe(pipe_jp);
    pipe(pipe_j1_c1); //j1->c1
    pipe(pipe_c1_c2);
    pipe(pipe_c2_p);
    pipe(pipe_c1_p);

    int turno = 1;
    const int meta = 500;
    int juego = 1; //juego 1 -> aun no termina el juego 0, se acabó

    //DATOS JUGADORES
    int pos = 0;
    int saldo = 100;
    int estado = 1; //1 puede jugar, 0 no (para Jail)
    int roll;

    //Crear procesos
    int j1, c1, c2;
    j1 = fork();
    if (j1 == 0){
        //Jugador 1
        srand(time(NULL)/2);
        //printf("j1 --> pid = %d and ppid = %d | j1 = %d\n",getpid(), getppid(), j1);
        close(pipe_pj[1]);
        close(pipe_jp[0]);
        close(pipe_j1_c1[0]);

        while (saldo < meta){
            while((read(pipe_pj[0], &turno, 1))<0){} //esperar turno
            if (estado ==1){
              roll = rando(6, 1);
              pos += roll;
              pos= pos%28;
              printf("Turno de j1\nJ1 sacó %d en el dado\n", roll);
              if (pos == 4){
                printf("J1 back 2\n");
                  pos -=2;
              }else if (pos ==13){
                printf("J1 back 3\n");
                  pos -=3;
              }else if (pos ==15){
                printf("J1 forward 3\n");
                  pos +=3;
              }else if (pos ==17){
                printf("J1 forward 4\n");
                  pos +=4;
              }else if (pos ==23){
                printf("J1 forward 5\n");
                  pos +=5;
              }else if (pos ==24){
                printf("J1 back 4\n");
                  pos -=5;
              }
              pos= pos%28;
              saldo += monedas[pos];
              //etc
              if (pos ==0){
                printf("J1 cruza la meta +100\n");
                saldo+=100;
              }else if (pos==7 || pos ==21 ){
                  estado=0;
                  printf("J1 entra a prisión\n");

              }
              printf("saldo: %d\nPos: %d\n", saldo, pos);
              printf("Celda: %s\n",casillas[pos]);
              printf("==============\n");
              tablero_current(pos,"J1");
              if (saldo >= meta){
                  juego = 0; //se acabo el juego
                  printf("J1 gana\n");
                  write(pipe_jp[1], &juego, 1); //mandar juego = 0
              } else {
                  turno++;
                  write(pipe_j1_c1[1], &turno, 1); //dar turno a c1
                  sleep(1);
                  write(pipe_jp[1], &juego, 1);
              }

            }else{
              estado=1;
              printf("J1 sale de prisión\n");
              printf("saldo: %d\nPos: %d\n", saldo, pos);
              printf("Celda: %s\n",casillas[pos]);
              printf("==============\n");
              tablero_current(pos,"J1");
              if (saldo >= meta){
                  juego = 0; //se acabo el juego
                  printf("FIN DEL JUEGO\nJ1 gana\n");
                  write(pipe_jp[1], &juego, 1); //mandar juego = 0
              } else {
                  turno++;
                  write(pipe_j1_c1[1], &turno, 1); //dar turno a c1
                  sleep(1);
                  write(pipe_jp[1], &juego, 1);
              }
            }

        }
    }
    sleep(1);
    if (j1 > 0){
        c1 = fork();
        if (c1 == 0) {
            //Computador 1
            srand(time(NULL)/3+2);
            //printf("c1 --> pid = %d and ppid = %d\n",getpid(), getppid());
            close(pipe_j1_c1[1]);
            close(pipe_c1_c2[0]);
            close(pipe_c1_p[0]);

            while(saldo < meta){
                while((read(pipe_j1_c1[0], &turno, 1))<0){} //esperar turno
                if (estado ==1){
                  roll = rando(6, 1);
                  pos += roll;
                  pos= pos%28;
                  printf("Turno de c1\nc1 sacó %d en el dado\n", roll);
                  if (pos == 4){
                    printf("C1 back 2\n");
                      pos -=2;
                  }else if (pos ==13){
                    printf("C1 back 3\n");
                      pos -=3;
                  }else if (pos ==15){
                    printf("C1 forward 3\n");
                      pos +=3;
                  }else if (pos ==17){
                    printf("C1 forward 4\n");
                      pos +=4;
                  }else if (pos ==23){
                    printf("C1 forward 5\n");
                      pos +=5;
                  }else if (pos ==24){
                    printf("C1 back 4\n");
                      pos -=5;
                  }
                  pos= pos%28;
                  saldo += monedas[pos];
                  if (pos ==0){
                    printf("C1 cruza la meta +100\n");
                    saldo+=100;
                  }else if (pos==7 || pos ==21 ){
                      estado=0;
                      printf("C1 entra a prisión\n");

                  }
                  printf("saldo: %d\nPos: %d\n", saldo, pos);
                  printf("Celda: %s\n",casillas[pos]);
                  printf("==============\n");
                  tablero_current(pos,"C1");
                  if (saldo >= meta){
                      juego = 0; //se acabo el juego
                      printf("C1 gana\n");
                      write(pipe_c1_p[1], &juego, 1); //mandar juego = 0
                  } else {
                      turno++;
                      write(pipe_c1_c2[1], &turno, 1); //dar turno a c2
                      sleep(1);
                      write(pipe_c1_p[1], &juego, 1); //juego sigue
                  }
                }else{
                  estado=1;
                  printf("C1 sale de prisión\n");
                  printf("saldo: %d\nPos: %d\n", saldo, pos);
                  printf("Celda: %s\n",casillas[pos]);
                  printf("==============\n");
                  tablero_current(pos,"C1");
                  if (saldo >= meta){
                      juego = 0; //se acabo el juego
                      printf("FIN DEL JUEGO\nC1 gana\n");
                      write(pipe_c1_p[1], &juego, 1); //mandar juego = 0
                  } else {
                      turno++;
                      write(pipe_c1_c2[1], &turno, 1); //dar turno a c2
                      sleep(1);
                      write(pipe_c1_p[1], &juego, 1); //juego sigue
                  }
                }

            }
        }
        else {
            c2 = fork();
            if (c2 == 0) {
                //Computador 2
                srand(time(NULL)/5-1);
                //printf("c2 --> pid = %d and ppid = %d\n",getpid(), getppid());
                close(pipe_c1_c2[1]);
                close(pipe_c2_p[0]);

                while(saldo < meta){
                    while((read(pipe_c1_c2[0], &turno, 1))<0){} //esperar turno
                    if (estado ==1){
                      roll = rando(6, 1);
                      pos += roll;
                      pos= pos%28;
                      printf("Turno de c2\nc2 sacó %d en el dado\n", roll);
                      if (pos == 4){
                        printf("C2 back 2\n");
                          pos -=2;
                      }else if (pos ==13){
                        printf("C2 back 3\n");
                          pos -=3;
                      }else if (pos ==15){
                        printf("C2 forward 3\n");
                          pos +=3;
                      }else if (pos ==17){
                        printf("C2 forward 4\n");
                          pos +=4;
                      }else if (pos ==23){
                        printf("C2 forward 5\n");
                          pos +=5;
                      }else if (pos ==25){
                        printf("C2 back 4\n");
                          pos -=5;
                      }
                      pos= pos%28;
                      saldo += monedas[pos];
                      if (pos ==0){
                        printf("C2 cruza la meta +100\n");
                        saldo+=100;
                      }else if (pos==7 || pos ==21 ){
                          estado=0;
                          printf("C2 entra a prisión\n");

                      }

                      printf("saldo: %d\nPos: %d\n", saldo, pos);
                      printf("Celda: %s\n",casillas[pos] );
                      printf("==============\n");
                      tablero_current(pos,"C2");
                      if (saldo >= meta){
                          juego = 0; //se acabo el juego
                          printf("FIN DEL JUEGO\nC2 gana\n");
                          write(pipe_c2_p[1], &juego, 1); //mandar juego = 0
                      } else {
                          turno = 1;
                          write(pipe_c2_p[1], &turno, 1); //dar turno a j1
                          sleep(1);
                          write(pipe_c2_p[1], &juego, 1); //juego sigue
                      }

                    }else{
                      estado=1;
                      printf("C2 sale de prisión\n");
                      printf("saldo: %d\nPos: %d\n", saldo, pos);
                      printf("Celda: %s\n",casillas[pos] );
                      printf("==============\n");
                      tablero_current(pos,"C2");
                      if (saldo >= meta){
                          juego = 0; //se acabo el juego
                          printf("C2 gana\n");
                          write(pipe_c2_p[1], &juego, 1); //mandar juego = 0
                      } else {
                          turno = 1;
                          write(pipe_c2_p[1], &turno, 1); //dar turno a j1
                          sleep(1);
                          write(pipe_c2_p[1], &juego, 1); //juego sigue
                      }
                    }
                }
            }
            else {
                //Proceso Padre
                //printf("parent --> pid = %d\n", getpid());
                close(pipe_pj[0]);
                close(pipe_jp[1]);
                close(pipe_c2_p[1]);
                close(pipe_c1_p[1]);

                write(pipe_pj[1], &turno, 1);
                while(juego == 1){ //mientras no se haya acabdo el juego
                    read(pipe_jp[0], &juego, 1);
                    if (juego == 0){ //ganó el jugador 1
                        kill_childs(j1);
                        kill_childs(c1);
                        kill_childs(c2);
                        break;
                    }
                    read(pipe_c1_p[0], &juego, 1);
                    if (juego == 0){ //ganó el c1
                        kill_childs(j1);
                        kill_childs(c1);
                        kill_childs(c2);
                        break;
                    }
                    read(pipe_c2_p[0], &juego, 1);
                    if (juego == 0){ //ganó el c2
                        kill_childs(j1);
                        kill_childs(c1);
                        kill_childs(c2);
                        break;
                    }
                    while((read(pipe_c2_p[0], &turno, 1))<0){} //esperar msg de c2
                    write(pipe_pj[1], &turno, 1); //pasar turno a j1
                    sleep(1);
                }
            }
        }
    }
}
