// ============================================================================
// File: main.cpp
// ============================================================================
// Programmer: ???
// Date: ???
// Class: CSCI 133 ("Data Structures Using C++")
// Time: ???
// Instructor: Dr. Rodriguez
// Project: CPersonInfo
//
// Description:
//      ???
//      ???
//      ???
//
// ============================================================================

#include    <iostream>
#include	<string>
using namespace std;
#include    "cpersoninfo.h"

// function prototypes
template <typename  ObjType>
void    DisplayInfo(const ObjType &object);



// ==== main ==================================================================
//
// ============================================================================

int     main()
{
    // create an int class object of CPersonInfo and have the default
    // constructor initialize it. Let's call it P1
    ???

	CPersonInfo<double>	P2(260.3, 67.1, 90, "James Buchanan Barnes");

    // create a double class object of CPersonInfo and invoke the copy
    // constructor to initialize it with the info from P2
	???

	int					weight; // pounds
	int					height; // inches
	int					age;	// years
	string				fName; 	// full name

    // create and initialze a pointer to function of DisplayInfo for a template
    // specific data type (double)
    ???

	// print the default value for P1 by calling DisplayInfo
	cout << "P1 = \n";
    ???

    // get info from user to update P1
    cout << "Please enter an integer value of your weight, height, age "
	     << "and your full name: ";
	???

	// update P1
	???

	// print P1 by calling DisplayInfo
	cout << "P1 = \n";
    ???

    // print P2 by calling DisplayInfo
	cout << "P2 = \n";
    ???

    // print P3 by calling the pointer to function variable
	cout << "P3 = \n";
    ???

    return 0;

}  // end of "main"



// ==== DisplayInfo ===========================================================
//
// This function displays the data members of CPersonInfo as a template since
// CPersonInfo can represent any data type for it's data members.
//
// Input:
//		object [IN]     -- a const reference to a specific template of
//                         CPersonInfo
//
// Output:
//      void
//
// ============================================================================

???
