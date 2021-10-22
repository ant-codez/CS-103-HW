// ============================================================================
// File: main.cpp
// ============================================================================
// Programmer: ???
// Date: ???
// Class: CSCI 133 ("Data Structures Using C++")
// Time: ???
// Instructor: Dr. Rodriguez
// Project: Inheritance
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

#include    "cvehicle.h"
#include    "ccar.h"
#include    "ctruck.h"

// function prototypes
void    DisplayInfo(???);



// ==== main ==================================================================
//
// ============================================================================

int     main()
{
    CCar            myCar ("Chevolet"           // make
                            , "Camaro"          // model
                            , "Bumblebee"       // name
                            , 'A'               // Automatic
                            , 2                 // Two doors
                            , 175000            // 175,000 miles
                          );
    CTruck          myTruck ("Ram"               // make
                            , "Rebel"           // model
                            , "Optimus Prime"   // name
                            , 'A'               // Automatic
                            , 4                 // Four doors
                            , 125               // 125 miles
                            , 91                // 91% fuel
                            , 'D'               // Diesel Fuel Type
                            , 'C'               // Crew Cab
                            , "Short"           // Short Bed
                            , true              // Four-Wheel-Drive Enabled
                           );

    // Display information for each vehicle before traveling
    cout << "==============================================================\n";
    cout << "                Displaying Initial Settings\n";
    cout << "==============================================================\n";
    DisplayInfo(myCar);
    DisplayInfo(myTruck);

    cout << endl;

    // Drive all vehicles different amount of miles.
    cout << "==============================================================\n";
    cout << "                      Driving Vehicles\n";
    cout << "==============================================================\n";
    myCar.Drive(103);
    myTruck.Drive(50);

    // Display information for each vehicle after traveling
    cout << "==============================================================\n";
    cout << "              Displaying Secondary Settings\n";
    cout << "==============================================================\n";
    DisplayInfo(myCar);
    DisplayInfo(myTruck);

    // Drive until we run out of fuel and display the info
    cout << "==============================================================\n";
    cout << "               Driving Vehicles Again\n";
    cout << "==============================================================\n";
    myCar.Drive(1000);
    myTruck.Drive(1000);

    cout << "==============================================================\n";
    cout << "               Displaying Final Settings\n";
    cout << "==============================================================\n";
    DisplayInfo(myCar);
    DisplayInfo(myTruck);
    

    return 0;

}  // end of "main"



// ==== DisplayInfo ===========================================================
//
// This function calls the member function DispVehicleInfo
//
// Input:
//		object [IN]     -- a const reference to a specific object of CVehicle
//                         (superclass) and it's subclasses (Polymorphism).
//
// Output:
//      void
//
// ============================================================================

void    DisplayInfo(???)
{
	???
}
