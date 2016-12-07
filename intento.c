#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define PISOS 3

//AL CAMBIAR EL VALOR DE DONDE INICIA DUPLIMAN SE
//AGREGAN 3 DUPLIMAN DEPENDIENDO DE LA POSICION

//AL AGREGAR UNA X EN LA POSICION 2,9,8 APARECE TAMBIEN UNA EN LA 2,0,9
// NO ENTIENDO PORQUE

/***********************************
Johann Valenzuela
Gustavo Sanhueza
***********************************/
struct dupliman{
    int piso;
    int coorX;
    int coorY;
    struct dupliman *next;
};

/***************************
edificio[A][B][C]
A: piso
B: coorX
C: coorY
***************************/
char edificio[3][10][10];

typedef struct posicion{
    int piso;
    int coorX;
    int coorY;
}POSICION;

typedef struct thread_dupliman{
    POSICION pos;
    int id;
}Dupliman;

/*****************************************
Carga el txt que contiene el laberinto y almacena
los caracteres en la matriz edificio.
*****************************************/
void cargar_laberinto(){
	int i, j, k;
	for(i=0;i<3;i++){
		for(j=0; j<10; j++){
			for(k=0;k<10;k++){
				edificio[i][j][k] = 0;
			}
		}
	}
    FILE* archivo;
    int piso, coorX, coorY;
    char construccion;
    archivo = fopen("laberinto.txt", "r" );
    if(archivo!=NULL){
        while(!feof(archivo)){
            fscanf(archivo, "%d",&piso);
            fscanf(archivo, "%d",&coorX);
            fscanf(archivo, "%d",&coorY);
            fscanf(archivo, "%c",&edificio[piso][coorX][coorY]);
        }
        fclose(archivo);
    }
}

/********************************************
Muestra en pantalla por piso el laberinto
********************************************/
void mostrar_laberinto(){
    int a,b,c;
    for(a=0;a<PISOS;a++){
        printf("Piso: %d \n",a+1);
        for(b=0;b<10;b++){
            for(c=0;c<10;c++){
                if(edificio[a][b][c]==0){printf("0 ");}
                else{printf("%c ",edificio[a][b][c]);}
            }
            printf("\n");
        }
        printf("\n");
    }
}

void crear_dupliman(POSICION pos){
	strcpy(&edificio[pos.piso][pos.coorX][pos.coorY],"M");
}

void avanza_dupliman(){

}
int main(int argc, char *argv[])
{
    // CAMBIE LAS COORDENADAS Y LES PUSE 0 A COORX Y 0 A COORY COMO DICE EN LA TAREA
    //RESULTA QUE SE AGREGAN MAS VALORES
    POSICION pos;
    pos.piso = 2;
    pos.coorX = 0;
    pos.coorY = 0;
    cargar_laberinto();
    mostrar_laberinto();
    crear_dupliman(pos);
    mostrar_laberinto();
    return 0;
}
