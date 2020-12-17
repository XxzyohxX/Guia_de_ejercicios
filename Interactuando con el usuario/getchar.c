#include <stdio.h>
#include <stdlib.h>

int main() {
	int variable = 0;
	while((variable = getchar()) != EOF) { //la primera ves como el buffer esta vacio le pide al usuario que ingrese texto
        printf("%c\n", variable);
        variable = getchar(); // hay una segundo llamada y pareceria que le pediria al usuario que ingrese texto otra vez, pero no, getchar saca un caracter del buffer y como en el buffer ya hay texto getchar saca un caracter
        printf("%c\n", variable);

	// para probar como funciona getchar. tiene dos funciones .1 agarrar un caracter
    // del buffer .2 si el buffer esta vacio osea que no haya mas carac
    // teres , le pide al usuario que ingrese texto
    }

	return 0;
}
