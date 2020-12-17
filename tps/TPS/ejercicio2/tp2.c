#include <stdio.h>
#include <math.h>
#define PI 3.1415926535897932
#define T0 0.0
#define F 110.0f
#define F_M 12000
#define A 1.0f

void inicializar_muestras(float v[], size_t n);
void imprimir_muestras(const float v[], size_t n, double t0, int f_m);
void muestrear_senoidal(float v[], size_t n, double t0, int f_m, float f, float a);
void muestrear_armonicos(float v[], size_t n, double t0, int f_m, float f, float a, const float fa[][2], size_t n_fa);
int main(){
    const float fa[][2]={
    {1, 0.58},
    {2, 0.58},
    {3, 0.064},
    {4, 0.13},
    {5, 0.10},
    {6, 0.012},
    {7, 0.012},
    {8, 0.012}
    };
    float v[150];
    
    muestrear_armonicos(v,sizeof(v)/sizeof(float),T0,F_M,F,A,fa,sizeof(fa)/(sizeof(float)*2));
    imprimir_muestras(v,sizeof(v)/sizeof(float),T0,F_M);
    
    return 0;
}

void inicializar_muestras(float v[], size_t n){
    for(size_t i=0;i<n;i++){
        v[i]=0;
    }
}
void imprimir_muestras(const float v[], size_t n, double t0, int f_m){
    for(size_t i=0;i<n;i++){
       printf("%f,%f\n",(t0+i/(double)f_m),v[i]);
    }
}
void muestrear_senoidal(float v[], size_t n, double t0, int f_m, float f, float a){
    for(size_t i=0;i<n;i++){
        v[i]+=a*sin(2*PI*f*(t0+i/(float)f_m));
    }
}
void muestrear_armonicos(float v[], size_t n, double t0, int f_m, float f, float a, const float fa[][2], size_t n_fa){
    inicializar_muestras(v,n);
    for(size_t i=0;i<n_fa;i++){
        muestrear_senoidal(v,n,t0,f_m,fa[i][0]*f,fa[i][1]*a);
    }
}
