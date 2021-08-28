// ============================================================================
// file: main.cpp
// ============================================================================
// Programmer: ???
// Date: ???
// Class: CSCI 123 ("Intro to Programming Using C++")
// Time: ???
// Instructor: Dr. Rodriguez
// Project: ???
//
// Description:
//      ???
//
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
        CPizza  order1; // default
        int     pizza;
        char    name[LEN];
        char    delivery;

        // prompt the user for their pizzas and assign to private members
        cout << "Will this be for delivery (Y/N)? ";
        cin >> delivery;
        if (toupper(delivery) == 'Y')
        {
                order1.SetDelivery(true);
        }
        else
        {
                order1.SetDelivery(false);
        }

        cout << "How many large pizzas? ";
        cin >> pizza;
        order1.SetLPizza(pizza);

        cout << "How many medium pizzas? ";
        cin >> pizza;
        order1.SetMPizza(pizza);

        cout << "How many small pizzas? ";
        cin >> pizza;
        order1.SetSPizza(pizza);

        cout << "What is your name? ";
        cin.ignore();
        cin.getline(name, LEN);
        order1.SetName(name);

        // calculate the cost
        order1.CalcCost();

        // create a second, third, and fourth object
        CPizza  order2(order1);
        CPizza  order3;
        CPizza  order4;

        // change the name and set 1 for each side of the pizza and no delivery
        strcpy(name, "Deadpool");
        order2.SetName(name);
        order2.SetLPizza(1);
        order2.SetMPizza(1);
        order2.SetSPizza(1);
        order2.SetDelivery(false);
        order2.CalcCost();

        // display the orders
        cout << "Order 1: \n\n";
        order1.DispOrder();

        cout << "Order 2: \n\n";
        order2.DispOrder();

        // overload the = operator
        order1 = order2;
        order2 = order2;
        order4 = order3 = order2;

        // display the orders one more time
        cout << "Displaying the results after the assignment operator...\n\n";
        cout << "Order 1: \n\n";
        order1.DispOrder();

        cout << "Order 2: \n\n";
        order2.DispOrder();

        cout << "Order 3: \n\n";
        order3.DispOrder();

        cout << "Order 4: \n\n";
        order4.DispOrder();

        return 0;
}   // end of "main"
