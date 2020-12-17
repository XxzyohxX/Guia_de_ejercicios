#include <stdio.h>
#include <math.h>

#define PI 3.1415927
#define PHI PI/2


double onda(double t, float a, float f, float phi) {
	return (a * sin(2 * PI * f * t + phi));
}

void inicializar_muestras(float v[], size_t n) {
	for(size_t i = 0; i < n; i++)
		v[i] = 0;
}

void imprimir_muestras(const float v[], size_t n, double t0, int f_m) {
	for(size_t i = t0; i < n; i++) {
		double ti = t0 + (double)i / f_m;
		printf("%f ; %f\n", ti, v[i]);
	}
}

void muestrear_senoidal(float v[], size_t n, double t0, int f_m, float f, float a) {
	for(int i = 0; i < n; i++) {
		double ti = t0 + (double)i / f_m;
		v[i] += onda(ti, a, f, 0);
	}
}

void muestrear_armonicos(float v[], size_t n, double t0, int f_m, float f, float a, const float fa[][2], size_t n_fa) {
	inicializar_muestras(v, n);
	for(size_t j = 0; j < n_fa; j++) {
		muestrear_senoidal(v, n, t0, f_m, f * fa[j][0], a * fa[j][1]);
	}
}



int main() {
	float v[10000] = {0};
	const float fa[][2] = {
    	{1, 0.58},
    	{2, 0.58},
    	{3, 0.064},
    	{4, 0.13},
    	{5, 0.10},
    	{6, 0.012},
    	{7, 0.012},
    	{8, 0.012}
	};
/*
	muestrear_senoidal(v, 10000, 0, 12000, 110, 1);
	muestrear_senoidal(v, 10000, 0, 12000, 1 * 110, 0.58);
	muestrear_senoidal(v, 10000, 0, 12000, 2 * 110, 0.58);
	muestrear_senoidal(v, 10000, 0, 12000, 3 * 110, 0.064);
	muestrear_senoidal(v, 10000, 0, 12000, 4 * 110, 0.13);
	muestrear_senoidal(v, 10000, 0, 12000, 5 * 110, 0.10);
	muestrear_senoidal(v, 10000, 0, 12000, 6 * 110, 0.012);
	muestrear_senoidal(v, 10000, 0, 12000, 7 * 110, 0.012);
	muestrear_senoidal(v, 10000, 0, 12000, 8 * 110, 0.012);
*/
	muestrear_armonicos(v, 10000, 0, 10000, 110, 1, fa, 8);
	imprimir_muestras(v, 10000, 0, 10000);

	return 0;
}