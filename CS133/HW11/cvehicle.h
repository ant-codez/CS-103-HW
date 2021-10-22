// ============================================================================
// File: cvehicle.h
// ============================================================================
// Header file for the CVehicle
// ============================================================================

#ifndef CVEHICLE_H
#define CVEHICLE_H

#include    <iostream>
#include	<string>

class   CVehicle
{
	public:
    	// constructors
    	CVehicle();
		CVehicle(std::string make, std::string model, std::string vehicleName,
                 double miles = 36000, double fuelLevel = 100,
                 char fuelType = 'G');

    	// member functions
    	std::string     GetMake() const;
        std::string     GetModel() const;
        std::string     GetVehicleName() const;
        char            GetFuelType() const;
        double          GetFuelLevel() const;
        double          GetNumMiles() const;
        void            SetMake(std::string make);
        void            SetModel(std::string model);
        void            SetVehicleName(std::string vehicleName);
        void            SetFuelType(char fuelType);
        void            SetFuelLevel(double fuelLevel);
        void            SetNumMiles(double miles);
        
        // Create the two functions below as pure virtual functions so that the
        // CVehicle class is an ABC
        void            Drive(double numMiles);
        void            DispVehicleInfo() const;

    protected:
        // protected data members
        double m_miles;

        // protected member function
        void    Driving(double numMiles, double fuelRate,
                        std::string methodTravel, std::string noFuelMesg);

	private:
        // private data members
   		string m_make;
        string m_model;
        string m_vehicleName;
        char m_fuelType;    // G>as, D>iesel, S>teamPowered
        double m_fuelLevel; // percentage (0% -> EMPTY and 100% -> FULL)
};

#endif  // CVEHICLE_H