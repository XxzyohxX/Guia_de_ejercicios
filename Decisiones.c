#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool es_primo(int n) {
    if(n == 1)
        return false;

    for(int i = 2; i < sqrt(n); i++)
        if(n % i == 0)
            return false;

    return true; 
}

void comparar(int x, int y) {
	if(x > y)
		puts("x es mayor que y");
	if(x == y)
		puts("x y y son iguales");
}

int valor_absoluto(int numero) {
	if(numero < 0)
		return numero * -1;
	return numero;
}

int Identity(int num) 
{ 
    int row, col; 
      
    for (row = 0; row < num; row++) 
    { 
        for (col = 0; col < num; col++) 
        { 
            // Checking if row is equal to column  
            if (row == col) 
                printf("%d ", 1); 
            else
                printf("%d ", 0); 
        }  
        printf("\n"); 
    } 
    return 0; 
} 

int main() {

	int size = 2;
	Identity(size);
	
	return 0;
}