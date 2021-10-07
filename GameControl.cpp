#include "GameControl.hpp"

void GameControl::MakeMove()
{
    placement.FriendlyGridIntake("RA1A2", board.gameBoard);
    placement.FriendlyGridIntake("MB1B3", board.gameBoard);
    placement.FriendlyGridIntake("DC1C4", board.gameBoard);
    placement.FriendlyGridIntake("FD1D5", board.gameBoard);

    board.PrintBoard();

    engagement.Fight(placement.enemyGrid);
}