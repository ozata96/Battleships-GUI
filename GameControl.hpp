#include <iostream>
#include <vector>

using namespace std;

class GameControl
{
private:
    bool CheckString(string input);
    int GetNumberDeployable(char shipType);
    int RowCoordinateMapConvert(char x);
    int ColCoordinateMapConvert(char x);
    void ConvertGridToCoordinate(string coordinate, int &row, int &col);
    vector<int> TranslateCoordinates(string input);
    
public:
    vector<string> SetGameBoard();
    void IntakeCoordinates(string input);
};

/*
RSA1A5


[0][0] = [4][6]
[0][1] = [4][10]
[0][2] = [4][14]
[0][3] = [4][18]

[1][0] = [6][6]
[1][1] = [6][10]
[1][2] = [6][14]
[1][3] = [6][18]


x -> y

y = (x * 4) + 2

1 -> 6
2 -> 10
3 -> 14
4 -> 18
5 -> 22
6 -> 26

*/
