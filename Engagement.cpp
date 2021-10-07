#include "Engagement.hpp"

// Constructor/Destructor
Engagement::Engagement(){};
Engagement::~Engagement(){};

// Functions

void Engagement::Fight(vector<string> &enemyGrid)
{

    int x, y;
    while (x != 20)
    {
        cout << "----------Enemy Ships------------" << endl;
        for (int i = 0; i < 10; i++)
            cout << enemyGrid[i] << endl;

        cout << "ROW: ";
        cin >> x;
        cout << endl
             << "COL: ";
        cin >> y;
        cout << endl;
        Strike(x, y, enemyGrid);
    }
}

void Engagement::Strike(int row, int col, vector<string> &grid)
{
    switch (grid[row][col])
    {
    case '.':
        Miss(row, col, grid);
        break;
    case 'o':
        Hit(row, col, grid);
        break;
    }
};

void Engagement::Hit(int row, int col, vector<string> &grid)
{
    cout << "HIT!" << endl;
    grid[row][col] = 'H';
};

void Engagement::Miss(int row, int col, vector<string> &grid)
{
    cout << "MISS!" << endl;
    grid[row][col] = 'M';
};