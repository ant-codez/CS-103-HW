// ============================================================================
// File: stack.cpp
// ============================================================================
// This is the implementation file for the ABT Stack. This
// implementation uses an array of doubles to hold the operators and doubles
// needed for the program to evaluate a postFix expression.
// ============================================================================

#include "Stack.h"
#include <stdio.h>

// ==== Stack::Push ==========================================================
//
// This function adds a new element to the top of the stack
//
// Input:
//      val --  The element to be added to the stack
//
// Output:
//      void
//
// ============================================================================
void Stack::Push(double val){
    if (m_top >= (SIZE - 1)){
        printf("Stack overflow\n");
        return;
    }

    m_stack[++m_top] = val;
    //printf("Pushed [%i] into stack\n", val);
}

// ==== Stack::Pop ==========================================================
//
// This function removes an element from the top of the stack and updates the
// new size of the stack.
//
// Input:
//      void
//
// Output:
//      A double value which was at the top of the stack
//
// ============================================================================
double Stack::Pop() {
    if (m_top < 0){
        printf("Stack underflow\n");
        return 0;
    }
    else {
        double x = m_stack[m_top--];
        return x;
    }
}

// ==== Stack::Peak ==========================================================
//
// This function shows what element is located at the top of the stack without
// removing the element.
//
// Input:
//      void
//
// Output:
//      A double value which was at the top of the stack.
//
// ============================================================================
double Stack::Peak() {
    if (m_top < 0) {
        //printf("Stack is empty");
        return 0;
    }
    else {
        double x = m_stack[m_top];
        return x;
    }
}