#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autos.h"
#include "trabajo.h"
#include "servicio.h"
#include "marca.h"
#include "color.h"

void mostrarAutosColorNegro(Auto autos[], int tAutos, Color colores[], int tColores, Marca marcas[], int tMarcas);
void mostrarAutosDeMarcaSeleccionada(Marca marcas[], int tMarcas, Auto autos[], int tAutos, Color colores[], int tColores);
void mostrarTrabajosParaAuto(Auto autos[], int tAutos, Marca marcas[], int tMarcas, Color colores[], int tColores, Trabajo trabajos[], int tTrabajos, Servicio servicios[], int tServicios);
void mostrarAutosEnceradosFecha(Auto autos[], int tAutos, Marca marcas[], int tMarcas, Color colores[], int tColores, Trabajo trabajos[], int tTrabajo);
void mostrarAutosSinTrabajo(Auto autos[], int tAutos, Trabajo trabajos[], int tTrabajos, Marca marcas[], int tMarcas, Color colores[], int tColores);
void mostrarImporteTrabajoAutoSeleccionado(Auto autos[], int tAutos, Marca marcas[], int tMarcas, Color colores[], int tColores, Trabajo trabajos[], int tTrabajos, Servicio servicios[], int tServicios);
void mostrarTrabajosAAutosBlancos(Trabajo trabajos[], int tTrabajos, Auto autos[], int tAutos, Servicio servicios[], int tServicios);
void mostrarFacturacionTotalPulidos(Trabajo trabajos[], int tTrabajo, Servicio servicios[]);
void mostrarTrabajosAutoFecha(Trabajo trabajos[], int tTrabajos, Auto autos[], int tAutos, Marca marcas[], int tMarcas, Color colores[], int tColores);
void mostrarRecaudacionEnFecha(Trabajo trabajos[], int tTrabajos, Servicio servicios[], int tServicios);

int menuInformes();
int menu();

