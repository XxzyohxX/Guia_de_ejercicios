#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool es_primo(int a) {
    if(a == 1)
        return false;

    for(int i = 2; i < sqrt(a); i++)
        if(a % i == 0)
            return false;

    return true;
}

void comparar(int x, int y) {
    if(x > y)
        puts("x es mayor que y");
    if(x == y)
        puts("x y yson iguales");
}

int main() {

    return 0;
}
