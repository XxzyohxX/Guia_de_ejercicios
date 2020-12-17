#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 256

int main() {
	char cadena[MAX_NUM];
	unsigned int calificacion, aprobados = 0, total = 0;
	float porcentaje;

	while(fgets(cadena,MAX_NUM, stdin)) {
		calificacion = atoi(cadena);

		if(calificacion < 0 || calificacion > 10) {
			porcentaje = (aprobados * 100) / total;

			if(porcentaje == 100)
				puts("Esto es raro");
			if(porcentaje > 80 && porcentaje < 100)
				puts("Muy bien");
			if(porcentaje > 60 && porcentaje <= 80)
				puts("No esta mal");
			if(porcentaje > 40 && porcentaje <= 60)
				puts("Algo no esta bien");
			if(porcentaje <= 40)
				puts("Algo esta mal");

			return 0;
		}

		if(calificacion >= 4)
			aprobados++;

		total++;
	}
	return 0;
}
