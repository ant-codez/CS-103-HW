#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void b2c(char word[100]){
    char text[100];

    for (int i = 0, j = 0; i < strlen(word); ++i, j += 2){
        int val[1];
        sscanf(word + j, "%2x", val);
        text[i] = val[0];
        text[i + 1] = '\0';
    }

    printf("%s\n", text);
}

int main() {
    char line[100];
    int currHexVal = 0;
    FILE * fpointer;
    fpointer = fopen("out.txt", "r");

    while(!feof(fpointer)){
        fgets(line, INT_MAX, fpointer);
        b2c(line);
    }

    

    fclose(fpointer);

    return (0);
}