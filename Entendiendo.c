#include <stdio.h>
#include <stdbool.h>

#define M_PI 3.14159265358979
#define STR_HOLA_MUNDO "Hola mundo"
#define NOTA_MAX 10 
#define NOTA_MIN_APROBADO 4
#define SEGxHORA 3600

//Ej28
long sumar(int a, int b) {
	return a + b;
}

long restar(int a, int b) {
	return a - b;
}

float multiplicar(int multiplicando, int multiplicador) {
	return multiplicando * multiplicador;
}

double dividir(int dividendo, int divisor) {
	return dividendo / divisor;
}

int mod(int dividendo, int divisor) {
	return dividendo % divisor;
}

//por que crees que se eligieron esos valores de retorno?
//porque se buscaba un cierto tipo de retorno especifico.

//si ahora quisieramos soportar operaciones en punto flotante, ademas de las operaciones con flotantes, que deberia cambiar?
//se deberia cambiar los tipos de los argumentos y de los retornos.


int main() {

	puts('A');
	return 0;
}