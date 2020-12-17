#ifndef EJERCICIO3_H
#define EJERCICIO3_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

struct tramo;
typedef struct tramo tramo_t;

size_t cantidad_de_muestras( tramo_t *t);
tramo_t *tramo_crear_muestreo(double t0, double tf, int f_m, float f, float a, const float fa[][2], size_t n_fa);
void tramo_destruir(tramo_t *t);
bool tramo_extender(tramo_t *destino, const tramo_t *extension);

#endif