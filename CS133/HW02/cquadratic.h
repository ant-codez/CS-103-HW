// ============================================================================
// File: cquadratic.h
// ============================================================================
// Programmer: Anthony Chavez
// Date: 9/4/2021
//
// Description:
//      This is the header file for the CQuadratic class.
// ============================================================================

#ifndef CQUADRATIC_HEADER
#define CQUADRATIC_HEADER

class CQuadratic
{
  public:
    CQuadratic(int a, int b, int c);
    ~CQuadratic();

    float Evaluate(float x);

  private:
    int c1;
    int c2;
    int c3;
};

#endif