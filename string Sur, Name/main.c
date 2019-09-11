#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nombre[20];
    char apellido[20];
    char nombreCompleto[41];
    char auxCad[100];

    printf("Ingrese un nombre: ");
    fflush(stdin);
    gets(auxCad);
    while(strlen(auxCad) > 18){
        printf("ERROR: nombre demasiado largo. Ingreselo nuevamente: ");
        fflush(stdin);
        gets(auxCad);
    }
    strcpy(nombre, auxCad);

    printf("Ingrese un apellido: ");
    fflush(stdin);
    gets(auxCad);
    while(strlen(auxCad) > 18){
        printf("ERROR: apellido demasiado largo. Ingreselo nuevamente: ");
        fflush(stdin);
        gets(auxCad);
    }
    strcpy(apellido, auxCad);

    strcpy(nombreCompleto, apellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, nombre);

    strlwr(nombreCompleto);
    nombreCompleto[0] = toupper(nombreCompleto[0]);

    int i = 0;
    while(nombreCompleto[i] != '\0'){
        if(nombreCompleto[i] == ' '){
            nombreCompleto[i + 1] = toupper(nombreCompleto[i + 1]);
        }
        i++;
    }

    puts(nombreCompleto);

    return 0;
}
