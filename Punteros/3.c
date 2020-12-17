#include <stdio.h>

int main() {
	float var1, set[] = {1.0, 2.0, 3.0, 4.0, 5.0};
	float *p1;

	p1 = set;
	var1 = *p1;
	*p1=10.0;

	int conj[5], list[]={5, 4, 3, 2, 1};
	int *punt;

	punt = list;
	conj = punt;  // no se puede cambiar la direccion del arreglo
	list = conj;  // idem
	punt = &conj;

	int *pint, arrayint[5];
	float *pfloat, arrayfloat[5];

	pint = arrayint;
	pfloat = arrayfloat;
	pint += 1;
	pfloat += 1;
	pint++;
	pfloat++;
	pint -= 1;
	pfloat -=1;

	int *p, a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int var;

	p = a;
	*p = 33;
	var = *p;
	var = *(p+1);
	var = *(p+3);
	var = *(p++);
	var = *p++;
	var = *(++p);
	var = *++p;
	var = ++*p;
	var = (*p)++;
	var = ++(*p);
	var = *p+1;

	return 0;
}