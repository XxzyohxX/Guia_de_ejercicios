#include <stdio.h>
#include <stdlib.h>



int main() {
    
    int space = 0, line = 0, tab = 0, character = 0, ch;
    /*
    while ((ch = fgetc(stdin)) != EOF) {
            character++;
            if (ch == ' ')
                space++;
            if (ch == '\n')
                line++;
            if (ch == '\t')
                tab++;
    }
            
    printf("\nNumber of characters = %d", character);
    printf("\nNumber of spaces = %d", space);
    printf("\nNumber of tabs = %d", tab);
    printf("\nNumber of lines = %d", line);
    */

    while((ch = getchar()) != EOF){
        if(ch == ' ')
            space ++;
        else if(ch == '\t')
            tab ++;
        else if(ch == '\n')
            line ++;
        else character ++;
    }

    printf("Number of characters = %d\n", character);
    printf("Number of spaces = %d\n", space);
    printf("Number of tabs = %d\n", tab);
    printf("Number of lines = %d\n", line);

    return 0;
}