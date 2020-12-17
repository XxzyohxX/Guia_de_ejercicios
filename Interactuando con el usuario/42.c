#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 100


int main(void) {
    int dia;
    char dias[] = {'D', 'L', 'M', 'X', 'J', 'V', 'S'};

    char aux[MAX_STR];
    fgets(aux, MAX_STR, stdin);

    dia = atoi(aux);

    if(dia < 1 || dia > 366)
        return 1;

    printf("El dia es %c\n", dias[(dia - 1) % 7]);

    return 0;
}

