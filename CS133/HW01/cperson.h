// ============================================================================
// File: cperson.h
// ============================================================================
// Programmer: Anthony Chavez
// Date: 8/26/2021
//
// Description:
//      This is the header file for the CPerson class.
// ============================================================================
#include <iostream>
#include <string.h>

using namespace std;

#ifndef CPERSON_HEADER
#define CPERSON_HEADER

class   CPerson
{
	public:
		// constructors
		CPerson();
		CPerson(char *name, int age);
		CPerson(CPerson &copy);
		~CPerson();

		// accessor functions
		int		GetAge() { return m_age; }
		char*	GetName() { return m_name; }
		void    SetAge(int age);
		void	SetName(char *name);

		// member functions
		void    	DisplayData(); // default to cout
		void    	GetData(); // default to cin
		bool    	operator== (const CPerson& a);
		bool 		operator>(const CPerson& a);

	private:
		char	*m_name;	// a char pointer to store a name
		int     m_age;      // an int to store the age
		
};

ostream&    operator<<(ostream &outStream, CPerson &a);
istream& 	operator >>(istream &inStream, CPerson &a);

#endif  // CPERSON_HEADER

