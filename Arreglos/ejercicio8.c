#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int completar_ceros(int arreglo[], int n) {
    for(size_t i = 0; i < n; i++) {
        arreglo[i] = 0;
    }
}

int completar_unos(int arreglo[], int n) {
        for(size_t i = 0; i < n; i++) {
            arreglo[i] = 1;
        }
}

int suma(int arreglo[], int n) {
    int suma = 0;
    for(size_t i = 0; i < n; i++) {
        suma += arreglo[i];
    }
    return suma;
}


int media(int arreglo[], int n) {
    int media = suma(arreglo, n) / n;
    return media;
}

float varianza(int arreglo[], int n) {
    int total = 0;
    for(size_t i = 0; i < n; i++) {
        total += pow(arreglo[i] - media(arreglo,n), 2);
    }
    float varianza = ((float)1 / n) * total;
    return varianza;
}

int main() {
    int mi_arreglo[5] = {1,2,3,4,5};

    printf("La suma es: %d\nla media es: %d\nla varianza es: %f\n", suma(mi_arreglo, 5), media(mi_arreglo, 5), varianza(mi_arreglo, 5));
    return 0;
}
