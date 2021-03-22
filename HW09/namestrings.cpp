// ============================================================================
// file: matrices.cpp
// ============================================================================
// Programmer: Anthony Chavez
// Date: 03/15/2021
// Class: CSCI 123 ("Intro to Programming Using C++")
// Time: 
// Instructor: Dr. Rodriguez
// Project: Matrices
//
// Description:
// 
// ============================================================================
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

// Function Prototypes


// ==== main ==================================================================
//
// ============================================================================

int main(){
    char    input[256];
    char    *token;
    char    *arr[3];
    int     i = 0;

    printf("Please enter your full name: ");

    cin.getline(input, 256);

    token = strtok(input, " ");

    while (token != NULL){
        arr[i++] = token;
        token = strtok(NULL, " ");
    }

    cout << endl;

    if (i == 1){
        printf("First name: %s\n", arr[0]);
        printf("The total number of characters in your name is: %i", strlen(arr[0]));
    }
    else if (i == 2){
        printf("First name: %s\n", arr[0]);
        printf("Last name: %s\n", arr[1]);
        printf("The total number of characters in your name is: %i", strlen(arr[0]) + strlen(arr[1]));
    }
    else if (i == 3){
        printf("First name: %s\n", arr[0]);
        printf("Middle name: %s\n", arr[1]);
        printf("Last name: %s\n", arr[2]);
        printf("The total number of characters in your name is: %i", strlen(arr[0]) + strlen(arr[1]) + strlen(arr[2]));
    }
    else{
        printf("Incorrect input. Try again!!\n");
    }

    return (0);
}
