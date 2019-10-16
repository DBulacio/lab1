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

/** \brief Pido todos los datos para el auto y devuelvo 1 si se pudo hacer correctamente el alta
 *
 * \param idAuto int Recibo el id por parametro y es autoincremental
 * \param vec[] Auto
 * \param tAutos int
 * \param marcas[] Marca
 * \param tMarcas int
 * \param colores[] Color
 * \param tColores int
 * \return int 1 si todo OK, 0 si error
 *
 */
int altaAuto(int idAuto, Auto vec[], int tAutos, Marca marcas[], int tMarcas, Color colores[], int tColores);

/** \brief Recibe por parametro los datos pedidos en altaAuto() y devuelve el auto.
 *
 * \param id int
 * \param patente int
 * \param idMarca int
 * \param idColor int
 * \param modelo int
 * \return Auto
 *
 */
Auto newAuto(int id, int patente, int idMarca, int idColor, int modelo);

/** \brief Inicializa las posiciones del array de autos para que esten vacios.
 *
 * \param vec[] Auto
 * \param tam int
 * \return void
 *
 */
void initAuto(Auto vec[], int tam);

/** \brief Busca una posicion libre en el array de autos
 *
 * \param vec[] Auto
 * \param tam int
 * \return int devuelvo la primer posicion libre del array
 *
 */
int buscarLibre(Auto vec[], int tam);

/** \brief Recibe y muestra un auto en particular
 *
 * \param x Auto
 * \param marcas[] Marca
 * \param tMarcas int
 * \param colores[] Color
 * \param tColores int
 * \return void
 *
 */
void listarAuto(Auto x, Marca marcas[], int tMarcas, Color colores[], int tColores);

/** \brief Recibe y muestra el array de autos ordenados por marca y patente
 *
 * \param vec[] Auto
 * \param tam int
 * \param marcas[] Marca
 * \param tMarcas int
 * \param colores[] Color
 * \param tColores int
 * \return void
 *
 */
void listarAutos(Auto vec[], int tam, Marca marcas[], int tMarcas, Color colores[], int tColores);

/** \brief busca un auto especifico en el array de autos
 *
 * \param patente int
 * \param vec[] Auto
 * \param tam int
 * \return int devuelve el indice del array donde esta ese auto
 *
 */
int buscarAuto(int patente, Auto vec[], int tam);

/** \brief coloca el isEmpty en 1.
 *
 * \param vec[] Auto
 * \param tam int
 * \param marcas[] Marca
 * \param tMarcas int
 * \param colores[] Color
 * \param tColores int
 * \return int devuelve 1 si todoOk
 *
 */
int bajaAuto(Auto vec[], int tam, Marca marcas[], int tMarcas, Color colores[], int tColores);

/** \brief ordena el array de autos por marca y patente
 *
 * \param vec[] Auto
 * \param tam int
 * \return void
 *
 */
void ordenarAuto(Auto vec[], int tam);

/** \brief modifica el color o la marca de un auto ya registrado
 *
 * \param vec[] Auto
 * \param tam int
 * \param marcas[] Marca
 * \param tMarcas int
 * \param colores[] Color
 * \param tColores int
 * \return int devuelve 1 si todoOk
 *
 */
int modificarAuto(Auto vec[], int tam, Marca marcas[], int tMarcas, Color colores[], int tColores);

/** \brief hardcodea un listado de autos
 *
 * \param autos[] Auto
 * \param tAutos int
 * \param cant int
 * \return int
 *
 */
int hardcodearAutos(Auto autos[], int tAutos, int cant);
