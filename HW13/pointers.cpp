// ============================================================================
// file: pointers.cpp
// ============================================================================
// Programmer: Anthony Chavez
// Date: 4/21/2021
// Class: CSCI 123 ("Intro to Programming Using C++")
// Time: 12:00PM
// Instructor: Dr. Rodriguez
// Project: 
//
// Description:
// This program utalizes pointers to insert data into a double array calling the initArray
// and dispRevArray function
// ============================================================================

#include <iostream>
#include <cstring>
using namespace std;

// Function Prototypes
void initArray(double *);
void dispRevArray(double *);


// ==== main ==================================================================
//
// ============================================================================

int     main()
{
    double *pointer;
    double arr[5];

    pointer = arr;

    cout << "This is the address of the array: " << &arr << endl;
    cout << "This is the address of where the pointer is pointing to: " << pointer << endl;
    cout << "This is the address of the pointer: " << &pointer << endl << endl;

    cout << "Please enter 5 values for the array:\n";
    initArray(pointer);
    cout << endl;

    cout << "The array you entered in reverse is: ";
    dispRevArray(pointer);
    return 0;
}   // end of "main"

//Function used to populate the double array with user generated values
void    initArray(double *ptr){

    for (int i = 0; i < 5; i++){
        cin >> *(ptr + i);
    }

}

//Function used to print out the values the user entered in reverse
void    dispRevArray(double *arr){

    for (int i = 4; i >= 0; i--){
        cout << *(arr + i) << " ";
    }
}
