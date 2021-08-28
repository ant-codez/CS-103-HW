#include "DynMem.h"
#include <string.h>
#include <iostream>
#include <iomanip>


//This function will allocate a block space of memory and return the address.
int     *AllocArray(int num){
    int *array;

    array = new int[num];

    return array;
}

// This function will prompt the user to enter a value to fill the array. 
void    InitArray(int *p, int num){
    std::cout << "Enter " << num << " ints for the array:\n";

    for(int i = 0; i < num; i++){
        std::cout << '\t' << "[" << i + 1<< "]: ";
        std::cin >> p[i];
    }
}


//This function will display the array to the monitor.
void    DispArray(int *p, int num){
    for (int i = 0; i < num; i++){
        std::cout << p[i] << " ";
    }

    std::cout << std::endl;
}

//This function will sort the contents of the array from least to greatest.
void    SortArray(int *p, int num){
    int temp;

    for (int i = 1; i < num; i++){
        if (p[i - 1] > p[i]){
            temp = p[i];
            p[i] = p[i - 1];
            p[i - 1] = temp;
            i = 0;
        }
    }
}