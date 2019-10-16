#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}Marca;

#endif // MARCA_H_INCLUDED

/** \brief  recibe y muestra una marca especifica
 *
 * \param x Marca
 * \return void
 *
 */
void listarMarca(Marca x);

/** \brief recibe y muestra el array de marcas
 *
 * \param vec[] Marca
 * \param tam int
 * \return void
 *
 */
void listarMarcas(Marca vec[], int tam);

/** \brief recibe el id de marca y un vector de char. Pone la descripcion de la marca en ese vector
 *
 * \param id int
 * \param marcas[] Marca
 * \param tam int
 * \param desc[] char
 * \return int devuelve 1 si todoOk
 *
 */
int cargarDescMarca(int id, Marca marcas[], int tam, char desc[]);
