
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct posicion{
  int piso;
  int fila;
  int columna;
  char construccion;
}Posicion;

typedef struct list_pos{
  Posicion pos;
  struct list_pos *next;
}List_pos;

typedef struct dupliman{
  Posicion pos;
  List_pos recorrido; //  Lista enlazada del recorrido de este Dupliman
}Dupliman;



void edificio_inic (List_pos *lista){
}

int main()
{
Posicion edificio[9][9][9];
srand (time(NULL));
  int i,j,k;
  for(i=0; i<10; i++){
    for(j=0; j<10; j++){
      for(k=0; k<10; k++){
        switch (1) {
          case 1:
            strcpy(edificio[i][j][k].construccion,"X");
            break;
          case 2:
            strcpy(edificio[i][j][k].construccion,"E");
            break;
          case 3:
            strcpy(edificio[i][j][k].construccion,"O");
            break;
          case 4:
            strcpy(edificio[i][j][k].construccion,"V");
            break;
          case 5:
            strcpy(edificio[i][j][k].construccion,"R");
            break;
         }
       }
     }
   }

    char *aux;

   for(i=0; i<10; i++){
     for(j=0; j<10; j++){
       for(k=0; k<10; k++){
         printf("\t %c",edificio[i][j][k].construccion);
       }
       printf("\n");
     }
     printf("\n");
   }
   return 0;
}
