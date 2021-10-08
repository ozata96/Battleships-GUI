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
    // ------------------------------------------

    vector<int> guessList;
    bool shipDetected = false;

    int detectedRow;
    int detectedCol;

public:
    void MakeMove();
    void EnemyMakeMove();
    bool isNewGuess(int row, int col);
    // BattleShip GetShip(char input);
    void EnemyMakeRandomGuess();
    void HuntShip();
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