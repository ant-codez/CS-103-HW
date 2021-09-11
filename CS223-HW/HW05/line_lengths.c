#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10000

void readLine(char line[], int x, int *p){
    int num_chars = 0;

    for (int i = 0; i < strlen(line); i++){
        if (line[i] == '\n'){
            break;
        }
        if (line[i] != ' '){
            num_chars++;
        }
    }

    if (num_chars > 80){
        printf("Line %i has %i characters\n", x, num_chars);
        *p += 1;
    }
}

int main() {
    char buff[SIZE];
    int print_total = 0;
    int line = 1;

    while (fgets(buff, SIZE, stdin)){
        readLine(buff, line++, &print_total);
    }

    if (print_total == 0){
        printf("The input file is valid");
    }
    
    return (0);
}