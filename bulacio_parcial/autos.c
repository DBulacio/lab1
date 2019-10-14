#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autos.h"

int altaAuto(int idAuto, Auto vec[], int tAutos, Marca marcas[], int tMarcas, Color colores[], int tColores)
{
    int todoOk = 0;
    int indice;
    int patente;
    int idMarca;
    int idColor;
    int modelo;
    int fm = 0;
    int fp = 0;
    int fc = 0;


    system("cls");

    printf("*****Alta Auto*****\n\n");

    indice = buscarLibre(vec, tAutos);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        printf("Ingrese patente: ");
        scanf("%d", &patente);
        for(int i = 0 ; i < tAutos ; i++){
            if(patente == vec[i].patente && vec[i].isEmpty == 0){
                fp = 1;
            }
        }
        while(fp == 1){
            printf("Patente falsa. ");
            printf("Ingrese patente: ");
            scanf("%d", &patente);
            for(int i = 0 ; i < tAutos ; i++){
                if(patente == vec[i].patente && vec[i].isEmpty == 0){
                    fp = 1;
                    break;
                } else {
                    fp = 0;
                }
            }
        }

        listarMarcas(marcas, tMarcas);
        printf("Ingrese idMarca: ");
        scanf("%d", &idMarca);
        for(int i = 0 ; i < tMarcas ; i++){
            if(idMarca == marcas[i].id){
                fm = 1;
            }
        }
        while(fm == 0){
            printf("id incorrecta. ");
            printf("Ingrese idMarca: ");
            scanf("%d", &idMarca);
            for(int i = 0 ; i < tMarcas ; i++){
                if(idMarca == marcas[i].id){
                    fm = 1;
                }
            }
        }

        listarColores(colores, tColores);
        printf("Ingrese idColor: ");
        scanf("%d", &idColor);
        for(int i = 0 ; i < tColores ; i++){
            if(idColor == colores[i].id){
                fc = 1;
            }
        }
        while(fc == 0){
            printf("id incorrecta. ");
            printf("Ingrese idColor: ");
            scanf("%d", &idColor);
            for(int i = 0 ; i < tColores ; i++){
                if(idColor == colores[i].id){
                    fc = 1;
                }
            }
        }

        printf("Ingrese modelo: ");
        scanf("%d", &modelo);

        vec[indice] = newAuto(idAuto, patente, idMarca, idColor, modelo);
        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

    return todoOk;
}

Auto newAuto(int id, int patente, int idMarca, int idColor, int modelo){
    Auto x;

    x.id = id;
    x.patente = patente;
    x.idMarca = idMarca;
    x.idColor = idColor;
    x.modelo = modelo;
    x.isEmpty = 0;

    return x;
}

int buscarLibre(Auto vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void initAuto(Auto vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

void listarAuto(Auto x, Marca marcas[], int tMarcas, Color colores[], int tColores)
{
    char descMarca[20];
    char descColor[20];

    cargarDescMarca(x.idMarca, marcas, tMarcas, descMarca);
    cargarDescColor(x.idColor, colores, tColores, descColor);

    printf("  %d    %d    %s    %s     %d\n",
           x.id,
           x.patente,
           descMarca,
           descColor,
           x.modelo);
}

void listarAutos(Auto vec[], int tam, Marca marcas[], int tMarcas, Color colores[], int tColores){
    int flag = 0;
    system("cls");

    printf(" ID      PATENTE    MARCA     COLOR     MODELO\n");

    ordenarAuto(vec, tam);

    for(int i=0; i < tam; i++)
    {
        if(vec[i].isEmpty == 0){
            listarAuto(vec[i], marcas, tMarcas, colores, tColores);
        }
        flag = 1;
    }
    if( flag == 0)
    {
        printf("\nNo hay autos que mostrar\n");
    }
    printf("\n\n");
}

int bajaAuto(Auto vec[], int tam, Marca marcas[], int tMarcas, Color colores[], int tColores)
{
    int todoOk = 0;
    int patente;
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja Auto *****\n\n");

    listarAutos(vec, tam, marcas, tMarcas, colores, tColores);

    printf("Ingrese patente: ");
    scanf("%d", &patente);


    indice = buscarAuto(patente, vec, tam);

    if( indice == -1)
    {
        printf("No existe un auto con esa patente\n\n");

    }
    else
    {
        listarAuto(vec[indice], marcas, tMarcas, colores, tColores);

        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            vec[indice].isEmpty = 1;
            todoOk = 1;
            printf("Baja exitosa!!!");
        }
        else
        {
            printf("Se ha cancelado la operacion");
        }
    }

    return todoOk;
}


int buscarAuto(int patente, Auto vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].patente == patente && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


void ordenarAuto(Auto vec[], int tam){

    Auto auxAutos;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if(vec[i].idMarca < vec[j].idMarca)
            {
                auxAutos = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAutos;
            }
        }
    }

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if(vec[i].idMarca == vec[j].idMarca && vec[i].patente < vec[j].patente)
            {
                auxAutos = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAutos;
            }
        }
    }
}


int modificarAuto(Auto vec[], int tam, Marca marcas[], int tMarcas, Color colores[], int tColores)
{
    int todoOk = 0;
    int patente;
    int indice;
    system("cls");
    printf("***** Modificar Auto *****\n\n");
    listarAutos(vec, tam, marcas, tMarcas, colores, tColores);
    printf("Ingrese patente: ");
    scanf("%d", &patente);
    int opcion;

    indice = buscarAuto(patente, vec, tam);

    if( indice == -1)    {
        printf("No existe un alumno con ese legajo\n\n");
    }
    else
    {
        listarAuto(vec[indice], marcas, tMarcas, colores, tColores);
        do{
            printf("1- Modificar Color\n");
            printf("2- Modificar Modelo\n");
            printf("3- Salir\n\n");
            printf("Ingrese opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);
            switch(opcion)
            {
            case 1:
                listarColores(colores, tColores);
                printf("Ingrese nuevo idColor: ");
                fflush(stdin);
                scanf("%d", &vec[indice].idColor);
                break;
            case 2:
                printf("Ingrese nuevo modelo: ");
                fflush(stdin);
                scanf("%d", &vec[indice].modelo);
                break;
            case 3:
                printf("Se ha cancelado la mofdificacion ");
                break;

            }
        } while(opcion != 3);
    }
    return todoOk;
}

