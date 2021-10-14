#include <random>
#include "ShipPlacement.hpp"
#include "BattleShip.hpp"

#include "Engagement.hpp"

ShipPlacement::ShipPlacement()
{
    string row = "";

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            row.push_back('.');
        }
        friendlyGrid.push_back(row);
        enemyGrid.push_back(row);
        row = "";
    }
};

ShipPlacement::~ShipPlacement(){};

int ShipPlacement::GetNumberDeployable(char shipType)
{

    switch (shipType)
    {
    case 'R':
        return 2;
    case 'M':
        return 3;
    case 'D':
        return 4;
    case 'F':
        return 5;
    default:
        return 0;
    }
};

bool ShipPlacement::areValidCoordinates(int numShipBlocks, int rowStart, int colStart, int rowEnd, int colEnd)
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
};

int ShipPlacement::convertRowForMainGrid(int row)
{
    return ((row + 4) + (row * 2) - row);
};

int ShipPlacement::convertColForMainGrid(int col)
{
    return ((col + 6) + (col * 4) - col);
};

void ShipPlacement::CreateShip(int numDeployed)
{
    // 2, 3, 4, 5
    if (numDeployed == 5)
    {
        friendlyFlagShipPlaced = true;
    }
    else if (numDeployed == 4)
    {
        friendlyDestroyerShipPlaced = true;
    }
    else if (numDeployed == 3)
    {
        friendlyMinorShipPlaced = true;
    }
    else if (numDeployed == 2)
    {
        friendlyRadarShipPlaced = true;
    }
};

string ShipPlacement::ConvertToString(int row, int col)
{
    string coord = "";
    char rowChar = static_cast<char>(row);
    char colChar = static_cast<char>(col);
    coord.push_back(rowChar);
    coord.push_back(colChar);
    return coord;
}

void ShipPlacement::MarkCoordinate(int row, int col, char shipType)
{
    shipTypeList[ConvertToString(row, col)] = shipType;
};

char ShipPlacement::GetCoordinateType(int row, int col)
{
    return shipTypeList[ConvertToString(row, col)];
}

void ShipPlacement::FriendlyGridIntake(string input, vector<string> &grid)
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
                if (friendlyGrid[rowStart][i] == '.')
                {
                    friendlyGrid[rowStart][i] = 'o';
                    grid[convertRowForMainGrid(rowStart)][convertColForMainGrid(i)] = 'o';
                    MarkCoordinate(rowStart, i, input[0]);
                }
                else
                {
                    cerr << "Error: Cannot overlap ships, please choose another placement" << endl;
                    break;
                }

        else if (colStart == colEnd)
            for (int i = rowStart; i <= rowEnd; i++)
                if (friendlyGrid[i][colStart] == '.')
                {
                    friendlyGrid[i][colStart] = 'o';
                    grid[convertRowForMainGrid(i)][convertColForMainGrid(colStart)] = 'o';
                    MarkCoordinate(i, colStart, input[0]);
                }
                else
                {
                    cerr << "Error: Cannot overlap ships, please choose another placement" << endl;
                    break;
                }

        CreateShip(numDeployed);
        if (friendlyFlagShipPlaced && friendlyDestroyerShipPlaced && friendlyMinorShipPlaced && friendlyRadarShipPlaced)
        {
            RandomEnemyShipPlacement(2, enemyRadarShipPlaced);
            RandomEnemyShipPlacement(3, enemyMinorShipPlaced);
            RandomEnemyShipPlacement(4, enemyDestroyerShipPlaced);
            RandomEnemyShipPlacement(5, enemyFlagShipPlaced);
        }
    }
};

int ShipPlacement::RandomNumberGenerator(int min, int max)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max);
    // cout << dist6(rng) << " ";
    return dist6(rng);
}

void ShipPlacement::ClearGrid(vector<string> &grid, vector<int> targetCoordinates)
{
    for (int i = 0; i < targetCoordinates.size(); i++)
    {
        grid[targetCoordinates[i]][targetCoordinates[i + 1]] = '.';
        // cout << targetCoordinates[i] << "," << targetCoordinates[i + 1] << endl;
        i++;
    }
}

void ShipPlacement::RandomEnemyShipPlacement(int shipBlocks, bool enemyShipType)
{
    int count = 0;
    int tracker = 0;
    vector<int> tempCoordinates;

    while (enemyShipType == false)
    {
        int flip = RandomNumberGenerator(0, 1);

        // Flagship Placement
        int rowStart = RandomNumberGenerator(0, 9);
        int colStart = RandomNumberGenerator(0, 8);

        // cout << rowStart << " , " << colStart << endl;
        // enemyGrid[rowStart][colStart] = 'o';

        if (flip == 0)
        {
            // VERTICAL
            for (int i = rowStart; i >= 0; i--)
            {
                tracker++;
                if (enemyGrid[i][colStart] == '.')
                {
                    enemyGrid[i][colStart] = 'o';
                    count++;
                    tempCoordinates.push_back(i);
                    tempCoordinates.push_back(colStart);
                }
                if (count == shipBlocks)
                    break;
                if (count != tracker)
                    break;
            }
            if (count < shipBlocks)
            {
                ClearGrid(enemyGrid, tempCoordinates);
                tempCoordinates.clear();
                count = 0;
                tracker = 0;

                for (int i = rowStart; i < 10; i++)
                {
                    tracker++;
                    if (enemyGrid[i][colStart] == '.')
                    {
                        enemyGrid[i][colStart] = 'o';
                        count++;
                        tempCoordinates.push_back(i);
                        tempCoordinates.push_back(colStart);
                    }
                    if (count == shipBlocks)
                        break;
                    if (count != tracker)
                        break;
                }
                if (count < shipBlocks)
                {
                    ClearGrid(enemyGrid, tempCoordinates);
                    tempCoordinates.clear();
                    count = 0;
                    tracker = 0;
                }

                if (count == shipBlocks)
                {
                    tempCoordinates.clear();
                    enemyShipType = true;
                }
            }

            else if (count == shipBlocks)
            {
                tempCoordinates.clear();
                enemyShipType = true;
            }
        }

        else
        {
            // HORIZONTAL

            for (int i = colStart; i >= 0; i--)
            {
                tracker++;
                if (enemyGrid[rowStart][i] == '.')
                {
                    enemyGrid[rowStart][i] = 'o';
                    count++;
                    tempCoordinates.push_back(rowStart);
                    tempCoordinates.push_back(i);
                }
                if (count == shipBlocks)
                    break;
                if (count != tracker)
                    break;
            }
            if (count < shipBlocks)
            {
                ClearGrid(enemyGrid, tempCoordinates);
                tempCoordinates.clear();
                count = 0;
                tracker = 0;
                for (int i = colStart; i < 9; i++)
                {
                    tracker++;
                    if (enemyGrid[rowStart][i] == '.')
                    {
                        enemyGrid[rowStart][i] = 'o';
                        count++;
                        tempCoordinates.push_back(rowStart);
                        tempCoordinates.push_back(i);
                    }
                    if (count == shipBlocks)
                        break;
                    if (count != tracker)
                        break;
                }
                if (count < shipBlocks)
                {
                    ClearGrid(enemyGrid, tempCoordinates);
                    tempCoordinates.clear();
                    count = 0;
                    tracker = 0;
                }

                if (count == shipBlocks)
                {
                    tempCoordinates.clear();
                    enemyShipType = true;
                }
            }
            else if (count == shipBlocks)
            {
                tempCoordinates.clear();
                enemyShipType = true;
            }
        }
    }
};
