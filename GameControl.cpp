#include "GameControl.hpp"

void GameControl::MakeMove()
{
    placement.FriendlyGridIntake("RA1A2", board.gameBoard);
    placement.FriendlyGridIntake("MB1B3", board.gameBoard);
    placement.FriendlyGridIntake("DC1C4", board.gameBoard);
    placement.FriendlyGridIntake("FD1D5", board.gameBoard);
    board.PrintBoard();



    int x, y;
    while (x != 20)
    {
        cout << "----------Enemy Ships------------" << endl;
        for (int i = 0; i < 10; i++)
            cout << placement.enemyGrid[i] << endl;

        cout << "ROW: ";
        cin >> x;
        cout << endl
             << "COL: ";
        cin >> y;
        cout << endl;

        // engagement.Strike(x, y, board.gameBoard);
        // board.PrintBoard();
        engagement.Strike(x, y, placement.enemyGrid, board.gameBoard);

        board.PrintBoard();
    }
}

    // int convertedRow = ((row + 4) + (row * 2)) - row;
    // int convertedCol = ((col + 56) + (col * 4)) - col;