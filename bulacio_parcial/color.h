#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
    int id;
    char nombreColor[20];
}Color;

#endif // COLOR_H_INCLUDED


/** \brief Recibe y muestra un color especifico
 *
 * \param x Color
 * \return void
 *
 */
void listarColor(Color x);

/** \brief recibe y muestra el array de colores
 *
 * \param vec[] Color
 * \param tam int
 * \return void
 *
 */
void listarColores(Color vec[], int tam);

/** \brief recibe el id del color y un vector de char. Pone la descripcion del color en ese vector
 *
 * \param id int
 * \param colores[] Color
 * \param tam int
 * \param desc[] char
 * \return int devuelve 1 si todoOk
 *
 */
int cargarDescColor(int id, Color colores[], int tam, char desc[]);
