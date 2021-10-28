#include "GameControl.hpp"

GameControl::GameControl(){
    // map<char, BattleShip> ship;

    // ship['D'] = enemyDestroyer;
};

GameControl::~GameControl(){};

void GameControl::MakeMove()
{
    string input = "";
    while (input != "NEXT")
    {
        if (!placement.overlapFlag && !invalidInputFlag)
        {
            board.PrintBoard();
            cout << "Welcome to Battleships. Above is the game board. Note the ship symbols." << endl;
            cout << "[F] is for flag ship, [D] is for destroyer, [M] is for minor ship, and [R] is for radar ship." << endl;
            cout << "Please place your ships onto the board in the following format." << endl;
            cout << "Example: FA1A5" << endl;
            cout << "The first character is the ship type F, D, M, or R. The 2nd and 3rd characters are " << endl;
            cout << "The beginning of the ship, and the 4th and 5th are the end of the ship." << endl;
            cout << "A flagship must be allocated 5 squares, a destroyer 4, a minor ship 3, and a radar ship 2." << endl;

            cout << "Alternatively, for automatic deployement, please type DEPLOY in all caps." << endl;
        }

        cout << "Input: ";
        cin >> input;

        if (input == "DEPLOY")
        {
            placement.FriendlyGridIntake("FI3I7", board.gameBoard);
            placement.FriendlyGridIntake("DA3A6", board.gameBoard);
            placement.FriendlyGridIntake("MD5F5", board.gameBoard);
            placement.FriendlyGridIntake("RA8B8", board.gameBoard);
            board.PrintBoard();
            break;
        }
        else if (!CheckPlacementInput(input))
        {
            invalidInputFlag = true;
            cerr << "Error: Invalid Input. Please enter input like this example: FI3I7." << endl;
            cerr << "Cannot deploy the same ship twice." << endl;
            input = "";
        }
        else
        {
            invalidInputFlag = false;
            placement.FriendlyGridIntake(input, board.gameBoard);
            input = "";
            if (placement.placementCounter == 4)
            {
                board.PrintBoard();
                break;
            }
        }
    }

    input = "";
    while (input != "EXIT")
    {
        cout << "Target the enemy ships!" << endl;
        cout << "Input: ";
        cin >> input;

        if (!CheckAttackInput(input))
        {
            cerr << "Error: Invalid Input. Please enter input as" << endl;
            cerr << "a capital letter followed by a number, both of which" << endl;
            cerr << "must be on the grid above." << endl;
            input = "";
        }
        else if (!CheckUniquePlayerMove(input))
        {
            cerr << "Redundant Move: You have already played that." << endl;
            cerr << "Please select a new unique move." << endl;
            input = "";
        }
        else
        {
            playerMoves.push_back(input);
            int rowStart = input[0] - 65;
            int colStart = input[1] - 49;

            engagement.Strike(rowStart, colStart, placement.enemyGrid, board.gameBoard);
            if (placement.enemyGrid[rowStart][colStart] == 'o')
                enemyBlockShipCount--;

            input = "";

            EnemyMakeMove();

            board.PrintBoard();

            if (enemyBlockShipCount == 0)
                TriggerWin("PLAYER");

            // cout << "----------Friendly Ships------------" << endl;
            // for (int i = 0; i < 10; i++)
            //     cout << placement.friendlyGrid[i] << endl;

            // cout << "----------Enemy Ships------------" << endl;
            // for (int i = 0; i < 10; i++)
            //     cout << placement.enemyGrid[i] << endl;
        }
    }
};

bool GameControl::CheckUniquePlayerMove(string input)
{
    for (int i = 0; i < playerMoves.size(); i++)
        if (input == playerMoves[i])
            return false;
    return true;
}

bool GameControl::CheckPlacementInput(string input)
{
    string charOne = "ABCDEFGHIJ";
    string charTwo = "123456789";

    if (input.length() < 5 || input.length() > 5)
        return false;

    if (input[0] != 'F' && input[0] != 'D' && input[0] != 'M' && input[0] != 'R')
        return false;

    for (int i = 0; i < deployedShips.size(); i++)
        if (input[0] == deployedShips[i])
            return false;

    for (int i = 0; i < charOne.length(); i++)
        if (input[1] == charOne[i])
            for (int m = 0; m < charOne.length(); m++)
                if (input[3] == charOne[m])
                    for (int j = 0; j < charTwo.length(); j++)
                        if (input[2] == charTwo[j])
                            for (int k = 0; k < charTwo.length(); k++)
                                if (input[4] == charTwo[k])
                                {
                                    deployedShips.push_back(input[0]);
                                    return true;
                                }

    return false;
}

