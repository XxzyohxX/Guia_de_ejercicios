#include <stdio.h>

void swap(void *a, void *b){
	a = b;
	b = a;
}

int main() {
	int *a, *b;
	int a1 = 5, b1 = 6;
	a = a1, b = b1;
	swap(a, b);
	printf("%d %d\n", *a, *b);

	return 0;
}