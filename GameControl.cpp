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

    row.push_back("                 YOUR SHIPS                                       ENEMY SHIPS               ");
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


int GameControl::convertRowForMainGrid(int row)
{
    return ((row + 4) + (row * 2) - row);
}

int GameControl::convertColForMainGrid(int col)
{
    return ((col + 6) + (col * 4) - col);
}

void GameControl::SimpleGridIntake(string input, vector<string> &grid)
{
    int rowStart, colStart, rowEnd, colEnd;

    int numDeployed = GetNumberDeployable(input[0]);

    rowStart = input[1] - 65;
    colStart = input[2] - 49;
    rowEnd = input[3] - 65;
    colEnd = input[4] - 49;

    if (!areValidCoordinates(numDeployed, rowStart, colStart, rowEnd, colEnd))
        cerr << "Invalid Coordinates" << endl;
    else
    {

        if (rowStart == rowEnd)
            for (int i = colStart; i <= colEnd; i++)
                if (simpleGrid[rowStart][i] == '.')
                {
                    simpleGrid[rowStart][i] = 'o';
                    grid[convertRowForMainGrid(rowStart)][convertColForMainGrid(i)] = 'o';
                }
                else
                    cerr << "Error: Cannot overlap ships, please choose another placement" << endl;

        if (colStart == colEnd)
            for (int i = rowStart; i <= rowEnd; i++)
                if (simpleGrid[i][colStart] == '.')
                {
                    simpleGrid[i][colStart] = 'o';
                    grid[convertRowForMainGrid(i)][convertColForMainGrid(colStart)] = 'o';
                }
                else
                    cerr << "Error: Cannot overlap ships, please choose another placement" << endl;

        for (int i = 0; i < 10; i++)
            cout << simpleGrid[i] << endl;
    }
}

void GameControl::IntakeCoordinates(string input, vector<string> &grid)
{
    vector<int> gridCoordinates;

    // gridCoordinates = TranslateCoordinates(input);

    SimpleGridIntake(input, grid);

    // grid[gridCoordinates[0]][gridCoordinates[1]] = 'o';
    // grid[gridCoordinates[2]][gridCoordinates[3]] = 'o';

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

/*
ROW CONVERSION
(x+4) + (x*2) - x
[0] -> [4]          - 4
[1] -> [6]          - 6
[2] -> [8]          - 8
[3] -> [10]         - 10
[4] -> [12]         - 
[5] -> [14]         -
[6] -> [18]         -
[7] -> [22]         -


COL CONVERSION
(x + 6) + (x * 4) - x
[0] -> [6]          - 6
[1] -> [10]         - 10
[2] -> [14]         - 
[3] -> [18]         - 
[4] -> [22]         - 
[5] -> [26]         - 
[6] -> [30]         -
[7] -> [34]         -
[8] -> [38]         -
*/
