#include <stdio.h>
#include <stdlib.h>

int buscarNumero(int, int[], int);

int main()
{
    int numeros[] = {1,5,3,2,4,8,6,3,5,2};
    int esta;

    esta = buscarNumero(5, numeros, 10);

    if(esta == 1){
        printf("Esta\n");
    } else {
        printf("No esta\n");
    }

    return 0;
}

int buscarNumero(int num, int vec[], int tam){
    int retorno;

    for(int i = 0 ; i < tam ; i++){
        if(vec[i] == num){
            retorno = 1;
            break;
        } else {
            retorno = 0;
        }
    }
    return retorno;
}
