#include <stdio.h>
#include <math.h>

float celcius_a_fahrenheit(int c) {
    return (float)9 / 5 * c + 32;
}

int factorial(int n) {
    int resultado = 1;
    for(int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

float e() {
    float e = 0;
    for(int i = 0; i < 25; i++) {
        e += 1 / (float)factorial(i);
    }
    return e;
}



int main() {
    // 11
    for(int i = 1; i < 11; i++) {
        printf("7 x %d = %d\n", i, 7 * i);
    }

    int i = 1;
    while(i < 11) {
        printf("7 x %d = %d\n", i, 7 * i);
        i++;
    }

    // 12
    for(int i = 1; i < 11; i++) {
        for(int j = 1; j < 11; j++) {
            printf("%d x %d = %d\n", i, j, i * j);
        }
    }

    int j = 1;
    while(i < 11) {
        while(j < 11) {
            printf("%d x %d = %d\n", i, j, i * j);
            j++;
        }
        i++;
    }

    //13
    for(int i = 0; i <= 100; i += 10) {
        printf("%d = %.2f\n", i, celcius_a_fahrenheit(i));
    }

    i = 0;
    while(i <= 100) {
        printf("%d = %.2f\n", i, celcius_a_fahrenheit(i));
        i += 10;
    }

    // 14
    for(int i = 0; i < 7; i++) {
        for(int j = i; j < 7; j ++) {
            printf("%d - %d ", i, j);
        }
    }

    // 15
    printf("factoral: %d\n", factorial(8));
    printf("e: %f\n", e());

    return 0;
}
