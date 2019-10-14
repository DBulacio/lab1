#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"

void listarMarca(Marca x)
{
    printf("  %d  %15s\n",
           x.id,
           x.descripcion);
}

void listarMarcas(Marca vec[], int tam){
    int flag = 0;
    system("cls");

    printf(" ID                  MARCA\n");

    for(int i=0; i < tam; i++)
    {
        listarMarca(vec[i]);
        flag = 1;
    }
    if( flag == 0)
    {
        printf("\nNo hay marcas que mostrar\n");
    }
    printf("\n\n");
}

int cargarDescMarca(int id, Marca marcas[], int tam, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if( id == marcas[i].id){
            strcpy(desc, marcas[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}
