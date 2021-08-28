// ============================================================================
// file: piCalc.cpp
// ============================================================================
// Programmer: Anthony Chavez
// Date:
// Class: CSCI 123 ("Intro to Programming Using C++")
// Time:
// Instructor: Dr. Rodriguez
// Project: Pi Calculation
//
// Description:
//      This program calculate the value of pi through iteration or
// approximation.
//
// ============================================================================

#include <iostream>
#include <cctype>
#include <cmath>
#include <stdio.h>
using namespace std;

// Function Prototypes
void    Iterate(int iter);
void    DecimalApprox(int approx);
void    DisplayPi(int signif, double pi);

// ==== main ==================================================================
//
// ============================================================================

int     main()
{

        // variables
        char answer;
        int numOfLoops;
        // Prompt the user if they want to iterate or have a decimal approx.
        cout << "\nThis program calculates the number Pi.\n\n";

        // Create a do while loop to prompt the user for Iteration or Approx.
        // Loop until the user enters the correct selection
        while (true){
                cout << "Would you like to calculate it through I>teration or ";
                cout << "A>pproximation: ";
                if (cin >> answer){
                    if (tolower(answer) == 'a' || towlower(answer) == 'i'){
                        break;
                    }
                    else{
                        printf("Incorrect Selection. Try again...\n");
                        cin.clear();
                        cin.ignore(42, '\n');
                    }
                }
                else{
                    printf("Incorrect Selection. Try again...\n");
                    cin.clear();
                    cin.ignore(42, '\n');
                }
        }

        // If it is iteration, ask how many iterations and call the
        // Iterate function.
        if (towlower(answer) == 'i'){
                while (true){
                        // Prompt the user of how many iterations
                        cout << "How many iterations?: ";
                        if (cin >> numOfLoops){
                                // Call the Iterate function
                                Iterate(numOfLoops);
                                break;
                        }
                        else {
                                printf("Incorrect Selection. Try again...\n");
                                cin.clear();
                                cin.ignore(42, '\n');
                        }
                }
        }
        // If it is approximation, ask the number of approximation and call
        // the DecimalApprox function
        else
        {
                while (true){
                        // Prompt the user of decimal approximation
                        cout << "How many decimals of approximation?: ";
                        if (cin >> numOfLoops){
                                // Call the DecimalApprox function
                                DecimalApprox(numOfLoops);
                                break;
                        }
                        else {
                                printf("Incorrect Selection. Try again...\n");
                                cin.clear();
                                cin.ignore(42, '\n');
                        }
                }
        }
        return 0;
}   // end of "main"



// ==== Iterate ===============================================================
//
// This function calcuates pi through iteration
//
// Input:
// iter [IN] -- an integer value containing the number of iterations
//
// Output:
// The value of pi.
//
// ============================================================================

void    Iterate(int iter)
{
        float pi; // variables
        int sign = 1;

        // do a loop to calculate pi based on the number of iterations
        for (int i = 0; i < iter; i++)
        {
                pi += sign / (2.0 * i + 1);
                sign *= -1;
        }

        // Call the DisplayPi function.
        // default to 5 digit significance for iteration
        DisplayPi(5, 4.0 * pi);

} // end of "Iterate"



// ==== DecimalApprox ==========================================================
//
// This function calcuates pi through decimal approximation
//
// Input:
// approx [IN] -- an integer value containing the approximation
//
// Output:
// The value of pi.
//
// ============================================================================

void    DecimalApprox(int approx)
{
        int i = 0;
        int sign = 1; // variables
        double  piVal = 0.0;             // Pi value
        double  previousPi = piVal;     // Previous pi value

        // loop to calculate pi based on the approx value of signif. digits.
        do{
                // calculate PI
                piVal += sign / (2.0 * i + 1);
                sign *= -1;

                // check if the significance has changed within 1 decimial appro                                                               x.
                // if so break out of the loop
                if (abs(piVal * 4.0 - previousPi *4.0) <= pow(10.0, -1.0 * approx))
                {
                        piVal *= 4.0;
                        break;
                }

                // update previousPi and increment i
                i++;
                previousPi = piVal;
        } while (true);

        // Call the DisplayPi function.
        // default to approx digit significance for iteration
        DisplayPi(approx, piVal);

} // end of "DecimalApprox"



// ==== DisplayPi =============================================================
//
// This function displays the value of pi.
//
// Input:
// signif [IN] -- an integer value containing the number of digit significance
// pi     [IN] -- a double value containing the value of pi.
//
// Output:
// void
//
// ============================================================================

void    DisplayPi(int signif, double pi)
{
        // settings for digit precision
        cout.setf(ios::showpoint);
        cout.setf(ios::fixed);
        cout.precision(signif);

        // display the value of pi
        cout << "The value of Pi is: " << pi << endl << endl;
} // end of "DisplayPi"