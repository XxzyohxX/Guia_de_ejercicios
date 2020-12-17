#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STRING 50

int main() {
    char buffer[MAX_STRING] = {0};
    fgets(buffer, MAX_STRING, stdin);

    float numero = atof(buffer);
    if(numero < 0) {
        float inverso = 1 / numero;
        printf("El inverso es %f, pero la raiz es invalida\n", inverso);
        return 0;
    } else if(numero == 0) {
        printf("El inverso es inf y la raiz es 0\n");
        return 0;
    }

    float raiz_numero = sqrt(numero);
    float inverso = 1 / numero;

    printf("El inverso es %f y la raiz es %f\n", inverso, raiz_numero);
    return 0;
}
