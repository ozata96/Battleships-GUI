#include "BoardDisplay.hpp"

BoardDisplay::BoardDisplay()
{
    SetBoard();
};

BoardDisplay::~BoardDisplay(){};

void BoardDisplay::SetBoard()
{
    gameBoard.push_back("                 YOUR SHIPS                                       ENEMY SHIPS               ");
    gameBoard.push_back("");
    gameBoard.push_back("      1   2   3   4   5   6   7   8   9                 1   2   3   4   5   6   7   8   9   ");
    gameBoard.push_back("    +===+===+===+===+===+===+===+===+===+             +===+===+===+===+===+===+===+===+===+ ");
    gameBoard.push_back("A   |   :   :   :   :   :   :   :   :   |         A   |   :   :   :   :   :   :   :   :   | ");
    gameBoard.push_back("    +---+---+---+---+---+---+---+---+---+             +---+---+---+---+---+---+---+---+---+ ");
    gameBoard.push_back("B   |   :   :   :   :   :   :   :   :   |         B   |   :   :   :   :   :   :   :   :   | ");
    gameBoard.push_back("    +---+---+---+---+---+---+---+---+---+             +---+---+---+---+---+---+---+---+---+ ");
    gameBoard.push_back("C   |   :   :   :   :   :   :   :   :   |         C   |   :   :   :   :   :   :   :   :   | ");
    gameBoard.push_back("    +---+---+---+---+---+---+---+---+---+             +---+---+---+---+---+---+---+---+---+ ");
    gameBoard.push_back("D   |   :   :   :   :   :   :   :   :   |         D   |   :   :   :   :   :   :   :   :   | ");
    gameBoard.push_back("    +---+---+---+---+---+---+---+---+---+             +---+---+---+---+---+---+---+---+---+ ");
    gameBoard.push_back("E   |   :   :   :   :   :   :   :   :   |         E   |   :   :   :   :   :   :   :   :   | ");
    gameBoard.push_back("    +---+---+---+---+---+---+---+---+---+             +---+---+---+---+---+---+---+---+---+ ");
    gameBoard.push_back("F   |   :   :   :   :   :   :   :   :   |         F   |   :   :   :   :   :   :   :   :   | ");
    gameBoard.push_back("    +---+---+---+---+---+---+---+---+---+             +---+---+---+---+---+---+---+---+---+ ");
    gameBoard.push_back("G   |   :   :   :   :   :   :   :   :   |         G   |   :   :   :   :   :   :   :   :   | ");
    gameBoard.push_back("    +---+---+---+---+---+---+---+---+---+             +---+---+---+---+---+---+---+---+---+ ");
    gameBoard.push_back("H   |   :   :   :   :   :   :   :   :   |         H   |   :   :   :   :   :   :   :   :   | ");
    gameBoard.push_back("    +---+---+---+---+---+---+---+---+---+             +---+---+---+---+---+---+---+---+---+ ");
    gameBoard.push_back("I   |   :   :   :   :   :   :   :   :   |         I   |   :   :   :   :   :   :   :   :   | ");
    gameBoard.push_back("    +---+---+---+---+---+---+---+---+---+             +---+---+---+---+---+---+---+---+---+ ");
    gameBoard.push_back("J   |   :   :   :   :   :   :   :   :   |         J   |   :   :   :   :   :   :   :   :   | ");
    gameBoard.push_back("    +===+===+===+===+===+===+===+===+===+             +===+===+===+===+===+===+===+===+===+ ");
    gameBoard.push_back("");
    gameBoard.push_back("         oo      Radar Ship  [R]                           oo      Radar Ship  [R]          ");
    gameBoard.push_back("         ooo     Minor Ship  [M]                           ooo     Minor Ship  [M]          ");
    gameBoard.push_back("         oooo    Destroyer   [D]                           oooo    Destroyer   [D]          ");
    gameBoard.push_back("         ooooo   Flagship    [F]                           ooooo   Flagship    [F]          ");
};

void BoardDisplay::PrintBoard()
{
    cout << endl << endl << endl;
    for (int i = 0; i < gameBoard.size(); i++)
    {
        cout << gameBoard[i] << endl;
    }
    cout << endl << endl;
};