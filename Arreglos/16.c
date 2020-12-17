#include <stdio.h>

#define N 4
#define M 5

int main() {
	int matriz[N][M];

	for(size_t i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			matriz[i][j] = 0;
		}
	}

	for(size_t i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			matriz[i][j] = 1;
		}
	}

	for(size_t i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			matriz[i][j] += j + ;
		}
	}

	return 0;
}