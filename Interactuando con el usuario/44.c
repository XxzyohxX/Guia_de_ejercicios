#include <stdlib.h>
#include <stdio.h>

#define MAX 250


int main() {

	int lineas = 0;
	int caracter;

	while((caracter = getchar()) != EOF) {
		if(caracter == '\n')
			lineas ++;
	}

	printf("La cantidad de lineas son: %d\n", lineas);

	return 0;
}