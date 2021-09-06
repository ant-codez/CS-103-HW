#include <stdio.h>
#include <stdlib.h>

void rot13(char input[42]){
    char temp;
    int i = -1;

    while(input[++i]){
        if ((input[i] >= 'A' && input[i] <= 'M') || (input[i] >= 'a' && input[i] <= 'm')){
            putchar(input[i] + 13);
        }
        else if ((input[i] >= 'N' && input[i] <= 'Z') || (input[i] >= 'n' && input[i] <= 'z')){
            putchar(input[i] - 13);
        }
        else{
            putchar(input[i]);
        }
    }
}

int main(){
    char input[42];

    while(fgets(input, sizeof(input), stdin)){
        rot13(input);
    }

    return (0);
}