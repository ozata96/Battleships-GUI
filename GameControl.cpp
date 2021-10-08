#include "GameControl.hpp"

void GameControl::MakeMove()
{
    placement.FriendlyGridIntake("RA1A2", board.gameBoard);
    placement.FriendlyGridIntake("MB1B3", board.gameBoard);
    placement.FriendlyGridIntake("DC1C4", board.gameBoard);
    placement.FriendlyGridIntake("FD1D5", board.gameBoard);
    // board.PrintBoard();

    int x, y;
    while (x != 20)
    {

        cin >> x;
        cin >> y;

        placement.GetCoordinateType(x,y);
        
        // cout << "----------Enemy Ships------------" << endl;
        // for (int i = 0; i < 10; i++)
        //     cout << placement.enemyGrid[i] << endl;

        // string input = "";
        // cout << "Input: ";
        // cin >> input;

        // int rowStart = input[0] - 65;
        // int colStart = input[1] - 49;

        // engagement.Strike(rowStart, colStart, placement.enemyGrid, board.gameBoard);
        // board.PrintBoard();
        // input = "";
    }
};

void GameControl::EnemyMakeMove()
{
    bool isNewGuess = false;
    int guessRow;
    int guessCol;

    // Avoid Redundant Guesses
    while (!isNewGuess)
    {
        guessRow = placement.RandomNumberGenerator(0, 9);
        guessCol = placement.RandomNumberGenerator(0, 8);

        for (int i = 0; i < guessList.size(); i++)
        {
            if (guessList[i] == guessRow && guessList[i + 1] == guessCol)
                isNewGuess = false;
            i++;
        }
        isNewGuess = true;
    }
    guessList.push_back(guessRow);
    guessList.push_back(guessCol);

    if (!shipDetected)
    {
        // Computer Misses!
        if (placement.friendlyGrid[guessRow][guessCol] == '.')
        {
            cout << "MISS!" << endl;
        }

        // Computer Hits!
        else if (placement.enemyGrid[guessRow][guessCol] == 'o')
        {
            cout << "HIT!" << endl;
            shipDetected = true;
        }
    } else {
        // Hunting Detected Ship




    }




};