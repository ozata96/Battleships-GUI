#include <iostream>
#include <vector>

using namespace std;

class ShipPlacement
{
private:

    
    bool CheckString(string input);
    int GetNumberDeployable(char shipType);
    void SimpleGridIntake(string input, vector<string> &grid);
    bool areValidCoordinates(int numShipBlocks, int rowStart, int colStart, int rowEnd, int colEnd);
    int convertRowForMainGrid(int row);
    int convertColForMainGrid(int col);

public:
    ShipPlacement();
    ~ShipPlacement();

    // Simple Grid
    vector<string> simpleGrid;

    // functions
    vector<string> SetGameBoard();
    void IntakeCoordinates(string input, vector<string> &grid);


};

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

*/
