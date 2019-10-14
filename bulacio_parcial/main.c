#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autos.h"
#include "trabajo.h"
#include "servicio.h"
#include "marca.h"
#include "color.h"

int menu();

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
