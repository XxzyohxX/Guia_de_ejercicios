#include <stdio.h>
#include <math.h>

#define PI 3.141592

int monto_final(int c, int x, int n) {
    return pow(c * (1 + x / 100), n);
}

int grados_celsius(int grados) {
    return (grados - 32) * 9 / 5;
}

int grados_farenheit(int grados) {
    return 9 / 5 * grados + 32;
}

int norma(int x, int y, int z) {
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

int diametro(int r) {
    return 2 * r;
}

int circunferencia(int r) {
    return PI * r * 2;
}

int area(int r) {
    return PI * pow(r, 2);
}

int volumen(int r, int h) {
    return area(r) * h;
}

int area_cilindro(int r, int h) {
    return 2 * PI * r * h + 2 * PI * pow(r, 2);
}

int par_o_impar(int n) {
    if(n % 2)
        return 1;
    else return 0;
}

int primer_numero_multiplo_de_19(int n) {
    return (n / 10) * 10;
}

int comparar(int a, int b) {
    return a - b;
}

void Julio() {
    printf("Nombre: Julio\nApellido: Gamarra\nPadron: 102805\n");
}

int main() {
    printf("la norma es: %d\n", norma(1, 1, 1));
    printf("el numero es: %d\n", par_o_impar(4));
    Julio();
    return 0;
}
