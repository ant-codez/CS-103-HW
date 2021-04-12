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

#include "cgrade.h"
#include <iostream>
#include <cstring>
using namespace std;



// ==== main ==================================================================
//
// ============================================================================

int     main()
{
        CGrade  S1;             // first student
        CGrade  S2("Edgar Allen Poe",0,0,0,0);        // second student
        CGrade  S2Copy(S2);                  // copy of the second student

        // Display the default constructor info
        cout << "\nThe grades of S1 (default constructor):\n";
        S1.DispGrade();

        // prompt the user for name/grades
        cout << "\nInfo for S1:\n";
        S1.GetInfo();

        // call the function to calculate percent/grade
        S1.CalcGrade();
        S2.CalcGrade();
        S2Copy.CalcGrade();

        // display their grades
        cout << "\n The grades of the students are:\n";
        S1.DispGrade();
        S2.DispGrade();
        S2Copy.DispGrade();

        return 0;
}   // end of "main"


