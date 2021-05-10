// ============================================================================
// file: main.cpp
// ============================================================================
// Programmer: Anthony Chavez
// Date: 5/9/2021
// Class: CSCI 123 ("Intro to Programming Using C++")
// Instructor: Dr. Rodriguez
// Project: HW16: CPizza Destructors
//
// Description:
// This program takes three orders of pizza using the constructors.  Each order 
// will invoke the default, type, and copy constructor (in that order). 
// ============================================================================

#include <iostream>
#include <cstring>
#include "cpizza.h"
using namespace std;



// ==== main ==================================================================
//
// ============================================================================

int     main()
{
        // Member variables
        char name[256];
        char ans;
        int large, med, small;
        CPizza  C1; // default

        // prompt the user for their pizzas and assign to private members
        cout << "Will this be for delivery (Y/N)? ";
        cin >> ans;

        if (toupper(ans) == 'Y')
                C1.SetDelivery(true);
        else
                C1.SetDelivery(false);

        cout << "How many large pizzas? ";
        cin >> large;
        C1.SetLPizza(large);

        cout << "How many medium pizzas? ";
        cin >> med;
        C1.SetMPizza(med);

        cout << "How many small pizzas? ";
        cin >> small;
        C1.SetSPizza(small);

        cout << "What is your name? ";
        cin >> name;
        C1.SetName(name);

        // calculate the cost for order 1
        //C1.DispOrder();

        // create a second object by calling the type constructor
        // and only providing a name as an argument
        CPizza C2("Thanos");

        // create a third object by calling the copy constructor and providing
        // order1 as an argument
        CPizza C3(C1);

        // change the name and set 1 for each size of the pizza and no delivery
        C3.SetName("Deadpool");
        C3.SetLPizza(1);
        C3.SetMPizza(1);
        C3.SetSPizza(1);
        C3.SetDelivery(false);
        C3.SetDeliveryFee(0);

        // display the orders
        cout << "Order 1: \n\n";
        C1.DispOrder();

        cout << "Order 2: \n\n";
        C2.DispOrder();

        cout << "Order 3: \n\n";
        C3.DispOrder();

        return 0;
}   // end of "main"
