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
#ifndef CGRADE_HEADER
#define CGRADE_HEADER

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

CGrade::CGrade(){

    std::cout << "Default Constructor!\n\n";

    m_quiz1 = 0;
    m_quiz2 = 0;
    m_midterm = 0;
    m_finalExam = 0;
    m_percent = 0;
    m_grade = 'F';
    strcpy(m_name, "NULL");
}

CGrade::CGrade(char name[256], double quiz1, double quiz2, double midterm, double final){

    std::cout << "Type Constructor!\n\n";

    strcpy(m_name, name);
    m_quiz1 = quiz1;
    m_quiz2 = quiz2;
    m_midterm = midterm;
    m_finalExam = final;
}

CGrade::CGrade(CGrade &cpy){

    std::cout << "Copy Constructor!\n\n";

    strcpy(m_name, cpy.m_name);
    m_quiz1 = cpy.m_quiz1;
    m_quiz2 = cpy.m_quiz2;
    m_midterm = cpy.m_midterm;
    m_finalExam = cpy.m_finalExam;
}

void CGrade::GetInfo(){
    std::cout << "Enter student's full name: ";
    std::cin.getline(m_name, 256);
    std::cout << "Enter Quiz 1 grade (out of 10): ";
    std::cin >> m_quiz1;
    std::cout << "Enter Quiz 2 grade (out of 10): ";
    std::cin >> m_quiz2;
    std::cout << "Enter midterm grade (out of 100): ";
    std::cin >> m_midterm;
    std::cout << "Enter final exam grade (out of 100): ";
    std::cin >> m_finalExam;
}

void CGrade::CalcGrade(){
    CalcPercent();
    
    //printf("PERCENT = %f\n", m_percent);
    
    if (m_percent >= 90){
        m_grade = 'A';
    }
    else if (m_percent >= 80){
        m_grade = 'B';
    }
    else if (m_percent >= 70){
        m_grade = 'C';
    }
    else if (m_percent >= 60){
        m_grade = 'D';
    }
    else if (m_percent < 60){
        m_grade = 'F';
    }
    else{
        std::cout << "ERROR CALCULATING GRADE\n";
    }
}

void CGrade::CalcPercent(){
    double quiz = ((m_quiz1 + m_quiz2) / 20) * 25;
    double midTerm = (m_midterm / 100) * 25;
    double final = (m_finalExam / 100) * 50;
    m_percent = quiz + midTerm + final;
}

void CGrade::DispGrade(){
    printf("%s: %.1f%% %c\n", m_name, m_percent, m_grade);
}

#endif  // CGRADE_HEADER