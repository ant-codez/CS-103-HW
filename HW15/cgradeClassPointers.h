// ============================================================================
// File: cgrade.h
// ============================================================================
// Programmer: Anthony Chavez   
// Date: 4/10/2020
//
// Description:
// Header file containing the class and member functions and private variables associated
// with it.
// ============================================================================
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#ifndef CGRADE_CLASS_POINTERS_HEADER
#define CGRADE_CLASS_POINTERS_HEADER

class   CGrade
{
public:
        // constructors
        CGrade();       // default constructor
        CGrade(char name[256], double quiz1, double quiz2, double midterm, double final);             // type constructor
        CGrade(CGrade &otherObject);               // copy constructor

        // member functions
        void    GetInfo();
        void    CalcGrade();
        void    CalcPercent();
        void    DispGrade();
        CGrade* MakeCGrade(char[256], double, double, double, double);
        void    ShowGrade(CGrade*);

private:
        // data members
        char    m_name[256];
        double  m_quiz1;
        double  m_quiz2;
        double  m_midterm;
        double  m_finalExam;
        double  m_percent;
        char    m_grade;
};



#endif  // CGRADE_HEADER