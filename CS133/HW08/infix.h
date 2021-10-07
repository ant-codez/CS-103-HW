// ============================================================================
// File: infix.h
// ============================================================================
// Header file that includes all the functions used in the calculator program.
// ============================================================================
#ifndef INFIX_HEADER
#define INFIX_HEADER

#include <string>
#include <iostream>
#include <cctype>
#include "stack.h"
#include <stdio.h>
#include <cmath>

using namespace std;

// ==== isOperator ==========================================================
//
// This function will determine if the argument recieved is a math operator
//
// Input:
//      c --  A char element representing a mathmatical operator
//
// Output:
//      A boolean value of success or failure
//
// ============================================================================
bool isOperator(char c){
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
        return true;
    }

    return false;
}

// ==== order ================================================================
//
// This function wwll return a int value representing the numerical order of
// the mathmatical operator which is being evaluated.
//
// Input:
//      c --  A char element representing a mathmatical operator
//
// Output:
//      An integer value based on the order of PEMDAS
//
// ============================================================================
int order(char op){
    switch (op){
        case '(':
            return 4;
            break;
        case '^':
            return 3;
            break;
        case '*':
            return 2;
            break;
        case '/':
            return 2;
            break;
        case '+':
            return 1;
            break;
        case '-':
            return 1;
            break;
        default:
            return -1;
            break;
    } 
}

// ==== operatorPres ================================================================
//
// This function is used to control a while loop in the foundOperator function 
// in conjunction with the order function. The function will take 2 math operators 
// as input and compare thepresidence of their operators. If the currentOp is less  
// than or equal in presidence to evalOp then return true else it will return false.
//
// Input:
//      currentOp --    the operator found in the InFix string to compare to evalOp
//      evalOp    --    the operator recieved from the stack to compare to currentOp
//
// Output:
//      A boolean value of success or failure
//
// =================================================================================
bool operatorPres(char currentOp, char evalOp){
    if (evalOp == '('){
        return false;
    } 

    int a = order(currentOp);
    int b = order(evalOp);

    if (b > a || a == b){
        return true;
    }
    else {
        return false;
    }
}

// ==== foundDigit ================================================================
//
// This function appends a digit to the postFix string and addes a space to it.
//
// Input:
//      digit   --  a char of a single digit to be appended to the postFix string
//      postFix --  a string passed by refrence to be appended to.
//
// Output:
//      void
//
// =================================================================================
void foundDigit(char digit, string &postFix) {
    postFix += digit;
    postFix += ' ';
}

// ==== foundOperator ================================================================
//
// This function relies on the operatorPres function to determine how many operators to
// pop off the stack and append onto the PostFix string. After all operators have been 
// popped off the stack we will push a new operator on to the stack.
//
// Input:
//      stk     --  A stack which is holding all operators that have been pushed to it.
//      postFix --  a string passed by refrence to be appended to.
//      op      --  a char representing a math operator, which will be append to the stack
//                  after being compared in the operatorPres function.
//
// Output:
//      void
//
// =================================================================================
void foundOperator(Stack &stk, string &postFix, char op) {
    while (operatorPres(op, stk.Peak())){
        postFix += stk.Pop();
        postFix += " ";
    }
    stk.Push(op);        
}

// ==== InfixToPostfix ================================================================
//
// This function converts a string in Infix notaion and returns a PostFix converted string
//
// Input:
//      str --  a string in Infix notation given by the user at runtime
//
// Output:
//      A string in Postfix notation
//
// =================================================================================
string InfixToPostfix(string str){
    Stack stk;
    string postFix;
    char temp;

    for (int i = 0; i < str.length() + 1; i++){
        if (isdigit(str[i])){
            foundDigit(str[i], postFix);
        }
        else if (str[i] == '('){
            stk.Push('(');
        }
        else if (isOperator(str[i]) && stk.isEmpty()){
            stk.Push(str[i]);
        }
        else if (isOperator(str[i]) && !stk.isEmpty()) {
            foundOperator(stk, postFix, str[i]);
        }
        else if (str[i] == ')'){
            while (stk.Peak() != '('){
                postFix += stk.Pop();
                postFix += " ";
            }
            stk.Pop();
        }
    }

    while (!stk.isEmpty()){
        if (isOperator(stk.Peak())){
            postFix += stk.Pop();
            postFix += " ";
        }
    }

    return postFix;
}

// ==== eval ======================================================================
//
// This function recieves a postFix string as input and returns the evaulated expression
// as a double.
//
// Input:
//      str --  a string in postfix notation
//
// Output:
//      A Double representing the answer to the postFix expression.
//
// =================================================================================
double eval(string postFix) {
    Stack stk;
    double v1, v2; 
    double total = 0;

    for (int i = 0; i < postFix.length() + 1; i++){
        if (isdigit(postFix[i])){
            int digit = postFix[i] - '0'; // Conversion of a char to an int

            stk.Push(digit);
        }
        else if (isOperator(postFix[i])){
            v2 = stk.Pop();
            v1 = stk.Pop();

            if (postFix[i] == '+'){
                stk.Push(v1 + v2);
            }
            else if (postFix[i] == '-'){
                stk.Push(v1 - v2);
            }
            else if (postFix[i] == '*'){
                stk.Push(v1 * v2);
            }
            else if (postFix[i] == '/'){
                stk.Push(v1 / v2);
            }
            else if (postFix[i] == '^'){
                stk.Push(pow(v1, v2));
            }
        }
    }

    return stk.Pop();
}


#endif