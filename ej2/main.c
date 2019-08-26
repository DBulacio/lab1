#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Pedir nombre, sexo y nota hasta que el usuario quiera. Informar:
// Nombre y sexo de la mejor y peor nota
// Promedio de notas totales
// Promedio de notas de mujeres
int main()
{
    char nombre[20], peorNombre[20], mejorNombre[20];
    char sexo, rta, peorSexo, mejorSexo;
    int nota, mejorNota = 0, peorNota = 0, sumNotas = 0, sumNotasF = 0;
    int flag = 0, contf = 0;
    float prom, promf;

    do {
        printf("Ingrese un nombre: ");
        scanf("%s", &nombre);
        fflush(stdin);

        do {
            printf("Ingrese el sexo (m/f): ");
            scanf("%c", &sexo);
            fflush(stdin);
        } while (sexo != 'f' && sexo != 'm');

        do {
            printf("Ingrese la nota (1-10): ");
            scanf("%d", &nota);
            fflush(stdin);
        } while (nota > 10 || nota < 0);


        if (nota < peorNota || flag == 0){
            peorNota = nota;
            strcpy(peorNombre, nombre);
            peorSexo = sexo;
        }
        if (nota > mejorNota || flag == 0){
            mejorNota = nota;
            strcpy(mejorNombre, nombre);
            mejorSexo = sexo;
        }

        sumNotas += nota;

        if (sexo == 'f') {
            sumNotasF += nota;
            contf++;
        }

        printf("Continuar ingresando datos? (y/n): ");
        scanf("%c", &rta);
        // rta = getch();
        // rta = getche();
        fflush(stdin);
        flag++;
    } while(rta == 'y');

    printf("El la nombre persona con la peor nota es %s, de sexo %c, con un %d.\n", peorNombre, peorSexo, peorNota);
    printf("El la nombre persona con la mejor nota es %s, de sexo %c, con un %d.\n", mejorNombre, mejorSexo, mejorNota);

    prom = (float) sumNotas / flag;
    printf("El promedio de las notas totales es %.2f.\n", prom);

    if (contf != 0){
        promf = (float) sumNotasF / contf;
        printf("El promedio de las notas totales de las mujeres es %.2f.\n", promf);
    }

    return 0;
}
