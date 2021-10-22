// ============================================================================
// File: ccar.h
// ============================================================================
// Header file for the CCar
// ============================================================================

#ifndef CCAR_H
#define CCAR_H

#include    <iostream>
#include	<string>

class   CCar
{
	public:
    	// constructors
    	CCar();
		CCar(std::string make, std::string model, std::string vehicleName,
             char transmission = 'M', int numDoors = 2,
             double miles = 57000, double fuelLevel = 63, char fuelType = 'G');

    	// member functions
        char            GetTransmission() const;
        int             GetNumberDoors() const;
        void            SetTransmission(char transmission);
        void            SetNumDoors(int numDoors);
        
        // 2 virtual functions needed
        ???
        ???

	private:
        // private data members
   		char m_transmission; // A>utomatic or M>anual
        int m_numDoors;
};

#endif  // CCAR_H