// ============================================================================
// file: range.cpp
// ============================================================================
// Programmer: Anthony Chavez
// Date: 02/16/2021
// Class: CSCI 123 ("Intro to Programming Using C++")
// Time: 
// Instructor: Dr. Rodriguez
// Project: Range
//
// Description:
//
// ============================================================================
#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

// Function Prototypes
void Range();
void Range(int, int);
void Range(int, int, int);
void DispVal(int);

// ==== main ==================================================================
//
// ============================================================================

int main(){
    int lowerBound;
    int upperBound;
    int divisor;

    while (true){
        printf("Enter an integer lower and upper boundaries and divisor of the range separated by white space: ");
        if (cin >> lowerBound >> upperBound >> divisor){
            cout << endl;
            break;
        }
        else{
            printf("Incorrect input: Not a number\n");
            //Clear the error flag on cin so future I/O operations will work correctly
            cin.clear();
            //Skip to next newline
            cin.ignore(INT_MAX, '\n');
        }
    }

    if (lowerBound > upperBound){
        printf("Lower number is greater than upper\nExiting...\n");
        exit(0);
    }

    printf("Calling the Range function with no arguments\n");
    Range();
    printf("Calling the Range function with upper & lower arguments\n");
    Range(lowerBound, upperBound);
    printf("Calling the Range function with upper, lower, & divisor arguments\n");
    Range(lowerBound, upperBound, divisor);
    return (0);
}

// ==== Range =============================================================
//
// This function prints the even numbers of a loop from 0 - 25
//
// Input:
// None
//
// Output:
// void
//
// ============================================================================

void Range(){
    
    for(int i = 0; i < 25; i += 2){
        DispVal(i);
    }
    cout << endl << endl;
}

// ==== Range =============================================================
//
// This function has prints the even numbers of a loop from a lower and upper
// bound given by the user
//
// Input:
// low [IN] -- an integer value containing the lower bound
// up     [IN] -- an integer value containing the upper bound
// Output:
// void
//
// ============================================================================

void Range(int low, int up){

    for(int i = low; i <= up; i++){
        if (i % 2 == 0){
            DispVal(i);
        }
    }
    cout << endl << endl;
}

// ==== Range =============================================================
//
// This function has prints the number divided by a the div argument of a loop from a lower and upper
// bound given by the user
//
// Input:
// low [IN] -- an integer value containing the lower bound
// up     [IN] -- an integer value containing the upper bound
// div     [IN] -- The number we are dividing by
// Output:
// void
//
// ============================================================================

void Range(int low, int up, int div){

    for(int i = low; i <= up; i++){
        if (i % div == 0){
            DispVal(i);
        }
    }
    cout << endl;
}

// ==== DisplayVal =============================================================
//
//  A help function of the Range() functions that prints out a number on the command line
//
// Input:
// None
//
// Output:
// void
//
// ============================================================================

void DispVal(int num){
    printf("%i ",num);
}
