// ============================================================================
// File: main.cpp
// ============================================================================
// Programmer: Anthony Chavez
// Date: 9/4/2021
// Class: CSCI 133 ("Data Structures Using C++")
// Instructor: Dr. Rodriguez
// Project: HW02 : CMathStud
//
// Description:
//      This program demonstrates the usage of advanced class composition
//
// ============================================================================

#include "cmathstud.h"
#include <iostream>
using namespace std;

int     main()
{
	// Create an object
    CMathStud   stud1(1,2);
    CMathStud   stud2(3,4,5);

    // Evaluation
    cout << "Stud1 Eval: " << stud1.getMyValue(3.14159) << endl;
    cout << "Stud2 Eval: " << stud2.getMyValue(3.14159) << endl << endl;

    return 0;

}  // end of "main"