int main()
{
    int tMarcas = 5;
    int tColores = 5;
    int tServicios = 4;
    int tAutos = 10;
    int tTrabajo = 10;
    int flag = 1;
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

    idAuto += hardcodearAutos(autos, tAutos, 5);
    idTrabajo += hardcodearTrabajos(trabajos, tTrabajo, 5);

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
                switch(menuInformes()){
                    case 1:
                        mostrarAutosColorNegro(autos, tAutos, colores, tColores, marcas, tMarcas);
                        break;
                    case 2:
                        mostrarAutosDeMarcaSeleccionada(marcas, tMarcas, autos, tAutos, colores, tColores);
                        break;
                    case 3:
                        mostrarTrabajosParaAuto(autos, tAutos, marcas, tMarcas, colores, tColores, trabajos, tTrabajo, servicios, tServicios);
                        break;
                    case 4:
                        mostrarAutosSinTrabajo(autos, tAutos, trabajos, tTrabajo, marcas, tMarcas, colores, tColores);
                        break;
                    case 5:
                        mostrarImporteTrabajoAutoSeleccionado(autos, tAutos, marcas, tMarcas, colores, tColores, trabajos, tTrabajo, servicios, tServicios);
                        break;
                    case 7:
                        //mostrarRecaudacionEnFecha(trabajos, tTrabajo, servicios, tServicios);
                        //break;
                    case 8:
                        mostrarAutosEnceradosFecha(autos, tAutos, marcas, tMarcas, colores, tColores, trabajos, tTrabajo);
                        break;
                    case 9:
                        mostrarTrabajosAAutosBlancos(trabajos, tTrabajo, autos, tAutos, servicios, tServicios);
                        break;
                    case 10:
                        mostrarFacturacionTotalPulidos(trabajos, tTrabajo, servicios);
                        break;
                    case 12:
                        mostrarTrabajosAutoFecha(trabajos, tTrabajo, autos, tAutos, marcas, tMarcas, colores, tColores);
                }
                break;
            case 11:
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
    printf("10-Menu Informes\n");
    printf("11-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuInformes(){
    int opcion;

    system("cls");
    printf("****** INFORMES *******\n\n");
    printf("1-Mostrar autos de color negro\n");
    printf("2-Mostrar autos de una marca seleccionada\n");
    printf("3-Mostrar trabajos de auto seleccionado\n");
    printf("4-Listar autos que no tuvieron trabajos\n");
    printf("5-Informar importe total de los trabajos de un auto seleccionado\n");
    printf("6-Mostrar servicio mas pedido\n");
    printf("7-Mostrar recaudacion en una fecha en particular\n");
    printf("8-Mostrar los autos que realizaron encerado y fecha\n");
    printf("9-Trabajos realizados a autos blancos\n");
    printf("10-Facturacion total por pulidos\n");
    printf("11-Informar la marca de autos que hicieron lavados completos\n");
    printf("12-Listar autos que recibieron trabajos en fechas determinada\n");
    printf("13-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void mostrarAutosColorNegro(Auto autos[], int tAutos, Color colores[], int tColores, Marca marcas[], int tMarcas){
    int flag = 0;

    for(int i = 0 ; i < tAutos ; i++){
        if(autos[i].idColor == 5000 && autos[i].isEmpty == 0){
            listarAuto(autos[i], marcas, tMarcas, colores, tColores);
            flag = 1;
        }
    }

    if(flag == 0){
        printf("No hay autos negros registrados.\n\n");
    }
    printf("\n\n");
}

void mostrarAutosDeMarcaSeleccionada(Marca marcas[], int tMarcas, Auto autos[], int tAutos, Color colores[], int tColores){
    int idMarca;
    int flag = 0;
    int sigue = 0;

    listarMarcas(marcas, tMarcas);
    printf("Ingrese idMarca: ");
    scanf("%d", &idMarca);
    for(int i = 0 ; i < tMarcas ; i++){
        if(idMarca == marcas[i].id){
            sigue = 1;
        }
    }
    while(sigue == 0){
        printf("ID Inexistente. Ingrese idMarca: ");
        scanf("%d", &idMarca);
        for(int i = 0 ; i < tMarcas ; i++){
            if(idMarca == marcas[i].id){
                sigue = 1;
            }
        }
    }

    for(int i = 0 ; i < tAutos ; i++){
        if(autos[i].idMarca == idMarca && autos[i].isEmpty == 0){
            listarAuto(autos[i], marcas, tMarcas, colores, tColores);
            flag = 1;
        }
    }

    if(flag == 0){
        printf("No hay autos registrados con esa marca.\n\n");
    }
    printf("\n\n");
}

void mostrarTrabajosParaAuto(Auto autos[], int tAutos, Marca marcas[], int tMarcas, Color colores[], int tColores, Trabajo trabajos[], int tTrabajos, Servicio servicios[], int tServicios){
    int patente;
    int flag = 0;
    int sigue = 0;

    listarAutos(autos, tAutos, marcas, tMarcas, colores, tColores);
    printf("Ingrese la patente: ");
    scanf("%d", &patente);
    for(int i = 0 ; i < tAutos ; i++){
        if(patente == autos[i].patente && autos[i].isEmpty == 0){
            sigue = 1;
        }
    }
    while(sigue == 0){
        printf("ERROR. Ingrese la patente: ");
        scanf("%d", &patente);
        for(int i = 0 ; i < tAutos ; i++){
            if(patente == autos[i].patente && autos[i].isEmpty == 0){
                sigue = 1;
            }
        }
    }

    for(int i = 0 ; i < tTrabajos ; i++){
        if(trabajos[i].patente == patente && trabajos[i].isEmpty == 0){
            listarTrabajo(trabajos[i], servicios, tServicios);
            flag = 1;
        }
    }

    if(flag == 0){
        printf("No hay trabajos registrados para ese auto.\n\n");
    }
}

void mostrarAutosEnceradosFecha(Auto autos[], int tAutos, Marca marcas[], int tMarcas, Color colores[], int tColores, Trabajo trabajos[], int tTrabajos){
    for(int i = 0 ; i < tTrabajos ; i++){
        if(trabajos[i].idServicio == 20002 && trabajos[i].isEmpty == 0){
            for(int j = 0 ; j < tAutos ; j++){
                if(autos[j].patente == trabajos[i].patente){
                    printf("%d/%d/%d", trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
                    listarAuto(autos[j], marcas, tMarcas, colores, tColores);
                }
            }
        }
    }
}

void mostrarAutosSinTrabajo(Auto autos[], int tAutos, Trabajo trabajos[], int tTrabajos, Marca marcas[], int tMarcas, Color colores[], int tColores){
    int found = 0;
    int flag = 0;

    for(int i = 0 ; i < tAutos ; i++){
        for(int j = 0 ; j < tTrabajos ; j++){
            if(autos[i].patente == trabajos[j].patente){
                found = 1;
            }
        }
        if(found == 0 && autos[i].isEmpty == 0){
            flag = 1;
            listarAuto(autos[i], marcas, tMarcas, colores, tColores);
        }
        found = 0;
    }

    if(flag == 1){
        printf("Todos los autos tienen trabajos registrados\n\n");
    }
}

void mostrarImporteTrabajoAutoSeleccionado(Auto autos[], int tAutos, Marca marcas[], int tMarcas, Color colores[], int tColores, Trabajo trabajos[], int tTrabajos, Servicio servicios[], int tServicios){
    int patente;
    int acumulado = 0;
    int flag = 0;
    int sigue = 0;

    listarAutos(autos, tAutos, marcas, tMarcas, colores, tColores);
    printf("Ingrese la patente: ");
    scanf("%d", &patente);
    for(int i = 0 ; i < tAutos ; i++){
        if(patente == autos[i].patente && autos[i].isEmpty == 0){
            sigue = 1;
        }
    }
    while(sigue == 0){
        printf("ERROR. Ingrese la patente: ");
        scanf("%d", &patente);
        for(int i = 0 ; i < tAutos ; i++){
            if(patente == autos[i].patente && autos[i].isEmpty == 0){
                sigue = 1;
            }
        }
    }

    for(int i = 0 ; i < tTrabajos ; i++){
        if(trabajos[i].patente == patente && trabajos[i].isEmpty == 0){
            // si existe un trabajo para esa patente
            flag = 1;
            for(int j = 0 ; j < tServicios ; j++){
                if(trabajos[i].idServicio == servicios[j].id){
                    acumulado += servicios[j].precio;
                }
            }
        }
    }

    if(flag == 0){
        printf("No hay trabajos registrados para ese auto\n\n");
    } else {
        printf("El precio acumulado es %d\n\n", acumulado);
    }
}
// 9 -------------
void mostrarTrabajosAAutosBlancos(Trabajo trabajos[], int tTrabajos, Auto autos[], int tAutos, Servicio servicios[], int tServicios){
    int flag = 0;

    for(int i = 0; i < tTrabajos ; i++){
        for(int j = 0 ; j < tAutos ; j++){
            if(trabajos[i].patente == autos[j].patente && trabajos[i].isEmpty == 0){
                if(autos[j].idColor == 5001){
                    listarTrabajo(trabajos[i], servicios, tServicios);
                }
            }
        }
    }
    if(flag == 0){
        printf("No hay trabajos registrados para autos blancos.\n\n");
    }
}
// 10 ----------
void mostrarFacturacionTotalPulidos(Trabajo trabajos[], int tTrabajo, Servicio servicios[]){
    int acumulado = 0;
    int flag = 0;

    for(int i = 0 ; i < tTrabajo ; i++){
        if(trabajos[i].idServicio == 20001 && trabajos[i].isEmpty == 0){
            acumulado += servicios[1].precio;
            flag = 1;
        }
    }
    if(flag == 0){
        printf("No hay pulidos registrados\n\n");
    } else {
        printf("Los pulidos acumularos: %d\n\n", acumulado);
    }
}
// 12 ---------
void mostrarTrabajosAutoFecha(Trabajo trabajos[], int tTrabajos, Auto autos[], int tAutos, Marca marcas[], int tMarcas, Color colores[], int tColores){
    Fecha fecha;
    int flag = 0;

    printf("Ingrese fecha (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

    for(int i = 0 ; i < tAutos; i++){
        for(int j = 0 ; j < tTrabajos ; j++){
            if(trabajos[j].fecha.dia == fecha.dia && trabajos[j].fecha.mes == fecha.mes && trabajos[j].fecha.anio == fecha.anio){
                if(trabajos[j].patente == autos[i].patente && trabajos[j].isEmpty == 0){
                    flag = 1;
                    listarAuto(autos[i], marcas, tMarcas, colores, tColores);
                }
            }
        }
    }

    if(flag == 0){
        printf("No hay trabajos registrados para esa fecha");
    }
}
// 7 ---------
/*
void mostrarRecaudacionEnFecha(Trabajo trabajos[], int tTrabajos, Servicio servicios[], int tServicios){
    Fecha fecha;
    int acumulado = 0;

    printf("Ingrese fecha (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

    for(int i = 0 ; i < tTrabajos ; i++){
        for(int j = 0 ; j < tServicios ; j++){
            if(trabajos[j].fecha.dia == fecha.dia && trabajos[j].fecha.mes == fecha.mes && trabajos[j].fecha.anio == fecha.anio){
                if(trabajos[i].idServicio == servicios[j].id && trabajos[i].isEmpty == 0){
                    acumulado += servicios[j].precio;
                }
            }
        }
    }
    printf("%d", acumulado);
}
*/
