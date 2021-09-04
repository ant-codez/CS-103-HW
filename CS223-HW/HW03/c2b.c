#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void c2b(char word[420], int *currHexVal){
    char hex[420];
    //int total = 0;

    for (int i = 0, j = 0; i < strlen(word); ++i, j += 2)
        sprintf(hex + j, "%02x", word[i] & 0xff);
    
    for (int i = 0; i < strlen(hex); i++){
        *currHexVal += 1;
        if (*currHexVal == 40){
            putchar('\n');
            *(currHexVal) = 0;
        }
        if (i != 0 && i % 2 == 0){
            putchar(' ');
        }
        
        putchar(hex[i]);
    }
    //printf("\n hex count = [%d]", *currHexVal);
}

void main() {
    char line[420];
    int currHexVal = 0;
    FILE * fpointer;
    fpointer = fopen("text.txt", "r");

    while(!feof(fpointer)){
        fgets(line, INT_MAX, fpointer);
        c2b(line, &currHexVal);
    }

    

    fclose(fpointer);

    return (0);
}