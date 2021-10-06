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

    shipPlacement.FriendlyGridIntake("RA1A2", table);
    shipPlacement.FriendlyGridIntake("MB1B3", table);
    shipPlacement.FriendlyGridIntake("DC1C4", table);
    shipPlacement.FriendlyGridIntake("FD1D5", table);




    cout << endl << endl << endl;
    for (int i = 0; i < table.size(); i++)
    {
        cout << table[i] << endl;
    }
    cout << endl << endl;
}

