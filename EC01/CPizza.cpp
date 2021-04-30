#include "cpizza.h"
#include <string.h>
#include <iostream>
#include <iomanip>

//default constructor 
CPizza::CPizza(){

    std::cout << "Default Constructor!\n\n";

    m_SPizza = 0;
    m_MPizza = 0;
    m_LPizza = 0;
    m_total = 0;
    m_sales_tax = 0.0775;
    m_delivery = false;
    strcpy(m_name, "Null");
    m_delivery_fee = 5;
}

//Type constructor
CPizza::CPizza(int small, int med, int large, char name[256]){

    std::cout << "Type Constructor!\n\n";

    m_SPizza = small;
    m_MPizza = med;
    m_LPizza = large;
    m_delivery = false;
    m_sales_tax = 0.0775;
    strcpy(m_name, name);
}

//Copy Constructor
CPizza::CPizza(CPizza &cpy){

    std::cout << "Copy Constructor!\n\n";

    m_SPizza = cpy.m_SPizza;
    m_MPizza = cpy.m_MPizza;
    m_LPizza = cpy.m_LPizza;
    m_delivery = cpy.m_delivery;
    m_sales_tax = cpy.m_sales_tax;
    strcpy(m_name, cpy.m_name);
}

void CPizza::GetInfo(){

    char ans;

    std::cout << "Will this be for delivery (Y/N)? ";
    std::cin >> ans;
    if (toupper(ans) == 'Y')
        m_delivery = true;
    else
        m_delivery = false;
    std::cout << "How many large pizzas? ";
    std::cin >> m_LPizza;
    std::cout << "How many medium pizzas? ";
    std::cin >> m_MPizza;
    std::cout << "How many small pizzas? ";
    std::cin >> m_SPizza;
    std::cout << "What is you name? ";
    std::cin.ignore();
    std::cin.getline(m_name, 256);
    std::cout << std::endl;

    if (m_delivery)
        m_delivery_fee = 5;
    else
        m_delivery_fee = 0;

}

void CPizza::CalculatePrice(){
    //total
    m_total = (m_SPizza * 10) + (m_MPizza * 15) +(m_LPizza * 20);
    double tax = m_total * m_sales_tax;
    //delivery fee is non taxable
    m_total += (tax + m_delivery_fee);

    //set precision to 2 decimal points
    std::cout << std::fixed << std::setprecision(2);

    //Show order to customers
    std::cout << m_name << std::endl;
    std::cout << "\t" << m_LPizza << " Large Pizza(s)\n";
    std::cout << "\t" << m_MPizza << " Medium Pizza(s)\n";
    std::cout << "\t" << m_SPizza << " Small Pizza(s)\n";
    std::cout << "\t" << "Delivery: ";

    if (m_delivery)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
     
    std::cout  << "\t" << "Total Cost: $" << m_total << std::endl << std::endl;
}