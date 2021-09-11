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

// ==== squareSum ==================================================================
// This function returns the sum of squares from 1 to num using recursion
//
// Input:
//      num [INT]  -- an integer value of the total number of squares to be added
//
// Output:
//      The sum of all the squares.
//
// ============================================================================

int squareSum(int num) {
    if (num == 0) 
        return 0;
    return squareSum(num -1) +  (num * num);
}

// ==== main ==================================================================
//
// ============================================================================

int main(){
    int n = 0;

    printf("Please enter a number...\n");

    cin >> n;

    printf("\nSum of Squares from 1 to %i = %i", n, squareSum(n));

    return (0);
}