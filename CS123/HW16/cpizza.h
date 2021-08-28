// ============================================================================
// File: cpizza.h
// ============================================================================
// Programmer: Anthony Chavez
// Date: 5/9/2021
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
        CPizza(); // default
        CPizza(char* name, int large = 0, int med = 0, int small = 0, double cost = 0, bool delivery = false, double delivery_fee = 0); // type
        CPizza(char* name);
        CPizza(CPizza &copy); // copy
        ~CPizza(); // destructor

        // member functions
        void            SetLPizza(int number) {*m_LPizza = number;}
        void            SetMPizza(int number) {*m_MPizza = number;}
        void            SetSPizza(int number) {*m_SPizza = number;}
        void            SetDelivery(bool del) {*m_delivery = del;}
        void            SetDeliveryFee(double fee) {*m_deliveryFee = fee;}

        void            SetName(char *name) {   m_name = new char[strlen(name) + 1];
                                                strcpy(m_name, name);
                                            }

        int             GetLPizza() const {return *m_LPizza;}
        int             GetMPizza() const {return *m_MPizza;}
        int             GetSPizza() const {return *m_SPizza;}
        bool            GetDelivery() const {return *m_delivery;}
        double          GetDeliveryFee() const {return DFEE;}
        char*           GetName() const {return m_name;}
        double          GetTotal() const {return *m_cost;}
        void            DispOrder();
        void            GetInfo();

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
