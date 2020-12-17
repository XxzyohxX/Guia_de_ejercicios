#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 50
#define CANTIDAD 5

int main() {
    char buffer[MAX_BUFFER_SIZE];
    float arreglo[CANTIDAD];
    float suma = 0;
    size_t i = 0;
    for(; i < 5; i++){
        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        float numero = atof(buffer);

        arreglo[i] = numero;
        suma += arreglo[i];
    }

    float media = suma / CANTIDAD;

    //sumatoria para varianza
    float total = 0;
    for(i = 0; i < 5; i++) {
        total += pow(arreglo[i] - media, 2);
    }

    float varianza = ((float)1 / CANTIDAD) * total;

    printf("la media es: %f\nla varianza es: %f\n", media, varianza);
    return 0;
}
