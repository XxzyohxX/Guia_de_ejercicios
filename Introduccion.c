#include <stdio.h>
#include <math.h>
#define PI 3.141592653589

//EJ1
float monto_final_a_cobrar(float c, float x, int n) {
	return (int)pow(c * (1 + x/100),n);
}

//EJ2
float celsius_a_fahrenheit(float c) {
	return ((float)9/5 * c) + 32;
}

//EJ3
float fahrenheit_a_celsius(float f) {
	return (9/5) * (f - 32);
}

//EJ4
int tiempo_en_segundos(char hora, char minutos, char segundos) {
	return hora * 3600 + minutos * 60 + segundos;
}

//EJ5
float norma(float x, float y, float z) {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

float diametro(float radio) {
	return 2 * radio;
}

float circunferencia(float radio) {
	return 2 * PI * radio;
}

float area_de_la_base(float radio){
	return PI * pow(radio, 2);
}

float volumen(float radio, float altura) {
	return area_de_la_base(radio) * altura;
}

float area_del_cilindro(float radio, float altura) {
	return circunferencia(radio) * (radio + altura);
}

int es_par(int entero) {
	if(entero % 2)
		return 1;
	else
		return 0;
}

int primer_numero_multiplo_de_10(int valor) {
	return (valor/10) * 10;
}

int main() {

	printf("el monto final a cobrar es: %f\n",monto_final_a_cobrar(1, 100, 1));
	printf("%f\n",celsius_a_fahrenheit(20));
	printf("%f\n",fahrenheit_a_celsius(32.5));
	printf("%d\n",tiempo_en_segundos(2, 46, 40));
	printf("la norma es: %f\n",norma(1, 2, 1));
	printf("el diametro es: %f\n", diametro(2.5));
	printf("la circunferencia es: %f\n", circunferencia(2.5));
	printf("el area de la base es: %f\n", area_de_la_base(2.5));
	printf("el volumen es: %f\n", volumen(2.5, 15));
	printf("el area del cilindro es: %f\n", area_del_cilindro(2.5, 15));
	printf("%d\n", es_par(3) );
	printf("%d\n", primer_numero_multiplo_de_10(153));
	puts("Nombre: Julio");
	puts("Apellido: Gamarra");
	puts("Padron: 102805");
	return 0;
}
