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
    vector<int> foundShipsList;

    bool shipDetected = false;
    bool orientationDetected = false;

    char direction;

    int detectedRow = 0;
    int detectedCol = 0;


    void DestroyShip();
    char AttackRight();

    void EnemyMakeMove();
    bool isNewGuess(int row, int col);
    void DestroyShipBlock(char input);
    int GetShipBlock(char shipType);

    void EnemyMakeRandomGuess();
    void FindShipOrientation();

    void HorizontalGuessing(char switchDirection);
    void VerticalGuessing(char switchDirection);

public:
    GameControl();
    ~GameControl();

    void MakeMove();
};

#endif