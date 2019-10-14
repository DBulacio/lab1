#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}Marca;

#endif // MARCA_H_INCLUDED

void listarMarca(Marca x);
void listarMarcas(Marca vec[], int tam);
int cargarDescMarca(int id, Marca marcas[], int tam, char desc[]);
