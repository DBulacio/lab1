#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    char nombre[20];
    char sexo;
    int legajo;
    int edad;
    int nota1;
    int nota2;
    float promedio;
    eFecha fechaIngreso;
}eAlumno;

int main()
{
    // HARDCODEO
    //eAlumno alumno = {"Daniel", 'm', 1610, 21, 10, 9, 9.5, {5, 8, 1998}};
    eAlumno alumno;

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(alumno.nombre);

    printf("Ingrese legajo: ");
    scanf("%d", &alumno.legajo);

    printf("Ingrese edad: ");
    scanf("%d", &alumno.edad);

    printf("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c", &alumno.sexo);

    printf("Ingrese nota primer parcial: ");
    scanf("%d", &alumno.nota1);

    printf("Ingrese nota segundo parcial: ");
    scanf("%d", &alumno.nota2);

    alumno.promedio = (float) (alumno.nota1 + alumno.nota2) / 2;

    printf("Ingrese el dia de ingreso: ");
    scanf("%d", &alumno.fechaIngreso.dia);

    printf("Ingrese el mes de ingreso: ");
    scanf("%d", &alumno.fechaIngreso.mes);

    printf("Ingrese el anio de ingreso: ");
    scanf("%d", &alumno.fechaIngreso.anio);

    printf("NOMBRE: %s\nLEGAJO: %d\nEDAD: %d\nSEXO: %c\nNOTA 1: %d\nNOTA 2: %d\nPROMEDIO: %.2f\nFECHA DE INGRESO: %02d/%02d/%d\n\n",
           alumno.nombre, alumno.legajo, alumno.edad, alumno.sexo, alumno.nota1, alumno.nota2, alumno.promedio, alumno.fechaIngreso.dia, alumno.fechaIngreso.mes, alumno.fechaIngreso.anio);

    return 0;
}
