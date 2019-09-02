#include <stdio.h>
#include <stdlib.h>

void changeX(int*);

int main()
{
    int x;  //Cambio el valor de x desde otra funcion
    changeX(&x);

    printf("%d", x);
    return 0;
}

void changeX(int* puntero){
    int n;

    printf("Ingrese un numero: ");
    scanf("%d", &n);
    *puntero = n;
}
