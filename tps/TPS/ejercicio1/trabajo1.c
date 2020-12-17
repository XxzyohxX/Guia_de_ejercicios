#include <stdio.h>
#include <math.h>
#define T0 0
#define TN 10
#define DELTAT 0.0005
#define PI 3.141592
#define A 50
#define F 29
#define PHI PI/2
double onda(double t,float a,float f,float phi);
int main(){
    float x;
    x=0;           
    for ( float t=T0;t<TN+DELTAT;t+=DELTAT){
        printf ("%f,%f\n",t,x);
        x+=DELTAT*onda(t,A,F,PHI);  
       
    } 
return 0;
}

double onda(double t,float a,float f,float phi){
    return a*sin(2*PI*t*f+phi);
    }