#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

void listarServicio(Servicio x)
{
    printf("  %d  %15s       %d\n",
           x.id,
           x.descripcion,
           x.precio);
}

void listarServicios(Servicio vec[], int tam){
    int flag = 0;
    system("cls");

    printf(" ID                  COLOR    PRECIO\n");

    for(int i=0; i < tam; i++)
    {
        listarServicio(vec[i]);
        flag = 1;
    }
    if( flag == 0)
    {
        printf("\nNo hay servicios que mostrar\n");
    }
    printf("\n\n");
}

int cargarDescServicio(int id, Servicio servicios[], int tam, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if( id == servicios[i].id){
            strcpy(desc, servicios[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}
