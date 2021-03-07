// ============================================================================
// file: cashRegisterFile.cpp
// ============================================================================
// Programmer: Anthony Chavez
// Date: 03/3/2021
// Class: CSCI 123 ("Intro to Programming Using C++")
// Time: 
// Instructor: Dr. Rodriguez
// Project: Cash Register Files
//
// Description:
// Modification of cashRegisterLoop.cpp that returns a recipt and reads input in from a file.
// ============================================================================
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
void CalculateTotal(double, double &, int, ofstream &);
void Payment(char answer, double total, ofstream &);
// Function Prototypes


// ==== main ==================================================================
//
// ============================================================================

int main(){
    int numberOfItems = 0;
    double salesTax, item, total;
    char answer;
    string fileText;
    ifstream myFile("items.txt");
    std::ofstream writeFile("Recipt.txt");

    writeFile.setf(ios::showpoint);
    writeFile.setf(ios::fixed);
    writeFile.precision(2);

    //Write header to recipt
    writeFile << "###########################################################\n\t\t\t\t\t\tRecipt\n";
    writeFile << "###########################################################\n";
    cout << "Items:\n";
    writeFile << "Items:\n";
    //read lines from file and insert them into item
    while (myFile >> item){
        numberOfItems++;
        CalculateTotal(item, total, numberOfItems, writeFile);
    }
    myFile.close();
    //calculate sales tax in california 
    salesTax = total * 0.075;
    printf("\nSubtotal: $%.2f\n", total);
    writeFile << "\nSubtotal: $" << total << endl;
    printf("Tax(7.75%): $%.2f\n", salesTax);
    writeFile << "Tax(7.75%): $" << salesTax << endl;
    printf("Total: $%.2f\n\n", total + salesTax);
    writeFile << "Total: $" << total + salesTax << endl << endl;
    printf("Cash or credit? Enter 'C' for Cash or 'T' for Credit: ");
    
    while (true)
    { 
        printf("Cash or credit? Enter 'C' for Cash or 'T' for Credit: ");
        cin >> answer;

        if (toupper(answer) == 'C' || toupper(answer) == 'T'){
            //Ends the program by asking for correct ammount cash from user or charging the cash to their credit card
            Payment(answer, total + salesTax, writeFile);
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

// ==== CalculateTotal ==================================================================
// This function Calculates the total value of each item and then prints the price of each item
// to the console as well as a text file named Recipt.txt
//
// Input:
//      item [DOUBLE]   -- Cost of an item passed into this function
//      &total  [DOUBLE] -- The total price of each item
//      &numItems  [INT] -- The total number of items read from the file.
//      &file  [ofstream] -- File steam used to write output to the Recipt
//
// Output:
//      None this function returns VOID
//
// ======================================================================================

void CalculateTotal(double item, double &total, int numItems, ofstream &file){
    file.setf(ios::showpoint);
    file.setf(ios::fixed);
    file.precision(2);

    printf("\t#%i: $%.2f\n", numItems, item);
    file << "\t#" << numItems << ": $" << item << endl; 
    total += item;
}

// ==== Payment ==================================================================
// This function handles how the user will pay for the items they have purchased and 
// Writes the total payed in the Recipt as well as the termial
//
// Input:
//      answer [CHAR]   -- The users choice if they will pay with Cash or Card
//      total  [DOUBLE] -- The total price with tax of the good purchased by the user
//      &file  [ofstream] -- File steam used to write output to the Recipt
//
// Output:
//      None this function returns VOID
//
// ============================================================================

void Payment(char answer, double total, ofstream &file){
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
        printf("Cash: $%.2f\n", cash);
        file << "Cash: $" << cash << endl;
        printf("Change: $%.2f\n", cash - total);
        file << "Change: $" << cash - total;
    }
    else if (toupper(answer) == 'T')
    {
        printf("Card Payment: $%.2f\n", total);
        file << "Card Payment: $" << total;
    }
}

