#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
    int id;
    char nombreColor[20];
}Color;

#endif // COLOR_H_INCLUDED


void listarColor(Color x);
void listarColores(Color vec[], int tam);
int cargarDescColor(int id, Color colores[], int tam, char desc[]);
