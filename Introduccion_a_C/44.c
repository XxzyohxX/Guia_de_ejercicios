#include <stdio.h>

int main() {
    int lineas = 0;
    int c;
    while((c = getchar()) != EOF) {
        if(c == '\n')
            lineas++;
    }
    printf("La cantidad de lineas es: %d\n", lineas);

    return 0;
}
