#include <iostream>
#include <vector>
#include "ShipPlacement.hpp"
#include "Battleship.hpp"

using namespace std;


int main()
{
    ShipPlacement shipPlacement;
    FlagShip flagShipFriendly;
    RadarShip radarShip;

    vector<string> table;
    table = shipPlacement.SetGameBoard();


    shipPlacement.SimpleGridIntake("FA1A5", table);
    // shipPlacement.IntakeCoordinates("FB2F2", table);


    cout << endl << endl << endl;
    for (int i = 0; i < table.size(); i++)
    {
        cout << table[i] << endl;
    }
    cout << endl << endl;
}
