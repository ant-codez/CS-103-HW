// ============================================================================
// File: patientAnalysis.cpp
// ============================================================================
// Programmer: Anthony Chavez
// Date: 9/19/2021
// Class: CSCI 133 ("Data Structures Using C++")
// Instructor: Dr. Rodriguez
// Project: Patient Analysis
//
// This program is an exercise in working with two-dimensional arrays and
// pointers-to-pointers. It is a hypothetical situation working with patient
// data (10 Patients total).  The idea is you want to write a program that will
// isolate a person who has a high (or low) feature (i.e. Max amount of weight
// or minimum pulse).

// A two-dimensional array of doubles is allocated from the stack and
// initialized in main. In addition a one-dimensional array of strings is
// allocated from the stack and initialzed in main. The two-dimensional array
// is passed to AbnormalCategory, along with the number of rows, the address of
// a local pointer-to-a-double, an int to represent a category in question, and
// a bool value. After the function returns, the local int pointer should be
// pointing to the array (Person) with the largest sum.
//
// Output:
//      ID#     Height      Weight      Temp    Pulse   Calcium     Potassi     Sodium
//      7       73          183         94.2    36      9.1         3.8         144
//
//      Patient has a min Temp of 94.2
//
// ============================================================================

#include    <iostream>
#include    <string>
#include    <float.h>
using namespace std;


// constants
const int NUM_PATIENTS = 10;
const int NUM_CLINICAL_DATA  = 8;


// function prototypes
void DispPatientInfo(double *arrayPtr, const int NUM_CLINICAL_DATA, string heading[]);
double  AbnormalCategory(double patientData[NUM_PATIENTS][NUM_CLINICAL_DATA], 
const int NUM_PATIENTS, double** arrayPtr, int catInterest, bool max);


// ==== main ==================================================================
//
// ============================================================================

int     main()
{
    // declare variables
    double      patientData[NUM_PATIENTS][NUM_CLINICAL_DATA] =
                    {  {1, 67, 147, 101.1,  79,  8.8, 3.5, 141}
                    ,  {2, 66, 270, 103.9, 120,  8.4, 3.7, 136}
                    ,  {3, 78, 232, 104.7,  49,  9.7, 5.2, 143}
                    ,  {4, 69, 284, 100.3, 104,  9.4, 3.8, 142}
                    ,  {5, 75, 215,  99.9,  45,  9.5, 4.9, 137}
                    ,  {6, 63, 155,  97.4,  90, 10.1, 3.7, 140}
                    ,  {7, 73, 183,  94.2,  36,  9.1, 3.8, 144}
                    ,  {8, 65, 180, 102.1, 102,  9.6, 4.8, 138}
                    ,  {9, 76, 152,  95.6,  96,  8.6, 4.2, 145}
                    , {10, 71, 213,  98.2,  92, 10.2, 3.9, 135}
                   };

    string      heading[NUM_CLINICAL_DATA] =
                    { "ID#"         // ID # of the patient
                    , "Height"      // Height in inches
                    , "Weight"      // Weight in pounds
                    , "Temp"        // Temperature in Fahrenheit
                    , "Pulse"       // Pulse Per Minute
                    , "Calcium"     // Calcium Levels
                    , "Potassi"     // Potassium Levels
                    , "Sodium"      // Sodium Levels
                    };
    double      *arrayPtr;
    double      value;
    bool        max;
    int         catInterest; // category of interest
                             // [1 through NUM_CLINICAL_DATA - 1]
    // Assign values to variables
    catInterest = 3; // interested in Temperature
    max = false; // True means find the max. False means find min.

    value = AbnormalCategory(patientData, NUM_PATIENTS, &arrayPtr,
                             catInterest, max);

    // Display Data
    DispPatientInfo(arrayPtr, NUM_CLINICAL_DATA, heading);


    if (max)
    {
        cout << "\nPatient has a max " << heading[catInterest]
             << " of " << value << endl << endl;
    }
    else
    {
        cout << "\nPatient has a min " << heading[catInterest]
             << " of " << value << endl << endl;
    }

    return  0;

}  // end of "main"



// ==== DispPatientInfo =======================================================
//
// This function displays the patient's record
//
// Input:
//
//       arrayPtr [DOUBLE] -- pointer to the array selected by AbnormalCategory
//
//       NUM_CLINICAL_DATA [INT] -- A constant integer variable that contains the
//       number of total data in the arrayPtr 
//
//       heading[] [STRING] -- An array of Strings which label the Data in arrayPtr
// Output:
//       The Output will be printed to the commandline with the Catagory printed with
//       the values for each catagory below them
// ============================================================================
void DispPatientInfo(double *arrayPtr, const int NUM_CLINICAL_DATA, string heading[]) {

    for (int i = 0; i < NUM_CLINICAL_DATA; i++){
        cout << heading[i] << "\t";
    }

    printf("\n");

    for (int i = 0; i < NUM_CLINICAL_DATA; i++){
        cout << arrayPtr[i] << "\t";
    }

    printf("\n");
}



// ==== AbnormalCategory ======================================================
//
// This function goes through all the patients records and finds the patient
// who has the MAX or MIN amount of a particular category of interest.  That
// interest could be their weight, height, et cetera. The function returns the
// value of interest.
//
// Input:
//      patientData** [DOUBLE] -- a two dimensional array holding the data we want
//      to look through
//
//      NUM_PATIENTS [INT] -- constant value which holds the total number of patients
//
//      arrayPtr* [DOUBLE] -- pointer to the patientData array
//      
//      catInterest [INT] -- Selector for the catagory to be picked in the patientData array
//
//      max [BOOL] -- A True value tells the function to return the MAX amount,
//      false means to return the MIN ammount
// Output:
//      value [DOUBLE] -- Either a MIN or MAX value from the patientData array
//
// ============================================================================

double AbnormalCategory(double patientData[NUM_PATIENTS][NUM_CLINICAL_DATA], 
const int NUM_PATIENTS, double **arrayPtr, int catInterest, bool max) {
    double value = 0;

    if (max){
        value = 0;
    }
    else{
        value = DBL_MAX;
    }

    for (int i = 0; i < NUM_PATIENTS; i++){
        if (max){
            if (patientData[i][catInterest] > value){
                value = patientData[i][catInterest];
                *arrayPtr = &patientData[i][0];
            }
        }
        else{
            if (patientData[i][catInterest] < value){
                value = patientData[i][catInterest];
                *arrayPtr = &patientData[i][0];
            }
        }
    }
    return value;
}