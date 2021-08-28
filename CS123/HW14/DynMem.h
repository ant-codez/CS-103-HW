// ============================================================================
// File: cpizza.h
// ============================================================================
// Programmer: Anthony Chavez   
// Date: 4/10/2020
//
// Description:
// Header file containing the class and member functions and private variables associated
// with it.
// ============================================================================
#ifndef DYNMEM_HEADER
#define DYNMEM_HEADER

//function prototypes
int*    AllocArray(int num_of_elements);
void    InitArray(int *pointer, int num_of_elements);
void    DispArray(int *pointer, int num_of_elements);
void    SortArray(int *pointer, int num_of_elements);

#endif 