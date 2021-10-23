// ============================================================================
// File: cvehicle.cpp
// ============================================================================
// This is the implementation file for cvehicle.
// ============================================================================

#include    <iostream>
#include	<string>
using namespace std;

#include    "cvehicle.h"



// ==== Default Constructor ===================================================
//
// The default constructor sets make and model to "Two" and "Legs"
// respectively. 
// It also sets vehicle name to "Sam Witwicky", fuel type to S>teamPowered,
// fuel level to 85%, and 17000 miles.
//
// ============================================================================

CVehicle::CVehicle() {
    m_make = "Two";
    m_model = "Legs";
    m_vehicleName = "Sam Witwicky";
    m_fuelType = 'S';
    m_fuelLevel = 85.0;
    SetNumMiles(17000);
}



// ==== Type Constructor ======================================================
//
// The type constructor assigns the values passed as arguments during
// declaration
//
// ============================================================================

CVehicle::CVehicle(std::string make, std::string model, std::string vehicleName,
                 double miles, double fuelLevel, char fuelType) {
    
    m_make = make;
    m_model = model;
    m_vehicleName = vehicleName;
    SetNumMiles(miles);
    m_fuelLevel = 100;
    m_fuelType = fuelType;
}

// ==== CVehicle::Driving =====================================================
//
// The function adds the inputed miles to the private data member and decreases
// the fuel level by fuelRate (passed argument) for every mile traveled.
//
// Note: The function neglects to check we have enough fuel to travel the
// desired number of miles. If there is not enough fuel, the function will
// display it is out of fuel and display how many miles it could travel and add
// to m_miles.
//
// Input:
//		numMiles     [IN] - A double value for the number of miles to travel
//      fuelRate     [IN] - A double representing the percentage of fuel level
//                          decrease for every mile traveled.
//      methodTravel [IN] - A string describing how the vehicle is traveling
//                          (Ex: Walking, Driving, etc.)
//      noFuelMesg   [IN] - A message to display after there is no more fuel.
//                          (Ex: Time to call an Uber!)
//
// Output:
//      void
//
// ============================================================================

void CVehicle::Driving(double numMiles, double fuelRate, std::string methodTravel, std::string noFuelMesg) {
    int miles = 0;

    cout << GetVehicleName() << ":\n";
    cout << "\t\t" << methodTravel << " " << numMiles << " miles..." << endl << endl;
    
    while (numMiles > 0) {
        if (m_fuelLevel <= 0) {
            cout << GetVehicleName() << ":\n";
            cout  << "\t\t" << noFuelMesg << endl;
            cout << "\t\tOnly traveled " << miles << " miles\n";
            break;
        }

        m_fuelLevel -= fuelRate;

        numMiles--;
        SetNumMiles(GetNumMiles() + 1);
        miles++;
    }
}
