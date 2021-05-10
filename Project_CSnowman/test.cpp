// =============================================================================
// File: main.cpp
// =============================================================================
// Programmer: ???
// Date: ???
// Class: CSCI 123 ("Intro to Programming Using C++")
// Time: ???
// Instructor: Dr. Rodriguez
// Project: Snowman
//
// Description:
//      This is a simulation of the game "snomwman", which is the politically
//      correct version of "hangman".  This is the file where the main function
//      is located.  Main uses the class CPlayer to Start and Reset the game.
//      At the end of the game, we retrieve the player's name and thank them for
//      playing.
//
// =============================================================================

#include <iostream>
#include "CPlayer.h"
using namespace std;

int main ()
{
    CPlayer C1;

    std::cout << "Name = " << C1.GetName();

    return 0;
}
