#include "Engagement.hpp"

// Constructor/Destructor
Engagement::Engagement(){};
Engagement::~Engagement(){};

// Functions

void Engagement::Strike(int row, int col, vector<string> &logicGrid, vector<string> &display)
{
    switch (logicGrid[row][col])
    {
    case '.':
        Miss(row, col, display);
        break;
    case 'o':
        Hit(row, col, display);
        break;
    default:
        cerr << "error" << endl;
    }
};

int Engagement::ConvertRow(int row)
{
    return ((row + 4) + (row * 2)) - row;
}

int Engagement::ConvertCol(int col)
{
    return ((col + 56) + (col * 4)) - col;
}

void Engagement::Hit(int row, int col, vector<string> &display)
{
<<<<<<< HEAD
    // cout << "HIT!" << endl;
=======
    cout << "HIT!" << endl;
>>>>>>> 2b8f1c8a8ad386ebb2388bd1ab2879ea81e7d77a
    row = ConvertRow(row);
    col = ConvertCol(col);
    display[row][col] = 'X';
};

void Engagement::Miss(int row, int col, vector<string> &display)
{
<<<<<<< HEAD
    // cout << "MISS!" << endl;
=======
    cout << "MISS!" << endl;
>>>>>>> 2b8f1c8a8ad386ebb2388bd1ab2879ea81e7d77a
    row = ConvertRow(row);
    col = ConvertCol(col);
    display[row][col] = '-';};