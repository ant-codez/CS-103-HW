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
void Sum(int, int, int&);
void Difference(int, int, int&);
void Product(int, int, int&);
void Division(int, int, int&, int&);

// ==== main ==================================================================
//
// ============================================================================

int main(){
    int num1, num2, result, remainder;
    char answer;

    while (true){
        cout << "Please enter two integer values separated by whitespace: "; 

        while (true){
            if (cin >> num1 >> num2) {
                break;
            }
            else{
                cout << "Error please enter whole numbers.\n";
                //Clear the error flag on cin so future I/O operations will work correctly
                cin.clear();
                //Skip to next newline
                cin.ignore(INT_MAX, '\n');
            }
        }

        Sum(num1, num2, result);
        printf("%i + %i = %i\n", num1, num2, result);
        Difference(num1, num2, result);
        printf("%i - %i = %i\n", num1, num2, result);
        Product(num1, num2, result);
        printf("%i * %i = %i\n", num1, num2, result);
        //we check to see if num2 is 0 to stop our program from crashing
        if (num2 == 0){
            cout << "Division by zero is undefined...\n";
        }
        else{
            Division(num1, num2, result, remainder);
            printf("%i / %i = %i with a remainder of %i\n", num1, num2, result, remainder);
        }
          
        while (true){
            cout << "Would you like to try different numbers (Y/N)? ";
            cin >> answer;

            if (toupper(answer) == 'Y'){
                break;
            }
            else if (toupper(answer) == 'N'){
                exit(0);
            }
            else{
                cout << "Error please enter Y or N\n";
                //Clear the error flag on cin so future I/O operations will work correctly
                cin.clear();
                //Skip to next newline
                cin.ignore(INT_MAX, '\n');
            }
        }

    }
    return (0);
}

// ==== Sum =============================================================
//
// This function adds the integers a and b and sets the ans variable to the sum
//
// Input:
// low [a] -- an integer value a
// low [b] -- an integer value b
// low [&ans] -- an integer value that will be set to the sum of a and b
// Output:
// void
//
// ============================================================================

void Sum(int a, int b, int &ans){
    ans = a + b; 
}

// ==== Difference =============================================================
//
// This function sbtracts the integers a and b and sets the ans variable to the difference
//
// Input:
// low [a] -- an integer value a
// low [b] -- an integer value b
// low [&ans] -- an integer value that will be set to the difference of a and b
// Output:
// void
//
// ============================================================================

void Difference(int a, int b, int &ans){
    ans = a - b; 
}

// ==== Product =============================================================
//
// This function multiplies the integers a and b and sets the ans variable to the product
//
// Input:
// low [a] -- an integer value a
// low [b] -- an integer value b
// low [&ans] -- an integer value that will be set to the product of a and b
// Output:
// void
//
// ============================================================================

void Product(int a, int b, int &ans){
    ans = a * b; 
}

// ==== Division =============================================================
//
// This function divides the integers a and b sets the variable ans to that
// This function also returns the remainder of a / b to rem
//
// Input:
// low [a] -- an integer value a
// low [b] -- an integer value b
// low [&ans] -- an integer value that will be set to a / b
// low [&rme] -- an integer value that will be set to the remainder of a / b
// Output:
// void
//
// ============================================================================

void Division(int a, int b, int &ans, int &rem){
    ans = a / b;
    rem = a % b;
}