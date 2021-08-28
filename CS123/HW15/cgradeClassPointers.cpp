
#include "cgradeClassPointers.h"

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

CGrade* CGrade::MakeCGrade(char name[256], double quiz1, double quiz2, double midterm, double final){
    CGrade *temp = new CGrade(name, quiz1, quiz2, midterm, final);

    printf("NAME = %s\nQUIZ1 = %d\nQUIZ2 = %d\nMIDTERM = %d\nFINAL = %d\n", temp->m_name, temp->m_quiz1, temp->m_quiz2, midterm, final);

    return temp;
}

void CGrade::ShowGrade(CGrade *obj) {
    std::cout << "(Using the ShowGrade function...)\n";
    obj->DispGrade();
}