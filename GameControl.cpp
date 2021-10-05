#include "GameControl.hpp"
using namespace std;

GameControl::GameControl()
{
    string row = "";

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            row.push_back('.');
        }
        simpleGrid.push_back(row);
        row = "";
    }
};

GameControl::~GameControl(){};

vector<string> GameControl::SetGameBoard()
{
    vector<string> row;

    row.push_back("                 ENEMY SHIPS                                       YOUR SHIPS               ");
    row.push_back("");
    row.push_back("      1   2   3   4   5   6   7   8   9                 1   2   3   4   5   6   7   8   9   ");
    row.push_back("    +===+===+===+===+===+===+===+===+===+             +===+===+===+===+===+===+===+===+===+ ");
    row.push_back("A   |   :   :   :   :   :   :   :   :   |         A   |   :   :   :   :   :   :   :   :   | ");
    row.push_back("    +---+---+---+---+---+---+---+---+---+             +---+---+---+---+---+---+---+---+---+ ");
    row.push_back("B   |   :   :   :   :   :   :   :   :   |         B   |   :   :   :   :   :   :   :   :   | ");
    row.push_back("    +---+---+---+---+---+---+---+---+---+             +---+---+---+---+---+---+---+---+---+ ");
    row.push_back("C   |   :   :   :   :   :   :   :   :   |         C   |   :   :   :   :   :   :   :   :   | ");
    row.push_back("    +---+---+---+---+---+---+---+---+---+             +---+---+---+---+---+---+---+---+---+ ");
    row.push_back("D   |   :   :   :   :   :   :   :   :   |         D   |   :   :   :   :   :   :   :   :   | ");
    row.push_back("    +---+---+---+---+---+---+---+---+---+             +---+---+---+---+---+---+---+---+---+ ");
    row.push_back("E   |   :   :   :   :   :   :   :   :   |         E   |   :   :   :   :   :   :   :   :   | ");
    row.push_back("    +---+---+---+---+---+---+---+---+---+             +---+---+---+---+---+---+---+---+---+ ");
    row.push_back("F   |   :   :   :   :   :   :   :   :   |         F   |   :   :   :   :   :   :   :   :   | ");
    row.push_back("    +---+---+---+---+---+---+---+---+---+             +---+---+---+---+---+---+---+---+---+ ");
    row.push_back("G   |   :   :   :   :   :   :   :   :   |         G   |   :   :   :   :   :   :   :   :   | ");
    row.push_back("    +---+---+---+---+---+---+---+---+---+             +---+---+---+---+---+---+---+---+---+ ");
    row.push_back("H   |   :   :   :   :   :   :   :   :   |         H   |   :   :   :   :   :   :   :   :   | ");
    row.push_back("    +---+---+---+---+---+---+---+---+---+             +---+---+---+---+---+---+---+---+---+ ");
    row.push_back("I   |   :   :   :   :   :   :   :   :   |         I   |   :   :   :   :   :   :   :   :   | ");
    row.push_back("    +---+---+---+---+---+---+---+---+---+             +---+---+---+---+---+---+---+---+---+ ");
    row.push_back("J   |   :   :   :   :   :   :   :   :   |         J   |   :   :   :   :   :   :   :   :   | ");
    row.push_back("    +---+---+---+---+---+---+---+---+---+             +---+---+---+---+---+---+---+---+---+ ");
    row.push_back("");
    row.push_back("         oo      Radar Ship  [R]                           oo      Radar Ship  [R]          ");
    row.push_back("         ooo     Minor Ship  [M]                           ooo     Minor Ship  [M]          ");
    row.push_back("         oooo    Battleship  [B]                           oooo    Battleship  [B]          ");
    row.push_back("         ooooo   Flagship    [F]                           ooooo   Flagship    [F]          ");

    return row;
};

int GameControl::GetNumberDeployable(char shipType)
{

    switch (shipType)
    {
    case 'R':
        return 2;
    case 'M':
        return 3;
    case 'B':
        return 4;
    case 'F':
        return 5;
    default:
        return 0;
    }
};

