// ============================================================================
// File: main.cpp
// ============================================================================
// Programmer: Anthony Chavez
// Date: 10/3/2021
// Class: CSCI 133 ("Data Structures Using C++")
// Instructor: Dr. Rodriguez
// Project: Stacks
//
// Description:
//  This is a calculator program that will solve mathmatical expressions
//  in order according to PEMDAS. To accomplish this the program uses Stacks to 
//  create a new mathmatical expression in PostFix format to evaluate the expressions
//  in correct order.
// ============================================================================

#include  "infix.h"

// ==== main ==================================================================
//
// ============================================================================
int main(void) {

    Stack myStack;
    string input;
    string postFix;
    char ans;

    while (42) {
        cout << "Enter an equation: ";
        getline(cin, input);

        postFix = InfixToPostfix(input);
        
        cout << "Infix: " << input << endl;
        cout << "PostFix: " << postFix << endl;
        cout << "Ans: " << eval(postFix) << endl;
        
        printf("Would you like to try again? (Y/N)? ");
        cin >> ans;

        if (toupper(ans) != 'Y'){
            break;
        }

        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }

    return (0);
}