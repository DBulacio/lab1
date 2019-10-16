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

/** \brief Recibe por parametro los datos pedidos en altaTrabajo() y devuelve el trabajo.
 *
 * \param id int
 * \param patente int
 * \param idServicio int
 * \param fecha Fecha
 * \return Trabajo
 *
 */
Trabajo newTrabajo(int id, int patente, int idServicio, Fecha fecha);

/** \brief Pido todos los datos para el trabajo
 *
 * \param idTrabajo int
 * \param vec[] Trabajo
 * \param tTrabajo int
 * \param autos[] Auto
 * \param tAutos int
 * \param servicios[] Servicio
 * \param tServicios int
 * \param marcas[] Marca
 * \param tMarcas int
 * \param colores[] Color
 * \param tColores int
 * \return int devuelvo 1 si todo Ok
 *
 */
int altaTrabajo(int idTrabajo, Trabajo vec[], int tTrabajo, Auto autos[], int tAutos, Servicio servicios[], int tServicios, Marca marcas[], int tMarcas, Color colores[], int tColores);

/** \brief busca una posicion libre en el array de trabajos
 *
 * \param vec[] Trabajo
 * \param tam int
 * \return int devuelvo la primer posicion libre del array
 *
 */
int buscarLibreTrabajo(Trabajo vec[], int tam);

/** \brief Inicializa las posiciones del array de trabajos para que esten vacios.
 *
 * \param vec[] Trabajo
 * \param tam int
 * \return void
 *
 */
void initTrabajo(Trabajo vec[], int tam);

/** \brief recibe y muestra un trabajo en especifico
 *
 * \param x Trabajo
 * \param servicios[] Servicio
 * \param tServicios int
 * \return void
 *
 */
void listarTrabajo(Trabajo x, Servicio servicios[], int tServicios);

/** \brief recibe y muestra el array de trabajos
 *
 * \param trabajos[] Trabajo
 * \param tTrabajo int
 * \param servicios[] Servicio
 * \param tServicios int
 * \return void
 *
 */
void listarTrabajos(Trabajo trabajos[], int tTrabajo, Servicio servicios[], int tServicios);

/** \brief hardcodea un listado de trabajos
 *
 * \param trabajos[] Trabajo
 * \param tTrabajos int
 * \param cant int
 * \return int
 *
 */
int hardcodearTrabajos(Trabajo trabajos[], int tTrabajos, int cant);
