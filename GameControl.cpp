#include "GameControl.hpp"

GameControl::GameControl(){
    // map<char, BattleShip> ship;

    // ship['D'] = enemyDestroyer;
};

GameControl::~GameControl(){};

void GameControl::MakeMove()
{

    placement.FriendlyGridIntake("FC3G3", board.gameBoard);
    placement.FriendlyGridIntake("FC7G7", board.gameBoard);
    placement.FriendlyGridIntake("FC5G5", board.gameBoard);
    // placement.FriendlyGridIntake("FI3I7", board.gameBoard);
    // board.PrintBoard();

    int x, y;
    while (x != 20)
    {
        // cout << "----------Enemy Ships------------" << endl;
        // for (int i = 0; i < 10; i++)
        //     cout << placement.enemyGrid[i] << endl;

        string input = "";
        cout << "Input: ";
        cin >> input;

        int rowStart = input[0] - 65;
        int colStart = input[1] - 49;

        engagement.Strike(rowStart, colStart, placement.enemyGrid, board.gameBoard);
        // board.PrintBoard();
        input = "";

        EnemyMakeMove();

        cout << "----------Friendly Ships------------" << endl;
        for (int i = 0; i < 10; i++)
            cout << placement.friendlyGrid[i] << endl;
    }
};

bool GameControl::isNewGuess(int row, int col)
{
    for (int i = 0; i < guessList.size(); i++)
    {
        cout << "Row: " << guessList[i] << " , Col: " << guessList[i + 1] << endl;
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
        cout << "MISS!" << endl;
    }

    // Computer Hits!
    else if (placement.friendlyGrid[guessRow][guessCol] == 'o')
    {
        cout << "HIT!" << endl;
        placement.friendlyGrid[guessRow][guessCol] = 'x';
        shipDetected = true;
        cout << "ROW:" << guessList[guessList.size() - 2] << endl;
        cout << "COL:" << guessList[guessList.size() - 1] << endl;

        detectedRow = guessList[guessList.size() - 2];
        detectedCol = guessList[guessList.size() - 1];

        char shipType = placement.GetCoordinateType(detectedRow, detectedCol);
        DestroyShipBlock(shipType);
    }
}

void GameControl::FindShipOrientation()
{
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

            char shipType = placement.GetCoordinateType(detectedRow - 1, detectedCol);
            DestroyShipBlock(shipType);
        }
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

            char shipType = placement.GetCoordinateType(detectedRow, detectedCol - 1);
            DestroyShipBlock(shipType);
        }
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

            char shipType = placement.GetCoordinateType(detectedRow, detectedCol + 1);
            DestroyShipBlock(shipType);
        }
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

            char shipType = placement.GetCoordinateType(detectedRow + 1, detectedCol);
            DestroyShipBlock(shipType);
        }
        cout << 'D' << endl;
        guessList.push_back(detectedRow + 1);
        guessList.push_back(detectedCol);
        placement.friendlyGrid[detectedRow + 1][detectedCol] = 'x';
    }
    // break;

    // }
};

// void GameControl::DownGuessing()
// {
//     char shipType = placement.GetCoordinateType(detectedRow, detectedCol);

//     if (placement.friendlyGrid[detectedRow + 2 + rightCounter][detectedCol] == 'x')
//         isSwitched = true;

//     if (!isSwitched)
//     {
//         if (placement.friendlyGrid[detectedRow + 2 + rightCounter][detectedCol] != 'o')
//             isSwitched = true;
//         else
//             DestroyShipBlock(shipType);
//         placement.friendlyGrid[detectedRow + 2 + rightCounter][detectedCol] = 'x';
//         rightCounter++;
//         DestroyShipBlock(shipType);
//     }
//     else
//     {
//         placement.friendlyGrid[detectedRow - 1 + leftCounter][detectedCol] = 'x';
//         leftCounter--;
//         DestroyShipBlock(shipType);
//     }
// }

// void GameControl::UpGuessing()
// {
//     char shipType = placement.GetCoordinateType(detectedRow, detectedCol);
//     if (placement.friendlyGrid[detectedRow - 2 + leftCounter][detectedCol] == 'x')
//         isSwitched = true;
//     if (!isSwitched)
//     {
//         if (placement.friendlyGrid[detectedRow - 2 + leftCounter][detectedCol] != 'o')
//             isSwitched = true;
//         else
//             DestroyShipBlock(shipType);
//         placement.friendlyGrid[detectedRow - 2 + leftCounter][detectedCol] = 'x';
//         leftCounter--;
//     }
//     else
//     {
//         placement.friendlyGrid[detectedRow + 1 + rightCounter][detectedCol] = 'x';
//         rightCounter++;
//         DestroyShipBlock(shipType);
//     }
// }

void GameControl::VerticalGuessing(int &forwardCounter, int &backwardCounter, int bufferTwo, int bufferOne)
{
    char shipType = placement.GetCoordinateType(detectedRow, detectedCol);
    if (placement.friendlyGrid[detectedRow + bufferTwo + forwardCounter][detectedCol] == 'x')
        isSwitched = true;
    if (!isSwitched)
    {
        if (placement.friendlyGrid[detectedRow + bufferTwo + forwardCounter][detectedCol] != 'o')
            isSwitched = true;
        else
            DestroyShipBlock(shipType);
        placement.friendlyGrid[detectedRow + bufferTwo + forwardCounter][detectedCol] = 'x';
        forwardCounter = (forwardCounter + (bufferOne * -1));
    }
    else
    {
        placement.friendlyGrid[detectedRow + bufferOne + backwardCounter][detectedCol] = 'x';
        backwardCounter += bufferOne;
        DestroyShipBlock(shipType);
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
            isSwitched = true;
        else
            DestroyShipBlock(shipType);
        placement.friendlyGrid[detectedRow][detectedCol + bufferTwo + forwardCounter] = 'x';
        forwardCounter = (forwardCounter + (bufferOne * -1));
    }
    else
    {
        placement.friendlyGrid[detectedRow][detectedCol + bufferOne + backwardCounter] = 'x';
        backwardCounter += bufferOne;
        DestroyShipBlock(shipType);
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
        cout << "yoo" << endl;
        FindShipOrientation();
    }
    else if (shipDetected == true && orientationDetected)
    {
        DestroyShip();
    }
    cout << friendlyFlag.GetBlockNumber() << endl;
};