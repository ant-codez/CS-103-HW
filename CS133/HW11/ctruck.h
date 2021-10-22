// ============================================================================
// File: ctruck.h
// ============================================================================
// Header file for the CTruck
// ============================================================================

#ifndef CTRUCK_H
#define CTRUCK_H

#include    <iostream>
#include	<string>

class   CTruck
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
        char            GetCabSize() const;
        std::string     GetBedSize() const;
        bool            GetFourWD() const;
        void            SetCabSize(char cabSize);
        void            SetBedSize(std::string bedSize);
        void            SetFourWD(bool fourWD);

        // 2 virtual functions needed
        ???
        ???

	private:
        // private data members
   		char m_cabSize; 		// S>ingle Cab, Q>uad Cab, C>rew Cab
        std::string m_bedSize; 	// "Long" 8 feet, "Standard" 6.5 feet, 
                               	// "Short" 5.7 feet
        bool   m_fourWD; 		// True if four-wheel-drive, false otherwise
};

#endif  // CTRUCK_H