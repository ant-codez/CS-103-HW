// ============================================================================
// file: main.cpp
// ============================================================================
// Programmer: Anthony Chavez
// Date: 5/9/2021
// Class: CSCI 123 ("Intro to Programming Using C++")
// Instructor: Dr. Rodriguez
// Project: HW16: CPizza Destructors
//
// Description:
// This file contains all the functions that the CPizza class uses.
//
// ============================================================================

#include "cpizza.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <iomanip>
using namespace std;

//default construstor
CPizza::CPizza(){
    printf("Default constructor...\n");

    m_LPizza = new int;
    m_MPizza = new int;
    m_SPizza = new int;
    m_cost = new double;
    m_delivery = new bool;
    m_deliveryFee = new double;
    m_name = new char[5];
    strcpy(m_name, "NULL");
}

//type constructor
CPizza::CPizza(char* name, int large, int med, int small, double cost, bool delivery, double fee){
    printf("Type constructor...\n");

    m_LPizza = new int;
    *m_LPizza = large;

    m_MPizza = new int;
    *m_MPizza = med;

    m_SPizza = new int;
    *m_SPizza = small;

    m_cost = new double;
    *m_cost = cost;

    m_delivery = new bool;
    *m_delivery = delivery;

    m_deliveryFee = new double;
    *m_deliveryFee = DFEE;

    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
}

//copy constructor
CPizza::CPizza(const CPizza &cpy){
    printf("Copy constructor...\n");

    m_LPizza = new int;
    *m_LPizza = cpy.GetLPizza();
    m_MPizza = new int;
    *m_MPizza = cpy.GetMPizza();
    m_SPizza = new int;
    *m_SPizza = cpy.GetSPizza();
    m_cost = new double;
    *m_cost = cpy.GetTotal();
    m_delivery = new bool;
    *m_delivery = cpy.GetDelivery();
    m_deliveryFee = new double;
    *m_deliveryFee = cpy.GetDeliveryFee();
    m_name = new char[strlen(cpy.GetName()) + 1];
    strcpy(m_name, cpy.GetName());
}

//class destructor
CPizza::~CPizza(){

    cout << "Destructor!\n";
    
    delete m_LPizza;
    delete m_MPizza;
    delete m_SPizza;
    delete m_cost;
    delete m_delivery;
    delete m_deliveryFee;
    delete m_name;
}

void CPizza::CalcCost(){
    //total
    *m_cost = (*m_SPizza * 10) + (*m_MPizza * 15) +(*m_LPizza * 20);
    double tax = *m_cost * TAX;
    //delivery fee is non taxable
    *m_cost += (tax + *m_deliveryFee);

}

void CPizza::DispOrder(){
    //set precision to 2 decimal points
    std::cout << std::fixed << std::setprecision(2);

    //Show order to customers
    std::cout << m_name << std::endl;
    std::cout << "\t" << *m_LPizza << " Large Pizza(s)\n";
    std::cout << "\t" << *m_MPizza << " Medium Pizza(s)\n";
    std::cout << "\t" << *m_SPizza << " Small Pizza(s)\n";
    std::cout << "\t" << "Delivery: ";

    if (*m_delivery)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
     
    std::cout  << "\t" << "Total Cost: $" << *m_cost << std::endl << std::endl;
}

CPizza & CPizza::operator=(const CPizza &obj){
    delete m_LPizza;
    m_LPizza = obj.m_LPizza;

    delete m_MPizza;
    m_MPizza = obj.m_MPizza;

    delete m_SPizza;
    m_SPizza = obj.m_SPizza;

    delete m_cost;
    m_cost = obj.m_cost;

    delete m_delivery;
    m_delivery = obj.m_delivery;

    delete m_deliveryFee;
    m_deliveryFee = obj.m_deliveryFee;

    if (m_name != obj.m_name){
        delete m_name;
        m_name = new char[strlen(obj.m_name) + 1];
        strcpy(m_name, obj.m_name); 
    }
    
    return *this;
}