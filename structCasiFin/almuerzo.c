#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "almuerzo.h"

void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam){
    for(int i = 0; i < tam; i++)
    {
        almuerzos[i].isEmpty = 1;
    }
}

int hardcodearAlmuerzo(eAlmuerzo almuerzos[], int tam, int cant){
    int cont = 0;

    eAlmuerzo suplentes[]=
    {
        { 60000, 20005, 5004, {30,9,2019}, 0},
        { 60001, 20003, 5000, {30,9,2019}, 0},
        { 60002, 20001, 5004, {30,9,2019}, 0},
        { 60003, 20000, 5002, {30,9,2019}, 0},
        { 60004, 20004, 5003, {30,9,2019}, 0},
        { 60005, 20005, 5004, {1,10,2019}, 0},
        { 60006, 20003, 5004, {1,10,2019}, 0},
        { 60007, 20006, 5001, {1,10,2019}, 0},
        { 60008, 20000, 5002, {1,10,2019}, 0},
        { 60009, 20005, 5004, {2,10,2019}, 0},
        { 60010, 20001, 5000, {2,10,2019}, 0}
    };

    if( cant <= 10 && tam >= cant)
    {
        for(int i=0; i < cant; i++)
        {

            almuerzos[i] = suplentes[i];
            cont++;
        }
    }
    return cont;
}

void mostrarAlmuerzo(eAlmuerzo x, eComida comidas[], int tam)
{
    char descComida[20];

    cargarDescComida(x.idComida, comidas, tam, descComida);
    printf("  %d  %d   %10s   %02d/%02d/%d\n",
           x.id,
           x.legajo,
           descComida,
           x.fecha.dia,
           x.fecha.mes,
           x.fecha.anio);
}

void mostrarAlmuerzos(eAlmuerzo vec[], int tam,  eComida comidas[], int tamC)
{

    int flag = 0;
    system("cls");
    printf("**** LISTADO ALMUERZOS ****\n\n");

    printf(" idAlmuerzo    Legajo    Comida   Fecha\n\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarAlmuerzo(vec[i], comidas, tamC);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay almuerzos que mostrar\n");
    }

    printf("\n\n");
}

int altaAlmuerzo(eAlmuerzo almuerzos[], int tAlmuerzo, int idAlmuerzo, eAlumno alumnos[], int tAlumno, eComida comidas[], int tComida, eCarrera carreras[], int tCarrera)
{
    int todoOk = 0;
    int indice;
    int legajo;
    int idComida;
    eFecha fecha;

    system("cls");

    printf("*****Alta Almuerzo*****\n\n");

    indice = buscarLibreAlmuerzo(almuerzos, tAlmuerzo);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        mostrarAlumnos(alumnos, tAlumno, carreras, tCarrera);
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        mostrarComidas(comidas, tComida);
        printf("Ingrese el id de la comida: ");
        scanf("%d", &idComida);

        printf("Ingrese fecha del almuerzo: ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

        almuerzos[indice] = newAlmuerzo(idAlmuerzo, legajo, idComida, fecha);
        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

    return todoOk;
}

eAlmuerzo newAlmuerzo(
    int id,
    int leg,
    int idComida,
    eFecha fecha
    )
{

    eAlmuerzo al;
    al.id = id;
    al.legajo = leg;
    al.idComida = idComida;
    al.fecha = fecha;
    al.isEmpty = 0;

    return al;
}

int buscarLibreAlmuerzo(eAlmuerzo vec[], int tam)
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
