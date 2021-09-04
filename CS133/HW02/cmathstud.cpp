// ============================================================================
// File: cmathstud.h
// ============================================================================
// Programmer: Anthony Chavez
// Date: 9/4/2021
//
// Description:
//      This is the cpp file for the CMathStud class.
// ============================================================================

#include "cmathstud.h"
#include <iostream>
#include <string.h>

using namespace std;

//Type constructor
CMathStud::CMathStud(int a, int b, int c)
: QE(a, b, c) //initializer list to allow QE to be initalized without default constructor
{
    cout << "CMathStud constructor!!!\n\n";
}

//Destructor
CMathStud::~CMathStud(){
    cout << "CMathStud Destructor!!!\n\n";
}

float CMathStud::getMyValue(float x){
    return QE.Evaluate(x);
}