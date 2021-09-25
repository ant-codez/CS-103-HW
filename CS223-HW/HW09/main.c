#include "dispoct.h"
#include "disphex.h"
#include <stdlib.h>


int main(void) {
    int num, check;

    printf("Please enter a base ten integer: ");
    check = scanf("%i", &num);
    if (!check){
        printf("Didn't read an int, bye!\n");
        exit(1);
    }

    DispOct(num);
    DispHex(num);
    
    return (0);
}