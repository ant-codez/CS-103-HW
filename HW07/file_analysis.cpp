// ============================================================================
// file: file_analysis.cpp
// ============================================================================
// Programmer: Anthony Chavez
// Date: 03/3/2021
// Class: CSCI 123 ("Intro to Programming Using C++")
// Time: 
// Instructor: Dr. Rodriguez
// Project: Cash Register Files
//
// Description:
// Modification of cashRegisterLoop.cpp that returns a recipt and reads input in from a file.
// ============================================================================
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
using namespace std;


// Function Prototypes
int ReadFile(ifstream &, int, int, int, int, int, int ,int, int);


// ==== main ==================================================================
//
// ============================================================================

int main(){
    int totalChars = 0, totalUpper = 0, totalLower = 0, totalDigits = 0, totalPunct = 0, totalSpace = 0, totalLines = 0;
    int totalPeriods = 0, totalQuestion = 0;
    ifstream text("dracula.txt");

    text >> std::noskipws;
    
    totalChars = ReadFile(text, totalUpper, totalLower, totalDigits, totalPunct, totalSpace, totalLines, totalPeriods, totalQuestion);

    return (0);
}

int ReadFile(ifstream &inFile, int totalUpper, int totalLower, int totalDigits, int totalPunct, int totalSpace, int totalLines, int totalPeriods, int totalQuestion){
    char c;
    string s;
    int totalChars = 0;

    

    
    while (inFile.get(c)){
        //c = infile.get();

        if (c == '\n' || c == '\f' || c == '\r'){
            totalLines++;
        }
        else{
            totalChars++;
        }

        if (isupper(c)){
            totalUpper++;
        }
        else if (islower(c)){
            totalLower++;
        }
        else if (isdigit(c)){
            totalDigits++;
        }
        else if(ispunct(c)){
            totalPunct++;
        }
        else if(isspace(c)){
            totalSpace++;
        }

        if(c == '.'){
            totalPeriods++;
        }
        else if (c == '?'){
            totalQuestion++;
        }
        //cout << c << endl;
    }

    printf("File \"dracula.txt\" contains the following:\nUppercase letters:\t%i\n", totalUpper);
    printf("Lowercase letters:\t%i\n", totalLower);
    printf("Digits:\t%i\n", totalDigits);
    printf("Punctuation characters:\t%i\n", totalPunct);
    printf("Whitespace characters:\t%i\n", totalSpace);
    printf("Lines:\t%i\n", totalLines);
    printf("Total Periods:\t%i\n", totalPeriods);
    printf("Total Question Marks:\t%i\n", totalQuestion);
    printf("Total characters read:\t%i\n", totalChars);

    return (totalChars);
}