// ============================================================================
// File: cquadratic.cpp
// ============================================================================
// Programmer: Anthony Chavez
// Date: 9/4/2021
//
// Description:
//      This is the cpp file for the CQuadratic class.
// ============================================================================

#include "cquadratic.h"
#include <iostream>
#include <string.h>

using namespace std;

//Type constructor
CQuadratic::CQuadratic(int a, int b, int c){
    cout << "CQuadratic Constructor!\n\n";

    c1 = a;
    c2 = b;
    c3 = c;
}

//Destructor
CQuadratic::~CQuadratic() {
    cout << "CQuadratic destructor!!!";
}

float CQuadratic::Evaluate(float x) {
    float total = 0;

    total += (x * x) * c1;
    total += (c2 * x);
    total += c3;

    return total;
}