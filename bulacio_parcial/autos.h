#include "color.h"
#include "marca.h"
#include "servicio.h"

#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED

typedef struct{
    int id;
    int patente;
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
}Auto;

#endif // AUTOS_H_INCLUDED

int altaAuto(int idAuto, Auto vec[], int tAutos, Marca marcas[], int tMarcas, Color colores[], int tColores);
Auto newAuto(int id, int patente, int idMarca, int idColor, int modelo);
void initAuto(Auto vec[], int tam);
int buscarLibre(Auto vec[], int tam);
void listarAuto(Auto x, Marca marcas[], int tMarcas, Color colores[], int tColores);
void listarAutos(Auto vec[], int tam, Marca marcas[], int tMarcas, Color colores[], int tColores);
int buscarAuto(int patente, Auto vec[], int tam);
int bajaAuto(Auto vec[], int tam, Marca marcas[], int tMarcas, Color colores[], int tColores);
void ordenarAuto(Auto vec[], int tam);
int modificarAuto(Auto vec[], int tam, Marca marcas[], int tMarcas, Color colores[], int tColores);
