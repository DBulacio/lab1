#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fIngreso;
}eEmpleado;

eEmpleado* intiEmpleado();
int mostrarEmpleado(eEmpleado* emp);

eEmpleado* newEmpleado(int leg, char* nombre, char sexo, float sueldo, int dia, int mes, int anio);
int agregarEmpleado(eEmpleado* arr, int* tam, eEmpleado* emp);
int mostrarEmpleados(eEmpleado* arr, int tam);

int main()
{
    eEmpleado* pEmp;
    eEmpleado* pEmp1;
    eEmpleado* pEmp2;
    eEmpleado* pEmp3;
    eEmpleado* pEmp4;
    eEmpleado* lista = (eEmpleado*) malloc(sizeof(eEmpleado));   // array de empleados
    int tam = 0;

    if(lista == NULL){
        printf("No se pudo conseguir lugar");
        exit(EXIT_FAILURE);
    }
    // si sali del if, tengo lugar
    pEmp  = newEmpleado(1234, "Jorge",  'm', 25000, 12, 5, 2010);
    pEmp1 = newEmpleado(1234, "Juana",  'f', 25000, 12, 5, 2010);
    pEmp2 = newEmpleado(1234, "Matias", 'm', 25000, 12, 5, 2010);
    pEmp3 = newEmpleado(1234, "Ana",    'f', 25000, 12, 5, 2010);
    pEmp4 = newEmpleado(1234, "Miguel", 'm', 25000, 12, 5, 2010);

    if(agregarEmpleado(lista, &tam, pEmp)){
        printf("Empleado registrado!\n");
    } else {
        printf("No se registro el empleado\n");
    }
    agregarEmpleado(lista, &tam, pEmp1);
    //agregarEmpleado(lista, &tam, pEmp2);
    //agregarEmpleado(lista, &tam, pEmp3);
    //agregarEmpleado(lista, &tam, pEmp4);

    mostrarEmpleados(lista, tam);  // no le paso &lista porque queremos la direccion de la estructura

    free(pEmp); // liberamos la memoria antes de terminar
    return 0;
}

eEmpleado* initEmpleado(){
    eEmpleado* p;

    p = (eEmpleado*) malloc(sizeof(eEmpleado)); // malloc devuelve void* entonces lo casteamos a eEmpleado*

    if(p != NULL){
        p->legajo = 0;
        strcpy(p->nombre, "Undefined");
        p->sexo = 'x';
        p->sueldo = 0;
        p->fIngreso = (eFecha) {1,1,1990};
    }

    return p;   // devuelve el espacio en memoria o NULL si hubo error,
}

int mostrarEmpleado(eEmpleado* emp){ // puede ser que el empleado que reciba sea null, por eso no es void y es int
    int todoOk = 0;

    if(emp != NULL){
        printf("%d   %s   %c   %.2f   %02d/%02d/%d\n", emp->legajo, emp->nombre, emp->sexo, emp->sueldo, emp->fIngreso.dia, emp->fIngreso.mes, emp->fIngreso.anio);
        todoOk = 1;
    }

    return todoOk;
}

int mostrarEmpleados(eEmpleado* arr, int tam){
    int todoOk = 0;

    if(arr != NULL){
        for(int i = 0 ; i < tam ; i++){
            mostrarEmpleado(arr + i);
        }
        todoOk = 1;
    }

    return todoOk;
}

eEmpleado* newEmpleado(int leg, char* nombre, char sexo, float sueldo, int dia, int mes, int anio){
    eEmpleado* p;

    p = initEmpleado(); // me fijo que no sea null e inicializo todo en 0
    if(p != NULL){
        p->legajo = leg;
        strcpy(p->nombre, nombre);
        p->sexo = sexo;
        p->sueldo = sueldo;
        p->fIngreso.dia = dia;
        p->fIngreso.mes = mes;
        p->fIngreso.anio = anio;
    }
    return p;
}
/*
int agregarEmpleado(eEmpleado* arr, int* tam, eEmpleado* emp){
    int todoOk = 0;
    int flag = 0;
    eEmpleado* aux;     // creo un auxiliar por si el nuevo lugar da NULL, asi no pierdo los datos que ya tenia

    if(arr != NULL && emp != NULL && tam != NULL){
        *(arr + *tam) = *emp;
        if(flag == 0){
            (*tam)++;
            flag = 1;
        }
        aux = (eEmpleado*) realloc(arr, sizeof(eEmpleado) * (*tam + 1));
        if(aux != NULL){
            arr = aux;
            (*tam)++;
            todoOk = 1;
        }
    }

    return todoOk;
}
*/
int agregarEmpleado(eEmpleado* arr, int* tam, eEmpleado* emp){
    int todoOk = 0;
    eEmpleado* aux;
    int nuevoTam = *tam + 1;

    if(arr != NULL && emp != NULL && tam != NULL){
        *(arr + (*tam)) = *emp;

        aux = (eEmpleado*) realloc(arr, sizeof(eEmpleado) * (nuevoTam + 1));
        if(aux != NULL){
            arr = aux;
            (*tam)++;
            todoOk = 1;
        }
    }

    return todoOk;
}
