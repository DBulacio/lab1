#include "autos.h"
#include "servicio.h"
#include "marca.h"
#include "color.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}Fecha;

typedef struct{
    int id;
    int patente;
    int idServicio;
    Fecha fecha;
    int isEmpty;
}Trabajo;

#endif // TRABAJO_H_INCLUDED

Trabajo newTrabajo(int id, int patente, int idServicio, Fecha fecha);
int altaTrabajo(int idTrabajo, Trabajo vec[], int tTrabajo, Auto autos[], int tAutos, Servicio servicios[], int tServicios, Marca marcas[], int tMarcas, Color colores[], int tColores);
int buscarLibreTrabajo(Trabajo vec[], int tam);
void initTrabajo(Trabajo vec[], int tam);
void listarTrabajo(Trabajo x, Servicio servicios[], int tServicios);
void listarTrabajos(Trabajo trabajos[], int tTrabajo, Servicio servicios[], int tServicios);
