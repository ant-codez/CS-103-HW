// ============================================================================
// File: Stack.h
// ============================================================================
// Header file for the class Stack
// ============================================================================
#ifndef STACK_HEADER
#define STACK_HEADER

const int SIZE = 100;

class Stack 
{
public:
    Stack() : m_top(-1) { }
    
    void    Push(double i);
    double     Pop();
    double     Size() { return m_top; }
    double     Peak();
    bool    isEmpty() { return (m_top < 0); }

private:
    double     m_stack[SIZE];
    int        m_top;
};

#endif