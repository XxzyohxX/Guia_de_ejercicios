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

int main() {


    return 0;
}
