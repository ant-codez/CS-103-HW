// ============================================================================
// file: studentGrades.cpp
// ============================================================================
// Programmer: Anthony Chavez
// Date: 4/10/2021
// Class: CSCI 123 ("Intro to Programming Using C++")
// Time: 12:00PM
// Instructor: Dr. Rodriguez
// Project: CGrade
//
// Description:
//      ???
//This program creates a Class to hold member functions that ask for grades from the student
//and then calculates their total grade.
// ============================================================================

#include "DynMem.h"
#include <iostream>
#include <cstring>
using namespace std;



// ==== main ==================================================================
//
// ============================================================================

int     main()
{
    int num;
    int *arr;

    std::cout << "Enter the number of elements: ";
    std::cin >> num;

    arr = AllocArray(num);
    InitArray(arr, num);

    std::cout << "The array you entered is:\t";
    DispArray(arr, num);
    std::cout << "The sorted array is:\t";
    SortArray(arr, num);
    DispArray(arr, num);

    std::cout << "Releasing memory...";
    delete arr;
    return 0;
}   // end of "main"


