// ============================================================================
// File: ctruck.h
// ============================================================================
// Header file for the CTruck
// ============================================================================

#ifndef CTRUCK_H
#define CTRUCK_H

#include        <iostream>
#include        <string>

class   CTruck : public CCar
{
	public:
    	// constructors
    	CTruck();
	CTruck(std::string make, std::string model, std::string vehicleName,
        char transmission = 'A', int numDoors = 4,
        double miles = 97350, double fuelLevel = 98, char fuelType = 'D',
        char cabSize = 'C', std::string bedSize = "Short",
        bool fourWD = false);

    	// member functions
        char            GetCabSize() const { return m_cabSize; };
        std::string     GetBedSize() const { return m_bedSize; };
        bool            GetFourWD() const { return m_fourWD; };
        void            SetCabSize(char cabSize) { m_cabSize = cabSize; };
        void            SetBedSize(std::string bedSize) { m_bedSize = bedSize; };
        void            SetFourWD(bool fourWD) { m_fourWD = fourWD; };

        // 2 virtual functions needed
        virtual void            Drive(double numMiles);
        virtual void            DispVehicleInfo() const;

	private:
        // private data members
   	char m_cabSize; 		// S>ingle Cab, Q>uad Cab, C>rew Cab
        std::string m_bedSize; 	// "Long" 8 feet, "Standard" 6.5 feet, 
                               	// "Short" 5.7 feet
        bool   m_fourWD; 		// True if four-wheel-drive, false otherwise
};

#endif  // CTRUCK_H