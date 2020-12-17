#include <stdio.h>
#include <stdbool.h>

bool veccpy(double dest[], size_t ldest, const double orig[], size_t lorig) {
	if(ldest < lorig)
		return false;
	for(size_t i = 0; i < lorig; i++) {
		dest[i] = orig[i];
	}
	return true;
} 

bool vecsame(int vec1[], size_t lvec1, int vec2[], size_t lvec2) {
	if(lvec2 != lvec1)
		return false;
	for(size_t i = 0; i < lvec2; i++) {
		if(vec2[i] != vec1[i])
			return false;
	}
	return true;
}

int main() {

	return 0;
}