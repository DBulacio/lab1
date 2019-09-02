#include <stdio.h>
#include <stdlib.h>
#include "bulacio.h"

int main()
{
    int n1, n2;
    printf("%d", getIntRange("Ingrese una nota: ", "ERROR. Ingrese una nota valida: ", 0, 10, 3, -1));

    return 0;
}



