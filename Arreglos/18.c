#include <stdio.h>

#define N 4
#define M 5

int main() {
	int matriz[N][N];
	int m[N][M];
	int n[M][N];
	size_t i = 0;
	size_t j = 0;
	int traza = 0;
	int numero = 2; // si ponia char numero = 2 cambiaba el formato de 2 a caracter y cuando queria sumar a cada elemento de la matriz por numero lo hacia mal porque hacia un int mas un caracter



	for(size_t i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			matriz[i][j] = 1;
		}
	}

	for(size_t i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			m[i][j] = 1;
		}
	}

	for(i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if(matriz[i] == matriz[j])
				traza += matriz[i][j];
		}
	}


	for(i = 0; i < N; i++) {
		for(j = 0; j < M; j++) {
			m[i][j] += numero;
		}
	}

	for(i = 0; i < N; i++) {
		for(j = 0; j < M; j++) {
			m[i][j] *= numero;
		}
	}

	for(i = 0; i < N; i++) {
    	for(j = 0; j < M; j++) {
        	n[j][i] = m[i][j];
        }
    }

    for(i = 0; i < N; i++) {
    	for(j = 0; j < M; j++) {
    		if(m[i][j] <= 0) {
    			if()
    		}
    		printf("es positiva\n");
    	}
    }


	return 0;
}