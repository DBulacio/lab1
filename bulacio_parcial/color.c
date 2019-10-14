#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

void listarColor(Color x)
{
    printf("  %d  %15s\n",
           x.id,
           x.nombreColor);
}

void listarColores(Color vec[], int tam){
    int flag = 0;
    system("cls");

    printf(" ID                  COLOR\n");

    for(int i=0; i < tam; i++)
    {
        listarColor(vec[i]);
        flag = 1;
    }
    if( flag == 0)
    {
        printf("\nNo hay colores que mostrar\n");
    }
    printf("\n\n");
}

int cargarDescColor(int id, Color colores[], int tam, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if( id == colores[i].id){
            strcpy(desc, colores[i].nombreColor);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}
