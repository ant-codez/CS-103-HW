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

#include "cgradeClassPointers.h"
#include <iostream>
#include <cstring>
using namespace std;



// ==== main ==================================================================
//
// ============================================================================

int     main()
{
        char name[256];
        double quiz1, quiz2, midterm, final;

        CGrade  *myGrade;
        CGrade  *myGrade2 = nullptr;
        

/*

        std::cout << "Enter student's full name: ";
        std::cin.getline(name, 256);
        std::cin.ignore();
        std::cout << "Enter Quiz 1 grade (out of 10): ";
        std::cin >> quiz1;
        std::cout << "Enter Quiz 2 grade (out of 10): ";
        std::cin >> quiz2;
        std::cout << "Enter midterm grade (out of 100): ";
        std::cin >> midterm;
        std::cout << "Enter final exam grade (out of 100): ";
        std::cin >> final;

        //printf("BEFORE\n\nNAME = %s\nQUIZ1 = %d\nQUIZ2 = %d\nMIDTERM = %d\nFINAL = %d\n", name, quiz1, quiz2, midterm, final);
        
*/
        myGrade2 = myGrade->MakeCGrade("name", 7.0, 8.0, 77.0, 88.0);

        //myGrade->ShowGrade(myGrade2);
        //myGrade->DispGrade();

        return 0;
}   // end of "main"

