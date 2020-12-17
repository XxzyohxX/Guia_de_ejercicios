#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void completar_ceros(int vector[], size_t n) {
	for(size_t i = 0; i < n; i++) {
		vector[i] = 0;
	}
}

void completar_unos(int vector[], size_t n) {
	for(size_t i = 0; i < n; i++) {
		vector[i] = 1;
	}
}

int suma(int vector[], size_t n) {
	int suma = 0;
	for (size_t i = 0; i < n; i++) {
		suma += vector[i];
	}
	return suma;
}

int media(int vector [], size_t n) {
	int suma = 0;
	for (size_t i = 0; i < n; i++) {
		suma += vector[i];
	}
	return suma / n;
}

int varianza(int vector[], size_t n) {
	int suma = 0;
	for(size_t i = 0; i < n; i++) {
		suma += pow(vector[i] - media(vector, n), 2);
	}
	return suma / n;
}

int maximo(int vector[], size_t n) {
	int maximo = vector[0];
	for(size_t i = 0; i < n; i++) {
		if(vector[i] > maximo)
			maximo = vector[i];
	}
	return maximo;
}	

int minimo(int vector[], size_t n) {
	int minimo = vector[0];
	for(size_t i = 0; i < n; i++) {
		if(vector[i] < minimo)
			minimo = vector[i];
	}
	return minimo;
}	

void elemento_al_cuadrado(int vector[], size_t n) {
	size_t i = 0;
	while(i < n) {
		vector[i] = pow(vector[i], 2);
		i++;
	}
}

void signo(int vector[], size_t n) {
	for (size_t i = 0; i < n; i++) {
		if(vector[i] < 0)
			vector[i] = -1;
		if(vector[i] >= 0)
			vector[i] = 1;
	}
}

void diferencia_finita(int vector[], size_t n) {
	for (size_t i = 0; i < n - 1; i++) {
		vector[i] = vector[i + 1] - vector[i];
	}
}

int main() {
	int vector[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	completar_ceros(vector, 10);
	completar_unos(vector, 10);
	int suma1 = suma(vector, 10);
	int media1 = media(vector, 10);
	int maximo1 = maximo(vector, 10);
	int minimo1 = minimo(vector, 10);
	
	elemento_al_cuadrado(vector, 10);
	signo(vector, 10);
	diferencia_finita(vector, 10);

	return 0;
}