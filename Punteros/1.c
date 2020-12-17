#include <stdio.h>

int main() {
	float * pfloat, manzana = 40.0, pera = 35.0;

	printf("&pfloat: %p\n", &pfloat);
	printf("&manzana: %p\n", &manzana);
	printf("&pera: %p\n", &pera);

	printf("pfloat: %p\n", pfloat);

	pfloat = &manzana;
	printf("pfloat: %p\n", pfloat);
	printf("*pfloat: %p\n", *pfloat);

	pfloat = &pera;
	printf("pfloat: %p\n", pfloat);
	printf("*pfloat: %p\n", *pfloat);

	int i = 3, * pint;
	float f = 10.0;

	pint = &i;
	*pint = 10;
	*pint = f;
	pint = &f;
	pint = 4321;

	return 0;
}