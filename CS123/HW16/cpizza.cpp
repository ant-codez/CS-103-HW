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

//type constructor
CPizza::CPizza(char* name){
    printf("Type constructor...\n");

    m_LPizza = new int;
    *m_LPizza = 0;

    m_MPizza = new int;
    *m_MPizza = 0;

    m_SPizza = new int;
    *m_SPizza = 0;

    m_cost = new double;
    *m_cost = 0;

    m_delivery = new bool;
    *m_delivery = false;

    m_deliveryFee = new double;
    *m_deliveryFee = 0;

    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
}

//copy constructor
CPizza::CPizza(CPizza &cpy){
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

void CPizza::GetInfo(){

    char ans;

    std::cout << "Will this be for delivery (Y/N)? ";
    std::cin >> ans;
    if (toupper(ans) == 'Y')
        *m_delivery = true;
    else
        *m_delivery = false;
    std::cout << "How many large pizzas? ";
    std::cin >> *m_LPizza;
    std::cout << "How many medium pizzas? ";
    std::cin >> *m_MPizza;
    std::cout << "How many small pizzas? ";
    std::cin >> *m_SPizza;
    std::cout << "What is you name? ";
    std::cin.ignore();
    std::cin.getline(m_name, 256);
    std::cout << std::endl;

    if (*m_delivery)
        *m_deliveryFee = DFEE;
    else
        *m_deliveryFee = 0;

}

void CPizza::DispOrder(){
    //total
    *m_cost = (*m_SPizza * 10) + (*m_MPizza * 15) +(*m_LPizza * 20);
    double tax = *m_cost * TAX;
    //delivery fee is non taxable
    *m_cost += (tax + *m_deliveryFee);

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