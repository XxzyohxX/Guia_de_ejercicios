#include "ejercicio3.h"

#define PI 3.1415926535897932

struct tramo {
    float *v;
    size_t n;
    double t0;
    int f_m;
};

tramo_t *_tramo_crear(double t0, double tf, int f_m);
bool tramo_extender(tramo_t *destino, const tramo_t *extension);
void inicializar_muestras(float v[], size_t n);
void muestrear_senoidal(float v[], size_t n, double t0, int f_m, float f, float a);
void muestrear_armonicos(float v[], size_t n, double t0, int f_m, float f, float a, const float fa[][2], size_t n_fa);
void imprimir_muestras ( tramo_t *t);
tramo_t *tramo_clonar(const tramo_t *t);

/*En el main se implementan todas las funciones creadas,de manera explicita o implicita,por ejemplo _tramo_crear.
se crean dos tramos los cuales se muestrean con los datos del Trabajo 2.Se llama a la funcion tramo_extender y
se les pasa t1 y t2.Luego usando la funcion tramo clonar,se crea una copia de t1 y se almacena en t2.Si luego se exporta
en formato .csv y se grafica,se veran las ondas fundamentales del Trabajo 2 unidas.(en t = 0.01 se produce un pico ya que 
las funciones no son continuas).*/

/*int main () {
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
    
    tramo_t *t1 = tramo_crear_muestreo (0, 0.01, 20000, 440, 1, fa, 8);
    tramo_t *t3 = tramo_crear_muestreo (0.01, 0.02, 20000, 440, 1, fa, 8);
    
    if (!tramo_extender(t1, t3)){
        tramo_destruir(t1);
        tramo_destruir(t3);
        printf("Error.\n");
        return 1;
    };
    
    tramo_t *t2 = tramo_clonar(t1);
    imprimir_muestras (t2);
        printf("Operacion exitosa.");
        tramo_destruir(t1);
        tramo_destruir(t2);
        tramo_destruir(t3);
    return 0;

}*/


void inicializar_muestras(float v[], size_t n){
    for(size_t i=0;i<n;i++){
        v[i]=0;
    }
}

void muestrear_senoidal(float v[], size_t n, double t0, int f_m, float f, float a){
    for(size_t i=0;i<n;i++){
        v[i] += a * sin(2 * PI * f * (t0 + i / (float) f_m));
    }
}

void muestrear_armonicos(float v[], size_t n, double t0, int f_m, float f, float a, const float fa[][2], size_t n_fa){
    inicializar_muestras(v, n);
    for(size_t i = 0; i < n_fa; i++){
        muestrear_senoidal(v, n, t0, f_m, fa[i][0] * f, fa[i][1] * a);
    }
}

void imprimir_muestras ( tramo_t *t) {
    for(size_t i = 0; i < t->n; i++){
       printf(" %f,%f\n", (t->t0 + i / (double) t->f_m), t->v[i]);
    }
}

tramo_t *_tramo_crear(double t0, double tf, int f_m) {
           
    tramo_t *tramo_creado = malloc (sizeof(tramo_t));
    if (tramo_creado == NULL){
        return NULL;
    }            
    
    tramo_creado->t0 = t0;
    tramo_creado->f_m = f_m;
    tramo_creado->n = (tf - t0) * f_m + 1.5;
    tramo_creado->v = malloc ((tramo_creado->n) * sizeof(float));
    
    if (tramo_creado->v == NULL) {
        tramo_destruir (tramo_creado);
        return NULL;
    }
    return tramo_creado;
}

void tramo_destruir(tramo_t *t) {
    if (t != NULL){
        if(t->v !=NULL)
            free (t->v);
    free (t);
    }
}

tramo_t *tramo_clonar(const tramo_t *t) {
    float tf = (t->t0) + (t->n - 1) / (float)(t->f_m);
    
    tramo_t *tramo_clonado = _tramo_crear ( t->t0, tf, t->f_m );
    if (tramo_clonado == NULL)
        return NULL;
    
    memcpy (tramo_clonado->v, t->v, tramo_clonado->n * sizeof(float) );

    return tramo_clonado;
}

tramo_t *tramo_crear_muestreo(double t0, double tf, int f_m, float f, float a, const float fa[][2], size_t n_fa) {
    tramo_t *tramo_muestreo = _tramo_crear (t0, tf,f_m);
    if (tramo_muestreo == NULL)
        return NULL;
    
    muestrear_armonicos(tramo_muestreo->v, tramo_muestreo->n, t0, f_m, f, a, fa, n_fa);

    return tramo_muestreo;
}

bool tramo_redimensionar(tramo_t *t, double tf){
    size_t n = ((tf - t->t0) * t->f_m + 1.5);
    
    if ( n == t->n)
        return true;

    float *vaux = realloc (t->v,  n * sizeof(float)); //Pide memoria para n elementos dados por el nuevo tf.
    if (vaux == NULL)
            return false;

    t->v = vaux;

    if (n > t->n) {
        for (size_t i = t->n; i < n; i++) //Itera desde n original,hasta el nuevo n-1.
            t->v[i] = 0;
    }
    t->n = n;   //Asigno el nuevo n,dado el tf que recibe la funcion.    
    
    return true;
}

bool tramo_extender(tramo_t *destino, const tramo_t *extension) {
    
    if (destino == NULL || extension == NULL)
        return false;

    float tf_extension = extension->t0 + (float)(extension->n - 1) / extension->f_m;
    float tf_destino = destino->t0 + (float)(destino->n - 1) / destino->f_m;
    
        
    size_t i0 = ((extension->t0 - destino->t0) * destino->f_m) ; // I0 es la posicion del vector que corresponde al t0 de la extension.
    
    if ( tf_destino < tf_extension ){
        tramo_redimensionar (destino ,tf_extension);
    }
    for (size_t i = 0 ; i < extension->n; i++)
        destino->v[i0 + i] += extension->v[i];  
    
    return true;
}

size_t cantidad_de_muestras( tramo_t *t){
    return t->n;
}





