#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void mostrarVectorInt(int vec[], int tam);
void ordenarVectorInt(int vec[], int tam, int criterio);

int main()
{
    int crit;
    int vec[TAM] = {7, 5, 8, 1, 3};

    printf("Vector sin ordenar\n\n");
    mostrarVectorInt(vec, TAM);

    printf("Ingrese 0 para ascendente y 1 para descendente: ");
    scanf("%d", &crit);

    ordenarVectorInt(vec, TAM, crit);

    printf("Vector Ordenado\n\n");
    mostrarVectorInt(vec, TAM);

    return 0;
}

void mostrarVectorInt(int vec[], int tam){

    for( int i=0; i < tam; i++){
        printf("%d ", vec[i]);
    }
    printf("\n\n");
}

void ordenarVectorInt(int vec[], int tam, int criterio){
    int aux;
    if(criterio == 1){      //ascendente
        printf("CRITERIO DESCENDENTE\n\n");
        for(int i = 0; i < TAM-1; i++){
            for(int j = i + 1; j < TAM; j++){
                if( vec[j] < vec[i]){
                    aux = vec[j];
                    vec[j] = vec[i];
                    vec[i] = aux;
                }
            }
        }
    } else {                // descendente
        printf("CRITERIO ASCENDENTE\n\n");
        for(int i = 0; i < TAM-1; i++){
            for(int j = i + 1; j < TAM; j++){
                if( vec[j] > vec[i]){
                    aux = vec[j];
                    vec[j] = vec[i];
                    vec[i] = aux;
                }
            }
        }
    }
}
