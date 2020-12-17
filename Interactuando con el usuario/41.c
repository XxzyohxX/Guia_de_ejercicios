#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_STRING 100

int main(void) {
	char numero[MAX_STRING] = {0};
	fgets(numero, MAX_STRING, stdin);
	
	float n = atof(numero);
	if(n <= 0)
		return 1;

	float inverso = 1 / n;
	float raiz = sqrt(n);

	printf("%f\n", n);
	printf("%f   %f\n", inverso, raiz);

	return 0;
}