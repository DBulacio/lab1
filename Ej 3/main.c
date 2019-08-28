#include <stdio.h>
#include <stdlib.h>

char menu();

int main()
{
    char salir;

    do{
        switch(menu()){
            case 'a':
                printf("\nESTOY SUMANDO\n");
                system("pause"); // Screen Pause
                break;
            case 'b':
                printf("\nESTOY RESTANDO\n");
                system("pause");
                break;
            case 'c':
                printf("\nESTOY MULTIPLICANDO\n");
                system("pause");
                break;
            case 'd':
                printf("\nESTOY DIVIDIENDO\n");
                system("pause");
                break;
            case 'e':
                printf("\nSeguro quiere salir? (s/n)\n");
                fflush(stdin);
                salir = getchar();
                break;
            default:
                printf("\nELIJA UNA OPCION VALIDA!!!\n");
                break;
        }
        system("cls"); // Screen Clear
    } while (salir != 's');

    return 0;
}

char menu(){
    char option;

    printf("-----------BIENVENIDO A LA CALCU!-----------\n\n\n");
    printf("a.               sumar\n");
    printf("b.               restar\n");
    printf("c.               multiplicar\n");
    printf("d.               dividir\n");
    printf("e.               salir\n");

    printf("\nElegi una opcion valida: ");
    fflush(stdin);
    scanf("%c", &option);

    return option;
}

