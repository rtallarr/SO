# Tarea 2 - Sistemas Operativos

### Integrantes

Rodrigo Tallar
201973528-4
Paralelo 201

Matia Cornejo
201873091-2
Paralelo 200

### Instrucciones de uso

Navegar en la terminal a la carpeta de la tarea.  
Ejecutar `make`.  
Esto crea una carpeta un archivo `mono` que es el ejecutable de `mono.c`.
El mismo comando `make` se encarga de correr `mono`, por lo que se deberia tener de forma inmediata el output del programa.
Con `make clean` se puede borrar todo el contenido creado.

Ejemplo de salida

```bash
Turno de c2
c2 sacó 4 en el dado
saldo: 525
Pos: 22
Celda: +75
==============
 ________________________________________________________
| Jail  |+75|-50|  -50   |+75|   +75   |Back 3|   Free   |
|  -25  |¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|Forward 3 |
|  +50  |                       L  Y          |   +50    |
| Back 2|                 P  O                |  Back 4  |
|  -25  |           N  O                      |   +50    |
|  +50  |      M  O                           |   -50    |
|  +50  |_____________________________________|   -25    |
| Start |-75|-25| Back 4 |+75|Forward 5|  C2 |   Jail   |
 ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
C2 gana
fin

```
