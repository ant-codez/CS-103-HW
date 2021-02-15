// ============================================================================
// file: cashRegisterFunc.cpp
// ============================================================================
// Programmer: Anthony Chavez
// Date: 02/14/2021
// Class: CSCI 123 ("Intro to Programming Using C++")
// Time: 
// Instructor: Dr. Rodriguez
// Project: Cash Register Function
//
// Description:
//      This project is a modification of our previous project cashRegisterLoop.cpp
//      The user is prompted to enter in the ammount of items they would like to purchase
//      The user is also prompted to input the cash value of each item he selected.
//      The sum of all products and tax is displayed on to the screen and then the 
//      user will choose to pay with Cash or Credit. If they pay with credit the program
//      closes, else it will ask the user to enter in the cash amount of the all the good or
//      an ammount greater than that.
// ============================================================================
#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

// Function Prototypes
double  ItemScan(int items);
void    Payment(char answer, double total);

// ==== main ==================================================================
//
// ============================================================================

int main(){
    int numberOfItems;
    float salesTax;
    double total;
    char answer;

    //This loop ensures that the input will always be "correct"
    while (true){
        printf("Please enter the number of items you will purchase: ");
        if (cin >> numberOfItems){
            //ItemScan will prompt the user to enter in the price of each item and return the sum of each item
            total = ItemScan(numberOfItems);
            break;
        }
        else{
            printf("Incorrect input: Not a number\n");
            //Clear the error flag on cin so future I/O operations will work correctly
            cin.clear();
            //Skip to next newline
            cin.ignore(INT_MAX, '\n');
        }
    }

    cout << endl;
    salesTax = total * 0.0075;
    printf("Subtotal: $%.2f\nTax (7.75%): $%.2f\nTotal: $%.2f\n\n", total, salesTax, total + salesTax);
    total += salesTax;
    

    while (true)
    { 
        printf("Cash or credit? Enter 'C' for Cash or 'T' for Credit: ");
        cin >> answer;

        if (toupper(answer) == 'C' || toupper(answer) == 'T'){
            //Ends the program by asking for correct ammount cash from user or charging the cash to their credit card
            Payment(answer, total);
            break;
        }
        else{
            printf("Incorrect selection: Not 'C' or 'T'\n");
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }

    return (0);
}

// ==== ItemScan ==================================================================
// This function calculates the sum of all products entered by the user.
//
// Input:
//      items [INT]  -- an integer value of the total number of products the user bought
//
// Output:
//      The sum of all products (Double) the user has provided us in the command line.
//
// ============================================================================

double ItemScan(int items){
    float cost;
    float rtotal;

    //For loop used to add up total cost while the nested while loop prevents the user from
    //entering incorrect input 
    for (int i = 0; i < items; i++) {
        printf("Please enter the cost of item #%i : $", i+1);
        while (!(cin >> cost)){
            printf("Incorrect input: Must be a dollar ammount\n");
            printf("Please enter the cost of item #%i : $", i+1);
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        rtotal += cost;
    }
    printf("Total = %f\n", rtotal);
    return ((double)rtotal);
}

// ==== Payment ==================================================================
// This function handles how the user will pay for the items they have purchased
//
// Input:
//      answer [CHAR]   -- The users choice if they will pay with Cash or Card
//      total  [DOUBLE] -- The total price with tax of the good purchased by the user
//
// Output:
//      None this function returns VOID
//
// ============================================================================

void Payment(char answer, double total){
    double cash;

    if (toupper(answer) == 'C')
    {
        //This while loop is used to stop a user from inputing an incorrect input or
        //Not enough cash to cover the cost of their items.
        while (true)
        {
            printf("Please enter amount of Cash: $");
            cin >> cash;
            if (cash < total)
            {
                printf("Not enough Cash, Please enter an amount greater than or equal to $%.2f\n", total);
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
            else
            {
                break;
            } 
        }
        printf("Change: $%.2f\n", cash - total);
    }
    else if (toupper(answer) == 'T')
    {
        printf("Card Payment: $%.2f\n", total);
    }
}
