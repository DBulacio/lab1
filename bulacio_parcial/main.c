#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autos.h"

typedef struct{
    int dia;
    int mes;
    int anio;
}Fecha;

typedef struct{
    int id;
    char descripcion[20];
}Marca;

typedef struct{
    int id;
    char nombreColor[20];
}Color;

typedef struct{
    int id;
    char descripcion[25];
    int precio;
}Servicio;

typedef struct{
    int id;
    int patente;
    int idServicio;
    Fecha fecha;
    int isEmpty;
}Trabajo;

typedef struct{
    int id;
    int patente;
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
}Auto;

int altaAuto(int idAuto, Auto vec[], int tAutos, Marca marcas[], int tMarcas, Color colores[], int tColores);
Auto newAuto(int id, int patente, int idMarca, int idColor, int modelo);
void initAuto(Auto vec[], int tam);
int buscarLibre(Auto vec[], int tam);

Trabajo newTrabajo(int id, int patente, int idServicio, Fecha fecha);
int altaTrabajo(int idTrabajo, Trabajo vec[], int tTrabajo, Auto autos[], int tAutos, Servicio servicios[], int tServicios, Marca marcas[], int tMarcas, Color colores[], int tColores);
int buscarLibreTrabajo(Trabajo vec[], int tam);
void initTrabajo(Trabajo vec[], int tam);

int menu();
void listarMarca(Marca x);
void listarColor(Color x);
void listarServicio(Servicio x);
void listarAuto(Auto x, Marca marcas[], int tMarcas, Color colores[], int tColores);

void listarMarcas(Marca vec[], int tam);
void listarColores(Color vec[], int tam);
void listarServicios(Servicio vec[], int tam);
void listarAutos(Auto vec[], int tam, Marca marcas[], int tMarcas, Color colores[], int tColores);

int cargarDescColor(int id, Color colores[], int tam, char desc[]);
int cargarDescMarca(int id, Marca marcas[], int tam, char desc[]);

int buscarAuto(int patente, Auto vec[], int tam);
int bajaAuto(Auto vec[], int tam, Marca marcas[], int tMarcas, Color colores[], int tColores);
void ordenarAuto(Auto vec[], int tam);
int modificarAuto(Auto vec[], int tam, Marca marcas[], int tMarcas, Color colores[], int tColores);
int cargarDescServicio(int id, Servicio servicios[], int tam, char desc[]);

int main()
{
    int tMarcas = 5;
    int tColores = 5;
    int tServicios = 4;
    int tAutos = 10;
    int tTrabajo = 10;
    int flag = 0;
    int idTrabajo = 20000;
    int idAuto = 1000;

    char salir = 'n';

    Auto autos[tAutos];
    Trabajo trabajos[tTrabajo];

    Marca marcas[] = {{1000, "Renault"},
                      {1001, "Fiat"},
                      {1002, "Ford"},
                      {1003, "Chevrolet"},
                      {1004, "Peugeot"}};

    Color colores[] = {{5000, "Negro"},
                       {5001, "Blanco"},
                       {5002, "Gris"},
                       {5003, "Rojo"},
                       {5004, "Azul"}};

    Servicio servicios[] = {{20000, "Lavado", 250},
                            {20001, "Pulido", 300},
                            {20002, "Encerado", 400},
                            {20003, "Completo", 600}};

    initAuto(autos, tAutos);
    initTrabajo(trabajos, tTrabajo);

    do{
        switch(menu()){
            case 1:
                if(altaAuto(idAuto, autos, tAutos, marcas, tMarcas, colores, tColores)){
                    idAuto++;
                    flag = 1;
                }
                break;
            case 2:
                if(flag == 1){
                    modificarAuto(autos, tAutos, marcas, tMarcas, colores, tColores);
                }
                break;
            case 3:
                if(flag == 1){
                    bajaAuto(autos, tAutos, marcas, tMarcas, colores, tColores);
                }
                break;
            case 4:
                if(flag == 1){
                    listarAutos(autos, tAutos, marcas, tMarcas, colores, tColores);
                }
                break;
            case 5:
                listarMarcas(marcas, tMarcas);
                break;
            case 6:
                listarColores(colores, tColores);
                break;
            case 7:
                listarServicios(servicios, tServicios);
                break;
            case 8:
                if(altaTrabajo(idTrabajo, trabajos, tTrabajo, autos, tAutos, servicios, tServicios, marcas, tMarcas, colores, tColores)){
                    idTrabajo++;
                }

                break;
            case 9:
                if(flag == 1){
                    listarTrabajos(trabajos, tTrabajo, servicios, tServicios);
                }
                break;
            case 10:
                printf("Confirma salir?:");
                fflush(stdin);
                salir = getchar();
                break;
            default:
                //
                break;
        }
        system("pause");
    }while(salir == 'n');


    return 0;
}

int menu(){
    int opcion;

    system("cls");
    printf("****** CAR WASH *******\n\n");
    printf("1-Alta auto\n");
    printf("2-Modificar auto\n");
    printf("3-Baja auto\n");
    printf("4-Listar autos\n");
    printf("5-Listar marcas\n");
    printf("6-Listar colores\n");
    printf("7-Listar servicios\n");
    printf("8-Alta trabajo\n");
    printf("9-Listar trabajos\n");
    printf("10-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

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



void listarServicio(Servicio x)
{
    printf("  %d  %15s\n",
           x.id,
           x.descripcion);
}

void listarServicios(Servicio vec[], int tam){
    int flag = 0;
    system("cls");

    printf(" ID                  COLOR\n");

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
                break;
            } else {
                fp = 1;
            }
        }
        while(fp == 0){
            printf("Patente falsa. ");
            printf("Ingrese patente: ");
            scanf("%d", &patente);
            for(int i = 0 ; i < tAutos ; i++){
                if(patente == vec[i].patente && vec[i].isEmpty == 0){
                    break;
                } else {
                    fp = 1;
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





void initTrabajo(Trabajo vec[], int tam)
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

