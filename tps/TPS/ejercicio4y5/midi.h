#ifndef MIDI_H
#define MIDI_H

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef enum { PISTAUNICA, MULTIPISTASINCRONICA, MULTIPISTASASINCRONICA} formato_t;

typedef enum { 
    NOTA_APAGADA, 
    NOTA_ENCENDIDA, 
    NOTA_DURANTE, 
    CAMBIO_DE_CONTROL, 
    CAMBIO_DE_PROGRAMA, 
    VARIAR_CANAL,
    CAMBIO_DE_PITCH, 
    METAEVENTO
} evento_t;

typedef enum { 
    C, CSHARP, D, DSHARP, E, F, FSHARP, G, GSHARP, A, ASHARP , B
} notaescala_t;

bool decodificar_evento(uint8_t valor, evento_t *evento, char *canal, int *longitud);
bool decodificar_formato(uint16_t valor, formato_t *formato);
bool decodificar_nota(uint8_t valor, notaescala_t *nota, signed char *octava); 
const char *codificar_formato(formato_t formato);
const char *codificar_evento(evento_t evento);
const char *codificar_nota(notaescala_t nota);

uint8_t leer_uint8_t(FILE *f);
uint16_t leer_uint16_big_endian(FILE *f);
uint32_t leer_uint32_big_endian(FILE *f);
bool leer_encabezado(FILE *f, formato_t *formato, uint16_t *numero_pistas, uint16_t *pulsos_negra);
bool leer_pista(FILE *f, uint32_t *tamagno);
bool leer_tiempo(FILE *f, uint32_t *tiempo);
bool leer_evento(FILE *f, evento_t *evento, char *canal, int *longitud, uint8_t mensaje[]);
void descartar_metaevento(FILE *f, uint8_t tamagno);

#endif