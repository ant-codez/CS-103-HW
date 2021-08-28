// ============================================================================
// File: cpizza.h
// ============================================================================
// Programmer: Anthony Chavez   
// Date: 4/10/2020
//
// Description:
// Header file containing the class and member functions and private variables associated
// with it.
// ============================================================================
#ifndef CPIZZA_HEADER
#define CPIZZA_HEADER

class   CPizza
{
public:
        // constructors
        CPizza();       // default constructor
        CPizza(int small, int medium, int large, char name[256]);             // type constructor
        CPizza(CPizza &otherObject);               // copy constructor

        // member functions
        void    GetInfo();
        void    CalculatePrice();

private:
        // data members
        int     m_SPizza;
        int     m_MPizza;
        int     m_LPizza;
        double  m_total;
        bool    m_delivery;
        char    m_name[256];
        double  m_delivery_fee;
        double  m_sales_tax;

};

#endif  