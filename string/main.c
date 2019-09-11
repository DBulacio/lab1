#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[10];
    char auxCad[100];

    printf("Ingrese nombre: ");
    gets(auxCad);

    while(strlen(auxCad) > 9){
        printf("ERROR: nombre demasiado largo. Ingreselo nuevamente: ");
        gets(auxCad);
    }
    strcpy(nombre, auxCad);
    // strcpy(nombre, auxCad, 9);

    printf("%s\n", nombre);

    /*
    char n1[10] = "Juan";
    char n2[10] = "Juana";
    int x;

    // Si el primero es mas chico devuelve -1
    // Si son iguales devuelve 0
    // Si el primero es mas grande devuelve 1
    x = strcmp(n1, n2);

    // No es case sensitive
    x = stricmp(n1, n2);

    // Concatenar dos cadenas
    strcat(n1, n2);

    // Toda la cadena a mayuscula o minuscula
    strupr(n1);
    strlwr(n2);
    */
    return 0;
}
