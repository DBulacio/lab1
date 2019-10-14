#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[25];
    int precio;
}Servicio;

#endif // SERVICIO_H_INCLUDED

void listarServicio(Servicio x);
void listarServicios(Servicio vec[], int tam);
int cargarDescServicio(int id, Servicio servicios[], int tam, char desc[]);
