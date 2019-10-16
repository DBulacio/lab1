#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"

Trabajo newTrabajo(int id, int patente, int idServicio, Fecha fecha){
    Trabajo x;

    x.id = id;
    x.patente = patente;
    x.fecha = fecha;
    x.idServicio = idServicio;
    x.isEmpty = 0;

    return x;
}

int buscarLibreTrabajo(Trabajo vec[], int tam)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


void listarTrabajo(Trabajo x, Servicio servicios[], int tServicios)
{
    char descServicio[20];

    cargarDescServicio(x.idServicio, servicios, tServicios, descServicio);

    printf("  %d    %d    %s    %d/%d/%d\n\n",
           x.id,
           x.patente,
           descServicio,
           x.fecha.dia,
           x.fecha.mes,
           x.fecha.anio);

}

void listarTrabajos(Trabajo trabajos[], int tTrabajo, Servicio servicios[], int tServicios){
    int flag = 0;
    system("cls");

    printf(" ID      PATENTE    SERVICIO     FECHA\n");

    for(int i=0; i < tTrabajo; i++)
    {
        if(trabajos[i].isEmpty == 0){
            listarTrabajo(trabajos[i], servicios, tServicios);
        }
        flag = 1;
    }
    if( flag == 0)
    {
        printf("\nNo hay autos que mostrar\n");
    }
    printf("\n\n");
}

int altaTrabajo(int idTrabajo, Trabajo vec[], int tTrabajo, Auto autos[], int tAutos, Servicio servicios[], int tServicios, Marca marcas[], int tMarcas, Color colores[], int tColores)
{
    int todoOk = 0;
    int indice;
    int patente;
    int idServicio;
    Fecha fecha;
    int fm = 0;
    int fc = 0;


    system("cls");

    printf("*****Alta Trabajo*****\n\n");

    indice = buscarLibreTrabajo(vec, tTrabajo);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        listarAutos(autos, tAutos, marcas, tMarcas, colores, tColores);

        printf("Ingrese patente: ");
        scanf("%d", &patente);
        for(int i = 0 ; i < tAutos ; i++){
            if(patente == autos[i].patente){
                fm = 1;
            }
        }
        while(fm == 0){
            printf("id incorrecta. ");
            printf("Ingrese patente: ");
            scanf("%d", &patente);
            for(int i = 0 ; i < tAutos ; i++){
                if(patente == autos[i].patente){
                    fm = 1;
                }
            }
        }

        listarServicios(servicios, tServicios);
        printf("Ingrese idServicio: ");
        scanf("%d", &idServicio);
        for(int i = 0 ; i < tServicios ; i++){
            if(idServicio == servicios[i].id){
                fc = 1;
            }
        }
        while(fc == 0){
            printf("id incorrecta. ");
            printf("Ingrese idServicio: ");
            scanf("%d", &idServicio);
            for(int i = 0 ; i < tServicios ; i++){
                if(idServicio == servicios[i].id){
                    fc = 1;
                }
            }
        }

        printf("Ingrese fecha: (dd/mm/aaaa)");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

        vec[indice] = newTrabajo(idTrabajo, patente, idServicio, fecha);
        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

    return todoOk;
}

void initTrabajo(Trabajo vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

int hardcodearTrabajos(Trabajo trabajos[], int tTrabajos, int cant){
    int cont = 0;

    Trabajo suplentes[] ={
    {20000, 112, 20003, {16, 10, 2019}, 0},
    {20001, 111, 20001, {15, 10, 2019}, 0},
    {20002, 113, 20001, {14, 10, 2019}, 0},
    {20003, 112, 20000, {14, 10, 2019}, 0},
    {20004, 111, 20002, {12, 10, 2019}, 0},
    };

    if( cant <= 5 && tTrabajos >= cant)
    {
        for(int i=0; i < cant; i++)
        {
            trabajos[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}
