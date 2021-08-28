// ============================================================================
// file: main.cpp
// ============================================================================
// Programmer: Anthony Chavez
// Date: 8/26/2021
// Class: CSCI 133 ("Data Structures Using C++")
// Instructor: Dr. Rodriguez
// Project: CPerson
//
// Description:
//      This program creates 3 Person Objects and compares which of them are the
// 		oldest, printing the results to the console.
//
// ============================================================================

#include    <iostream>
#include	"cperson.h"
using namespace std;


int     main()
{
	// Create an object (Default)
    CPerson	        P1;

	// Invoke type constructor
	char name[] = "Elon Musk";
	CPerson			P2(name, 47);

	// Copy Constructor
	CPerson			P3(P2);

	// Display the objects
    cout << "\n\nHere are the three people\n\n";
    cout << "P1: " << P1 << endl;
    cout << "P2: " << P2 << endl;
    cout << "P3: " << P3 << endl << endl;

	// Enter name and age for P1
    cout << "Enter your name and age (Hit enter after entering name): ";
    cin >> P1;

	// Display the objects again
    cout << "\nHere are the three people (revised):\n\n";
    cout << "P1: " << P1 << endl;
    cout << "P2: " << P2 << endl;
    cout << "P3: " << P3 << endl << endl;

	// Find who is older between P1 and P2
	if (P1 == P2)
	{
		cout << P1.GetName() << " and " 
			 << P2.GetName() << " are the same age of "
			 << P1.GetAge() << " years old\n\n";
	}
	else if (P1 > P2)
	{
		cout << P1.GetName() 
			 << " is the oldest at age "
			 << P1.GetAge() << " years old\n\n";
	}
	else
	{
		cout << P2.GetName() 
			 << " is the oldest at age "
			 << P2.GetAge() << " years old\n\n";
	}

    return  0;

}  // end of "main"

