#include <stdio.h>

float celsius_a_fahrenheit(float c) {
	return (float)9/5 * c + 32;
}


int main() {
//  Ej11
	for (char numero = 0; numero < 11; numero++) {
		printf("%d ", numero * 7);
	}
	puts("\n");

//  Ej12
	for(char numero = 1; numero < 10; numero++) {
		for(char numero2 = 0; numero2 < 11; numero2++) {
			printf("%d ",numero2 * numero);
		}
		puts("\n");
	}

// Ej13
	for(float grados = 0; grados < 101; grados += 10) {
		printf("%.2f\n",celsius_a_fahrenheit(grados));
	}

// Ej14
	
	return 0;
}