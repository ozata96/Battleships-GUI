#ifndef GameControl_HPP
#define GameControl_HPP

#include "BoardDisplay.hpp"
#include "Engagement.hpp"
#include "ShipPlacement.hpp"
#include "BattleShip.hpp"

class GameControl
{
private:
    BoardDisplay board;
    Engagement engagement;
    ShipPlacement placement;

    // Ships-------------------------------------
    FlagShip enemyFlag;
    FlagShip friendlyFlag;

    DestroyerShip enemyDestroyer;
    DestroyerShip friendlyDestroyer;

    MinorShip enemyMinor;
    MinorShip friendlyMinor;

    RadarShip enemyRadar;
    RadarShip friendlyRadar;

    BattleShip *placeholderShip;
    // ------------------------------------------

    vector<int> guessList;
    bool shipDetected = false;
    bool orientationDetected = false;
    string direction = "";

    int detectedRow = 0;
    int detectedCol = 0;

    void DestroyShip();
    void EnemyMakeMove();
    bool isNewGuess(int row, int col);
    void DestroyShipBlock(char input);
    void EnemyMakeRandomGuess();
    void FindShipOrientation();

public:
    GameControl();
    ~GameControl();

    void MakeMove();
};

#endif

/*
XXXX
. . . . . . . . . . 
. . . . - . . . . . 
. . . . X - . . . . 
. . . . - . . . . . 
. . . . . . . . . . 
. . . . . . . . . . 

*/