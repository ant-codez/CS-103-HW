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

#include "cpizza.h"
#include <iostream>
#include <cstring>
using namespace std;



// ==== main ==================================================================
//
// ============================================================================

int     main()
{
    //first order
    CPizza C1;

    C1.GetInfo();

    //second order
    CPizza C2(3,1,2, "Clark Kent");
    CPizza C3(C2);

    std::cout << "Order 1: \n\n"; 
    C1.CalculatePrice();
    std::cout << "Order 2: \n\n"; 
    C2.CalculatePrice();
    std::cout << "Order 3: \n\n"; 
    C3.CalculatePrice();


    return 0;
}   // end of "main"


