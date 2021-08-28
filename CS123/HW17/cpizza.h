// ============================================================================
// File: cpizza.h
// ============================================================================
// Programmer: ???
// Date: ???
//
// Description:
//      This is the header file for the CPizza class.
// ============================================================================

#ifndef CPIZZA_HEADER
#define CPIZZA_HEADER
#include <cstring>
// constant grade values
const   double  TAX = 0.0775;   // taxes
const   double  LPIZZA = 20.0;  // price of a large pizza
const   double  MPIZZA = 15.0;  // price of a medium pizza
const   double  SPIZZA = 10.0;  // price of a small pizza
const   double  DFEE = 5.0;     // delivery fee
const   int             LEN = 256; // name length

class   CPizza
{
public:
        // constructors
        CPizza(void); // default
        CPizza(char *name, int LPizza = 0, int MPizza = 0, int SPizza = 0,
                   double cost = 0, bool delivery = false, double deliveryFee = 0); // type
        CPizza(const CPizza &object); // copy
        ~CPizza(); // destructor

        // member functions
        void    SetLPizza (int pizza) {*m_LPizza = pizza;}
        void    SetMPizza (int pizza) {*m_MPizza = pizza;}
        void    SetSPizza (int pizza) {*m_SPizza = pizza;}
        void    SetDelivery (bool delivery) {*m_delivery = delivery;}
        void    SetDeliveryFee (double fee) {*m_deliveryFee = fee;}
        void    SetName(char *name) {   m_name = new char[strlen(name) + 1];
                                        strcpy(m_name, name);
                                    }
        int     GetLPizza (void) const {return *m_LPizza;}
        int     GetMPizza (void) const {return *m_MPizza;}
        int     GetSPizza (void) const {return *m_SPizza;}
        bool    GetDelivery (void) const {return *m_delivery;}
        double  GetDeliveryFee (void) const {return *m_deliveryFee;}
        char*   GetName (void) const {return m_name;}
        double  GetTotal (void) const {return *m_cost;}
        void    CalcCost (void);
        void    DispOrder (void);
        CPizza&    operator=(const CPizza &obj); // overloaded assignment operator prototype
        //void    operator=(const CPizza &obj);
private:
        // data members
        int     *m_LPizza;
        int     *m_MPizza;
        int     *m_SPizza;
        double  *m_cost;
        bool    *m_delivery;
        double  *m_deliveryFee;
        char    *m_name;
};

#endif  // CPIZZA_HEADER
