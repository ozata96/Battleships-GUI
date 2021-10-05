#include "GameControl.hpp"
using namespace std;


vector<string> GameControl::SetGameBoard(){
    vector<string> row;

    row.push_back("                   ENEMY SHIPS                                              YOUR SHIPS");
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

void GameControl::IntakeCoordinates(string input, vector<string> &grid)
{
    vector<int> finalCoordinates;
    vector<int> tempCoordinates;

    int numDeployed = GetNumberDeployable(input[0]);
    finalCoordinates.push_back(numDeployed);

    tempCoordinates = TranslateCoordinates(input);

    for (int i = 0; i < tempCoordinates.size(); i++){
        finalCoordinates.push_back(tempCoordinates[i]);
    }

    for (int i = 0; i < finalCoordinates.size(); i++)
    {
        cout << finalCoordinates[i] << endl;
    }

    grid[finalCoordinates[1]][finalCoordinates[2]] = 'o';
    grid[finalCoordinates[3]][finalCoordinates[4]] = 'o';
};