bool GameControl::CheckAttackInput(string input)
{
    string charOne = "ABCDEFGHIJ";
    string charTwo = "123456789";

    if (input.length() < 2 || input.length() > 2)
        return false;

    for (int i = 0; i < charOne.length(); i++)
    {
        if (input[0] == charOne[i])
        {
            for (int j = 0; j < charTwo.length(); j++)
            {
                if (input[1] == charTwo[j])
                    return true;
            }
        }
    }
    return false;
}

void GameControl::TriggerWin(string type)
{
    if (type == "BOT")
    {
        cout << "BOT WINS GAME!" << endl;
        cout << "Good luck next time!" << endl;
        exit(0);
    }
    else if (type == "PLAYER")
    {
        cout << "CONGRATULATIONS! YOU HAVE WON!" << endl;
        exit(0);
    }
    else if (type == "TIE")
    {
        cout << "It's a stalemate!" << endl;
        exit(0);
    }
}

bool GameControl::isNewGuess(int row, int col)
{
    for (int i = 0; i < guessList.size(); i++)
    {
        // cout << "Row: " << guessList[i] << " , Col: " << guessList[i + 1] << endl;
        i++;
    }
    for (int i = 0; i < guessList.size(); i++)
    {
        if (guessList[i] == row && guessList[i + 1] == col)
            return false;
        i++;
    }
    return true;
}

int GameControl::GetShipBlock(char shipType)
{
    switch (shipType)
    {
    case 'R':
        return friendlyRadar.GetBlockNumber();
    case 'M':
        return friendlyMinor.GetBlockNumber();
    case 'D':
        return friendlyDestroyer.GetBlockNumber();
    case 'F':
        return friendlyFlag.GetBlockNumber();
    default:
        return 0;
    }
}

void GameControl::DestroyShipBlock(char shipType)
{
    switch (shipType)
    {
    case 'R':
        friendlyRadar.DestroyBlock();
        break;
    case 'M':
        friendlyMinor.DestroyBlock();
        break;
    case 'D':
        friendlyDestroyer.DestroyBlock();
        break;
    case 'F':
        friendlyFlag.DestroyBlock();
        break;
    }
}

void GameControl::EnemyMakeRandomGuess()
{
    bool newGuess = false;

    int guessRow;
    int guessCol;

    // Avoid Redundant Guesses
    while (!newGuess)
    {
        guessRow = placement.RandomNumberGenerator(0, 9);
        guessCol = placement.RandomNumberGenerator(0, 8);

        if (isNewGuess(guessRow, guessCol))
            newGuess = true;
    }
    guessList.push_back(guessRow);
    guessList.push_back(guessCol);

    // Computer Misses!
    if (placement.friendlyGrid[guessRow][guessCol] == '.')
    {
        placement.friendlyGrid[guessRow][guessCol] = 'x';
        // cout << "MISS!" << endl;
        board.gameBoard[placement.convertRowForMainGrid(guessRow)][placement.convertColForMainGrid(guessCol)] = '-';
    }

    // Computer Hits!
    else if (placement.friendlyGrid[guessRow][guessCol] == 'o')
    {
        // cout << "HIT!" << endl;
        placement.friendlyGrid[guessRow][guessCol] = 'x';
        shipDetected = true;
        // cout << "ROW:" << guessList[guessList.size() - 2] << endl;
        // cout << "COL:" << guessList[guessList.size() - 1] << endl;

        detectedRow = guessList[guessList.size() - 2];
        detectedCol = guessList[guessList.size() - 1];

        board.gameBoard[placement.convertRowForMainGrid(detectedRow)][placement.convertColForMainGrid(detectedCol)] = 'X';

        char shipType = placement.GetCoordinateType(detectedRow, detectedCol);
        DestroyShipBlock(shipType);
    }
}

