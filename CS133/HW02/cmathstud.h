// ============================================================================
// File: cmathstud.h
// ============================================================================
// Programmer: Anthony Chavez
// Date: 9/4/2021
//
// Description:
//      This is the header file for the CMathStud class.
// ============================================================================

#include "cquadratic.h"
#ifndef CMATHSTUD_HEADER
#define CMATHSTUD_HEADER


class CMathStud
{
  public:
    CMathStud(int a, int b, int c = 0);
    ~CMathStud();
    float getMyValue(float x);

  private:
    CQuadratic QE;
};

#endif
