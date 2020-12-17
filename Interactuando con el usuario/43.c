#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING 200

int main() {

	char segundos_recibidos[MAX_STRING];
	fgets(segundos_recibidos, MAX_STRING, stdin);

	int segundos_convertidos = atoi(segundos_recibidos);
	if(segundos_convertidos < 0)
		return 1;

	int segundos = segundos_convertidos % 60;
	int minutos = (segundos_convertidos / 60) % 60;
	int horas = (segundos_convertidos / 60) / 60;

	printf("%d %d %d\n",horas, minutos, segundos);

	return 0;
}