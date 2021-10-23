// ============================================================================
// File: ccar.cpp
// ============================================================================
// This is the implementation file for CCar.
// ============================================================================

#include    <iostream>
#include	<string>
using namespace std;

#include    "cvehicle.h"
#include    "ccar.h"



// ==== Default Constructor ===================================================
//
// The default constructor sets make and model to "Honda" and "Civic"
// respectively. 
// It also sets vehicle name to "Rumble", fuel type to G>asPowered,
// fuel level to 75%, 53000 miles, transmission to M>anual, and 2 number of
// doors
//
// ============================================================================

CCar::CCar() {
    SetMake("Honda");
    SetModel("Civic");
    SetVehicleName("Rumble");
    SetFuelType('G');
    SetFuelLevel(75);
    SetNumMiles(53000);
    m_transmission = 'M';
    m_numDoors = 2;
}



// ==== Type Constructor ======================================================
//
// The type constructor assigns the values passed as arguments during
// declaration
//
// ============================================================================

CCar::CCar(std::string make, std::string model, std::string vehicleName,
             char transmission, int numDoors, double miles, double fuelLevel, 
             char fuelType){
    
    SetMake(make);
    SetModel(model);
    SetVehicleName(vehicleName);
    SetFuelType(fuelType);
    SetFuelLevel(fuelLevel);
    SetNumMiles(miles);
    m_transmission = transmission;
    m_numDoors = numDoors;
}




// 2 virtual functions implmentation below

void CCar::DispVehicleInfo() const {
    cout << GetVehicleName() << " info:\n";
    cout << "\t\tMake: " << GetMake() << endl;
    cout << "\t\tModel: " << GetModel() << endl;
    cout << "\t\tNumber of Miles: " << GetNumMiles() <<endl;
    cout << "\t\tFuel Level: " << GetFuelLevel() << "%" << endl;
    cout << "\t\tFuel Type: ";

    switch (GetFuelType()) {
        case 'G':
            cout << "Gas\n";
            break;
        case 'M':
            cout << "Diesel\n";
            break;
        default:
            cout << "ERROR\n";
            break;
    }

    cout << "\t\tNumber of Doors: " << GetNumberDoors() << endl;
    cout << "\t\tTransmission: ";

    switch (GetTransmission()) {
        case 'A':
            cout << "Automatic\n";
            break;
        case 'M':
            cout << "Manual\n";
            break; 
        default:
            cout << "ERROR\n";
            break;
    }
}

void CCar::Drive(double numMiles) {
    Driving(numMiles, 0.4, "Car driving", "Ooops, out of fuel! Time to call a tow truck!");
}