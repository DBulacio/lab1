#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "carrera.h"
#include "alumno.h"
#include "almuerzo.h"
#include "comida.h"

#define TAM 10
#define TAMC 3
#define TAMCOM 5
#define TAMAL 20

int menu();
int menuInformes();
void InformesAlumnos(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, eAlmuerzo almuerzos[], int tamAl, eComida comidas[], int tamCom);
void mostrarAlumnosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void mostrarAlumnosCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, int idCarrera);
void mostrarAlumnosDeUnaCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void mostrarCantidadAlumnosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
int cantidadAlumnosCarrera(eAlumno alumnos[], int tam,int idCarrera);
void mejoresPromediosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void carreraMasCursada(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);

int compararFechas(eFecha f1, eFecha f2);

void mostrarAlmuerzosDeUnaFecha(eAlmuerzo almuerzos[], int tam, eComida comidas[], int tamC);
void mostrarAlumnosQueComieronDeterminadaComida(eAlmuerzo almuerzos[], int tAlmuerzo, eComida comidas[], int tComida, eAlumno alumnos[], int tAlumno, eCarrera carreras[], int tCarrera);


int main()
{
    int legajo = 20000;
    int idAlmuerzo = 60000;
    eCarrera carreras[TAMC]= {{1000,"TUP"},{1001,"TUSI"},{1002,"LIC"}};
    eComida comidas[TAMCOM] = {{5000,"Bife",250},{5001,"Fideos",180},{5002,"Pizza",200},{5003,"Arroz",160},{5004,"Milanesa",220}};
    eAlumno lista[TAM];
    eAlmuerzo almuerzos[TAMAL];
    char salir = 'n';

    inicializarAlumnos( lista, TAM);
    inicializarAlmuerzos(almuerzos, TAMAL);

    legajo += hardcodearAlumnos(lista, TAM, 9);
    idAlmuerzo += hardcodearAlmuerzo(almuerzos, TAMAL, 9);

    do
    {
        switch(menu())
        {
        case 1:
            if(altaAlumno(lista, TAM, legajo, carreras, TAMC))
            {
                legajo++;
            }
            break;
        case 2:
            bajaAlumno(lista, TAM, carreras, TAMC);
            break;
        case 3:
            ModificarAlumno(lista, TAM, carreras, TAMC);
            break;
        case 4:
            mostrarAlumnos(lista, TAM, carreras, TAMC);
            break;
        case 5:
            ordenarAlumnos(lista, TAM);
            break;
        case 6:
            InformesAlumnos(lista, TAM, carreras, TAMC, almuerzos, TAMAL, comidas, TAMCOM);
            break;
        case 7:
            mostrarCarreras(carreras, TAMC);
            break;
        case 8:
            mostrarComidas(comidas, TAMCOM);
            break;
        case 9:
            mostrarAlmuerzos(almuerzos, TAMAL, comidas, TAMCOM);
            break;
        case 10:
            if(altaAlmuerzo(almuerzos, TAMAL, idAlmuerzo, lista, TAM, comidas, TAMCOM, carreras, TAMC)){
                idAlmuerzo++;
            }
            break;
        case 11:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("****** ABM Alumnos *******\n\n");
    printf("1-Alta alumno\n");
    printf("2-Baja alumno\n");
    printf("3-Modificar alumno\n");
    printf("4-Listar alumnos\n");
    printf("5-Ordenar alumnos\n");
    printf("6-Informes alumno\n");
    printf("7-Mostrar Carreras\n");
    printf("8-Mostrar Comidas\n");
    printf("9-Mostrar Almuerzos\n");
    printf("10-Alta Almuerzo\n");
    printf("11-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuInformes()
{
    int opcion;

    system("cls");
    printf("****** Informes *******\n\n");
    printf("1-Mostrar Alumnos de una Carrera\n");
    printf("2-Mostrar Alumnos por Carrera\n");
    printf("3-Mostrar Cantidad de alumnos por Carrera\n");
    printf("4-Mostrar La Carrera con mas incriptos\n");
    printf("5-Mostrar Mejor Promedio por Carrera\n");
    printf("6-Mostrar Alumnos Varones\n");
    printf("7-Mostrar Mujeres de Alguna Carrera\n");
    printf("8-Mostrar Alumnos mayores a 30 de Licenciatura\n");
    printf("9-Mostrar Almuerzos de una fecha determinada\n");
    printf("10-Listar Alumnos que comieron una comida determinada\n");
    printf("11-Listar cantidad de almuerzo por carrera");
    printf("12-Carrera amante de la milanesa");
    printf("13-Informe deuda alumno seleccionado");
    printf("20-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

void InformesAlumnos(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, eAlmuerzo almuerzos[], int tamAl, eComida comidas[], int tamCom)
{
    char salir = 'n';
    system("cls");
    printf("***** Informes Alumnos ****\n\n");

    do
    {
        switch( menuInformes())
        {
        case 1:
            mostrarAlumnosDeUnaCarrera(alumnos, tam, carreras, tamC);
            break;
        case 2:
            mostrarAlumnosXCarrera(alumnos, tam, carreras, tamC);
            break;
        case 3:
            mostrarCantidadAlumnosXCarrera(alumnos, tam, carreras, tamC);
            break;
        case 4:
            carreraMasCursada(alumnos, tam, carreras, tamC);
            break;
        case 5:
            mejoresPromediosXCarrera(alumnos, tam, carreras, tamC);
            break;
        case 6:
            printf("Informe 6\n");
            break;
        case 7:
            printf("Informe 7\n");
            break;
        case 8:
            printf("Informe 7\n");
            break;
        case 9:
            mostrarAlmuerzosDeUnaFecha(almuerzos, tamAl, comidas, tamCom);
            break;
        case 10:
            mostrarAlumnosQueComieronDeterminadaComida(almuerzos, tamAl, comidas, tamCom, alumnos, tam, carreras, tamC);
            break;
        case 20:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getchar();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');
}



void mostrarAlumnosDeUnaCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{
    // aca mostramos carreras y obtenemos el idCarrera
    // y llamamos a mostrarAlumnosCarrera
    int idCarrera;
    system("cls");
    printf("***Carreras***\n\n");
    mostrarCarreras(carreras, tamC);
    printf("Ingrese id carrera: ");
    scanf("%d", &idCarrera);
    mostrarAlumnosCarrera(alumnos, tam, carreras, tamC, idCarrera);

}

void mostrarAlumnosCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, int idCarrera)
{
    char desc[20];
    int flag = 0;
    cargarDescCarrera(idCarrera, carreras, 20,desc);

    printf("Carrera: %s\n\n", desc);

    for(int i=0; i < tam; i++)
    {
        if( alumnos[i].isEmpty == 0 && alumnos[i].idCarrera == idCarrera)
        {
            mostrarAlumno(alumnos[i], carreras, tamC);
            flag = 1;
        }
    }
    if( flag == 0)
    {
        printf("No hay Alumnos cursando %s", desc);
    }
    printf("\n\n");
}

void mostrarAlumnosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{

    system("cls");
    printf("***Listado de Alumnos por Carrera***\n\n");

    for(int i=0; i < tamC; i++)
    {
        mostrarAlumnosCarrera(alumnos, tam, carreras, tamC, carreras[i].id);
    }

    printf("\n\n");
}

void mostrarCantidadAlumnosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{

    int contador = 0;
    char desc[20];

    system("cls");
    printf("***Cantidad de Alumnos por Carrera***\n\n");

    // Recorro vector de carreras
    for(int i=0; i < tamC; i++)
    {
        cargarDescCarrera(carreras[i].id, carreras, tamC,desc);
        printf("Carrera: %s\n\n", desc);

        for(int j= 0; j < tam; j++)
        {
            if( alumnos[j].isEmpty == 0 && alumnos[j].idCarrera == carreras[i].id)
            {
                contador++;
            }
        }
        printf("Cantidad: %d\n\n", contador);
        contador = 0;
    }
    printf("\n\n");
}

int cantidadAlumnosCarrera(eAlumno alumnos[], int tam,int idCarrera)
{
    int cant = 0;

    for(int i= 0; i < tam; i++ )
    {
        if(alumnos[i].isEmpty == 0 && alumnos[i].idCarrera == idCarrera)
        {
            cant++;
        }
    }
    return cant;
}

void carreraMasCursada(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{

    int cantidades[tamC];
    int mayor;
    int flag = 0;
    char desc[20];

    for( int i=0; i < tamC; i++)
    {
        cantidades[i] = cantidadAlumnosCarrera(alumnos, tam, carreras[i].id);
    }


    for(int i=0; i < tamC; i++)
    {
        if( mayor < cantidades[i] || flag==0)
        {
            mayor = cantidades[i];
            flag = 1;
        }
    }

    for(int i=0; i < tamC; i++)
    {
        if( cantidades[i]== mayor)
        {

            cargarDescCarrera( carreras[i].id, carreras, tamC, desc);
            printf("Carrera: %s %d alumnos\n", desc, mayor);

        }
    }
}

void mejoresPromediosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC){

    char desc[20];
    float mayor;
    int flag = 0;
    system("cls");
    printf("***Mejores Promedios por Carrera***\n\n");

    for( int i=0; i < tamC; i++){
         cargarDescCarrera(carreras[i].id, carreras, tamC,desc);
         printf("Carrera: %s\n\n", desc);

         for(int j=0; j < tam; j++){
            if((mayor < alumnos[j].promedio && alumnos[j].isEmpty == 0 && alumnos[j].idCarrera == carreras[i].id) || ( flag == 0  && alumnos[j].idCarrera == carreras[i].id)){
                mayor = alumnos[j].promedio;
                flag = 1;
            }
         }

         printf("Promedio: %.2f\n\n", mayor);
         mayor = 0;
         flag = 0;
    }
}

void mostrarAlmuerzosDeUnaFecha(eAlmuerzo almuerzos[], int tam, eComida comidas[], int tamC){
    eFecha fecha;
    int flag = 0;

    printf("Ingrese la fecha: ");
    scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

    for(int i = 0 ; i < tam ; i++){
        if(almuerzos[i].isEmpty == 0 && compararFechas(fecha, almuerzos[i].fecha)){
            flag = 1;
            mostrarAlmuerzo(almuerzos[i], comidas, tamC);
        }
    }

    if(flag == 0){
        printf("No hay almuerzos que mostrar con la fecha indicada");
    }
}

void mostrarAlumnosQueComieronDeterminadaComida(eAlmuerzo almuerzos[], int tAlmuerzo, eComida comidas[], int tComida, eAlumno alumnos[], int tAlumno, eCarrera carreras[], int tCarrera){
    int idComida;
    int flag = 0;

    mostrarComidas(comidas, tComida);

    printf("Ingrese el id de la comida: ");
    scanf("%d", &idComida);

    for(int i = 0 ; i < tAlmuerzo ; i++){
        if(almuerzos[i].isEmpty == 0 && idComida == almuerzos[i].idComida){
            flag = 1;
            for(int j = 0 ; j < tAlumno ; j++){
                if(alumnos[j].isEmpty == 0 && almuerzos[i].legajo == alumnos[j].legajo){
                    mostrarAlumno(alumnos[j], carreras, tCarrera);
                }
            }
        }
    }
    if(flag == 0){
        printf("No existe ese id de comida");
    }
}

int compararFechas(eFecha f1, eFecha f2){
    int sonIguales = 0;

    if(f1.dia == f2.dia && f1.mes == f2.mes && f1.anio == f2.anio){
        sonIguales = 1;
    }

    return sonIguales;
}

// FALTA A PARTIR DE ACA!!!!!!!!!!!!!!!!!&&&&&&&&&&&&&&&&&%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%&&&&&&&&&&&&&&&&&&&&&&&&&
//%%%%%%%%%%%%%%%%&&&&&&&&&&&&&&&&&&&&&&&

void mostrarCantidadAlmuerzosXCarrera(){
system("cls");
    printf("***Listado de Almuerzos por Carrera***\n\n");

    for(int i=0; i < tamC; i++)
    {
        mostrarAlumnosCarrera(alumnos, tam, carreras, tamC, carreras[i].id);
    }

    printf("\n\n");
}

void mostrarAlmuerzosCarrera(eAlmuerzo almuerzo[], int tam, eCarrera carreras[], int tamC, int idCarrera)
{
    char desc[20];
    int flag = 0;
    cargarDescCarrera(idCarrera, carreras, 20,desc);

    printf("Carrera: %s\n\n", desc);

    for(int i=0; i < tam; i++)
    {
        if( almuerzo[i].isEmpty == 0 && almuerzo[i].idCarrera == idCarrera)
        {
            mostrarAlumno(alumnos[i], carreras, tamC);
            flag = 1;
        }
    }
    if( flag == 0)
    {
        printf("No hay Alumnos cursando %s", desc);
    }
    printf("\n\n");
}
