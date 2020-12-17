#include "midi.h"

#define MASK_BIT_VALOR 0x80u
#define MASK_VALOR_E 0x70u
#define MASK_VALOR_C 0x0fu
#define SHIFT_VALOR_E 4
#define TRACK_ID 0x4D54726B
#define HEADER_ID 0x4D546864
#define HEADER_SIZE 6
#define MASK_MSB 0x80
#define SHIFT_BYTE 8
#define SHIFT_TIME 7

const char*notaS[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

const int V_longitud[] = { 2, 2, 2, 2, 1, 1, 2, 2};

const char *formatoS[] = { "pista unica", "multipista sincronica", "multipista asincronica"};

const char *eventoS[] = { 
    "nota apagada", 
    "nota encendida", 
    "nota durante", 
    "cambio de control", 
    "cambio de programa", 
    "variar canal",
    "cambio de pitch", 
    "metaevento"
};

bool decodificar_formato(uint16_t valor, formato_t *formato) {
    if (valor <= 2){
        *formato = valor;
        return true;
    }
    return false;
}

bool decodificar_evento(uint8_t valor, evento_t *evento, char *canal, int *longitud) {
    if ( valor & MASK_BIT_VALOR){
        *evento = ( valor & (~MASK_BIT_VALOR)) >> SHIFT_VALOR_E;
        *canal = valor & MASK_VALOR_C;
        *longitud = V_longitud[*evento];
        return true;
    }
    return false;
}

bool decodificar_nota(uint8_t valor, notaescala_t *nota, signed char *octava) {
        
    if ( (valor < 0) | (valor > 127))
        return false;
    
    *nota = valor % 12;
    *octava = ( valor / 12 ) - 1;
    return true;
}

const char *codificar_formato(formato_t formato) {
    return formatoS[formato];
}

const char *codificar_evento(evento_t evento) {
    return eventoS[evento];
}

const char *codificar_nota(notaescala_t nota) {
    return notaS[nota];
}

uint8_t leer_uint8_t(FILE *f) {
    uint8_t x;
    fread( &x, 1, 1, f);    
    return x;
}

uint16_t leer_uint16_big_endian(FILE *f) {
    uint8_t v[2];
    fread ( v, 1, 2, f);
    return v[0] << 8 | v[1]; 
}

uint32_t leer_uint32_big_endian(FILE *f) {
    uint8_t v[4];
    fread ( v, 1, 4, f);
    return v[0] << 24 | v[1] << 16 | v[2] << 8 | v[3]; 
}

bool leer_encabezado(FILE *f, formato_t *formato, uint16_t *numero_pistas, uint16_t *pulsos_negra){
            
    uint32_t headerid = leer_uint32_big_endian(f);
    uint32_t size = leer_uint32_big_endian(f);
    
    if ( headerid != HEADER_ID || size != HEADER_SIZE )
        return false;
    
    uint16_t valor = leer_uint16_big_endian(f);
    if ( !decodificar_formato( valor, formato))
        return false;
    
    *numero_pistas = leer_uint16_big_endian(f);
    *pulsos_negra = leer_uint16_big_endian(f);

    return true;
}

bool leer_pista(FILE *f, uint32_t *tamagno){
    uint32_t trackid = leer_uint32_big_endian(f);
    
    if ( trackid != TRACK_ID)
        return false;
    *tamagno = leer_uint32_big_endian(f);
    return true;    
}

bool leer_tiempo(FILE *f, uint32_t *tiempo){
    size_t i;
    *tiempo = 0;    
        
    for (i = 0; i < 4; i++){
        uint8_t time = leer_uint8_t(f);

        if (i == 3 && (time & MASK_MSB) != 0 ) //Si en la ultima iteracion, el MSB es 1,es un tiempo invalido.
            return false;

        *tiempo = (*tiempo << SHIFT_TIME) | (time & ~MASK_MSB);
        if ( (time & MASK_MSB) == 0){
            break;           
        }
        
    }
    
    return true;
}

bool leer_evento(FILE *f, evento_t *evento, char *canal, int *longitud, uint8_t mensaje[]) {
    uint8_t valor = leer_uint8_t(f);
            
    if(decodificar_evento(valor, evento, canal, longitud)){
        mensaje[0] = leer_uint8_t(f);
    }
    else {
        mensaje[0] = valor;
    }
    for (size_t i = 0; i < (*longitud - 1); i++){
            mensaje[1+i] = leer_uint8_t(f);
    }

    return true;
}

void descartar_metaevento(FILE *f, uint8_t tamagno) {
    for (size_t i = 0; i < tamagno; i++){
        uint8_t x = leer_uint8_t(f);
    }
}