void GameControl::FindShipOrientation()
{
    char shipType = placement.GetCoordinateType(detectedRow, detectedCol);
    // int ranNum = placement.RandomNumberGenerator(1, 4);
    // Check Top
    // switch (ranNum)
    // {
    // case 1:
    if (((detectedRow - 1) > -1) && (isNewGuess(detectedRow - 1, detectedCol)))
    {
        if (placement.friendlyGrid[detectedRow - 1][detectedCol] == 'o')
        {
            orientationDetected = true;
            direction = 'T';
            board.gameBoard[placement.convertRowForMainGrid(detectedRow - 1)][placement.convertColForMainGrid(detectedCol)] = 'X';
            char shipType = placement.GetCoordinateType(detectedRow - 1, detectedCol);
            DestroyShipBlock(shipType);
        }
        else
            board.gameBoard[placement.convertRowForMainGrid(detectedRow - 1)][placement.convertColForMainGrid(detectedCol)] = '-';

        cout << 'T' << endl;
        guessList.push_back(detectedRow - 1);
        guessList.push_back(detectedCol);
        placement.friendlyGrid[detectedRow - 1][detectedCol] = 'x';
    }
    // break;
    // Check Left
    // case 4:
    else if (((detectedCol - 1) > -1) && (isNewGuess(detectedRow, detectedCol - 1)))
    {
        if (placement.friendlyGrid[detectedRow][detectedCol - 1] == 'o')
        {
            orientationDetected = true;
            direction = 'L';
            board.gameBoard[placement.convertRowForMainGrid(detectedRow)][placement.convertColForMainGrid(detectedCol - 1)] = 'X';

            char shipType = placement.GetCoordinateType(detectedRow, detectedCol - 1);
            DestroyShipBlock(shipType);
        }
        else
            board.gameBoard[placement.convertRowForMainGrid(detectedRow)][placement.convertColForMainGrid(detectedCol - 1)] = '-';

        cout << 'L' << endl;
        guessList.push_back(detectedRow);
        guessList.push_back(detectedCol - 1);
        placement.friendlyGrid[detectedRow][detectedCol - 1] = 'x';
    }
    // break;
    // Check Right
    // case 2:
    else if (((detectedCol + 1) < 11) && (isNewGuess(detectedRow, detectedCol + 1)))
    {
        if (placement.friendlyGrid[detectedRow][detectedCol + 1] == 'o')
        {
            orientationDetected = true;
            direction = 'R';
            board.gameBoard[placement.convertRowForMainGrid(detectedRow)][placement.convertColForMainGrid(detectedCol + 1)] = 'X';
            char shipType = placement.GetCoordinateType(detectedRow, detectedCol + 1);
            DestroyShipBlock(shipType);
        }
        else
            board.gameBoard[placement.convertRowForMainGrid(detectedRow)][placement.convertColForMainGrid(detectedCol + 1)] = '-';

        cout << 'R' << endl;
        guessList.push_back(detectedRow);
        guessList.push_back(detectedCol + 1);
        placement.friendlyGrid[detectedRow][detectedCol + 1] = 'x';
    }
    // break;
    // Check Down
    // case 3:
    else if (((detectedRow + 1) < 10) && (isNewGuess(detectedRow + 1, detectedCol)))
    {
        if (placement.friendlyGrid[detectedRow + 1][detectedCol] == 'o')
        {
            orientationDetected = true;
            direction = 'D';
            board.gameBoard[placement.convertRowForMainGrid(detectedRow + 1)][placement.convertColForMainGrid(detectedCol)] = 'X';
            char shipType = placement.GetCoordinateType(detectedRow + 1, detectedCol);
            DestroyShipBlock(shipType);
        }
        else
            board.gameBoard[placement.convertRowForMainGrid(detectedRow + 1)][placement.convertColForMainGrid(detectedCol)] = '-';

        cout << 'D' << endl;
        guessList.push_back(detectedRow + 1);
        guessList.push_back(detectedCol);
        placement.friendlyGrid[detectedRow + 1][detectedCol] = 'x';
    }
    if (GetShipBlock(shipType) == 0)
    {
        shipDetected = false;
        orientationDetected = false;
        isSwitched = false;
        leftCounter = 0;
        rightCounter = 0;
        detectedCol = 0;
        detectedRow = 0;
    }
    // break;

    // }
};

