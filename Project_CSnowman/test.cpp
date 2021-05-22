#include <iostream>
#include "CPlayer.h"

int main(){

    CPlayer player1("Darth Vader");
    player1.Start();
    //CWords Word;
    //CSnowmanGame Test;

    //printf("WORD = %s", Word.GetRandomWord());
    printf("TEST\n");
    printf("Name = %s", player1.GetName());

    return 0;
}