#include <stdio.h>

void printBinary(unsigned int num){
    unsigned int i = 1  << 31;
    int whiteSpace = 0;
    
    for (; i > 0; i = i / 2){
        (num & i) ? printf("1") : printf("0");

        if (++whiteSpace % 4 == 0 && whiteSpace != 0){
            printf(" ");
        }
        
    }
}

int main(void) {

    unsigned int inNum;

    printf("Enter an integer value: ");
    scanf("%d", &inNum);
    printf("NUMBER: %i\n", inNum);

    printBinary(inNum);

    return (0);
}