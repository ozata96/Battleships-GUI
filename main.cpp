#include <iostream>
#include <vector>
#include <map>

#include "GameControl.hpp"

using namespace std;

int main()
{
    GameControl control;
    control.MakeMove();

}


/*

Center = 
    row = guessList[guessList.size() - 2]
    col = guessList[guessList.size() - 1]
--------------------------------------------------------
Top = 
    row = (guessList[guessList.size() - 2]) - 1
    col = (guessList[guessList.size() - 1])

Down = 
    row = (guessList[guessList.size() - 2]) + 1
    col = (guessList[guessList.size() - 1])

Right = 
    row = (guessList[guessList.size() - 2])
    col = (guessList[guessList.size() - 1]) + 1

Left = 
    row = (guessList[guessList.size() - 2])
    col = (guessList[guessList.size() - 1]) - 1

*/