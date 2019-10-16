#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[25];
    int precio;
}Servicio;

#endif // SERVICIO_H_INCLUDED

/** \brief recibe y muestra un servicio en particular
 *
 * \param x Servicio
 * \return void
 *
 */
void listarServicio(Servicio x);

/** \brief recibe y muestra el array de servicios
 *
 * \param vec[] Servicio
 * \param tam int
 * \return void
 *
 */
void listarServicios(Servicio vec[], int tam);

/** \brief recibe el id del servicio y un vector de char. Pone la descripcion del servicio en ese vector
 *
 * \param id int
 * \param servicios[] Servicio
 * \param tam int
 * \param desc[] char
 * \return int devuelve 1 si todoOk
 *
 */
int cargarDescServicio(int id, Servicio servicios[], int tam, char desc[]);
