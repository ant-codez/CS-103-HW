// ============================================================================
// file: file_analysis.cpp
// ============================================================================
// Programmer: Anthony Chavez
// Date: 03/3/2021
// Class: CSCI 123 ("Intro to Programming Using C++")
// Time: 
// Instructor: Dr. Rodriguez
// Project: File Analysis
//
// Description:
// Reads the dracula.txt file and outputs the total number of periods, question marks,
// newlines, characters, digits, punctuation marks, spaces, and upper and lower case characters
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

    //stop ifstream from skipping whitespaces
    text >> std::noskipws;
    
    totalChars = ReadFile(text, totalUpper, totalLower, totalDigits, totalPunct, totalSpace, totalLines, totalPeriods, totalQuestion);

    return (0);
}

// ==== ReadFile ==================================================================
// Reads the ifstream from the inFile variable and returns the total number of digits in
// the file. This Function also prints the total number of Uppercase and Lowercase Characters,
// digits, punctutations, whitespaces, newlines, periods and question marks to the console
//
// Input:
//      &inFile [IFSTREAM]   -- The file stream we will use to recieve each character from the txt
//      totalUpper  [INT] -- The total number of uppercase characters
//      totalLower  [INT] -- The total number of lowercase characters
//      totalDigits  [INT] -- The total number of digits
//      totalPunct [INT] -- The total number of punctuation characters
//      totalSpace  [INT] -- The total number of whitespace characters
//      totalLines  [INT] -- The total number of newline characters
//      totalPeriods  [INT] -- The total number of period '.' characters
//      totalQuestion  [INT] -- The total number of question mark '?' characters
//
// Output:
//      Returns an integer value of the total number of charcters in the text.
//
// ======================================================================================

int ReadFile(ifstream &inFile, int totalUpper, int totalLower, int totalDigits, int totalPunct, int totalSpace, int totalLines, int totalPeriods, int totalQuestion){
    char c;
    int totalChars = 0;

    while (inFile.get(c)){
        if (c == '\n' || c == '\f'){
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