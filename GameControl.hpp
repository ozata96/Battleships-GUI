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
    
    bool isSwitched = false;


    char direction;

    int detectedRow = 0;
    int detectedCol = 0;

    int leftCounter = 0;
    int rightCounter = 0;

    void DestroyShip();

    void EnemyMakeMove();
    bool isNewGuess(int row, int col);
    void DestroyShipBlock(char input);
    int GetShipBlock(char shipType);

    void EnemyMakeRandomGuess();
    void FindShipOrientation();

    void RightGuessing();
    void LeftGuessing();

    void VerticalGuessing(char switchDirection);

public:
    GameControl();
    ~GameControl();

    void MakeMove();
};

#endif