#include "bulacio.h"

int getIntRange(char* msj, char* msjError, int min, int max, int intentos, int returnError){
    int num, cont = 1;

    printf("%s", msj);
    scanf("%d", &num);

    while (num < min || num > max){
        if(cont < intentos){
            printf("%s", msjError);
            scanf("%d", &num);
            cont++;
        } else {
            return returnError;
            break;
        }
    }
    return num;
}
