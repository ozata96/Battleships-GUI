class BattleShip
{
protected:
    int blocks;
    int shipCounter;
    BattleShip(int blocks);
    ~BattleShip();

public:
    virtual int GetBlockNumber() = 0;
    void DestroyBlock();
};

class FlagShip : public BattleShip
{
public:
    FlagShip();
    ~FlagShip();
    int GetBlockNumber() override;
};

class DestroyerShip : public BattleShip
{
public:
    DestroyerShip();
    ~DestroyerShip();
    int GetBlockNumber() override;
};

class MinorShip : public BattleShip
{
public:
    MinorShip();
    ~MinorShip();
    int GetBlockNumber() override;
};

class RadarShip : public BattleShip
{
public:
    RadarShip();
    ~RadarShip();
    int GetBlockNumber() override;
};