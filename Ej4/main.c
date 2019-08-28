#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calcularSupCirculo(float r);

int main()
{
    float radio, superficie;

    printf("Ingrese el radio del circulo: ");
    fflush(stdin);
    scanf("%f", &radio);

    superficie = calcularSupCirculo(radio);
    printf("La superficie del circulo es: %f\n", superficie);

    return 0;
}

float calcularSupCirculo(float r){
// pi * r * r
    float s;

    s = M_PI * r * r;

    return s;
}
