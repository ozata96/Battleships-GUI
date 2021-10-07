#ifndef BoardDisplay_HPP
#define BoardDisplay_HPP

#include <iostream>
#include <vector>

using namespace std;

class BoardDisplay
{
    public:
        vector<string> gameBoard;
        BoardDisplay();
        ~BoardDisplay();

    // Functions
        void PrintBoard();
        void SetBoard();
};

#endif