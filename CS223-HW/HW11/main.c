#include "add.h"
#include "sub.h"
#include <stdio.h>
#include <stdlib.h>


int main(void) {
    int a, b, check;

    printf("Please enter 2 numbers seperated by a space: ");
    check = scanf("%d %d", &a, &b);

    if (!check){
        printf("Error incorrect input. EX: 1 1\n");
        return (1);
    }

    printf("%i + %i = %i\n", a, b, add(a, b));
    printf("%i - %i = %i\n", a, b, sub(a, b));
    
    return (0);
}