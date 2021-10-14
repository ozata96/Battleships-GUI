#ifndef ShipPlacement_HPP
#define ShipPlacement_HPP

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class ShipPlacement
{
private:
    // Friendly Ship Placement

    // Enemy Ship Placement
    bool enemyFlagShipPlaced = false;
    bool enemyDestroyerShipPlaced = false;
    bool enemyMinorShipPlaced = false;
    bool enemyRadarShipPlaced = false;

    void ClearGrid(vector<string> &grid, vector<int> targetCoordinates);

    // Friendly Ship Functions
    bool CheckString(string input);
    int GetNumberDeployable(char shipType);
    bool areValidCoordinates(int numShipBlocks, int rowStart, int colStart, int rowEnd, int colEnd);

    void CreateShip(int numDeployed);

    // Enemy Ship Functions
    void RandomEnemyShipPlacement(int shipBlocks, bool enemyShipType);

public:
    int convertRowForMainGrid(int row);
    int convertColForMainGrid(int col);

    bool friendlyFlagShipPlaced = false;
    bool friendlyDestroyerShipPlaced = false;
    bool friendlyMinorShipPlaced = false;
    bool friendlyRadarShipPlaced = false;

    ShipPlacement();
    ~ShipPlacement();
    int RandomNumberGenerator(int min, int max);

    // Logic Grids
    vector<string> friendlyGrid;
    vector<string> enemyGrid;
    map<string, char> shipTypeList;

    // functions
    void FriendlyGridIntake(string input, vector<string> &grid);
    string ConvertToString(int row, int col);
    void MarkCoordinate(int row, int col, char shipType);
    char GetCoordinateType(int row, int col);
};

#endif

/*
R A1 J8


[0][0] = [4][6]
[0][1] = [4][10]
[0][2] = [4][14]
[0][3] = [4][18]


[1][0] = [6][6]
[1][1] = [6][10]
[1][2] = [6][14]
[1][3] = [6][18]

[9][8] = [22][38]



x -> y

y = (x * 4) + 2

1 -> 6
2 -> 10
3 -> 14
4 -> 18
5 -> 22
6 -> 26



+---+---+---+---+---+---+
:   :   :   :   :   :   :
+---+---+---+---+---+---+
:   :   : - : X :   :   :
+---+---+---+---+---+---+
:   :   : X : X :   :   :
+---+---+---+---+---+---+
:   :   : X :   :   :   :
+---+---+---+---+---+---+
:   :   : X :   :   :   :
+---+---+---+---+---+---+







*/
