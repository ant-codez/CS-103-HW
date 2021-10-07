#include <stdio.h>
#include <stdlib.h>

void MakeChange(int *dollars, int *halfDollars, int *quarters, int *dimes, int *nickels, int *pennies){
    //convert first to dollars
    while (*pennies >= 100){
        *dollars += 1;
        *pennies -= 100;
    }

    //check if you can use a half dollar
    while (*pennies >= 50){
        *halfDollars += 1;
        *pennies -= 50;
    }

    //check for quarters
    while (*pennies >= 25) {
        *quarters += 1;
        *pennies -= 25;
    }

    //check for dimes
    while (*pennies >= 10) {
        *dimes += 1;
        *pennies -= 10;
    }

    //check for nickels 
    while (*pennies >= 5){
        *nickels += 1;
        *pennies -= 5;
    }
}

int main(void) {
    int dollars = 0, halfDollars = 0, quarters = 0, dimes = 0, nickles = 0, pennies = 0, check;

    printf("Please enter the total number of pennies: ");
    check = scanf("%d", &pennies);

    if (!check){
        printf("Error incorrect input, please enter a number\n");
        return (1);
    }

    MakeChange(&dollars, &halfDollars, &quarters, &dimes, &nickles, &pennies);

    printf("Here is the currency equivalent:\n");
    printf("%d dollars\n%d half dollar\n%d quarters\n%d dimes\n%d nickles\n%d pennies\n", dollars, halfDollars, quarters, dimes, nickles, pennies);


    return (0);
}