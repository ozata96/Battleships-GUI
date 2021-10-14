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

    FlagShip friendlyFlag;
    DestroyerShip friendlyDestroyer;
    MinorShip friendlyMinor;
    RadarShip friendlyRadar;

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
    int enemyBlockShipCount = 14;

    void DestroyShip();

    void EnemyMakeMove();
    bool isNewGuess(int row, int col);
    void DestroyShipBlock(char input);
    int GetShipBlock(char shipType);
   
    void EnemyMakeRandomGuess();
    void FindShipOrientation();

    void UpGuessing();
    void DownGuessing();

    void HorizontalGuessing(int &forwardCounter, int &backwardCounter, int bufferTwo, int bufferOne);
    void VerticalGuessing(int &forwardCounter, int &backwardCounter, int bufferTwo, int bufferOne);

    void TriggerWin(string type);

    bool CheckAttackInput(string input);
    bool CheckPlacementInput(string input);

public:
    GameControl();
    ~GameControl();

    void MakeMove();
};

#endif