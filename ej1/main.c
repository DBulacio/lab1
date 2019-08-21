#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    int num       = 2019;     //%d
    float precio  = 1,75;     //%.2f
    char letra    = 'A';      //%c
    char name[20] = "Juan";   //%s

    printf("Estamos en el anio %d\n", num.);
    return 0;
    */
    /*
    char name[20];
    int edad;

    printf("Ingrese su nombre: ");
    gets(name);
    printf("Ingrese su edad: ");
    fflush(stdin);  // limpiar el buffer
    scanf("%d", &edad);

    printf("Usted se llama %s y tiene %d anios\n", name, edad);
    return 0;
    */
    // ingresar 5 numeros, mostrarlos y mostrar el promedio
    int num, sum_num = 0;
    float prom;

    for(int i = 0 ; i < 5 ; i++){       // para poder declarar la var aca, cambiar el compilador al del 99
        printf("Ingrese un numero: ");
        scanf("%d", &num);
        sum_num += num;
    }
    prom = (float) sum_num / 5;      //casteo
    printf("La suma de los numeros es %d y el promedio es %.2f\n", sum_num, prom);
    return 0;

    // Parsear es convertir un dato no numerico en numerico.
    // Castear es convertir un dato numerico a otro tipo de dato numerico.
}
