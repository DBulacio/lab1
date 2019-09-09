#include <stdio.h>
#include <stdlib.h>

void mostrarVectorInt(int[], int);
void mostrarVectorChar(char[], int);
void mostrarVectorFloat(float[], int);

int main()
{
    int numeros[] = {23,21,43,54,28,21,66,88,32,50};
    char x[] = {'a', 'e', 'i', 'o', 'u'};
    float r[] = {1.2, 5.2, 2.97, 21.5, 75.6};

    mostrarVectorInt(numeros, 10);
    mostrarVectorChar(x, 5);
    mostrarVectorFloat(r, 5);

    return 0;
}

void mostrarVectorInt(int arr[], int tam){
    for(int i = 0 ; i < tam ; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

void mostrarVectorChar(char arr[], int tam){
    for(int i = 0 ; i < tam ; i++){
        printf("%c ", arr[i]);
    }
    printf("\n\n");
}

void mostrarVectorFloat(float arr[], int tam){
    for(int i = 0 ; i < tam ; i++){
        printf("%.2f ", arr[i]);
    }
    printf("\n\n");
}