void GameControl::VerticalGuessing(int &forwardCounter, int &backwardCounter, int bufferTwo, int bufferOne)
{
    char shipType = placement.GetCoordinateType(detectedRow, detectedCol);
    if (placement.friendlyGrid[detectedRow + bufferTwo + forwardCounter][detectedCol] == 'x')
        isSwitched = true;
    if (!isSwitched)
    {
        if (placement.friendlyGrid[detectedRow + bufferTwo + forwardCounter][detectedCol] != 'o')
        {
            isSwitched = true;
            board.gameBoard[placement.convertRowForMainGrid(detectedRow + bufferTwo + forwardCounter)][placement.convertColForMainGrid(detectedCol)] = '-';
        }
        else
        {
            board.gameBoard[placement.convertRowForMainGrid(detectedRow + bufferTwo + forwardCounter)][placement.convertColForMainGrid(detectedCol)] = 'X';
            DestroyShipBlock(shipType);
        }
        placement.friendlyGrid[detectedRow + bufferTwo + forwardCounter][detectedCol] = 'x';
        forwardCounter = (forwardCounter + (bufferOne * -1));
        guessList.push_back(detectedRow + bufferTwo + forwardCounter);
        guessList.push_back(detectedCol);
    }
    else
    {
        placement.friendlyGrid[detectedRow + bufferOne + backwardCounter][detectedCol] = 'x';
        board.gameBoard[placement.convertRowForMainGrid(detectedRow + bufferOne + backwardCounter)][placement.convertColForMainGrid(detectedCol)] = 'X';
        backwardCounter += bufferOne;
        DestroyShipBlock(shipType);
        guessList.push_back(detectedRow + bufferTwo + forwardCounter);
        guessList.push_back(detectedCol);
    }
    if (GetShipBlock(shipType) == 0)
    {
        shipDetected = false;
        orientationDetected = false;
        isSwitched = false;
        leftCounter = 0;
        rightCounter = 0;
        detectedCol = 0;
        detectedRow = 0;
    }
};

void GameControl::HorizontalGuessing(int &forwardCounter, int &backwardCounter, int bufferTwo, int bufferOne)
{
    char shipType = placement.GetCoordinateType(detectedRow, detectedCol);
    if (placement.friendlyGrid[detectedRow][detectedCol + bufferTwo + forwardCounter] == 'x')
        isSwitched = true;
    if (!isSwitched)
    {
        if (placement.friendlyGrid[detectedRow][detectedCol + bufferTwo + forwardCounter] != 'o')
        {
            isSwitched = true;
            board.gameBoard[placement.convertRowForMainGrid(detectedRow)][placement.convertColForMainGrid(detectedCol + bufferTwo + forwardCounter)] = '-';
        }
        else
        {
            board.gameBoard[placement.convertRowForMainGrid(detectedRow)][placement.convertColForMainGrid(detectedCol + bufferTwo + forwardCounter)] = 'X';
            DestroyShipBlock(shipType);
        }

        placement.friendlyGrid[detectedRow][detectedCol + bufferTwo + forwardCounter] = 'x';
        forwardCounter = (forwardCounter + (bufferOne * -1));
        guessList.push_back(detectedRow);
        guessList.push_back(detectedCol + bufferTwo + forwardCounter);
    }
    else
    {
        placement.friendlyGrid[detectedRow][detectedCol + bufferOne + backwardCounter] = 'x';
        board.gameBoard[placement.convertRowForMainGrid(detectedRow)][placement.convertColForMainGrid(detectedCol + bufferOne + backwardCounter)] = 'X';
        backwardCounter += bufferOne;
        DestroyShipBlock(shipType);
        guessList.push_back(detectedRow);
        guessList.push_back(detectedCol + bufferTwo + forwardCounter);
    }
    if (GetShipBlock(shipType) == 0)
    {
        shipDetected = false;
        orientationDetected = false;
        isSwitched = false;
        leftCounter = 0;
        rightCounter = 0;
        detectedCol = 0;
        detectedRow = 0;
    }
}

void GameControl::DestroyShip()
{
    switch (direction)
    {
    case 'T':
        VerticalGuessing(leftCounter, rightCounter, -2, 1);
        // UpGuessing();
        break;
    case 'D':
        VerticalGuessing(rightCounter, leftCounter, 2, -1);
        // DownGuessing();
        break;
    case 'R':
        HorizontalGuessing(rightCounter, leftCounter, 2, -1);
        break;
    case 'L':
        HorizontalGuessing(leftCounter, rightCounter, -2, 1);
        break;
    }
};

void GameControl::EnemyMakeMove()
{
    if (!shipDetected)
        EnemyMakeRandomGuess();
    else if (shipDetected == true && !orientationDetected)
    {
        FindShipOrientation();
    }
    else if (shipDetected == true && orientationDetected)
    {
        DestroyShip();
    }
    if (friendlyFlag.GetBlockNumber() == 0 && friendlyDestroyer.GetBlockNumber() == 0 && friendlyRadar.GetBlockNumber() == 0 && friendlyMinor.GetBlockNumber() == 0)
    {
        TriggerWin("BOT");
    }
};