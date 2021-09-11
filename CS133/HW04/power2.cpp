// ============================================================================
// File: sumOfSquares.cpp
// ============================================================================
// Programmer: Anthony Chavez
// Date: 9/6/2021
// Class: CSCI 133 ("Data Structures Using C++")
// Instructor: Dr. Rodriguez
// Project: HW03 : Sum of Squares
//
// Description:
//      This program outputs the sum of squares from 1 to N using recursion.
//      The program will start by asking the user to enter a number and then
//      Returns the output after calling the squareSum function.
//
// ============================================================================

#include <iostream>
using namespace std;

long long power(int num, int raised, int i){
   printf("Calls = %i\n", i++);
    if (raised > 0)
        return (num * power(num, raised - 1, i));
    else
        return 1;
}

int main(){
    int x = 0;
    int n = 0;
    int i = 1;

    printf("Please enter an x value\n");
    cin >> x;
    printf("Please enter the power you would like to raise it too\n");
    cin >> n;

    printf("%i to the power of %i = %lli", x, n, power(x, n, i));

    return (0);
}