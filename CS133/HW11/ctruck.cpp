// ============================================================================
// File: ctruck.cpp
// ============================================================================
// This is the implementation file for CTruck.
// ============================================================================

#include    <iostream>
#include	<string>
using namespace std;

#include    "cvehicle.h"
#include    "ccar.h"
#include    "ctruck.h"



// ==== Default Constructor ===================================================
//
// The default constructor sets make and model to "Ford" and "F150"
// respectively. 
// It also sets vehicle name to "Turbofire", fuel type to D>iesel,
// fuel level to 37%, 210154 miles, transmission to A>utomatic, 4 number of
// doors, cab size is single, bed size is standard, and it is not four-wheel-
// drive.
//
// ============================================================================

CTruck::CTruck() {
    SetMake("Ford");
    SetModel("F150");
    SetVehicleName("Turbofire");
    SetFuelType('D');
    SetFuelLevel(37);
    SetNumMiles(210154);
    SetTransmission('A');
    SetNumDoors(4);
    m_cabSize = 'S';
    m_bedSize = "Standard";
    m_fourWD = false;
}



// ==== Type Constructor ======================================================
//
// The type constructor assigns the values passed as arguments during
// declaration
//
// ============================================================================

CTruck::CTruck(std::string make, std::string model, std::string vehicleName,
        char transmission, int numDoors, double miles, double fuelLevel, 
        char fuelType, char cabSize, std::string bedSize, bool fourWD) {

    SetMake(make);
    SetModel(model);
    SetVehicleName(vehicleName);
    SetFuelType(fuelType);
    SetFuelLevel(fuelLevel);
    SetNumMiles(miles);
    SetTransmission(transmission);
    SetNumDoors(numDoors);
    m_cabSize = cabSize;
    m_bedSize = bedSize;
    m_fourWD = fourWD;
}




// 2 virtual functions implmentation below
void CTruck::Drive(double numMiles) {
    Driving(numMiles, 1, "Truck Driving", "Ooops, out of fuel! Time to call a very large tow truck!");
}

void CTruck::DispVehicleInfo() const {
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
        case 'D':
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

    cout << "\t\tCab Size: ";

    switch (GetCabSize()) {
        case 'C':
            cout << "Crew\n";
            break;
        case 'S':
            cout << "Single\n";
            break; 
        default:
            cout << "ERROR\n";
            break;
    }

    cout << "\t\tBed Size: " << GetBedSize() << endl;
    cout << "\t\tFour Wheel Drive: ";

    if (GetFourWD()){
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
}