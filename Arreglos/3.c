#include <stdio.h>
#include <stdlib.h>

int main() {
	char cadena[100];


	int vector[10] = {0};
	for(size_t i = 0; i < 10; i++) {
		vector[i] += 1;
	}


	float temp_mensuales[12];
	for(size_t i = 0; i < 12; i++) {
		fgets(cadena, 100, stdin);
		temp_mensuales[i] = atof(cadena);
	}


	int puntajes[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for(size_t i = 0; i < 5; i++) {
		printf("%d\n", puntajes[i]);
	}


	int salarios[20];
	for (size_t i = 0; i < 20; i++) {
		salarios[i] += 1000; 
	}
	for(size_t i = 0; i < 20; i++) {
		salarios[i] += salarios[i] * 0.30;
	}

	return 0;
}
