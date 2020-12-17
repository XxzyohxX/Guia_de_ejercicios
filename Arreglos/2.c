#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main() {
	int a[15] = {0}, sumaa = 0;
	double b[7] = { [0 ... 6] = 3.0}, sumab = 0;
	float c[SIZE] = {0}, sumac = 0;
	int d[4] = {9, 5, 1, 1}, sumad = 0;
	char e[4] = {'h', 'o', 'l', 'a'}, sumae = 0;
	char f[4] = {104, 111, 108 , 97}, sumaf = 0;
	int g[SIZE] = {1, 10, 9, 4, 414, 104, 14, 54, 76}, sumag = 0;

	for(size_t i = 0; i < SIZE; i++) {
		printf("%d ", a[i]);
		sumaa += a[i];
	}

	printf("\n%d", sumaa);
	putchar('\n');

	for(size_t i = 0; i < 7; i++) {
		printf("%f ", b[i]);
		sumab += b[i];
	}

	printf("\n%f", sumab);
	putchar('\n');

	for(size_t i = 0; i < SIZE; i++) {
		printf("%f ", c[i]);
		sumac += c[i];
	}

	printf("\n%f", sumac);
	putchar('\n');

	for(size_t i = 0; i < 4; i++) {
		printf("%d ", d[i]);
		sumad += d[i];
	}

	printf("\n%d", sumad);
	putchar('\n');

	for(size_t i = 0; i < 4; i++) {
		printf("%c ", e[i]);
		sumae += e[i];
	}

	printf("\n%d", sumae);
	putchar('\n');

	for(size_t i = 0; i < 4; i++) {
		printf("%c ", f[i]);
		sumaf += f[i];
	}
	
	printf("\n%d", sumaf);
	putchar('\n');

	for(size_t i = 0; i < SIZE; i++) {
		printf("%d ", g[i]);
		sumag += g[i];
	}
	
	printf("\n%d", sumag);
	putchar('\n');
	
	return 0;
}