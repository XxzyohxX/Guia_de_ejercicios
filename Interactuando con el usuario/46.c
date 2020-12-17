#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 256

int main() {

	char cadena[MAX_NUM] = {0};
	int numero, max = 0, min = 2147483647, cant = 0;
	float promedio = 0;
	int total = 0;
/*
	while(fgets(cadena, MAX_NUM, stdin) != NULL) {
		numero = atoi(cadena);

		if(numero > max)
			max = numero;
		if(min > numero)
			min = numero;

		total += numero;
		cant ++;

	}

	promedio = total / cant;

	printf("el maximo es: %d\nel minimo es: %d\nel promedio es: %f\n", max, min, promedio);


	do {

		if(fgets(cadena, MAX_NUM, stdin) == NULL) {
			promedio = total / cant;

			printf("el maximo es: %d\nel minimo es: %d\nel promedio es: %f\n", max, min, promedio);
			return 0;
		}
			
		numero = atoi(cadena);

		if(numero > max)
			max = numero;
		if(min > numero)
			min = numero;

		total += numero;
		cant ++;

	} while(1);

*/
	for(cant = 0; fgets(cadena, MAX_NUM, stdin) != NULL; cant++) {
		numero = atoi(cadena);

		if(numero > max)
			max = numero;
		if(min > numero)
			min = numero;

		total += numero;

	}

	promedio = total / cant;

	printf("el maximo es: %d\nel minimo es: %d\nel promedio es: %f\n", max, min, promedio);

	return 0;
}