int GameControl::RowCoordinateMapConvert(char x)
{
    switch (x)
    {
    case 'A':
        return 4;
    case 'B':
        return 6;
    case 'C':
        return 8;
    case 'D':
        return 10;
    case 'E':
        return 12;
    case 'F':
        return 14;
    case 'G':
        return 16;
    case 'H':
        return 18;
    case 'I':
        return 20;
    case 'J':
        return 22;
    default:
        return 0;
    }
};

int GameControl::ColCoordinateMapConvert(char x)
{
    int xInt;
    xInt = x - 48;

    return (xInt * 4) + 2;
};

void GameControl::ConvertGridToCoordinate(string coordinate, int &row, int &col)
{
    row = RowCoordinateMapConvert(coordinate[0]);
    col = ColCoordinateMapConvert(coordinate[1]);
};

vector<int> GameControl::TranslateCoordinates(string input)
{
    int row = 0;
    int col = 0;
    string rowStr = "";
    string colStr = "";

    vector<int> coordinates;

    // Intaking Row Numbers
    rowStr.push_back(input[1]);
    rowStr.push_back(input[2]);

    ConvertGridToCoordinate(rowStr, row, col);

    coordinates.push_back(row);
    coordinates.push_back(col);

    row = col = 0;

    // Intaking Col numbers
    colStr.push_back(input[3]);
    colStr.push_back(input[4]);

    ConvertGridToCoordinate(colStr, row, col);

    coordinates.push_back(row);
    coordinates.push_back(col);

    return coordinates;
};

bool GameControl::areValidCoordinates(int numShipBlocks, int rowStart, int colStart, int rowEnd, int colEnd)
{
    if (rowStart < 0 || rowStart > 9 || rowEnd < 0 || rowEnd > 9)
    {
        return false;
    }
    if (colStart < 0 || colStart > 8 || colEnd < 0 || colEnd > 8)
    {
        return false;
    }
    if (rowStart != rowEnd)
        if (colStart != colEnd)
        {
            return false;
        }
    if (rowStart == rowEnd)
        if (numShipBlocks - 1 == (colEnd - colStart))
        {
            return true;
        }

    if (colStart == colEnd)
    {
        if (numShipBlocks - 1 == (rowEnd - rowStart))
        {
            return true;
        }
    }
    // cout << numShipBlocks << " , " << colEnd - colStart << endl;
    // cout << numShipBlocks << " , " << rowEnd - rowStart << endl;
    return false;
}

// void ShipPlacement(int shipType, int rowStart, int colStart, int rowEnd, int colEnd, vector<string> &grid)
// {
//     int locCount = 0;

//     if (!areValidCoordinates(shipType, rowStart, colStart, rowEnd, colEnd))
//         cerr << endl << endl << "Error, coordinates are not valid" << endl;
//     else
//     {

//     }

// }

void GameControl::SimpleGridIntake(string input)
{
    int rowStart, colStart, rowEnd, colEnd;

    int numDeployed = GetNumberDeployable(input[0]);

    rowStart = input[1] - 65;
    colStart = input[2] - 49;
    rowEnd = input[3] - 65;
    colEnd = input[4] - 49;

    if (!areValidCoordinates(numDeployed, rowStart, colStart, rowEnd, colEnd))
        cout << "Invalid Coordinates" << endl;
    else
    {

        if (rowStart == rowEnd)
            for (int i = colStart; i <= colEnd; i++)
                simpleGrid[rowStart][i] = 'o';

        else if (colStart == colEnd)
            for (int i = rowStart; i <= rowEnd; i++)
                simpleGrid[i][colStart] = 'o';

        for (int i = 0; i < 10; i++)
            cout << simpleGrid[i] << endl;
    }
}

void GameControl::IntakeCoordinates(string input, vector<string> &grid)
{
    vector<int> gridCoordinates;

    gridCoordinates = TranslateCoordinates(input);

    SimpleGridIntake(input);

    grid[gridCoordinates[0]][gridCoordinates[1]] = 'o';
    grid[gridCoordinates[2]][gridCoordinates[3]] = 'o';

    // for (int i = 0; i < gridCoordinates.size(); i++)
    // {
    //     cout << gridCoordinates[i] << " , ";
    // }
};

// .........
// .........
// .........
// .........
// .........
// .........
// .........
// .........
// .........
// .........