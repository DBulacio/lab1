#include "alumno.h"
#include "comida.h"

#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED
typedef struct{
    int id;
    int legajo;
    int idComida;
    eFecha fecha;
    int isEmpty;
} eAlmuerzo;
#endif // ALMUERZO_H_INCLUDED

void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam);
int hardcodearAlmuerzo(eAlmuerzo almuerzos[], int tam, int cant);
void mostrarAlmuerzos(eAlmuerzo vec[], int tam,  eComida comidas[], int tamC);
void mostrarAlmuerzo(eAlmuerzo x, eComida comidas[], int tam);
eAlmuerzo newAlmuerzo(int id, int leg, int idComida, eFecha fecha);
int altaAlmuerzo(eAlmuerzo almuerzos[], int tAlmuerzo, int idAlmuerzo, eAlumno alumnos[], int tAlumno, eComida comidas[], int tComida, eCarrera carreras[], int tCarrera);
int buscarLibreAlmuerzo(eAlmuerzo vec[], int tam);
