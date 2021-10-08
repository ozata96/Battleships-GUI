#include "BattleShip.hpp"

// Mother Class
BattleShip::BattleShip(int blocks) : blocks(blocks){};
BattleShip::~BattleShip(){};
int BattleShip::GetBlockNumber() { return blocks; };
void BattleShip::DestroyBlock() { blocks--; };

// +--------------------------------------------------------------------------+

// Child 1
FlagShip::FlagShip() : BattleShip(blocks)
{
    blocks = 5;
};
FlagShip::~FlagShip(){};
int FlagShip::GetBlockNumber() { return blocks; };

// Child 2
DestroyerShip::DestroyerShip() : BattleShip(blocks)
{
    blocks = 4;
};
DestroyerShip::~DestroyerShip(){};
int DestroyerShip::GetBlockNumber() { return blocks; };

// Child 3
MinorShip::MinorShip() : BattleShip(blocks)
{
    blocks = 3;
};
MinorShip::~MinorShip(){};
int MinorShip::GetBlockNumber() { return blocks; };

// Child 4
RadarShip::RadarShip() : BattleShip(blocks)
{
    blocks = 2;
};
RadarShip::~RadarShip(){};
int RadarShip::GetBlockNumber() { return blocks; };
